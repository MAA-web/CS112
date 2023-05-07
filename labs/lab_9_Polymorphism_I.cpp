#include<iostream>
using namespace std;

class account {
protected:
    double increment, zakat, balance;
public:
    virtual void calc_zakat(){};
    virtual void calc_inc(){};
    virtual void display(){cout<<"result";};
};
class current :public account {
public:
    inline void calc_inc(){
        increment = balance*0.052;
    }
    inline void calc_zakat(){
        zakat = balance*0.025;
    }
    inline void display() {
        cout<<"Current account:\n\tbalance: "<<balance<<" increment: "<<increment<<" Total: "<<balance+increment<<"\n";
    }
    explicit current(double a){
        balance = a;
    }

};

class savings :public account {
public:
    inline void calc_inc(){
        increment = balance*0.052;
    }
    inline void calc_zakat(){
        zakat = balance*0.025;
    }
    inline void display() {
        cout<<"Savings account:\n\tbalance: "<<balance<<" zakat: "<<zakat<<" Total: "<<balance-zakat<<"\n";
    }
    explicit savings(double a){
        balance = a;
    }

};

int main(){
    double a;
    while(true){
    cout<<"Type the balance: ";
    cin>>a;
    if(a < 0)continue;break;
    }
    account *A; savings S(a); current C(a);
    A = &S;
    A->calc_zakat();
    A->display();
    A = &C;
    A->calc_inc();
    A->display();

    return 0;
}