#include <iostream>//header file for input and output
using namespace std;//name o fcommon functions and vaiables

int a = 1;//initialising a

struct phone_number//phone numbers struct
{
    int area;
    int exchange;
    int number;
}num, num_own;//initialising variables

enum area_code {Islamabad=111, Lahore=222, Karachi=333, Faisalabad=444};//enum of area codes

int main(int argc, char const *argv[])//main function
{
    while(true){                                     //while loop to exit if everything id ok           
        cout<<"Which is your city:"<<endl;//city prompt
        cout<<"1:Islamabad\n2:Lahore\n3:Karnum.areahi\n4:Fasialabad"<<endl;
        cout<<endl;
        cout<<"Type you city's number: ";//asking for city number
        cin>>a;
        cout<<endl;
        /*Assigning area code values*/
        if (a == 1)//if statement as toggle for user
        {
            num.area = area_code::Islamabad;
        }
        else if (a == 2)
        {
            num.area = area_code::Lahore;
        }
        else if (a == 3)
        {
            num.area = area_code::Karachi;
        }
        else if (a == 4)
        {
            num.area = area_code::Faisalabad;
        }
        else{
            cout<<"entered wrong number"<<endl;//else statement if wrong number entered
            continue;//break if wrong number entered
        }
        break;
    }

    
    /*my own number (not my own wink wink)*/
    num_own.area = 261;
    num_own.exchange = 681;
    num_own.number = 6666;
    
    while(true){
        //asking for exchange numeber
        cout<<"Type the exchange: ";
        cin>>num.exchange;
        if(to_string(num.exchange).length() != 3){cout<<"type three digit exchange number"<<endl;continue;}//checking length
        break;
    }
    while(true){
        //asking for number
        cout<<"Type the number: ";
        cin>>num.number;
        if(to_string(num.number).length() != 4){cout<<"type four digit number"<<endl;continue;}//checkig length
        break;
    }
    cout<<endl;

    //printing both numbers
    cout<<"my number is ("<<num_own.area<<")-"<<num_own.exchange<<"-"<<num_own.number<<endl;
    cout<<"your number is ("<<num.area<<")-"<<num.exchange<<"-"<<num.number<<endl;

    return 0;//return 0 if everything is ok
}
