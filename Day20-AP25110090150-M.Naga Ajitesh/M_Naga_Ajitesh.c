//Name: M.Naga Ajitesh
//Rg n.o: AP25110090150

#include <stdio.h>

int main() {
    int ids[20];
    int stocks[20];
    int prices[20];
    char names[20][31];
    int count;
    int choice;
    int a, b, c, d, e, f, g, h;
    int q[4][4];
    int max, min, m, k, tni, n, j;

    printf("Enter number of products (1 - 20) : ");
    scanf("%d", &count);
    while(count < 1 || count > 20) {
        printf("Enter a number between 1 and 20: ");
        scanf("%d", &count);
    }

    for(a = 0; a < count; a = a + 1) {
        printf("\n===== Enter details for Product #%d =====\n", a + 1);
        printf("Product Name: ");
        scanf("%30s", names[a]);
        printf("Product ID: ");
        scanf("%d", &ids[a]);
        printf("Product Stock: ");
        scanf("%d", &stocks[a]);
        printf("Product Price: ");
        scanf("%d", &prices[a]);
    }

    do {
        printf("\n===== Warehouse Menu =====\n");
        printf("1. Search Product (by ID)\n");
        printf("2. Update Stock\n");
        printf("3. Rack Report\n");
        printf("4. Report: Value\n");
        printf("5. Show All Products\n");
        printf("6. Exit\n");
        printf("=============================\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1: 
            {
                printf("Enter Product ID to search for: ");
                scanf("%d", &a);
                d = -1;
                for(b = 0; b < count; b = b + 1) 
                {
                    if(ids[b] == a) 
                    {
                        d = b;
                    }
                }
                if(d == -1) 
                {
                    printf("Sorry, this Product ID was not found.\n");
                } 
                else 
                {
                    printf("RESULT: Name: %s | ID: %d | Stock: %d | Price: %d\n", names[d], ids[d], stocks[d], prices[d]);
                }
                break;
            }
            case 2: 
            {
                printf("Enter Product ID to update: ");
                scanf("%d", &a);
                d = -1;
                for(b = 0; b < count; b = b + 1) 
                {
                    if(ids[b] == a) 
                    {
                        d = b;
                    }
                }
                if(d == -1) 
                {
                    printf("Sorry, this Product ID was not found.\n");
                    break;
                }
                printf("Type 1 to Increase Stock or 2 to Decrease Stock: ");
                scanf("%d", &e);
                printf("Enter how much to change the stock: ");
                scanf("%d", &f);
                if(f <= 0) 
                {
                    printf("The amount should be greater than zero.\n");
                    break;
                }
                if(e == 1) 
                {
                    stocks[d] = stocks[d] + f;
                    printf("Increased successfully. New stock: %d\n", stocks[d]);
                } else if(e == 2) {
                    if(stocks[d] < f) 
                    {
                        printf("Error: Cannot reduce below zero!\n");
                    } else {
                        stocks[d] = stocks[d] - f;
                        printf("Decreased successfully. New stock: %d\n", stocks[d]);
                    }
                } 
                else 
                {
                    printf("Please enter only 1 (increase) or 2 (decrease).\n");
                }
                break;
            }
            case 3: 
            {
                n = 3;
                tni = 0;
                printf("Enter rack diagonal (q[j][j]) values for j = 1 to %d:\n", n);
                for(j = 1; j <= n; j = j + 1) 
                {
                    for(b = 1; b <= n; b = b + 1) 
                    {
                        q[j][b] = 0;
                    }
                }
                for(j = 1; j <= n; j = j + 1) 
                {
                    printf("q[%d][%d] (stock for rack position %d): ", j, j, j);
                    scanf("%d", &q[j][j]);
                    tni = tni + q[j][j];
                }
                max = q[1][1];
                min = q[1][1];
                m = 1;
                k = 1;
                for(j = 1; j <= n; j = j + 1) 
                {
                    if(q[j][j] > max) 
                    {
                        max = q[j][j];
                        m = j;
                    }
                    if(q[j][j] < min) 
                    {
                        min = q[j][j];
                        k = j;
                    }
                }
                printf("\nThe max stock is the product (ID = %d): %d", m, max);
                printf("\nThe min stock is the product (ID = %d): %d", k, min);
                printf("\nTotal no. of items across racks: %d\n", tni);
                break;
            }
            case 4: 
            {
                if(count == 0) 
                {
                    printf("There are no products in the warehouse yet.\n");
                    break;
                }
                g = stocks[0] * prices[0];
                h = stocks[0] * prices[0];
                f = 0;
                e = 0;
                d = 0;
                for(a = 0; a < count; a = a + 1) 
                {
                    b = stocks[a] * prices[a];
                    f = f + b;
                    printf("Product: %s | ID: %d | Total Value: %d\n", names[a], ids[a], b);
                    if(b > g) 
                    {
                        g = b;
                        e = a;
                    }
                    if(b < h) 
                    {
                        h = b;
                        d = a;
                    }
                }
                printf("Product with HIGHEST value: %s (ID: %d)\n", names[e], ids[e]);
                printf("Product with LOWEST value: %s (ID: %d)\n", names[d], ids[d]);
                printf("All products total value: %d\n", f);
                break;
            }
            case 5: 
            {
                printf("==== List of All Products ====\n");
                printf("Name\t\t\tID\tStock\tPrice\tValue\n");
                for(a = 0; a < count; a = a + 1) 
                {
                    printf("%-18s %d\t%d\t%d\t%d\n", names[a], ids[a], stocks[a], prices[a], stocks[a] * prices[a]);
                }
                break;
            }
            case 6: 
            {
                printf("Thank you! Program will now exit.\n");
                break;
            }
            default: 
            {
                printf("Invalid option! Please enter a number from 1 to 6 :\n");
            }
        }
    } while(choice != 6);

    return 0;
}
