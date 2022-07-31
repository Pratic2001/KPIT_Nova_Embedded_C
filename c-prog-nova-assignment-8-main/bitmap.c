#include<stdio.h>
#include<math.h>
#include "bitmap.h"


/*

This function returns the approximated value for angle passed in struct Data variable till the limit 
specified by the degree field in the struct.

The function must implement the formula required for the approximation as given in
the document and return the answer with upto 6 places of decimal precision.

Notes:
●	All angles stored in the struct member will be in degrees and must be converted 
    to radian before calculation of final answer.
●	The limit given by the system's hidden test cases will not exceed 10 
    to avoid integer overflow during factorial calculation.

*/


float approximateTaylorSeries(struct Data d1)
{
    
    float x,Q,sum=0;
    int i,j,limit;
    
    x = d1.angle;
    limit = d1.degree;
    
    Q=x;
    x = x * (3.1415/180);

    for(i=1,j=1;i<=limit;i++,j=j+2)
    {
        if(i%2!=0)
        {
            sum=sum+pow(x,j)/factorial(j);
        }
        else
            sum=sum-pow(x,j)/factorial(j);
    }
    
    return sum;    
}


/* 

This function returns the factorial of integer passed if it is greater than or equal to 0.

For negative numbers, the function must return -1 as an answer to indicate invalid values.

*/

int factorial(int x)
{

    int i,fac;
    if(x >= 0){
        fac = 1;
        for(i=1; i <= x; i++)
            fac=fac*i;
    
        return fac;
    }
    
    return -1;
}
