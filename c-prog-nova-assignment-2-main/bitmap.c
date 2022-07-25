#include "bitmap.h"
/*  In this case The function has to remove all character in string except
    alphabets.Input consist of string assume that the character in the
    string can contain both uppercase, lowercase &symbols.
    Ex: 
    Input: 1@3joy
    Expected output: joy */

        char* rmvExpAlpha(char *str)
        {
            for (int i = 0, j; str[i] != '\0'; ++i) {
                while (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] == '\0')) {
                    for (j = i; str[j] != '\0'; ++j) {
                        str[j] = str[j + 1];
                    }
                    str[j] = '\0';
                }
            }
            return str;

        }

/* In this case, Input is string of lowercase character from ‘a – z’,
   the function will return the character of this string in sorted 
   alphabetical order as per below example. 
   Ex: 
   Input: “kpit”
   Expected output: ikpt..*/

        const char* sortStr(char *lowerCase)
        {       
                char chTemp;
                int i, j, len;
                len = strlen(lowerCase);
                for(i=0; i<len; i++)
                {
                    for(j=0; j<(len-1); j++)
                    {
                        if(lowerCase[j]>lowerCase[j+1])
                        {
                            chTemp = lowerCase[j];
                            lowerCase[j] = lowerCase[j+1];
                            lowerCase[j+1] = chTemp;
                        }
                    }
                }
                return lowerCase;
        
        }

/* In this case the function will return reverse digit of the unsigned number. 
   Ex: 
   Input: 103 
   Expected output:301. */


        unsigned int revDigit (unsigned int num)
        {
            int temp = 0;
            while(num != 0){
                temp =(10 * temp) + (num % 10);
                num /= 10;
            }
        return temp;

        }

/* In this case, the function will return equivalent binary value of unsigned number.
   Ex: 
   Input: 5
   Expected output:101*/


        unsigned int biValue(unsigned int num)
        {
            unsigned int bin = 0;
            unsigned int rem, i = 1;

            while (num !=0) {
                rem = num  % 2;
                num /= 2;
                bin += rem * i;
                i *= 10;
            }
            return bin;

        }

