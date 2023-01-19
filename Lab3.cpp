#include "lab1_2.cpp"
#include <chrono>
using namespace std;

class Polynomial {
public:
  static const size_t length = 326;
  static Polynomial* generator;
  bool p[length]={0};
  
  Polynomial() {};
  Polynomial(bool p1[length]) {
    for(int i=0; i<length; i++){
    this->p[i] = p1[i];
      }
  };

  void printpoly (){
    cout<<"Coefs: "<<endl;
    for(int i= length-1;i>=0;i--){
      cout<<(this->p[i]);
    }
    cout<<endl;
  }

  Polynomial operator+(const Polynomial& b) const{
    Polynomial result;
    for(int i=0; i<length; i++){
    result.p[i]=(this->p[i]!=b.p[i]);
    }
    
    return result%(*generator);
  }

  Polynomial operator<<(int a) const{
    Polynomial temp;
    for(int i =0;i<length-a; i++){
      temp.p[i+a]=this->p[i];
    }    
    return temp;
  }
 int deg () const {
  for(int i=length-1; i>=0; i--) {
   if(this->p[i]==1) return i;
  }
  return -1;
}

bool operator== (const Polynomial& b) const{
  for(int i=length-1; i>=0; i--){
    if(this->p[i]!=b.p[i]) return false;
  }
  
  return true;
}


Polynomial operator% (const Polynomial& b) const{
  Polynomial one;
  one.p[0]=1;
  Polynomial q;
  Polynomial r=*this;
  Polynomial temp = b;
  while (r.deg()>=temp.deg()) {
    int ssuv = r.deg()-b.deg();
    temp=(b<<ssuv);
    r=r+temp;
    q=q+(one<<ssuv);
  }
  return r;
  }
////////////////////////////////////////////////////// 2 lab


Polynomial Horner (const LongNum& b) const{
    Polynomial result;
    result.p[0]=1;
    for(int i=b.first_one(); i>=0; i--){
      if(b.number[i]==1) result=(result*(*this));
      if(i!=0) result=(result*result);
    }
    return result;
  }

  Polynomial operator* (const Polynomial& a) const{
    Polynomial temp;
    Polynomial b =a;
    for(int i=0; i<length; i++,b=(b<<1)){
     if(this->p[i]){
       temp=temp+b;
     } 
    }
    return temp;
  }

};



 

