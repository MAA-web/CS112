#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

fstream input_file("Pakistan.txt", ios::in);

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

fstream output_file("Pakistan_Cities_Sanitised.txt",ios::out);
string str;
int main(){
	while(getline(input_file, str)){
		if(string_tokenizer(str).size() == 1){
			output_file << str << "\n";
			cout << str << endl;
		}
	}
	return 0;
}