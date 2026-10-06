#include <stdio.h>

int main()
{
    char studentName[50];
    float test1;
    float test2;
    float assignment;
    float total;

    // Prompt user for student information
    printf("Enter Student Name: ");
    scanf("%49s", studentName);

    printf("Enter Test 1 Mark: ");
    scanf("%f", &test1);

    printf("Enter Test 2 Mark: ");
    scanf("%f", &test2);

    printf("Enter Assignment Mark: ");
    scanf("%f", &assignment);

    // Calculate Total Mark
    total = test1 + test2 + assignment;

    // Display summary and Grade Evaluation
    printf("\n--- STUDENT RESULT ---\n");
    printf("Student Name: %s\n", studentName);
    printf("Total Mark: %.2f\n", total);

    if (total >= 75.0)
    {
        printf("Result: Distinction\n");
    }
    else if (total >= 60.0)
    {
        printf("Result: Credit\n");
    }
    else if (total >= 50.0)
    {
        printf("Result: Pass\n");
    }
    else
    {
        printf("Result: Fail\n");
    }

    return 0;
}