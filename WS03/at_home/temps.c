//==============================================
// Name:           Full name here
// Student Number: #########
// Email:          userID@myseneca.ca
// Section:        XXX
// Workshop:       3 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>
#define NUMS 4


int main(void) {
    printf("---=== IPC Temperature Analyzer ===---\n");
    int i;
    int sumHigh = 0;
    int sumlow = 0;
    double meanHigh = 0;
    double meanlow = 0;
    double mean = 0;
    int highest = -41;
    int lowest = 41;
    int dayHigh = 0;
    int dayLow = 0;
    for (i = 1; i <= NUMS; i++) { // how many days
        int high = 0;
        int low = 0;
        do { // notice user input
            printf("Enter the high value for day %d: ", i);
            scanf("%d", &high);
            printf("\n");
            printf("Enter the low value for day %d: ", i);
            scanf("%d", &low);
            printf("\n");

            if (high <= low || high >= 41 || low <= -41) { // wrong input
                printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
                printf("\n");
            }
            if (!(high <= low || high >= 41 || low <= -41)) { // filter out wrong input; error prompt did not print
                sumHigh += high;
                sumlow += low;
                if (highest < high) {  // find the highest
                    highest = high;    // give the temprature to highest
                    dayHigh = i;  // give the date to dayHigh
                }
                if (lowest > low) {
                    lowest = low;
                    dayLow = i;
                }
            }
            
        } while (high <= low || high >= 41 || low <= -41);
    }
    meanHigh = (double)sumHigh / NUMS;
    meanlow = (double)sumlow / NUMS;
    mean = (meanHigh + meanlow) / 2;
    printf("The average (mean) LOW temperature was: %.2lf", meanlow);
    printf("\n");

    printf("The average (mean) HIGH temperature was: %.2lf", meanHigh);
    printf("\n");

    printf("The average (mean) temperature was: %.2lf", mean);
    printf("\n");

    printf("The highest temperature was %d, on day %d", highest, dayHigh);
    printf("\n");

    printf("The lowest temperature was %d, on day %d", lowest,dayLow);
    printf("\n");

    return 0;
}
