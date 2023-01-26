#ifndef DICTIONARYUTILS_H
#define DICTIONARYUTILS_H

#include "mpbLibs.h"

/**
* @brief	internal structures
*/

typedef enum
{
    coerced		,
    not_coerced
}
mpb_coerced_t;


class dictionaryUtils
{
public:
    dictionaryUtils();


    float mpb_math_fdiv( float numerator, float denominator );


    float mpb_math_flinear_approx( float x1, float y1, float x2, float y2, float x, mpb_coerced_t coerce );


    eBool_t mpb_float1_minor_than_float2(float float1, float float2, unsigned int precision);

};

#endif // DICTIONARYUTILS_H
