#include"bitmap.h"


/*The function returns unsigned integer.

In this case the function accept unsigned integer as input (valid inputs from 1 to 9)
and the output should be in below pattern.
If the input value of Num =3, then output will be 333, 
if the value of Num =9, then output will be 999999999 can be 
achieved without using control statement like switch, if, if-else and loop statement.*/

unsigned int resultant = 0;
unsigned int balancer = 0;

int Sequence(unsigned int Num)
{
   unsigned int digit = Num + balancer;
   unsigned int result = (resultant * 10) + digit;
   
   balancer ++;
   resultant = result;
   
   return (Num == 1) ? result : Sequence(--Num);
}


/* 
The function returns unsigned integer either ‘1’ or ‘0’.
Input consists of one unsigned integer. In this case the function checks
the given number is Niven Number or Not. Niven Number is an integer that is
divisible by the sum of its digits. If its Niven Number then it returns 0, if not it returns 1.
Ex:   156 
It is Niven Number. The above Number (156) is divisible by sum of its digits. 
156  1+5+6 =12. Hence 156 can be divisible by 12. */

int NivenNumber(unsigned int Num)
{
    unsigned int copy = Num;
    unsigned int sum = 0;
    while(copy != 0){
        sum += copy % 10;
        copy /= 10;
    }
    
    return (Num % sum == 0)? 0 : 1;
    //return 0;
   
}
/* The function returns integer value. It has two arguments one is 
integer array and other is arraysize (length of an array). 
In this case, the function will return the 3rd smallest number in given array.
Ex.

{98,4,33,54,6}, In this integer array 33 is the 3 rd smallest number. Hence function will return 33.*/


int Find3rdSmallestNumber(unsigned int arrVal[], unsigned int arrSize)
{
   unsigned int firstmin = 4294967295, secmin = 4294967295, thirdmin = 4294967295;
    for (int i = 0; i < arrSize; i++)
    {

        if (arrVal[i] < firstmin)
        {
            thirdmin = secmin;
            secmin = firstmin;
            firstmin = arrVal[i];
        }

        else if (arrVal[i] < secmin)
        {
            thirdmin = secmin;
            secmin = arrVal[i];
        }
 
        else if (arrVal[i] < thirdmin)
            thirdmin = arrVal[i];
    }

    
    return thirdmin;
    
}

/* 

The function returns integer value. It has two arguments, the start number and
the end number of a region and should calculate the count of all numbers except number
with a 5 in it. The start number will always be smaller than the end number. 

Ex.
input :(1,10)
output: 9 -> (1,2,3,4,6,7,8,9,10) it count of all numbers except number
with a 5.


*/


int countNumbersExceptFive(int start, int end)
{
    int i, count = 0;
    int temp , digit , flag;
    for(i = start; i <= end; i++){
        temp = i;
        flag = 0;
        while(temp != 0){
            digit = temp % 10;
            if(digit == 5){
                flag = 1;
                break;
            }
            else
                temp /= 10;
        }
        if(!flag)
            count ++;
        
    }

    return count;

}

/* 

The function returns integer value. It has two arguments one is 
integer array and other is length(length of an array or Size of array). 
In this case, the function will return the sum of two highest positive numbers 
in given array. No floats or non- positive numbers will be passed

Ex.
When array is passed like 
{8,4,3,5,6},  the output should be 14 
(the sum of two highest positive numbers in given arrays are 6 and 8 hence 6+8 =14).

*/


long sumOfTwoLargestNumbers(int length , const int numbers[])

{
    int i , sum = 0 , largest1 = 0, largest2 = 0, temp = 0;
    
    for(i=0; i < length; i++)
    {
        if(numbers[i] >= 0){
            if(numbers[i] > largest1)
            {
                largest2 = largest1;
                largest1 = numbers[i];
            }
            else if(numbers[i] > largest2 && numbers[i] < largest1)
            {
                largest2 = numbers[i];
            }
        }
    }
    
    sum = largest1 + largest2;

    return sum;

}

