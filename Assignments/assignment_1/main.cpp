#include <iostream>
#include <utility>
#include <string>
using namespace std;

int course_present = 0;
struct Course {
    int ID{};
    string CourseName;
    string teacher;
    float fee{};
    float creditHours{};
    void PrintAll() const{
        if(ID != 0) {
            cout << "[ Course ID: " << ID << ", Course Name: " << CourseName << ", Teacher: " << teacher << ", Fee: " << fee << ", Credit Hour: " << creditHours << "]" << flush;
            course_present++;
        }
        else{
            //course_present++;
        }
    }
};

struct CourseList {
    Course courses[5];
    void PrintAll(){
        for (auto & course : courses) {
            course.PrintAll();cout<<endl;
        }
    }

    void addCourse(int index, int id, string CN, string tch, float fe, float CH){
        courses[index] = {id, std::move(CN), std::move(tch), fe, CH};
    }

    void sort(const string& srtp){
        Course temp;
        if (srtp == "ass") {
            for (int j = 0; j < 5 - 1; j++) {
                for (int i = 0; i < 5 - j - 1; i++) {
                    if (courses[i].ID > courses[i + 1].ID) {
                        temp = courses[i];
                        courses[i] = courses[i + 1];
                        courses[i + 1] = temp;
                    }
                }
            }
        }
        else{
            for (int j = 0; j < 5 - 1; j++) {
                for (int i = 0; i < 5 - j - 1; i++) {
                    if (courses[i].ID < courses[i + 1].ID) {
                        temp = courses[i];
                        courses[i] = courses[i + 1];
                        courses[i + 1] = temp;
                    }
                }
            }
        }
    }

    void show(int ID){
        courses[ID].PrintAll();
    }

    void Delete(int ID){
        for (auto & course : courses) {
            if(course.ID == ID){
                course = {0,"", "",0,0};
                break;
            }
        }
        cout<<"If this course ID exists then it has been removed otherwise, no effect has taken place"<<endl;

    }

    void DeleteAll(){
        for (auto & course : courses) {
            course = {0, "", "", 0, 0};
        }
    }

    bool check_id(int id){
        for (auto & course : courses) {
            if(course.ID == id){cout<<"Sorry this ID is already associated with a course. Choose another one: "; return true;}
        }
        return false;
    }

    bool check_index(int ind, int ID){
        if(ID == 90){
            if(courses[ind].ID == 0){return true;}
            else{cout<<"Wrong index value chosen. Type again: ";return false;}
        }
        if(ID == 1) {
            for (auto & course : courses) {
                if(course.ID == ind){return true;}
                else{cout<<"This ID is not present in the array. Type a correct one (if unsure first see all the present courses): ";return false;}
            }
        }
        return false;
    }
};

struct Student {
    int ID{};
    string StdName = " ";
    int RollNo{};
    void PrintAll() const{
        if(ID != 0){
            cout << "[ Student ID: " <<ID<<", Student Name: "<<StdName<<", Student Roll No: "<<RollNo<<"]"<<flush;
            course_present++;
        }
    }
};

struct StudentList {
    Student std[5];
    void PrintAll(){
        for (auto & i : std) {
                i.PrintAll();cout<<endl;
            }
    }

    bool check_ID(int id){
        for (auto & i : std) {
            if(i.ID == id){return true;}
        }
        return false;

    }

    bool check_rollNo(int roll){
        for (auto & i : std) {
            if (i.RollNo == roll){return true;}
        }
        return false;
    }

    int check_index(){
        for (int i = 0; i < 5; i++) {
            if(std[i].ID == 0.0){
                return i;
            }
        }
        return 60;
    }

    void Add(int index, int id, string SN, int RN){
        std[index] = {id, std::move(SN), RN};
        cout<<"\n==============Student added Successfully==============\n"<<endl;
    }

    void Delete(int id){
        int not_present = 0;
        for (auto & i : std) {
            if (i.ID == id){
                i = {0, " ", 0};
                not_present = 1;
                cout<<"\n==============Student deleted successfully.=============="<<endl;
                break;
            }
        }
        if (not_present == 0)cout<<"\n==============Student not present.==============";
    }

};

CourseList CL;
StudentList SL;

int main() {
    /*cout<< "\n\t\t*Main Menu*\n1. Add New Student.\n2. Delete Existing Student.\n3. Show all Students.\n4. Add New Course.\n5. Delete Existing Course(s)."
           "\n6. Show particular Course.\n7. Show all Courses.\n8. Sort Courses in Ascending order.\n9. Sort Courses in Descending order.\n11. Display this menu.\n0. Clears the screen.\n10. Exit\n";
*/
    cout<<
        "\n\t\t*Main Menu*\n\n"
        "\t1. Add New Student.\n"
        "\t2. Delete Existing Student.\n"
        "\t3. Show all Students.\n"
        "\t4. Add New Course.\n"
        "\t5. Delete Existing Course."
        "\n\t6. Show particular Course.\n"
        "\t7. Show all Courses.\n"
        "\t8. Sort Courses in Ascending order.\n"
        "\t9. Sort Courses in Descending order.\n"
        "\t11. Displays this menu.\n"
        "\t0. Clears the screen.\n"
        "\t10. Exit\n"
        "  --------------------------------------------\n";

    int a = 0;
    while(a != 10) {

        int ID;
        string Name = " ";
        int rn;
        int ind;
        string teacher = " ";
        float CH;
        float fee;
        string check_del;


        cout<<"\n(11 to display menu)\nChoose an option: ";
        cin >> a;
        switch (a) {
            case 1:
                cout << "==============Give the following parameters to add the new student.==============" << endl;
                cout << "Student ID: ";
                while (true) {
                    cin >> ID;
                    if(ID < 0){cout<<"Type a non-negative ID: ";continue;}
                    if (SL.check_ID(ID)) { cout<<"Type a distinct id: ";continue; }
                    else { break; }
                }
                cout << "Student Name: ";
                while (true) {
                    if(Name.empty() || Name == " ") {
                        getline(cin, Name);
                    }
                    else { break; }
                }
                cout << "Student RollNo: ";
                while (true) {
                    cin >> rn;
                    if(rn < 0){cout<<"Type a non-negative number: ";continue;}
                    if (SL.check_rollNo(rn)) { cout<<"Type a distinct roll no: ";continue; }
                    else { break; }
                }

                ind = SL.check_index();
                if (ind == 60) {
                    cout << "Sorry all the places are taken." << endl;
                    break;
                }

                SL.Add(ind, ID, Name, rn);

                break;
            case 2:
                cout << "==============Give the following parameters to delete a student.==============" << endl;
                cout << "\nStudent ID to delete: ";
                while(true){
                    cin >> ID;
                    if(ID < 0){
                        cout<<"Type a non-negative ID: ";continue;
                    }
                    else {
                        break;
                    }
                }
                SL.Delete(ID);
                break;
            case 3:
                cout << "    =========================================================================" << endl;
                SL.PrintAll();

                if (course_present == 0) {
                    cout
                            << "\n==============Sorry, but there are no students present consider entering some students by selecting option 1.=============="
                            << endl;
                } else {
                    cout << "==============Here are all the entries in the students list.==============" << endl;
                    course_present = 0;
                }
                break;

            case 4:
                cout << "==============Give the following parameters to add a new course==============" << endl;
                cout << "Course ID: ";
                while (true) {
                    cin >> ID;
                    if (ID < 0){cout<<"Type a non-negative number: ";continue;}
                    if (CL.check_id(ID)) { continue; }
                    else { break; }
                }
                cout << "Course Name: ";
                while (true) {
                    if(Name.empty() || Name == " ") {
                        getline(cin, Name);
                    }
                    else { break; }
                }
                cout << "index: ";
                while (true) {
                    cin >> ind;
                    if(ind < 0 || ind >= 5){cout<<"Type a non-negative index which is also less than 5: ";continue;}
                    if (CL.check_index(ind, 90)) { break; }
                }
                cout << "The name of the teacher the course is taught by: ";
                while (true) {
                    if(teacher == " " || teacher.empty()) {
                        getline(cin, teacher);
                    }
                    else { break; }
                }
                cout << "Fee per semester of the course: ";
                while (true){
                    cin >> fee;
                    if (fee < 0){cout<<"Type a non-negative fee: ";continue;}
                    else{break;}
                }
                cout << "The credit hours of the course: ";
                while (true){
                    cin >> CH;
                    if (CH < 0){cout<<"Type a non-negative credit hour: ";continue;}
                    else{break;}
                }
                CL.addCourse(ind, ID, Name, teacher, fee, CH);
                break;
            case 5:
                cout << "-> Delete one course or delete all (type one or all): ";
                cin >> check_del;
                if (check_del == "one") {
                    cout << "Delete an existing course by id: " << endl;
                    cout << "Course id: ";
                    while (true) {
                        cin >> ID;
                        if (ID < 0) {
                            cout << "Type correct ID: ";
                            continue;
                        } else {
                            break;
                        }
                    }
                    CL.Delete(ID);
                    break;
                } else if (check_del == "all") {
                    CL.DeleteAll();
                    cout << "All courses have been deleted." << endl;
                    break;
                } else {
                    cout << "You chose the wrong option so nothing happened." << endl;
                    break;
                }

            case 6:
                cout << "Type the id of the particular course you want to see: " << endl;
                while (true) {
                    cin >> ID;
                    if(ID < 0){cout<<"Type a non-negative id: ";continue;}
                    if (CL.check_index(ID, 1)) { break; }
                    else {break;}
                }
                CL.show(ID);
                break;
            case 7:
                cout << "    =========================================================================" << endl;
                CL.PrintAll();
                if (course_present == 0) {
                    cout
                            << "\n==============Sorry, but there are no courses present consider entering some courses by selecting option 4.=============="
                            << endl;
                } else {
                    cout << "\n==============These are all the courses present.==============\n" << endl;
                    course_present = 0;
                }
                break;
            case 8:
                cout << "\n==============The courses have been sorted in the ascending order according to ID.==============\n" << endl;
                CL.sort("ass");
                break;
            case 9:
                cout << "\n==============The courses have been sorted in the descending order according to ID.==============\n" << endl;
                CL.sort("des");
                break;
            case 11:
                cout<<
                        "\n\t\t*Main Menu*\n\n"
                       "\t1. Add New Student.\n"
                       "\t2. Delete Existing Student.\n"
                       "\t3. Show all Students.\n"
                       "\t4. Add New Course.\n"
                       "\t5. Delete Existing Course."
                       "\n\t6. Show particular Course.\n"
                       "\t7. Show all Courses.\n"
                       "\t8. Sort Courses in Ascending order.\n"
                       "\t9. Sort Courses in Descending order.\n"
                       "\t11. Displays this menu.\n"
                       "\t0. Clears the screen.\n"
                       "\t10. Exit\n"
                       "  --------------------------------------------\n";
                break;
            case 0:
                std::system("CLS");
                break;
            case 10:
                cout<<"==================================================="<<endl;
                cout<<"=             Ok, bye have a nice day!            ="<<endl;
                cout<<"==================================================="<<endl;
                break;

            default:
                cout << "please choose one of the options mentioned in the menu" << endl;
        }
    }

    return 0;
}
