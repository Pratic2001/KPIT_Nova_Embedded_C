#include "bitmap.h"

//Complete other records in this array...

LoanApp LD1[MAX_SIZE] = {
{28,70000,2500000,6.8},
{35, 80000, 3500000, 7.3},
{43, 120000, 4200000, 7.4},
{38, 145000, 5500000, 7.2},
{27, 110000, 5000000, 6.75}
//complete other records here...
};

//Pointer creation and pointing to the array...
LoanApp *ptr = LD1;


/*

The function must calculate and return the average loan amount in the given record(record name: LoanApp)

*/


float AverageLoanAmount(const LoanApp *ptr, int length)
{
	int i ;
	float sum = 0;
	for(i = 0; i < length; i++){
		sum += ptr[i].LoanAmount; 	
	}
	sum /= length;
return sum;

}

/*
The function returns minimum age Value in the given records.

*/

unsigned int MinimumAge(const LoanApp *ptr, int length)
{
	unsigned int i, smallest;
	smallest = ptr[0].PersonAge;
 
   for (i = 0; i < length; i++) {
      if (ptr[i].PersonAge < smallest) {
         smallest = ptr[i].PersonAge;
      }
   }
return smallest;

}

/*
The functions returns the person income for the  highest loan amount in the given record.

*/


unsigned long IncomeForHighestAmount(const LoanApp *ptr, int length)
{
	unsigned long highest , temp;
	temp = ptr[0].LoanAmount;
	for (int i = 0; i < length; ++i) {
    		if (temp < ptr[i].LoanAmount) {
     			temp = ptr[i].LoanAmount;
    		}
  	}
  	
  	for (int i = 0; i < length; ++i){
  		if(ptr[i].LoanAmount == temp)
  			return ptr[i].PersonIncome;
  	}
return 0;
}

/* This method counts and returns the count value of the interest 
rate which is greater than or equal 7.0 percent in the given record. */

unsigned int HighInterestCount(const LoanApp *ptr, int length)
{
	unsigned int count = 0;
	
	for(int i = 0; i < length; i++){
		if(ptr[i].LoanInterestRate >= 7.0){
			count ++;
		}
	}
return count;

}
