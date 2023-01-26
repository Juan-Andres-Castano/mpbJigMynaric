#ifndef MPBPACKER_H
#define MPBPACKER_H


#include "mpbLibs.h"

#define MPB_PACKER_MAX_LEN  		( 75 )
#define MAX_TX_LENGTH_BUFFER 		( 240 )
#define SIZE_OF_FS_BYTE      		( 1 )
#define SIZE_OF_LENGTH_BYTE  		( 1 )
#define SIZE_OF_CRC_BYTES	  		( 2 )
#define M2M_MIN_COMMAND_VALUE       ( 0x10 )
#define M2M_MAX_COMMAND_VALUE       ( 0xFA )
#define M2M_HEADER_CHAR             ( 0x7E )


class mpbPacker
{
public:
    mpbPacker();


    quint8* mpbPacker_AddMsg(eErrorCodes_t eErrorCode, quint8 ucCommand, quint8 ucLength, quint8* pData  );


private:
    quint8 ucBuffer[ MAX_TX_LENGTH_BUFFER + SIZE_OF_FS_BYTE ];

};

#endif // MPBPACKER_H
