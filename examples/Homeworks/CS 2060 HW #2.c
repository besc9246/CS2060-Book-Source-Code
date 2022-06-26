//
//  CS 2060 HW #2.c
//  CS 2060
//
//  Created by Benjamin Schwartz on 6/22/22.
//

#include "CS 2060 HW #2.h"
#include <stdio.h>
#include <stdbool.h>
//#include <math.h>

static const short scanfOkRtrnVal = 1;


int main(void) {
    
    //Initialize vars
    double charge = 2.0;
    double chargeSum = 0.0;
    double numHours = 0.0;
    double totalHours = 0.0;
    double ceilingInt = 0.0;
    bool stopLoop = false;
    bool isError = true;
    int scanfRtrn = -1;
    short carCnt = 0;
    
    //Constants
    const short sentinelVal = -1;
    
    const double min = 0.0;
    const double max = 24.0;
    const double initialVal = 2.0;
    const double increment = 0.5;
    const double maxDailyCharge = 10.0;

    while (!stopLoop) {
        
        scanfRtrn = getUserInput(numHours);
        
        isError = validateData(scanfRtrn, min, max, sentinelVal, numHours);

        //if (scanfRtrn != scanfOkRtrnVal) {
            //puts("\nPlease enter a single number. No characters other than numbers and a decimal point are allowed.\n");
        //}
        
        //else {
        
        if (!isError) {
                    
            if (numHours != sentinelVal) {
            
                //if (scanfRtrn == scanfOkRtrnVal) {
                
                    //if (numHours < min || numHours > max) {
                    //    printf("\nInvalid input. Number of hours must be between %.2lf and %.2lf\n\n", min, max);
                    //}
                    
                    //else {
                    
                        //if (numHours > sentinelVal && numHours < 0) {
                            //puts("\nInvalid input. Input hours must be positive.\n");
                        //}
                        
                        //else {
                                
                            //if (numHours == 0.0) {
                               //puts("\nThere were no cars parked today.\n");
                            //}
                            
                            //else {
                                                                             
                carCnt++;
        
                totalHours += numHours;
    
                if (!stopLoop) {
                    
                    ceilingInt = ceil(numHours);
    
                    if (numHours <= 3.0) {
                        charge = initialVal;
                    }
                    
                    else {
                        charge = initialVal + (ceilingInt - 3.0) * increment;
                    }
                    
                    if (charge > maxDailyCharge) {
                        charge = maxDailyCharge;
                    }
                    
                    chargeSum += charge;

                    puts("Car\t\t Hours\t\t Charge\n");
    
                    printf("%d\t\t %.2lf\t\t  $%.2lf\n\n", carCnt, numHours, charge);
        
                } //End if (!stopLoop)
                        
            } //End if (numHours != sentinelVal) {

                
            //} //End else for numHours > sentinelVal && numHours < 0
        
        //} //End else for numHours < min || numHours > max
            
    //} //End if (scanfRtrn == 1)

//} //End if (numHours == sentinelVal)
        
            else {
                stopLoop = true;
            }
            
        } //End if (!isError)
            
        //} //End else for scanfRtrn != scanfOkRtrnVal
        
    } //End while (!stopLoop)
    
    puts("\n\nTotals for the day:\n");
    puts("Car(s)\t\t Hours\t\t Charge\n");
    
    printf("%d\t\t %.2lf\t\t  $%.2lf\n\n", carCnt, totalHours, chargeSum);

    
    return 0;
    
}

bool validateData(int scanfRtrn, double min, double max, double sentinelVal, double numHours) {
    
    bool isError = false;
    
    if (numHours != sentinelVal) {
    
        if (scanfRtrn != scanfOkRtrnVal) {
            puts("\nPlease enter a single number. No characters other than numbers and a decimal point are allowed.\n");
            isError = true;
        }
        
        if (numHours < min || numHours > max) {
            printf("\nInvalid input. Number of hours must be between %.2lf and %.2lf\n\n", min, max);
            isError = true;
        }
        
        if (numHours > sentinelVal && numHours < 0) {
            puts("\nInvalid input. Input hours must be positive.\n");
            isError = true;
        }
        
        if (numHours == 0.0) {
            puts("\nThere were no cars parked today.\n");
            isError = true;
        }
        
    } //End if (numHours != sentinelVal)
    
    return isError;
    
}

double chargeAlgorithm (double numHours) {
    double charge = 0;
   
    return charge;
    
}

int getUserInput(double numHours) {
    int scanfRtrn = -1;
    
    puts("Enter the number of hours the car was parked or enter -1 to quit.");
    
    //Get user input
    scanfRtrn = scanf("%lf", &numHours);
    
    //Clear buffer
    while (getchar() != '\n');

    return scanfRtrn;
}
