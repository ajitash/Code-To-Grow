#include <stdio.h>
int main()
{int nc,ni,ip,q,fb;//nc=number of customers,ni=number of items,ip=item price,q=quantity,fb=feedback
float bill,tr,fbr,fbill;//tr=total revenvue,fbr=feedback rating,fbill=final bill
int i,j;
  printf("Enter number of customers :");
  scanf("%d",&nc);
  for(i=1;i<=nc;i++)
  { printf("\nCustomer %d:\n",i);
    printf("Enter number of items :");
    scanf("%d",&ni);

    for(j=1;j<=ni;j++)
    { printf("Enter item price %d:",j);
      scanf("%d",&ip);
      printf("Enter quantity of item %d:",j);
      scanf("%d",&q);

      bill+=(ip*q);
      fbill=bill+(bill*0.05);
      
    } printf("Enter feedback(1-5):");
      scanf("%d",&fb);
      while(fb<1||fb>5)
      {printf("Invalid feedback. Enter feedback(1-5):");
       scanf("%d",&fb);
      }
      printf("Customer %d Bill: %.2f\n",i,fbill);
      fbr+=fb;
      tr+=fbill;
  }
  printf("\n--- Restaurant Billing Summary ---");
  printf("\nTotal Revenue: %.2f",tr);
  printf("\nAverage Feedback Rating: %.2f",fbr/nc);
  return 0;
}