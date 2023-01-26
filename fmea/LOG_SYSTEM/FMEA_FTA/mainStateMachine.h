/**
* @file		    mainStateMachine.h
* @brief        mainStateMachine header file.
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
#ifndef __MAINSTATEMACHINE_H
#define __MAINSTATEMACHINE_H
/* Includes ----------------------------------------------------------------- */
#include "mpbLibs.h"
//#include "ControlAlarm.h"
//#include "CurrentSensor.h"
//#include "temperature.h"
//#include "PowerSensor.h"
//#include "BSPGpio.h"
#include "LaserDiodeBeam.h"

/* Define ------------------------------------------------------------------- */
/* Exported macro ----------------------------------------------------------- */
/* Exported enum ------------------------------------------------------------ */
enum eMainLoopStates
{
    eMainLoopStateInit = 0,
    eMainLoopStateOff,
    eMainLoopStateReady,
    eMainLoopStateOn,
    eMainLoopStateTest,
    eMainLoopStateFault
};

typedef enum eMainLoopStates eMainLoopState_t ;



/* Exported struct ---------------------------------------------------------- */
/* Global variables --------------------------------------------------------- */
/* Exported function prototypes --------------------------------------------- */


//eMainLoopState_t getMainLoopState(void);

#endif /* __MAINSTATEMACHINE_H */
