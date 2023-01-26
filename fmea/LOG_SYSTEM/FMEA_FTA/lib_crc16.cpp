#include "lib_crc16.h"

lib_crc16::lib_crc16()
{

}

quint16 lib_crc16::crc_ccitt_ffff(const quint8 *input_str, quint8 num_bytes)
{
    return crc_ccitt_generic( input_str, num_bytes, CRC_START_CCITT_FFFF );
}

quint16 lib_crc16::crc_ccitt_generic(const quint8 *input_str, size_t num_bytes, quint16 start_value)
{
    quint16 crc;
    quint16 tmp;
    quint16 short_c;
    const unsigned char *ptr;
    size_t a;

    if ( ! crc_tabccitt_init ) init_crcccitt_tab();

    crc = start_value;
    ptr = input_str;

    if ( ptr != NULL ) for (a=0; a<num_bytes; a++) {

        short_c = 0x00ff & (unsigned short) *ptr;
        tmp     = (crc >> 8) ^ short_c;
        crc     = (crc << 8) ^ crc_tabccitt[tmp];

        ptr++;
    }

    return crc;
}

void lib_crc16::init_crcccitt_tab()
{
    quint16 i;
    quint16 j;
    quint16 crc;
    quint16 c;

    for (i=0; i<256; i++) {

        crc = 0;
        c   = i << 8;

        for (j=0; j<8; j++) {

            if ( (crc ^ c) & 0x8000 ) crc = ( crc << 1 ) ^ CRC_POLY_CCITT;
            else                      crc =   crc << 1;

            c = c << 1;
        }

        crc_tabccitt[i] = crc;
    }

    crc_tabccitt_init = true;
}
