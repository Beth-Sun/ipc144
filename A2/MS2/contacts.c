//==============================================
// Name:           Full name here
// Student Number: #########
// Email:          userID@myseneca.ca
// Section:        XXX
// Date:           
//==============================================
// Assignment:     2
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


// This source file needs to "know about" the functions you prototyped
//         in the contact helper header file too
// HINT-1: You will want to use the new yes() and getInt() functions to help
//         simplify the data input process and reduce redundant coding
//
// HINT-2: Put the header file name in double quotes so the compiler knows
//         to look for it in the same directory/folder as this source file
//         #include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// +-------------------------------------------------+
//
// HINT:  Update these function to use the helper 
//        functions where applicable (ex: yes() and getInt() )


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

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]", address->postalCode);
    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]", address->city);
    clearKeyboard();
}


// getNumbers:
// NOTE:  Also modify this function so the cell number is
//        mandatory (don't ask to enter the cell number)
void getNumbers(struct Numbers* numbers) {
    printf("Please enter the contact's cell phone number: ");
    scanf("%10[^\n]", numbers->cell);
    clearKeyboard();

    if (doYouWantToEnter("a home phone number")) {
        printf("Please enter the contact's home phone number: ");
        scanf("%10[^\n]", numbers->home);
        clearKeyboard();
    }

    if (doYouWantToEnter("a business phone number")) {
        printf("Please enter the contact's business phone number: ");
        scanf("%10[^\n]", numbers->business);
        clearKeyboard();
    }
}



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+

// getContact
void getContact(struct Contact* contact) {
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}