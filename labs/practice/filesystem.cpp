#include <iostream>
#include <filesystem>
using namespace std;

namespace FS = std::filesystem;

int main(int argc, char const *argv[])
{
    string PATH = R"(C:\Users\hithe\projects\university-work\CS112\Semester_II_Project\CS112-B Semester Project Data)";
    for (auto i : FS::directory_iterator(PATH))
    {
        cout<<i.path().filename().string() + "\\"<<endl;
    }
    
    return 0;
}
