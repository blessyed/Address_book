/*
 * contact.h
 * 
 * Author: Blessy Edison
 * Description: Header file for the Address Book program containing 
 *              definitions of data structures and function declarations.
 * Created on: 21-10-2024
 *  */
#ifndef CONTACT_H
#define CONTACT_H
#define DUMMY_CONTACTS_COUNT 10


#define MAX_CONTACTS 100

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

extern Contact dummyContacts[];

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContacts(AddressBook *addressBook);


#endif
