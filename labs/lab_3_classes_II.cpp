#include <iostream>
using namespace std;

class square{
    public:

    float length;

    square(){
        cout<<"\nDefault Constructor["<<endl;
        cout<<"Type the length of the square: ";
        while(true){
            cin>>length;
            if(length < 0){cout<<"Type a non-negative length: ";continue;}
            break;
        }
        cout<<"]"<<endl<<endl<<flush;
    }

    square(float a){
        cout<<"parameterized Constructor["<<endl;
        this->length = a;
        cout<<"Value added: "<<length<<endl;
        cout<<"]"<<endl<<endl<<flush;
    }

    square(const square &sqr){
        cout<<"Copy Constructor["<<endl;
        this->length = sqr.length;
        cout<<"The length of the square 3 after the copy constructor (copied fron square 2): "<<this->length<<endl;
        cout<<"]"<<endl<<endl<<flush;
    }
};

int main(void){
    square s0;
    float b;
    cout<<"Type the length of the second square: ";
    while(true){
        cin>>b;
        if(b < 0){cout<<"Type a non-negative length: ";continue;}
        break;
    }
    square s1(b);
    square s3(s1);
    cout<<"Area of square 1: "<<(s0.length * s0.length)<<endl;
    cout<<"Area of square 2: "<<(s1.length * s1.length)<<endl;
    cout<<"Area of square 3: "<<(s3.length * s3.length)<<endl;
    return 0;
}