/* CS261- Assignment 1 - Q.2*/
/* Name:
 * Date:
 * Solution description:
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c){
    
    /*printed confirmations of address swap
    printf("address of a is: %p\n", a);
    printf("address of b is: %p\n", b);
     */
    
    /*Swap the addresses stored in the pointer variables a and b*/
    /*move a to storage, b to a, and storage (a), to b*/
    printf("Swapping addresses...\n");
    int *storage = a;
    a = b;
    b=storage;
    
    /*printed confirmations of address swap
    printf("address of a is now: %p\n", a);
    printf("address of b is now: %p\n", b);
     */
    
    /*Decrement the value of integer variable c*/
    c--;
    
    /*Return c*/
    return c;
}


int main(){
    
    /*random seed*/
    srand(time(NULL));
    
    /*Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    int x = rand() % 10 + 1;
    int y = rand() % 10 + 1;
    int z = rand() % 10 + 1;
    
    /*Print the values of x, y and z*/
    printf("x is: %d\n", x);
    printf("y is: %d\n", y);
    printf("z is: %d\n", z);

    /*Call foo() appropriately, passing x,y,z as parameters*/
    int printC = foo(&x, &y, z);
    
    /*Print the values of x, y and z*/
    printf("x is now: %d\n", x);
    printf("y is now: %d\n", y);
    printf("z is now: %d\n", z);
    
    /*Print the value returned by foo*/
    printf("The value returned by foo() is: %d\n", printC);
    
    /* Answer a: The return value of foo() is different than z in that is is decremented by 1. The reasons for this lie in the return function.
     If I had just passed in the variable z, and decremented it, z would be unchanged in main() (which is exactly what happened). But what's
     happening here is going beyond a simple variable pass/change. By passing in z, changing it, and then RETURNING the new value of z,
     the return value of the function is equal to the new value of z (in this case, z-1). While z may be unchanged, the return value of
     the function is still the decremented value of z, and since we're printing the function's return value, it's different than z. */
    
    /* Answer b: The values of x and y are exactly the same before and after calling foo().  What's happening here relies on the fact that
     pointers are simply variables that hold addresses, as opposed to, say, a variable that holds an int. We can almost think of variables
     as made up of two distinct components: values, and addresses. When we pass an int variable to a function, any changes we make to the
     value of that variable won't be a local change, meaning that if we pass a 7, and make all kinds of changes inside the function, it
     will still be a 7 outside of the function. In order to make a permanent, global change, we'd have to pass the ADDRESS (in the form
     of a pointer). If we're changing the value of the address (rather than the abstracted variable), we can make a global change.
     
     Pointers work in the same way, except rather than being comprised of an int and an address, they're comprised of the address of
     another variable (analogous to the number value of an int), and their own address.  Here, we passed two pointers, and changed
     the address that they were pointing to. This is simply changing their "value" and has the same effect as if we has changed the
     value of an int without accessing its address--that is, the change is purely local. If, however, we were to access the ADDRESS of
     those pointers, we could have swapped them and it would have been a global change.  But as it stands, since we passed pure pointer
     variables and then simply changed the addresses they were pointing TO, it's a local change (just like changing the number value of
     a passed int variable) and doesn't persist outside of the function. */
    
    
    return 0;
}
    
    


