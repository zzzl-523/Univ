//2019060164
/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */
                                                                                                                                                          
 
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
  int col = 0,row = 0;
  int i = 0, j = 0, k = 0;
  int Miss = 0;
  int M61_67 = 0;
  int b_32_32 = 8;
  int b_64_64 = 4;
  int b_61_67 = 16;

  
  if(M == 32){
    for(row = 0; row < M; row += b_32_32){
      for(col =0; col < M; col += b_32_32){
	for(i = row; i < row + b_32_32; i++){
	  for(j = col; j < col + b_32_32; j++){
	    if(i == j){
	      k = i;
	      Miss = A[i][j];
	    }
	    else{
	      B[j][i] = A[i][j];
	    }
	  }

	  if(row == col){
	    B[k][k] = Miss;
	  }
	}
      }
    }
  }


 else if(M == 64){
   int temp,temp1,temp2,temp3,temp4,temp5,temp6,temp7;

    for(row = 0; row < M; row += b_32_32){
      for(col =0; col < M; col += b_32_32){
        for(i = row; i < row + b_64_64; i++){
            temp=A[i][col];
            temp1=A[i][col+1];
            temp2=A[i][col+2];
            temp3=A[i][col+3];
            temp4=A[i][col+4];
            temp5=A[i][col+5];
            temp6=A[i][col+6];
            temp7=A[i][col+7];

            B[col][i]=temp;
            B[col+1][i]=temp1;
            B[col+2][i]=temp2;
            B[col+3][i]=temp3;
            B[col][i+4]=temp4;
            B[col+1][i+4]=temp5;
            B[col+2][i+4]=temp6;
            B[col+3][i+4]=temp7;

      }
      for(i=col;i<col+b_64_64;i++){
          temp4=A[row+4][i];
          temp5=A[row+5][i];
          temp6=A[row+6][i];
          temp7=A[row+7][i];

          temp=B[i][row+4];
          temp1=B[i][row+5];
          temp2=B[i][row+6];
          temp3=B[i][row+7];
         
          B[i][row+4]=temp4;
          B[i][row+5]=temp5;
          B[i][row+6]=temp6;
          B[i][row+7]=temp7;
          B[i+4][row]=temp;
          B[i+4][row+1]=temp1;
          B[i+4][row+2]=temp2;
          B[i+4][row+3]=temp3;

          for(int l=0;l<b_64_64;l++){
              B[i+4][row+l+4] = A[row+l+4][i+4];

          }
        }
      }
    }
  }


 else{
  
   for(row = 0; row < 67; row += b_61_67){
     for(col = 0; col < 61; col += b_61_67){
       for(i = row;  (i < row + b_61_67) && (i < 67); i++){
    	 for(j = col; (j < col + b_61_67) && (j < 61);j++){
          if(i == j){
	       
	       k = i;
	       M61_67 = A[i][j];
	     }
	     else{

	       B[j][i] = A[i][j];
	       
	     }      
	 }

	 if(row == col){
	   B[k][k] = M61_67;
	 }
    
       }
   
     }
   }

 }
}
/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc); 

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}
