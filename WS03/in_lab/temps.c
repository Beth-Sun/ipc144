//==============================================
// Name:           Full name here
// Student Number: #########
// Email:          userID@myseneca.ca
// Section:        XXX
// Workshop:       3 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>
#define NUMS 3

int main(void) {
  printf("---=== IPC Temperature Analyzer ===---\n");
  int i;
  for (i = 1; i <= NUMS; i++) {
    int high = 0;
    int low = 0;
    do {
      printf("Enter the high value for day %d: ", i);
      scanf("%d", &high);
      printf("\n");
      printf("Enter the low value for day %d: ", i);
      scanf("%d", &low);
      printf("\n");

      if (high <= low || high >= 41 || low <= -41) {
        printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
        printf("\n");
      }
    } while(high <= low || high >= 41 || low <= -41);
  }
  return 0;
}
