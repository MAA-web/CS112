#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <list>
#include <string>
#include <filesystem>
#include <chrono>
using namespace std;
namespace FS = std::filesystem;
class Student {
public:
    string SID, St_Name, Father_Name, Gender, Address, Date_of_Birth, Reg_Date, Reg_Status, Degree_Status, Last_Degree, Campus, Degree, City;
    void Display() const{
        cout<<this->SID<<" "<<this->St_Name<<" "<<this->Father_Name<<" "<<this->Gender<<" "<<Address<<" "<<this->Date_of_Birth<<" "<<this->Reg_Date<<" "<<this->Reg_Status<<" "<<this->Degree_Status<<" "<<this->Last_Degree<<" "<<this->Campus<<" "<< this->Degree<<" "<<this->City<<endl;
    }
};

class Course {
public:

    string SID, Degree, Semester, Course, Marks, Discipline, Campus;
    void Display() const{
        cout<<SID<<" "<<Degree<<" "<<Semester<<" "<<Course<<" "<<Marks<<" "<<Discipline<<" "<<Campus<<endl;
    }
};

vector<string> string_tokenizer(string src){
    string var;
    vector<string> vec_s;
    src += " ";
    for (int i = 0; src[i] != '\0'; ++i) {
        if (src[i] == ' '){// || src[i] == '-') {
            vec_s.push_back(var);
            var = "";
            continue;
        }
        var += src[i];
    }
    return vec_s;
}
vector<string> all_names;
void put_in_file(string string_to_tokenize, const string& file_name, const string& gender, const string &check){
    string var;
    vector<string> vec_s;
    string_to_tokenize += " ";
    for (int i = 0; string_to_tokenize[i] != '\0'; ++i) {
        if (string_to_tokenize[i] == ' ') {
            vec_s.push_back(var);
            var = "";
            continue;
        }
        var += string_to_tokenize[i];
    }
    bool should_add_to_file = true;
    for (const auto& hi : all_names){
        if (vec_s[0] == hi) {
            should_add_to_file = false;
            break;
        }
    }

    if (should_add_to_file) {
        all_names.push_back(vec_s[0]);
        ofstream file(file_name, ios::app);
        if (gender == check) {
            file << vec_s[0] << "\n";
        }
        file.close();
    }
}

int Alice_Jardine(const string& string_to_tokenize){
    string line, first_name = string_tokenizer(string_to_tokenize)[0];
    ifstream file("females.txt");
    while(getline(file, line)){
        if (string_to_tokenize.find(line)){
            return 1;
        }
    }
    file.close();
    ifstream file1("males.txt");
    while(getline(file1, line)){
        if (line == first_name){
            return 0;
        }
    }
    file1.close();
    return 3;
}

string City_Searcher(string adrr){
    vector<string> address = string_tokenizer(adrr);
    vector<string> search_vec;
    string search_str;
    ifstream file("Pakistan_Cities_Sanitised.txt");
    while (getline(file, search_str)) {
        search_vec = string_tokenizer(search_str);
        for (auto const &str: address) {
            for (auto const &i: search_vec) {
                if (str == i) {return str; };
            }
        }
    }
    file.close();
    return "U";
}

auto students = new list<Student>;
auto courses = new list<Course>;
Student student;
Course course;
int main() {
    string src, var_names, var;
    vector<string> entities;
    string degree_from_FS, campus_from_FS;
    auto start = chrono::high_resolution_clock::now();
    string general_PATH = R"(C:\Users\hithe\projects\university-work\CS112\Semester_II_Project\CS112-B Semester Project Data)";
    //string general_PATH = R"(C:\Users\hithe\projects\university-work\CS112\Semester_II_Project\Semester_II_Project_UI_CLI\New folder)";
    for (const auto & i_j : FS::directory_iterator(general_PATH)) {
//    string PATH = R"(C:\Users\hithe\projects\university-work\CS112\Semester_II_Project\CS112-B Semester Project Data\Lahore)";
        string PATH = i_j.path().string();
        //string PATH = R"(C:\Users\hithe\projects\university-work\CS112\Semester_II_Project\Semester_II_Project_UI_CLI\New folder)";
        for (const auto &directoryEntry: FS::directory_iterator(PATH)) {
            cout << "Reading: " << directoryEntry.path().filename() << endl;
            if (directoryEntry.path().filename().string().find("MS") != std::string::npos) {
                degree_from_FS = "MS";
            } else {
                degree_from_FS = "BS";
            }
            if (directoryEntry.path().filename().string().find("Lhr") != std::string::npos) {
                campus_from_FS = "Lahore";
            } else {
                campus_from_FS = "Peshawar";
            }

            if (directoryEntry.path().filename().string().find("Student") != std::string::npos) {
                fstream input_file(directoryEntry.path(), ios::in);
                getline(input_file, var_names);
                /*int var_counter = 0;
                for (int i = 0; var_names[i] != '\0'; ++i) {
                    if (var_names[i] == ',') {
                        variables.push_back(var);
                        var_counter++;
                        var = "";
                        continue;
                    }
                    var += var_names[i];
                }*/

                /*for (const auto &iyt: variables) {
                    cout << iyt << " | ";
                }*/
                // cout<<endl;

                while (getline(input_file, src)) {
                    src += ",";

                    for (int i = 0; src[i] != '\0'; ++i) {
                        if (src[i] == ',') {
                            entities.push_back(var);
                            var = "";
                            continue;
                        }
                        var += src[i];
                    }
                    if (campus_from_FS == "Lahore") {
                        student.SID = entities[0];
                        student.St_Name = entities[1];
                        student.Father_Name = entities[2];
                        entities[3] == "0" ? student.Gender = "M" : student.Gender = "F";
                        student.Address = entities[4];
                        student.Date_of_Birth = entities[5];
                        student.Reg_Date = entities[6];
                        student.Reg_Status = entities[7];
                        student.Degree_Status = entities[8];
                        student.Last_Degree = entities[9];
                        student.Campus = campus_from_FS;
                        student.Degree = degree_from_FS;
                        //student.City = City_Searcher(entities[4]);
                        /*if (student->Gender == "F")
                            put_in_file(student->St_Name, "females.txt", student->Gender, "F");
                        if (student->Gender == "M")
                            put_in_file(student->St_Name, "males.txt", student->Gender, "M");
                        */
                        students->push_back(student);
                    } else if (campus_from_FS == "Peshawar") {
                        student.SID = entities[0];
                        student.St_Name = entities[1];
                        student.Father_Name = entities[2];
                        if (Alice_Jardine(entities[1]) == 0){
                            student.Gender = 'M';
                        }
                        else if (Alice_Jardine(entities[1]) == 1){
                            student.Gender = 'F';
                        }
                        else {
                            student.Gender = 'U';
                        }

                        student.Address = entities[3];
                        student.Date_of_Birth = entities[4];
                        student.Reg_Date = entities[5];
                        student.Reg_Status = entities[6];
                        student.Degree_Status = entities[7];
                        student.Last_Degree = entities[8];
                        student.Campus = campus_from_FS;
                        student.Degree = degree_from_FS;
                        //student.City = City_Searcher(entities[3]);
                        students->push_back(student);
                    }
                    entities.clear();
                }
                input_file.close();
            }

            if (directoryEntry.path().filename().string().find("Detail") != std::string::npos ||
                directoryEntry.path().filename().string().find("Reg") != std::string::npos) {
                if (directoryEntry.path().filename().string().find("MS") != std::string::npos) {
                    degree_from_FS = "MS";
                } else {
                    degree_from_FS = "BS";
                }
                if (directoryEntry.path().filename().string().find("Lhr") != std::string::npos) {
                    campus_from_FS = "Lahore";
                } else {
                    campus_from_FS = "Peshawar";
                }
                //auto *course = new Course;
                entities.clear();
                src = "";
                fstream input_file_details(
                        directoryEntry.path(),
                        ios::in);
                getline(input_file_details, src);
                while (getline(input_file_details, src)) {
                    src += ",";

                    for (int i = 0; src[i] != '\0'; ++i) {
                        if (src[i] == ',') {
                            entities.push_back(var);
                            var = "";
                            continue;
                        }
                        var += src[i];
                    }
                    if (campus_from_FS == "Lahore") {
                        course.SID = entities[0];
                        course.Degree = entities[1];
                        course.Semester = entities[2];
                        course.Course = entities[3];
                        course.Marks = entities[4];
                        course.Discipline = entities[5];
                        course.Campus = campus_from_FS;
                        courses->push_back(course);
                    } else if (campus_from_FS == "Peshawar") {
                        course.SID = entities[0];
                        course.Degree = degree_from_FS;
                        course.Semester = entities[4] + entities[5][2] + entities[5][3];
                        course.Course = entities[1];
                        course.Marks = entities[2];
                        course.Discipline = entities[3];
                        course.Campus = campus_from_FS;
                        courses->push_back(course);
                    }
                    entities.clear();
                }
                input_file_details.close();
            }
        }
    }
    auto end = chrono::high_resolution_clock::now();
    const auto TotalTime = chrono::duration_cast<chrono::milliseconds>(end - start);

    //for (const auto& i : *students) {
    //    if (i.City == "U")i.Display();
    //}



    auto output_file_string = new string;
    fstream output_file("TEST_list_back.csv", ios::out);
    string s, Disc, campus;
    
    for (const auto& stu : *students) {
        s = "";
        campus = stu.Campus;
        s += stu.SID + ","+ stu.St_Name + "," + stu.Father_Name + "," + stu.Gender + "," + stu.Address + "," + stu.City + "," + stu.Date_of_Birth + "," + stu.Reg_Date + "," + stu.Reg_Status  + "," + stu.Degree_Status + "," + stu.Last_Degree + "," + stu.Campus + "," + stu.Degree;
        for (const auto& cors : *courses ) {
            Disc = cors.Discipline;
            if (cors.SID == stu.SID && cors.Degree == stu.Degree && cors.Campus == stu.Campus) {
                s += ",";
                s += cors.Semester + "," + cors.Course + "," + cors.Marks;// + "," + cors.Discipline;
            }
        }
        s  += "," + Disc + "\n";    
        cout << s;
        output_file << s;    
    }
    
    output_file.close();




    cout<<"Time taken: "<<TotalTime.count()<<endl;





    //for (const auto& i : *courses ) {
    //    i.Display();//cout<<<<endl;
    //}
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