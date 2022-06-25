//
//  CS 2060 HW #2.c
//  CS 2060
//
//  Created by Benjamin Schwartz on 6/22/22.
//

#include "CS 2060 HW #2.h"
#include <stdbool.h>

int main(void) {
    
    //Initialize vars
    double charge = 2.0;
    double chargeSum = 0.0;
    double numHours = 0.0;
    double totalHours = 0.0;
    double hrsCntr = 3.0;
    bool stopLoop = false;
    int scanfRtrn = -1;
    short carCnt = 0;
    
    //Constants
    const short sentinelVal = -1;
    const double maxHrsDaily = 18.0;
    const short scanfOkRtrnVal = 1;
    const double min = 0.0;
    const double max = 24.0;

    while (!stopLoop) {
        
        puts("Enter the number of hours the car was parked or enter -1 to quit.\n");
        
        //Get user input
        scanfRtrn = scanf("%lf", &numHours);
        
        //Clear buffer
        while (getchar() != '\n');
        
        if (scanfRtrn != scanfOkRtrnVal) {
            puts("\nPlease enter a single number. No characters other than numbers and a decimal point are allowed.\n");
        }
        
        else {
                    
            if (numHours != sentinelVal) {
            
                if (scanfRtrn == scanfOkRtrnVal) {
                
                    if (numHours < min || numHours > max) {
                        printf("\nInvalid input. Number of hours must be between %.2lf and %.2lf\n\n", min, max);
                    }
                    
                    else if (numHours > sentinelVal && numHours < 0) {
                        puts("\nInvalid input.\n");
                    }
                
                    else if (numHours == 0.0) {
                        puts("\nThere were no cars parked today.\n");
                    }
                                
                    carCnt++;
                    
                    totalHours += numHours;
                    
                    if (!stopLoop && numHours > min) {
                    
                        //Charge must be reset
                        if (numHours <= 2.0) {
                            charge = 2.0;
                        }
                        //else if (numHours != min) {
                        else {
                            charge = 1.5;
                        }
                        
                        //Hours counter must be reset here
                        hrsCntr = 2.0;
                        
                        while (hrsCntr <= maxHrsDaily && hrsCntr < numHours) {
                        
                            if (numHours <= 3.0) {
                                charge = 2.0;
                            }
                            
                            else {
                                charge += 0.5;
                            }
             
                            hrsCntr = hrsCntr + 1.0;
                        
                        }//End while
                                    
                        chargeSum += charge;
               
                        puts("Car\t\t Hours\t\t Charge\n");
                        
                        printf("%d\t\t %.2lf\t\t  $%.2lf\n\n", carCnt, numHours, charge);
                        
                    } //End if (!stopLoop)
                    
                } //End if (scanfRtrn == 1)
            
            } //End if (numHours == sentinelVal)
        
            else {
                stopLoop = true;
            }
            
        } //End else
        
    } //End while (!stopLoop)
    
    puts("Totals for the day:\n");
    puts("Car(s)\t\t Hours\t\t Charge\n");
    
    printf("%d\t\t %.2lf\t\t  $%.2lf\n\n", carCnt, totalHours, chargeSum);

    
    return 0;
    
}

void validateData(int scanfRtrn, double min, double max, double sentinelVal, double numHours) {
    //bool errorEncountered = false;
    
    if (scanfRtrn != 1) {
        puts("\nYou did not enter a number.\n");
    }
    
    if (numHours < min || numHours > max) {
        printf("\nInvalid input. Number of hours must be betwwen %.2lf and %.2lf\n\n", min, max);
    }
    
    if (numHours > sentinelVal && numHours <= 0) {
        puts("\nInvalid input.\n");
    }
    
}

double chargeAlgorithm (double numHours) {
    double charge = 0;
   
    return charge;
}
