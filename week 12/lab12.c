#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 5

typedef struct {
    int id;
    char name[30];
    double salary;
} Employee;

// Task 1: Update salary using pointer arrow notation
void updateSalary(Employee *e, double newSalary) {
    e->salary = newSalary;
}

// Task 2: Find employee and return pointer (or NULL if not found)
Employee *findEmployee(Employee list[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (list[i].id == id) {
            return &list[i]; // Return address of the match
        }
    }
    return NULL;
}

int main(void) {
    Employee staff[MAX_EMPLOYEES] = {
        {1001, "Maria", 18500.50},
        {1002, "Simon", 17200.00},
        {1003, "Anna", 21000.75}
    };
    int count = 3;
    Employee *found;

    printf("--- Week 12: Pointer & Structure Demo ---\n");
    
    found = findEmployee(staff, count, 1002);
    if (found != NULL) {
        printf("Found employee: %s, Current Salary: N$%.2f\n", found->name, found->salary);
        updateSalary(found, 19000.00);
        printf("Updated Salary for %s: N$%.2f\n", found->name, found->salary);
    } else {
        printf("Employee not found.\n");
    }

    return 0;
}