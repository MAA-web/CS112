#include <iostream>
#include <vector> // including vector
using namespace std;

int main(){
    vector<int> vec_list = {1, 2, 3, 4, 5};
    cout<<"\nOriginal: ";
    for (auto i : vec_list) cout<<i<<", ";
    
    vec_list.push_back(6);
    cout<<"\npush_back(6): ";
    for (auto i : vec_list) cout<<i<<", ";
    
    cout<<"\nat(3): "<<vec_list.at(3);

    vec_list.pop_back();
    cout<<"\npop_back(): ";
    for (auto i : vec_list) cout<<i<<", ";

    vec_list[2] = 0;
    cout<<"\nvec_list[2] = 0: ";
    for (auto i : vec_list) cout<<i<<", ";

    return 0;
}