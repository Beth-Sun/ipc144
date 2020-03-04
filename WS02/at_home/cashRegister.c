//==============================================
// Name:           Full name here
// Student Number: #########
// Email:          userID@myseneca.ca
// Section:        XXX
// Workshop:       2 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:
#include<stdio.h>

int main(void)
{
	const int LOONIES_IN_CENTS = 100;
	const int QUATER_IN_CENTS = 25;
	const int DIMES_IN_CENTS = 10;
	const int NICKELS_IN_CENTS = 5;
	const int PENNIES_IN_CENTS = 1;
	int loonies;
	int cents;
	float dollars;
	float gst;
	float balanceowing;

	printf("Please enter the amount to be paid: $");
	scanf("%f", &dollars);

	gst = dollars * 0.13 + 0.005;
	balanceowing = dollars + gst;
	printf("GST: %.2f\n", gst);
	printf("Balance owing: $%.2f\n", balanceowing);


	cents = (dollars  + gst ) * 100;

	loonies = cents / LOONIES_IN_CENTS;
	int ownAfterLoonies = cents % LOONIES_IN_CENTS;


	int quarters = ownAfterLoonies / QUATER_IN_CENTS;
	int ownAfterQuarters = ownAfterLoonies % QUATER_IN_CENTS;


	int dimes = ownAfterQuarters / DIMES_IN_CENTS;
	int ownAfterDimes = ownAfterQuarters % DIMES_IN_CENTS;

	int nickels = ownAfterDimes / NICKELS_IN_CENTS;
	int ownAfterNickels = ownAfterDimes % NICKELS_IN_CENTS;

	int pennies = ownAfterNickels / PENNIES_IN_CENTS;




	printf("Loonies required: %d, balance owing $%.2f\n", loonies, ownAfterLoonies / 100.0);
	printf("Quarters required: %d, balance owing $%.2f\n", quarters, ownAfterQuarters / 100.0);
	printf("Dimes required: %d, balance owing $%.2f\n", dimes, ownAfterDimes / 100.0);
	printf("Nickels required: %d, balance owing $%.2f\n", nickels, ownAfterNickels / 100.0);
	printf("Pennies required: %d, balance owing $0.00\n", pennies);
	return 0;
}
