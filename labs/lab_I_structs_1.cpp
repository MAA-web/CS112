#include <iostream>//header file for input and output
using namespace std;//names of common functions

struct imaginary {//imaginary number struct
    float a = 1.1;
    float b = 2.2;
}n1, n2;//initialising variables

int main () {
    cout<<"write real and imaginary part of first number: ";//first number
    cin>>n1.a;
    cin>>n1.b;

    cout<<"write real and imaginary part of second number: ";//second number
    cin>>n2.a;
    cin>>n2.b;

    cout<<"Addition: <"<< (n1.a + n2.a) <<">+<"<< (n1.b + n2.b) <<">i"<<endl;//addition
    cout<<"Subtraction: <"<< (n1.a - n2.a) <<">+<"<< (n1.b - n2.b) <<">i"<<endl;//substraction
    cout<<"Multiplication: <"<< (n1.a * n2.a) - (n1.b * n2.b) <<">+<"<< (n2.b * n1.a) + (n1.b * n2.a) <<">i"<<endl;//multiplicaion

    return 0;//returning 0 so everything is ok
}
