//Name : M.Naga Ajitesh
//Reg N.o : AP25110090150

//Name : M.Naga Ajitesh
//Reg N.o : AP25110090150

#include <stdio.h>
int main()
{
    int ID[10], quantity[10], price[10], value[10];
    char name[10][55];
    int products, choice, searchID;
    int totalvalue = 0;
    int highest = 0, lowest = 0;
    int i;

    printf("\n========= Inventory Management System =========\n");
    printf("\nEnter number of products: ");
    scanf("%d", &products);
    if (products > 10) { 
        printf("Maximum Allowed 10. Setting products to 10."); 
        products = 10; 
    }

    for (i = 0; i < products; i++)
    {
        printf("Enter product ID for product %d: ", i + 1);
        scanf("%d", &ID[i]);
        printf("Enter product name for product %d: ", i + 1);
        scanf(" %s", name[i]);
        printf("Enter quantity in stock for product %d: ", i + 1);
        scanf("%d", &quantity[i]);
        printf("Enter price per item for product %d: ", i + 1);
        scanf("%d", &price[i]);

        value[i] = quantity[i] * price[i];

        if (value[i] > value[highest]) highest = i;
        if (value[i] < value[lowest]) lowest = i;

        totalvalue += value[i];
    }

    do
    {
        printf("\nInventory Management System Menu:\n");
        printf("1. Display all products\n");
        printf("2. Show total inventory value\n");
        printf("3. Show product with highest and lowest value in stock\n");
        printf("4. Search product by ID\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("\nProduct List:\n");
            for (int i = 0; i < products; i++)
            {
                printf("ID: %d, Name: %s, Quantity: %d, Price: %d\n",
                       ID[i], name[i], quantity[i], price[i]);
            }
        }

        else if (choice == 2)
        {
            printf("Total inventory value: %d\n", totalvalue);
        }

        else if (choice == 3)
        {
            printf("\nProduct with highest value in stock:\n");
            printf("ID: %d, Name: %s, Quantity: %d, Price: %d, Value: %d\n",
                   ID[highest], name[highest], quantity[highest], price[highest], value[highest]);

            printf("Product with lowest value in stock:\n");
            printf("ID: %d, Name: %s, Quantity: %d, Price: %d, Value: %d\n",
                   ID[lowest], name[lowest], quantity[lowest], price[lowest], value[lowest]);
        }

        else if (choice == 4)
        {
            printf("Enter product ID to search: ");
            scanf("%d", &searchID);

            int found = 0;//declared here as it resets found value back to 0 everytime

            for (int i = 0; i < products; i++)
            {
                if (ID[i] == searchID)
                {
                    printf("Product found:\n");
                    printf("ID: %d, Name: %s, Quantity: %d, Price: %d\n",
                           ID[i], name[i], quantity[i], price[i]);
                    found = 1;
                    break; //to break the code to find the product
                }
            }

            if (!found) //if found value is not updated to 1 it prints this code
            {
                printf("Product with ID %d not found.\n", searchID);
            }
        }

        else if (choice == 5)
        {
            printf("Exiting program...\n");
        }

        else
        {
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
