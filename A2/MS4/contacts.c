//==============================================
// Name:           Full name here
// Student Number: #########
// Email:          userID@myseneca.ca
// Section:        XXX
// Date:           
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contacts.h"
#include "contactHelpers.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

int doYouWantToEnter(char field[]) {
    printf("Do you want to enter %s? (y or n): ", field);
    return yes();
}

// getName:
void getName(struct Name* name) {
    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]", name->firstName);
    clearKeyboard();

    if (doYouWantToEnter("a middle initial(s)")) {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]", name->middleInitial);
        clearKeyboard();
    }
    else {
        name->middleInitial[0] = '\0';
    }

    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]", name->lastName);
    clearKeyboard();
}
// getAddress:
void getAddress(struct Address* address) {
    int numberInput = -1;
    printf("Please enter the contact's street number: ");
    while (1) {
        numberInput = getInt();
        if (numberInput > 0) {
            break;
        }
        printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
    }
    address->streetNumber = numberInput;


    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]", address->street);
    clearKeyboard();

    if (doYouWantToEnter("an apartment number")) {
        printf("Please enter the contact's apartment number: ");
        while (1) {
            numberInput = getInt();
            if (numberInput > 0) {
                break;
            }
            printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
        }
        address->apartmentNumber = numberInput;
    }
    else {
        address->apartmentNumber = 0;
    }

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]", address->postalCode);
    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]", address->city);
    clearKeyboard();
}

// getNumbers:
void getNumbers(struct Numbers* numbers) {
    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell);

    if (doYouWantToEnter("a home phone number")) {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numbers->home);
    }
    else {
        numbers->home[0] = '\0';
    }

    if (doYouWantToEnter("a business phone number")) {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numbers->business);
    }
    else {
        numbers->business[0] = '\0';
    }
}
// getContact:
void getContact(struct Contact* contact) {
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}
