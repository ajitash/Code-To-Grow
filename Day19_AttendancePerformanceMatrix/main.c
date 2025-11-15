//Name: M.Naga Ajitesh
//Reg N.o: AP25110090150

#include <stdio.h>
int main()
{
    int attendance[5][5];
    int mark[5][5];
    char name[5][50];
    int choice;
    int attended ,absences;
    int highA = 0,lowA = 0,highAS = 0,lowAS = 0;
    int total ,avg, highT = 0, lowT = 500, highTS = 0, lowTS = 0;
    int i ,j;//variables for loops

    printf("====== Student Attendance & Performance Matrix System ======");
    printf("\nEnter names of 5 students:\n");//name
    for (i = 0; i < 5; i++) 
    {
        printf("Student %d: ", i+1);
        scanf("%s", name[i]);
    }

    printf("\nEnter Attendance (1-Present , 0 - Absent): \n");//attendance
    for(i = 0; i < 5; i++)
    {
        printf("\nAttendance for %s:\n" ,name[i]);
        for(j = 0; j < 5; j++) 
        {
            printf("Subject %d: ", j+1);
            scanf("%d" ,&attendance[i][j]);
        }
    }

    printf("\nEnter Marks (0-100):\n");//Marks
    for(i = 0; i < 5; i++)
    {
        printf("\nMarks for %s  \n" ,name[i]);
        for(j = 0; j < 5; j++) 
        {
            printf("Subject %d: ", j+1);
            scanf("%d" ,&mark[i][j]);
        }
    }

    do
    {
        printf("\n========== Menu ==========\n");
        printf("1. Display Attendance Matrix\n");
        printf("2. Display Marks Matrix\n");
        printf("3. Attendance Report\n");
        printf("4. Performance Report\n");
        printf("5. Grade Report\n");
        printf("6. Exit\n");
        printf("============================");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                printf("\nAttendance Matrix:\n");
                for(i = 0; i < 5; i++)
                {
                    printf("\n%s: " ,name[i]);
                    for(j = 0; j < 5; j++)
                    {
                        printf(" %d ",attendance[i][j]);
                    }
                }
            } break;
            case 2:
            {
                printf("\nMarks Matrix:\n");
                for(i = 0; i < 5; i++)
                {
                    printf("\n%s: " ,name[i]);
                    for(j = 0; j < 5; j++)
                    {
                        printf(" %d ",mark[i][j]);
                    }
                }
            }break;
            case 3:
            {
                printf("\nAttendance Report:\n");
                for(i = 0; i < 5; i++)
                {
                    attended = 0;
                    absences = 0;
                    for(j = 0; j < 5; j++)
                    {
                        if( attendance[i][j] == 1 ) { attended += 1; }
                        if( attendance[i][j] == 0 ) { absences += 1; }
                        if( attended > highA ) { highA = attended; highAS = i;}
                        if( absences > lowA ) { lowA = absences; lowAS = i;}
                    }
                    printf("\nTotal Classes Attended by %s: %d" ,name[i] ,attended);
                    printf("\nTotal Absences by %s: %d\n" ,name[i] ,absences);
                }
                printf("\nStudent with Highest Attendence: %s" ,name[highAS]);
                printf("\nStudent with Lowest  Attendence: %s" ,name[lowAS]);
            }break;
            case 4:
            {
                printf("\nPerformance Report:\n");
                for(i = 0; i < 5; i++)
                {
                    total = 0;
                    avg = 0;
                    for(j = 0; j < 5; j++)
                    {
                        total += mark[i][j];
                        avg = total/5;
                        if( total > highT) {highT = total; highTS = i;}
                        if( total < lowT) {lowT = total; lowTS = i;}
                    }
                    printf("\nTotal  marks  of %s: %d" ,name[i] ,total);
                    printf("\nAverage marks of %s: %d\n" ,name[i] ,avg);
                }
                printf("\nClass topper(highest total marks): %s" ,name[highTS]);
                printf("\nLowest performer(lowest total marks): %s", name[lowTS]);
            }break;
            case 5:
            {
                printf("\nGrade Report:\n");
                for(i = 0; i < 5; i++)
                {
                   total = 0;
                   avg = 0;

                   for(j = 0; j < 5; j++)
                   {
                        total += mark[i][j];  
                   }

                   avg = total / 5;         
                   if (avg >= 90 && avg <= 100) {printf("\n%s grade = A+" ,name[i]);}
                   else if (avg >= 80 && avg < 90) {printf("\n%s grade = A" ,name[i]);}
                   else if (avg >= 70 && avg < 80) {printf("\n%s grade = B" ,name[i]);}
                   else if (avg >= 60 && avg < 70) {printf("\n%s grade = C" ,name[i]);}
                   else if (avg >= 50 && avg < 60) {printf("\n%s grade = D" ,name[i]);}
                   else if (avg < 50 && avg >= 0 ) {printf("\n%s grade = F" ,name[i]);}
                }
            }break;
            case 6:
            {
                printf("Exiting program....................\n");
            }break;
            default:
            {
                printf("Invalid choice. Please try again.\n");
            }   
        
        }
    }while( choice != 6);
    return 0;
}
