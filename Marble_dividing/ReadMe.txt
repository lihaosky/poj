Dividing
Time Limit: 1000MS  Memory Limit: 10000K 
Total Submissions: 19062  Accepted: 4620 

Description

Marsha and Bill own a collection of marbles. They want to split the collection among themselves so that both receive an equal share of the marbles. This would be easy if all the marbles had the same value, because then they could just split the collection in half. But unfortunately, some of the marbles are larger, or more beautiful than others. So, Marsha and Bill start by assigning a value, a natural number between one and six, to each marble. Now they want to divide the marbles so that each of them gets the same total value. Unfortunately, they realize that it might be impossible to divide the marbles in this way (even if the total value of all marbles is even). For example, if there are one marble of value 1, one of value 3 and two of value 4, then they cannot be split into sets of equal value. So, they ask you to write a program that checks whether there is a fair partition of the marbles. 
Input

Each line in the input file describes one collection of marbles to be divided. The lines contain six non-negative integers n1 , . . . , n6 , where ni is the number of marbles of value i. So, the example from above would be described by the input-line "1 0 1 2 0 0". The maximum total number of marbles will be 20000. 
The last line of the input file will be "0 0 0 0 0 0"; do not process this line. 
Output

For each collection, output "Collection #k:", where k is the number of the test case, and then either "Can be divided." or "Can't be divided.". 
Output a blank line after each test case. 
Sample Input

1 0 1 2 0 0 
1 0 0 0 1 1 
0 0 0 0 0 0 
Sample Output

Collection #1:
Can't be divided.

Collection #2:
Can be divided.




对于任意一组数,6的个数为n(n>=8)
> 
> 一。如果可以分成两堆，我们可以分成两种情况：
> 1.两堆里都有6，那么我们可知：把n改为n-2，仍然可分。(两堆各减一个6)
> 2.只有一堆里有6，设为左边，那么左边的总和不小于6*8=48。
>   我们观察，5*6=6*5  ，4*3=6*2  ， 3*2=6  ， 2*3=6 ， 1*6=6
>   而 5*5 + 4*2 + 3*1 + 2*2 + 1*5 = 25 + 8 + 3 + 4 + 5 = 45 < 48
>   由抽屉原理右边必然存在(多于5个的5 或者 多于2个的4 或者 多于1个的3
>                          或者 多于2个的2 或者 多于5个的1)
>   即右边至少存在一组数的和等于若干个6，比如右边有3个4
>   这样把左边的2个6与右边的3个4交换，则又出现左右都有6的情况。
>   根据1，我们还是可以把n改为n-2且可分的状态不变。
> 综合1，2。我们可以看出只要原来n的个数>=8,我们就可以把它改为n-2，
> 这样操作一直进行到n<8。我们可以得出结论，对于大于等于8的偶数，可以换成6
> 对于大于8的奇数，可以换成7。换完之后仍然可分。
> 
> 二。如果不能分成两堆：
>   显然改为n-2时同样也不能分，那么对于大于等于8的偶数，可以换成6
> 对于大于8的奇数，可以换成7。换完之后仍然不可分。
> 
> 综合一，二。我们得出结论把不小于8的偶数改为8，大于8的奇数改为7，
> 原来可分与否的性质不会改变。
> 
> 以上是对6的讨论，同样的方法可以推出
> 5的个数 6*4 + 4*4 + 3*4 + 2*4 + 1*4 = 64 < 5*13
>     即5的个数多于12时，偶数换为12，奇数换为11
> 4的个数 6*1 + 5*3 + 3*3 + 2*1 + 1*3 = 35 < 4*9
>     即4的个数多于8时，偶数换为8，奇数换为7
> 3的个数 5*2 + 4*2 + 2*2 + 1*2 = 24 < 3*9
>     即3的个数多于8时，偶数换为8，奇数换为7
> 2的个数 5*1 + 3*1 + 1*1 = 9 < 2*5
>     即2的个数多于4时，偶数换为4，奇数换为3
> 1的个数 多于5则必然可分(在总数是偶数的前提下)
