#include <stdio.h>
#include <string.h>
struct EMPLOYEE {
    char name[50];
    char designation[50];
    char gender[10];
    char doj[15];
    float salary;
};
int main() {
    int n, i, maleCount = 0, femaleCount = 0;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    struct EMPLOYEE emp[n];
    for(i = 0; i < n; i++) {
        printf("\nEmployee %d details:\n", i + 1);
        printf("Name: "); 
        scanf("%s", emp[i].name);
        printf("Designation: "); 
        scanf("%s", emp[i].designation);
        printf("Gender (Male/Female): "); 
        scanf("%s", emp[i].gender);
        printf("Date of Joining (DD-MM-YYYY): "); 
        scanf("%s", emp[i].doj);
        printf("Salary: "); 
        scanf("%f", &emp[i].salary);
        if(strcmp(emp[i].gender, "Male") == 0) 
        maleCount++;
        else if(strcmp(emp[i].gender, "Female") == 0) 
        femaleCount++;
    }
    printf("\nTotal number of employees = %d", n);
    printf("\nMale Employees = %d", maleCount);
    printf("\nFemale Employees = %d", femaleCount);
    printf("\nEmployees with salary more than 10000: ");
    for(i = 0; i < n; i++) {
        if(emp[i].salary > 10000)
        printf("%s ", emp[i].name);
    }
    printf("\nEmployees with designation AsstManager: ");
    for(i = 0; i < n; i++) {
        if(strcmp(emp[i].designation, "AsstManager") == 0) 
        printf("%s ", emp[i].name);
    }
    printf("\n");
    return 0;
}
