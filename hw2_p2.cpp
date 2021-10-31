#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill2dMatrix (double **A, int row, int col) {
	int value;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{	
			printf("Lütfen A[%d][%d] için değer giriniz\n", i,j);
			scanf("%lf", A[i][j]);
		//	A[i][j] = value;
		}
	}
}

void print_2DMatrix(double **A , int row, int col)
{
    printf("\n");
    for (int i = 0; i < row; i++)
    {
		for (int j = 0; j < col; j++)
		{
	    	printf("%6.4lf\t", A[i][j]);
		}
		printf("\n");
    }

}

void	getMemory(double **A, int size)
{
	A = (double **)malloc(size * sizeof(double*));
	for (int i = 0; i<size; i++)
	{
		A[i] = (double *)malloc(size*sizeof(double));
	}
	printf("Memory is taken.\n");

}
void	releaseMemory(double **A, int size){
	for (int i = 0; i < size; i++)
	{
		free(A[i]);
	}
	
	free(A);
	printf("Memory is released.\n");
}
int main(int argc, char const *argv[])
{
	int size;
	printf("Bu program kullanıcı tarafından girilen bir matrisin simetirk olup olmadığını kontrol eder.\n");
	printf("Lütfen kare matrisin boyutunu giriniz: ");
	scanf("%d", &size);
	double **A;
	A = (double **)malloc(size * sizeof(double*));
	for (int i = 0; i<size; i++)
	{
		A[i] = (double *)malloc(size*sizeof(double));
	}
	printf("Memory is taken.\n");
	//getMemory(A,size);

	fill2dMatrix(A,size,size);
	print_2DMatrix(A,size,size);
	releaseMemory(A,size);

	return 0;
}






