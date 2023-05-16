#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

class Student{
private:
    string std_name;
    int std_ID;
    string father_name;
    string gender;
    string address;
    string reg_status;
    string degree_status;
    string last_degree;
public:
    void setID(int id){
        std_ID=id;
    }
    int getID(){
        return std_ID;
    }

};

class Course{
    string course_code;
    int score;
    string degree;
    string sem;
    string year;
    string program;
public:
    void set_degree(const string& d){
        degree=d;
    }
    string get_degree(){
        return degree;
    }
    void set_sem(const string& d){
        sem=d;
    }
    string get_sem(){
        return sem;
    }
    void set_coursecode(const string& d){
        course_code=d;
    }
    string get_coursecode(){
        return course_code;
    }
    void set_marks(int d){
        score=d;
    }
    int get_marks(){
        return score;
    }
    void set_program(const string& d){
        program=d;
    }
    string get_program(){
        return program;
    }
};

int main() {
    int t;
    int size=1000;
    int lines=1000;
    int i=0;
    string l;
    ifstream in("Lhr_Detail_94.txt");
    vector<Student>s(size);
    vector<Course>c(size);
    getline(in, l); // discard first line
    l="";
    while(i<lines){
        in>>t;
        in.ignore(2, ',');
        s[i].setID(t);
        //cout<<s[i].getID();
        //in.ignore(1);
        getline(in, l,',');
        c[i].set_degree(l);
        in.ignore(1);
        getline(in, l, ',');
        c[i].set_sem(l);
        getline(in>>ws, l, ',');
        c[i].set_coursecode(l);
        in>>t;
        c[i].set_marks(t);
        in.ignore(1);
        getline(in, l);
        c[i].set_program(l);
        i++;
    }
    cout<<s[0].getID()<<endl;
    cout<<c[0].get_coursecode()<<endl;
    cout<<c[0].get_marks()<<endl;
    cout<<c[0].get_program()<<endl;
    for(auto i : s){
        cout<<i.getID()<<endl;
    }
    return 0;
}