#include "SamplingDataThread.h"
#include "SignalData.h"
#include "mpbLibs.h"
#include <QwtMath>
#include <qmath.h>

SamplingDataThread::SamplingDataThread( QObject* parent )
    : QwtSamplingThread( parent )
    , m_frequency( 5.0 )
    , m_amplitude( 20.0 )

{
}

void SamplingDataThread::setFrequency( double frequency )
{
    m_frequency = frequency;
}

void SamplingDataThread::getRealData(const quint8 *Data)
{
    mpbShortData_t mpbShortData;

    mpbShortData.ucValue[0] = Data[0];
    mpbShortData.ucValue[1] = Data[1];

    m_amplitude = mpbShortData.sValue/100;
}


double SamplingDataThread::frequency() const
{
    return m_frequency;
}



void SamplingDataThread::setAmplitude( double amplitude )
{
   // m_amplitude = amplitude;
}



double SamplingDataThread::amplitude() const
{
    return m_amplitude;
}



void SamplingDataThread::sample( double elapsed )
{
    if ( m_frequency > 0.0 )
    {
        const QPointF s( elapsed, value( elapsed ) );
        SignalData::instance().append( s );
    }
}


double SamplingDataThread::value( double timeStamp ) const
{
    const double period = 1.0 / m_frequency;

    const double x = std::fmod( timeStamp, period );
    const double v = m_amplitude;// * qFastSin( x / period * 2 * M_PI );

    return v;
}


#include "moc_SamplingDataThread.cpp"
