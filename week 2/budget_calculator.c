#include <stdio.h>

int main() {
    double revenue = 0.0;
    double expenses = 0.0;
    double balance = 0.0;

    printf("MUNICIPAL BUDGET CALCULATOR\n");
    printf("---------------------------\n");

    printf("Enter Total Revenue: ");
    scanf("%lf", &revenue);

    printf("Enter Total Expenses: ");
    scanf("%lf", &expenses);

    balance = revenue - expenses;

    printf("\n--- FINANCIAL SUMMARY ---\n");
    printf("Revenue:  %.2f\n", revenue);
    printf("Expenses: %.2f\n", expenses);
    printf("Balance:  %.2f\n", balance);

    return 0;
}