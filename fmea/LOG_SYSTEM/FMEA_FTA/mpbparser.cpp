#include "mpbparser.h"
#include "lib_crc16.h"
#include <cstring>
#include <iostream>

mpbParser::mpbParser()
{
 state = PARSER_LOOKING_FOR_START ;
 length = 0;
 ucCrc1 = 0;
 ucCrc2 = 0;
 usDataBytesNeeded = 0;
 usLengthForCrcCalcultation =0;
 length =0;

}

quint8 *mpbParser::mpbParser_AddChar(uint8_t NewByte)
{

    //eMpbError_t     eMpbError;
        quint16        usCrcValueCalculated  ;
        quint16        usCrcValueReceived    ;
        lib_crc16     lib_crc16;


        switch(state)
        {
            case PARSER_LOOKING_FOR_START:
                length = 0;
                if (NewByte == M2M_HEADER_CHAR )
                {
                    memset( buffer, 0, PARSER_BUFFER_LENGTH_MAX);
                    buffer[length] = NewByte;
                    state = PARSER_LOOKING_FOR_LEN;
                }
               break;

            case PARSER_LOOKING_FOR_LEN:
                if ((NewByte > 0) && (NewByte <= PARSER_BUFFER_LENGTH_MAX) && (NewByte >= M2M_MIN_SIZE_OF_DATA ) )
                {
                    buffer[++length] = NewByte;
                    usDataBytesNeeded = NewByte    ;// - M2M_MIN_SIZE_OF_DATA + 1;
                    usLengthForCrcCalcultation = NewByte + 1  ;//+ M2M_SIZE_OF_LENGTH_DATA ;
                    state = PARSER_LOOKING_FOR_DAT;
                }
                else
                {
                    state = PARSER_LOOKING_FOR_START;
                }
                break;

          /*  case PARSER_LOOKING_FOR_CMD:
                if ((NewByte >= M2M_MIN_COMMAND_VALUE ) && (NewByte <= M2M_MAX_COMMAND_VALUE ))
                {
                    buffer[ ++length ] = NewByte;
                    if(usDataBytesNeeded >= 1 )
                    {
                        state =  PARSER_LOOKING_FOR_DAT;
                    }
                    else
                    {
                        state =  PARSER_LOOKING_FOR_CRC_1;
                    }
                }
                else
                {
                    state = PARSER_LOOKING_FOR_START;
                }
                break;
*/
            case PARSER_LOOKING_FOR_DAT:
                    buffer[++length] = NewByte;
                    usDataBytesNeeded--;
                    if ( usDataBytesNeeded == 0)
                    {
                        state = PARSER_LOOKING_FOR_CRC_1;
                    }
                break;

            case PARSER_LOOKING_FOR_CRC_1:
                    buffer[ ++length ] = NewByte;
                    ucCrc1 = NewByte;
                    state = PARSER_LOOKING_FOR_CRC_2;
                break;

            case PARSER_LOOKING_FOR_CRC_2:
                    buffer[++length] = NewByte;
                    ucCrc2 = NewByte;
                    state = PARSER_LOOKING_FOR_START;

                    usCrcValueReceived =  usMpbParserCONCAT_BYTES(ucCrc2, ucCrc1);



                    usCrcValueCalculated = lib_crc16.crc_ccitt_ffff( &buffer[1], (usLengthForCrcCalcultation)  );

                 //   {
                        if(  usCrcValueReceived == usCrcValueCalculated )
                        {
                            return (uint8_t *)buffer;
                        }
                        else
                        {
                            return NULL;
                        }
               //     }

                break;

            default:
                state = PARSER_LOOKING_FOR_START;
        }

        return NULL;
   // return 0;
}
