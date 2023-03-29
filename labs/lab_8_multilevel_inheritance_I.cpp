#include <iostream>

using namespace std;

class base {// first class
    public:
    double x;
    explicit base(double x = 0){ // constructor with defaut value
        this->x = x;
    }
};

class derived1 : public base{// second class derived from first class
    public:
    double y;
    explicit derived1(double y = 0, double x = 0){// constructor with defaut value
        this->y = y;
        this->x = x;
    }
};

class derived2 : public derived1{ // third class derived from second class which was derive from first class (publically ofcourse)
    public:
    double z;
    explicit derived2(double x = 1, double y = 1, double z = 1){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    inline void print () const {//function to find and print result
        cout<<"Answer: "<<this->x*this->y*this->z<<endl;
    }
};

int main() {// main function where the whole code is written
    double a, b, c;
    cout<<"Please type in three numbers: ";//user input
    while(true){
        cin>>a>>b>>c;
        if (a < 0 || b < 0 || c < 0){cout<<"Please type in non-negative numbers: ";continue;}//checking for negative numbers
        break;
    }
    derived2 D2(a,b,c);//object instantialisation
    D2.print();//printing result
    return 0;
}