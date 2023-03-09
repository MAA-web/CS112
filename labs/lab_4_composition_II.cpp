#include <iostream>
#include <string.h>
using namespace std;

class Time{
    public:
    int hour, min;
    
    void get_Time(){
        int a,b;
        cout<<"Type the hour: ";
        while(true){
            cin>>this->hour;
            if(this->hour < 0){cout<<"Type a non-negative number: ";continue;}
            break;
        }
        cout<<"Type the minutes: ";
        while(true){
            cin>>this->min;
            if(this->min < 0){cout<<"Type a non-negative number: ";continue;}
            break;
        }
    }
};

class Date{
    public:
    int day, month, year;
    
    void get_Date(){
        int a,b,c;
        cout<<"Type the day: ";
        while(true){
            cin>>this->day;
            if(this->day <= 0){cout<<"Type a non-negative number: ";continue;}
            break;
        }
        cout<<"Type the month: ";
        while(true){
            cin>>this->month;
            if(this->month <= 0){cout<<"Type a non-negative number: ";continue;}
            break;
        }
        cout<<"Type the year: ";
        while(true){
            cin>>this->year;
            if(this->year < 0){cout<<"Type a non-negative number: ";continue;}
            break;
        }
    }
};

class Event{
    string name;
    Time T;
    Date D;
    public:
    Event(string a){
        this->name = a;
        T.get_Time();
        D.get_Date();
    };
    void _printAll(){
        cout<<"Event: "<<name<<endl;
        cout<<"Occoured on"<<endl;
        cout<<"Time: "<<T.hour<<":"<<T.min<<endl;
        cout<<"Date: "<<D.day<<"/"<<D.month<<"/"<<D.year<<endl;
    }
};

int main(int argc, char const *argv[])
{
    string a;
    cout<<"Type the name of the event: ";
    if (a.empty() || a == " ")
    {
        getline(cin,a);
    }
    
    Event E(a);
    E._printAll();
    return 0;
}
