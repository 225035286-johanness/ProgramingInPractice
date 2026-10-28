#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int id;
    char name[30];
    char department[20];
    double salary;
} Employee;

void displayEmployee(Employee e) {
    printf("ID: %d | Name: %s | Dept: %s | Salary: N$%.2f\n", e.id, e.name, e.department, e.salary);
}

int main(void) {
    Employee employees[MAX_RECORDS];
    int employeeCount = 0;
    char filename[] = "employees.dat";
    FILE *file;

    employees[employeeCount].id = 1001;
    strcpy(employees[employeeCount].name, "Maria");
    strcpy(employees[employeeCount].department, "Finance");
    employees[employeeCount].salary = 18500.50;
    employeeCount++;

    employees[employeeCount].id = 1002;
    strcpy(employees[employeeCount].name, "Simon");
    strcpy(employees[employeeCount].department, "IT");
    employees[employeeCount].salary = 17200.00;
    employeeCount++;

    printf("--- Week 11: Displaying Employees ---\n");
    for (int i = 0; i < employeeCount; i++) {
        displayEmployee(employees[i]);
    }

    file = fopen(filename, "wb");
    if (file != NULL) {
        fwrite(&employeeCount, sizeof(int), 1, file);
        fwrite(employees, sizeof(Employee), employeeCount, file);
        fclose(file);
        printf("Successfully saved records to %s\n", filename);
    }

    return 0;
}