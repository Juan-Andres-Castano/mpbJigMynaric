#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "mpbLogEvent.h"
#include "comunicationthread.h"
#include "candictionary.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QComboBox;
class QLabel;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void getLogData(xLaserLogEventDescriptor_t *t, uint8_t i);
    void splitAlarms(xAlarmRegister_t xAlarmRegister);
    void splitStatus(xStatusRegister_t xStatusRegister);
    void splitFta_1(mpbFtaLowTempBitAssignment_t mpbFtaLowTempBitAssignment);
    void splitFta_0(mpbFtaLowPowerBitAssignment_t mpbFtaLowPowerBitAssignment);
    void splitFmea(mpbFmeaMode_t mpbFmeaMode);

    xLaserLogEventDescriptor_t* setBuffer(uint8_t newUcBufferIndex);

    ~MainWindow();

    void setUcBufferIndex(uint8_t newUcBufferIndex);

    uint8_t getUcBufferIndex() const;

    void setUcBufferRunIndex(uint8_t newUcBufferRunIndex);

    uint8_t getUcBufferRunIndex() const;

public slots:
  //  void showResponse(const QString &s);
    void showResponseData(const quint8 *buffer);
    void showResponseDataBuffer( xLaserLogEventDescriptor_t *pxLaserLogEventDescriptor );

   void processError();
    void processTimeout();
    void transactionLog( quint8 Index);


private slots:
    void on_pushButton_clicked();
    void Timer_triggered();
    void Timer2_triggered();
   // void fill_BufferLog();
    void on_forward_clicked();
    void on_back_clicked();


    void on_adqData_clicked();

    void on_Decode401_clicked();

signals:
    void triggerLogbuffer(quint8 index);

    void trigger401( c401Status1Definition_t *c401Status1Definition, eBool_t bInputBoosterChannelSelection, eBool_t bOutputLnaChannelSelection );


private:
    Ui::MainWindow *ui;
    QTimer                  m_Timer;
    QTimer                  m_Timer2;
    uint8_t                 ucBufferIndex;
    uint8_t                 ucBufferRunIndex;
    comunicationThread m_thread;
    CanDictionary canDictionary;
 //   QLabel *m_serialPortLabel = nullptr;
  //  QComboBox *m_serialPortComboBox = nullptr;
  //  QLabel *m_waitResponseLabel = nullptr;

};
#endif // MAINWINDOW_H
