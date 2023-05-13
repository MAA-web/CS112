#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <filesystem>

using namespace std;
namespace FS = std::filesystem;
class Student {
public:
    string SID, St_Name, Father_Name, Gender, Address, Date_of_Birth, Reg_Date, Reg_Status, Degree_Status, Last_Degree, campus, Discipline;
    void Display() const{
        cout<<SID<<" "<<St_Name<<" "<<Father_Name<<" "<<Gender<<" "<<Address<<" "<<Date_of_Birth<<" "<<Reg_Date<<" "<<Reg_Status<<" "<<Degree_Status<<" "<<Last_Degree<<" "<<campus<<endl;
    }
};

class Course {
public:

    string SID, Degree, Semester, Course, Marks, Discipline;
    void Display() const{
        cout<<SID<<" "<<Degree<<" "<<Semester<<" "<<Course<<" "<<Marks<<" "<<Discipline<<endl;
    }
};
//bool isPresent(const stirng&, const list<Course>&);
list<Student> students;
auto student = new Student;
int main() {


/*
    list<Course> courses;
    //list<Course> courses;
    auto *course = new Course;
    entities.clear();
    src = "";
    fstream input_file1(R"(C:\Users\hithe\projects\university-work\CS112\Semester_II_Project\Semester_II_Project_UI_CLI\Lhr_Detail_94.txt)", ios::in);
    while(getline(input_file1, src)){
        src+=",";

        for (int i = 0; src[i] != '\0'; ++i) {
            if (src[i] == ','){
                entities.push_back(var);
                var = "";
                continue;
            }
            var += src[i];
        }
        course->SID = entities[0];
        course->Degree = entities[1];
        course->Semester = entities[2];
        course->Course = entities[3];
        course->Marks = entities[4];
        course->Discipline = entities[5];
        courses.push_back(*course);
        entities.clear();
    }
    input_file1.close();


    cout<<"\ndone\n";
    auto output_file_string = new string;
    fstream output_file("output.csv", ios::out);
    string s, degree, campus;

    //for (const auto& iyt : variables){
    //    s += iyt + ",";
    //}
    for (int i = 0; i < var_counter; ++i) {
        s += variables[i];
        if (i != var_counter - 1){
            s += ",";
        }
    }
    s += ",Semester,Course,Marks,Discipline";
    s += ",Semester,Course,Marks,Discipline";
    s += ",Semester,Course,Marks,Discipline";
    s += ",Semester,Course,Marks,Discipline";
    s += ",Semester,Course,Marks,Discipline";
    s += "\n";
    for (const auto& i : students) {
        //SID,Degree,Semester,Course,Marks,Discipline
        campus = i.campus;
        s += i.SID + ","+ i.St_Name + "," + i.Father_Name + "," + i.Gender + "," + i.Address + "," + i.Date_of_Birth + "," + i.Reg_Date + "," + i.Reg_Status  + "," + i.Degree_Status + "," + i.Last_Degree;
        for (const auto& j : courses ) {
            degree = j.Degree;
            if (j.SID == i.SID) {
                s += *",";
                s += j.Semester + "," + j.Course + "," + j.Marks + "," + j.Discipline;
                //s += *",";
            }
        }
        s += ",";
        s += degree;
        s += ",";
        s += campus;
        //s.append(degree + "," + campus);
        s  += "\n";
    }
    output_file << s;
    output_file.close();*/
    cout<<"\nTotally done!!!\n";
    string discipline_from_FS;
    string PATH = R"(C:\Users\hithe\projects\university-work\CS112\Semester_II_Project\CS112-B Semester Project Data\Lahore)";
    for (const auto & directoryEntry : FS::directory_iterator(PATH)){
        if (directoryEntry.path().filename().string().find("MS") != std::string::npos) {
            discipline_from_FS = "MS";
            cout<<directoryEntry.path().filename()<<endl;
        }
        else {
            discipline_from_FS = "CS";
        }

        /*
         fstream input_file(R"(C:\Users\hithe\projects\university-work\CS112\Semester_II_Project\Semester_II_Project_UI_CLI\Lhr_Student_94.txt)", ios::in);
    string src, var_names;
    getline(input_file, var_names);
    var_names += ',';
    string var;
    vector<string> variables;
    vector<string> entities;
    int var_counter = 0;
    for (int i = 0; var_names[i] != '\0'; ++i) {
        if (var_names[i] == ','){
            variables.push_back(var);
            var_counter++;
            var = "";
            continue;
        }
        var += var_names[i];
    }

    /*for (const auto& iyt : variables) {
        cout<<iyt<<" | ";
    }
        cout<<endl;

        while(getline(input_file, src)){
            src+=",";

            for (int i = 0; src[i] != '\0'; ++i) {
                if (src[i] == ','){
                    entities.push_back(var);
                    var = "";
                    continue;
                }
                var += src[i];
            }

            student->SID = entities[0];
            student->St_Name = entities[1];
            student->Father_Name = entities[2];
            student->Gender = entities[3];
            student->Address = entities[4];
            student->Date_of_Birth = entities[5];
            student->Reg_Date = entities[6];
            student->Reg_Status = entities[7];
            student->Degree_Status = entities[8];
            student->Last_Degree = entities[9];
            student->campus = "lhr";
            students.push_back(*student);
            entities.clear();
        }
        input_file.close();
        */


    }

    /*for (const auto& i : courses ) {
        i.Display();
    }*/
    //cout<<"number of variables: "<<var_counter<<endl;

    return 0;
}
/*
bool isPresent(const stirng& a, const list<Course>& b){
    for (const auto& i:b) {
        if (i.SID == a)return true;
    }
    return false;
}*/