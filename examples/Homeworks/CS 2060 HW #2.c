//
//  CS 2060 HW #2.c
//  CS 2060
//
//  Created by Benjamin Schwartz on 6/22/22.
//

#include "CS 2060 HW #2.h"
#include <stdbool.h>

int main(void) {
    
    //Vars
    double charge = 2.0;
    double chargeSum = 0.0;
    double numHours = 0.0;
    double totalHours = 0.0;
    
    bool stopLoop = false;
    
    int scanfRtrn = -1;
    const double min = 0;
    const double max = 24.0;
    short carCnt = 0;
    
    
    double hrsCntr = 3.0;
    
    
    const short sentinelVal = -1;
    const double maxHrsDaily = 18.0;
    const short scanfOkRtrnVal = 1;

    while (!stopLoop) {
        
        puts("Enter the number of hours the car was parked or enter -1 to quit.\n");
        
        scanfRtrn = scanf("%lf", &numHours);
        
        while (getchar() != '\n');
        
        if (scanfRtrn != scanfOkRtrnVal) {
            puts("\nPlease enter a number.\n");
        }
        
        if (numHours != sentinelVal) {
            
            if (scanfRtrn == scanfOkRtrnVal) {
            
                if (numHours < min || numHours > max) {
                    printf("\nInvalid input. Number of hours must be betwwen %.2lf and %.2lf\n\n", min, max);
                }
                
                if (numHours > sentinelVal && numHours <= 0) {
                    puts("\nInvalid input.\n");
                }
                            
                carCnt++;
                
                totalHours += numHours;
                
                if (!stopLoop) {
                
                    //Charge must be reset
                    if (numHours <= 2.0) {
                        charge = 2.0;
                    }
                    else {
                        charge = 1.5;
                    }
                    
                    //Hours counter must be reset
                    hrsCntr = 2.0;
                    
                    while (hrsCntr <= maxHrsDaily && hrsCntr < numHours) {
                    
                        if (numHours <= 3.0) {
                            charge = 2.0;
                        }
                        
                        else {
                            charge += 0.5;
                        }
            //            if (numHours > (hrsCntr - 1.0) && numHours <= hrsCntr) {
        //                    charge += 0.5;
            //            }
                        
                        hrsCntr = hrsCntr + 1.0;
                    }//end while
                    
                    
                    chargeSum += charge;
            //         if (numHours > 4.0 && numHours <= 5.0) {
            //            charge += 0.5;
            //        }
            //         if (numHours > 5.0 && numHours <= 6.0) {
            //            charge += 0.5;
            //        }
            //         if (numHours > 6.0 && numHours <= 7.0) {
            //            charge += 0.5;
            //        }
            //         if (numHours > 7.0 && numHours <= 8.0) {
            //            charge += 0.5;
            //        }
            //         if (numHours > 8.0 && numHours <= 9.0) {
            //            charge += 0.5;
            //        }
            //         if (numHours > 9.0 && numHours <= 10.0) {
            //            charge += 0.5;
            //        }
            //         if (numHours > 10.0 && numHours <= 11.0) {
            //            charge += 0.5;
            //        }
            //         if (numHours > 11.0 && numHours <= 12.0) {
            //            charge += 0.5;
            //        }
            //        else if (numHours > 12.0 && numHours <= 13.0) {
            //            charge += 0.5;
            //        }
                   
                    puts("Car\t\t Hours\t\t Charge\n");
                    
                    printf("%d\t\t %.2lf\t\t  $%.2lf\n\n", carCnt, numHours, charge);
                    
                    
                } //end if (!stopLoop)
                
            } //end if if (scanfRtrn == 1)
            
        } //end if (numHours == sentinelVal)
        
        else {
            stopLoop = true;
        }
        
    } //end while (!stopLoop)
    
    
    puts("Total for the day:\n");
    puts("Cars\t\t Hours\t\t Charge\n");
    
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
