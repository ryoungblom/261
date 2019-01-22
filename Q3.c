/* CS261- Assignment 1 - Q.3*/
/* Name: Reuben Youngblom
 * Date: January 21, 2019
 * Solution description: Takes in a string, and performs three main actions:  removes all non-character symbols and
 *  replaces them with a single underscore; converts to all lowercase; and then removes all underscores and
 *  converts the string to camelCase. There are other minor processing steps that happen, as well.
 */

#include <stdio.h>
#include <stdlib.h>


char toUpperCase(char ch){
  /*Convert ch to upper case, assuming it is in lower case currently*/
    
    /*if the letter is lower case:*/
    if (ch >= 'a' && ch <= 'z') {
        /*change is to upper case by changing the ASCII value*/
        ch = (ch - 32);
    }
    
    /*return upper case character*/
    return ch;

}


char toLowerCase(char ch){
  /*Convert ch to lower case, assuming it is in upper case currently*/
    
    /*if the letter is upper case:*/
    if (ch >= 'A' && ch <= 'Z') {
    /*change is to lower case by changing the ASCII value*/
    ch = (ch + 32);
    }
    
    /*return lower case character*/
    return ch;

}


int stringLength(char s[]) {
   /*Return the length of the string*/
    
    /*sets to get string length*/
    int strLength=0;
    
    /*runs through string...*/
    for (int i=0; s[i] != '\0'; i++) {
        /*and adds one to length int*/
        strLength++;
    }
    
    //printf("Length of string is: %d\n", strLength);
    return strLength;
}


void camelCase(char* word) {
    
    /*for converting to camelCase*/
    for (int i=0; word[i] != '\0'; i++) {
        if(!(word[i] >= 'a' && word[i] <= 'z')) {
            
            for (int j=i; word[j] != '\0'; j++){
            word[j] = word[j+1];
            }
            
            word[i] = toUpperCase(word[i]);
        }
    }
}


void processString(char * word){
    
    printf("\n");
    printf("Processing string... \n");
    
    /*variable to test if symbols are doubled up*/
    int underScore = 0;
    int firstLetter = 0;
    
    /*First function processes string*/
    /*Puts strings into "underscore" format*/
    
    /*loops through array*/
    for (int i=0; word[i] != '\0'; i++) {
        
        /*if it's a letter... basically just skip it*/
        if((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')){
            underScore=0;
            firstLetter = 1;
        }
        
        /*but if not, it must be an odd "break" character*/
        else {

            /*if it's a 'break' character...*/
            /*if no letters have been hit yet...*/
            if (firstLetter == 0) {
                for (int k=i; word[k] != '\0'; k++) {
                    word[k] = word[k+1];
                }
                i--;
            }
        
            /*but once firstLetter has been changed, if it's the first one in a row...*/
            else if (underScore == 0){
                /*just replace it with an underscore, and change underScore variable to catch if there are two in a row*/
               word[i]='_';
               underScore = 1;
            }
            
            /*if underScore == 1, this must be the second (or more) 'break' character in a row*/
            else if (underScore==1) {
                
                /*in this case, delete the extra break character in move everything else in the array down*/
                for (int j=i; word[j] != '\0'; j++) {
                    word[j] = word[j+1];
                }
                
                /*because I'm moving everything down in the array and deleting an element, i must stay the same on the next loop*/
                i--;
            }
        }
    }
    
    /*The string has been processed, except for possible break characters at the end.  This is to process those end characters*/
    
    /*this gets the length of the string, so I can work backwards and eliminate any trailing characters*/
    int strLength = stringLength(word);
    int cutEnd = 0;
    
    /*this runs through the loop backwards to cut off any ending characters*/
    for (int i=strLength; i > 0; i--) {
        
        /*if no letters have been found yet*/
        if (cutEnd == 0) {

            /*if the current last character is anything other than a letter...*/
            if (!((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z'))) {
                /*change it to a null termination*/
                word[i] = '\0';
            }
            
            /*otherwise, change value of cutEnd so no other characters are changed*/
            else {
                cutEnd = 1;
            }
        }
    }
    
    
    /*send string to toLowerCase() to be turned into lower case*/
    
    /*run through array, and send each char to toLowerCase() to check its case*/
    for (int i=0; word[i] != '\0'; i++) {
        /*if it's upper case, it will get returned as lower case*/
       word[i] = toLowerCase(word[i]);
    }


    /*string is now full processed, so print it*/
    printf("Processed string: ");
    
    /*run through string*/
    for (int i=0; word[i] != '\0'; i++) {
        /*and print the characters*/
        printf("%c", word[i]);
    }
    /*for readability*/
    printf("\n");
}



int main(){

	/*Read the string from the keyboard*/
    printf("Please enter your string of less than 50 characters:");
    int maxSize = 51;
    char * userInput = malloc(maxSize*sizeof(char));
    
    scanf("%[^\n]s",userInput);
    
    printf("Your input was: ");
    printf("%s\n", userInput);
    printf("\n");
    
    /*for visual reference in main
    for (int i =0; i<sizeof(userInput); i++) {
        printf("%c", userInput[i]);
    }
     */
    
	
    /*checks for valid input*/
    
    /*test variable*/
    int validTest = 0;
    
    /*loops through user input and runs tests*/
    for (int i=0; userInput[i] != '\0'; i++) {
        
        /*if there is a "first letter*/
        if((userInput[i] >= 'a' && userInput[i] <= 'z') || (userInput[i] >= 'A' && userInput[i] <= 'Z')){
            

            /*and then there is a 'break' of some kind (i.e. a non-letter character)*/
            for (int j=i; userInput[j] != '\0'; j++) {
            
                if (!((userInput[j] >= 'a' && userInput[j] <= 'z') || (userInput[j] >= 'A' && userInput[j] <= 'Z'))) {
                    
    
                    /*and then there is another letter...*/
                    for (int k=j; userInput[k] != '\0'; k++) {
                     
                        if((userInput[k] >= 'a' && userInput[k] <= 'z') || (userInput[k] >= 'A' && userInput[k] <= 'Z')){
                            /*then validTest = 1*/
                            validTest = 1;
                        }
                    }
                }
            }
        }
    }
    
    /*alerts user to invalid input*/
    if (validTest < 1) {
        printf("Invalid Input!\n");
    }
    

    /*but if it's valid...*/
    else {
        
    /*alert user and...*/
    printf("User Input is VALID!\n");
        
    /*process string*/
    processString(userInput);
        
    /*Call camelCase now that string has been processed*/
    camelCase(userInput);
    
    /*Print the new string*/
    printf("\n");
    printf("Your string is now: ");
    printf("%s\n", userInput);
    printf("\n");
        
    }
    
    free(userInput);
    
	/*for readability*/
    printf("\n");
	return 0;
}

