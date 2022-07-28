
#include"bitmap.h"

//Complete other records in this array...

struct cabDatabase vechArr[100] = { 
                                     {"electroniccity","mini",5,"azar",20},
                                     {"electroniccity", "mini", 4, "arun", 25},
                                     {"electroniccity", "macro", 4, "birbal", 25},
{"electroniccity", "macro", 5, "billu", 30},
{"electroniccity", "suv", 5, "mani", 30},
{"electroniccity", "suv", 3, "jai", 35},
{"silkboard", "mini", 5, "ranjith", 20},
{"silkboard", "mini", 3, "riyaz", 25},
{"silkboard", "macro", 5, "vasanth", 25},
{"silkboard", "macro", 3, "durgesh", 30},
{"silkboard", "suv", 5, "ragu", 30},
{"silkboard", "suv", 3, "raman", 35},
{"ecoworld", "mini", 5, "sam", 20},
{"ecoworld", "mini", 3, "dheena", 25},
{"ecoworld", "macro", 5, "dixon", 25},
{"ecoworld", "macro", 3, "nixon", 30},
{"ecoworld", "suv", 4, "sridhar", 30},
{"ecoworld", "suv", 5, "joseph", 35},
{"madiwala", "mini", 5, "chira", 20},
{"madiwala", "mini", 3, "laxshman", 25},
{"madiwala", "macro", 5, "dravid", 25},
{"madiwala", "macro", 3, "tanu", 30},
{"madiwala", "suv", 5, "maxi", 30},
{"madiwala", "suv", 3, "john", 35},
{"majestic", "mini", 5, "ravi", 20},
{"majestic", "mini", 3, "ram", 25},
{"majestic", "macro", 5, "somesh", 25},
{"majestic", "macro", 3, "navin", 30},
{"majestic", "suv", 5, "raj", 30},
{"majestic", "suv", 3, "boss", 35}
                                     //complete other records here...

                                  };

struct location locArr[05] = {

                                 {"electroniccity",12.8452, 77.6602},
                                 {"silkboard", 12.9177, 77.6238},
                                 {"ecoworld", 12.9213, 77.6844},
                                 {"madiwala", 12.9226, 77.6174},
                                 {"majestic", 12.9767, 77.5713}

                                 //complete other records here...

                             };

/* The function has two arguments, like source and destination. 
The function helps to find the distance between two points and 
return the result(distance (km)) in integer format.

Hint:
Use “Haversine formula” to calculate the distance between two points. */


int sourDesti(const char *source, const char *desti)
{ 
   float lat1, lon1, lat2, lon2;
   
   for(int i = 0; i < 5; i++){
        if(!strcmp(source , locArr[i].locationName)){
            lat1 = locArr[i].lati;
            lon1 = locArr[i].longi;
        }
        
        if(!strcmp(desti , locArr[i].locationName)){
            lat2 = locArr[i].lati;
            lon2 = locArr[i].longi;
        }
   }
   
   float dLat = (lat2 - lat1) * PI / 180.0;
   float dLon = (lon2 - lon1) * PI / 180.0;
 
        // convert to radians
   lat1 = (lat1) * PI / 180.0;
   lat2 = (lat2) * PI / 180.0;
 
        // apply formulae
   float a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
   float rad = 6371;
   float c = 2 * asin(sqrt(a));
   
   return ceilf(rad * c);
   
}

/*  
 The function has three arguments source, destination, and VechType
 The function help to find the fare(price). To get fare , first find the 
 distance (KM) by using first two arguments (source and destination)
 and then find the fare by using third arguments. Refer below hint for different cab charges.

Hint:
•	Fare for mini cab – 5RS/km
•	Fare for macro cab – 10RS/km
•	Fare for SUV cab – 15RS/km          */


int maxFare(const char *source,const char *desti,const char *vehi)
{
    int distance = sourDesti(source , desti);
    
    char type1[06] = "mini" , type2[06] = "macro" , type3[06] = "suv";
    char conv_vehi[06];
    
    for(int i = 0; i < strlen(vehi); i++){
        if(vehi[i] >= 'A' && vehi[i] <= 'Z')
            conv_vehi[i] = vehi[i] + 32;
        else
            conv_vehi[i] = vehi[i];
    }
      
    if(!strcmp(type1 , conv_vehi)){
        return distance * 5;
    }
    
    if(!strcmp(type2 , conv_vehi)){
        return distance * 10;
    }
        
    if(!strcmp(type3 , conv_vehi)){
        return distance * 15;
    }
    
    else
        return distance;

}

/* The function has two arguments, like source and vehicle type. 
The function helps to find best driver in the given cabDatabase records.
the candidate must navigate through record return the best driver. 
(Return the result in string format). */

const char* goodDriver(const char *source, const char *vehi)
{
    unsigned int temp = vechArr[0].rating;
    
    for(int i = 0; i < 100; i++){
        if(!strcmp(vechArr[i].startPoint , source) && !strcmp(vechArr[i].vechType , vehi)){
            if(temp < vechArr[i].rating)
                temp = vechArr[i].rating;
        }
    }
    
    for(int i = 0; i < 100; i++){
        if(!strcmp(vechArr[i].startPoint , source) && !strcmp(vechArr[i].vechType , vehi) && (vechArr[i].rating == temp))
            return vechArr[i].driverNam;
        
    }

// to be implemented
    return 0;

}

/* The function has three arguments, like source, 
destination, and driver name. The function helps to
find maximum time to reach destination (Return the result in integer format).

Hint:
To solve, use time formula. 
Refer cabDatabase (structure name) for speed value. */


int times(const char *source, const char *desti,const char *name)
{
    float distance = sourDesti(source , desti);
    float max_time;
    
    for(int i = 0; i < 100; i++){
        if(!strcmp(vechArr[i].startPoint , source) && !strcmp(vechArr[i].driverNam , name)){
            max_time = (distance / ((float)(vechArr[i].speed) / 60.0));
        }
    }

    return ceilf(max_time);

}


