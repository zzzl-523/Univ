/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/* 
 * Please fill in the following team struct 
 */
team_t team = {
    "Lee, Jihyun",              /* name */

    "2019060164",     /* student ID */
    "zzh23@hanyang.ac.kr",  /* student email */

    "",                   /* Second member full name (leave blank if none) */
    ""                    /* Second member email addr (leave blank if none) */
};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

/* 
 * naive_rotate - The naive baseline version of rotate 
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}

/* 
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */


// V0
char rotate_descr[] = "rotate: Current working version";
void rotate(int dim, pixel *src, pixel *dst) 
{

int i, j;
    for(i = 0; i < dim; i = i + 16)
	{
		for(j = 0; j < dim; j++)
		{
			dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
			dst[RIDX(dim-1-j, i+1, dim)] = src[RIDX(i+1, j, dim)];
			dst[RIDX(dim-1-j, i+2, dim)] = src[RIDX(i+2, j, dim)];
			dst[RIDX(dim-1-j, i+3, dim)] = src[RIDX(i+3, j, dim)];
			dst[RIDX(dim-1-j, i+4, dim)] = src[RIDX(i+4, j, dim)];
			dst[RIDX(dim-1-j, i+5, dim)] = src[RIDX(i+5, j, dim)];
			dst[RIDX(dim-1-j, i+6, dim)] = src[RIDX(i+6, j, dim)];
			dst[RIDX(dim-1-j, i+7, dim)] = src[RIDX(i+7, j, dim)];
			dst[RIDX(dim-1-j, i+8, dim)] = src[RIDX(i+8, j, dim)];
			dst[RIDX(dim-1-j, i+9, dim)] = src[RIDX(i+9, j, dim)];
			dst[RIDX(dim-1-j, i+10, dim)] = src[RIDX(i+10, j, dim)];
			dst[RIDX(dim-1-j, i+11, dim)] = src[RIDX(i+11, j, dim)];
			dst[RIDX(dim-1-j, i+12, dim)] = src[RIDX(i+12, j, dim)];
			dst[RIDX(dim-1-j, i+13, dim)] = src[RIDX(i+13, j, dim)];
			dst[RIDX(dim-1-j, i+14, dim)] = src[RIDX(i+14, j, dim)];
			dst[RIDX(dim-1-j, i+15, dim)] = src[RIDX(i+15, j, dim)];
			//dst[RIDX(dim-1-j, i+16, dim)] = src[RIDX(i+16, j, dim)];
			

		}
	}

}

// V1
char rotate1_descr[] = "rotate1: Current working version";
void rotate1(int dim, pixel *src, pixel *dst) 
{
 int i, j;
   int i_;   
   for (i = 0; i < dim; i = i + 16){
    for (j = 0; j < dim; j++)
    {
      i_=i;
      dst[RIDX(dim-1-j, i_, dim)] = src[RIDX(i_, j, dim)];      i_++;
      dst[RIDX(dim-1-j, i_, dim)] = src[RIDX(i_, j, dim)];      i_++;
      dst[RIDX(dim-1-j, i_, dim)] = src[RIDX(i_, j, dim)];      i_++;
      dst[RIDX(dim-1-j, i_, dim)] = src[RIDX(i_, j, dim)];      i_++;
      dst[RIDX(dim-1-j, i_, dim)] = src[RIDX(i_, j, dim)];      i_++;
      dst[RIDX(dim-1-j, i_, dim)] = src[RIDX(i_, j, dim)];      i_++;
      dst[RIDX(dim-1-j, i_, dim)] = src[RIDX(i_, j, dim)];      i_++;
      dst[RIDX(dim-1-j, i_, dim)] = src[RIDX(i_, j, dim)];      i_++;
      dst[RIDX(dim-1-j, i_, dim)] = src[RIDX(i_, j, dim)];      i_++;
      dst[RIDX(dim-1-j, i_, dim)] = src[RIDX(i_, j, dim)];      i_++;
      dst[RIDX(dim-1-j, i_, dim)] = src[RIDX(i_, j, dim)];      i_++;
      dst[RIDX(dim-1-j, i_, dim)] = src[RIDX(i_, j, dim)];      i_++;
      dst[RIDX(dim-1-j, i_, dim)] = src[RIDX(i_, j, dim)];      i_++;
      dst[RIDX(dim-1-j, i_, dim)] = src[RIDX(i_, j, dim)];      i_++;
      dst[RIDX(dim-1-j, i_, dim)] = src[RIDX(i_, j, dim)];      i_++;
      

      dst[RIDX(dim-1-j, i_, dim)] = src[RIDX(i_, j, dim)];      
   }    
 }



}



// V2
//char rotate2_descr[] = "rotate2: Current working version";
//void rotate2(int dim, pixel *src, pixel *dst) 
//{


//}


/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_rotate_functions() 
{
    add_rotate_function(&naive_rotate, naive_rotate_descr);   
    add_rotate_function(&rotate, rotate_descr);
    add_rotate_function(&rotate1, rotate1_descr);   
   // add_rotate_function(&rotate2, rotate2_descr);

    /* ... Register additional test functions here */
}


/***************
 * SMOOTH KERNEL
 **************/

/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 **************************************************************/

/* A struct used to compute averaged pixel value */
typedef struct {
    int red;
    int green;
    int blue;
    int num;
} pixel_sum;

/* Compute min and max of two integers, respectively */
static int min(int a, int b) { return (a < b ? a : b); }
static int max(int a, int b) { return (a > b ? a : b); }

/* 
 * initialize_pixel_sum - Initializes all fields of sum to 0 
 */
static void initialize_pixel_sum(pixel_sum *sum) 
{
    sum->red = sum->green = sum->blue = 0;
    sum->num = 0;
    return;
}

/* 
 * accumulate_sum - Accumulates field values of p in corresponding 
 * fields of sum 
 */
static void accumulate_sum(pixel_sum *sum, pixel p) 
{
    sum->red += (int) p.red;
    sum->green += (int) p.green;
    sum->blue += (int) p.blue;
    sum->num++;
    return;
}

/* 
 * assign_sum_to_pixel - Computes averaged pixel value in current_pixel 
 */
static void assign_sum_to_pixel(pixel *current_pixel, pixel_sum sum) 
{
    current_pixel->red = (unsigned short) (sum.red/sum.num);
    current_pixel->green = (unsigned short) (sum.green/sum.num);
    current_pixel->blue = (unsigned short) (sum.blue/sum.num);
    return;
}

/* 
 * avg - Returns averaged pixel value at (i,j) 
 */
static pixel avg(int dim, int i, int j, pixel *src) 
{
    int ii, jj;
    pixel_sum sum;
    pixel current_pixel;

    initialize_pixel_sum(&sum);
    for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++) 
	for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++) 
	    accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

    assign_sum_to_pixel(&current_pixel, sum);
    return current_pixel;
}

/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/

/*
 * naive_smooth - The naive baseline version of smooth 
 */
char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
void naive_smooth(int dim, pixel *src, pixel *dst) 
{
   int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
}

/*
 * smooth - Your current working version of smooth. 
 * IMPORTANT: This is the version you will be graded on
 */

// V0
char smooth_descr[] = "smooth: Current working version";
void smooth(int dim, pixel *src, pixel *dst) 
{

    int i, j;   

    i = 0;
    j = 0;

    dst[RIDX(0, 0, dim)].red = (unsigned short)(((int)
                   (src[RIDX(0, 0, dim)].red + src[RIDX(0, 1, dim)].red + 
                   src[RIDX(1, 0, dim)].red + src[RIDX(1, 1, dim)].red)) >> 2);
    dst[RIDX(0, 0, dim)].green = (unsigned short)(((int)
                   (src[RIDX(0, 0, dim)].green + src[RIDX(0, 1, dim)].green + 
                   src[RIDX(1, 0, dim)].green + src[RIDX(1, 1, dim)].green)) >> 2);
    dst[RIDX(0, 0, dim)].blue = (unsigned short)(((int)
                   (src[RIDX(0, 0, dim)].blue + src[RIDX(0, 1, dim)].blue + 
                   src[RIDX(1, 0, dim)].blue + src[RIDX(1, 1, dim)].blue)) >> 2);

    i = 0;
    j = dim - 1;
    dst[RIDX(i, j, dim)].red = (unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i, j - 1, dim)].red + src[RIDX(i + 1, j, dim)].red + src[RIDX(i + 1, j - 1, dim)].red)) >> 2);
    dst[RIDX(i, j, dim)].green = (unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i, j - 1, dim)].green + src[RIDX(i + 1, j, dim)].green +  src[RIDX(i + 1, j - 1, dim)].green)) >> 2);
    dst[RIDX(i, j, dim)].blue = (unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i, j - 1, dim)].blue + src[RIDX(i + 1, j, dim)].blue +  src[RIDX(i + 1, j - 1, dim)].blue)) >> 2);

    i = dim - 1;
    j = 0;
    dst[RIDX(i, j, dim)].red = (unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i, j + 1, dim)].red + src[RIDX(i - 1, j, dim)].red +  src[RIDX(i - 1, j + 1, dim)].red)) >> 2);
    dst[RIDX(i, j, dim)].green = (unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i, j + 1, dim)].green + src[RIDX(i - 1, j, dim)].green + src[RIDX(i - 1, j + 1, dim)].green)) >> 2);
    dst[RIDX(i, j, dim)].blue = (unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i, j + 1, dim)].blue + src[RIDX(i - 1, j, dim)].blue + src[RIDX(i - 1, j + 1, dim)].blue)) >> 2);

    i = dim - 1;
    j = dim - 1;
    dst[RIDX(i, j, dim)].red = (unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i, j - 1, dim)].red + src[RIDX(i - 1, j, dim)].red + src[RIDX(i - 1, j - 1, dim)].red)) >> 2);
    dst[RIDX(i, j, dim)].green = (unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i, j - 1, dim)].green + src[RIDX(i - 1, j, dim)].green + src[RIDX(i - 1, j - 1, dim)].green)) >> 2);
    dst[RIDX(i, j, dim)].blue = (unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i, j - 1, dim)].blue + src[RIDX(i - 1, j, dim)].blue + src[RIDX(i - 1, j - 1, dim)].blue)) >> 2);

    j = 0;
    for (i = 1; i < dim - 1; i++)
    {
        dst[RIDX(i, j, dim)].red = (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].red + src[RIDX(i - 1, j + 1, dim)].red +
                                    src[RIDX(i, j, dim)].red + src[RIDX(i, j + 1, dim)].red +
                                    src[RIDX(i + 1, j, dim)].red + src[RIDX(i + 1, j + 1, dim)].red)) / 6);
        dst[RIDX(i, j, dim)].green = (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].green + src[RIDX(i - 1, j + 1, dim)].green +
                                    src[RIDX(i, j, dim)].green + src[RIDX(i, j + 1, dim)].green +
                                    src[RIDX(i + 1, j, dim)].green + src[RIDX(i + 1, j + 1, dim)].green)) / 6);
        dst[RIDX(i, j, dim)].blue = (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].blue + src[RIDX(i - 1, j + 1, dim)].blue +
                                    src[RIDX(i, j, dim)].blue + src[RIDX(i, j + 1, dim)].blue +
                                    src[RIDX(i + 1, j, dim)].blue + src[RIDX(i + 1, j + 1, dim)].blue)) / 6);
    }

    i = dim - 1;
    for (j = 1; j < dim - 1; j++)
    {
        dst[RIDX(i, j, dim)].red = (unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i - 1, j, dim)].red +
                                    src[RIDX(i, j - 1, dim)].red + src[RIDX(i - 1, j - 1, dim)].red +
                                    src[RIDX(i, j + 1, dim)].red + src[RIDX(i - 1, j + 1, dim)].red)) / 6);
        dst[RIDX(i, j, dim)].green = (unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i - 1, j, dim)].green +
                                    src[RIDX(i, j - 1, dim)].green + src[RIDX(i - 1, j - 1, dim)].green +
                                    src[RIDX(i, j + 1, dim)].green + src[RIDX(i - 1, j + 1, dim)].green)) / 6);
        dst[RIDX(i, j, dim)].blue = (unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i - 1, j, dim)].blue +
                                    src[RIDX(i, j - 1, dim)].blue + src[RIDX(i - 1, j - 1, dim)].blue +
                                    src[RIDX(i, j + 1, dim)].blue + src[RIDX(i - 1, j + 1, dim)].blue)) / 6);
    }

    j = dim - 1;
    for (i = 1; i < dim - 1; i++)
    {
        dst[RIDX(i, j, dim)].red = (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].red + src[RIDX(i - 1, j - 1, dim)].red +
                                    src[RIDX(i, j, dim)].red + src[RIDX(i, j - 1, dim)].red +
                                    src[RIDX(i + 1, j, dim)].red + src[RIDX(i + 1, j - 1, dim)].red)) / 6);
        dst[RIDX(i, j, dim)].green = (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].green + src[RIDX(i - 1, j - 1, dim)].green +
                                    src[RIDX(i, j, dim)].green + src[RIDX(i, j - 1, dim)].green +
                                    src[RIDX(i + 1, j, dim)].green + src[RIDX(i + 1, j - 1, dim)].green)) / 6);
        dst[RIDX(i, j, dim)].blue = (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].blue + src[RIDX(i - 1, j - 1, dim)].blue +
                                    src[RIDX(i, j, dim)].blue + src[RIDX(i, j - 1, dim)].blue +
                                    src[RIDX(i + 1, j, dim)].blue + src[RIDX(i + 1, j - 1, dim)].blue)) / 6);

    }

    i = 0;
    for (j = 1; j < dim - 1; j++)
    {
        dst[RIDX(i, j, dim)].red = (unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i + 1, j, dim)].red +
                                    src[RIDX(i, j - 1, dim)].red + src[RIDX(i + 1, j - 1, dim)].red +
                                    src[RIDX(i, j + 1, dim)].red + src[RIDX(i + 1, j + 1, dim)].red)) / 6);
        dst[RIDX(i, j, dim)].green = (unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i + 1, j, dim)].green +
                                    src[RIDX(i, j - 1, dim)].green + src[RIDX(i + 1, j - 1, dim)].green +
                                    src[RIDX(i, j + 1, dim)].green + src[RIDX(i + 1, j + 1, dim)].green)) / 6);
        dst[RIDX(i, j, dim)].blue = (unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i + 1, j, dim)].blue +
                                    src[RIDX(i, j - 1, dim)].blue + src[RIDX(i + 1, j - 1, dim)].blue +
                                    src[RIDX(i, j + 1, dim)].blue + src[RIDX(i + 1, j + 1, dim)].blue)) / 6);
    }


   pixel *pA = &src[0]; 
   pixel *pB = &src[dim];
   pixel *pC = &src[dim+dim];
   pixel *pD = &src[dim+dim+dim];

   int sum0_red, sum0_green, sum0_blue;
   int sum1_red, sum1_green, sum1_blue;
   int sum2_red, sum2_green, sum2_blue;
   int sum3_red, sum3_green, sum3_blue;
   int sum4_red, sum4_green, sum4_blue;
   int sum5_red, sum5_green, sum5_blue; 


   int index_first = dim+1;
   int index_second = index_first+dim;

   for (i = 1; i < dim - 2; i = i + 2) {
      sum0_red = pB->red;
      sum0_blue = pB->blue;
      sum0_green = pB->green;

      sum0_red += pC->red;
      sum0_blue += pC->blue;
      sum0_green += pC->green;
      sum3_red = sum0_red+pD->red;
      sum3_green = sum0_green+pD->green;
      sum3_blue = sum0_blue+pD->blue;
      sum0_red += pA->red;
      sum0_blue += pA->blue;
      sum0_green += pA->green;

      pA++;      pB++;      pC++;      pD++;

      sum1_red = pB->red;
      sum1_green = pB->green;
      sum1_blue = pB->blue;
      sum1_red += pC->red;
      sum1_green += pC->green;
      sum1_blue += pC->blue;
      sum4_red = sum1_red+pD->red;
      sum4_green = sum1_green+pD->green;
      sum4_blue = sum1_blue+pD->blue;
      sum1_red += pA->red;
      sum1_green += pA->green;
      sum1_blue += pA->blue;


      pA++;      pB++;      pC++;      pD++;

      sum2_red = pB->red;
      sum2_green = pB->green;
      sum2_blue = pB->blue;

      sum2_red += pC->red;
      sum2_green += pC->green;
      sum2_blue += pC->blue;

      sum5_red = sum2_red+pD->red;
      sum5_green = sum2_green+pD->green;
      sum5_blue = sum2_blue+pD->blue;

      sum2_red += pA->red;
      sum2_green += pA->green;
      sum2_blue += pA->blue;

      pA++;      pB++;      pC++;      pD++;

      dst[index_first].red = ((sum0_red+sum1_red+sum2_red)/9);
      dst[index_first].green = ((sum0_green+sum1_green+sum2_green)/9);
      dst[index_first].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
      index_first++;
      dst[index_second].red = ((sum3_red+sum4_red+sum5_red)/9);
      dst[index_second].green = ((sum3_green+sum4_green+sum5_green)/9);
      dst[index_second].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
      index_second++;

      sum0_red = sum1_red;
      sum1_red = sum2_red;
      sum0_green = sum1_green;
      sum1_green = sum2_green;
      sum0_blue = sum1_blue;
      sum1_blue = sum2_blue;
      sum3_red = sum4_red;
      sum4_red = sum5_red;
      sum3_green = sum4_green;
      sum4_green = sum5_green;
      sum3_blue = sum4_blue;
      sum4_blue = sum5_blue;

      for (j = 2; j < dim-4; j = j + 4) {

	
         sum2_red = pB->red;
         sum2_green = pB->green;
         sum2_blue = pB->blue;

         sum2_red += pC->red;
         sum2_green += pC->green;
         sum2_blue += pC->blue;

         sum5_red = sum2_red+pD->red;
         sum5_blue = sum2_blue+pD->blue;
         sum5_green = sum2_green+pD->green;

         sum2_red += pA->red;
         sum2_green += pA->green;
         sum2_blue += pA->blue;

         pA++;      pB++;      pC++;      pD++;


         dst[index_first].red = ((sum0_red+sum1_red+sum2_red)/9);
         dst[index_first].green = ((sum0_green+sum1_green+sum2_green)/9);
         dst[index_first].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
         index_first++;
         dst[index_second].red = ((sum3_red+sum4_red+sum5_red)/9);
         dst[index_second].green = ((sum3_green+sum4_green+sum5_green)/9);
         dst[index_second].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
         index_second++;

         sum0_red = sum1_red;
         sum1_red = sum2_red;
         sum0_green = sum1_green;
         sum1_green = sum2_green;
         sum0_blue = sum1_blue;
         sum1_blue = sum2_blue;
         sum3_red = sum4_red;
         sum4_red = sum5_red;
         sum3_green = sum4_green;
         sum4_green = sum5_green;
         sum3_blue = sum4_blue;
         sum4_blue = sum5_blue;


         sum2_red = pB->red;
         sum2_green = pB->green;
         sum2_blue = pB->blue;

         sum2_red += pC->red;
         sum2_green += pC->green;
         sum2_blue += pC->blue;

         sum5_red = sum2_red+pD->red;
         sum5_blue = sum2_blue+pD->blue;
         sum5_green = sum2_green+pD->green;

         sum2_red += pA->red;
         sum2_green += pA->green;
         sum2_blue += pA->blue;

         pA++;      pB++;      pC++;      pD++;

         dst[index_first].red = ((sum0_red+sum1_red+sum2_red)/9);
         dst[index_first].green = ((sum0_green+sum1_green+sum2_green)/9);
         dst[index_first].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
         index_first++;
         dst[index_second].red = ((sum3_red+sum4_red+sum5_red)/9);
         dst[index_second].green = ((sum3_green+sum4_green+sum5_green)/9);
         dst[index_second].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
         index_second++;

         sum0_red = sum1_red;
         sum1_red = sum2_red;
         sum0_green = sum1_green;
         sum1_green = sum2_green;
         sum0_blue = sum1_blue;
         sum1_blue = sum2_blue;
         sum3_red = sum4_red;
         sum4_red = sum5_red;
         sum3_green = sum4_green;
         sum4_green = sum5_green;
         sum3_blue = sum4_blue;
         sum4_blue = sum5_blue;


         sum2_red = pB->red;
         sum2_green = pB->green;
         sum2_blue = pB->blue;

         sum2_red += pC->red;
         sum2_green += pC->green;
         sum2_blue += pC->blue;

         sum5_red = sum2_red+pD->red;
         sum5_blue = sum2_blue+pD->blue;
         sum5_green = sum2_green+pD->green;

         sum2_red += pA->red;
         sum2_green += pA->green;
         sum2_blue += pA->blue;

         pA++;      pB++;      pC++;      pD++;

         dst[index_first].red = ((sum0_red+sum1_red+sum2_red)/9);
         dst[index_first].green = ((sum0_green+sum1_green+sum2_green)/9);
         dst[index_first].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
         index_first++;
         dst[index_second].red = ((sum3_red+sum4_red+sum5_red)/9);
         dst[index_second].green = ((sum3_green+sum4_green+sum5_green)/9);
         dst[index_second].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
         index_second++;

         sum0_red = sum1_red;
         sum1_red = sum2_red;
         sum0_green = sum1_green;
         sum1_green = sum2_green;
         sum0_blue = sum1_blue;
         sum1_blue = sum2_blue;
         sum3_red = sum4_red;
         sum4_red = sum5_red;
         sum3_green = sum4_green;
         sum4_green = sum5_green;
         sum3_blue = sum4_blue;
         sum4_blue = sum5_blue;


         sum2_red = pB->red;
         sum2_green = pB->green;
         sum2_blue = pB->blue;

         sum2_red += pC->red;
         sum2_green += pC->green;
         sum2_blue += pC->blue;

         sum5_red = sum2_red+pD->red;
         sum5_blue = sum2_blue+pD->blue;
         sum5_green = sum2_green+pD->green;

         sum2_red += pA->red;
         sum2_green += pA->green;
         sum2_blue += pA->blue;

         pA++;      pB++;      pC++;      pD++;

         dst[index_first].red = ((sum0_red+sum1_red+sum2_red)/9);
         dst[index_first].green = ((sum0_green+sum1_green+sum2_green)/9);
         dst[index_first].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
         index_first++;
         dst[index_second].red = ((sum3_red+sum4_red+sum5_red)/9);
         dst[index_second].green = ((sum3_green+sum4_green+sum5_green)/9);
         dst[index_second].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
         index_second++;

         sum0_red = sum1_red;
         sum1_red = sum2_red;
         sum0_green = sum1_green;
         sum1_green = sum2_green;
         sum0_blue = sum1_blue;
         sum1_blue = sum2_blue;
         sum3_red = sum4_red;
         sum4_red = sum5_red;
         sum3_green = sum4_green;
         sum4_green = sum5_green;
         sum3_blue = sum4_blue;
         sum4_blue = sum5_blue;

      }

      for (; j < dim-1; j++) {
	 sum2_red = pB->red;
         sum2_green = pB->green;
         sum2_blue = pB->blue;

         sum2_red += pC->red;
         sum2_green += pC->green;
         sum2_blue += pC->blue;

         sum5_red = sum2_red+pD->red;
         sum5_blue = sum2_blue+pD->blue;
         sum5_green = sum2_green+pD->green;

         sum2_red += pA->red;
         sum2_green += pA->green;
         sum2_blue += pA->blue;

         pA++;      pB++;      pC++;      pD++;

	 dst[index_first].red = ((sum0_red+sum1_red+sum2_red)/9);
         dst[index_first].green = ((sum0_green+sum1_green+sum2_green)/9);
         dst[index_first].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
         index_first++;
         dst[index_second].red = ((sum3_red+sum4_red+sum5_red)/9);
         dst[index_second].green = ((sum3_green+sum4_green+sum5_green)/9);
         dst[index_second].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
         index_second++;		

         sum0_red = sum1_red;
         sum1_red = sum2_red;
         sum0_green = sum1_green;
         sum1_green = sum2_green;
         sum0_blue = sum1_blue;
         sum1_blue = sum2_blue;
         sum3_red = sum4_red;
         sum4_red = sum5_red;
         sum3_green = sum4_green;
         sum4_green = sum5_green;
         sum3_blue = sum4_blue;
         sum4_blue = sum5_blue;
      }


      pA += dim;
      pB += dim;
      pC += dim;
      pD += dim;
      index_first += dim+2;
      index_second += dim+2;
   }


}

// V1
char smooth1_descr[] = "smooth1: Current working version";
void smooth1(int dim, pixel *src, pixel *dst) 
{



int j = 0;
    int i = 0;

    for (j = 0; j < dim; j= j+16)
    {
        for (i = 0;  i< dim; i++)
        {

        dst[RIDX(j, i, dim)] = avg(dim, j, i, src);
        dst[RIDX(j+1, i, dim)] = avg(dim, j+1, i, src);
        dst[RIDX(j+2, i, dim)] = avg(dim, j+2, i, src);
        dst[RIDX(j+3, i, dim)] = avg(dim, j+3, i, src);
        dst[RIDX(j+4, i, dim)] = avg(dim, j+4, i, src);
        dst[RIDX(j+5, i, dim)] = avg(dim, j+5, i, src);
        dst[RIDX(j+6, i, dim)] = avg(dim, j+6, i, src);
        dst[RIDX(j+7, i, dim)] = avg(dim, j+7, i, src);
        dst[RIDX(j+8, i, dim)] = avg(dim, j+8, i, src);
        dst[RIDX(j+9, i, dim)] = avg(dim, j+9, i, src);
        dst[RIDX(j+10, i, dim)] = avg(dim, j+10, i, src);
        dst[RIDX(j+11, i, dim)] = avg(dim, j+11, i, src);
        dst[RIDX(j+12, i, dim)] = avg(dim, j+12, i, src);
        dst[RIDX(j+13, i, dim)] = avg(dim, j+13, i, src);
        dst[RIDX(j+14, i, dim)] = avg(dim, j+14, i, src);
        dst[RIDX(j+15, i, dim)] = avg(dim, j+15, i, src);
       

        }


    }
}


// V2
//char smooth2_descr[] = "smooth2: Current working version";
//void smooth2(int dim, pixel *src, pixel *dst) 
//{
   
//}



/********************************************************************* 
 * register_smooth_functions - Register all of your different versions
 *     of the smooth kernel with the driver by calling the
 *     add_smooth_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_smooth_functions() {
    add_smooth_function(&naive_smooth, naive_smooth_descr);
    add_smooth_function(&smooth, smooth_descr);
    add_smooth_function(&smooth1, smooth1_descr);
    //add_smooth_function(&smooth2, smooth2_descr);
    /* ... Register additional test functions here */
}
