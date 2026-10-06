#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    char contact[50];
} Supplier;

void addSupplier(void);
void listSuppliers(void);
void showMenu(void);

void addSupplier(void) {
    printf("\n[Week 9 Stub] Adding supplier in memory...\n");
}

void listSuppliers(void) {
    printf("\n[Week 9 Stub] Listing suppliers in memory...\n");
}

void showMenu(void) {
    printf("\n=== MFMS SYSTEM (WEEK 9) ===\n");
    printf("1. Add Supplier\n");
    printf("2. List Suppliers\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

int main(void) {
    int choice;
    do {
        showMenu();
        if (scanf("%d", &choice) != 1) {
            break;
        }
        switch (choice) {
            case 1:
                addSupplier();
                break;
            case 2:
                listSuppliers();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}