#include<stdio.h>
int main() 
{
    char name[50];
    char regnum[20];
    char section;
    int employeenum, choice, aboveavg, belowavg;
    int total = 0, high = 0, low = 999999999;
    float avg = 0.00;
    int salary[10];
    int i, j;

    printf("\n========= Employee Salary Analysis System =========\n");
    printf("\nEnter Student Name :");
    scanf("%s", name);
    printf("Enter Registration Number :");
    scanf("%s", regnum);
    printf("Enter Section :");
    scanf(" %c", &section); 

    printf("\nEnter Number of emoloyees :");
    scanf("%d", &employeenum);

    for(i = 0; i < employeenum; i++) {
        printf("Enter salary of employee %d: ", i + 1);
        scanf("%d", &salary[i]);
    }

    do
    {
        printf("\n========= Menu =========\n");
        printf("1. Display All Salaries\n2. Display Total and Average Salary\n3. Display Highest and Lowest Salary");
        printf("\n4. Count Above/Below Average\n5. Display Sorted Salaries\n6. Exit");
        printf("\n===========================\n");
        printf("Enter your Choice :");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("\nSalaries :");
            for (j = 0; j < employeenum; j++) {
                printf("\n%d. %d", j + 1, salary[j]);
            }
        }
        else if(choice == 2)
        {
            total = 0;
            for (j = 0; j < employeenum; j++) 
            { 
                total += salary[j];
            }
            avg = (float)total / employeenum;
            printf("\nTotal Salary: %d\nAverage Salary: %.2f", total, avg);
        }
        else if(choice == 3)
        {
            high = salary[0];
            low = salary[0];
            for(j = 1; j < employeenum; j++)
            {
                if(salary[j] > high) high = salary[j];
                if(salary[j] < low) low = salary[j];
            }
            printf("\nHighest Salary: %d\nLowest Salary: %d", high, low);
        }
        else if(choice == 4)
        {
            total = 0;
            for(i = 0; i < employeenum; i++){total += salary[i];}
            avg = (float)total / employeenum;
            aboveavg = belowavg = 0;
            for(i = 0; i < employeenum; i++) 
            {
                if (salary[i] > avg) aboveavg++;
                else if (salary[i] < avg) belowavg++;
            }
            printf("\nEmployees Above Average: %d\nEmployees Below Average: %d", aboveavg, belowavg);
        }
        else if(choice == 5)
        {
            for(i = 0; i < employeenum - 1; i++) //takes value from 0 to employeenum - 1
            {
                for(j = i + 1; j < employeenum; j++) // takes value from 1 to employee num
                {
                    if(salary[i] > salary[j]) //compares values of employee 0,1 ; 1,2 etc
                    {
                        int temp = salary[i];  //these 3 statements sort the salaries in the acending order
                        salary[i] = salary[j];
                        salary[j] = temp;
                    }
                }
            }
            printf("\nSorted Salaries :");
            for (j = 0; j < employeenum; j++) {
                printf("\n%d. %d", j + 1, salary[j]);
            }
        }
        else if (choice > 6 || choice <= 0)
        {
            printf("\nInvalid choice \n");
        }
    } while (choice != 6);

    printf("\nExited program\n\nSubmited by: %s\nReg n.o: %s\nSection: %c\n\nCode written by M.Naga Ajiesh \nRegistration number: AP25110090150 \nSection: C\nChallenge Day 17 - Code2Grow Program",name ,regnum, section);
    return 0;
}
