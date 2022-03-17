#include<bits/stdc++.h>
using namespace std ; 

class Veh {
    public:

    Veh(){
        cout<<"This is a Vehicle" <<endl ;
    }
    void start(){
        cout<<"Veh is starting " ;
    }
};
class car: protected Veh{
  public:
  car(){
      cout<<"this is a car"<<endl  ;
  }
  void start(){
      cout<< "car is starting" ;
  }

};

int main(){
    car* v = new car();
    v->start() ;


}