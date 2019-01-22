/* CS261- Assignment 1 - Q. 0*/
/* Name: Reuben Youngblom
 * Date: Jan. 21, 2019
 * Solution description: generates random values, then passes the pointers into
 *  various functions to show local vs. global changes, and how pointers
 *  are affected differently than variables.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fooA(int* iptr){
    
    printf("\n");
    printf("We are now in fooA()!\n");
    
    /*Print the value and address of the integer pointed to by iptr*/
    printf("The value in the address that iptr points to is: %d\n", *iptr);
    printf("The address that iptr points to is: %p\n", iptr);
  
     /*Increment the value of the integer pointed to by iptr by 5*/
    printf("Now incrementing iptr by 5...\n");
    *iptr = *iptr + 5;
    printf("The value of iptr is now: %d\n", *iptr);
    
     /*Print the address of iptr itself*/
    
    printf("The address of iptr itself is: %p\n", &iptr);
}


void fooB(int* jptr){
  
    printf("\n");
    printf("We are now in fooB()!\n");
    
    /*Print the value and address of the integer pointed to by jptr*/
    
    printf("The value in the address that jptr points to is: %d\n", *jptr);
    printf("The address that jptr points to is: %p\n", jptr);
    
    
     /*Decrement the address by 1 pointed to by jptr using jptr */
    
    printf("Decrementing the address pointed to by jptr gives you: %p\n", jptr-1);
    
    
     /*Print the address of jptr itself*/
    printf("The address of jptr itself is: %p\n", &jptr);
}


int main(){
    
    /*Declare an integer x and initialize it randomly to a value in [0,10]*/
    
    srand(time(NULL));
    
    int x = rand() % 10 + 1;
    
    /*Print the value and address of x*/
    
    printf("int x generated! The value is: ");
    
    printf("%d\n", x);
    
    printf ("and the address is: ");
    
    printf("%p\n", &x);
    
    
    /*Call fooA() with the address of x*/

    fooA(&x);

    
    /*Print the value of x*/
    
    printf("\n");
    printf("Back in Main, the value of x is : %d\n", x);
    
    /* ANSWER:  The value of X has been changed/increased despite the incrementation taking place inside of a function because
     a pointer was passed to the function.  If the variable x had been passed, it only would have incremented within fooA(), but
     a pointer actually access the address where the value is stored.  Therefore, when a pointer (or, more accurately, the
     variable stored at an address that a pointer points to) is accessed, it actually changed the value globally. When the pointer
     to x was incremented inside fooA(), it actually changed the integer that was stored at the address of x. */
    
    /*Call fooB() with the address of x*/
    
    fooB(&x);
    
    /*Print the value and address of x*/
    
    printf("\n");
    printf("Back in Main, the address of x is : %p\n", &x);
    
    /* ANSWER: The address of x is the same as it was before the call to fooB().  This is, again, due to the nature of pointers. When
     sending in the address of x, you're sending a pointer to an address, which is really just a variable that holds an address
     value.  As we can see from fooA(), this variable even has its own address. So by changing the "value" of the pointer  variable
     inside a function, it's just like changing the value of any other variable inside a function—it's a local change that does not
     persist outside of the function. Therefore, when we're back in Main, the address, despite being decremented inside of a
     function, is restored back to its original value (which, in this case, is the original address). */
    
 
    printf("\n");
    return 0;
}


