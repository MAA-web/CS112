#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>

using namespace std;

std::fstream file;
//std::string src;
std::string src1;
int number_of_zeros{0};
int number_of_polynomials{};
int size_of_polynomials{};
int main() {
    string input_file_name;
    cout<<"type the path of the input file: ";
    getline(cin, input_file_name);
    file.open(input_file_name, std::ios::in);
    file>>number_of_polynomials;
    file>>size_of_polynomials;
    char polynomial[number_of_polynomials][size_of_polynomials];
    int result[number_of_polynomials];
    int polynomial_in_int[number_of_polynomials][size_of_polynomials];
    int iterator{};
    /*while( getline(file, src1)){
        iterator++;
        if(iterator > 1) {
            //cout << src1 << endl;
            for (int i = 0; src1[i] != '\0'; ++i){
                if(src1[i] != '\t')polynomial[iterator - 2] += src1[i];
            }
        }
    }
    */
    for (int i = 0; i < number_of_polynomials; ++i) {
        for (int j = 0; j < size_of_polynomials; ++j) {
            file>>polynomial[i][j];
        }
    }
    file.close();

    for (int i = 0; i < number_of_polynomials; ++i) {
        for (int j = 0; j < size_of_polynomials; ++j) {
            if ((int)polynomial[i][j] == 48) { polynomial_in_int[i][j] = 0; number_of_zeros++; }
            if ((int)polynomial[i][j] == 49)polynomial_in_int[i][j] = 1;
        }
    }

    string output_file_name = "result_addition-";
    output_file_name += std::to_string(number_of_polynomials) + "x" + to_string(size_of_polynomials) + ".txt";

    fstream output_file(output_file_name, ios::out);

    string out_res;
    cout<<"example-"<<number_of_polynomials<<"x"<<size_of_polynomials<<endl;
    cout<<"number of polynomials: "<<number_of_polynomials<<endl;
    cout<<"number of variables: "<<size_of_polynomials<<endl;

    /*for (int i = 0; i < number_of_polynomials; ++i) {
        for (int j = 0; j < size_of_polynomials; ++j) {
            cout<<polynomial[i][j];
        }
        cout<<endl;
    }*/
    const auto time1 = chrono::system_clock::now();
    for (int i = 0; i < number_of_polynomials; ++i) {
        int result_ = 0;
        for (int j = 0; j < size_of_polynomials; ++j) {
            result_ += polynomial_in_int[i][j] * j;
        }
        out_res += to_string(result_) + " ";
        output_file<<result_<<" ";
    }
    output_file.close();
    const auto time2 = chrono::system_clock::now();
    const auto TotalTime = chrono::duration_cast<chrono::milliseconds>(time2 - time1);
    const auto TotalTime_in_nanoseconds = chrono::duration_cast<chrono::nanoseconds>(time2 - time1);

    cout<<out_res<<endl;
    cout<<"Total time taken for addition in milliseconds: "<<TotalTime<<endl;
    cout<<"Total time taken for addition in nanoseconds: "<<TotalTime_in_nanoseconds<<endl;
    cout<<"A 2D array is used to represent the whole file."<<endl;
    cout<<"number of zeros: "<<number_of_zeros<<endl;
    output_file<<"example-"<<number_of_polynomials<<"x"<<size_of_polynomials<<"\n";
    return 0;
}
