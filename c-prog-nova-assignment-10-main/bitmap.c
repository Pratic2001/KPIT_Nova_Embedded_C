#include <stdio.h>
#include "bitmap.h"


/* Determine whether the value is valid or invalid */

enum Validity ValidateRH(RelHumidity rh)
{
	// to be implemented..
	if(rh > 70 || rh < 45){
		return Invalid;
	}
	else
		return Valid;
}

/* Determine whether the value is valid or invalid */

enum Validity ValidateTemp(Temp t)
{
	 // to be implemented...
	 if(t > 50 || t < 0){
	 	return Invalid;
	 }
	 else
	 	return Valid;
}

/* Determine whether the value is valid or invalid */

enum Validity ValidateHourOfDay(HourOfDay hr)
{
	 // to be implemented...
	 if(hr > 23 || hr < 0)
	 	return Invalid;
	 else
	 	return Valid;
}

/* Determines the category of Relative Humidity based on Table 1 */

enum RHCategory GetRHCategory(RelHumidity rh)
{
 // to be implemented...
 	if(rh >= 45 && rh <= 50)
 		return Soothing;
 	else if(rh >= 51 && rh <= 60)
 		return Humid;
 	else if(rh >= 61 && rh <= 70)
 		return VeryHumid;
 	else
 		return InvalidRHCategory;

}

/* Determines the category of Temperature based on Table 2 */

enum TempCategory GetTempCategory(Temp t)
{
	 // to be implemented...
	if(t >= 0 && t <= 20)
 		return Cold;
 	else if(t >= 21 && t <= 30)
 		return Pleasant;
 	else if(t >= 31 && t <= 50)
 		return Hot;
 	else
 		return InvalidTempCategory;
}

/* Determines the category of Hour of day based on Table 3 */

enum HourOfDayCategory GetHourOfDayCategory(HourOfDay h)
{
	 // to be implemented...
	if(h >= 0 && h <= 10)
 		return Morning;
 	else if(h >= 11 && h <= 17)
 		return Afternoon;
 	else if(h >= 18 && h <= 23)
 		return Evening;
 	else
 		return InvalidHrCategory;
}

/* Determines the AC fan speed based on condition  in Table 4 */

enum ACFanSpeed GetACFanSpeed(RelHumidity rh, Temp t, HourOfDay hr)
{
	 // to be implemented...
	if(GetRHCategory(rh) == 0){
		if(GetTempCategory(t) == 0){
			if(GetHourOfDayCategory(hr) == 0){
				return Off;
			}
			else if(GetHourOfDayCategory(hr) == 1){
				return Normal;
			}
			else if(GetHourOfDayCategory(hr) == 2){
				return Off;
			}
			else{
				return InvalidInput;
			}
		}
		else if(GetTempCategory(t) == 1){
			if(GetHourOfDayCategory(hr) == 0){
				return Off;
			}
			else if(GetHourOfDayCategory(hr) == 1){
				return High;
			}
			else if(GetHourOfDayCategory(hr) == 2){
				return Normal;
			}
			else{
				return InvalidInput;
			}
		}
		else if(GetTempCategory(t) == 2){
			if(GetHourOfDayCategory(hr) == 0){
				return Normal;
			}
			else if(GetHourOfDayCategory(hr) == 1){
				return VeryHigh;
			}
			else if(GetHourOfDayCategory(hr) == 2){
				return Normal;
			}
			else{
				return InvalidInput;
			}
		}
		else
			return InvalidInput;
		
	}
	else if(GetRHCategory(rh) == 1){
		if(GetTempCategory(t) == 0){
			if(GetHourOfDayCategory(hr) == 0){
				return Normal;
			}
			else if(GetHourOfDayCategory(hr) == 1){
				return High;
			}
			else if(GetHourOfDayCategory(hr) == 2){
				return Normal;
			}
			else{
				return InvalidInput;
			}
		}
		else if(GetTempCategory(t) == 1){
			if(GetHourOfDayCategory(hr) == 0){
				return Normal;
			}
			else if(GetHourOfDayCategory(hr) == 1){
				return High;
			}
			else if(GetHourOfDayCategory(hr) == 2){
				return Off;
			}
			else{
				return InvalidInput;
			}
		}
		else if(GetTempCategory(t) == 2){
			if(GetHourOfDayCategory(hr) == 0){
				return High;
			}
			else if(GetHourOfDayCategory(hr) == 1){
				return VeryHigh;
			}
			else if(GetHourOfDayCategory(hr) == 2){
				return VeryHigh;
			}
			else{
				return InvalidInput;
			}
		}
		else
			return InvalidInput;
		
	}
	else if(GetRHCategory(rh) == 2){
		if(GetTempCategory(t) == 0){
			if(GetHourOfDayCategory(hr) == 0){
				return High;
			}
			else if(GetHourOfDayCategory(hr) == 1){
				return VeryHigh;
			}
			else if(GetHourOfDayCategory(hr) == 2){
				return VeryHigh;
			}
			else{
				return InvalidInput;
			}
		}
		else if(GetTempCategory(t) == 1){
			if(GetHourOfDayCategory(hr) == 0){
				return Normal;
			}
			else if(GetHourOfDayCategory(hr) == 1){
				return Normal;
			}
			else if(GetHourOfDayCategory(hr) == 2){
				return VeryHigh;
			}
			else{
				return InvalidInput;
			}
		}
		else if(GetTempCategory(t) == 2){
			if(GetHourOfDayCategory(hr) == 0){
				return High;
			}
			else if(GetHourOfDayCategory(hr) == 1){
				return VeryHigh;
			}
			else if(GetHourOfDayCategory(hr) == 2){
				return High;
			}
			else{
				return InvalidInput;
			}
		}
		else
			return InvalidInput;
		
	}
	else
		return InvalidInput;
	 
}

