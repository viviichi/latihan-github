#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define TABLE_SIZE 1007
#define MAX_MEDICINE_NAME 50
#define MIN_MEDICINE_NAME 5
#define MAX_MANUFACTURER_NAME 25
#define MIN_MANUFACTURER_NAME 3
#define REGISTRATION_NUMBER_LENGTH 10
#define BATCH_NUMBER_LENGTH 16

typedef struct Medicine {
    int id;
    char name[MAX_MEDICINE_NAME];
    char manufacturer[MAX_MANUFACTURER_NAME];
    char registration_number[REGISTRATION_NUMBER_LENGTH + 1];
    char batch_number[BATCH_NUMBER_LENGTH + 1];
    struct Medicine *next;
} Medicine;

Medicine *hashTable[TABLE_SIZE] = { NULL };

int generateId() {
    static int id = 1;
    return id++;
}

int hash(int key) {
    return key % TABLE_SIZE;
}

bool isNumeric(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return false;
        }
        str++;
    }
    return true;
}

Medicine *searchMedicine(int id) {
    int index = hash(id);

    Medicine *ptr = hashTable[index];
    while (ptr != NULL) {
        if (ptr->id == id) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

void insertMedicine() {
    Medicine *newMedicine = (Medicine *)malloc(sizeof(Medicine));
    if (newMedicine == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter Medicine Name (between 5 and 50 characters): ");
    fgets(newMedicine->name, MAX_MEDICINE_NAME, stdin);
    strtok(newMedicine->name, "\n");
    while (strlen(newMedicine->name) < MIN_MEDICINE_NAME || strlen(newMedicine->name) > MAX_MEDICINE_NAME) {
        printf("Invalid input! Medicine Name must be between 5 and 50 characters.\n");
        printf("Enter Medicine Name (between 5 and 50 characters): ");
        fgets(newMedicine->name, MAX_MEDICINE_NAME, stdin);
        strtok(newMedicine->name, "\n");
    }

    do {
        printf("Enter Manufacturer Name (between 3 and 25 characters, ending with 'Ltd.'): ");
        fgets(newMedicine->manufacturer, MAX_MANUFACTURER_NAME, stdin);
        strtok(newMedicine->manufacturer, "\n");
        if (strlen(newMedicine->manufacturer) < MIN_MANUFACTURER_NAME || 
            strlen(newMedicine->manufacturer) > MAX_MANUFACTURER_NAME ||
            strncmp(newMedicine->manufacturer + strlen(newMedicine->manufacturer) - 4, "Ltd.", 4) != 0) {
            printf("Invalid input! Manufacturer Name must be between 3 and 25 characters and end with 'Ltd.'!\n");
        }
    } while (strlen(newMedicine->manufacturer) < MIN_MANUFACTURER_NAME || 
             strlen(newMedicine->manufacturer) > MAX_MANUFACTURER_NAME ||
             strncmp(newMedicine->manufacturer + strlen(newMedicine->manufacturer) - 4, "Ltd.", 4) != 0);

    do {
        printf("Enter Registration Number (10 digits): ");
        fgets(newMedicine->registration_number, REGISTRATION_NUMBER_LENGTH + 1, stdin);
        strtok(newMedicine->registration_number, "\n");
        if (strlen(newMedicine->registration_number) != REGISTRATION_NUMBER_LENGTH || !isNumeric(newMedicine->registration_number)) {
            printf("Invalid input! Registration Number must be 10 digits.\n");
        }
    } while (strlen(newMedicine->registration_number) != REGISTRATION_NUMBER_LENGTH || !isNumeric(newMedicine->registration_number));

    do {
        printf("Enter Batch/Lot Number (16 digits): ");
        fgets(newMedicine->batch_number, BATCH_NUMBER_LENGTH + 1, stdin);
        strtok(newMedicine->batch_number, "\n");
        if (strlen(newMedicine->batch_number) != BATCH_NUMBER_LENGTH || !isNumeric(newMedicine->batch_number)) {
            printf("Invalid input! Batch/Lot Number must be 16 digits.\n");
        }
    } while (strlen(newMedicine->batch_number) != BATCH_NUMBER_LENGTH || !isNumeric(newMedicine->batch_number));

    newMedicine->id = generateId();
    int index = hash(newMedicine->id);
    newMedicine->next = hashTable[index];
    hashTable[index] = newMedicine;
    printf("Medicine inserted successfully!\n");
}

void viewMedicine() {
    bool empty = true;
    printf("Medicine ID | Medicine Name | Manufacturer | Registration Number | Batch/Lot Number\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        Medicine *ptr = hashTable[i];
        while (ptr != NULL) {
            printf("%-12d| %-14s| %-13s| %-21s| %-16s\n", ptr->id, ptr->name, ptr->manufacturer, ptr->registration_number, ptr->batch_number);
            ptr = ptr->next;
            empty = false;
        }
    }
    if (empty) {
        printf("There is no medicine(s)!\n");
    }
}

void removeMedicine() {
    int id;
    printf("Enter Medicine ID to remove: ");
    scanf("%d", &id);
    getchar(); 

    Medicine *ptr = searchMedicine(id);
    if (ptr == NULL) {
        printf("Medicine not found!\n");
        return;
    }

    printf("Medicine found:\n");
    printf("Medicine ID | Medicine Name | Manufacturer | Registration Number | Batch/Lot Number\n");
    printf("%-12d| %-14s| %-13s| %-21s| %-16s\n", ptr->id, ptr->name, ptr->manufacturer, ptr->registration_number, ptr->batch_number);

    char choice;
    printf("Are you sure you want to remove this medicine? (y/n): ");
    scanf(" %c", &choice);
    getchar(); 

    if (choice == 'y' || choice == 'Y') {
        int index = hash(ptr->id); 
        Medicine *temp = hashTable[index];
        if (temp == ptr) {
            hashTable[index] = ptr->next;
        } else {
            while (temp->next != ptr) {
                temp = temp->next;
            }
            temp->next = ptr->next;
        }
        free(ptr);
        printf("Medicine removed successfully!\n");
    } else if (choice == 'n' || choice == 'N') {
        printf("Operation canceled.\n");
    } else {
        printf("Invalid choice!\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Sunib Hospital ---\n");
        printf("1. View Medicine\n");
        printf("2. Insert Medicine\n");
        printf("3. Remove Medicine\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                viewMedicine();
                break;
            case 2:
                insertMedicine();
                break;
            case 3:
                removeMedicine();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}

