#ifndef COMUNICATIONTHREAD_H
#define COMUNICATIONTHREAD_H

#include <QMutex>
#include <QThread>
#include <QWaitCondition>
#include "mpbpacker.h"
#include "mpbparser.h"



class comunicationThread : public QThread
{
    Q_OBJECT
public:
    explicit comunicationThread(QObject *parent = nullptr);
    ~comunicationThread();

    void transaction (const QString &portName, int waitTimeout , quint8 mCommand, quint8 Index) ;

Q_SIGNALS:
    void response(const QString &s);
    void responseData(const quint8 *buffer);
    void error(const QString &s);
    void timeout(const QString &s);

private:
    void run() override;

    QString m_portName;
    QString m_request;
    int m_waitTimeout = 0;
    QMutex m_mutex;
    QWaitCondition m_cond;
    bool m_quit = false;
    mpbPacker m_mpbPacker;
    mpbParser m_mpbParser;
    char d1[ MAX_TX_LENGTH_BUFFER ];
    char dataRx[ MAX_TX_LENGTH_BUFFER ];
    quint8 m_ucParametersData[24] ; //= {1,3};
    quint8 m_length ;//= 2;
    quint8 m_ucCommand ;//= 10;

};

#endif // COMUNICATIONTHREAD_H

