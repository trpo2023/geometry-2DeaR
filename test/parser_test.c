#include <../thirdparty/ctest.h>
#include <libgeometry/parser.c>
#include <libgeometry/parser.h>

CTEST(ctest, check_perimetr)
{
    double pi = 3.14;
    float rad = 2.3;
    const double expected = 2 * pi * rad;
    const double result = pcircle(rad);
    ASSERT_DBL_NEAR_TOL(expected, result, 1e-1);
}

CTEST(ctest, check_square)
{
    double pi = 3.14;
    float rad = 2.3;
    const double expected = pi * rad * rad;
    const double result = acircle(rad);
    ASSERT_DBL_NEAR_TOL(expected, result, 1e-1);
}
