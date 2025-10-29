#include <stdio.h>
int main()
{int plan,data,cost,ed,ss,cs; //ss=student status, cs=corporate status, ed=extra data
 float total,fb;
    printf("Enter total data used (in GB) :");
    scanf("%d",&data);
    printf("Are you a student (1-yes/0-no) :");
    scanf("%d",&ss);
    printf("Are you a corporate user? (1-yes/0-no) :");
    scanf("%d",&cs);

    printf("\nUser Plan Summary :\n");
    printf("Data Used: %d GB",data);

    if (data<30 && data>=0)//to decide the plan and its cost using data used
    { plan=1;
      cost=299;}
      else if(data>=30 && data<=60)
      { plan=2;
        cost=499;}
        else if(data>60 && data<=100)
        { plan=3;
          cost=799;}
          else
          { printf("\nExcessive Usage-Plan Not Allowed");}
    
    
    if(plan==1) //naming the plan and cost of plan based of plan numebr 
    { printf("\nSelected Plan :Silver");
      printf("\nBase Cost : Rs %d",cost);}
      else if(plan==2)
      { printf("\nSelected Plan :Gold");
        printf("\nBase Cost : Rs %d",cost);}
        else if(plan==3)
        { printf("\nSelected Plan :Platinum");
          printf("\nBase cost : Rs %d",cost);}
          else {return 0;}
    
    if(data>60 && data<=100)//to calculate extra data cost
    { ed=data-60;
      total=cost+(ed*30);
      printf("\nExtra Data: %d GB",ed);}
      else
      { ed=0;
        total=cost+(ed);
        printf("\nExtra Data: %d GB",ed);}

    printf("\nTotal Cost (before discount): Rs %.2f",total);
    
    if (ss==1) //to apply discount for student and corporate users
    { fb=total*0.85;
      printf("\nDiscount Applied: 15%%");}
      else if(cs==1)
      { fb=total*0.90;
        printf("\nDiscount Applied: 10%%");}
        else
        {fb=total;
        printf("\nDiscount Applied: 0%%");}

    printf("\nFinal Bill: Rs%.2f",fb);
    return 0;
}