/**
 * This is a collection of unit tests for the
 * color utils library using the cmocka unit
 * test framework.
 *
 */
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <math.h>
#include <cmocka.h>

#include "colorUtils.h"

/**
 * This function is a generic testing function for min()
 * in which the passed state is expected to have 4 integer values
 * corresponding to the 3 input values and the expected output
 * value.
 */
static void testMinValues(void **state) {
  //cast the generic state to an int array
  int *values = *((int **)state);
  assert_true( min(values[0], values[1], values[2]) == values[3]);
}

/**
 * This function is a generic testing function for max()
 * in which the passed state is expected to have 4 integer values
 * corresponding to the 3 input values and the expected output
 * value.
 */
static void testMaxValues(void **state) {
  //cast the generic state to an int array
  int *values = *((int **)state);
  assert_true( max(values[0], values[1], values[2]) == values[3]);
}

/**
 * This function tests toSepia's error handling of NULL
 * values for its pass-by-reference parameters.  Each of
 * the three parameters are tested independently.  The function
 * should return a non-zero error value so we assert that the
 * return value is not equal to zero.
 *
 */
static void testToSepiaNull(void **state) {
  int r = 0, g = 0, b = 0;
  assert_int_not_equal(toSepia(NULL,&g,&b), 0);
  assert_int_not_equal(toSepia(&r,NULL,&b), 0);
  assert_int_not_equal(toSepia(&r,&g,NULL), 0);

}