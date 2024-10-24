#include "contact.h"

/**
 * main.c
 * Author: Blessy Edison
 * Description: Main program for the Address Book application. 
 *              This file contains the main menu and controls the 
 *              overall flow of the program.
 * Created on: 21-10-2024

 * @brief Main function that runs the address book application.
 * 
 * This function initializes the address book and presents a menu to
 * the user, allowing them to perform various operations such as
 * listing contacts, adding a new contact, searching for a contact,
 * editing an existing contact, deleting a contact, saving the
 * contacts, and quitting the application.
 * 
 * @return int Returns 0 upon successful completion of the program.
 */
int main() {
    AddressBook addressBook;  // Declare an instance of AddressBook
    initialize(&addressBook); // Initialize the address book

    int choice;  // Variable to store user choice

    // Loop to display the menu until the user chooses to exit
    do {
        printf("\nAddress Book Menu:\n");
        printf("1. List Contacts\n");
        printf("2. Add Contact\n");
        printf("3. Search Contact\n");
        printf("4. Edit Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Save Contacts\n");
        printf("7. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);  // Read user choice

        // Switch case to handle user choice
        switch (choice) {
            case 1:
                listContacts(&addressBook);  // List all contacts
                break;
            case 2:
                createContact(&addressBook); // Add a new contact
                break;
            case 3:
                searchContact(&addressBook);  // Search for a contact
                break;
            case 4:
                editContact(&addressBook);    // Edit an existing contact
                break;
            case 5:
                deleteContact(&addressBook);  // Delete a contact
                break;
            case 6:
                saveContacts(&addressBook);    // Save contacts to a file
                break;
            case 7:
                printf("Exiting...\n");       // Exit the application
                break;
            default:
                printf("Invalid choice. Please try again.\n"); // Handle invalid choice
        }
    } while (choice != 0); // Continue looping until the user chooses to exit

    return 0; // Successful completion of the program
}
