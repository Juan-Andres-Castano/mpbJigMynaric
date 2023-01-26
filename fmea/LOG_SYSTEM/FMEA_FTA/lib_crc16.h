#ifndef LIB_CRC16_H
#define LIB_CRC16_H

//#include "mpbLibs.h"
#include <QDataStream>

#define		CRC_START_16					0x0000
#define		CRC_START_CCITT_1D0F	0x1D0F
#define		CRC_START_CCITT_FFFF	0xFFFF
#define		CRC_POLY_CCITT		0x1021


class lib_crc16
{
public:
    lib_crc16();
   // ~lib_crc16();




private:
    quint16 crc_ccitt_generic( const quint8 *input_str, size_t num_bytes, quint16 start_value );
    void    init_crcccitt_tab( void );

    bool             crc_tabccitt_init       = false;
    quint16         crc_tabccitt[256];


public:
    quint16 crc_ccitt_ffff( const quint8 *input_str, quint8 num_bytes );


};

#endif // LIB_CRC16_H
