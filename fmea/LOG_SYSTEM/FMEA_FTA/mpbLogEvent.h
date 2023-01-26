/**
* @file         mpbLogEvent.h
* @brief        fmea and fta reporting utility.
* @author       juan andres Castano
* @date         Created on 2022-07-30
* @note
* @copyright MPB, Montreal, Qc
* <h2><center>&copy; COPYRIGHT 2022 MPB, Montreal, Quebec, Canada</center></h2>
* <h2><center>&copy; All rights reserved.</center></h2><br/><br/>
* <center>This document contains confidential and proprietary information
* of MPB (subject to a non-disclosure agreement) and shall</center>
* <center>not be disclosed, distributed, or reproduced in whole or in
* part, without the prior written authorization of MPB.</center>
*
**/

#ifndef MPBLOGEVENT_H
#define MPBLOGEVENT_H


/* Includes ----------------------------------------------------------------- */
//#include "Defs.h"
#include "mpbLibs.h"
#include "mainStateMachine.h"
#include "LaserDiodeBeam.h"
//#include "mpbSamplingTime.h"

/* Private define ----------------------------------------------------------- */
#define  SAMPLING_TIME_FOR_NO_ALARMS_MS ( 100 )
#define  SAMPLING_TIME_FOR_ALARMS_MS 		( 10 )
#define  SAMPLING_TIME_FOR_FAULT_MS 		( 1 )
#define  BUFFER_LOG_SIZE								( 40 )

/* Private macro ------------------------------------------------------------ */
/* Private enum ------------------------------------------------------------- */
/* Private struct ----------------------------------------------------------- */
typedef struct
{
    uint16_t b980PoweromputingError 			: 1;     /* bit 0 */
        uint16_t b1545PowercomputingError			: 1;     /* bit 1 */
      uint16_t bLowPowerFail      					: 1;     /* bit 2 */
        uint16_t bNormalLowPowerFail 				  : 1;     /* bit 3  */
      uint16_t bElectricalFailLowPower			: 1;     /* bit 4 */
    uint16_t b980NormalLowPowerFail   		: 1;     /* bit 5 */
        uint16_t b1545NormalLowPowerFail 			: 1;     /* bit 6  */
      uint16_t b980ElectricalLowPowerFail	  : 1;     /* bit 7 */
      uint16_t b1545ElectricalLowPowerFail	: 1;     /* bit 8 */
} __attribute__ ((packed)) mpbFtaLowPowerBitAssignment_t;

typedef struct
{
    uint16_t b980nmcomputingError 							: 1;     /* bit 0 */
        uint16_t b1545nmcomputingError    					: 1;     /* bit 1 */
      uint16_t bLowTemperatureFail      					: 1;     /* bit 2 */
        uint16_t bNormalLowTemperatureFail 				  : 1;     /* bit 3  */
      uint16_t bElectricalFailLowTemperature			: 1;     /* bit 4 */
    uint16_t b980NormalLowTemperatureFail   		: 1;     /* bit 5 */
        uint16_t b1545NormalLowTemperatureFail 			: 1;     /* bit 6  */
      uint16_t b980ElectricalLowTemperatureFail	  : 1;     /* bit 7 */
      uint16_t b1545ElectricalLowTemperatureFail	: 1;     /* bit 8 */
} __attribute__ ((packed)) mpbFtaLowTempBitAssignment_t;

typedef struct
{
    uint8_t bIsAlarm 			: 1;     /* bit 0 */
        uint8_t bIsFault			: 1;     /* bit 1 */
      uint8_t bNormal				: 1;     /* bit 2 */

} __attribute__ ((packed)) mpbEventTypeBitsignment_t;

typedef enum
{
    mpbFtaCodeNoError = 0,
    mpbFtaCodeTempExtremLow ,
    mpbFtaCodePowerExtremLow ,
    mpbFtaCodePowerExtremHigh ,

}mpbFtaCode_t;

typedef struct
{
    eBool_t bMpbEventTypeDetectedNone;
    eBool_t bMpbEventTypeDetectedAlarm;
    eBool_t bMpbEventTypeDetectedFault;
}__attribute__ ((packed)) mpbEventTypeDetected_t;

typedef enum
{
    mpbFmeaNoError = 0,
    mpbFmeaLnaPowerMonitor,
    mpbFmeaLnaCurrentMonitor,
    mpbFmeaLnaTempMonitor,
    mpbFmeaHpaPowerMonitor

}mpbFmeaMode_t;
/*
typedef struct
{
    mpbFmeaMode_t 						 		mpbFmeaMode;
    mpbFtaCode_t 									mpbFtaCode;
    mpbFtaLowTempBitAssignment_t  mpbFtaLowTempBitAssignment;
    mpbFtaLowPowerBitAssignment_t mpbFtaLowPowerBitAssignment;

    uint32_t 											ulmpbLogEventTime;
    eMainLoopState_t 							eMpbLogMainLoopState;
    xLaserBeamDescriptor_t  			xMpbLogLaserBeamDescriptor;
}mpbLogEvent_t;*/


typedef struct
{
    uint8_t 															ucSampleNumber;
    mpbFmeaMode_t 						 						mpbFmeaMode;
//	mpbFtaCode_t 													mpbFtaCode;
    mpbFtaLowTempBitAssignment_t  				mpbFtaLowTempBitAssignment;
    mpbFtaLowPowerBitAssignment_t 				mpbFtaLowPowerBitAssignment;
    eMainLoopState_t 											eMpbLogMainLoopState;
    uint32_t 															ulmpbLogEventTime;
    eBeaconIdUsedActually_t 							xBeaconId;
  xLaserOperationMode_t									xLaserOperationMode[ NUMBER_OF_LEDS_BY_BOARD ];
    xElectricalVariablesStatus_t  				xElectricalVariablesStatus; //[ NUMBER_OF_LEDS_BY_BOARD ];
    eOperationMode_t 											eOperationMode;//[ NUMBER_OF_LEDS_BY_BOARD] ;
    eControlGeneralMode_t									eControlGeneralMode;

    xAlarmRegister_t 						 					xAlarmRegister ;
    xStatusRegister_t											xStatusRegister;
    xCriticalAnalogCurrents_t 						xCriticalAnalogCurrents;
    xCriticalAnalogPowers_t								xCriticalAnalogPowers;
    xAnalogTemperatureInputs_t						xAnalogTemperatureInputs;
    mpbEventTypeBitsignment_t							xEventType;
}__attribute__ ((packed)) xLaserLogEventDescriptor_t;



#endif
