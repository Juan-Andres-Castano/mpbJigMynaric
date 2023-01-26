#include "dictionaryutils.h"

dictionaryUtils::dictionaryUtils()
{

}

float dictionaryUtils::mpb_math_fdiv(float numerator, float denominator)
{
    if( numerator >= 0 )
    {
        numerator += (denominator/2);			// add half of divider for rounding
    }
    else
    {
        numerator -= (denominator/2);			// remove half of divider for rounding
    }
    return numerator / denominator;
}

float dictionaryUtils::mpb_math_flinear_approx(float x1, float y1, float x2, float y2, float x, mpb_coerced_t coerce)
{
    float y, x21;

        /* get slope denominator */
        x21 = x2 - x1;
        /* prevent division by 0 */
        if( x21 == 0 )
        {
            return x;
        }
        /* coerce input/output value */
        if( coerce == coerced )
        {
            /* if positive slope */
            if( x21 >= 0 )
            {
                if( x <= x1 )
                {
                    return y1;
                }
                else if( x >= x2 )
                {
                    return y2;
                }
            }
            /* else negative slope */
            else
            {
                if( x >= x1 )
                {
                    return y1;
                }
                else if( x <= x2 )
                {
                    return y2;
                }
            }
        }
        /* get input offset */
        y = (x - x1);
        /* multiply by slope numerator */
        y *= (y2 - y1);
        /* divide by slope denominator */
        y = mpb_math_fdiv( y, x21 );
        /* add output offset */
        y += y1;
        /* return value */
        return y;

}

eBool_t dictionaryUtils::mpb_float1_minor_than_float2(float float1, float float2, unsigned int precision)
{
    int int1, int2;
        eBool_t bReturn = eFalse;

        if (float1 > 0)
        int1 = (int)(float1 * precision + .5);
        else
        int1 = (int)(float1 * precision - .5);

        if (float2 > 0)
        int2 = (int)(float2 * precision + .5);
        else
        int2 = (int)(float2 * precision - .5);


        if(int1 < int2)
        {
            bReturn = eTrue;
        }
        return bReturn;

}
