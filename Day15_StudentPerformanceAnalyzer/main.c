#include<stdio.h>
int main()
{
 int students[10];
 int sum=0;
 float avg;
 int pass=0;
 int fail=0;
 int totalstu;
 int i=0;
 int j=1;
 int A1=0, A=0, B=0, C=0, D=0, F=0;
 int high=0;
 int low=999;

 printf("========= Student Performance Analyzer =========");
 printf("\nEnter total number of students :");
 scanf("%d" ,&totalstu);
 printf("Enter marks for each student :\n");

 for(i=0 ; i < totalstu ; i+=1)
   {
     printf("Student %d :",j); 
     scanf("%d" ,&students[i]);
     j++;
     sum += students[i];

     if( students[i] >= 90 && students[i] <= 100) { A1 += 1; pass += 1; }
     else if( students[i] >= 80) { A += 1; pass += 1;}
     else if( students[i] >= 70) { B += 1; pass += 1;}
     else if( students[i] >= 60) { C += 1; pass += 1;}
     else if( students[i] >= 50) { D += 1; pass += 1;}
     else if( students[i] < 50 && students[i] >= 0) { F += 1; fail += 1;}

     if( students[i] > high) { high = students[i]; }
     if( students[i] < low)  { low = students[i]; }
   }
 
 printf("\n========= Result Summary =========\n");
 avg = (sum/totalstu) ;
 printf("Average Marks: %.2f" ,avg);
 printf("\nHighest Marks: %d" ,high);
 printf("\nLowest  Marks: %d\n" ,low);
 printf("\nTotal Passed Students: %d" ,pass);
 printf("\nTotal Failed Students: %d\n" ,fail);

 printf("\nGrade Distribution:");
 printf("\nA+ : %d", A1);
 printf("\nA  : %d", A);
 printf("\nB  : %d", B);
 printf("\nC  : %d", C);
 printf("\nD  : %d", D);
 printf("\nFail : %d", F);
 printf("\n====================================\n");
 return 0;
}
