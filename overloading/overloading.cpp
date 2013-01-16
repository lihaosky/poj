//operator overloading pactice
// LiHao Nov.4th

#include<iostream>
using namespace std;


class complex{
      private: 
               double re,im;
      public:
             complex(double a=0,double b=0):re(a),im(b){};
             double get_re(){return re;};
             double get_im(){return im;};
             complex operator+(complex& );  //plus overloading
             complex operator*(complex&);     //multiply overloading
             complex operator-(complex&);     //minus overloading
};

complex complex::operator+(complex& a){
        complex c=a;
        c.re=this->re+a.re;
        c.im=this->im+a.im;
        return c;
        }

complex complex::operator*(complex& a){
        complex c=a;
        c.re=this->re*a.re-this->im*a.im;
        c.im=this->re*a.im+this->im*a.re;
        return c;
        }
        
complex complex::operator-(complex& a){
        complex c=a;
        c.re=this->re-a.re;
        c.im=this->im-a.im;
        return c;
        }
          
int main()
{
    complex a(1,3.77777);
    complex b(12,14);
    complex c=a*b;
    cout.setf(ios::fixed);      //keep three digit after point
    cout.precision(3);          //this could keep three digits overall
    cout<<c.get_re()<<showpos<<c.get_im()<<"i"<<endl;
    complex d=a-b;
    cout<<d.get_re()<<showpos<<d.get_im()<<"i"<<endl;  
    system("PAUSE");
}
