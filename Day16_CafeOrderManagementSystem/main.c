#include<stdio.h>
int main()
{
    int customers, items, quantity, TB = 0, TR = 0, Titems = 0, itemno; // TB=total bill, TR=total revenue
    int itemp[6], quantitys[6] = {0}; // corrected array size & initialized
    int most=1, least=999;
    int i = 0;
    int j = 0;
    int k = 0;

    printf("\n========= Cafe Order Management System =========\n");
    printf("Enter total number of customers : ");
    scanf("%d", &customers);

    for(i = 1; i <= customers; i++)
    {
        // Menu initialization for each customer
        printf("\n========= Menu =========\n");
        itemp[0] = 0;
        printf("1. Coffee      Rs.50\n");   itemp[1] = 50;
        printf("2. Tea         Rs.30\n");   itemp[2] = 30;
        printf("3. Sandwich    Rs.80\n");   itemp[3] = 80;
        printf("4. Burger      Rs.120\n");  itemp[4] = 120;
        printf("5. Pastry      Rs.60\n");   itemp[5] = 60;

        printf("\n--- Customer %d ---\n", i);
        printf("Enter number of items : ");
        scanf("%d", &items);

        TB = 0; // reset total bill for each customer
        printf("Enter item number and quantity :\n");

        for(j = 0; j < items; j++)
        {
            scanf("%d%d", &itemno, &quantity);
            if(itemno >= 1 && itemno <= 5)
            {
                TB += itemp[itemno] * quantity;

                if(itemno == 1) { quantitys[1] += quantity; }
                if(itemno == 2) { quantitys[2] += quantity; }
                if(itemno == 3) { quantitys[3] += quantity; }
                if(itemno == 4) { quantitys[4] += quantity; }
                if(itemno == 5) { quantitys[5] += quantity; }

                Titems += quantity;
            }
            else
            {
                printf("Invalid item number! Try again.\n");
                j--;
            }
        }

        printf("Total Bill for customer %d: Rs.%d\n", i, TB);
        TR += TB;
    }

    // Find most and least sold items
    for(k = 2; k <= 5; k++)
    {
        if(quantitys[k] > most) {most = k;}
        if(quantitys[k] < least) {least = k;}
    }

    printf("\n========= Cafe Summary =========\n");
    printf("Total Revenue: Rs.%d\n", TR);
    printf("Total Items Sold: %d\n", Titems);
    printf("Most Sold Item: %d \n", most);
    printf("Least Sold Item: %d \n", least);
    printf("====================================\n");

    return 0;
}
