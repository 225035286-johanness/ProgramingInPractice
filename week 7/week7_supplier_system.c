#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 5
#define STR_LEN 100

void strip_newline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

int main() {
    char names[MAX_SUPPLIERS][STR_LEN];
    char emails[MAX_SUPPLIERS][STR_LEN];
    char phones[MAX_SUPPLIERS][30];
    char towns[MAX_SUPPLIERS][50];
    int count = 0, choice;

    do {
        printf("\n==================================================\n");
        printf("  WEEK 7: SUPPLIER MANAGEMENT SYSTEM (STRINGS)\n");
        printf("==================================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display All Suppliers\n");
        printf("3. Search Supplier by Name (strcmp)\n");
        printf("4. Show Name Lengths (strlen)\n");
        printf("5. Construct Descriptions (strcpy & strcat)\n");
        printf("6. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n'); // clear newline

        switch (choice) {
            case 1: { // TASK 1 & CHALLENGE
                if (count >= MAX_SUPPLIERS) {
                    printf("\nSystem full (%d/%d).\n", MAX_SUPPLIERS, MAX_SUPPLIERS);
                    break;
                }
                printf("\n--- ADD SUPPLIER %d ---\n", count + 1);

                printf("Enter name: ");
                fgets(names[count], sizeof(names[count]), stdin);
                strip_newline(names[count]);

                printf("Enter email: ");
                fgets(emails[count], sizeof(emails[count]), stdin);
                strip_newline(emails[count]);

                printf("Enter phone: ");
                fgets(phones[count], sizeof(phones[count]), stdin);
                strip_newline(phones[count]);

                printf("Enter town: ");
                fgets(towns[count], sizeof(towns[count]), stdin);
                strip_newline(towns[count]);

                count++;
                printf("Supplier saved successfully!\n");
                break;
            }

            case 2: { // DISPLAY SUPPLIERS
                if (count == 0) {
                    printf("\nNo suppliers recorded yet.\n");
                    break;
                }
                printf("\n--- SUPPLIER LIST ---\n");
                for (int i = 0; i < count; i++) {
                    printf("%d. %s | %s | %s | %s\n", i + 1, names[i], emails[i], phones[i], towns[i]);
                }
                break;
            }

            case 3: { // TASK 3: SEARCH
                if (count == 0) {
                    printf("\nNo suppliers recorded yet.\n");
                    break;
                }
                char search[STR_LEN];
                int found = 0;

                printf("\nEnter supplier name to search: ");
                fgets(search, sizeof(search), stdin);
                strip_newline(search);

                for (int i = 0; i < count; i++) {
                    if (strcmp(names[i], search) == 0) {
                        printf("\n[MATCH FOUND] Name: %s | Email: %s | Phone: %s | Town: %s\n",
                               names[i], emails[i], phones[i], towns[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Supplier '%s' not found.\n", search);
                break;
            }

            case 4: { // TASK 2: STRLEN
                if (count == 0) {
                    printf("\nNo suppliers recorded yet.\n");
                    break;
                }
                printf("\n--- SUPPLIER NAME LENGTHS ---\n");
                for (int i = 0; i < count; i++) {
                    printf("'%s' -> %zu characters\n", names[i], strlen(names[i]));
                }
                break;
            }

            case 5: { // TASKS 4 & 5: STRCPY & STRCAT
                if (count == 0) {
                    printf("\nNo suppliers recorded yet.\n");
                    break;
                }
                printf("\n--- SUPPLIER DESCRIPTIONS ---\n");
                for (int i = 0; i < count; i++) {
                    char sentence[STR_LEN * 2];
                    strcpy(sentence, names[i]);
                    strcat(sentence, " operates in ");
                    strcat(sentence, towns[i]);
                    strcat(sentence, ".");
                    printf("%s\n", sentence);
                }
                break;
            }

            case 6:
                printf("\nExiting Week 7 Module.\n");
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
        }

    } while (choice != 6);

    return 0;
}