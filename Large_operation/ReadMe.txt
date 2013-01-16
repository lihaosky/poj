Write a program large op.cpp that will do addition, substraction and multipli-
cation for arbitrarily large integers. Each integer should be represented as a list of its
digits. Since the integers are allowed to be as large as you like, linked lists will be needed
to prevent the possibility of overflow. For some operations, it is useful to move back-
wards through the list; hence, doubly linked lists are appropriate. Use the following data
structure in your program:
struct Node {
unsigned digit;
Node* next;
Node* previous;
};
The program first reads in the input file name from the user. The input file can con-
tain multiple cases, and each case consists of three lines. The first two lines are two
arbitrarily large nonnegative integers as the operands, and the last line is a single charac-
ter (one of ¡®+¡¯, ¡®-¡¯ or ¡®*¡¯) indicating the operator. There will be a blank line between cases.
3
The following is a sample file:
2
3
+
384765379023121
198234890987234
-
1
100000
-
29384987634765182734
18293784765342891872
*
For each case, the result should be printed on a separate line. The program ends when
all results are shown Here is a sample run with the above sample file:
[tmchan@localhost ~/c1122/a1]$ ./large_op
test-case
5
186530488035887
-99999
537562639122656557670471733298083338048
