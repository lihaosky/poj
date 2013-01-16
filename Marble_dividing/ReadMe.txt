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




��������һ����,6�ĸ���Ϊn(n>=8)
> 
> һ��������Էֳ����ѣ����ǿ��Էֳ����������
> 1.�����ﶼ��6����ô���ǿ�֪����n��Ϊn-2����Ȼ�ɷ֡�(���Ѹ���һ��6)
> 2.ֻ��һ������6����Ϊ��ߣ���ô��ߵ��ܺͲ�С��6*8=48��
>   ���ǹ۲죬5*6=6*5  ��4*3=6*2  �� 3*2=6  �� 2*3=6 �� 1*6=6
>   �� 5*5 + 4*2 + 3*1 + 2*2 + 1*5 = 25 + 8 + 3 + 4 + 5 = 45 < 48
>   �ɳ���ԭ���ұ߱�Ȼ����(����5����5 ���� ����2����4 ���� ����1����3
>                          ���� ����2����2 ���� ����5����1)
>   ���ұ����ٴ���һ�����ĺ͵������ɸ�6�������ұ���3��4
>   ��������ߵ�2��6���ұߵ�3��4���������ֳ������Ҷ���6�������
>   ����1�����ǻ��ǿ��԰�n��Ϊn-2�ҿɷֵ�״̬���䡣
> �ۺ�1��2�����ǿ��Կ���ֻҪԭ��n�ĸ���>=8,���ǾͿ��԰�����Ϊn-2��
> ��������һֱ���е�n<8�����ǿ��Եó����ۣ����ڴ��ڵ���8��ż�������Ի���6
> ���ڴ���8�����������Ի���7������֮����Ȼ�ɷ֡�
> 
> ����������ֳܷ����ѣ�
>   ��Ȼ��Ϊn-2ʱͬ��Ҳ���ܷ֣���ô���ڴ��ڵ���8��ż�������Ի���6
> ���ڴ���8�����������Ի���7������֮����Ȼ���ɷ֡�
> 
> �ۺ�һ���������ǵó����۰Ѳ�С��8��ż����Ϊ8������8��������Ϊ7��
> ԭ���ɷ��������ʲ���ı䡣
> 
> �����Ƕ�6�����ۣ�ͬ���ķ��������Ƴ�
> 5�ĸ��� 6*4 + 4*4 + 3*4 + 2*4 + 1*4 = 64 < 5*13
>     ��5�ĸ�������12ʱ��ż����Ϊ12��������Ϊ11
> 4�ĸ��� 6*1 + 5*3 + 3*3 + 2*1 + 1*3 = 35 < 4*9
>     ��4�ĸ�������8ʱ��ż����Ϊ8��������Ϊ7
> 3�ĸ��� 5*2 + 4*2 + 2*2 + 1*2 = 24 < 3*9
>     ��3�ĸ�������8ʱ��ż����Ϊ8��������Ϊ7
> 2�ĸ��� 5*1 + 3*1 + 1*1 = 9 < 2*5
>     ��2�ĸ�������4ʱ��ż����Ϊ4��������Ϊ3
> 1�ĸ��� ����5���Ȼ�ɷ�(��������ż����ǰ����)
