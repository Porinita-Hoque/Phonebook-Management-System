#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

Contact phonebook[MAX_CONTACTS];
int numContacts = 0;

void addContact() {
    if (numContacts == MAX_CONTACTS) {
        printf("Phonebook is full. Cannot add more contacts.\n");
        return;
    }

    Contact newContact;
    printf("Enter name: ");
    fgets(newContact.name, MAX_NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter phone number: ");
    fgets(newContact.phone, MAX_PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0'; // Remove trailing newline

    phonebook[numContacts] = newContact;
    numContacts++;

    printf("Contact added successfully.\n");
}

void searchContacts() {
    if (numContacts == 0) {
        printf("Phonebook is empty.\n");
        return;
    }

    char searchName[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(searchName, MAX_NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Remove trailing newline

    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phonebook[i].name, searchName) == 0) {
            printf("Name: %s\nPhone: %s\n", phonebook[i].name, phonebook[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void updateContact() {
    if (numContacts == 0) {
        printf("Phonebook is empty.\n");
        return;
    }

    char updateName[MAX_NAME_LENGTH];
    printf("Enter name of contact to update: ");
    fgets(updateName, MAX_NAME_LENGTH, stdin);
    updateName[strcspn(updateName, "\n")] = '\0'; // Remove trailing newline

    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phonebook[i].name, updateName) == 0) {
            printf("Enter new name: ");
            fgets(phonebook[i].name, MAX_NAME_LENGTH, stdin);
            phonebook[i].name[strcspn(phonebook[i].name, "\n")] = '\0'; // Remove trailing newline

            printf("Enter new phone number: ");
            fgets(phonebook[i].phone, MAX_PHONE_LENGTH, stdin);
            phonebook[i].phone[strcspn(phonebook[i].phone, "\n")] = '\0'; // Remove trailing newline

            printf("Contact updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void deleteContact() {
    if (numContacts == 0) {
        printf("Phonebook is empty.\n");
        return;
    }

    char deleteName[MAX_NAME_LENGTH];
    printf("Enter name of contact to delete: ");
    fgets(deleteName, MAX_NAME_LENGTH, stdin);
    deleteName[strcspn(deleteName, "\n")] = '\0'; // Remove trailing newline

    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phonebook[i].name, deleteName) == 0) {
            for (int j = i; j < numContacts - 1; j++) {
                phonebook[j] = phonebook[j + 1];
            }
            numContacts--;

            printf("Contact deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void showAllContacts() {
    if (numContacts == 0) {
        printf("Phonebook is empty.\n");
        return;
    }

    printf("All Contacts:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("Name: %s\nPhone: %s\n", phonebook[i].name, phonebook[i].phone);
        printf("------------------\n");
    }
}

void displayMenu() {
    printf("\nPhonebook Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Update Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Show All Contacts\n");
    printf("6. Exit\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContacts();
                break;
            case 3:
                updateContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                showAllContacts();
                break;
            case 6:
                printf("Exiting phonebook.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
