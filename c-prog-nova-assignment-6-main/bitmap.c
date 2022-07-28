#include "bitmap.h"
//Complete other records in this array...
VehD VD1[MAX_SIZE] = {
			{"KonaElectric", 7548, 42, 996, 920400},
            {"JaguarIPace", 8990, 70, 470, 5070000},
            {"StromMotorsR3", 4572, 12, 200, 701600},
            {"MerBenzEQC", 9098, 21, 120, 4798000},
            {"MG_ZS_EV", 9011, 42, 403, 3987111},
            {"E_Verito", 8006, 21, 140, 2055000},
            {"TigorEV", 7676, 21, 213, 1634000},
            {"NexonEV", 7155, 28, 220, 1533555}//0
			//complete other records here...	 		

	};

//Pointer creation and pointing to the array...
VehD *ptr = VD1;

/*The function returns the Price of EV with the Highest 
Value in the given records.
In case there are 2 or more vehicles with the same 
highest price, return the first EV record found.*/
unsigned long HighestPrice(const VehD *parr, int length)
{
    unsigned long temp = parr[0].Price;
    for (int i = 0; i < length; ++i) {
        if (temp < parr[i].Price) {
            temp = parr[i].Price;
        }
    }


	return temp;
}

/*
The function returns the lowest/least distance covered 
in the given EV records.  
The candidate must navigate through the records and 
return the lowest no. of DistanceCovered.
In case there are 2 or more vehicles with the same distance 
covered, return the first EV record found.
*/
unsigned int VehWithLeastDistanceCovered(const VehD *parr, int length)
{
    unsigned int temp = parr[0].DistanceCovered;
    for (int i = 0; i < length; ++i) {
        if (temp > parr[i].DistanceCovered) {
            temp = parr[i].DistanceCovered;
        }
    }
	
	return temp;
}

/*
The function returns the total number of vehicles with specific 
BatteryPack value from the given records. Specific BatteryPack 
Value to be identifed as per the third argument passed to the 
function. If argument value is not found in the records under 
BatteryPack, return 0 from function.
Else, return the number of vehicles with the given argument 
BatteryPack value from the function.
*/
unsigned int NoOfVehWithSpecificBatteryPack(const VehD *parr, int length, unsigned int VehBattPack)
{
    unsigned int count = 0;
    for(int i = 0; i < length; i++){
        if(parr[i].BatteryPack == VehBattPack)
            count++;
    }


	return count;
}

/*
The function must calculate the average VehicleMass 
from provided record entries and return the average value 
(unsigned integer) from the function. 
In case records are absent, return 0 from the function.
*/
unsigned int AverageVehicleMass (const VehD *parr, int length)
{
    unsigned int avg = 0;
    for(int i = 0; i < length; i++){
        avg += parr[i].VehicleMass;
    }
    
    avg /= length; 
	
	return avg;
}

/*
This function is used to display all Vehicle Data Records. 
Call the function displayOneEntry() in this function.
*/
void displayEntries(const VehD *ptr,int len)
{
   for(int i = 0; i < len; i++){
        displayOneEntry(ptr + i);
   }
	
}

/*
This function used for displaying a single record at a time. 
This function should be called inside displayEntries function.
*/
void displayOneEntry(const VehD *ptr)
{
    printf("\nMass: %u , Name: %s , BatteryPack: %u , Price: %lu , DistanceCovered: %u", ptr -> VehicleMass, ptr -> ModelName, ptr -> BatteryPack, ptr -> Price, ptr -> DistanceCovered);

	
}






