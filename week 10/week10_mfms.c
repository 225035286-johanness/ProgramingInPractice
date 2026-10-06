#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    char contact[50];
} Supplier;

void addSupplier(void);
void listSuppliersText(void);
void saveSupplierBinary(const Supplier *s);
void listSuppliersBinary(void);
void showMenu(void);

void saveSupplierBinary(const Supplier *s) {
    FILE *fp = fopen("suppliers.dat", "ab");
    if (fp == NULL) {
        perror("suppliers.dat");
        return;
    }
    fwrite(s, sizeof(Supplier), 1, fp);
    fclose(fp);
}

void addSupplier(void) {
    Supplier s;
    printf("\nEnter Supplier ID: ");
    scanf("%d", &s.id);
    printf("Enter Supplier Name: ");
    scanf("%49s", s.name);
    printf("Enter Contact Info: ");
    scanf("%49s", s.contact);

    FILE *fp = fopen("suppliers.txt", "a");
    if (fp == NULL) {
        perror("suppliers.txt");
        return;
    }
    fprintf(fp, "%d|%s|%s\n", s.id, s.name, s.contact);
    fclose(fp);
    printf("-> Saved to text file (suppliers.txt)\n");

    saveSupplierBinary(&s);
    printf("-> Saved to binary file (suppliers.dat)\n");
}

void listSuppliersText(void) {
    FILE *fp = fopen("suppliers.txt", "r");
    if (fp == NULL) {
        perror("suppliers.txt");
        return;
    }

    Supplier s;
    printf("\n--- SUPPLIERS (TEXT FILE: suppliers.txt) ---\n");
    while (fscanf(fp, "%d|%49[^|]|%49s\n", &s.id, s.name, s.contact) == 3) {
        printf("ID: %d | Name: %s | Contact: %s\n", s.id, s.name, s.contact);
    }
    fclose(fp);
}

void listSuppliersBinary(void) {
    FILE *fp = fopen("suppliers.dat", "rb");
    if (fp == NULL) {
        perror("suppliers.dat");
        return;
    }

    Supplier s;
    printf("\n--- SUPPLIERS (BINARY FILE: suppliers.dat) ---\n");
    while (fread(&s, sizeof(Supplier), 1, fp) == 1) {
        printf("ID: %d | Name: %s | Contact: %s\n", s.id, s.name, s.contact);
    }
    fclose(fp);
}

void showMenu(void) {
    printf("\n=== MFMS SYSTEM (WEEK 10 FILE HANDLING) ===\n");
    printf("1. Add Supplier (Saves Text & Binary)\n");
    printf("2. Read Suppliers from Text File\n");
    printf("3. Read Suppliers from Binary File\n");
    printf("4. Exit\n");
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
                listSuppliersText();
                break;
            case 3:
                listSuppliersBinary();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}