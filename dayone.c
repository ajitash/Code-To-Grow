#include<stdio.h>
int main()
{float bs,da,hra,tax,gs;
    printf("\nEnter basic salary :");
    scanf("%f",&bs);
    printf("\nEnter HRA :");
    scanf("%f",&hra);
    printf("\nEnter DA :");
    scanf("%f",&da);
    printf("\nEnter TAX :");
    scanf("%f",&tax);
    hra=bs*(hra/100);
    da=bs*(da/100);
    tax=bs*(tax/100);
    gs=bs+hra+da-tax;
    printf("\nHRA = %.2f\n",hra);
    printf("\nDA = %.2f\n",da);
    printf("\nTAX = %.2f\n",tax);

    int a;
    a=gs>50000;
    printf("\nif gross salary is above 50000 : %d",a);
    return 0;
}