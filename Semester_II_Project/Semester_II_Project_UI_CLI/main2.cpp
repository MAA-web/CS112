#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <filesystem>
#include <chrono>
#include <set>
using namespace std;

namespace FS = std::filesystem;

class Student {
public:
    string SID{};
    string St_Name{}, Father_Name{}, Address{}, Degree_Status{}, Last_Degree{}, Campus{}, Degree{}, City{};
    vector<string> Date_of_Birth;// = new int[3];
    vector<string> Reg_Date;// = new int[3];
    string  Gender{}, stfirst{}, stlast{}, ftfirst{}, stftlast{};
    string Reg_Status{};
    Student(void) = default;
    ~Student(void) = default;

    //void Display() const {
    //    cout << this->SID << " " << this->St_Name << " " << this->Father_Name << " " << this->Gender << " " << Address << " " << this->Date_of_Birth[2] << " " << this->Reg_Date[2] << " " << this->Reg_Status << " " << this->Degree_Status << " " << this->Last_Degree << " " << this->Campus << " " << this->Degree << " " << this->City << endl;
    //}
};

class Course {
public:

    string c_SID{}, Degree{}, Semester{}, c_Course{}, Marks{}, Discipline{}, Campus{};
    Course(void) = default;
    //void Display() const {
        //    cout << SID << " " << Degree << " " << Semester << " " << Course << " " << Marks << " " << Discipline << " " << Campus << endl;
    //}
};
    int nulls = 0, null_st = 0, null_ft = 0, null_ad = 0;
    int invalids = 0, inv_mark = 0, inv_dob = 0, inv_regd = 0;
string stfirsttokenizer(string src, string b) {
    string var;
    vector<string> vec_s;
    vector<string> vec_f;
    src += " ";
    for (int i = 0; src[i] != '\0'; ++i) {
        if (src[i] == ' ') {// || src[i] == '-') {
            vec_s.push_back(var);
            var = "";
            continue;
        }
        var += src[i];
    }
    var = "";
    b += ' '; // A Z S    Z M S
    for (int i = 0; b[i] != '\0'; ++i)
    {
        if (b[i] == ' ')
        {
            vec_f.push_back(var);
            var = "";
            continue;
        }
        var += b[i];
    }
    string first_name;
    bool should_add = true;
    for (const auto& i : vec_s)
    {
        should_add = true;
        for (const auto& j : vec_f)
        {
            if (i == j)
            {
                should_add = false;
            }

        }

        if (should_add) { first_name += i + ' '; }
    }
    return first_name;
}

vector<string> string_tokenizer(string);

string ftfirsttokenizer(string src, string b) {
    string var;
    vector<string> vec_s;
    vector<string> vec_f;
    src += " ";
    for (int i = 0; src[i] != '\0'; ++i) {
        if (src[i] == ' ') {// || src[i] == '-') {
            vec_s.push_back(var);
            var = "";
            continue;
        }
        var += src[i];
    }
    var = "";
    b += ' ';
    for (int i = 0; b[i] != '\0'; ++i)
    {
        if (b[i] == ' ')
        {
            vec_f.push_back(var);
            var = "";
            continue;
        }
        var += b[i];
    }
    string first_name;
    bool should_add = true;
    for (const auto& j : vec_f)
    {
        should_add = true;
        for (const auto& i : vec_s)
        {
            if (i == j)
            {
                should_add = false;
            }
        }
        if (should_add) {
            first_name += j + ' ';
        }
    }
    //cout<<first_name;
    if (first_name.empty() || (first_name.size() - 1) == src.size()) {
        return *string_tokenizer(b).begin();
    }
    return first_name;
}

string stlasttokenizer(string src, string b) {
    string var;
    vector<string> vec_s;
    vector<string> vec_f;
    src += " ";
    for (int i = 0; src[i] != '\0'; ++i) {
        if (src[i] == ' ') {// || src[i] == '-') {
            vec_s.push_back(var);
            var = "";
            continue;
        }
        var += src[i];
    }
    var = "";
    b += ' ';
    for (int i = 0; b[i] != '\0'; ++i)
    {
        if (b[i] == ' ')
        {
            vec_f.push_back(var);
            var = "";
            continue;
        }
        var += b[i];
    }

    /*for (const auto& i : vec_f){
        cout<<i<<" ";
    }

    for (const auto& i : vec_s){
        cout<<i<<" ";
    }*/
    string last_name;
    for (const auto& i : vec_s)
    {
        for (const auto& j : vec_f)
        {
            if (i == j)
            {
                last_name += j + ' ';
            }

        }
    }
    //cout<<last_name;
    if (last_name.empty() || (last_name.size() - 1) == src.size()) {
        return string_tokenizer(src)[0];
    }
    return last_name;
}


vector<string> string_tokenizer(string src) {
    string var;
    vector<string> vec_s;
    if (src.empty())
    {
        vec_s.push_back("U");
        return vec_s;
    }
    
    src += " ";
    for (int i = 0; src[i] != '\0'; ++i) {
        if (src[i] == ' ') {// || src[i] == '-') {
            vec_s.push_back(var);
            var = "";
            continue;
        }
        var += src[i];
    }
    return vec_s;
}
vector<string> all_names;
[[maybe_unused]] void put_in_file(string string_to_tokenize, const string& file_name, const string& gender, const string& check) {
    string var;
    vector<string> vec_s;
    string_to_tokenize += " ";
    ofstream file(file_name, ios::app);
    for (int i = 0; string_to_tokenize[i] != '\0'; ++i) {
        if (string_to_tokenize[i] == ' ') {
            vec_s.push_back(var);
            var = "";
            continue;
        }
        var += string_to_tokenize[i];
    }
    bool should_add_to_file = true;
    for (const auto& hi : all_names) {
        if (vec_s[0] == hi) {
            should_add_to_file = false;
            break;
        }
    }

    if (should_add_to_file) {
        all_names.push_back(vec_s[0]);
        if (gender == check) {
            file << vec_s[0] << "\n";
        }
    }
    file.close();
}

int Alice_Jardine(const string& string_to_tokenize, string f_p, string m_p) {
    string line, first_name = string_tokenizer(string_to_tokenize)[0];
    ifstream file(f_p);
    while (getline(file, line)) {
        if (string_to_tokenize.find(line)) {
            return 1;
        }
    }
    file.close();
    ifstream file1(m_p);
    while (getline(file1, line)) {
        if (line == first_name) {
            return 0;
        }
    }
    file1.close();
    return 3;
}

string City_Searcher(string adrr, vector<string> cities) {
    for (auto& i : cities) {
        if (adrr.find(i) != std::string::npos) { return i; }
    }
    return "U";
}
//string_tokenizer_for_(){

//}
vector<string> date_tokenizer(string src) {
    //int* date_ = new int[3];
    //auto * date_vec = new vector<int>;
    //*date_vec = string_tokenizer_for_();
    
    
    string var;
    vector<string> vec_s;
    if (src.empty())
    {nulls++;
        vec_s.push_back("-1");
        vec_s.push_back("0");
        vec_s.push_back("0");
        return vec_s;
    }
    src += "-";
    for (int i = 0; src[i] != '\0'; ++i) {
        if (src[i] == '-') {// || src[i] == '-') {
            if (var == "Jan") var = "1";
            else if (var == "Feb") var = "2";
            else if (var == "Mar") var = "3";
            else if (var == "Apr") var = "4";
            else if (var == "May") var = "5";
            else if (var == "Jun") var = "6";
            else if (var == "Jul") var = "7";
            else if (var == "Aug") var = "8";
            else if (var == "Sep") var = "9";
            else if (var == "Oct") var = "10";
            else if (var == "Nov") var = "11";
            else if (var == "Dec") var = "12";
            vec_s.push_back(var);
            var = "";
            continue;
        }
        var += src[i];
    }

    return vec_s;
}


auto students = new list<Student>;
auto courses = new list<Course>;
Student student;
Course course;

//<-------------------------------------------------------------------------------------------------------------------------------------------------->

/*
std::string toStandardString(System::String^ str) {
    using System::Runtime::InteropServices::Marshal;
    System::IntPtr pointer = Marshal::StringToHGlobalAnsi(str);
    char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
    std::string returnString(charPointer, str->Length);
    Marshal::FreeHGlobal(pointer);
    return returnString;
}*/

int main() {
    string file_path, cities_path, females_path , males_path, cities_lookup;
    string src, var_names, var;
    //auto number_of_students_batches = new vector<int>;
    //auto city_lookup_map = new map<string, string>;
    cout<<"Type the folder path with Lahore and Peshawar databases: ";
    getline(cin, file_path);
    cout<<"Type the file path of the cities file: ";
    getline(cin, cities_path);
    cout<<"Type the file path for the cities lookup: ";
    getline(cin, cities_lookup);
    cout<<"Type the file path for the female lookup file: ";
    getline(cin, females_path);
    cout<<"Type the file path for the male lookup file: ";
    getline(cin, males_path);
    //file_path = "C:\\Users\\hithe\\projects\\university-work\\CS112\\Semester_II_Project\\Semester_II_Project_UI_CLI\\New folder";
    /*file_path = R"(C:\Users\hithe\projects\university-work\CS112\Semester_II_Project\CS112-B Semester Project Data)";
    cities_path = R"(C:\Users\hithe\OneDrive\Desktop\PakistanCitiesList.txt)";
    females_path = R"(C:\Users\hithe\OneDrive\Desktop\females.txt)";
    males_path = R"(C:\Users\hithe\OneDrive\Desktop\males.txt)";
    cities_lookup = "C:\\Users\\hithe\\OneDrive\\Desktop\\Cities_Lookup.txt";*/



    //auto city_names = new vector<string>;
    vector<string> city_names;
    fstream city_file(cities_path, ios::in);
    while (getline(city_file, src)) {
        //cout<<src<<" ";
        city_names.push_back(src);
    }

    //for (const auto& i : city_names) {
    //    cout<<i<<"\n";
    //}
    city_file.close();
    int number_of_lhr_batches_bs = 0, number_of_psh_batches_bs = 0;
    int number_of_lhr_batches_ms = 1, number_of_psh_batches_ms = 1;
    int lahore_batches = 0, peshawar_batches = 0, number_of_females = 0, number_of_males = 0;
    vector<string> entities;
    string degree_from_FS, campus_from_FS;
    auto un_sid = new set<string>;
    auto un_date_y = new set<string>;
    auto un_fstn = new set<string>;
    auto un_lstn = new set<string>;
    auto un_ftfstn = new set<string>;
    auto un_cit = new set<string>;

    auto start = chrono::high_resolution_clock::now();
    //string general_PATH = R"(C:\Users\hithe\projects\university-work\CS112\Semester_II_Project\CS112-B Semester Project Data)";
    //string general_PATH = R"(C:\Users\hithe\projects\university-work\CS112\Semester_II_Project\Semester_II_Project_UI_CLI\New folder)";
    string general_PATH = file_path;
    //string general_PATH = R"(C:\Users\hithe\projects\university-work\CS112\Semester_II_Project\Semester_II_Project_UI_CLI\New folder (2))";
    for (const auto& i_j : FS::directory_iterator(general_PATH)) {
        //    string PATH = R"(C:\Users\hithe\projects\university-work\CS112\Semester_II_Project\CS112-B Semester Project Data\Lahore)";
        string PATH = i_j.path().string();
        //string PATH = R"(C:\Users\hithe\projects\university-work\CS112\Semester_II_Project\Semester_II_Project_UI_CLI\New folder)";
        for (const auto& directoryEntry : FS::directory_iterator(PATH)) {
            std::cout << "Reading: " << directoryEntry.path().filename() << endl;
            if (directoryEntry.path().filename().string().find("MS") != std::string::npos) {
                degree_from_FS = "MS";
            }
            else {
                degree_from_FS = "BS";
            }
            if (directoryEntry.path().filename().string().find("Lhr") != std::string::npos) {
                campus_from_FS = "Lahore"; lahore_batches++;
            }
            else {
                campus_from_FS = "Peshawar"; peshawar_batches++;
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
                if (campus_from_FS == "Lahore" && degree_from_FS == "BS") { number_of_lhr_batches_bs++; }
                else if (campus_from_FS == "Lahore" && degree_from_FS == "MS") {
                    number_of_lhr_batches_ms++;
                }
                else if (campus_from_FS == "Peshawar" && degree_from_FS == "BS") { number_of_psh_batches_bs++; }
                else if (campus_from_FS == "Peshawar" && degree_from_FS == "MS") {
                    number_of_psh_batches_ms++;
                }
                while (getline(input_file, src)) {
                    src += ",";

                    for (int i = 0; src[i] != '\0'; ++i) {
                        if (src[i] == ',') {
                            entities.push_back(var);
                            var = "";
                            continue;
                        }
                        var += src[i];
                        //cout<<entities.size();
                    }
                    if (campus_from_FS == "Lahore") {
                        //for (auto i : entities)std::cout<<i<<"......";
                        //if (entities.size() >= 10)
                        //{
                            student.SID = entities[0];
                            un_sid->insert(entities[0]);

                            student.St_Name = entities[1];
                            student.stfirst = stfirsttokenizer(entities[1], entities[2]);
                            un_fstn->insert(student.stfirst);

                            student.stftlast = stlasttokenizer(entities[1], entities[2]);
                            un_lstn->insert(student.stftlast);

                            student.ftfirst = ftfirsttokenizer(entities[1], entities[2]);
                            un_ftfstn->insert(student.ftfirst);

                            student.Father_Name = entities[2];
                            if (entities[3] == "1") {
                                student.Gender = "F";
                                number_of_females++;
                            }
                            else {
                                student.Gender = "M";
                                number_of_males++;
                            }
                            student.Address = entities[4];
                            student.Date_of_Birth = date_tokenizer(entities[5]);
                            student.Reg_Date = date_tokenizer(entities[6]);
                            student.Reg_Status = entities[7];
                            student.Degree_Status = entities[8];
                            student.Last_Degree = entities[9];
                            student.Campus = campus_from_FS;
                            student.Degree = degree_from_FS;
                            student.City = City_Searcher(entities[4], city_names);
                            un_cit->insert(student.City);
                            //if (student.St_Name.empty() || student.Father_Name.empty() || student.Address.empty())
                            //{
                            //    nulls++;
                            //}

                            students->push_back(student);
                            entities.clear();
                        //}
                        //input_file.close();
                    }
                    
                    else if (campus_from_FS == "Peshawar") {
                        //if (entities.size() >= 9)
                        //{
                            
                            student.SID = entities[0];
                            un_sid->insert(entities[0]);

                            student.St_Name = entities[1];
                            student.stfirst = stfirsttokenizer(entities[1], entities[2]);
                            un_fstn->insert(student.stfirst);

                            student.stftlast = stlasttokenizer(entities[1], entities[2]);
                            un_lstn->insert(student.stftlast);

                            student.ftfirst = ftfirsttokenizer(entities[1], entities[2]);
                            un_ftfstn->insert(student.ftfirst);

                            student.Father_Name = entities[2];
                            // TODO make a different function for father's last name
                            if (Alice_Jardine(entities[1], females_path, males_path) == 1) {
                                student.Gender = 'F';
                                number_of_females++;
                            }
                            else {
                                student.Gender = 'M';
                                number_of_males++;
                            }

                            student.Address = entities[3];
                            student.Date_of_Birth = date_tokenizer(entities[4]);
                            student.Reg_Date = date_tokenizer(entities[6]);
                            student.Reg_Status = entities[7];
                            student.Degree_Status = entities[8];
                            student.Last_Degree = entities[5];
                            student.Campus = campus_from_FS;
                            student.Degree = degree_from_FS;
                            student.City = City_Searcher(entities[3], city_names);
                            un_cit->insert(student.City);
                            if (student.St_Name.empty() || student.Father_Name.empty() || student.Address.empty())
                            {
                                nulls++;
                                if (student.St_Name.empty())null_st++;
                                if (student.Father_Name.empty())null_ft++;
                                if (student.Address.empty())null_ad++;
                            }
                            students->push_back(student);
                            entities.clear();
                        //}
                    }
                    
                    //entities.clear();
                }
                input_file.close();
            }

            if (directoryEntry.path().filename().string().find("Detail") != std::string::npos ||
                directoryEntry.path().filename().string().find("Reg") != std::string::npos) {
                if (directoryEntry.path().filename().string().find("MS") != std::string::npos) {
                    degree_from_FS = "MS";
                }
                else {
                    degree_from_FS = "BS";
                }
                if (directoryEntry.path().filename().string().find("Lhr") != std::string::npos) {
                    campus_from_FS = "Lahore";
                }
                else {
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
                        course.c_SID = entities[0];
                        course.Degree = entities[1];
                        course.Semester = entities[2];
                        course.c_Course = entities[3];
                        course.Marks = entities[4];
                        if (!course.Marks.empty() && stoi(course.Marks) >= 100 && stoi(course.Marks) <= 0)
                        {
                            invalids++; inv_mark++;
                        }
                        course.Discipline = entities[5];
                        course.Campus = campus_from_FS;
                        courses->push_back(course);
                    }
                    else if (campus_from_FS == "Peshawar") {
                        course.c_SID = entities[0];
                        course.Degree = degree_from_FS;
                        course.Semester = entities[4] + entities[5][2] + entities[5][3];
                        course.c_Course = entities[1];
                        course.Marks = entities[2];
                        if (!course.Marks.empty() && stoi(course.Marks) >= 100 && stoi(course.Marks) <= 0)
                        {
                            invalids++; inv_mark++;
                        }
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
    int number_of_courses = 0;
    set<string> course_names;
    for (auto const& i : *courses) {
        course_names.insert(i.c_Course);
    }

    for (const auto& i : course_names) {
        //cout<<i<<" ";
        number_of_courses++;
    }


    int students_batches_psh_bs = 0, students_batches_lhr_bs = 0;
    int students_batches_psh_ms = 0, students_batches_lhr_ms = 0;
    vector<string> city_lookup_vec;
    string dob;
    string reg_d;
    for (auto& i : *students) {
        if (i.Campus == "Lahore" && i.Degree == "BS") {
            students_batches_lhr_bs++;
        }
        else if (i.Campus == "Lahore" && i.Degree == "MS") {
            students_batches_lhr_ms++;
        }
        else if (i.Campus == "Peshawar" && i.Degree == "BS") {
            students_batches_psh_bs++;
        }
        else if (i.Campus == "Peshawar" && i.Degree == "MS") {
            students_batches_psh_ms++;
        }
        un_date_y->insert(i.Date_of_Birth[2]);
        if (i.City == "U")
        {   
            vector<string> ad_vec;
            ad_vec = string_tokenizer(i.Address);
            ifstream city_lookup_file(cities_lookup, ios::in);
            while (getline(city_lookup_file, src)) {
                city_lookup_vec = string_tokenizer(src);
                if (ad_vec[ad_vec.size()-1] == city_lookup_vec[0])
                {
                    i.City = city_lookup_vec[1];
                }
            }
            city_lookup_file.close();
        }
        if (stoi(i.Reg_Date[2]) < 50 && i.Reg_Date[0] != "-1") {
            if (stoi(i.Date_of_Birth[2]) < stoi(i.Reg_Date[2]))
            {
                invalids++; inv_dob++; dob = i.Date_of_Birth[2];
                i.Date_of_Birth[2] = i.Reg_Date[2];
                i.Reg_Date[2] = dob;
            }
        }
        if (stoi(i.Reg_Date[2]) > 50 && i.Reg_Date[0] != "-1") {
            if (stoi(i.Date_of_Birth[2]) > stoi(i.Reg_Date[2]))
            {
                invalids++; inv_regd++; dob = i.Date_of_Birth[2];
                i.Date_of_Birth[2] = i.Reg_Date[2];
                i.Reg_Date[2] = dob;
            }
        }
    }

    //int counter = 0;
    //for (const auto& i : *students) {
    //    if (i.City == "U") {
    //        i.Display();
    //        counter++;
    //    }
    //}

    //cout<<"number: "<<counter;
    //int progress = 0;
    ofstream output_file("results.txt", ios::out);
    output_file << "SID,St_Name,St_first_name,St_last_name,Father_Name,Father_first_name,Father_last_name,Gender,Address,City,Date of Birth,Reg Date,Reg_status,Degree_status,Last_Degree,Campus,Degree,Semester,Course,Marks\n";
    string s;
    std::string Disc, campus;
    auto Course_students_5 = new list<Student>;
    int counter = 0;
    int people_5 = 0;
    for (const auto& stu : *students) {
        s = "";
        campus = stu.Campus;
        s += stu.SID + "," + stu.St_Name + "," + stu.stfirst + "," + stu.stftlast + "," + stu.Father_Name + "," + stu.ftfirst + "," + stu.stftlast + "," + stu.Gender + "," + stu.Address + "," + stu.City + "," + stu.Date_of_Birth[0] + "-" + stu.Date_of_Birth[1] + "-" + stu.Date_of_Birth[2] + "," + stu.Reg_Date[0] + "-" + stu.Reg_Date[1] + "-" + stu.Reg_Date[2] + "," + stu.Reg_Status + "," + stu.Degree_Status + "," + stu.Last_Degree + "," + stu.Campus + "," + stu.Degree;
        counter = 0;
        for (const auto& cors : *courses) {
            Disc = cors.Discipline;
            if (cors.c_SID == stu.SID && cors.Degree == stu.Degree && cors.Campus == stu.Campus) {
                s += ",";
                s += cors.Semester + "," + cors.c_Course + "," + cors.Marks;// + "," + cors.Discipline;
                counter++;
            }
        }
        s += "," + Disc+"\n";
        //if (stu.City == "U")
        //Console::WriteLine(s);
        //std::cout<<s;
        if ((counter / 8) > 5) {
            people_5++;
        }
        output_file << s;
        //progress++;
    }
    
    //output_file.close();
    s = "";
    s += "\nStudents in Lahore(MS): " + to_string(students_batches_lhr_ms) + "\n";
    s += "Students in Lahore(BS): " + to_string(students_batches_lhr_bs) + "\n";
    s += "Students in Peshawar(MS): " + to_string(students_batches_psh_ms) + "\n";
    s += "Students in Peshawar(BS): " + to_string(students_batches_psh_bs) + "\n";
    s += "Total students: " + to_string(students_batches_lhr_bs + students_batches_lhr_ms + students_batches_psh_ms + students_batches_psh_bs) + "\n";
    s += "Time taken to read files: " + to_string(TotalTime.count()) + "\n";
    s += "No. of people with more than 5 courses: " + to_string(people_5) + "\n";
    s += "No. of courses: " + to_string(number_of_courses)+"\n";
    s += "No. of Males: " + to_string(number_of_males) + "\n";
    s += "No. of Females: " + to_string(number_of_females)+"\n";
    s += "Average no of students in every batch of Lahore campus(BS): " + to_string(students_batches_lhr_bs / number_of_lhr_batches_bs) + "\n";
    s += (string)"Average no of students in every batch of Peshawar campus(BS): " + to_string(students_batches_psh_bs / number_of_psh_batches_bs) + "\n";
    s += (string)"Average no of students in every batch of Lahore campus(MS): " + to_string(students_batches_lhr_ms / number_of_lhr_batches_ms) + "\n";
    s += (string)"Average no of students in every batch of Peshawar campus(MS): " + to_string(students_batches_psh_ms / number_of_psh_batches_ms) + "\n";
    s += (string)"Average no of people per semester of Lahore campus(BS): " + to_string((students_batches_lhr_bs / number_of_lhr_batches_bs) / 8) + "\n";
    s += (string)"Average no of people per semester of Peshawar campus(BS): " + to_string((students_batches_psh_bs / number_of_psh_batches_bs) / 8) + "\n";
    s += (string)"Average no of people per semester of Lahore campus(MS): " + to_string((students_batches_lhr_ms / number_of_lhr_batches_ms) / 4) + "\n";
    s += (string)"Average no of people per semester of Peshawar campus(MS): " + to_string((students_batches_psh_ms / number_of_psh_batches_ms) / 4) + "\n";
    s += (string)"Number of unique cities: " + to_string(un_cit->size()) + "\n";
    s += (string)"Number of unique birth day years: " + to_string(un_date_y->size()) + "\n";
    s += (string)"Number of unique first names: " + to_string(un_fstn->size()) + "\n";
    s += (string)"Number of unique father first names: " + to_string(un_ftfstn->size()) + "\n";
    s += (string)"Number of unique Student Ids: " + to_string(un_sid->size()) + "\n";
    s += (string)"Number of unique last names: " + to_string(un_lstn->size()) + "\n";
    s += (string)"\t\tTotal invalids: " + to_string(invalids) + "\n";
    s += (string)"\t\tTotal nuls: " + to_string(nulls) + "\n";
    s += (string)"Invalid Date of Births: " + to_string(inv_dob) + "\n";
    s += (string)"Invalid Marks: " + to_string(inv_mark) + "\n";
    s += (string)"Invalid registration date: " + to_string(inv_regd) + "\n";
    s += (string)"Null adresses: " + to_string(null_ad) + "\n";
    s += (string)"Null Student Names: " + to_string(null_st) + "\n";
    s += (string)"Null Father Names: " + to_string(null_ft) + "\n";
    output_file << s;
    delete students;
    delete courses;
    delete un_cit;
    delete un_fstn;
    delete un_ftfstn;
    delete un_lstn;
    delete un_sid;
    output_file.close();
    std::cout<<s;
    return 0;
}
