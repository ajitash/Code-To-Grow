Name: M.Naga Ajitesh
Reg N.o: AP25110090150

Approach:
This C program analyzes the performance of up to 10 students by processing their marks.
It starts by asking for the total number of students and then inputs each student's marks.
For every mark, it calculates the sum to later derive the average, counts the number of passes (marks ≥ 50) and fails (marks < 50),
categorizes each mark into grade groups (A+, A, B, C, D, Fail), and tracks the highest and lowest marks entered. After all data is collected,
the program prints a summary displaying the average, highest, and lowest marks, the total numbers of passed and failed students, and the distribution of grades.

Variables:

students[10] — Array to store marks of up to 10 students.

sum — Accumulates the total marks of all students to calculate the average.

avg — Holds the calculated average marks of all students.

pass — Counts how many students scored 50 or more (pass).

fail — Counts how many students scored below 50 (fail).

totalstu — Number of students whose marks are being analyzed.

i — Loop iterator for accessing students and grades.

j — Generic loop iterator or index, possibly used for additional loops or display.

A1 — Counter for students scoring in the A+ grade (typically highest bracket).

A — Counter for students scoring in the A grade.

B — Counter for students scoring in the B grade.

C — Counter for students scoring in the C grade.

D — Counter for students scoring in the D grade.

F — Counter for students who failed (scoring below passing mark).

high — Stores the highest mark among all students.

low — Stores the lowest mark among all students.
