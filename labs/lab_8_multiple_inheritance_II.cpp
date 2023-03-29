#include <iostream>

using namespace std;

class base1 {//first base class
    public:
    double x;
    explicit base1(double x = 0){//constructor with defaut value for base1 so that it acts as a defaut constructor
        this->x = x;
    }
};

class base2 {//second base class
    public:
    double y;
    explicit base2(double y = 0){//constructor with defaut value for base2 so that it acts as a defaut constructor
        this->y = y;
    }
};

class derived : public base1, base2{//multiple derived class
    public:
    double z;
    explicit derived(double x = 1, double y = 1, double z = 1){//cunstructor for multiple derived class so that it acts as a defaut constructor
        this->x = x;
        this->y = y;
        this->z = z;
    }
    inline void print () const {
        cout<<"Answer: "<<this->x*this->y*this->z<<endl;
    }
};

int main()
{
    double a, b, c;
    cout<<"Please type in three numbers: ";     //user input
    while(true){
        cin>>a>>b>>c;
        if (a < 0 || b < 0 || c < 0){cout<<"Please type in non-negative numbers: ";continue;}// checking for negative numbers
        break;
    }
    derived D(a,b,c);
    D.print();
    return 0;
}