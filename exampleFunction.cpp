#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h> 

/*Added check if addition makes overflow in UINT type*/

unsigned int wrapFunctionAdd(unsigned int ui_a, unsigned int ui_b) {
  unsigned int usum;
  if(( UINT_MAX - ui_a )< ui_b ){
    printf("System Error: The numbers makes overflow warps\n");
    return 0;
  }
  else
    usum = ui_a + ui_b;
  return usum;
}
//-pthread

/*Added check if multiplication makes overflow in UINT type*/

unsigned int wrapFunctionMul(unsigned int ui_a, unsigned int ui_b) {
  unsigned umul = ui_a;
  if( ui_a == 0)
    umul = 0;
  else if( ui_b > ( UINT_MAX / ui_a ) ){
    printf("System Error: The numbers makes overflow warps\n");
    return 1;
  }
  else
    umul *= ui_b;
  return umul;
}

uint32_t wrapFunctionShift(uint32_t ui_a, unsigned int ui_b) {
  uint32_t uShift = 0;
  if( ui_b >= 32 )
    return 0;
  else 
    uShift = ui_a << ui_b | ui_a >> ( 32 - ui_b );
  return uShift;
}
