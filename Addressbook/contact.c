#include "contact.h"

/**
 * contact.c
 * Author: Blessy Edison
 * Description: Implementation of functions related to managing 
 *              contacts in the Address Book program.
 * Created on: 21-10-2024
 * @brief Lists all the contacts in the address book in a tabular format,
 *        with vertical lines to separate each column.
 * 
 * @param addressBook Pointer to the AddressBook structure containing contacts.
 */
void listContacts(AddressBook *addressBook) 
{
    // Check if there are any contacts
    if (addressBook->contactCount == 0) {
        printf("No contacts available.\n");
    } else {
        // Print header for the table
        printf("\n%-5s | %-20s | %-15s | %-30s\n", "Sl.No", "Name", "Phone", "Email");
        printf("---------------------------------------------------------------\n");

        // Iterate through the contacts and print them in a tabular format
        for (int i = 0; i < addressBook->contactCount; i++) {
            printf("%-5d | %-20s | %-15s | %-30s\n", 
                   i + 1, 
                   addressBook->contacts[i].name, 
                   addressBook->contacts[i].phone, 
                   addressBook->contacts[i].email);
        }
        printf("---------------------------------------------------------------\n");
    }
}


/**
 * @brief Initializes the address book with dummy data.
 * 
 * @param addressBook Pointer to the AddressBook structure.
 */
void initialize(AddressBook *addressBook) {
    addressBook->contactCount = DUMMY_CONTACTS_COUNT;
    memcpy(addressBook->contacts, dummyContacts, DUMMY_CONTACTS_COUNT * sizeof(Contact));
}

/**
 * @brief Creates a new contact and adds it to the address book.
 * 
 * @param addressBook Pointer to the AddressBook structure.
 */
void createContact(AddressBook *addressBook) 
{
    // Check if the address book is full
    if (addressBook->contactCount >= MAX_CONTACTS) {
        printf("Address book is full. Cannot add new contact.\n");
        return;
    }

    // Input new contact details
    Contact newContact;
    printf("Enter name: ");
    scanf(" %[^\n]s", newContact.name);
    printf("Enter phone: ");
    scanf(" %[^\n]s", newContact.phone);
    printf("Enter email: ");
    scanf(" %[^\n]s", newContact.email);

    // Add new contact to the address book
    addressBook->contacts[addressBook->contactCount++] = newContact;
    printf("Contact added successfully!\n");
}

/**
 * @brief Searches for a contact based on name, phone, or email.
 * 
 * @param addressBook Pointer to the AddressBook structure.
 */
void searchContact(AddressBook *addressBook) {
    int choice;
    char searchTerm[50];

    // Ask user how they want to search
    printf("How would you like to proceed with your search:\n");
    printf("1. Name\n2. Phone\n3. Email\nEnter your choice: ");
    scanf("%d", &choice);
    getchar();  // Consume the newline character

    // Get search term from the user
    printf("Enter search term: ");
    fgets(searchTerm, sizeof(searchTerm), stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0';  // Remove newline character from input

    // Search and display results
    int found = 0;
    printf("\n%-20s %-15s %-30s\n", "Name", "Phone", "Email");  // Table headers
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < addressBook->contactCount; i++) {
        if ((choice == 1 && strstr(addressBook->contacts[i].name, searchTerm) != NULL) ||
            (choice == 2 && strstr(addressBook->contacts[i].phone, searchTerm) != NULL) ||
            (choice == 3 && strstr(addressBook->contacts[i].email, searchTerm) != NULL)) {

            // Print matching contact in table format
            printf("%-20s %-15s %-30s\n", 
                   addressBook->contacts[i].name, 
                   addressBook->contacts[i].phone, 
                   addressBook->contacts[i].email);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching contacts found.\n");
    }

    printf("\nPress any key to continue...\n");
    getchar();  // Wait for user to press any key
}

/**
 * @brief Edits an existing contact in the address book.
 * 
 * @param addressBook Pointer to the AddressBook structure.
 */
void editContact(AddressBook *addressBook) {
    char searchTerm[50];

    // Get the name of the contact to edit
    printf("Enter the name of the contact you want to edit: ");
    fgets(searchTerm, sizeof(searchTerm), stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0';  // Remove newline character from input

    int found = 0;
    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(addressBook->contacts[i].name, searchTerm) == 0) {
            int choice;

            // Display contact details
            printf("Contact found:\nName: %s\nPhone: %s\nEmail: %s\n", 
                   addressBook->contacts[i].name, 
                   addressBook->contacts[i].phone, 
                   addressBook->contacts[i].email);

            // Ask what to edit
            printf("What do you want to edit?\n1. Name\n2. Phone\n3. Email\nEnter your choice: ");
            scanf("%d", &choice);
            getchar();  // Consume the newline character

            // Edit the contact based on user choice
            switch (choice) {
                case 1:
                    printf("Enter new name: ");
                    fgets(addressBook->contacts[i].name, sizeof(addressBook->contacts[i].name), stdin);
                    addressBook->contacts[i].name[strcspn(addressBook->contacts[i].name, "\n")] = '\0';
                    break;
                case 2:
                    printf("Enter new phone number: ");
                    fgets(addressBook->contacts[i].phone, sizeof(addressBook->contacts[i].phone), stdin);
                    addressBook->contacts[i].phone[strcspn(addressBook->contacts[i].phone, "\n")] = '\0';
                    break;
                case 3:
                    printf("Enter new email: ");
                    fgets(addressBook->contacts[i].email, sizeof(addressBook->contacts[i].email), stdin);
                    addressBook->contacts[i].email[strcspn(addressBook->contacts[i].email, "\n")] = '\0';
                    break;
                default:
                    printf("Invalid choice.\n");
            }

            printf("Contact updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

/**
 * @brief Deletes a contact based on name, phone, or email search.
 * 
 * @param addressBook Pointer to the AddressBook structure.
 */
void deleteContact(AddressBook *addressBook) 
{
    int choice;
    char searchTerm[50];

    // Step 1: Ask user how they want to search for the contact
    printf("Please specify how you want to proceed with the search:\n");
    printf("1. Name\n2. Phone\n3. Email\nEnter your choice: ");
    scanf("%d", &choice);
    getchar();  // Consume the newline character

    // Step 2: Get the search term
    printf("Enter search term: ");
    fgets(searchTerm, sizeof(searchTerm), stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0';  // Remove newline character

    int found = 0;
    int serialNumber = 1;

    // Step 3: Display matching contacts with serial numbers
    printf("\n%-5s %-20s %-15s %-30s\n", "Sl.No", "Name", "Phone", "Email");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < addressBook->contactCount; i++) {
        if ((choice == 1 && strstr(addressBook->contacts[i].name, searchTerm) != NULL) ||
            (choice == 2 && strstr(addressBook->contacts[i].phone, searchTerm) != NULL) ||
            (choice == 3 && strstr(addressBook->contacts[i].email, searchTerm) != NULL)) {

            // Print matching contacts with serial numbers
            printf("%-5d %-20s %-15s %-30s\n", 
                   serialNumber++, 
                   addressBook->contacts[i].name, 
                   addressBook->contacts[i].phone, 
                   addressBook->contacts[i].email);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching contacts found.\n");
        printf("Press any key to continue...\n");
        getchar();
        return;
    }

    // Step 4: Ask for serial number to delete
    printf("\nEnter the serial number of the contact you want to delete: ");
    int deleteSerial;
    scanf("%d", &deleteSerial);
    getchar();  // Consume the newline character

    // Validate the serial number
    if (deleteSerial < 1 || deleteSerial >= serialNumber) {
        printf("Invalid serial number.\n");
        printf("Press any key to continue...\n");
        getchar();
        return;
    }

    // Step 5: Delete the contact by serial number
    int realIndex = deleteSerial - 1;
    for (int i = realIndex; i < addressBook->contactCount - 1; i++) {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }
    addressBook->contactCount--;

    printf("Contact deleted successfully.\n");
    printf("Press any key to continue...\n");
    getchar();
}
void saveContacts(AddressBook *addressBook) {
    FILE *file = fopen("contacts.txt", "w"); // Open a file in write mode
    if (!file) {
        printf("Error opening file for saving contacts.\n");
        return;
    }

    for (int i = 0; i < addressBook->contactCount; i++) {
        fprintf(file, "%s,%s,%s\n", 
                addressBook->contacts[i].name, 
                addressBook->contacts[i].phone, 
                addressBook->contacts[i].email); // Write contacts in CSV format
    }

    fclose(file); // Close the file
    printf("Contacts saved successfully!\n");
}

