#include <stdio.h>

#define NUM_SALARIES 5
#define NUM_BUDGETS 5

int main() {
    int choice;

    do {
        printf("\n==================================================\n");
        printf("   WEEK 6: MUNICIPAL FINANCIAL MANAGEMENT (ARRAYS)\n");
        printf("==================================================\n");
        printf("1. Employee Salary Analytics (Min, Max, Avg)\n");
        printf("2. Linear Salary Search\n");
        printf("3. Department Budget Bubble Sort\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: { // TASK 1: ARRAY CAPTURE & ANALYTICS
                float salaries[NUM_SALARIES];
                float total = 0.0f;

                printf("\nEnter %d employee salaries:\n", NUM_SALARIES);
                for (int i = 0; i < NUM_SALARIES; i++) {
                    printf("Salary %d: $", i + 1);
                    scanf("%f", &salaries[i]);
                    total += salaries[i];
                }

                float high = salaries[0], low = salaries[0];
                for (int i = 1; i < NUM_SALARIES; i++) {
                    if (salaries[i] > high) high = salaries[i];
                    if (salaries[i] < low)  low = salaries[i];
                }

                printf("\n--- SALARY ANALYTICS ---\n");
                printf("Total: $%.2f | Average: $%.2f\n", total, total / NUM_SALARIES);
                printf("Highest: $%.2f | Lowest: $%.2f\n", high, low);
                break;
            }

            case 2: { // TASK 2: LINEAR SEARCH
                float salaries[NUM_SALARIES];
                float search;
                int found = 0;

                printf("\nEnter %d salaries:\n", NUM_SALARIES);
                for (int i = 0; i < NUM_SALARIES; i++) {
                    printf("Salary %d: $", i + 1);
                    scanf("%f", &salaries[i]);
                }

                printf("\nEnter salary to search: $");
                scanf("%f", &search);

                for (int i = 0; i < NUM_SALARIES; i++) {
                    if (salaries[i] == search) {
                        printf("Found $%.2f at index %d (Employee %d)\n", search, i, i + 1);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Salary $%.2f not found.\n", search);
                break;
            }

            case 3: { // TASK 3: BUBBLE SORT
                float budgets[NUM_BUDGETS];

                printf("\nEnter %d department budgets:\n", NUM_BUDGETS);
                for (int i = 0; i < NUM_BUDGETS; i++) {
                    printf("Budget %d: $", i + 1);
                    scanf("%f", &budgets[i]);
                }

                // Bubble Sort algorithm
                for (int i = 0; i < NUM_BUDGETS - 1; i++) {
                    for (int j = 0; j < NUM_BUDGETS - i - 1; j++) {
                        if (budgets[j] > budgets[j + 1]) {
                            float temp = budgets[j];
                            budgets[j] = budgets[j + 1];
                            budgets[j + 1] = temp;
                        }
                    }
                }

                printf("\n--- BUDGETS SORTED (LOWEST TO HIGHEST) ---\n");
                for (int i = 0; i < NUM_BUDGETS; i++) {
                    printf("  %d. $%.2f\n", i + 1, budgets[i]);
                }
                break;
            }

            case 4:
                printf("\nExiting Week 6 Module.\n");
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}