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

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// -------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// -------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
    while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void) {
    printf("(Press Enter to Continue)");
    clearKeyboard();
}


// getInt:
int getInt(void) {
    char nl = '\0';
    int value = 0;
    while (!scanf("%d%c", &value, &nl) || nl != '\n') {
        clearKeyboard();
        printf("*** INVALID INTEGER *** <Please enter an integer>: ");
    }
    return value;
}

// getIntInRange:
int getIntInRange(int min, int max) {
    int value;
    while (1) {
        value = getInt();
        if (value >= min && value <= max) {
            break;
        }
        printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
    }
    return value;
}

// yes:
int yes(void) {
    char input = '\0';
    char nl = '\0';
    while (!scanf("%c%c", &input, &nl) || nl != '\n'
        || (input != 'y' && input != 'Y' && input != 'n' && input != 'N')) {
        clearKeyboard();
        printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
    }
    return input == 'y' || input == 'Y';
}

// menu:
int menu(void) {
    printf("Contact Management System\n-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n");
    printf("\nSelect an option:> ");
    return getIntInRange(0, 6);
}

// contactManagerSystem:
void contactManagerSystem(void) {
    int option = -1;
    int exit = 0;

    struct Contact contacts[MAXCONTACTS] = {
        {
            { "Rick", {'\0'}, "Grimes" },
            {11, "Trailer Park", 0, "A7A 2J2", "King City"},
            {"4161112222", "4162223333", "4163334444"}
        },
        {
            {"Maggie", "R.", "Greene"},
            {55, "Hightop House", 0, "A9A 3K3", "Bolton"},
            {"9051112222", "9052223333", "9053334444"}
        },
        {
            {"Morgan", "A.", "Jones" },
            {77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough"},
            {"7051112222", "7052223333", "7053334444"}
        },
        {
            {"Sasha", {'\0'}, "Williams"},
            {55, "Hightop House", 0, "A9A 3K3", "Bolton"},
            {"9052223333", "9052223333", "9054445555"}
        }
    };

    while (!exit) {
        option = menu();
        switch (option)
        {
        case 0:
            printf("\nExit the program? (Y)es/(N)o: ");
            if (yes()) {
                exit = 1;
            }
            break;
        case 1:
            displayContacts(contacts, MAXCONTACTS);
            break;
        case 2:
            addContact(contacts, MAXCONTACTS);
            break;
        case 3:
            updateContact(contacts, MAXCONTACTS);
            break;
        case 4:
            deleteContact(contacts, MAXCONTACTS);
            break;
        case 5:
            searchContacts(contacts, MAXCONTACTS);
            break;
        case 6:
            sortContacts(contacts, MAXCONTACTS);
            break;
        }
        if (option) {
            pause();
        }
        printf("\n");
    }
    printf("Contact Management System: terminated\n");
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char phoneNum[])
{
    int needInput = 1;

    while (needInput == 1) {
        scanf("%10[0-9]", phoneNum);
        clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
        if (strlen(phoneNum) == 10)
            needInput = 0;
        else
            printf("Enter a 10-digit phone number: ");
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    int i = 0;
    for (; i < size; i++) {
        if (strcmp(contacts[i].numbers.cell, cellNum) == 0) {
            return i;
        }
    }
    return -1;
}

// displayContactHeader
void displayContactHeader(void) {
    printf("\n+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int count) {
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d\n\n", count);
}

// displayContact:
void displayContact(const struct Contact* contact) {
    if (strlen(contact->name.middleInitial)) {
        printf(" %s %s %s\n",
            contact->name.firstName,
            contact->name.middleInitial,
            contact->name.lastName);
    }
    else {
        printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
    }
    printf("    C: %-10s   H: %-10s   B: %-10s\n",
        contact->numbers.cell,
        contact->numbers.home,
        contact->numbers.business);
    printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
    if (contact->address.apartmentNumber > 0) {
        printf("Apt# %d, ", contact->address.apartmentNumber);
    }
    printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

// displayContacts:
void displayContacts(const struct Contact contacts[], int size) {
    int i = 0;
    int count = 0;
    displayContactHeader();
    for (; i < size; i++) {
        if (strcmp(contacts[i].numbers.cell, "")) {
            displayContact(&contacts[i]);
            ++count;
        }
    }
    displayContactFooter(count);
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int size) {
    printf("\nEnter the cell number for the contact: ");
    char cellNum[11];
    getTenDigitPhone(cellNum);
    int index = findContactIndex(contacts, size, cellNum);
    if (index == -1) {
        printf("*** Contact NOT FOUND ***\n");
    }
    else {
        printf("\n");
        displayContact(&contacts[index]);
    }
    printf("\n");
}

// addContact:
void addContact(struct Contact contacts[], int size) {
    int index = findContactIndex(contacts, size, "");
    if (index == -1) {
        printf("\n*** ERROR: The contact list is full! ***\n\n");
    }
    else {
        printf("\n");
        getContact(&contacts[index]);
        printf("--- New contact added! ---\n\n");
    }
}

// updateContact:
void updateContact(struct Contact contacts[], int size) {
    printf("\nEnter the cell number for the contact: ");
    char cellNum[11];
    getTenDigitPhone(cellNum);
    int index = findContactIndex(contacts, size, cellNum);
    if (index == -1) {
        printf("*** Contact NOT FOUND ***\n\n");
        return;
    }
    printf("\nContact found:\n");
    displayContact(&contacts[index]);
    printf("\n");
    printf("Do you want to update the name? (y or n): ");
    if (yes()) {
        getName(&contacts[index].name);
    }
    printf("Do you want to update the address? (y or n): ");
    if (yes()) {
        getAddress(&contacts[index].address);
    }
    printf("Do you want to update the numbers? (y or n): ");
    if (yes()) {
        getNumbers(&contacts[index].numbers);
    }
    printf("--- Contact Updated! ---\n\n");
}

// deleteContact:
void deleteContact(struct Contact contacts[], int size) {
    printf("\nEnter the cell number for the contact: ");
    char cellNum[11];
    getTenDigitPhone(cellNum);
    int index = findContactIndex(contacts, size, cellNum);
    if (index == -1) {
        printf("*** Contact NOT FOUND ***\n\n");
        return;
    }
    printf("\nContact found:\n");
    displayContact(&contacts[index]);
    printf("\n");
    printf("CONFIRM: Delete this contact? (y or n): ");
    if (yes()) {
        strcpy(contacts[index].numbers.cell, "");
        printf("--- Contact deleted! ---\n");
    }
    printf("\n");
}

// sortContacts:
void sortContacts(struct Contact contacts[], int size) {
    int i, j;
    struct Contact tmp;
    for (i = size - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (strcmp(contacts[j].numbers.cell, contacts[j + 1].numbers.cell) > 0) {
                tmp = contacts[j];
                contacts[j] = contacts[j + 1];
                contacts[j + 1] = tmp;
            }
        }
    }
    printf("\n--- Contacts sorted! ---\n\n");
}
