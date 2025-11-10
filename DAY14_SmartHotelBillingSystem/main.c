#include <stdio.h>
int main() {

    int i, y, n, s, cust;             // i=loop, cust=number of customers
    int d, r;                        // d=days, r=room code
    int gym, wifi, bf;               // gym=Gym service, wifi=Wi-Fi, bf=Breakfast
    int base=0;                     // base=base room fare
    int tot, ad1, ad2, ad3, add;     // tot=total before GST, ad1-ad3=each add-on, add=total add-ons
    float disc=0, gst=0, bill=0;     // disc=discount, gst=tax, bill=final bill per customer
    float rev=0, high=0, low=9999;   // rev=total revenue, high=highest bill, low=lowest bill

    printf("Enter number of customers: ");
    scanf("%d", &cust);

    for(i=1; i<=cust; i++) {

        printf("\n-------- AVAILABLE ROOMS ---------\n");
        printf("1. Deluxe Room   : 2500\n");
        printf("2. Super Deluxe  : 4000\n");
        printf("3. Suite Room    : 6000\n");
        
        printf("\nSelect room (1,2,3): ");
        scanf("%d", &r);

        printf("Enter number of days: ");
        scanf("%d", &d);

        printf("\n----------- ADDITIONAL SERVICES ------------\n");
        printf("1. Breakfast : 300/day\n");
        printf("2. Wi-Fi     : 100/day\n");
        printf("3. Gym       : 200/day\n");

        printf("\nBreakfast (1=Yes,0=No): ");
        scanf("%d", &bf);
        printf("Wi-Fi (1=Yes,0=No): ");
        scanf("%d", &wifi);
        printf("Gym (1=Yes,0=No): ");
        scanf("%d", &gym);

        // Room base fare
        if(r==1) {
            base = d*2500;
        }
        if(r==2) {
            base = d*4000;
        }
        if(r==3) {
            base = d*6000;
        }

        // Add-on calculations
        if(bf==1) {
            ad1 = d*300;
        } else {
            ad1 = 0;
        }
        if(wifi==1) {
            ad2 = d*100;
        } else {
            ad2 = 0;
        }
        if(gym==1) {
            ad3 = d*200;
        } else {
            ad3 = 0;
        }

        add = ad1 + ad2 + ad3;
        tot = base + add;
        gst = tot * 0.12;

        if(tot >= 10000) {
            disc = tot * 0.1;
        } else {
            disc = 0;
        }

        bill = tot + gst - disc;
        rev = rev + bill;

        if(bill > high) {
            high = bill;
        }
        if(bill < low) {
            low = bill;
        }

        printf("\n---------- CUSTOMER %d -------------\n", i);
        printf("Base Fare        : %d\n", base);
        printf("Additional Serv.  : %d\n", add);
        printf("Discount          : %.2f\n", disc);
        printf("GST(12%%)          : %.2f\n", gst);
        printf("GRAND TOTAL       : %.2f\n", bill);
        printf("_________________________________________________\n");
    }

    printf("\n============= HOTEL SUMMARY ==================\n");
    printf("Total Rooms Booked : %d\n", cust);
    printf("Total Revenue      : %.2f\n", rev);
    printf("Highest Bill       : %.2f\n", high);
    printf("Lowest Bill        : %.2f\n", low);
    printf("===================================================\n");

    return 0;
}
