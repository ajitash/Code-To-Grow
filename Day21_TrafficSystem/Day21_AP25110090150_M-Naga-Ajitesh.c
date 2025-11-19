//Name: M.Naga Ajitesh
//Rg n.o: AP25110090150


#include <stdio.h>

int ID[30];
int speed[30];
int lane[30];
int laneCount[4];
int vnum;
int high;
int low;
int mostSevereID;
int severityVal;

void inputdata()
{
    int i;
    for (i = 0; i < 4; i++) laneCount[i] = 0;
    printf("Enter number of vehicles: ");
    scanf("%d", &vnum);

    for (i = 0; i < vnum; i++)
    {
        printf("Enter Vehicle %d ID(4 digits): ", i+1);
        scanf("%d", &ID[i]);

        do
        {
            printf("Vehicle %d Speed: ", i+1);
            scanf("%d", &speed[i]);
        } while (speed[i] <= 0);

        do
        {
            printf("Enter lane of Vehicle %d: ", i+1);
            scanf("%d", &lane[i]);
        } while (lane[i] <= 0 || lane[i] > 4);

        laneCount[lane[i]-1] += 1;
    }
}

int speedsreport()
{
    int a;
    int count = 0;
    high = speed[0];
    low = speed[0];
    for (a = 0; a < vnum; a++)
    {
        if (speed[a] > 80) count++;
        if (speed[a] > high) high = speed[a];
        if (speed[a] < low) low = speed[a];
    }
    return count;
}

int laneviolations()
{
    int a;
    int count = 0;
    int highestseverity = -1;
    mostSevereID = -1;

    for (a = 0; a < vnum; a++)
    {
        int correctlane = ID[a] % 4;
        if (correctlane == 0) correctlane = 4;

        int severity = correctlane - lane[a];
        if (severity < 0) severity = -severity;

        if (correctlane != lane[a])
        {
            count++;
            if (severity > highestseverity)
            {
                highestseverity = severity;
                mostSevereID = ID[a];
                severityVal = severity;
            }
        }
    }
    return count;
}

int busiestlane()
{
    int a;
    int max = laneCount[0];
    int busy = 1;
    for (a = 1; a < 4; a++)
    {
        if (laneCount[a] > max)
        {
            max = laneCount[a];
            busy = a+1;
        }
    }
    return busy;
}

int leastbusy()
{
    int a;
    int min = laneCount[0];
    int Lbusy = 1;
    for (a = 1; a < 4; a++)
    {
        if (laneCount[a] < min)
        {
            min = laneCount[a];
            Lbusy = a+1;
        }
    }
    return Lbusy;
}

void finalreport()
{
    int a;
    printf("\nFinal Vehicle Data Report:\n");
    printf("ID\tSpeed\tLane\tSpeedV\tLaneV\n");
    for (a = 0; a < vnum; a++)
    {
        int speedv = (speed[a] > 80);
        int lanev = ((ID[a] % 4 == 0 ? 4 : ID[a] % 4) != lane[a]);
        printf("%d\t%d\t%d\t%d\t%d\n", ID[a], speed[a], lane[a], speedv, lanev);
    }
}

int main()
{
    printf("\n======== Smart City Traffic Monitoring & Violation Detection System ========\n");
    inputdata();
    int nSpeedViol = speedsreport();
    int nLaneViol = laneviolations();
    int busy = busiestlane();
    int Lbusy = leastbusy();

    printf("\nTotal Speed Violations: %d\n", nSpeedViol);
    printf("Highest Speed: %d\nLowest Speed: %d\n", high, low);
    printf("Total Lane Violations: %d\n", nLaneViol);

    if (mostSevereID != -1) {printf("Most Severe Lane Violation: Vehicle ID %d (severity %d)\n", mostSevereID, severityVal);}
    else {printf("No lane violations found\n");}

    printf("\nLane Densities:\n");
    for (int i = 0; i < 4; i++)
       { 
           printf("Lane %d: %d vehicles\n", i+1, laneCount[i]);
           printf("Busiest Lane: %d\nLeast Busy Lane: %d\n", busy, Lbusy);
       }
    finalreport();
    return 0;
}
