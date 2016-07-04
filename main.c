/* Dennis Raykhel 
 * July 4, 2016
*This program will take simple words and encrypt them such that they form 10
 digit long numbers which can be decrypted, if the user knows that the first 4 digits hold the value of the character they need,
 and if they know the multiplying and adding value associated with that character.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 20
/*
 * 
 */
int main(int argc, char** argv) {
                                /* Declarations*/
    int counter = 0, counter2 = 0, value = (rand() % 8)+ 1, edit = 0;
    int converted [MAX_LEN];
    int primes [MAX_LEN]={53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149};
    int multiply [MAX_LEN]={49, 29, 37, 19, 24, 47, 21, 23, 7, 2, 48, 31, 13, 43, 41, 5, 44, 36, 26, 22};
    char text [MAX_LEN];
    
      
    fscanf(stdin, "%s", text); /*Calling for user to input a word*/ 
    for(counter = 0; counter < MAX_LEN; counter++){
        for(counter2 = 0; counter2 < 5; counter2 ++){ /*This creates a "buffer" in front of the encrypted number, to disguise the valuesand make solving difficult as regular mathematics would not be able to determine the value*/
            value += rand() % 10;   
            value *= 10;
        }
        value *= 1000;          /*leaving 4 digits of space for the character value */
        if(text[counter] != NULL){        /* the last step to encrypting the character*/
            edit = toupper(text[counter]); /* converting to uppercase for simplicity*/
            edit += primes[counter];       /* using a prime number to hide the ascII value */
            edit *= multiply[counter];     /* using random numbers and multiplying them to blur the numbers */
            /* The reason why this uses different numbers to add and multiply is to further cover up the letters and to prevent
             the same letters from having the same values which make the encryption easier to crack */
            value += edit;                 /* adds the new character value into the encrypted number*/
            printf("%d \n", value);
        }
        else{ 
            counter=20; /*Ends loop since the string has been read*/
        }
        value=0;
    }
    return (EXIT_SUCCESS);
}

