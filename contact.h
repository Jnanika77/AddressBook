#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact; // contact is data type we can use conact s[size];

typedef struct {
    Contact contacts[MAX_CONTACTS];// array of structure
    int contactCount; // 4 byte int variable
} AddressBook; 

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void savecontacts(AddressBook *addressBook);
void saveAndExit(AddressBook *addressBook);

#endif
