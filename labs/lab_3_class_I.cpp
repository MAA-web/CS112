#include <iostream>
using namespace std;

class bill{
    float Number_of_Days{};
    float PDC{};
    float Elec_Charges{};
    float Gas_charges{};
    float Internet_Charges{};
    
    public:

    void setNod(){
        cout<<"\nAdd the number of days the student has eaten: ";
        while(true){
            cin>>this->Number_of_Days;
            if(this->Number_of_Days < 0){cout<<"Type a non-negative number: ";continue;}
            break;
        }
    }

    void Input(){
        cout<<"Per day charges: ";
        while(true){
            cin>>this->PDC;
            if(this->PDC < 0){cout<<"Type a non-negative number: ";continue;}
            break;
        }
        
        cout<<"Electricity charges: ";
        while(true){
            cin>>this->Elec_Charges;
            if(this->Elec_Charges < 0){cout<<"Type a non-negative number: ";continue;}
            break;
        }

        cout<<"Gas charges: ";
        while(true){
            cin>>this->Gas_charges;
            if(this->Gas_charges < 0){cout<<"Type a non-negative number: ";continue;}
            break;
        }
        cout<<"Internet Charges: ";
        while(true){
            cin>>this->Internet_Charges;
            if(this->Internet_Charges < 0){cout<<"Type a non-negative number: ";continue;}
            break;
        }
    }

    float Grand_Total(){
        float result{0};
        result = (this->Number_of_Days * this->PDC) + (this->Elec_Charges) + (this->Gas_charges) + (this->Internet_Charges);
        return result;
    }

    void Display(){
        cout<<"--------------------------------------"<<endl;
        cout<<"The values inputed by the user"<<endl<<endl;
        cout<<"Number of days: "<<this->Number_of_Days<<endl;
        cout<<"Per Day Charge: "<<this->PDC<<endl;
        cout<<"Electricity charges: "<<this->Elec_Charges<<endl;
        cout<<"Gas charges: "<<this->Gas_charges<<endl;
        cout<<"Internet Charges: "<<this->Internet_Charges<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"The Grand total is: "<<this->Grand_Total();
    }
};

bill s;

int main(){
    s.setNod();
    s.Input();
    s.Display();

    return 0;
}