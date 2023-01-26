/*****************************************************************************
 * Qwt Examples - Copyright (C) 2002 Uwe Rathmann
 * This file may be used under the terms of the 3-clause BSD License
 *****************************************************************************/

#include "SamplingThread.h"
#include "SignalData.h"
#include "mpbLibs.h"

#include <QwtMath>
#include <qmath.h>

SamplingThread::SamplingThread( QObject* parent )
    : QwtSamplingThread( parent )
    , m_frequency( 5.0 )
    , m_amplitude( 20.0 )
    , m_current(0.0)
    , m_power(0.0)
    , selectElectricVariable(0)

{
}

void SamplingThread::setFrequency( double frequency )
{
    m_frequency = frequency;
}

void SamplingThread::getRealData(const quint8 *Data)
{
    mpbShortData_t mpbShortData;
    mpbShortData_t currentData;
    mpbShortData_t powerData;

    //get current
    currentData.ucValue[0]= Data[19];
    currentData.ucValue[1]= Data[20];

    //get power
    powerData.ucValue[0]= Data[21];
    powerData.ucValue[1]= Data[22];

    mpbShortData.ucValue[0] = Data[0];
    mpbShortData.ucValue[1] = Data[1];

    m_amplitude = mpbShortData.sValue/100;
     m_current = currentData.sValue;
     m_power = powerData.sValue;
}

void SamplingThread::selectCurrent(int state)
{
  selectElectricVariable = (state == 0)? 2 : 1;
}


double SamplingThread::frequency() const
{
    return m_frequency;
}



void SamplingThread::setAmplitude( double amplitude )
{
    m_amplitude = amplitude;
}



double SamplingThread::amplitude() const
{
    return m_amplitude;
}



void SamplingThread::sample( double elapsed )
{
    if ( m_frequency > 0.0 )
    {
        const QPointF s( elapsed, value( elapsed ) );
        SignalData::instance().append( s );
    }
}


double SamplingThread::value( double timeStamp ) const
{
    const double period = 1.0 / m_frequency;

    const double x = std::fmod( timeStamp, period );
    double v1 ;

    if(selectElectricVariable == 1)
    {
        v1 = (double)m_current ;//* qFastSin( x / period * 2 * M_PI );
    }
    else
    {
        v1 = (double)m_power ;
    }

    const double v  = v1;

    return v;
}


#include "moc_SamplingThread.cpp"
