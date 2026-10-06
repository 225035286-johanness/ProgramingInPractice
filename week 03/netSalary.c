#include <stdio.h>

int main()
{
    float basicSalary;
    float housing;
    float transport;
    float tax;
    float grossSalary;
    float netSalary;

    // Prompt user for input
    printf("Enter basic salary: ");
    scanf("%f", &basicSalary);

    printf("Enter housing allowance: ");
    scanf("%f", &housing);

    printf("Enter transport allowance: ");
    scanf("%f", &transport);

    printf("Enter tax: ");
    scanf("%f", &tax);

    // Calculate Gross and Net Salary
    grossSalary = basicSalary + housing + transport;
    netSalary = grossSalary - tax;

    // Display results
    printf("\n--- SALARY DETAILS ---\n");
    printf("Gross Salary: NAD %.2f\n", grossSalary);
    printf("Net Salary: NAD %.2f\n", netSalary);

    // Income Classification
    if (netSalary >= 20000.0)
    {
        printf("Income Status: High Income\n");
    }
    else
    {
        printf("Income Status: Standard Income\n");
    }

    return 0;
}