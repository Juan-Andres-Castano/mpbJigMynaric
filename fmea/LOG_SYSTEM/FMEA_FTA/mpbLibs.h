#ifndef MPBLIBS_H
#define MPBLIBS_H

#include <QDataStream>

typedef enum
{
    eSuccess				    =  0,
    eInvalidParameter           = -1,
    eAccessDenied			    = -2,
    eBusy	 		    		= -3,
    eTimeout	 		    	= -4,
  eBufferEmpty                = -5,
    eBufferFull		          	= -6,
    eBufferOverflow		    	= -7,
    eOutOfMemory			    = -8,
    eCheckFailed	 			= -9,
    eCorrupted	 		    	= -10,
    eOutOfRange	 		    	= -11,
    eNotFound	 		    	= -12,
    eInvalidObject			    = -13,
    eNotDiscarded		    	= -14,
    eNotRegistered			    = -15,
    ePropertyNotSuported	    = -16,
    eObjectTypeNotSuported	    = -17,
    eDriverError 				= -18,
    eUnknownError	    	    = -19,
  eInternalDeviceError        = -20
}
eMpbError_t;


typedef enum
{
    eCommandAccepted = 0,
    eMessageLengthTooShort = 1,
    eMessageLengthTooLongMMC = 2,
    eCrcError						=3,
    eUnknowcommand = 4,
    eIncorrectNumberOfArgumentsMany = 5,
    eIncorrectNumberOfArgumentsFew = 6,
    eArgumentValueOutofRangeLow = 7,
    eArgumentValueOutofRangeHigh = 8,
    ecommandRejected = 9
}eErrorCodes_t;

/**
* @brief	Mpbtronic define access
*/
typedef enum
{
    eREAD_ACCESS = 0,
    eWRITE_ACCESS = 1,
}
eAccess_t;

/**
* @brief boolean definition
*/
typedef enum
{
    eFalse 		= 0,
    eTrue		= !eFalse,
}
eBool_t;

typedef union
{
    quint16 sValue;
    quint8 ucValue[2];
}mpbShortData_t;

typedef union
{
    float fValue;
    quint8 ucValue[4];
}mpbFloatData_t;

typedef union
{
    quint32 ulValue;
    quint8  ucValue[4];
}mpbLongData_t;

typedef union
{
   uint64_t ullValue;
    uint8_t  ucValue[8];
}mpbLLongData_t;
/**
* @brief	user define handle
*/
typedef quint32	handle_t;

#endif // MPBLIBS_H

