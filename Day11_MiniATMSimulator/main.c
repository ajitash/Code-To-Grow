#include <stdio.h>
int main()
{
    int bal,choice,amount,trans;//bal=balance,trans=transactions
    bal=10000;
    trans=0;
     printf("\n=========Mini ATM Simulator=========\nInitial Balance: %d\n",bal);
    do
    {
        printf("\n1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nYour Current Balance: Rs.%d\n",bal);
                //no transaction count increase for balance check
                break;
            case 2:
                printf("\nEnter amount to deposit: ");
                scanf("%d", &amount);
                bal += amount;
                printf("Amount deposited successfully\n");
                trans++;
                break;
            case 3:
                printf("Enter amount to withdraw:");
                scanf("%d", &amount);
                if(amount>bal)
                {
                    printf("Insufficient balance\n");
                }
                else
                {
                    bal -= amount;
                    printf("Withdrawal successful!\n Remaining Balance: Rs.%d\n",bal);
                    trans++;
                }
                break;
            case 4:
                printf("Thank you for banking with us!\n");
                break;
        }
    }while (trans<5 && choice!=4);
    printf("\n=========Transaction Summary=========\n");
    printf("Total Transactions: %d",trans);
    printf("\nFinal Balance: Rs.%d\nSession Ended.\n",bal);
    return 0;
}
