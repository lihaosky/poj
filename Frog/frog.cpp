/*
���ܵ�Լ��
Time Limit: 1000MS  Memory Limit: 10000K
Total Submissions: 32910  Accepted: 4229

Description

��ֻ������������ʶ�ˣ������ĵúܿ��ģ����Ǿ��ú��б�Ҫ��һ�档���Ǻܸ��˵ط�������ס��ͬһ��γ�����ϣ���������Լ�����Գ�������ֱ������Ϊֹ���������ǳ���֮ǰ������һ������Ҫ�����飬��û��������Է���������Ҳû��Լ������ľ���λ�á����������Ƕ��Ǻ��ֹ۵ģ����Ǿ���ֻҪһֱ����ĳ����������ȥ�����������Է��ġ����ǳ�������ֻ������ͬһʱ������ͬһ���ϣ���Ȼ����Զ������������ġ�Ϊ�˰�������ֻ�ֹ۵����ܣ��㱻Ҫ��дһ���������ж�����ֻ�����Ƿ��ܹ����棬����ʲôʱ�����档
���ǰ�����ֻ���ֱܷ��������A������B�����ҹ涨γ�����϶���0�ȴ�Ϊԭ�㣬�ɶ�����Ϊ�����򣬵�λ����1�ף��������Ǿ͵õ���һ����β��ӵ����ᡣ������A�ĳ�����������x������B�ĳ�����������y������Aһ������m�ף�����Bһ������n�ף���ֻ������һ�������ѵ�ʱ����ͬ��γ�����ܳ�L�ס�����Ҫ������������˼����Ժ�Ż����档

Input

����ֻ����һ��5������x��y��m��n��L������x��y < 2000000000��0 < m��n < 2000000000��0 < L < 2100000000��
Output

�����������Ҫ����Ծ�����������Զ���������������һ��"Impossible"
Sample Input

1 2 3 4 5
Sample Output

4
*/

//purpose is to find x such that ax=b(modn)
//using euclid gcd algorithm
//AUTHOR: LIHAO
//DATE: MAR 3RD 2009
//VENUE: DORMITORY

#include <iostream>
using namespace std;


void gcd(long long a,long long b,long long& xx,long long& yy,long long &divisor)
{
      if(b==0){
            xx=1;
            yy=0;
           divisor=a;
           return;
      }
      gcd(b,a%b,xx,yy,divisor);
      long long tmp=xx;
      xx=yy;
      yy=tmp-(a/b)*yy;
}

int main()
{
      long long x,y,m,n,l,b,xx,yy,a,x0,divisor,step;
      cin>>x>>y>>m>>n>>l;
      x%=l;
      y%=l;
      m%=l;
      n%=l;
      if(n==m){
            cout<<"Impossible"<<endl;
            return 0;
      }
      if(x<y){
            b=y-x;
            if(m<n){
                  a=m-n+l;
            }
            else{
                  a=m-n;
            }
      }
      else{
            b=x-y;
            if(m>n){
                  a=n-m+l;
            }
            else{
                  a=n-m;
            }
      }
      gcd(a,l,xx,yy,divisor);
      if(divisor==1&&b==1){
            if(xx<0){
                  xx+=l;
                  cout<<xx<<endl;
                  return 0;
            }
            cout<<xx<<endl;
            return 0;
      }
      if(b%divisor){
            cout<<"Impossible"<<endl;
            return 0;
      }
      x0=(xx*(b/divisor))%l;
      if(x0>0){
            x0-=l;
      }
      for(int i=1;i<=divisor;i++){
            step=x0+i*(l/divisor);
            if(step>0){
                  cout<<step<<endl;
                  return 0;
            }
      }
      return 0;
}
