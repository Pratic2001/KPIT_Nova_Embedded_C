#include"bitmap.h"



/*        The function returns length of given string.
 Student is expected to design without using string length function strlen(). */

                int arrLength(const char* str)
                {
                   int i;
                   int len = 0;
                   for(i = 0; str[i] != '\0' ; i++)
                       len += 1;
                   return len;
                }

/*The function returns 1 or 0.  
Input is string of lowercase character from ‘a – z’ 
the function will check repeated character in a given string, 
if it’s found, then return 1 or else 0.*/


                int repCharaCheck(const char* str1)
                {
                    int count;
                    for(int i = 0; i < arrLength(str1); i++) {  
                        count = 1;  
                    for(int j = i+1; j < arrLength(str1); j++) {  
                        if(str1[i] == str1[j] && str1[i] != ' ') {  
                            count++;  
                        }  
                    }
                    
                    if(count > 1 && str1[i] != '0')  
                        return 1;  
                    }  
                
                        return 0; 
                }


/*The function returns 1 or 0. It has two arguments one is string 
and other one is an index position. In this case, the function will 
identify whether value at index position is a character or a Number.
If the value at index position is numbered it returns 1else it return 0
*/

                int checkAnyIndex(const char* str, int indexPosition)
                {
                        if(str[indexPosition] == '0' || str[indexPosition] == '1' || str[indexPosition] == '2' || str[indexPosition] == '3' || str[indexPosition] == '4' || str[indexPosition] == '5' || str[indexPosition] == '6' || str[indexPosition] == '7' || str[indexPosition] == '8' || str[indexPosition] == '9')
                
                            return 1;
                        
                        return 0;
                }
/*The function returns middle character in given string.
Case 1: odd
If the length of the string is odd, it’s easy to identify the middle character in given string.

Case2: Even.
If the length of the string is even, then there would be two middle character we need compare 
those two middle character and the greater one has to print.
Ex: Input string is “abcd” here ‘b’ and ‘ c’are the middle character so we need compare 
‘b’ element and ‘c’ which is greater that has to print. In above example c is greater, then output will be ‘c’
*/

                char checkMidChara(const char* str)
                {
                   int length = arrLength(str);
                   if(length % 2){
                       char first = str[length / 2];
                       char second = str[(length / 2) + 1];
                       if(first > second)
                        return first;
                       else
                           return second;
                   }
                   else{
                        
                        return str[length / 2];;
                   }
                }
