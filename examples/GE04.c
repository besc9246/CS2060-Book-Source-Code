/*
********************************************************

ch07sec7_4CubePassRef.c
 
 Ben Schwartz
 Deborah Harding
 CS 2060
 7/3/22
 Guided Exploration 04
 Due: July 4

********************************************************
 */


////
////  GE04.c
////  BookExample
////
////  Created by Benjamin Schwartz on 7/3/22.
////
//
//// Passing Primitive Data Types and pointers
////Add comments to explain the code
//



//#include <stdio.h>
//#include <stdlib.h>
//
//int cubePass1(int number);
//int cubePass2(int * numberPtr);
//
//int main(void) {
//
//    int numberMain = 5;
//    int result = 0;
//
//    printf ("In main before cubePass1  numberMain = %d\n", numberMain);
//    printf("&numberMain = %p\n", &numberMain);
//    result = cubePass1(numberMain);
//    printf ("In main after cubePass1  numberMain = %d\n", numberMain);
//    printf ("Result = %d\n", result);
//    printf("\nIn main before cubePass2  numberMain = %d\n", numberMain);
//    result = cubePass2(&numberMain);
//    printf("\nIn main after cubePass2  numberMain = %d\n", numberMain);
//    printf("result = %d\n", result);
//
//} // main
//
//
//int cubePass1 (int number)
//{
//    int cube = 0;
//    puts("\nIn cubePass1");
//    printf("number = %d\n", number);
//    printf("&number = %p\n", &number);
//    cube = number * number * number;
//    printf("cube  = %d\n", cube);
//    number = cube;
//    printf("number = %d\n", number);
//    return cube;
//}
//
//int cubePass2 (int * numberPtr)
//{
//    int cube = 0;
//    puts ("\nIn cubePass2");
//    printf("numberPtr = %p\n", numberPtr);
//    printf ("*numberPtr = %d\n", *numberPtr);
//    printf("&numberPtr = %p\n", &numberPtr);
//    cube = (* numberPtr )* (* numberPtr )* (* numberPtr);
//    *numberPtr = cube;
//    printf ("*numberPtr = %d\n", *numberPtr);
//    return cube;
//}







/*******************
 Understanding pointers
 Add comments to explain the code
 
ch07pointerExploration1.c
**************/

#include <stdio.h>


int main (void)
{

    
    /*
     ********************************************************
    Commented out the 5 lines directly below...
    // Initalize A
     int A = 13;
     int calcA1 = 0;
     int calcA2 = 0;
     int *aPtr = &A;

     ...And added these 5 lines directly below.
     No code was changed other than simplifying the names of the variables.
     */
    int A = 13;
    int calcA1 = 0;
    int calcA2 = 0;
    int *APtr = &A;
    //********************************************************

   
    //Notice that A and *APtr are the same value when printed as an integer.
    printf("A = %d\n", A);

    //APtr and &A indeed print the same address, so these two are equal.
    printf("&A = %p\n\n", &A);

    printf ("*APtr = %d\n", *APtr);
    
    //APtr and &APtr do not print the same address, so these two are not equal.
    //Remember that APtr is a pointer and was initialized to &A
    printf ("APtr = %p\n\n", APtr);

    printf ("&APtr = %p\n\n", &APtr);

    //We would still expect *APtr = 13 so its not surprising that *APtr + *APtr = 26
    calcA1 =  *APtr + *APtr;

    printf("*APtr + *APtr = %d\n\n", calcA1);

    calcA2 = 2 * (*APtr);

    //Neither is it surprising that 2 * (*APtr) =  26
    printf("2 * (*APtr) = %d\n\n", calcA2);

    //What I don't fully understand is this line below. Why is it that &*APtr = *&APtr?
    printf("\n&*APtr = %p"
        "\n*&APtr = %p\n\n", &*APtr, *&APtr);

    return 0;
}








