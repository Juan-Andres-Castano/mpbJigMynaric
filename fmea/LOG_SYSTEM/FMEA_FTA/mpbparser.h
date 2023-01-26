#ifndef MPBPARSER_H
#define MPBPARSER_H
#include "mpbLibs.h"

#define usMpbParserCONCAT_BYTES( msb, lsb )                   ( ( ( quint16 )msb << 8 ) | ( quint16 )lsb )

typedef enum _MPB_PARSER_STATE_T {
    PARSER_LOOKING_FOR_START = 0,
    PARSER_LOOKING_FOR_LEN,
//    PARSER_LOOKING_FOR_CMD,
    PARSER_LOOKING_FOR_DAT,
    PARSER_LOOKING_FOR_CRC_1,
    PARSER_LOOKING_FOR_CRC_2,
} MPB_PARSER_STATE_T;

#define PARSER_BUFFER_LENGTH_MAX    ( 200 )
#define M2M_MIN_SIZE_OF_DATA        ( 1 )
#define M2M_SIZE_OF_LENGTH_DATA     ( 1 )
#define M2M_HEADER_CHAR             ( 0x7E )
#define M2M_MIN_COMMAND_VALUE       ( 0x10 )
#define M2M_MAX_COMMAND_VALUE       ( 0xFA )

class mpbParser
{
public:
    mpbParser();

    quint8* mpbParser_AddChar(uint8_t NewByte);

private:
    MPB_PARSER_STATE_T state ;
    quint8  buffer[PARSER_BUFFER_LENGTH_MAX];
    quint8  ucCrc1;
    quint8  ucCrc2;
    quint8  usDataBytesNeeded;
    quint8  usLengthForCrcCalcultation;
    quint8  length ;

};



#endif // MPBPARSER_H
