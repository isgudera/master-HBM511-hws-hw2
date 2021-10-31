    #include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <iostream>
#define SIZE 3

using namespace std;

double randBtw(double lb, double ub) {
    double range = (ub - lb);
    double div = RAND_MAX / range;
    return (lb + (rand() / div));
}

void fill_2dStackMatRand(double A[SIZE][SIZE] , int row, int col ) {
    int i,j,val;
    for(i=0; i<row;i++) {
    	for(j=0 ; j<col; j++){
            //printf("Enter value");
            ///scanf("%d", &val);
    	    A[i][j] = randBtw(0.0 , 1.0);//1 + rand()%10;//
	   }
    }

}
// << "\t"


void LU_Decomposition_2dStackMat(double A[SIZE][SIZE], double L[SIZE][SIZE] , double U[SIZE][SIZE],int row, int col ) {

    int i,j,k;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%6.4lf\t", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%6.4lf\t", U[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%6.4lf\t", L[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    double sum;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
    	    if (i>j) {
    	    	U[i][j]=0;
    	    }
            else {
           //     sum = 0;
                //printf("Sum: %6.4lf\n", U[i][j]); 
                U[i][j] = A[i][j];
                for (int k = 0; k < i; k++)
                {
                    printf("L[%d][%d]:  %lf\n", i,k,L[i][k]);
                    U[i][j] = U[i][j] - L[i][k]*U[k][j];
                    printf("i:%d,  j:%d,  k:%d  \n",i,j,k );
                    printf("Sum: %6.4lf\n", U[i][j]);
                }
            }
        }
    	for (int j = 0; j < col; j++)
    	{
    	    if (i==j) {
   	    	L[j][i]=1;
    	    }
    	    else if (i>j) {
    	    	L[j][i]=0;
    	    }
    	    else {
                L[j][i] = A[j][i]/U[i][i];
                //sum = 0;
                for (int k = 0; k < j; k++)
                {
                    L[j][i] = (L[j][i] - L[j][k]*U[k][i]) * U[i][i];
                }
            }
    	}
    }

}


void MatrixMulti_2_2 (double L[SIZE][SIZE] , double U[SIZE][SIZE], double R[SIZE][SIZE], int row, int col ) {

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            //R[i][j] = 0;
            for (int k = 0; k < SIZE; k++)
            {
                R[i][j] = R[i][j] +     L[i][k]*U[k][j];
            }
        }
    }

}


void print_2DStackMat(double A[SIZE][SIZE] , int row, int col)
{
    for (int i = 0; i < row; i++)
    {
	for (int j = 0; j < col; j++)
	{
	    printf("%6.4lf\t", A[i][j]);
	}
	printf("\n");
    }
    printf("\n");

}

void transpose_2dStackMat(double A[SIZE][SIZE] , double M[SIZE][SIZE] ,int row, int col) {
    for (int i = 0; i < row; i++)
    {
	for (int j = 0; j < col; j++)
	{
	    M[j][i] = A[i][j];
	}
    }

}

int main(int argc, char const *argv[]) 
{
    srand(time(NULL));
    double A[SIZE][SIZE],transA[SIZE][SIZE], L[SIZE][SIZE], U[SIZE][SIZE], R[SIZE][SIZE];
    fill_2dStackMatRand(A,SIZE,SIZE); // A matrisi oluşturuldu.
    transpose_2dStackMat(A,transA,SIZE,SIZE);
    printf("A Matrix:\n");
    print_2DStackMat(A,SIZE,SIZE);
    //	printf("\n");

//    print_2DStackMat(transA,SIZE,SIZE);

    LU_Decomposition_2dStackMat(A,L,U,SIZE,SIZE);
    printf("L Matrix:\n");
    print_2DStackMat(L,SIZE,SIZE);
    printf("U Matrix:\n");
    print_2DStackMat(U,SIZE,SIZE);
    MatrixMulti_2_2(L,U,R,SIZE,SIZE);
    printf("R Matrix:\n");
    print_2DStackMat(R,SIZE,SIZE);
    double R2[3][3];

    double M1[3][3] = {
        {1,2,3},
        {3,4,4},
        {5,6,7}
    };
    
    double M2[3][3] = {
        {3,6,2},
        {1,8,6},
        {2,3,6}
    };
    MatrixMulti_2_2(M1,M2,R2,3,3);
    print_2DStackMat(R2,3,3);

    printf("Hello world %d\n", SIZE);
    return 0;
}

