#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
double	func (double x) {
	return pow(x,3) - 11.0;
}
double	func2 (double x) {
	return pow(3*x*x+11,0.25);
	//return (11+x) / pow(x,2)+1;
}
double bisection(double a, double b, double tol) {
	double x;
	int i=0;
	x = (a + b) / 2;
	while (fabs(func(a)) > tol) {
		x = (a+b)/2;
		printf("%d --> %6.9lf\n" , i , x);
		if (func(x) < 0 )
		{
			a = x;
		}
		else {
			b = x;
		}
		i++;
	}
	return x;
}

double fixedPointIter(double p0, double tol, int N) {
	double p;
	int i=1;
	printf("%6.20lf\n", fabs(p-p0));
	while (i <= N) {
		p = func2(p0);
		if (fabs(p-p0) < tol)
		{
			printf("%6.20lf\n", p);
			break;
		}
		printf("Iteration %d: Current value = %lf\n",i,p);
		i++;
		p0 = func2(p);
		if(i>N)
    	{
			printf("Solution not found (method diverges)\n");
			break;
		}
	}
	return p;
}

int main(int argc, char const *argv[])
{
	double x1,x2;
	double y ;// = std::cbrt(x);

	double a = -900;
	double b = 3;
	double tol = 1e-8;
	x1 = bisection(a,b,tol);
	double p0 = 1;
	int N = 15;
	x2 = fixedPointIter(p0,tol,N);

/*	double error = std::cbrt(11);
		y = func(x);
		printf("%6.20lf\n", y);
		int i=0;
	x = (a+b)/2;
	while (abs(func(x)) > tol) {

		x = (a+b)/2;
		printf("%d\n", i);
		printf("%6.20lf\n", x);
		y = func(x);
		if (y < 0)
		{
			a = x;
		}
		else {
			b = x;
		}
		y = func(x);
		//printf("%6.20lf\n", y);
		i++;
	}
*/
	//	y = func(x);
	printf("x1: %6.20lf  and x2: %6.20lf \n", x1,x2);
	return 0;
}