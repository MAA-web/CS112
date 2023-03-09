#include <iostream>
using namespace std;

class a{
public:

bool istrue = false;
int a = 10;

bool operator!(){
    if(a == 10){
    return (!this->istrue);
    }
    else {
        return (this->istrue);
    }
}
};

int main(int argc, char const *argv[])
{
    int input;
    a c;
    
    cout<<"Type input (10): ";
    cin>>input;

    c.a = input;
    
    if(!c)
    {
        cout<<"C is 10\n";
    }
    else {
        cout<<"C is not 10\n";
    }
    
    return 0;
}