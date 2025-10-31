#include<stdio.h>
int main()
{
    int bal,dm,wm,n,bonus;//bal=balance, dm=deposite money, wm=withdraw money, n=choice
    bal=10000.00; //initial balance
    do 
    {
        printf("\n1. Deposite Money");//menu display
        printf("\n2. Withdraw Money");
        printf("\n3. Check Balance");
        printf("\n4. Exit");
        printf("\nEnter your choice :");
        scanf("%d",&n);
        if(n==1)//for deposite money
        { printf("\nEnter amount to deposite: ");
          scanf("%d",&dm);
          bal=bal+dm;
          if (dm>25000)
            { bonus=dm*0.01;//for 1% bonus
              bal=bal+bonus;
              printf("Bonus of Rs %d added!",bonus);}
          printf("\nservice charge of 5Rs applied");//service charge
          bal=bal-5;
          printf("\nUpdated Balance: Rs %d\n",bal);}
        if(n==2)//for withdraw money
        { printf("\nEnter amount to withdraw:");
          scanf("%d",&wm);
          if(wm>bal)
          { printf("Insufficient Balance\n");}//for insufficient balalnce if you try to withdraw more than the balance
         else
         { bal=bal-wm;
           printf("\nservice charge of 5Rs applied");//service charge
           bal=bal-5;
           printf("\nUpdated Balance: Rs %d",bal);}}
        if(n==3)//to check balance
        { printf("\ncurrent Balance: Rs %d\n",bal);}
    }while(n!=4);
     printf("\nThank you for banking with us!");//exit statement
     return 0;
}

