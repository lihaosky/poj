4 Values whose Sum is 0
Time Limit: 15000MS  Memory Limit: 228000K 
Total Submissions: 6300  Accepted: 1563 
Case Time Limit: 5000MS 

Description

The SUM problem can be formulated as follows: given four lists A, B, C, D of integer values, compute how many quadruplet (a, b, c, d ) ¡Ê A x B x C x D are such that a + b + c + d = 0 . In the following, we assume that all lists have the same size n . 
Input

The first line of the input file contains the size of the lists n (this value can be as large as 4000). We then have n lines containing four integer values (with absolute value as large as 228 ) that belong respectively to A, B, C and D . 
Output

For each input file, your program has to write the number quadruplets whose sum is zero. 
Sample Input

6
-45 22 42 -16
-41 -27 56 30
-36 53 -37 77
-36 30 -75 -46
26 -38 -10 62
-32 -54 -6 45

Sample Output

5

Hint

Sample Explanation: Indeed, the sum of the five following quadruplets is zero: (-45, -27, 42, 30), (26, 30, -10, -46), (-32, 22, 56, -46),(-32, 30, -75, 77), (-32, -54, 56, 30). 
Source

