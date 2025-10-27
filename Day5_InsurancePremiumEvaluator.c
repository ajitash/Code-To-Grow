#include <stdio.h>
int main()
{
    int age,Health;
    int gender;
    printf("\nEnter youe age :");//assinging values for age,gender,Health
    scanf("%d",&age);
    printf("Enter your Gender(1-F/0-M) :");
    scanf("%d",&gender);
    printf("Enter your Health (1-Healthy/0-Unhealthy) : ");
    scanf("%d",&Health);
    
    printf("\nCoustomer Details :");
    printf("\nAge : %d",age);

    if (gender==1)//to translate genger input 0/1 to M/F
    {printf("\nGender : F");}
    else if (gender==0)
    {printf("\nGender : M");}
    else {printf("\nInvalid Gender");}

    if (Health==1) //print statement for Health
    {printf("\nHealth : Healthy");}
    else if (Health==0)
    {printf("\nHealth : Unhealthy");}
    else {printf("\nHealth : Invalid Input");}

    float pre; //statements for permium calculation
    if (Health==1)//statements for a healthy person
    {
     if (age<25 && age>0)
     { pre=5000;}
     else if (age>=25 && age<=40)
     { pre=7000;}
     else if (age>40 && age<=60)
     { pre=10000;}
     else if (age>60)
     {pre=15000;}
     else {printf("\nInvalid  Age");}
    }
    else if (Health==0)//statements for an unhealthy person
    {
        if (age<25 && age>0)
     { printf("\nnot eligile for insurance");}
     else if (age>=25 && age<=40)
     { pre=9500;}
     else if (age>40 && age<=60)
     { pre=13000;}
     else if (age>60)
     {printf("\nStatus :Not eligible for insurance");}
     else {printf("\nInvalid  Age");}
    }
    if (gender==0)//statement to add 10% discount for Female
    {printf("\nFinal Premium : %.2f",pre);}
    else if(gender==1)
    {printf("\nFinal Premium: %.2f",pre-(pre*0.10));}
    else {printf("\nInvalid Gender to calculate final premium");}
    return 0;
}
