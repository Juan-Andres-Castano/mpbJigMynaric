#ifndef LASERDIODEBEAM_H
#define LASERDIODEBEAM_H
/**
* @file		    LaserDiodeBeam.h
* @brief        LaserDiodeBeam header file.
* @author		juan
* @date			Created on 2021-3-12
* @copyright MPB, Montreal, Qc
* <h2><center>&copy; COPYRIGHT 2021 MPB, Montreal, Quebec, Canada</center></h2>
* <h2><center>&copy; All rights reserved.</center></h2><br/><br/>
* <center>This document contains confidential and proprietary information
* of MPB (subject to a non-disclosure agreement) and shall</center>
* <center>not be disclosed, distributed, or reproduced in whole or in
* part, without the prior written authorization of MPB.</center>
*
**/
/* Header guard ------------------------------------------------------------- */
/* Includes ----------------------------------------------------------------- */
#include "mpbLibs.h"
/* Define ------------------------------------------------------------------- */
#define	NUMBER_OF_LEDS_BY_BOARD  (  2  )
#define COMMAND_GET_STATUS ( 0x60 )
#define	LASER_1545_CODE  (  1  )
#define	LASER_980_CODE  (  2  )

/* Exported macro ----------------------------------------------------------- */
/* Exported enum ------------------------------------------------------------ */
enum
{
    e940MultiModeLaserDiode940 = 0,
    e980SingleModeLaserDiode980 = 1,
    eNumberTotalOfLaserBeams = 2
};
/* Exported struct ---------------------------------------------------------- */
/* alarms register bit */
/* meaning when bit value = 1 */
typedef struct
{
    uint32_t bDeviceIsAssignedHardwareAddress0 									: 1;     /* bit 0 */
    uint32_t bSp0IsthePrimarySerialPort					    						: 1;     /* bit 1 */
    uint32_t bMeMpryBankAIsUsedAtFirstBootUp	    						  : 1;     /* bit 2 - 0 : memory A, 1: memory B*/
    uint32_t bCodeFromMemoryBankAIsCurrentlyInUse    						: 1;     /* bit 3 - 0 : memory A, 1: memory B*/
    uint32_t bQfbIsInOffState																	  : 1;     /* bit 4 */
    uint32_t bQfbIsInReadyState														   		: 1;     /* bit 5 */
    uint32_t bQfbIsInOnState																	 	: 1;     /* bit 6 */
    uint32_t bQfbIsInFaultState																  : 1;     /* bit 7 */


    uint32_t bQfbIsIntestState														   	  : 1;     /* bit 8 */
    uint32_t bUnlockModeIsActive						  								  : 1;     /* bit 9 */
    uint32_t b980LaserDiodeDriverIsEnabled										  : 1;     /* bit 10 */
    uint32_t b980BeaconIsEmmitingPower												  : 1;     /* bit 11 */
    uint32_t b980LaserDiodeTecIsEnabled												  : 1;     /* bit 12 */
    uint32_t b980LaserDiodeCaseTemperatureIsNormal						  : 1;     /* bit 13 */
    uint32_t b980BeaconIsInAccMode								  					  : 1;     /* bit 14 */
    uint32_t b980BeaconIsInApcMode								  					  : 1;     /* bit 15 */


    uint32_t b940LaserDiodeDriverIsEnabled						 				  : 1;     /* bit 16 */
    uint32_t b1545nmBeaconIsEmittingPower												: 1;     /* bit 17 */
    uint32_t b940caseTemperatureIsInNormalRange									: 1;     /* bit 18 */
    uint32_t b1545nmBeaconIsInAccMode														: 1;     /* bit 19 */
    uint32_t b1545nmBeaconIsInApcMode														: 1;     /* bit 20 */
    uint32_t bResetLineFromOtherMcuSection											: 1;     /* bit 21 */
    uint32_t bPowerFailFromOtherMcuSection											: 1;     /* bit 22 */
    uint32_t bStatusSpare									  										: 9;     /* Bits   23-31  spare*/
}StatusRegisterBitAssignment_t;

typedef struct
{
    eBool_t  bPort;
    uint32_t ulMemoryId;
    uint32_t ulResetTime;
    uint32_t ulRunningTime;
    eBool_t  bTestMode;
}xBeaconStatus_t;

typedef enum
{
    eContinuosMode = 0,
    eModulantMode = 1,
    eNumberOfConrolModes = 2
}eControlGeneralMode_t;

typedef enum
{
    eAlarm = 0,
    eTest = 1,
    eIdle = 2,
    eAcc = 3,
    eApc = 4,

}eOperationMode_t;

typedef enum
{
    e980Beacon = 1,
    e940Beacon = 2,
    eBothBeacons = 3,
}eBeaconIdUsedActually_t;

typedef struct
{
    float			fQfbCaseTemperature;
    float			fQfbCaseRawTemperature;
    float 		f940MultiModeLaserDiodeTemperature;
    float 		f940MultiModeLaserDiodeRawTemperature;
    float 		f980SingleModeLaserDiodeTemperature;
    float 		f980SingleModeLaserDiodeRawTemperature;
    float			fQfbCaseTemperatureMpb;
    float			fQfbCaseRawTemperatureMpb;
    float			fCalibrationFactorQfbCase;
    float			fCalibrationFactor940MultiMode;
    float			fCalibrationFactor980singleMode;
    float 		f940MultiModeLaserDiodeTemperatureMpb;
    float 		f980SingleModeLaserDiodeTemperatureMpb;

}xAnalogTemperatureInputs_t;


typedef struct
{
    float f940MultiModeLaserDiodeCurrent;
    float f940MultiModeLaserDiodeRawCurrent;
    float f980SingleModeLaserDiodeCurrent;
    float f980SingleModeLaserDiodeRawCurrent;
    float f980LaserDiodeTecCurrent;
    float f980LaserDiodeTecRawCurrent;

}xCriticalAnalogCurrents_t;


typedef struct
{
    float f940CurrentSetpoint;
    float f980CurrentSetpoint;
    float fInternlaMcuTemperature;
    float fInternal_1_0_BandGapMonitor;
    float fInternal_1_5_BandGapMonitor;
    float fInternal_analog_1_5_Monitor;
    float fInternal_digital_1_5_Monitor;
    float fInternal_reference_2_5_Monitor;
}xNonCriticalInternalAnalogChannels_t;


typedef struct
{
    float fRs485Sp1Negative;
    float fRs485Sp1CommonPositive;
    float fRs485Sp0Negative;
    float fRAMBankACurrentMonitor;
    float fRAMBankACurrentCommonPositive;
    float fRAMBankBCurrentMonitor;
    float fPhotoDiodeOffset;
    float f980BackFacetMonitor;
}xNonCriticalExternalAnalogChannels_t;

typedef struct
{
    float f1545OutputPower;
    float f1545OutputRawPower;
    float f980OutputPower;
    float f980OutputRawPower;
    float f1545FakeOutputPower;
    float f980FakeOutputPower;
}xCriticalAnalogPowers_t;

typedef struct
{
    uint16_t 											usActiveSetpoint;
    uint16_t 											usPowerSetpoint;
    uint16_t 											usCurrentSetpoint;
    uint16_t 											usCurrentThresholdSetpoint;
    float	 												fTemperatureSetpoint;
    uint16_t 											usLedPower;				 		//Actual Peak Power  todo...
    uint16_t 											usFrequency;
}xElectricalVariablesStatus_t;

typedef struct
{
    int16_t 											sThresholdForAlarmLowInternal_2_5VoltageMonitor;
    int16_t 											sThresholdForAlarmHighInternal_2_5VoltageMonitor;
    int16_t 											sThresholdForPhotoDiodeOffsetTooHigh;
    int16_t 											sThresholdForPhotoDiodeOffsetTooLow;
}xAlarmsThresholdsForVoltageValues_t;

typedef struct
{
    int16_t 											sThresholdForAlarmLow1545OutputPower;
    int16_t 											sThresholdForAlarmHigh1545OutputPower;
    int16_t 											sThresholdForFaultHigh1545OutputPower;
    int16_t 											sThresholdForAlarmLow980OutputPower;
    int16_t 											sThresholdForAlarmHigh980OutputPower;
    int16_t 											sThresholdForFaultHigh980OutputPower;
}xAlarmsThresholdsForPowerValues_t;

typedef struct
{
    int16_t 											sThresholdForAlarm940TooLowWrtToSetPoint;
    int16_t 											sThresholdForAlarm940TooHigh;
    int16_t 											sThresholdForAlarm940WayTooHigh;

    int16_t 											sThresholdForAlarm980TooLowWrtToSetPoint;
    int16_t 											sThresholdForAlarm980TooHigh;
    int16_t 											sThresholdForAlarm980WayTooHigh;

    int16_t 											sThresholdForAlarmTecTooHigh;
    int16_t 											sThresholdForAlarmTecWayTooHigh;

    int16_t 											sThresholdForFault940MultiModeDiodeCurrentSetpointTooHigh;
    int16_t 											sThresholdForFault980SingleModeDiodeCurrentSetpointTooHigh;

    int16_t 											sThresholdForAlarmRs485Sp1NegativeTooHigh;
    int16_t 											sThresholdForAlarmRs485Sp0NegativeTooHigh;
    int16_t 											sThresholdForAlarmFramBankANegativeTooHigh;
    int16_t 											sThresholdForAlarmFramBankBNegativeTooHigh;

}xAlarmsThresholdsForCurrentValues_t;


typedef struct
{
    int16_t 											sMaxSetpointCurrent940;
    int16_t 											sMaxSetpointCurrent980;
    uint16_t 										sMaxSetpointPower940;
    uint16_t 											sMaxSetpointPower980;
}xMaxSetpointsAllowed_t;


typedef struct
{
    uint16_t 										uMinSetpointPower940;
    uint16_t 										uMinSetpointPower980;
}xMinSetpointsAllowed_t;

typedef struct
{
    /* qfb */
    int16_t 											sThresholdForQfbAlarmExtraLowTemperature;
    int16_t 											sThresholdForQfbAlarmLowTemperature;
    int16_t 											sThresholdForQfbAlarmHighTemperature;
    int16_t 											sThresholdForQfbAlarmExtraHighTemperature;
    /* 980*/
    int16_t 											sThresholdFor980AlarmWayTooLowTemperature;
    int16_t 											sThresholdFor980AlarmTooLowTemperature;
    int16_t 											sThresholdFor980AlarmTooHighTemperature;
    int16_t 											sThresholdFor980AlarmWayTooHighTemperature;
    /* 940*/
    int16_t 											sThresholdFor940AlarmWayTooLowTemperature;
    int16_t 											sThresholdFor940AlarmTooLowTemperature;
    int16_t 											sThresholdFor940AlarmTooHighTemperature;
    int16_t 											sThresholdFor940AlarmWayTooHighTemperature;

    int16_t 											sThresholdForInternalMcuWayTooLowTemperature;
    int16_t 											sThresholdForInternalMcuLowTemperature;
    int16_t 											sThresholdForInternalMcuHighTemperature;
    int16_t 											sThresholdForInternalMcuWayTooHighTemperature;


}xAlarmsThresholdsForTemperatureValues_t;

typedef struct
{
    xAlarmsThresholdsForPowerValues_t				xAlarmsThresholdsForPowerValues;
    xAlarmsThresholdsForCurrentValues_t			xAlarmsThresholdsForCurrentValues;
    xAlarmsThresholdsForTemperatureValues_t	xAlarmsThresholdsForTemperatureValues;
    xAlarmsThresholdsForVoltageValues_t			xAlarmsThresholdsForVoltageValues;
}xAlarmsThresholdsValues_t;




typedef struct
{
    eBool_t 	 										bLaserIsEnable;
    eBool_t    										bLaserIsInTestMode;
    eBool_t    										bTecIsEnable;
}xLaserOperationMode_t;


typedef union
{
    StatusRegisterBitAssignment_t StatusRegisterBitAssignment;
    uint8_t											ucStatusRegistersBytes[4];
    uint32_t										ulStatusRegisterValue;
}xStatusRegister_t;

typedef struct
{
    uint32_t MinCurrent;
    uint32_t MaxCurrent;
    uint32_t MinPower;
    uint32_t MaxPower1545;
    uint32_t MaxPower980;
}xLoggerValues_t;

typedef enum
{
    eLaserStateInit = 0,
    eLaserStateWise,
    eLaserStateBrake,
    eLaserStateFULL,
}eLaserState_t;

typedef enum
{
    eApcControlStateInit = 0,
    eApcControlStateIdle,
    eApcControlStateNormal,
    eApcControlStateAlarm,
    eApcControlStateConfiguration,
}eApcControlState_t;

typedef enum
{
    eFramAisthefirstboot = 1,
    eFramBisthefirstboot = 2,

}eFramIsFirstBoot_t;


typedef struct
{
    uint8_t																ucAdditionCheck;
    uint8_t																ucUpdateFirmwareIsDemanded;
    uint8_t																ucBootMemoryisUsedatBootup;
    uint8_t																ucBootMemoryAisDemandedAsBootup;
    uint8_t																ucBootMemoryErrorcomError;
    uint8_t																ucBootMemoryErrorTpowerUp;
    uint8_t																ucIsAnErrorInMemoryACrc;
    uint8_t																ucIsAnErrorInMemoryBCrc;
    uint8_t																ucIsAnErrorInMemoryA;
    uint8_t																ucIsAnErrorInMemoryB;
    uint16_t															usCrcCalculatedMemoryA;
    uint16_t															usCrcCalculatedMemoryB;
    uint16_t															usCrcSavedMemoryA;
    uint16_t															usCrcSavedMemoryB;
    float 																fBootloaderVersion;
}xInfoFromBootloader_t;


typedef struct
{
    float fPGain;
    float fIGain;
    float fDGain;
}xPidValues_t;


typedef struct
{
    xMinSetpointsAllowed_t								xMinSetpointsAllowed;
    xMaxSetpointsAllowed_t								xMaxSetpointsAllowed;
    eBeaconIdUsedActually_t 							xBeaconId;
    uint16_t 															usSetNewLedTemperature;
    uint16_t 															usLowCurrent[ NUMBER_OF_LEDS_BY_BOARD ];
    uint16_t 															usLowPower[ NUMBER_OF_LEDS_BY_BOARD ];
    xLaserOperationMode_t									xLaserOperationMode[ NUMBER_OF_LEDS_BY_BOARD ];
    xElectricalVariablesStatus_t  				xElectricalVariablesStatus[ NUMBER_OF_LEDS_BY_BOARD ];
    eOperationMode_t 											eOperationMode[ NUMBER_OF_LEDS_BY_BOARD] ;
    eControlGeneralMode_t									eControlGeneralMode;
    xBeaconStatus_t  											xBeaconStatus;

    xAlarmsThresholdsValues_t							xAlarmsThresholdsValues;
    xStatusRegister_t											xStatusRegister;
    xCriticalAnalogCurrents_t 						xCriticalAnalogCurrents;
    xCriticalAnalogPowers_t								xCriticalAnalogPowers;
    xAnalogTemperatureInputs_t						xAnalogTemperatureInputs;
    xNonCriticalInternalAnalogChannels_t	xNonCriticalInternalAnalogChannels;
    xNonCriticalExternalAnalogChannels_t	xNonCriticalExternalAnalogChannels;
    xLoggerValues_t												xLoggerValues;
    xPidValues_t													xPidValues[ NUMBER_OF_LEDS_BY_BOARD] ;
    eBool_t																eNvmMemoryUpdateIdNeeded;
    eBool_t 	 														bHardwiredSignalIsActivated;

    uint8_t											          cSoftwareVersion[4];
    uint8_t											          cIdNumber;
    uint8_t											          cSerialNumber;
    eBool_t												        bExternalMemoryIsReadedAndHaveGoodData;
    eBool_t																bSystemIsUnLocked;
    eBool_t																bSystemIsInTestMode;
    eBool_t																bSystemIsBoosted;
    uint16_t 															usCrc16Value;
    uint16_t															usCrc16CalculatedA;
    uint32_t															ulTimer980;
    uint32_t															ulTimer1545;
    //	uint8_t																ucBootMemoryAisDemandedAsBootup;

} xLaserBeamDescriptor_t;





typedef enum
{
    eThreshold1545OutputPower = 0,
    eThreshold1980OutputPower = 1,
    eThresholdQfbCaseTemperature = 2,
    eThreshold940MultiModeLaserDiodeCurrent = 3,
    eThreshold980SingleModeLaserDiodeCurrent = 4,
    eThreshold940MultiModeLaserDiodeCaseTemperature = 5,
    eThreshold980SingleModeLaserDiodeCaseTemperature = 6,
    eThreshold980LaserDiodeTecCurrent = 7,
    eThreshold940MultiModeLaserDiodeCurrentSetpoint = 8,
    eThreshold980SingleModeLaserDiodeCurrentSetpoint = 9,
    eThresholdInternalMcuTemperature = 10,
    eThresholdInternal_1_0_bandGapMonitor = 11,
    eThresholdInternal_1_5_bandGapMonitor = 12,
    eThresholdInternalAnalog_1_5_Monitor = 13,
    eThresholdInternalDigital_1_5_Monitor = 14,
    eThresholdInternal_2_5_V_referenceVoltageMonitor = 15,
    eThresholdRs485CurrentMonitorSp1Negative = 16,
    eThresholdRs485CurrentMonitorCommonPositive = 17,
    eThresholdRs485CurrentMonitorSp0Negative = 18,
    eThresholdFramMemoryCurrentMonitorBankANegative = 19,
    eThresholdFramMemoryCurrentMonitorCommonPositive = 20,
    eThresholdFramMemoryCurrentMonitorBankBNegative = 21,
    eThresholdPhotoDiodeOffset = 22,
    eThreshold980SingleModeLaserDiodeBackFacetMonitor = 23,
    eThresholdTotalNumberOfIndexAlarms = 24,
}eThresholdValues_t;

typedef struct
{
    uint64_t b980nmLaserDiodeTemperatureIsWayTooLow 						: 1;     /* bit 0 - FAULT*/
    uint64_t b980nmLaserDiodeTemperatureIsTooLow    						: 1;     /* bit 1 */
    uint64_t b980nmLaserDiodeTemperatureIsToohigh    						: 1;     /* bit 2 */
    uint64_t b980nmLaserDiodeTemperatureIsWayToohigh 						: 1;     /* bit 3  - FAULT */
    uint64_t b980BeaconOutputPowerIsTooLowWithRtoSetPoint			  : 1;     /* bit 4 */
    uint64_t b980BeaconOutputPowerIsTooHighWithRtoSetPoint   		: 1;     /* bit 5 */
    uint64_t b980BeaconOutputPowerIsWayTooHighWithRtoSetPoint 	: 1;     /* bit 6  - FAULT - this could be PD saturation fault */
    uint64_t b980LaserDiodeCurrentIsTooLowWithRespToSetpoint	  : 1;     /* bit 7 */


    uint64_t b980LaserDiodeCurrentIsTooHigh								   	  : 1;     /* bit 8 */
    uint64_t b980LaserDiodeCurrentIsWayTooHigh								  : 1;     /* bit 9 - FAULT */
    uint64_t b980LaserDiodeControlValueMismatch								  : 1;     /* bit 10 - compare internal ADC feedback value and compare with DAC control value, if difference is greater than xxx, then declare alarm */
    uint64_t b980LaserDiodeTecCurrentIsTooHigh								  : 1;     /* bit 11 */
    uint64_t b980LaserDiodeTecCurrentIsWayTooHigh							  : 1;     /* bit 12 - FAULT */
    uint64_t b940LaserDiodeTemperatureIsWayTooLow							  : 1;     /* bit 13 - FAULT */
    uint64_t b940LaserDiodeTemperatureIsTooLow		  					  : 1;     /* bit 14 */
    uint64_t b940LaserDiodeTemperatureIsTooHigh		  					  : 1;

    /* bit 15 */
    uint64_t b940LaserDiodeTemperatureIswayTooHigh		 				  : 1;     /* bit 16 - FAULT */
    uint64_t b1545nmBeaconOutputPowerIsTooLowWrToSetpoint				: 1;     /* bit 17 */
    uint64_t b1545nmBeaconOutputPowerIsTooHighWrToSetpoint			: 1;     /* bit 18 */
    uint64_t b1545nmBeaconOutputPowerIswayTooHighWrToSetpoint		: 1;     /* bit 19 - this could be PD saturation fault */
    uint64_t b940nmLaserDiodeCurrentIsTooLowWrToSetpoint				: 1;     /* bit 20 */
    uint64_t b940nmLaserDiodeCurrentIsTooHigh										: 1;     /* bit 21 */
    uint64_t b940nmLaserDiodeCurrentIsWayTooHigh								: 1;     /* bit 22 - FAULT */
    uint64_t b940nmLaserDiodeControlValueMismatch								: 1;     /* bit 23 - compare internal ADC feedback value and compare with DAC control value, if difference is greater than xxx, then declare alarm */


    uint64_t bQfbHousingTemperatureIsWayTooLow   								: 1;     /* bit 24 - FAULT */
    uint64_t bQfbHousingTemperatureIsTooLow		   								: 1;     /* bit 25  */
    uint64_t bQfbHousingTemperatureIsTooHigh	   								: 1;     /* bit 26  */
    uint64_t bQfbHousingTemperatureIsWayTooHigh  								: 1;     /* bit 27  - FAULT */
    uint64_t bPhotoDiodeOffsetVoltageTooLow		  								: 1;     /* bit 28 */
    uint64_t bPhotoDiodeOffsetVoltageTooHigh		  							: 1;     /* bit 29 */
    uint64_t bMcuInternal_2_5_V_ReferenceVoltageTooLow					: 1;     /* bit 30 */
    uint64_t bMcuInternal_2_5_V_ReferenceVoltageTooHigh					: 1;     /* bit 31 */



    uint64_t bMcuInternalTemperatureIsWayTooLow									: 1;     /* bit 32 */
    uint64_t bMcuInternalTemperatureIsTooLow										: 1;     /* bit 33 */
    uint64_t bMcuInternalTemperatureIsTooHigh										: 1;     /* bit 34 */
    uint64_t bMcuInternalTemperatureIsWayTooHigh								: 1;     /* bit 35 */
    uint64_t bSerialPort0HasAReceiveError												: 1;     /* bit 36 */
    uint64_t bSerialPort0HasATransmitError											: 1;     /* bit 37 */
    uint64_t bSerialPort1HasAReceiveError												: 1;     /* bit 38 */
    uint64_t bSerialPort1HasATransmitError											: 1;     /* bit 39 */


    uint64_t bBootMemoryCommunicationError											: 1;     /* bit 40 */
    uint64_t bMemoryACommunicationError													: 1;     /* bit 41 */
    uint64_t bMemoryBCommunicationError													: 1;     /* bit 42 */
    uint64_t bBootMemoryCrcErrorDetectedAtPowerUp								: 1;     /* bit 43 */
    uint64_t bMemoryACrcErrorDetectedAtPowerUp									: 1;     /* bit 44 */
    uint64_t bMemoryBCrcErrorDetectedAtPowerUp									: 1;     /* bit 45 */
    uint64_t bSerialPort0HasAReceivedErrorCondition							: 1;     /* bit 46 */
    uint64_t bSerialPort1HasAReceivedErrorCondition							: 1;     /* bit 47 */



    uint64_t bErrorDetectedInProramMemoryA											: 1;     /* bit 48 */
    uint64_t bErrorDetectedInProramMemoryB											: 1;     /* bit 49 */
    uint64_t bErrorDetectedInDataMemoryA												: 1;     /* bit 50 */
    uint64_t bErrorDetectedInDataMemoryB												: 1;     /* bit 51 */
    uint64_t bCalibrationDataIsMissing													: 1;     /* bit 52 */
    uint64_t bAlarmConditionFromOtherMcuSection									: 1;     /* bit 53 */
    uint64_t bSpiAdcTimeoutAlarm																: 1;     /* bit 54 */
    uint64_t b422TransceiversSp0drawExcessiceCurrent						: 1;     /* bit 55 */

    uint64_t b422TransceiversSp1drawExcessiceCurrent						: 1;     /* bit 56 */
    uint64_t bMemoryADrwasExcessiceCurrent											: 1;     /* bit 57 - suspect SEU */
    uint64_t bMemoryBDrwasExcessiceCurrent											: 1;     /* bit 58 - suspect SEU */
    uint64_t bAlarmsSpare									  										: 5;    /* Bits   59...63  spare*/
} AlarmsRegisterBitAssignment_t;


typedef union
{
    AlarmsRegisterBitAssignment_t AlarmsRegisterBitAssignment;
    uint8_t												AlarmsRegisterBytes[8];
    uint64_t 											AlarmGlobalValue;

}xAlarmRegister_t;
/* Global variables --------------------------------------------------------- */
/* Exported function prototypes --------------------------------------------- */

#endif // LASERDIODEBEAM_H

