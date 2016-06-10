#include "QLIT_lib.h"
#include <sys/time.h>

#define M_PI 3.14159265358979323846
#define M_E  2.71828182845904523536

int main(){
 #ifdef RUNTIME
  struct timeval t1, t2;
  double elapsedTime;
  gettimeofday(&t1, NULL);
 #endif
 Matrix* hadamard = hadamardG();
 Matrix* not = notG();
 Matrix* cnot = cnotG();
 Matrix* identity = identityG();
 Qubit* q = qubitInit(0,12);
 Qubit* c = q;
 Matrix** slot_c0 = (Matrix**)malloc(sizeof(Matrix*)*12);
slot_c0[0] = hadamard;
slot_c0[1] = identity;
slot_c0[2] = identity;
slot_c0[3] = identity;
slot_c0[4] = identity;
slot_c0[5] = identity;
slot_c0[6] = identity;
slot_c0[7] = identity;
slot_c0[8] = identity;
slot_c0[9] = identity;
slot_c0[10] = identity;
slot_c0[11] = identity;
 calcSlot(&c, slot_c0);
 Matrix** slot_c1 = (Matrix**)malloc(sizeof(Matrix*)*11);
slot_c1[0] = controlGen(0,1,not);
slot_c1[1] = identity;
slot_c1[2] = identity;
slot_c1[3] = identity;
slot_c1[4] = identity;
slot_c1[5] = identity;
slot_c1[6] = identity;
slot_c1[7] = identity;
slot_c1[8] = identity;
slot_c1[9] = identity;
slot_c1[10] = identity;
 calcSlot(&c, slot_c1);
 Matrix** slot_c2 = (Matrix**)malloc(sizeof(Matrix*)*10);
slot_c2[0] = controlGen(0,2,not);
slot_c2[1] = identity;
slot_c2[2] = identity;
slot_c2[3] = identity;
slot_c2[4] = identity;
slot_c2[5] = identity;
slot_c2[6] = identity;
slot_c2[7] = identity;
slot_c2[8] = identity;
slot_c2[9] = identity;
 calcSlot(&c, slot_c2);
 Matrix** slot_c3 = (Matrix**)malloc(sizeof(Matrix*)*9);
slot_c3[0] = controlGen(0,3,not);
slot_c3[1] = identity;
slot_c3[2] = identity;
slot_c3[3] = identity;
slot_c3[4] = identity;
slot_c3[5] = identity;
slot_c3[6] = identity;
slot_c3[7] = identity;
slot_c3[8] = identity;
 calcSlot(&c, slot_c3);
 Matrix** slot_c4 = (Matrix**)malloc(sizeof(Matrix*)*8);
slot_c4[0] = controlGen(0,4,not);
slot_c4[1] = identity;
slot_c4[2] = identity;
slot_c4[3] = identity;
slot_c4[4] = identity;
slot_c4[5] = identity;
slot_c4[6] = identity;
slot_c4[7] = identity;
 calcSlot(&c, slot_c4);
 Matrix** slot_c5 = (Matrix**)malloc(sizeof(Matrix*)*7);
slot_c5[0] = controlGen(0,5,not);
slot_c5[1] = identity;
slot_c5[2] = identity;
slot_c5[3] = identity;
slot_c5[4] = identity;
slot_c5[5] = identity;
slot_c5[6] = identity;
 calcSlot(&c, slot_c5);
 Matrix** slot_c6 = (Matrix**)malloc(sizeof(Matrix*)*6);
slot_c6[0] = controlGen(0,6,not);
slot_c6[1] = identity;
slot_c6[2] = identity;
slot_c6[3] = identity;
slot_c6[4] = identity;
slot_c6[5] = identity;
 calcSlot(&c, slot_c6);
 Matrix** slot_c7 = (Matrix**)malloc(sizeof(Matrix*)*5);
slot_c7[0] = controlGen(0,7,not);
slot_c7[1] = identity;
slot_c7[2] = identity;
slot_c7[3] = identity;
slot_c7[4] = identity;
 calcSlot(&c, slot_c7);
 Matrix** slot_c8 = (Matrix**)malloc(sizeof(Matrix*)*4);
slot_c8[0] = controlGen(0,8,not);
slot_c8[1] = identity;
slot_c8[2] = identity;
slot_c8[3] = identity;
 calcSlot(&c, slot_c8);
 Matrix** slot_c9 = (Matrix**)malloc(sizeof(Matrix*)*3);
slot_c9[0] = controlGen(0,9,not);
slot_c9[1] = identity;
slot_c9[2] = identity;
 calcSlot(&c, slot_c9);
 Matrix** slot_c10 = (Matrix**)malloc(sizeof(Matrix*)*2);
slot_c10[0] = controlGen(0,10,not);
slot_c10[1] = identity;
 calcSlot(&c, slot_c10);
 Matrix** slot_c11 = (Matrix**)malloc(sizeof(Matrix*)*1);
slot_c11[0] = controlGen(0,11,not);
 calcSlot(&c, slot_c11);
measurement(&c,0);
 outputQ("qubitoutput_c",c);
#ifdef RUNTIME
  gettimeofday(&t2, NULL);
  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
  printf("delta time for the total run %f ms.\n", elapsedTime);
 #endif
 return 0;
}