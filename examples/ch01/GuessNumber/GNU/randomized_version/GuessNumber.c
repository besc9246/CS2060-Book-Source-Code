/*
* The program randomly generates numbers   
* between 1 and 1000 for the user to guess.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>>


#define MIN_NUMBER 1
const int MAX_NUMBER = 1000;

void guessGame(void); 
int isCorrect(int, int); 


/*
 int main(void)
{
   srand(time(0));
   guessGame();
    
   return 0;
} // end main
 
 */


// function main begins program execution
int main( void )
{
    // Initialize constants
    const int stdnt_cnt = 10;
    const int pass = 1;
    const int bonus_stdnt_num = 8;
    const int min = 1;
    const int max = 2;
    
    // Initialize validation vars
    //double numEntered = 0;
    unsigned int scanfRtrn = -1;
    
    
   // initialize variables in definitions
   unsigned int passes = 0; // number of passes
   unsigned int failures = 0; // number of failures
   unsigned int student = 1; // student counter
   int result = 0; // one exam result

    /*
   // process 10 students using counter-controlled loop
   while ( student <= 10 ) {
   */
    
    // Create boolean flag for loop
    bool numValid = false;
    
    // process stdnt_cnt students using counter-controlled loop
   //while (student <= stdnt_cnt) {
   do {

      // prompt user for input and obtain value from user
      //printf( "%s", "Enter result ( 1=pass,2=fail ): " );
       puts("Enter result ( 1 = pass, 2 = fail ): ");
      
       //scanf( "%d", &result );
       scanfRtrn = scanf( "%d", &result);
       
       // Clear buffer
       while (getchar() != '\n');

           
           if(scanfRtrn != 1 || result < min || result > max ) {
               printf("Invalid input. Please enter a value between %d and %d.\n", min, max);
           }
           else {
               // if result 1, increment passes
               //if ( result == 1 ) {
               if (result == pass) {
                   passes = passes + 1;
              } // end if
              else { // otherwise, increment failures
                 failures = failures + 1;
              } // end else

              student = student + 1; // increment student counter
               
               if (student > stdnt_cnt) {
               numValid = true;
               }
           }
           
       
   } while (!numValid && student <= stdnt_cnt);

       // termination phase; display number of passes and failures
       printf( "Passed %u\n", passes );
       printf( "Failed %u\n", failures );

       
        // if more than bonus_stdnt_num students passed, print "Bonus to instructor!"
       //if (passes > 8 ) {
       if (passes > bonus_stdnt_num ) {
          puts( "Bonus to instructor!" );
           
           
       } // end if
       
} // end function main


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
