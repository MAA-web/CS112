#include <iostream>
using namespace std;

class shape {
protected:
    double length,width,area;
public:
    virtual void get_area() = 0;
    virtual void display_area() = 0;
};

class rectangle : public shape{
    public:
    explicit rectangle(double a, double b){
        length = a;
        width = b;
    }
    protected:
    inline void get_area(){
        area = length * width;
    }
    inline void display_area(){
        cout<<"Rectangle:\n\tlength: "<<length<<" width: "<<width<<" area: "<<area<<"\n";
    }
};
class triangle : public shape{
    protected:
    inline void get_area(){
        area = (0.5 * length * width);
    }
    inline void display_area(){
        cout<<"triangle:\n\tlength: "<<length<<" width: "<<width<<" area: "<<area<<"\n";
    }
    public:
    explicit triangle(double a, double b){
    length = a;
    width = b;
    }
};

int main()
{
    double a,b;
    while(true){
    cout<<"Type the length: ";
    cin>>a;
    cout<<"Type the width: ";
    cin>>b;
    if(a < 0 || b  < 0)continue;break;
    }
    shape *A; rectangle S(a,b); triangle C(a,b);
    A = &S;
    A->get_area();
    A->display_area();
    A = &C;
    A->get_area();
    A->display_area();

    return 0;
}
