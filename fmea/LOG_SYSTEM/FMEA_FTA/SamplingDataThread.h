#ifndef SAMPLINGDATATHREAD_H
#define SAMPLINGDATATHREAD_H


#include <QwtSamplingThread>

class SamplingDataThread : public QwtSamplingThread
{
    Q_OBJECT

  public:
    SamplingDataThread( QObject* parent = NULL );

    double frequency() const;
    double amplitude() const;

  public Q_SLOTS:
    void setAmplitude( double );
    void setFrequency( double );
    void getRealData( const quint8 *Data );

  protected:
    virtual void sample( double elapsed ) QWT_OVERRIDE;


  private:
    virtual double value( double timeStamp ) const;


    double m_frequency;
    double m_amplitude;

};
#endif // SAMPLINGDATATHREAD_H
