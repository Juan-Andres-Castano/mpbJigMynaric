#include "candictionary.h"

CanDictionary::CanDictionary()
{

}

void CanDictionary::vInitCanImage()
{
    cRPDO_401.data.value = 0;
}

eMpbError_t CanDictionary::getCan401(CAN_FRAME *pCan)
{
    eMpbError_t eMpbError = eSuccess;
    uint8_t size;
    size = sizeof(CAN_FRAME);

    memcpy(pCan, &cRPDO_401, size );
    return eMpbError;
}

eMpbError_t CanDictionary::setCan401(CAN_FRAME *pCan)
{
    eMpbError_t eMpbError = eSuccess;
    uint8_t size;
    size = sizeof(CAN_FRAME);

    memcpy(&cRPDO_401, pCan, size );
    return eMpbError;
}

eMpbError_t CanDictionary::eMpbCan401Decode(c401Status1Definition_t *c401Status1Definition, eBool_t bInputBoosterChannelSelection, eBool_t bOutputLnaChannelSelection)
{
    BytesUnion cxInternalMountingSurfaceTemperature;
        BytesUnion cxLaserPump1CurrentOfBooster;
        BytesUnion cxLaserPump2CurrentOfBooster;
        BytesUnion cxLaserPump3CurrentOfBooster;
        BytesUnion cxLaserPump4CurrentOfLna;
        BytesUnion cxBoosterOpticalInputPower;
        BytesUnion cxLnaOpticalOutputPower;
        BytesUnion cxBoosterOutputOpticalPower;
        eMpbError_t eMpbError = eSuccess;
        uint8_t cTempValue =0;

        mpb_coerced_t coerce = coerced;
        floatUnion	fxBoosterOutputOpticalPower;
        floatUnion fxValue;
        float fRecoveredFrom255 = 0.0f;



        if(c401Status1Definition != NULL)
        {
            /* Bit 0-7: value internal unit mounting surface temperature, detection range from -40°C to +90°C.	The resolution is determined by the bit range 0..255. */
            cxInternalMountingSurfaceTemperature.value							= ( cRPDO_401.data.value >> DEF_CAN_0401_INTERNAL_MOUNTING_TEMPERATURE) & 0x00000000000000FF; /* bits 0-7 */
            c401Status1Definition->fInternalMountingSurfaceTemperature			= (float)(cxInternalMountingSurfaceTemperature.byte[0]);

            fxValue.fValue											= MydictionaryUtils.mpb_math_flinear_approx(  (float)(Y1_INTERNAL_TEMP_SURFACE_TEMP_LINEAR_APROX_ENCODE),
                                                                                                (float)(X1_INTERNAL_TEMP_SURFACE_TEMP_LINEAR_APROX_ENCODE),
                                                                                                (float)(Y2_INTERNAL_TEMP_SURFACE_TEMP_LINEAR_APROX_ENCODE),
                                                                                                (float)(X2_INTERNAL_TEMP_SURFACE_TEMP_LINEAR_APROX_ENCODE),
                                                                                                c401Status1Definition->fInternalMountingSurfaceTemperature ,  coerce );

            c401Status1Definition->fInternalMountingSurfaceTemperature = fxValue.fValue;

            /*Bit 8-15: value laser pump1 current of the Booster section.	The resolution is determined by the bit range 0..255. */
            cxLaserPump1CurrentOfBooster.value						= ( cRPDO_401.data.value >> DEF_CAN_0401_PUMP1_CURRENT_IN_BOOSTER) & 0x00000000000000FF;// & 0x000000000000FF00; /* bits 8-15 */
            c401Status1Definition->fLaserPump1CurrentOfBooster		= (float)(cxLaserPump1CurrentOfBooster.byte[0]);

            fxValue.fValue											= MydictionaryUtils.mpb_math_flinear_approx(  (float)(Y1_LASER_PUM1_CURRENT_BOOSTER_LINEAR_APROX_ENCODE),
                                                                                                (float)(X1_LASER_PUM1_CURRENT_BOOSTER_LINEAR_APROX_ENCODE),
                                                                                                (float)(Y2_LASER_PUM1_CURRENT_BOOSTER_LINEAR_APROX_ENCODE),
                                                                                                (float)(X2_LASER_PUM1_CURRENT_BOOSTER_LINEAR_APROX_ENCODE),
                                                                                                c401Status1Definition->fLaserPump1CurrentOfBooster,  coerce );

            c401Status1Definition->fLaserPump1CurrentOfBooster = fxValue.fValue;

            /*Bit 16-23: value laser pump2 current (if such hardware is present).	The resolution is determined by the bit range 0..255.*/
            cxLaserPump2CurrentOfBooster.value						= ( cRPDO_401.data.value >> DEF_CAN_0401_PUMP2_CURRENT_IN_BOOSTER) & 0x00000000000000FF;// & 0x0000000000FF0000; /* bits 16-23 */
            c401Status1Definition->fLaserPump2CurrentOfBooster		= (float)(cxLaserPump2CurrentOfBooster.byte[0]);

            fxValue.fValue											= MydictionaryUtils.mpb_math_flinear_approx(  (float)(Y1_LASER_PUM2_CURRENT_BOOSTER_LINEAR_APROX_ENCODE),
                                                                                                (float)(X1_LASER_PUM2_CURRENT_BOOSTER_LINEAR_APROX_ENCODE),
                                                                                                (float)(Y2_LASER_PUM2_CURRENT_BOOSTER_LINEAR_APROX_ENCODE),
                                                                                                (float)(X2_LASER_PUM2_CURRENT_BOOSTER_LINEAR_APROX_ENCODE),
                                                                                                c401Status1Definition->fLaserPump2CurrentOfBooster,  coerce );

            c401Status1Definition->fLaserPump2CurrentOfBooster		= fxValue.fValue;

            /*	Bit 24-31: value laser pump3 current (if such hardware is present).The resolution is determined by the bit range 0..255.*/
            cxLaserPump3CurrentOfBooster.value						= ( cRPDO_401.data.value >> DEF_CAN_0401_PUMP3_CURRENT_IN_BOOSTER) & 0x00000000000000FF;// & 0x00000000FF000000; /* bits 24-31 */
            c401Status1Definition->fLaserPump3CurrentOfBooster		= (float)(cxLaserPump3CurrentOfBooster.byte[0]);

            fxValue.fValue											= MydictionaryUtils.mpb_math_flinear_approx(  (float)(Y1_LASER_PUM3_CURRENT_BOOSTER_LINEAR_APROX_ENCODE),
                                                                                                (float)(X1_LASER_PUM3_CURRENT_BOOSTER_LINEAR_APROX_ENCODE),
                                                                                                (float)(Y2_LASER_PUM3_CURRENT_BOOSTER_LINEAR_APROX_ENCODE),
                                                                                                (float)(X2_LASER_PUM3_CURRENT_BOOSTER_LINEAR_APROX_ENCODE),
                                                                                                c401Status1Definition->fLaserPump3CurrentOfBooster,  coerce );
            c401Status1Definition->fLaserPump3CurrentOfBooster		= fxValue.fValue;

            /*	Bit 32-39: value laser pump4 current of the LNA section.	The resolution is determined by the bit range 0..255.*/
            cxLaserPump4CurrentOfLna.value							= ( cRPDO_401.data.value >> DEF_CAN_0401_PUMP4_CURRENT_IN_LNA ) & 0x00000000000000FF;// & 0x000000FF00000000; /* bits 32-39 */
            c401Status1Definition->fLaserPump4CurrentOfLna			= (float)( cxLaserPump4CurrentOfLna.byte[0] );

            fxValue.fValue											= MydictionaryUtils.mpb_math_flinear_approx(  (float)(Y1_LASER_PUM4_CURRENT_LNA_LINEAR_APROX_ENCODE),
                                                                                                (float)(X1_LASER_PUM4_CURRENT_LNA_LINEAR_APROX_ENCODE),
                                                                                                (float)(Y2_LASER_PUM4_CURRENT_LNA_LINEAR_APROX_ENCODE),
                                                                                                (float)(X2_LASER_PUM4_CURRENT_LNA_LINEAR_APROX_ENCODE),
                                                                                                c401Status1Definition->fLaserPump4CurrentOfLna ,  coerce );

            c401Status1Definition->fLaserPump4CurrentOfLna			= fxValue.fValue;

            /*Bit 40-47:  for the selected input channel, the value of the booster optical input power. The resolution is determined by the specified input dBm range and the bit range 0...255.*/
            cxBoosterOpticalInputPower.value						= ( cRPDO_401.data.value >> DEF_CAN_0401_BOOSTER_OPTICAL_INPUT_POWER ) & 0x00000000000000FF;// & 0x0000FF0000000000; /* bits 40-47 */
            c401Status1Definition->fBoosterOpticalInputPower		= (float)(cxBoosterOpticalInputPower.byte[0]);

            if(bInputBoosterChannelSelection == eFalse )
            {
                fxValue.fValue										= MydictionaryUtils.mpb_math_flinear_approx(  (float)(Y1_CHANEL_30_1553_NM_INPUT_OPT_POW_BOOSTER_ENCODE),
                                                                                                (float)(X1_CHANEL_30_1553_NM_INPUT_OPT_POW_BOOSTER_ENCODE),
                                                                                                (float)(Y2_CHANEL_30_1553_NM_INPUT_OPT_POW_BOOSTER_ENCODE),
                                                                                                (float)(X2_CHANEL_30_1553_NM_INPUT_OPT_POW_BOOSTER_ENCODE),
                                                                                                c401Status1Definition->fBoosterOpticalInputPower,  coerce );
            }
            else
            {
                fxValue.fValue										= MydictionaryUtils.mpb_math_flinear_approx(  (float)(Y1_CHANEL_1_CH51_1536_NM_IN_OPT_POW_BOOSTER_ENCODE),
                                                                                                (float)(X1_CHANEL_1_CH51_1536_NM_IN_OPT_POW_BOOSTER_ENCODE),
                                                                                                (float)(Y2_CHANEL_1_CH51_1536_NM_IN_OPT_POW_BOOSTER_ENCODE),
                                                                                                (float)(X2_CHANEL_1_CH51_1536_NM_IN_OPT_POW_BOOSTER_ENCODE),
                                                                                                c401Status1Definition->fBoosterOpticalInputPower,  coerce );
            }

           c401Status1Definition->fBoosterOpticalInputPower 		= fxValue.fValue;

            /*Bit 48-55:  for the selected output channel, the value of the LNA optical output power. The resolution is determined by the specified output dBm range and the bit range 0...255.*/
            cxLnaOpticalOutputPower.value										= ( cRPDO_401.data.value >> DEF_CAN_0401_LNA_OPTICAL_OUTPUT_POWER ) & 0x00000000000000FF;// & 0x00FF000000000000; /* bits 48-55 */
            c401Status1Definition->fLnaOpticalOutputPower						= (float)( cxLnaOpticalOutputPower.byte[0] );

            if(bOutputLnaChannelSelection == eFalse )
            {
                fxValue.fValue													= MydictionaryUtils.mpb_math_flinear_approx(  (float)(Y1_CHANEL_30_1553_NM_OUTPUT_POW_LNA_ENCODE),
                                                                                                            (float)(X1_CHANEL_30_1553_NM_OUTPUT_POW_LNA_ENCODE),
                                                                                                            (float)(Y2_CHANEL_30_1553_NM_OUTPUT_POW_LNA_ENCODE),
                                                                                                            (float)(X2_CHANEL_30_1553_NM_OUTPUT_POW_LNA_ENCODE),
                                                                                                            c401Status1Definition->fLnaOpticalOutputPower,  coerce );
            }
            else
            {
                fxValue.fValue													= MydictionaryUtils.mpb_math_flinear_approx(  (float)(Y1_CHANEL_51_1536_NM_OUTPUT_POW_LNA_ENCODE),
                                                                                                            (float)(X1_CHANEL_51_1536_NM_OUTPUT_POW_LNA_ENCODE),
                                                                                                            (float)(Y2_CHANEL_51_1536_NM_OUTPUT_POW_LNA_ENCODE),
                                                                                                            (float)(X2_CHANEL_51_1536_NM_OUTPUT_POW_LNA_ENCODE),
                                                                                                            c401Status1Definition->fLnaOpticalOutputPower,  coerce );
            }

            c401Status1Definition->fLnaOpticalOutputPower						= fxValue.fValue ;

           /* Bit 56-63: value of the Booster output optical power in APC mode:
            Value 0..17 allocated to the range -30 dBm to +19 dBm
            Value 18..193 allocated to the range 20 dBm to >36 dBm (for example 37.5 dBm)
            Value 194..255 allocated to the maximum output dBm value, for example 37.5 dBm.*/

            cxBoosterOutputOpticalPower.value									= ( cRPDO_401.data.value >> DEF_CAN_0401_BOOSTER_OPTICAL_OUTPUT_POWER ) & 0x00000000000000FF;// & 0xFF00000000000000; /* bits 56-63 */
            cTempValue															= cxBoosterOutputOpticalPower.byte[0];
            fxBoosterOutputOpticalPower.fValue									= (float)(cxBoosterOutputOpticalPower.byte[0]);


            if ( cTempValue <= FIRST_DECIMAL_LIMIT_FOR_BOOSTER_OUTPUT_OPTICAL_POWER )
            {
                fRecoveredFrom255												= MydictionaryUtils.mpb_math_flinear_approx(  (float)(Y1_RANGE_1_BOOSTER_OUTPUT_OPTICAL_POWER),
                                                                                                            (float)(X1_RANGE_1_BOOSTER_OUTPUT_OPTICAL_POWER),
                                                                                                            (float)(Y2_RANGE_1_BOOSTER_OUTPUT_OPTICAL_POWER),
                                                                                                            (float)(X2_RANGE_1_BOOSTER_OUTPUT_OPTICAL_POWER),
                                                                                                            fxBoosterOutputOpticalPower.fValue,  coerce );
            }
            else if( (cTempValue > FIRST_DECIMAL_LIMIT_FOR_BOOSTER_OUTPUT_OPTICAL_POWER ) &&  (cTempValue <= SECOND_DECIMAL_LIMIT_FOR_BOOSTER_OUTPUT_OPTICAL_POWER ) )
            {
                fRecoveredFrom255												= MydictionaryUtils.mpb_math_flinear_approx(  (float)(Y1_RANGE_2_BOOSTER_OUTPUT_OPTICAL_POWER),
                                                                                                            (float)(X1_RANGE_2_BOOSTER_OUTPUT_OPTICAL_POWER),
                                                                                                            (float)(Y2_RANGE_2_BOOSTER_OUTPUT_OPTICAL_POWER),
                                                                                                            (float)(X2_RANGE_2_BOOSTER_OUTPUT_OPTICAL_POWER),
                                                                                                            fxBoosterOutputOpticalPower.fValue,  coerce );
            }
            else
            {
                fRecoveredFrom255												= MydictionaryUtils.mpb_math_flinear_approx(  (float)(Y1_RANGE_3_BOOSTER_OUTPUT_OPTICAL_POWER),
                                                                                                            (float)(X1_RANGE_3_BOOSTER_OUTPUT_OPTICAL_POWER),
                                                                                                            (float)(Y2_RANGE_3_BOOSTER_OUTPUT_OPTICAL_POWER),
                                                                                                            (float)(X2_RANGE_3_BOOSTER_OUTPUT_OPTICAL_POWER),
                                                                                                            fxBoosterOutputOpticalPower.fValue,  coerce );
            }

            c401Status1Definition->fBoosterOutputOpticalPowerIndBmApc = fRecoveredFrom255;
        }
        else
        {
            eMpbError = eOutOfMemory;
        }
        return eMpbError;
}
