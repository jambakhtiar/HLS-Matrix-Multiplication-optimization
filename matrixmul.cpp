
#include "matrixmul.h"

void matrixmul(
      mat_a_t a[MAT_A_ROWS][MAT_A_COLS],
      mat_b_t b[MAT_B_ROWS][MAT_B_COLS],
      result_t res[MAT_A_ROWS][MAT_B_COLS])
{
  /*
  #pragma HLS ARRAY_RESHAPE variable=b complete dim=0
  #pragma HLS ARRAY_RESHAPE variable=a complete dim=0
  #pragma HLS ARRAY_RESHAPE variable=res complete dim=0
  #pragma HLS INTERFACE ap_vld port=a
  #pragma HLS INTERFACE ap_vld port=b
  #pragma HLS INTERFACE ap_vld port=res
  #pragma HLS PIPELINE II=1
*/
  // Iterate over the rows of the A matrix
  Row: for(int i = 0; i < MAT_A_ROWS; i++) {
    // Iterate over the columns of the B matrix
    Col: for(int j = 0; j < MAT_B_COLS; j++) {
      result_t tmp = 0;
      // Do the inner product of a row of A and col of B
      Product: for(int k = 0; k < MAT_B_ROWS; k++) {
       // #pragma HLS UNROLL
        tmp += a[i][k] * b[k][j];
      }
      res[i][j] = tmp;
    }
  }
}
      
