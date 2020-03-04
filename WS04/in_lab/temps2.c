//==============================================
// Name:           Full name here
// Student Number: #########
// Email:          userID@myseneca.ca
// Section:        XXX
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
# include <stdio.h>

int main(void)
{
    int days;

    int high[10];
    int low[10];


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
    for (i = 1; i <= days; i++) {
        printf("Day %d - High: ", i);
        scanf("%d", &high[i - 1]);

        printf("Day %d - Low: ", i);
        scanf("%d", &low[i - 1]);
    }
    printf("\n");


    printf("Day  Hi  Low\n");
    for (i = 1; i <= days; i++) {
        printf("%d    %d    %d\n", i, high[i - 1], low[i - 1]);
    }















    return 0;
}
