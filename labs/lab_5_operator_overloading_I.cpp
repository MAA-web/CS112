#include <iostream>
using namespace std;

class Frac
{
private:
    double num;
    double den;
public:
    Frac(double, double);
    Frac();
    Frac operator*(const Frac& b){
        Frac c((this->num * b.num), (this->den * b.den));return c;
    }

    friend void operator<<(ostream& output, Frac c){
        output<<c.num<<"/"<<c.den<<endl;
    }

    void divide(void) const {
        cout<<num/den<<endl;
    }
};

Frac::Frac(double numerator, double denominator)
{
    this->num = numerator;
    this->den = denominator;
}

int main(int argc, char const *argv[])
{
    double a, b;
    cout<<"Add the values of the First fraction: ";
    cin>>a>>b;
    Frac a1(a,b);

    cout<<"Add the values of the second fraction: ";
    cin>>a>>b;
    Frac b1(a,b);
    Frac c = a1 * b1;

    cout<<"Fraction form: ";
    cout<<c;
    cout<<"Decimal form: ";
    c.divide();
    return 0;
}
