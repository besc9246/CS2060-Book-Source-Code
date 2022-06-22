// Fig. 2.1: fig02_01.c
// A first program in C 
#include <stdio.h>
#include <stdbool.h>

// function main begins program execution 
int main( void )
{
    const int goodScanfRtrtn = 1;
    
    //Create boolean flag for loop
    bool cntnueLoop = true;

    unsigned int length = 0;
    unsigned int width = 0;
    unsigned int area = 0;
    unsigned int scanfRtrn = -1;
    
    puts("Enter the length.");
    
    //Read the length into the variable length.
    scanfRtrn = scanf("%u", &length);
    
    //Clear buffer
    while (getchar() != '\n');
    
    while (cntnueLoop) {
    
        if (scanfRtrn != goodScanfRtrtn) {
            puts("Error using scanf for length.");
            cntnueLoop = true;
        }
        
        puts("Enter the width.");
        
        //Read the width into the variable width.
        scanfRtrn = scanf("%u", &width);
            
        //Clear buffer
        while (getchar() != '\n');
        
        if (scanfRtrn != goodScanfRtrtn) {
            puts("Error using scanf for width.");
            cntnueLoop = false;
        }
        
        //Calculate the area and assign it to the area variable.
        area = length * width;
        
        cntnueLoop = false;
    }
    //Print out the information
    printf("Length = %u, Width = %u, and Area = %u.\n", length, width, area);
    
    //printf( "Welcome to C!\n" );
} // end function main 


/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
