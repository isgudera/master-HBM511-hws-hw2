#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define SIZE 3

using namespace std;

double randBtw(double lb, double ub) {
    double range = (ub - lb);
    double div = RAND_MAX / range;
    return lb + (rand() / div);
}

void fill_2dStackMatRand(double A[SIZE][SIZE] , int row, int col ) {
    int i,j;
    for(i=0; i<row;i++) {
    	for(j=0 ; j<col; j++){
    	    A[i][j] = 1 + rand()%10;// randBtw(0.0 , 1.0);
	}
    }

}

void fill_StackVecRand(double A[SIZE] , int row)
{
    for (int i = 0; i < row; i++)
    {
	A[i] = randBtw(0.0 , 1.0);
    }
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

void LU_Decomposition_2dStackMat(double A[SIZE][SIZE], double L[SIZE][SIZE] , double U[SIZE][SIZE],int row, int col ) {
    double sum;
    for (int i = 0; i < row; i++)
    {
    	for (int j = 0; j < col; j++)
    	{
    	    if (i==j) {
    	    	L[i][j]=1;
    	    }
    	    else if (i>j) {
    	    	L[i][j]=0;
    	    }
    	    else {
                sum = 0; 
                for (int k = 0; k < i-1; k++)
                {
                    sum += L[i][k]*U[k][j];
                }
                L[i][j] = (A[i][j] - sum) / U[j][j];
    	    }
    	}

        for (int j = 0; j < col; j++)
        {
    	    if (i>j) {
    	    	U[i][j]=0;
    	    }
            else {
                sum = 0; 
                for (int k = 0; k < i-1; k++)
                {
                    sum += L[i][k]*U[k][j];
                }
                U[i][j] = A[i][j] - sum;
            }
        }
    }
}


void MatrixMulti_2_2 (double L[SIZE][SIZE] , double U[SIZE][SIZE], double R[SIZE][SIZE], int row, int col ) {

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            for (int k = 0; k < SIZE; k++)
            {
                R[i][j] = L[i][k]*U[k][j];
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

void print_StackVec(double A[SIZE] , int row)
{
    printf("\n");
    for (int i = 0; i < row; i++)
    {
	printf("%6.4lf\t", A[i]);
    }
    printf("\n");
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


    printf("Hello world %d\n", SIZE);
    return 0;
}

