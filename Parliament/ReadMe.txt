����Ȼ��N�ֽ�����ɸ�������ͬ����������ʹ�˻����

�������ַֽ����Ŀ�����޵ģ������������ڣ�

���������ķֽ�Ϊ

n=a1+a2+a3+...+a[t-2]+a[t-1]+a[t]

(a1<a2<a3<...<a[t-2]<a[t-1]<a[t])

������֤��������е�һЩ���ʣ�

1.1<a1

if a1=1, then a1(=1), a[t] together could be replaced by a[t]+1.

2.to all i, a[i+1]-a[i]<=2;

if some i make a[i+1]-a[i]>=3,

then a[i],a[i+1] together could be replaced by a[i]+1,a[i+1]-1 together.

3. at MOST one i, fits a[i+1]-a[i]=2

if i<j and a[i+1]-a[i]=2 and a[j+1]-a[j]=2 then

a[i],a[j+1] could be replaced by a[i]+1, a[j+1]-1

 

4. a1<=3

if a1>=4, then a1,a2 together could be replaced by 2, a1-1, a2-1 together 

5. if a1=3 and one i fits a[i+1]-a[i]=2 then i must be t-1

if i<t-1 then a[i+2] could be replaced by 2, a[i+2]-2 together

Now, from the five rules above, we could make the mutiple maximum.

to an N, find the integer k, fits

A=2+3+4+...+(k-1)+k <= N < A+(k+1)=B

Suppose N = A + p, (0 <= p < k+1)

1) p=0, then answer is Set A

2) 1<=p<=k-1 then answer is Set B - { k+1-p }

3) p=k, then answer is Set A - {2} + {k+2}

We can prove this is the best choice with ease,

as any other choice will lead to at least one of the following:

1) a1>=4 or a1=1

2) two a[i+1]-a[i]=1 or one a[i+1]-a[i]=2

3) a1=3 and some i<t-2 fits a[i+1]-a[i]=1

