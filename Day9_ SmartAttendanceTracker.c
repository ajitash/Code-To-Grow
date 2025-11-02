#include <stdio.h>
int main()
{
    int ns,es,ne;//ns=number of students, es=eligible students,ne=not eligible
    float atten,attenPer,avgatten;//atten=attendance,avgatten=average attendance,attenper=attendance percentage
    int i;
    es=0;
    ne=0;
    avgatten=0.0;
    printf("Enter total number of students :");
    scanf("%d",&ns);
    for(i=1;i<=ns;i+=1)    
    {
        printf("\nEnter attendance of student %d (out of 30)",i);
        scanf("%f",&atten);
        attenPer = (atten / 30.0) * 100.0;
        if (attenPer>=75.0 && attenPer<=100.0)
        {
            printf("\nStudent %d:%.2f%% - Eligible",i,attenPer);
            es+=1;
        }
        else
        {
            printf("\nStudent %d:%.2f%% - Not Eligible",i,attenPer);
            ne+=1;
        }
        avgatten+=attenPer;
    }
    printf("\n Class Summary:");
    printf("\nTotal Students: %d",ns);
    printf("\nEligible Students: %d",es);
    printf("\nNot Eligible: %d",ne);
    if (ns > 0)
        printf("\nAverage Attendance: %.2f%%", avgatten / ns);
    else
        printf("\nAverage Attendance: N/A (no students)");
    return 0;
}