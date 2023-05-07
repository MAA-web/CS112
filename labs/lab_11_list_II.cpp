#include <iostream>
#include <list> // including list
using namespace std;

template<typename T>
void showlist(T); // prototype of showlist

int main(){
    
    list<int> list_array{1, 2, 3, 4, 5};
    cout<<"\nOriginal: ";
    for (auto i : list_array) cout<<i<<", ";

    cout<<"\nfront: "<<list_array.front();

    cout<<"\nback: "<<list_array.back();

    list_array.pop_front();
    cout<<"\npop_front(): ";
    for (auto i : list_array) cout<<i<<", ";

    list_array.pop_back();
    cout<<"\npop_back(): ";
    for (auto i : list_array) cout<<i<<", ";
    
    cout<<"\nShowlist(): ";showlist(list_array);

    list_array = {5,4,3,2,1};
    cout<<"\nNew list: ";
    for (auto i : list_array) cout<<i<<", ";

    list_array.sort();
    cout<<"\nSorted New list: ";
    for (auto i : list_array) cout<<i<<", ";

    list_array.reverse();
    cout<<"\nreverse list: ";
    for (auto i : list_array) cout<<i<<", ";
    
    return 0;
}
template<typename T>
void showlist(T value){ // showlist function having template
    list<int>::iterator i;
    for ( i = value.begin(); i != value.end(); ++i)
    cout<<*i<<", ";
    
    //for (auto i : value) cout<<i<<", ";
}
