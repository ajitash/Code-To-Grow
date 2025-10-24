#include<stdio.h>
int main()
{
    float uc; // uc=units consumed (used float to consider decimal values)
    float bill;
    printf("Enter total units consumed :");
    scanf("%f",&uc); // print and scan statement to assign value to uc
    if(uc<=100 && uc>=0)//statement for bill when units are from 0 to 100
    {
        bill=(uc*3.00);
    }
    else if(uc<=200)//statement for bill when units are from 101 to 200
    {
        bill=(uc*4.50);
    }
    else if(uc<=300)//statement for bill when units are from 201 to 300
    {
        bill=(uc*6.00);
    }
    else if(uc>300)//statement for bill when units are above 300
    { 
        bill=(uc*8.00);
    }
    else
    {
        printf("invalid Input");
        return 0;
    }
printf("\nElectricity Bill summary :\n");
printf("\nUnits Consumed : %.2f\n",uc);
bill=bill+50.00;  //addinf fixed charge of 50 to the bill
printf("\nTotal Bill(after adding fixed charge of 50) = %.2f\n",bill);
    return 0;
}