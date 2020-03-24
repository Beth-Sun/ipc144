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

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n')   ; // empty execution code block on purpose
}

// pause: Empty function definition goes here:
void pause(void) {
    printf("(Press Enter to Continue)");
    clearKeyboard();
}


// getInt: Empty function definition goes here:
int getInt(void) {
    char nl = '\0';
    int value = 0;
    while (!scanf("%d%c", &value, &nl) || nl != '\n') {
        clearKeyboard();
        printf("*** INVALID INTEGER *** <Please enter an integer>: ");
    }
    return value;
}


// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max) {
    int value;
    while(1) {
        value = getInt();
        if (value >= min && value <= max) {
            break;
        }
        printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
    }
    return value;
}


// yes: Empty function definition goes here:
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


// menu: Empty function definition goes here:
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


// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void) {
    int option = -1;
    int exit = 0;
    while (!exit) {
        option = menu();
        switch (option)
        {
        case 0:
            printf("\nExit the program? (Y)es/(N)o: ");
            if (yes()) {
                exit = 1;
            }
            printf("\n");
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            printf("\n<<< Feature %d is unavailable >>>\n\n", option);
            pause();
            printf("\n");
            break;
        }
    }
    printf("Contact Management System: terminated\n");
}
