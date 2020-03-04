//==============================================
// Name:           Full name here
// Student Number: #########
// Email:          userID@myseneca.ca
// Section:        XXX
// Workshop:       2 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:
#include<stdio.h>

int main(void)
{
	float amountInDollars; 
	int loonies;
	int amountInCents; 
	
	printf("Please enter the amount to be paid: $");
	scanf("%f", &amountInDollars);


	amountInCents = amountInDollars * 100;

	int balance1 = amountInCents % 100;
	loonies = amountInCents / 100; 
	printf("Loonies required: %d, balance owing $%.2f\n", loonies, balance1 / 100.0);

	int quarters = balance1 / 25;
	int balance2 = balance1 % 25;
	printf("Quarters required: %d, balance owing $%.2f\n", quarters, balance2 / 100.0);

	return 0;
}