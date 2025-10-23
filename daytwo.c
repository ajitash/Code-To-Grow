#include <stdio.h>
int main()
{
    float mc,tax,tip,tb,p1,p2,p3;

    printf("Enter cost of meal :");
    scanf("%f",&mc);
    tax=mc*0.05;
    tip=mc*0.1;
    tb=mc+tax+tip;
    p1=tb/2;
    p2=tb/2;
    p3=0;
    printf("\nTotal bill = %.3f\n",tb);
    printf("\nEach person should pay as follows : \n");
    printf("\nperson 1 = %.3f\n",p1);
    printf("\nperson 2 = %.3f\n",p2);
    printf("\nperson 3 = %.3f\n",p3);
    return 0;
}