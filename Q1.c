/* CS261- Assignment 1 - Q.1*/
/* Name: Reuben Youngblom
 * Date: January 21, 2019
 * Solution description: Generates random IDs and Scores for students. Also
 *  generates a summary report and deallocates memory.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};


struct student* allocate(){
    
    printf("Allocating memory...\n");
    
    /*Allocate memory for ten students*/
    struct student *studentPointer = malloc(10*(sizeof(struct student)));
    
    printf("Pointer Address: %p\n", studentPointer);
    
    /*Return the pointer*/
    return studentPointer;
}


void generate(struct student* students){
    
     /*Generate random and unique IDs and random scores for ten students, 
IDs being between 1 and 10, scores between 0 and 100*/
    printf("\n");
    printf("generating IDs and Scores...\n");
    
    
    /*generates some useful variables */
    
    int ID;
    int idArray [10];
    int score;
    
    
    /*seeds random function to be different each time*/
    
    srand(time(NULL));

    
    /*ID generator*/
    
    /*Loops through the array and fills it with an ID number, subject to conditions set out in inner loops*/
    
    for (int i=0; i < 10; i++) {
        
        /*using this as a loop switch. It's set to 0, and while loop will keep looping until this is != 0*/
        int idTest = 0;
        
        /*this loop keeps generating random numbers until it gets an unused one*/
        while (idTest == 0) {
            
            /*generates random ID number*/
            ID = rand() % 10 + 1;
            
            /*makes sure that idTest is 1. Loop will run if this is unchanged*/
            idTest = 1;
            
            /*loops through storage array to check for used ID numbers*/
            for (int j=0; j<10; j++) {
                
                /*if one is found to be used, change idTest back to 0 so the loop will keep running*/
                if (idArray[j] == ID) {
                    idTest = 0;
                }
                /*if no used int is the same as generated ID, idTest remains 1 and outer loop will stop generating numbers*/
            }
        }
        
        /*once there is a non-used ID number, add it to the array to check against*/
        idArray[i] = ID;
        
        /*and set the ID number to a student id*/
        students[i].id = ID;
        
        /* for checking printed output, making sure IDs are random and unique:
        printf("ID# is: %d \n", students[i].id);
         */
        
    }
    
    
    /*Scores Generator*/
    
    /*loops through array and adds random score to students.score*/
    for (int k=0; k<10; k++) {
        
    score = rand() % 100 + 1;
        
        /* for checking printed output:
         printf("Score: %d\n", score);
         */
        
        students[k].score=score;
    }
    
    
    /* for checking output visually; lists student IDs and scores:
    for (int n=0; n<10; n++) {
        printf("student %d ID: %d; score: %d\n", n+1, students[n].id, students[n].score);
    }
     */
}

void output(struct student* students){
    
    printf("\n");
    printf("Generating ID/scores list...\n");
    printf("\n");
    
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    
    for (int n=0; n<10; n++) {
        printf("ID: %d Score: %d\n", students[n].id, students[n].score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the 
ten students*/
    
    /*line space*/
    printf("\n");
    printf("Generating summary...\n");
    printf("\n");
    
    /*storage integers*/
    int high = 0;
    int low = 100;
    int test = 0;
    int average = 0;
    
    /*outer loop runs through the students arrays*/
    for (int i=0; i<10; i++) {
        
        /*test to see if current score is highest score*/
        test = students[i].score;
        if (high < test ) {
            /*if so, replace high*/
            high = test;
        }
        
        /*test to see if current score is lowest score*/
        if (low > test) {
            /*if so, replace low*/
            low = test;
        }
        
        /*gather averages*/
        average=(average + students[i].score);
    }
    
    /*average total equation*/
    int averageTotal = average/10;

    /*print out high, low, and averages*/
    printf ("High score: %d\n", high);
    printf ("Low score: %d\n", low);
    printf ("Average score: %d\n", averageTotal);
     
}

void deallocate(struct student* stud){
    /*Deallocate memory from stud*/
    printf("\n");
    printf("Deallocating memory...\n");
    printf("\n");

    /*check that stud is NOT NULL before freeing*/
    if(stud != NULL){
    free(stud);
    printf("Memory deallocation successful!\n");
    stud = NULL;
    }
}


int main(){
    struct student* stud = NULL;
    
    /*Call allocate*/
    stud = allocate();
    
    printf("Pointer: %p\n", stud);
    
    /*Call generate*/
    generate(stud);
    
    /*Call output*/
    output(stud);
    
    /*Call summary*/
    summary(stud);
    
    /*Call deallocate*/
    deallocate(stud);

    /*for readability*/
    printf("\n");
    return 0;
}

