//
//  CS 2060 HW #2.c
//  CS 2060
//
//  Created by Benjamin Schwartz on 6/22/22.
//

#include "CS 2060 HW #2.h"
#include <stdio.h>
#include <stdbool.h>

//Prototypes
bool validateData(int scanfRtrn, double min, double max, double sentinelVal, double numHours);
int getUserInput(double numHours);
double chargeAlgorithm (double numHours, int carCnt);
void printTotals(int carCnt, double totalHours, double chargeSum);

const short scanfOkRtrnConst = 1;


int main(void) {
    
    //Initialize vars
    bool isError = true;
    bool stopLoop = false;
    int scanfRtrn = -1;
    int rtrn = 0;
    unsigned int carCnt = 0;
    double totalHours = 0.0;
    double chargeSum = 0.0;
    double charge = 0.0;
    double numHours = 0.0;

    //Constants
    const double sentinelVal = -1;
    const double min = 0.0;
    const double max = 24.0;
    
    while (!stopLoop) {
                
        puts("\nEnter the number of hours the car was parked. Enter -1 to end the program.");
        
        //Get user input
        scanfRtrn = scanf("%lf", &numHours);
        
        //Clear buffer
        while (getchar() != '\n');
        
        isError = validateData(scanfRtrn, min, max, sentinelVal, numHours);
        
        if (!isError) {
                    
            if (numHours != sentinelVal) {
                                         
                carCnt++;
                
                totalHours += numHours;
                
                charge = chargeAlgorithm(numHours, carCnt);
                
                chargeSum += charge;

            } //End if (numHours != sentinelVal) {
        
            else {
                stopLoop = true;
            }
            
        } //End if (!isError)
                    
    } //End while (!stopLoop)
    
    printTotals(carCnt, totalHours, chargeSum);

    return rtrn;
    
} //End main()


bool validateData(int scanfRtrn, double min, double max, double sentinelVal, double numHours) {
    
    bool rtrn = false;
        
        if (scanfRtrn != scanfOkRtrnConst) {
            puts("----------------------------------------------------------------------------------------------------------");
            puts("Error. Please enter a single number. No characters other than numbers and a decimal point (.) are allowed.");
            puts("----------------------------------------------------------------------------------------------------------");
            rtrn = true;
        }
        
        if ((numHours < min || numHours > max) && numHours != sentinelVal) {
            puts("---------------------------------------------------------------------");
            printf("Error. Invalid input. Number of hours must be between %.2lf and %.2lf.\n", min, max);
            puts("---------------------------------------------------------------------");
            rtrn = true;
        }
        
        if (numHours != sentinelVal && numHours < 0) {
            puts("--------------------------------------------------");
            puts("Error. Invalid input. Input hours must be positive.");
            puts("---------------------------------------------------");
            rtrn = true;
        }
        
        if (numHours == 0.0) {
            puts("-----------------------------------------------------------");
            puts("Error. Zero (0) hours will be entered for this transaction.");
            puts("-----------------------------------------------------------");
            rtrn = true;
        }
    
    return rtrn;
    
} //End validateData()


double chargeAlgorithm (double numHours, int carCnt) {
   
    //Vars
    double charge = 0.0;
    double ceilingInt = 0.0;
    bool stopLoop = false;

    //Constants
    const double basePay = 2.0;
    const double increment = 0.5;
    const double maxDailyCharge = 10.0;
        
    if (!stopLoop) {
        
        //Set numHours to the smallest integer greater than numHours
        ceilingInt = ceil(numHours);

        if (numHours <= 3.0) {
            charge = basePay;
        }
        
        else {
            //Use derived formula
            charge = basePay + (ceilingInt - 3.0) * increment;
        }
        
        if (charge > maxDailyCharge) {
            charge = maxDailyCharge;
        }
        puts("----------------------------------------------------------------");
        puts("Car Number\t\t Hours Parked\t\t Charge for This Transaction");
        printf("%d\t\t\t\t %.2lf\t\t\t\t $%.2lf\n", carCnt, numHours, charge);
        puts("----------------------------------------------------------------");
    } //End if (!stopLoop)
   
    return charge;
    
} //End chargeAlgorithm()


void printTotals(int carCnt, double totalHours, double chargeSum) {
    puts("\n********************************************************************************************************");
    puts("Totals for the day:\n");
    puts("Total Number of Cars Parked Today:  Total Hours for Cars Parked Today: Total Bill for Cars Parked Today:");
    printf("%d\t\t\t\t\t\t\t\t\t%.2lf\t\t\t\t\t\t\t   $%.2lf\n", carCnt, totalHours, chargeSum);
    puts("********************************************************************************************************\n");

} //End printTotals()

