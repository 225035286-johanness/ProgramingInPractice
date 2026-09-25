#include <stdio.h>

#define VAT_RATE 0.15f
#define NUM_EMPLOYEES 5

// --- FUNCTION DECLARATIONS (PROTOTYPES) ---
void displayWelcome(void);
void displayMenu(void);
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, const int ids[], int size);

int main() {
    int employeeIDs[NUM_EMPLOYEES] = {101, 102, 103, 104, 105};
    int choice;

    displayWelcome();

    do {
        displayMenu();
        
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                float amount;
                printf("\nEnter amount: $");
                scanf("%f", &amount);
                printf("VAT (15%%): $%.2f\n", calculateVAT(amount));
                break;
            }

            case 2: {
                float basic, housing, transport;
                printf("\nEnter Basic Salary: $");
                scanf("%f", &basic);
                printf("Enter Housing Allowance: $");
                scanf("%f", &housing);
                printf("Enter Transport Allowance: $");
                scanf("%f", &transport);

                printf("Gross Salary: $%.2f\n", calculateSalary(basic, housing, transport));
                break;
            }

            case 3: {
                float revenue, expenses;
                printf("\nEnter Revenue: $");
                scanf("%f", &revenue);
                printf("Enter Expenses: $");
                scanf("%f", &expenses);

                float balance = calculateBudget(revenue, expenses);
                printf("Budget Balance: $%.2f\n", balance);

                if (balance > 0) {
                    printf("Status: SURPLUS\n");
                } else if (balance < 0) {
                    printf("Status: DEFICIT\n");
                } else {
                    printf("Status: BALANCED\n");
                }
                break;
            }

            case 4: {
                int target_id;
                printf("\nEnter Employee ID to search: ");
                scanf("%d", &target_id);

                int pos = searchEmployee(target_id, employeeIDs, NUM_EMPLOYEES);
                if (pos != -1) {
                    printf("Employee ID %d found at index %d (Position %d).\n", target_id, pos, pos + 1);
                } else {
                    printf("Employee ID %d not found in system.\n", target_id);
                }
                break;
            }

            case 5:
                printf("\nExiting Municipal Financial Management System. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice. Please enter a option between 1 and 5.\n");
        }

    } while (choice != 5);

    return 0;
}

void displayWelcome(void) {
    printf("==================================================\n");
    printf(" Welcome to Municipal Financial Management System \n");
    printf("==================================================\n");
}

void displayMenu(void) {
    printf("\n==================================================\n");
    printf("   MUNICIPAL FINANCIAL MANAGEMENT SYSTEM (MFMS)\n");
    printf("==================================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Gross Salary\n");
    printf("3. Calculate Budget Status\n");
    printf("4. Search Employee ID\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}

float calculateVAT(float amount) {
    return amount * VAT_RATE;
}

float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;
}

int searchEmployee(int id, const int ids[], int size) {
    for (int i = 0; i < size; i++) {
        if (ids[i] == id) {
            return i;
        }
    }
    return -1;
}