#include <iostream>

using namespace std;

class D1;
class D2;

class D1 {
    
    float meters;
    float centi_meters;
    
    public:
    
    friend float add(D1 a , D2 b);

    D1(float a, float b){
        meters = a;
        centi_meters = b;
    }

};

class D2 {
   
    float feet;
    float inches;
    public:
    
    D2(float a, float b){
        feet = a;
        inches = b;
    }

    friend float add(D1 a , D2 b);
};


float add(D1 a,D2 b){
        return ((b.feet/3.28084) + (b.inches/39.3701) + (a.meters) + (a.centi_meters/100));
}


int main(){
    float c,d,e,f;
    cout<<"Type the meters: ";
    while(true){
        cin>>c;
        if(c < 0){cout<<"Type a non-negative number: ";continue;}
        break;
    }
    cout<<"Type the centi meters: ";
    while(true){
        cin>>d;
        if(d < 0){cout<<"Type a non-negative number: ";continue;}
        break;
    }
    cout<<"Type the feets: ";
    while(true){
        cin>>e;
        if(e < 0){cout<<"Type a non-negative number: ";continue;}
        break;
    }
    cout<<"Type the inches: ";
    while(true){
        cin>>f;
        if(f < 0){cout<<"Type a non-negative number: ";continue;}
        break;
    }
    D1 a(c,d);
    D2 b(e,f);
    float x = add(a, b);

    cout<<"Answer in meters: ";

    cout<<x<<" ";
    return 0;
}