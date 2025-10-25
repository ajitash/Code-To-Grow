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
    if (atten<75)
    {
        printf("\nFinal grade = F\n");
        printf("Remarks = Fail\n");
    }
    if(tp<=49 && tp>=45)
    {
        if (atten>=90)
        {
            tp=tp+5/5;
        }
    }
     printf("\nTotal percentage = %.2f\n",tp);
     printf("Attendance percentage = %.2f\n",atten);
    if (atten>=75)
    {
    if(tp>=90 && tp<=100)
    {
        printf("Final grade = A+\n");
        printf("Remarks = Exellent\n");
    }
    else if(tp>=80 && tp<90)
    {
        printf("Final grade = A\n");
        printf("Remarks = Very Good\n");
    }
    else if(tp>=70 && tp<80)
    {
        printf("Final grade = B\n");
        printf("Remarks = Good\n");
    }
    else if(tp>=60 && tp<70)
    {
        printf("Final grade = C\n");
        printf("Remarks = Average\n");
    }
    else if(tp>=50 && tp<60)
    {
        printf("Final grade = D\n");
        printf("Remarks = Pass\n");
    }
    else if(tp<50 && tp>=0)
    {
        printf("Final grade =F\n");
        printf("Remarks = Fail\n");
    }
    else
    {
        printf("invalid input\n");
    }
    return 0;
}}