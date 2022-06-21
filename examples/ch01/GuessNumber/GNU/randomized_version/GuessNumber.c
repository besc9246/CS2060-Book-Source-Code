/*
* The program randomly generates numbers   
* between 1 and 1000 for the user to guess.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MIN_NUMBER 1
const int MAX_NUMBER = 100;

void guessGame(void); 
int isCorrect(int, int); 


int main(void)
{
   //srand(time(0));
   //guessGame();
    

    unsigned int aCount = 0;
    unsigned int bCount = 0;
    unsigned int cCount = 0;
    unsigned int dCount = 0;
    unsigned int fCount = 0;

    puts("Enter the letter grades." );
    puts("Enter the EOF character to end input." );
    int grade; // one grade

    // loop until user types end-of-file key sequence
    while ((grade = getchar()) != EOF) {
       
       // determine which grade was input
       switch (grade) { // switch nested in while

          case 'A': // grade was uppercase A
          case 'a': // or lowercase a
             ++aCount;
             break; // necessary to exit switch

          case 'B': // grade was uppercase B
          case 'b': // or lowercase b
             ++bCount;
             break;

          case 'C': // grade was uppercase C
          case 'c': // or lowercase c
             ++cCount;
             break;

          case 'D': // grade was uppercase D
          case 'd': // or lowercase d
             ++dCount;
             break;

          case 'F': // grade was uppercase F
          case 'f': // or lowercase f
             ++fCount;
             break;

          case '\n': // ignore newlines,
          case '\t': // tabs,
          case ' ': // and spaces in input
             break;

          default: // catch all other characters
             printf("%s", "Incorrect letter grade entered.");
             puts(" Enter a new grade.");
             break; // optional; will exit switch anyway
       }
    } // end while

    // output summary of results
    puts("\nTotals for each letter grade are:");
    printf("A: %u\n", aCount);
    printf("B: %u\n", bCount);
    printf("C: %u\n", cCount);
    printf("D: %u\n", dCount);
    printf("F: %u\n", fCount);
    
    
   return 0;
} // end main


void guessGame(void)
{
   int answer = 0; 
   int guess = 0; 
   int response = 0; 

   do {
      answer = MIN_NUMBER + rand() % MAX_NUMBER;
      
      printf("Hello there, I have a number between %d and %d .\n" 
          "Can you guess my number?\n"
           "Please type your first guess.", MIN_NUMBER, MAX_NUMBER);

      printf("%s", "? ");
      scanf("%d", &guess);

      while (!isCorrect(guess, answer)) 
         scanf("%d", &guess);

      puts("\nExcellent! You guessed the number!\n"
         "Would you like to play again?");
      printf("%s", "Please type ( 1=yes, 2=no )? ");
      scanf("%d", &response);

      puts("");
   } while (response == 1);
} 


int isCorrect(int g, int a)
{
    if (g == a){
        return 1;
    }

   if (g < a)
      printf( "%s", "Too low. Try again.\n? " );
   else
      printf( "%s", "Too high. Try again.\n? " );

   return 0;
} 



/**************************************************************************
 * (C) Copyright 1992-2012 by Deitel & Associates, Inc. and               *
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
 **************************************************************************/
