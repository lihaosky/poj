Popular Cows
Time Limit: 2000MS  Memory Limit: 65536K 
Total Submissions: 4615  Accepted: 1858 

Description

Every cow's dream is to become the most popular cow in the herd. In a herd of N (1 <= N <= 10,000) cows, you are given up to M (1 <= M <= 50,000) ordered pairs of the form (A, B) that tell you that cow A thinks that cow B is popular. Since popularity is transitive, if A thinks B is popular and B thinks C is popular, then A will also think that C is 
popular, even if this is not explicitly specified by an ordered pair in the input. Your task is to compute the number of cows that are considered popular by every other cow. 

Input

* Line 1: Two space-separated integers, N and M 

* Lines 2..1+M: Two space-separated numbers A and B, meaning that A thinks B is popular. 

Output

* Line 1: A single integer that is the number of cows who are considered popular by every other cow. 

Sample Input

3 3
1 2
2 1
2 3

Sample Output

1

Hint

Cow 3 is the only cow of high popularity. 

Source

USACO 2003 Fall