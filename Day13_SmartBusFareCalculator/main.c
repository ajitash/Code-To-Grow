#include <stdio.h>

int main() {
    int age, distance, time, Bfare, passengers;
    int i = 0;
    float Ffare = 0, TR = 0, HF = 0, LF = 999999;

    printf("\n========= SRM Smart Bus Fare Calculator =========\n");

    printf("Enter number of passengers: ");
    if (scanf("%d", &passengers) != 1 || passengers <= 0) {
        printf("\nInvalid number of passengers. Exiting.\n");
        return 1;
    }

    for (i = 1; i <= passengers; ++i) {
        printf("\n--- Passenger %d ---\n", i);

        printf("Enter age: ");
        if (scanf("%d", &age) != 1 || age < 0) {
            printf("Invalid age input. Exiting.\n");
            return 1;
        }

        printf("Enter distance (in km): ");
        if (scanf("%d", &distance) != 1 || distance <= 0) {
            printf("Invalid distance input. Exiting.\n");
            return 1;
        }

        printf("Enter travel time (in 24hr format): ");
        if (scanf("%d", &time) != 1 || time < 0 || time > 23) {
            printf("Invalid time input. Must be between 0 and 23.\n");
            return 1;
        }

        Bfare = distance * 10;  // base fare calculation
        printf("\nBase Fare: %d", Bfare);

        Ffare = (float)Bfare;

        // Minimum fare is Rs.20
        if (Bfare <= 20) {
            Ffare = 20.0f;
        } else {
            // Peak hour surcharge (20%)
            if ((time >= 8 && time <= 10) || (time >= 17 && time <= 20)) {
                printf("\nPeak Hour Surcharge Applied");
                Ffare += (Ffare * 0.2f);
            }

            // Discounts
            if (age < 12) {
                printf("\nChild Discount Applied");
                Ffare -= (Ffare * 0.5f);
            } else if (age >= 60) {
                printf("\nSenior Citizen Discount Applied");
                Ffare -= (Ffare * 0.3f);
            }
        }

        printf("\nFinal Fare: Rs%.2f\n", Ffare);

        // Initialize HF/LF on first passenger
        if (i == 1) {
            HF = LF = Ffare;
        } else {
            if (Ffare > HF) HF = Ffare;
            if (Ffare < LF) LF = Ffare;
        }

        TR += Ffare;
    }

    printf("\n========= Daily Summary =========\n");
    printf("Total Passengers: %d\n", passengers);
    printf("Total Revenue Collected: Rs%.2f\n", TR);
    printf("Highest Fare: Rs%.2f\n", HF);
    printf("Lowest Fare: Rs%.2f\n", LF);

    return 0;
}
