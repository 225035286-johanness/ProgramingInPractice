#include <stdio.h>

int main() {
    int choice;

    do {
        printf("\n==================================================\n");
        printf("   WEEK 5: MUNICIPAL FINANCIAL MANAGEMENT (LOOPS)\n");
        printf("==================================================\n");
        printf("1. Process Employee Salaries (For Loop)\n");
        printf("2. Calculate Department Expenses (While Loop)\n");
        printf("3. Search Salary Record\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // clear buffer
            continue;
        }

        switch (choice) {
            case 1: { // SALARY ITERATION (FOR LOOP)
                int count;
                float salary, total = 0.0f;

                printf("\nEnter number of employees: ");
                scanf("%d", &count);

                for (int i = 1; i <= count; i++) {
                    printf("Enter salary for employee %d: $", i);
                    scanf("%f", &salary);
                    total += salary;
                }

                printf("\nTotal Salaries: $%.2f\n", total);
                if (count > 0) {
                    printf("Average Salary: $%.2f\n", total / count);
                }
                break;
            }

            case 2: { // EXPENSE CALCULATION (WHILE LOOP)
                float expense = 0.0f, total_expense = 0.0f;
                int count = 0;

                printf("\nEnter department expenses (-1 to finish):\n");
                while (1) {
                    printf("Expense %d: $", count + 1);
                    scanf("%f", &expense);
                    if (expense == -1.0f) break;
                    total_expense += expense;
                    count++;
                }

                printf("\nTotal Department Expenses: $%.2f across %d entries.\n", total_expense, count);
                break;
            }

            case 3: { // SALARY SEARCH
                float target, current;
                int found = 0, num_records;

                printf("\nEnter total salary records to check: ");
                scanf("%d", &num_records);
                printf("Enter target salary to search: $");
                scanf("%f", &target);

                for (int i = 1; i <= num_records; i++) {
                    printf("Record %d salary: $", i);
                    scanf("%f", &current);
                    if (current == target) {
                        printf("-> Match found at record %d!\n", i);
                        found = 1;
                        break;
                    }
                }

                if (!found) printf("Salary $%.2f not found.\n", target);
                break;
            }

            case 4:
                printf("\nExiting Week 5 Module.\n");
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}