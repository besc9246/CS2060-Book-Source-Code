//
//  Tester.c
//  CS 2060
//
//  Created by Benjamin Schwartz on 6/30/22.
//

#include "Tester.h"
#include <stdbool.h>

int comission(void);
int salary(void);
void sumNums2To100(void);


int main(void) {
    
    //comission();
    //salary();


    return 0;
    
}



int comission(void) {
    double sale = 0.0;
    int scanfRtrn = -1;
    double salary = 0.0;
    const double basePay = 200.0;
    const double comission = 0.09;
    const double sentinel = -1.0;
    
    while (sale != sentinel) {
        printf("%s", "Enter sales in dollars. Enter -1 to end program.");
        scanfRtrn = scanf("%lf", &sale);
        while (getchar() != '\n');
        if (sale != sentinel) {
            if (sale < 0.0 || scanfRtrn != 1) {
                puts("\nInvalid Entry\n");
            }
            else {
                salary = sale*comission+basePay;
                printf("\nSalary is %.2lf\n\n", salary);
            }
            
        }
    } //End while (sale != sentinel)
    
    return 0;
}



int salary(void) {
    
    double numHours = 0.0;
    double hrlyRate = 0.0;
    double salary = 0.0;
    double overtime = 0.0;
    int scanfRtrn = -1;
    bool endLoop = false;
    
    const int sentinel = -1;
    const double maxHours = 40.0;
    
    while (!endLoop) {
        printf("%s", "Enter # of hours worked. Enter -1 to end program.");
        scanfRtrn = scanf("%lf", &numHours);
        while (getchar() != '\n');
        if (numHours != sentinel) {
            if (scanfRtrn != 1 || numHours < 0.0) {
                puts("Invalid Entry. Try again.");
            }
            else {
                printf("%s", "Enter hourly rate of the worker ($00.00):");
                scanfRtrn = scanf("%lf", &hrlyRate);
                while (getchar() != '\n');
                if (scanfRtrn != 1 || hrlyRate < 0.0) {
                    puts("Invalid Entry. Try again.");
                }
            }
                    
            if (numHours <= maxHours) {
                salary = hrlyRate * numHours;
            }
            
            else {
                salary = hrlyRate * maxHours;
                overtime = numHours - maxHours;
                salary += 1.5 * (overtime * hrlyRate);
            }
            
            printf("Salary is $%.2lf\n", salary);
            
        }
        else {
            endLoop = true;
        }
    } //End while
    
    return 0;
}


void sumNums2To100(void) {
    
}



