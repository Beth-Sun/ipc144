//==============================================
// Name:           Full name here
// Student Number: #########
// Email:          userID@myseneca.ca
// Section:        XXX
// Workshop:       4 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
# include <stdio.h>

int main(void)
{
    int days;

    int high[10];
    int low[10];
    int highest = -273;
    int lowest = 273;
    int dayHigh = 0;
    int dayLow = 0;
    printf("---=== IPC Temperature Calculator V2.0 ===---\n");

    printf("Please enter the number of days, between 3 and 10, inclusive: ");
    scanf("%d", &days);
    printf("\n");

    while (days > 10 || days < 3)
    {
        printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
        scanf("%d", &days);
        printf("\n");

    }
    int i;
    for (i = 0; i < days; i++) {
        printf("Day %d - High: ", i + 1);
        scanf("%d", &high[i]);

        printf("Day %d - Low: ", i + 1);
        scanf("%d", &low[i]);
    }

    printf("\nDay  Hi  Low\n");
    for (i = 0; i < days; i++) {
        printf("%d    %d    %d\n", i + 1, high[i], low[i]);
    
        if (highest < high[i])
        {  // find the highest
            highest = high[i];  // give the temprature to highest
            dayHigh = i+1;  // give the date to dayHigh
        }
        if (lowest > low[i])
        {
            lowest = low[i];
            dayLow = i+1;
        }
    }
    printf("\nThe highest temperature was %d, on day %d\n", highest, dayHigh);

    printf("The lowest temperature was %d, on day %d\n", lowest, dayLow);

    int numberOfDays = 0;
    do {
        printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", days);
        scanf("%d", &numberOfDays);
        
        while (numberOfDays == 0 || numberOfDays > days) {
            printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", days);
            scanf("%d", &numberOfDays);
        }

        if (!(numberOfDays < 0))
        {
            int sum = 0;
            int j;
            for (j = 0; j < numberOfDays; j++) {
                sum += (low[j] + high[j]);
            }
            printf("\nThe average temperature up to day %d is: %.2lf\n", numberOfDays, sum / (2. * numberOfDays));
        }
    } while (!(numberOfDays < 0));
    printf("\nGoodbye!\n");
    return 0;
}
