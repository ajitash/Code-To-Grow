#include <stdio.h>
int main()
{
    int a,b,c,d,e;
    float atten,tp;//tp=total percentage //atten=attendance
    char grade,remark;
    printf("\nEnter marks of 5 subjects :");
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    printf("\nEnter attendance percentage :");
    scanf("%f",&atten);
    tp=(a+b+c+d+e)/5;
    if (atten<75) //for putting that condition of below 75% attendance to fail directly
    {
        printf("\nFinal grade = F\n");
        printf("Remarks = Fail\n");
    }
    if(tp<=49 && tp>=45) //to add grace marks +5 if the tp is 45 to 49 and attendance is above 90%
    {
        if (atten>=90)
        {
            tp=tp+5/5;
        }
    }
     printf("\nTotal percentage = %.2f\n",tp); //printing total percentage and attendance
     printf("Attendance percentage = %.2f\n",atten);
    if (atten>=75)
    {
    if(tp>=90 && tp<=100) //printing final grades and remarks
    {
        printf("\nFinal grade = A+\n");
        printf("Remarks = Exellent\n");
    }
    else if(tp>=80 && tp<90)
    {
        printf("\nFinal grade = A\n");
        printf("Remarks = Very Good\n");
    }
    else if(tp>=70 && tp<80)
    {
        printf("\nFinal grade = B\n");
        printf("Remarks = Good\n");
    }
    else if(tp>=60 && tp<70)
    {
        printf("\nFinal grade = C\n");
        printf("Remarks = Average\n");
    }
    else if(tp>=50 && tp<60)
    {
        printf("\nFinal grade = D\n");
        printf("Remarks = Pass\n");
    }
    else if(tp<50 && tp>=0)
    {
        printf("\nFinal grade =F\n");
        printf("Remarks = Fail\n");
    }
    else
    {
        printf("\ninvalid input\n");
    }
    return 0;
}}