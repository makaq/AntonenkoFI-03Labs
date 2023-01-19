#include <iostream>
#include <sstream>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;


class LongNum {
public:
  static const size_t length = 1024;
  bool number[length]={0};
  


  LongNum operator+(const LongNum& b) const{
    bool carry=0;
    LongNum result;
    for(int i=0; i<length; i++){
      bool ai = this->number[i];
      bool bi = b.number[i];
      result.number[i]=((ai!=bi)!=carry);
      carry=(((ai&&bi)!=(ai&&carry))!=(bi&&carry));
    }
    return result;
  }


  LongNum operator-(const LongNum& b) const{
    if(*this<b) throw "Eror" ;
    bool carry=0;
    LongNum result;
    for(int i=0; i<length; i++){
      bool ai = this->number[i];
      bool bi = b.number[i];
      result.number[i]=((ai!=bi)!=carry);
      int c1=0;
      int c2=0;
      if(ai) c1=1;
      if(bi) c2++;
      if(carry) c2++;
      carry = (c1<c2);
    }
    return result;
  }

  void readhex (string a){
    for(int i=0; i<a.size(); i++){
     switch ( a[a.size()-i-1] )
      {
        case '0':
           number[i*4+3]=0;
           number[i*4+2]=0;
           number[i*4+1]=0;
           number[i*4]=0;
            break;
        case '1':
            number[i*4+3]=0;
           number[i*4+2]=0;
           number[i*4+1]=0;
           number[i*4]=1;
            break;
        case '2':
            number[i*4+3]=0;
           number[i*4+2]=0;
           number[i*4+1]=1;
           number[i*4]=0;
            break;
        case '3':
            number[i*4+3]=0;
           number[i*4+2]=0;
           number[i*4+1]=1;
           number[i*4]=1;
            break;
        case '4':
            number[i*4+3]=0;
           number[i*4+2]=1;
           number[i*4+1]=0;
           number[i*4]=0;
            break;
        case '5':
            number[i*4+3]=0;
           number[i*4+2]=1;
           number[i*4+1]=0;
           number[i*4]=1;
            break;
        case '6':
            number[i*4+3]=0;
           number[i*4+2]=1;
           number[i*4+1]=1;
           number[i*4]=0;
            break;
        case '7':
            number[i*4+3]=0;
           number[i*4+2]=1;
           number[i*4+1]=1;
           number[i*4]=1;
            break;
        case '8':
            number[i*4+3]=1;
           number[i*4+2]=0;
           number[i*4+1]=0;
           number[i*4]=0;
            break;
        case '9':
            number[i*4+3]=1;
           number[i*4+2]=0;
           number[i*4+1]=0;
           number[i*4]=1;
            break;
        case 'A':
            number[i*4+3]=1;
           number[i*4+2]=0;
           number[i*4+1]=1;
           number[i*4]=0;
            break;
        case 'B':
            number[i*4+3]=1;
           number[i*4+2]=0;
           number[i*4+1]=1;
           number[i*4]=1;
            break;
        case 'C':
            number[i*4+3]=1;
           number[i*4+2]=1;
           number[i*4+1]=0;
           number[i*4]=0;
            break;
        case 'D':
            number[i*4+3]=1;
           number[i*4+2]=1;
           number[i*4+1]=0;
           number[i*4]=1;
            break;
        case 'E':
            number[i*4+3]=1;
           number[i*4+2]=1;
           number[i*4+1]=1;
           number[i*4]=0;
            break;
        case 'F':
            number[i*4+3]=1;
           number[i*4+2]=1;
           number[i*4+1]=1;
           number[i*4]=1;
            break;
         default:
            throw "Invalid symbol";
      }
      }
    }
  void printhex () {
    for(int i=length-4; i>=0; i-=4){
      string temp;
      temp.push_back((char)(number[i+3]+'0'));
      temp.push_back((char)(number[i+2]+'0'));
      temp.push_back((char)(number[i+1]+'0'));
      temp.push_back((char)(number[i]+'0'));
     // reverse(temp.begin(),temp.end());
        if(temp=="0000"){
          cout<<"0";
        }
        else if(temp=="0001"){
          cout<<"1";
        }
      else if(temp=="0010"){
          cout<<"2";
        }
      else if(temp=="0011"){
          cout<<"3";
        }
      else if(temp=="0100"){
          cout<<"4";
        }
      else if(temp=="0101"){
          cout<<"5";
        }
      else if(temp=="0110"){
          cout<<"6";
        }
      else if(temp=="0111"){
          cout<<"7";
        }
      else if(temp=="1000"){
          cout<<"8";
        }
      else if(temp=="1001"){
          cout<<"9";
        }
      else if(temp=="1010"){
          cout<<"A";
        }
      else if(temp=="1011"){
          cout<<"B";
        }
      else if(temp=="1100"){
          cout<<"C";
        }
      else if(temp=="1101"){
          cout<<"D";
        }
      else if(temp=="1110"){
          cout<<"E";
        }
      else if(temp=="1111"){
          cout<<"F";
        }
      else {throw "ERROR";}
      }
    }

  LongNum operator<<(int a) const{
    LongNum temp;
    for(int i =0;i<length-a; i++){
      temp.number[i+a]=this->number[i];
    }    
    return temp;
  }

LongNum operator>>(int a) const{
    LongNum temp;
    for(int i =0;i<length-a; i++){
      temp.number[i]=this->number[i+a];
    }    
    return temp;
  }

bool operator< (const LongNum& b) const{
  for(int i=length-1; i>=0; i--){
    if(this->number[i]<b.number[i]) return true;
    else if (this->number[i]>b.number[i]) return false;
  }
  
  return false;
}

 int first_one () const {
  for(int i=length-1; i>=0; i--) {
   if(this->number[i]==1) return i;
  }
  return -1;
}

bool operator== (const LongNum& b) const{
  for(int i=length-1; i>=0; i--){
    if(this->number[i]!=b.number[i]) return false;
  }
  
  return true;
}

LongNum operator/ (const LongNum& b) const{
  LongNum one;
  one.number[0]=1;
  LongNum q;
  LongNum r=*this;
  LongNum temp = b;
  while (!(r < b)) {
    int ssuv = r.first_one()-b.first_one();
    temp=(b<<ssuv);
    if(r<temp) {
      temp=(b<<(ssuv-1));
      ssuv--;
      }
    r=r-temp;
    q=q+(one<<ssuv);
  }
  return q;
  }

LongNum operator% (const LongNum& b) const{
  LongNum one;
  one.number[0]=1;
  LongNum q;
  LongNum r=*this;
  LongNum temp = b;
  while (!(r < b)) {
    int ssuv = r.first_one()-b.first_one();
    temp=(b<<ssuv);
    if(r<temp) {
      temp=(b<<(ssuv-1));
      ssuv--;
      }
    r=r-temp;
    q=q+(one<<ssuv);
  }
  return r;
  }
////////////////////////////////////////////////////// 2 lab
LongNum Muuu () const{
  LongNum u; 
  u.number[0]=1;
  u=(u<<((this->first_one()+1)*2));
  u=u/(*this);
  return u;
  }


  LongNum Barrret ( const LongNum& n, const LongNum& m) const{
    LongNum r;
    LongNum q1,q2,q3;
    int xfirst = n.first_one();
    q1=(*this)>>(xfirst);
    q2=q1*m;
    q3=(q2>>(xfirst+2));
    r=(*this)-(q3*n);
    while ( n<r || n==r ){
      r=r-n;
    }
    return r;
  }

  LongNum Horner_mod (const LongNum& b, const LongNum& n) const{
    LongNum a=*this;
    a=a%n;
    LongNum m = n.Muuu();
    LongNum result;
    result.number[0]=1;
    for(int i=b.first_one(); i>=0; i--){
      if(b.number[i]==1) result=(result*(a)).Barrret(n, m);
      if(i!=0) result=(result*result).Barrret(n, m);
    }
    return result;
  }

LongNum Horner (const LongNum& b) const{
    LongNum result;
    result.number[0]=1;
    for(int i=b.first_one(); i>=0; i--){
      if(b.number[i]==1) result=(result*(*this));
      if(i!=0) result=(result*result);
    }
    return result;
  }

  LongNum operator* (const LongNum& a) const{
    LongNum temp;
    LongNum b =a;
    for(int i=0; i<this->length; i++,b=(b<<1)){
     if(this->number[i]){
       temp=temp+b;
     } 
    }
    return temp;
  }

};




