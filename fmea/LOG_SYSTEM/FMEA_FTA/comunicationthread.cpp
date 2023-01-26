#include "comunicationthread.h"
#include <QSerialPort>
#include <QTime>
#include <QDebug>
//#include "m2mcommunication.h"
#include <cstring>
#include <iostream>

comunicationThread::comunicationThread(QObject *parent)
    : QThread{parent}
{
    qInfo() << "comunication thread created " << QThread::currentThread();
}
comunicationThread::~comunicationThread()
{
    m_mutex.lock();
    m_quit = true;
    m_cond.wakeOne();
    m_mutex.unlock();

    qInfo() << "comunication thread destroyed " << QThread::currentThread();
    this->quit();
    wait();
}

void comunicationThread::transaction(const QString &portName, int waitTimeout , quint8 mCommand, quint8 Index)
{
//! [1]
    const QMutexLocker locker(&m_mutex);


  /*  m_length = length ;
    m_ucCommand = Command ;
    for(quint8 i = 0; i< length ; i++)
    {
        m_ucParametersData[i] = data[i];
    }
*/

    m_portName = portName;
    m_waitTimeout = 2000;//waitTimeout;
    m_request = Index;
    m_ucParametersData[0] = 0x81;
    m_ucParametersData[1] = Index;
    m_ucCommand = mCommand;
    m_length = 2 ; //mlength;
//! [3]
    if (!isRunning())
        start();
    else
        m_cond.wakeOne();
}

void comunicationThread::run()
{
    bool currentPortNameChanged = false;

    m_mutex.lock();
//! [4] //! [5]
    QString currentPortName;
    if (currentPortName != m_portName) {
        currentPortName = m_portName;
        currentPortNameChanged = true;
    }

    int currentWaitTimeout = m_waitTimeout;
    QString currentRequest = m_request;
    m_mutex.unlock();
//! [5] //! [6]
    QSerialPort serial;

    serial.setBaudRate(QSerialPort::Baud115200);
    serial.setDataBits(QSerialPort::Data8 );
    serial.setFlowControl(QSerialPort::NoFlowControl);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
   // serial.s


    if (currentPortName.isEmpty()) {
        Q_EMIT error(tr("No port name specified"));
        return;
    }

    while (!m_quit) {
//![6] //! [7]
        if (currentPortNameChanged) {
            serial.close();
            serial.setPortName(currentPortName);

            if (!serial.open(QIODevice::ReadWrite)) {
                Q_EMIT error(tr("Can't open %1, error code %2")
                           .arg(m_portName).arg(serial.error()));
                return;
            }
        }
//! [7] //! [8]
        // write request
        const QByteArray requestData = currentRequest.toUtf8();

   //     simulated data, this sould come from the ui, app
      //  quint8 parametersData[2] = {0x81,Index};
          quint8 length = m_length;
      //  quint8 ucCommand = 0x60;

      //  m_ucParametersData[0] = LaserDiodeNumber;
      //  m_ucCommand = 0x60;
       // m_length = 2;
      //    m_ucCommand = 10;

        //quint8 *data = m_mpbPacker.mpbPacker_AddMsg( eCommandAccepted, m_ucCommand, length, &m_ucParametersData[0]);
        quint8 *data = m_mpbPacker.mpbPacker_AddMsg( eCommandAccepted, m_ucCommand, length, &m_ucParametersData[0]);
        length = length + 4;

         memset(&d1[0],0,length);
         memcpy(&d1[0],data , length);

          serial.write( d1, length);

        if (serial.waitForBytesWritten(m_waitTimeout)) {
//! [8] //! [10]
            // read response
            if (serial.waitForReadyRead(currentWaitTimeout)) {
                QByteArray responseData = serial.readAll();
                while (serial.waitForReadyRead(30))
                    responseData += serial.readAll();
              //  qint8 large = 0;

                QByteArray responseData1 = responseData.toHex(0);
           //     large = responseData.length();
                //quint8 *data;
                memset( dataRx, 0, MAX_TX_LENGTH_BUFFER);
                int rl = responseData.length();
                for(int i =0; i< (rl) ;i++)
                {
                     dataRx[i] =  responseData[i];

                     data = m_mpbParser.mpbParser_AddChar( responseData[i] );

                }


                //const QString response = QString::fromUtf8(responseData);
                //Q_EMIT this->response(response);
                //Q_EMIT this->responseData( &data[0] );

                if(data == NULL)
                {

                }
                else
                {
                    const QString response = QString::fromUtf8(responseData);
                    Q_EMIT this->response(response);
                    Q_EMIT this->responseData( &data[0] );

                }



//! [12]

//! [10] //! [11] //! [12]
            } else {
                Q_EMIT timeout(tr("Wait read response timeout %1")
                             .arg(QTime::currentTime().toString()));
            }
//! [9] //! [11]
        } else {
            Q_EMIT timeout(tr("Wait write request timeout %1")
                         .arg(QTime::currentTime().toString()));
        }
//! [9]  //! [13]
        m_mutex.lock();
        m_cond.wait(&m_mutex);
        if (currentPortName != m_portName) {
            currentPortName = m_portName;
            currentPortNameChanged = true;
        } else {
            currentPortNameChanged = false;
        }
        currentWaitTimeout = m_waitTimeout;
        currentRequest = m_request;
        m_mutex.unlock();
    }
//! [13]
}



