#ifndef CANDICTIONARY_H
#define CANDICTIONARY_H

//#include "mpbLibs.h"
#include "dictionaryutils.h"


/* Define ------------------------------------------------------------------- */
#define DEF_CAN_0401_INTERNAL_MOUNTING_TEMPERATURE               0
#define DEF_CAN_0401_PUMP1_CURRENT_IN_BOOSTER					 8
#define DEF_CAN_0401_PUMP2_CURRENT_IN_BOOSTER					 16
#define DEF_CAN_0401_PUMP3_CURRENT_IN_BOOSTER					 24
#define DEF_CAN_0401_PUMP4_CURRENT_IN_LNA						 32
#define DEF_CAN_0401_BOOSTER_OPTICAL_INPUT_POWER   				 40
#define DEF_CAN_0401_LNA_OPTICAL_OUTPUT_POWER   				 48
#define DEF_CAN_0401_BOOSTER_OPTICAL_OUTPUT_POWER   			 56

#define DEF_CAN_0402_POWER_SUPPLY_VOLTAGE			             15
#define DEF_CAN_0402_LASER_PUMP1_TEMPERATURE		             20
#define DEF_CAN_0402_LASER_PUMP2_TEMPERATURE		             27
#define DEF_CAN_0402_LASER_PUMP3_TEMPERATURE		             34
#define DEF_CAN_0402_LASER_PUMP_TEMPERATURE_LNA		             41
#define DEF_CAN_0402_BACKFACER_CURRENT_PUMP1_BOOSTER             48
#define DEF_CAN_0402_BACKFACER_CURRENT_PUMP_LNA		             56

#define DEF_CAN_0406_LASER_PUMP1_IN_BOOSTER			             8
#define DEF_CAN_0406_LASER_PUMP2_IN_BOOSTER			             16
#define DEF_CAN_0406_LASER_PUMP3_IN_BOOSTER			             24
#define DEF_CAN_0406_RESET							             32
#define DEF_CAN_0406_LASER_PUMP_IN_LNA				             36
#define DEF_CAN_0406_OPTICAL_POWER_RANGE_BOOSTER	             44

#define DEF_RANGE_1_HIGH_LIMIT_SETPOINT_POWER_LNA	             ( -2.98 )
#define DEF_DECIMAL_RANGE_1_HIGH_LIMIT_SETPOINT_POWER_LNA	    ( 11 )


#define DEF_X1_COORDINATE_LINEAR_APROXIMATION_ENCODE			( -30.0)
#define DEF_Y1_COORDINATE_LINEAR_APROXIMATION_ENCODE			( 0.0)
#define DEF_X2_COORDINATE_LINEAR_APROXIMATION_ENCODE			( 38.0)
#define DEF_Y2_COORDINATE_LINEAR_APROXIMATION_ENCODE			( 255.0)

#define DEF_X1_COORDINATE_LINEAR_APROXIMATION_DECODE_RANGE1		( 0.0 )
#define DEF_Y1_COORDINATE_LINEAR_APROXIMATION_DECODE_RANGE1		( -30.0 )
#define DEF_X2_COORDINATE_LINEAR_APROXIMATION_DECODE_RANGE1		( 255.0 )
#define DEF_Y2_COORDINATE_LINEAR_APROXIMATION_DECODE_RANGE1		( 37.5 )

#define DEF_X1_COORDINATE_LINEAR_APROXIMATION_DECODE_RANGE2		( 0.0 )
#define DEF_Y1_COORDINATE_LINEAR_APROXIMATION_DECODE_RANGE2		( -30.0 )
#define DEF_X2_COORDINATE_LINEAR_APROXIMATION_DECODE_RANGE2		( 255.0 )
#define DEF_Y2_COORDINATE_LINEAR_APROXIMATION_DECODE_RANGE2		( 38.0 )



#define X1_PUMP1_TEMP_BOOSTER_LINEAR_APROXIMATION_ENCODE		( -40.0)
#define Y1_PUMP1_TEMP_BOOSTER_LINEAR_APROXIMATION_ENCODE		( 0.0)
#define X2_PUMP1_TEMP_BOOSTER_LINEAR_APROXIMATION_ENCODE		( 90.0)
#define Y2_PUMP1_TEMP_BOOSTER_LINEAR_APROXIMATION_ENCODE		( 127.0)

#define X1_BACKFACET_CURRENT_BOOSTER_LINEAR_APROXIMATION_ENCODE	( 0.0)
#define Y1_BACKFACET_CURRENT_BOOSTER_LINEAR_APROXIMATION_ENCODE	( 1000.0)
#define X2_BACKFACET_CURRENT_BOOSTER_LINEAR_APROXIMATION_ENCODE	( 0.0)
#define Y2_BACKFACET_CURRENT_BOOSTER_LINEAR_APROXIMATION_ENCODE	( 255.0)

#define X1_INTERNAL_TEMP_SURFACE_TEMP_LINEAR_APROX_ENCODE		( -40.0)
#define Y1_INTERNAL_TEMP_SURFACE_TEMP_LINEAR_APROX_ENCODE		( 0.0)
#define X2_INTERNAL_TEMP_SURFACE_TEMP_LINEAR_APROX_ENCODE		( 90.0)
#define Y2_INTERNAL_TEMP_SURFACE_TEMP_LINEAR_APROX_ENCODE		( 255.0)

#define X1_LASER_PUM1_CURRENT_BOOSTER_LINEAR_APROX_ENCODE		( 0.0)
#define Y1_LASER_PUM1_CURRENT_BOOSTER_LINEAR_APROX_ENCODE		( 0.0)
#define X2_LASER_PUM1_CURRENT_BOOSTER_LINEAR_APROX_ENCODE		( 1000.0)
#define Y2_LASER_PUM1_CURRENT_BOOSTER_LINEAR_APROX_ENCODE		( 255.0)

#define X1_LASER_PUM2_CURRENT_BOOSTER_LINEAR_APROX_ENCODE		( 0.0)
#define Y1_LASER_PUM2_CURRENT_BOOSTER_LINEAR_APROX_ENCODE		( 0.0)
#define X2_LASER_PUM2_CURRENT_BOOSTER_LINEAR_APROX_ENCODE		( 1000.0)
#define Y2_LASER_PUM2_CURRENT_BOOSTER_LINEAR_APROX_ENCODE		( 255.0)

#define X1_LASER_PUM3_CURRENT_BOOSTER_LINEAR_APROX_ENCODE		( 0.0)
#define Y1_LASER_PUM3_CURRENT_BOOSTER_LINEAR_APROX_ENCODE		( 0.0)
#define X2_LASER_PUM3_CURRENT_BOOSTER_LINEAR_APROX_ENCODE		( 1000.0)
#define Y2_LASER_PUM3_CURRENT_BOOSTER_LINEAR_APROX_ENCODE		( 255.0)

#define X1_LASER_PUM4_CURRENT_LNA_LINEAR_APROX_ENCODE		( 0.0)
#define Y1_LASER_PUM4_CURRENT_LNA_LINEAR_APROX_ENCODE		( 0.0)
#define X2_LASER_PUM4_CURRENT_LNA_LINEAR_APROX_ENCODE		( 1000.0)
#define Y2_LASER_PUM4_CURRENT_LNA_LINEAR_APROX_ENCODE		( 255.0)

#define X1_LASER_PUM4_POWER_LNA_RANGE1_LINEAR_APROX_ENCODE		( -13.0)
#define Y1_LASER_PUM4_POWER_LNA_RANGE1_LINEAR_APROX_ENCODE		( 0.0)
#define X2_LASER_PUM4_POWER_LNA_RANGE1_LINEAR_APROX_ENCODE		( -3.0)
#define Y2_LASER_PUM4_POWER_LNA_RANGE1_LINEAR_APROX_ENCODE		( 10.0)

#define X1_LASER_PUM4_POWER_LNA_RANGE2_LINEAR_APROX_ENCODE		( -2.98)
#define Y1_LASER_PUM4_POWER_LNA_RANGE2_LINEAR_APROX_ENCODE		( 11.0)
#define X2_LASER_PUM4_POWER_LNA_RANGE2_LINEAR_APROX_ENCODE		( 0.0 )
#define Y2_LASER_PUM4_POWER_LNA_RANGE2_LINEAR_APROX_ENCODE		( 255.0)


#define X1_POWER_SETPOINT_BOOST_RANGE1_LINEAR_APROX_ENCODE		( -30.0)
#define Y1_POWER_SETPOINT_BOOST_RANGE1_LINEAR_APROX_ENCODE		( 0.0)
#define X2_POWER_SETPOINT_BOOST_RANGE1_LINEAR_APROX_ENCODE		( 37.5 )
#define Y2_POWER_SETPOINT_BOOST_RANGE1_LINEAR_APROX_ENCODE		( 680.0)

#define X1_POWER_SETPOINT_BOOST_RANGE2_LINEAR_APROX_ENCODE		( 37.6)
#define Y1_POWER_SETPOINT_BOOST_RANGE2_LINEAR_APROX_ENCODE		( 681.0)
#define X2_POWER_SETPOINT_BOOST_RANGE2_LINEAR_APROX_ENCODE		( 40.0 )
#define Y2_POWER_SETPOINT_BOOST_RANGE2_LINEAR_APROX_ENCODE		( 1024.0)


#define X1_CHANEL_30_1553_NM_INPUT_OPT_POW_BOOSTER_ENCODE		( 0.0)
#define Y1_CHANEL_30_1553_NM_INPUT_OPT_POW_BOOSTER_ENCODE		( 0.0)
#define X2_CHANEL_30_1553_NM_INPUT_OPT_POW_BOOSTER_ENCODE		( 1000.0)
#define Y2_CHANEL_30_1553_NM_INPUT_OPT_POW_BOOSTER_ENCODE		( 255.0)

#define X1_CHANEL_1_CH51_1536_NM_IN_OPT_POW_BOOSTER_ENCODE		( 0.0)
#define Y1_CHANEL_1_CH51_1536_NM_IN_OPT_POW_BOOSTER_ENCODE		( 0.0)
#define X2_CHANEL_1_CH51_1536_NM_IN_OPT_POW_BOOSTER_ENCODE		( 1000.0)
#define Y2_CHANEL_1_CH51_1536_NM_IN_OPT_POW_BOOSTER_ENCODE		( 255.0)

#define X1_CHANEL_30_1553_NM_OUTPUT_POW_LNA_ENCODE				( 0.0)
#define Y1_CHANEL_30_1553_NM_OUTPUT_POW_LNA_ENCODE				( 0.0)
#define X2_CHANEL_30_1553_NM_OUTPUT_POW_LNA_ENCODE				( 1000.0)
#define Y2_CHANEL_30_1553_NM_OUTPUT_POW_LNA_ENCODE				( 255.0)

#define X1_CHANEL_51_1536_NM_OUTPUT_POW_LNA_ENCODE				( 0.0)
#define Y1_CHANEL_51_1536_NM_OUTPUT_POW_LNA_ENCODE				( 0.0)
#define X2_CHANEL_51_1536_NM_OUTPUT_POW_LNA_ENCODE				( 1000.0)
#define Y2_CHANEL_51_1536_NM_OUTPUT_POW_LNA_ENCODE				( 255.0)

#define FIRST_LIMIT_FOR_BOOSTER_OUTPUT_OPTICAL_POWER			( 20 )  /*in dBm */
#define FIRST_LIMIT_FOR_BOOSTER_OUTPUT_OPTICAL_POWER_			( 19 )  /*in dBm */
#define FIRST_DECIMAL_LIMIT_FOR_BOOSTER_OUTPUT_OPTICAL_POWER	( 17 ) /* in decimal */
#define SECOND_LIMIT_FOR_BOOSTER_OUTPUT_OPTICAL_POWER			( 37 )
#define SECOND_DECIMAL_LIMIT_FOR_BOOSTER_OUTPUT_OPTICAL_POWER	( 193 )
#define THIRD_LIMIT_FOR_BOOSTER_OUTPUT_OPTICAL_POWER			( 40 )
#define THIRD_DECIMAL_LIMIT_FOR_BOOSTER_OUTPUT_OPTICAL_POWER	( 255 )

#define X1_RANGE_1_BOOSTER_OUTPUT_OPTICAL_POWER					( -30.0)
#define Y1_RANGE_1_BOOSTER_OUTPUT_OPTICAL_POWER					( 0.0 )
#define X2_RANGE_1_BOOSTER_OUTPUT_OPTICAL_POWER					( 19.0)
#define Y2_RANGE_1_BOOSTER_OUTPUT_OPTICAL_POWER					( 17.0 )

#define X1_RANGE_2_BOOSTER_OUTPUT_OPTICAL_POWER					( 20.0)
#define Y1_RANGE_2_BOOSTER_OUTPUT_OPTICAL_POWER					( 18.0 )
#define X2_RANGE_2_BOOSTER_OUTPUT_OPTICAL_POWER					( 36.0)
#define Y2_RANGE_2_BOOSTER_OUTPUT_OPTICAL_POWER					( 193.0 )

#define X1_RANGE_3_BOOSTER_OUTPUT_OPTICAL_POWER					( 37.0)
#define Y1_RANGE_3_BOOSTER_OUTPUT_OPTICAL_POWER					( 194.0 )
#define X2_RANGE_3_BOOSTER_OUTPUT_OPTICAL_POWER					( 40.0)
#define Y2_RANGE_3_BOOSTER_OUTPUT_OPTICAL_POWER					( 255.0 )


#define DEF_LIMIT_RANGE1_POWER_SETPOINT							( 37.6 )
#define DEF_DECIMAL_LIMIT_RANGE1_POWER_SETPOINT					( 681 )
#define DEF_PRECITION											( 1 )


/* Exported macro ----------------------------------------------------------- */
/* Exported enum ------------------------------------------------------------ */
typedef union {
    uint64_t value;
    struct {
        uint32_t low;
        uint32_t high;
    };
    struct {
        uint16_t s0;
        uint16_t s1;
        uint16_t s2;
        uint16_t s3;
    };
    uint8_t bytes[8];
    uint8_t byte[8]; //alternate name so you can omit the s if you feel it makes more sense
} BytesUnion;

typedef union {
    float fValue;
    uint8_t bytes[4];
    uint32_t ulValue;
} floatUnion;

typedef struct
{
    uint32_t id;		// EID if ide set, SID otherwise
    uint32_t fid;		// family ID
    uint8_t rtr;		// Remote Transmission Request
    uint8_t priority;	// Priority but only important for TX frames and then only for special uses.
    uint8_t extended;	// Extended ID flag
    uint8_t length;		// Number of data bytes
    BytesUnion data;	// 64 bits - lots of ways to access it.
} CAN_FRAME;

/* Exported struct ---------------------------------------------------------- */
typedef struct
{
    uint16_t bStatusLaserPump1Booster 						: 1;     /* bit 0 */
    uint16_t bStatusLaserPump2Booster 						: 1;     /* bit 1 */
    uint16_t bStatusLaserPump3Booster 						: 1;     /* bit 2 */
    uint16_t bStatusLaserPumpLna	 						: 1;     /* bit 3 */
    uint16_t bStatusBoosterMode		 						: 1;     /* bit 4 - (0: ACC, 1: APC) */
    uint16_t bStatusLnaMode			 						: 1;     /* bit 5 - (0: ACC, 1: APC) */
    uint16_t bRxOutputChannelSelectionLna					: 1;     /* bit 6 - (0: amplified CH30-1553nm, 1: amplified CH51-1536nm) */
    uint16_t bRxInputChannelSelectionBoost					: 1;     /* bit 7 - (0: amplified CH30-1553nm, 1: amplified CH51-1536nm) */
    uint16_t bLimitAlarmOpticalPowerOutputLna				: 1;     /* bit 8 - (0: within limits, 1: out of limits) */
    uint16_t bLimitAlarmCurrentLaserPumpLna					: 1;     /* bit 9 - (0: within limits, 1: out of limits) */
    uint16_t bLimitAlarmOpticalPowerInputAndOutputBooster	: 1;     /* bit 10 - (0: within limits, 1: out of limits) */
    uint16_t bLimitAlarmCurrentallLaserPumpsBooster			: 1;     /* bit 11 - (0: within limits, 1: out of limits) */
    uint16_t bLimitAlarmPumpLaserBackFacetLna				: 1;     /* bit 12 - (0: within limits, 1: out of limits) */
    uint16_t bLimitAlarmforUnitTemperature					: 1;     /* bit 13 - (0: within limits, 1: out of limits) */
    uint16_t bAlarmsafetyShutdown							: 1;     /* bit 14 - (0: normal operation, 1: critical error) */
    uint16_t bAlarmsSpare									: 1;    /* spare*/
} AlarmsAndStatusRegisterBitAssignment_t;

typedef union
{
    AlarmsAndStatusRegisterBitAssignment_t	AlarmsAndStatusRegisterBitAssignment;
    uint8_t									AlarmsStatusRegisterBytes[2];
    uint16_t 								AlarmStatusGlobalValue;

}xAlarmAndStatusRegister_t;

typedef struct
{
    eBool_t bEnablePumpLaser1OnBooster 						: 1;     /* bit 0 (0: disable; 1 enable), default is disabled */
    eBool_t bEnablePumpLaser2OnBooster						: 1;     /* bit 1  (0: disable; 1 enable) */
    eBool_t bEnablePumpLaser3OnBooster   					: 1;     /* bit 2 - (0: disable; 1 enable)*/
    eBool_t bEnablePumpLaserOnLna							: 1;     /* bit 3 - (0: disable; 1 enable) */
    eBool_t bSetBoosterMode		 							: 1;     /* bit 4 - (0: ACC; 1: APC), default is ACC. */
    eBool_t bSetLnaMode 			 						: 1;     /* bit 5 - (0: ACC; 1: APC), default is ACC. */
    eBool_t bSetRxChannelOnLna								: 1;     /* bit 6 - (0: CH30-1553nm; 1: CH51-1536nm), default is CH30-1553nm.*/
    eBool_t bSetTxChannelOnBooster							: 1;     /* bit 7 - (0: CH30-1553nm; 1: CH51-1536nm), default is CH30-1553nm. */
} Status_406_RegisterBitAssignment_t;

typedef union
{
    Status_406_RegisterBitAssignment_t Status_406_RegisterBitAssignment;
    uint8_t							   ucStatus_406_RegisterGlobalValue;
}Status_406_Register_t;




typedef struct
{
    float						fInternalMountingSurfaceTemperature;
    float						fLaserPump1CurrentOfBooster;
    float						fLaserPump2CurrentOfBooster;
    float						fLaserPump3CurrentOfBooster;
    float						fLaserPump4CurrentOfLna;
    float						fBoosterOpticalInputPower;
    float						fLnaOpticalOutputPower;
    float						fBoosterOutputOpticalPowerIndBmApc;
    //float						fBoosterOutputOpticalPowerIndBmAcc;
}c401Status1Definition_t;

typedef struct
{
    float						fValueOfPowerSupplyVoltage;
    float						fValueOfLaserPump1TemperatureBooster;
    float						fValueOfLaserPump2TemperatureBooster;
    float						fValueOfLaserPump3TemperatureBooster;
    float						fValueOfLaserPumpTemperatureLna;
    float						fValueBackFacetCurrentLaserPump1Booster;
    float						fValueBackFacetCurrentLaserPumpLna;
    xAlarmAndStatusRegister_t	xAlarmAndStatusRegister;
}c402Status2Definition_t;

/*typedef struct
{
    uint8_t

}c403StatusDefinition_t;*/

typedef struct
{
    float					fSetCurrentOnLaserPump1OnBooster;		/* within the applicable operational laser current range, Bit 8-15: */
    float					fSetCurrentOnLaserPump2OnBooster ;				/* within the applicable operational laser current range.Bit 16-23:*/
    float					fSetCurrentOnLaserPump3OnBooster;				/* within the applicable operational laser current range.Bit 24-31:*/
    float					fSetCurrentOnLaserPumpOnLNA;			/* with a default in ACC mode of 0mA.  Bit 36-43:*/
    float					fSetOpticalPowerForBooster;    /* Selects the optical power output range for APC mode on Booster section. Bit 44-53: */

    Status_406_Register_t	Status_406_Register;
}c406PacketControl1Definition_t;



class CanDictionary
{
private:


    CAN_FRAME cRPDO_401;
    CAN_FRAME cRPDO_402;
    CAN_FRAME cRPDO_403;
    CAN_FRAME cRPDO_404;
    CAN_FRAME cRPDO_405;

    CAN_FRAME cRPDO_406;
    CAN_FRAME cRPDO_407;
    CAN_FRAME cRPDO_408;
    CAN_FRAME cRPDO_409;
    CAN_FRAME cRPDO_40a;
    dictionaryUtils MydictionaryUtils;// = new(dictionaryUtils);


public:
    CanDictionary();

    void vInitCanImage( void );

    eMpbError_t getCan401( CAN_FRAME *pCan);

    eMpbError_t setCan401( CAN_FRAME *pCan);

    /**
    * @brief		encode the 401 CAN message to be sent
    * @param[in]	c401Status1Definition_t: pointer to the 401 mesage
    * @return       Success or library error message
    */
    //eMpbError_t eMpbCan401Encode( c401Status1Definition_t *c401Status1Definition );
    eMpbError_t eMpbCan401Decode( c401Status1Definition_t *c401Status1Definition, eBool_t bInputBoosterChannelSelection, eBool_t bOutputLnaChannelSelection );

    /**
    * @brief		decode and set the image for the 401 CAN message
    * @param[in]	c401Status1Definition_t: pointer to the 401 mesage
    * @return       Success or library error message
    */
   // eMpbError_t eMpbCan401Encode( c401Status1Definition_t *c401Status1Definition, eBool_t bInputBoosterChannelSelection, eBool_t bOutputLnaChannelSelection );


};

#endif // CANDICTIONARY_H
