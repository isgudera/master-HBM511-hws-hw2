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
                        A[i][j] = randBtw(0.0 , 1.0);
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

void getUpper_2dStackMat(double A[SIZE][SIZE], A[SIZE][SIZE],int row, int col ) {
	for (int i = 0; i < row; ++i)
	{
		/* code */
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

	double A[SIZE][SIZE],transA[SIZE][SIZE], L[SIZE][SIZE], U[SIZE][SIZE], R[SIZE][SIZE];
	fill_2dStackMatRand(A,SIZE,SIZE); // A matrisi oluşturuldu.
	transpose_2dStackMat(A,transA,SIZE,SIZE);

	print_2DStackMat(A,SIZE,SIZE);
//	printf("\n");

	print_2DStackMat(transA,SIZE,SIZE);

	printf("Hello world %d\n", SIZE);
	return 0;
}