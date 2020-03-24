//==============================================
// Name:           Full name here
// Student Number: #########
// Email:          userID@myseneca.ca
// Section:        XXX
// Date:           
//==============================================
// Assignment:     1
// Milestone:      4
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

// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name* name) {
    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]", name->firstName);
    clearInput();

    if (doYouWantToEnter("a middle initial(s)")) {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]", name->middleInitial);
        clearInput();
    }

    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]", name->lastName);
    clearInput();
}


// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address* address) {
    printf("Please enter the contact's street number: ");
    scanf("%d", &address->streetNumber);
    clearInput();

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]", address->street);
    clearInput();

    if (doYouWantToEnter("an apartment number")) {
        printf("Please enter the contact's apartment number: ");
        scanf("%d", &address->apartmentNumber);
        clearInput();
    }

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]", address->postalCode);
    clearInput();

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]", address->city);
    clearInput();
}



// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers* numbers) {
    if (doYouWantToEnter("a cell phone number")) {
        printf("Please enter the contact's cell phone number: ");
        scanf("%10[^\n]", numbers->cell);
        clearInput();
    }

    if (doYouWantToEnter("a home phone number")) {
        printf("Please enter the contact's home phone number: ");
        scanf("%10[^\n]", numbers->home);
        clearInput();
    }

    if (doYouWantToEnter("a business phone number")) {
        printf("Please enter the contact's business phone number: ");
        scanf("%10[^\n]", numbers->business);
        clearInput();
    }
}
