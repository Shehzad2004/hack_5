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

}/**
 * This function tests toSepia's error handling of out-of-range
 * values for the r, g, b parameters, each tested independently.
 * two values are tested each: a less-than-zero value and a value
 * greater than 255.
 */
static void testToSepiaOutOfBounds(void **state) {
  int r = 0, g = 0, b = 0, big = 256, neg = -1;
  assert_int_not_equal(toSepia(&neg,&g,&b), 0);
  assert_int_not_equal(toSepia(&big,&g,&b), 0);
  assert_int_not_equal(toSepia(&r,&neg,&b), 0);
  assert_int_not_equal(toSepia(&r,&big,&b), 0);
  assert_int_not_equal(toSepia(&r,&g,&neg), 0);
  assert_int_not_equal(toSepia(&r,&g,&big), 0);
  assert_int_equal(toSepia(&r,&g,&g), 0);
}

/**
 * This function tests toSepia passing a single, hard-coded
 * rgb-value (Steele Blue, 70, 130, 180).
 */
static void testToSepia001(void **state) {
  //steel blue:
  int r = 70, g = 130, b = 180;
  toSepia(&r,&g,&b);
  assert_true(r == 162 && g == 144 && b == 112);
}

/**
 * This function is a generic testing function for toSepia
 * in which the passed state is expected to have 6 integer values
 * corresponding to 3 RGB input values and 3 result values
 * that are known to be equivalent.