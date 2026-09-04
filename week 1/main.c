#include <stdio.h>

int main()
{
    char municipality[50];
    char mayor[50];
    int population;

    // 1 & 2. System Title and Welcome Message
    printf("===========================================\n");
    printf("   Municipal Financial Management System   \n");
    printf("===========================================\n");
    printf("Welcome to Windhoek Municipality\n\n");

    // 3. Prompt user for details
    printf("Enter Municipality Name: ");
    scanf("%49s", municipality);

    printf("Enter Mayor's Name: ");
    scanf("%49s", mayor);

    printf("Enter Population: ");
    scanf("%d", &population);

    // 4. Display formatted report
    printf("\n===========================================\n");
    printf("         MUNICIPALITY SUMMARY REPORT        \n");
    printf("===========================================\n");
    printf("Municipality : %s\n", municipality);
    printf("Mayor        : %s\n", mayor);
    printf("Population   : %d\n", population);
    printf("===========================================\n");

    return 0;
}