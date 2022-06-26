//
//  CS 2060 HW #2.h
//  CS 2060
//
//  Created by Benjamin Schwartz on 6/22/22.
//

#ifndef CS_2060_HW__2_h
#define CS_2060_HW__2_h

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool validateData(int scanfRtrn, double min, double max, double sentinelVal, double numHours);

int getUserInput(double numHours);

double chargeAlgorithm (double numHours, int carCnt);

void printTotals(int carCnt, double totalHours, double chargeSum);

#endif /* CS_2060_HW__2_h */
