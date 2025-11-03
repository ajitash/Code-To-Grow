#include <stdio.h>
int main()
{
    int nc,choice,sw,b,ps,c,jui,qt,total,ni,fb,dis,tr;
    int i=1;
    int j=1;
    printf("Enter total number of customers:");
    scanf("%d",&nc);

    tr=0;
    for(i=1; i<=nc; i+=1)
    {
        sw=80;
        b=120;
        ps=150;
        c=60;
        jui=50;
        total=0;
        printf("\nMenu Card:\n1. sandwitch - 80\n2. burger - 120\n3. pizza slice - 150\n4. coffee - 60\n5. juice - 50\n");

        printf("\nCustomer %d Bill:\n",i);

        printf("Enter number of items:");
        scanf("%d",&ni);
        for(j=1; j<=ni; j+=1)
        {
            printf("\nEnter item %d code:",j);
            scanf("%d",&choice);
            printf("Enter quantity:");
            scanf("%d",&qt);
            switch(choice)
            {
                case 1:
                    printf("sandwitch x %d=%d\n",qt,sw*qt);
                    total += sw*qt;
                    break;
                case 2:
                    printf("burger x %d=%d\n",qt,b*qt);
                    total += b*qt;
                    break;
                case 3:
                    printf("Pizza SLice x %d=%d\n",qt,ps*qt);
                    total += ps*qt;
                    break;
                case 4:
                    printf("Coffee x %d=%d\n",qt,c*qt);
                    total += c*qt;
                    break;
                case 5:
                    printf("Juice x %d=%d\n",qt,jui*qt);
                    total += jui*qt;
                    break;
                default:
                    printf("\nInvalid item code\n");
                    break;
            }
        
            printf("\nTotal: %d\n",total);
            fb=total;
            if(total>500)
            {
                dis=0.1 * total;
                fb = total - dis;
                printf("Discount(10%%): %d\n",dis);
                printf("Final Bill: %d\n",fb);
            }
            tr+=fb;
        }
    }
    printf("\n========Canteen Summary========\n");
    printf("Total customers Served: %d\n",nc);
    printf("Total Revenue: %d\n",tr);
    return 0;
}