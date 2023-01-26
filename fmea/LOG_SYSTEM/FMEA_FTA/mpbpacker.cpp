#include "mpbpacker.h"
#include "lib_crc16.h"
#include <cstring>
#include <iostream>

mpbPacker::mpbPacker()
{

}

quint8 *mpbPacker::mpbPacker_AddMsg(eErrorCodes_t eErrorCode, quint8 ucCommand, quint8 ucLength, quint8 *pData)
{
    quint8         i                       = 0;
    quint16        usCrcValueCalculated    = 0;
    quint8         ucCrc8Low               = 0;
    quint8         ucCrc8High              = 0;
    quint8			ucCopyLength		   = 0;
    lib_crc16     lib_crc16;


    if ( ucLength > MAX_TX_LENGTH_BUFFER)
    {
        return NULL;
    }


    memset( &ucBuffer[0],0, (MAX_TX_LENGTH_BUFFER + SIZE_OF_FS_BYTE) );


    ucCopyLength = ucLength ;
    ucBuffer[i++] = M2M_HEADER_CHAR;
    ucBuffer[i++] = ucLength; // +  + SIZE_OF_FS_BYTE ; //SIZE_OF_CRC_BYTES
    // ucBuffer[i++] = eErrorCode;
    ucBuffer[i++] = ucCommand;
    ucBuffer[i++] = *(pData+1);
    //while( --ucCopyLength )
    //{
      //  ucBuffer[i++] = *pData++;
    //}

    usCrcValueCalculated = lib_crc16.crc_ccitt_ffff( &ucBuffer[1], (ucLength +1)  );

    ucCrc8Low   = usCrcValueCalculated;
    ucCrc8High  = usCrcValueCalculated >> 8 ;
    ucBuffer[i++] = ucCrc8Low;
    ucBuffer[i++] = ucCrc8High;



    return ucBuffer;
}
