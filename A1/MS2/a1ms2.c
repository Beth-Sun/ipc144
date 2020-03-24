//==============================================
// Name:           Full name here
// Student Number: #########
// Email:          userID@myseneca.ca
// Section:        XXX
// Date:           
//==============================================
// Assignment:     1
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

void clearInput() {
    while (getchar() != '\n');
}

int doYouWantToEnter(char field[]) {
    char yesOrNo = 'n';
    printf("Do you want to enter %s? (y or n): ", field);
    scanf("%c", &yesOrNo);
    clearInput();
    return yesOrNo == 'y' || yesOrNo == 'Y';
}

int main (void)
{
    // Declare variables here:
    struct Name name = {{ 0 }};
    struct Address address = { 0 };
    struct Numbers numbers = {{ 0 }};
    
    // Display the title
    printf("Contact Management System\n-------------------------\n");

    // Contact Name Input:
    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]", name.firstName);
    clearInput();

    if (doYouWantToEnter("a middle initial(s)")) {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]", name.middleInitial);
        clearInput();
    }

    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]", name.lastName);
    clearInput();

    // Contact Address Input:
    printf("Please enter the contact's street number: ");
    scanf("%d", &address.streetNumber);
    clearInput();

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]", address.street);
    clearInput();

    if (doYouWantToEnter("an apartment number")) {
        printf("Please enter the contact's apartment number: ");
        scanf("%d", &address.apartmentNumber);
        clearInput();
    }

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]", address.postalCode);
    clearInput();

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]", address.city);
    clearInput();

    // Contact Numbers Input:
    if (doYouWantToEnter("a cell phone number")) {
        printf("Please enter the contact's cell phone number: ");
        scanf("%10[^\n]", numbers.cell);
        clearInput();
    }

    if (doYouWantToEnter("a home phone number")) {
        printf("Please enter the contact's home phone number: ");
        scanf("%10[^\n]", numbers.home);
        clearInput();
    }

    if (doYouWantToEnter("a business phone number")) {
        printf("Please enter the contact's business phone number: ");
        scanf("%10[^\n]", numbers.business);
        clearInput();
    }

    // Display Contact Summary Details
    printf("\n");
    printf("Contact Details\n---------------\n");
    printf("Name Details:\n");
    printf("First name: %s\n", name.firstName);
    printf("Middle initial(s): %s\n", name.middleInitial);
    printf("Last name: %s\n", name.lastName);
    printf("\n");

    printf("Address Details:\n");
    printf("Street number: %d\n", address.streetNumber);
    printf("Street name: %s\n", address.street);
    printf("Apartment: %d\n", address.apartmentNumber);
    printf("Postal code: %s\n", address.postalCode);
    printf("City: %s\n", address.city);
    printf("\n");

    printf("Phone Numbers:\n");
    printf("Cell phone number: %s\n", numbers.cell);
    printf("Home phone number: %s\n", numbers.home);
    printf("Business phone number: %s\n", numbers.business);
    printf("\n");
    // Display Completion Message
    printf("Structure test for Name, Address, and Numbers Done!\n");

    return 0;
}

/*  SAMPLE OUTPUT:
    
    Contact Management System
    -------------------------
    Please enter the contact's first name: Tom
    Do you want to enter a middle initial(s)? (y or n): y
    Please enter the contact's middle initial(s): L. A.
    Please enter the contact's last name: Wong Song
    Please enter the contact's street number: 20
    Please enter the contact's street name: Keele Street
    Do you want to enter an apartment number? (y or n): y
    Please enter the contact's apartment number: 40
    Please enter the contact's postal code: A8A 4J4
    Please enter the contact's city: North York
    Do you want to enter a cell phone number? (y or n): Y
    Please enter the contact's cell phone number: 9051116666
    Do you want to enter a home phone number? (y or n): Y
    Please enter the contact's home phone number: 7052227777
    Do you want to enter a business phone number? (y or n): Y
    Please enter the contact's business phone number: 4163338888

    Contact Details
    ---------------
    Name Details:
    First name: Tom
    Middle initial(s): L. A.
    Last name: Wong Song

    Address Details:
    Street number: 20
    Street name: Keele Street
    Apartment: 40
    Postal code: A8A 4J4
    City: North York

    Phone Numbers:
    Cell phone number: 9051116666
    Home phone number: 7052227777
    Business phone number: 4163338888

    Structure test for Name, Address, and Numbers Done!
*/
