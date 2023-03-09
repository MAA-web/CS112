#include <iostream>
using namespace std;

int main(){
    int size;
    cout<<"Type the size: ";
    cin>>size;
    int* arr = new int[size];
    cout<<"Type the values of the array of size "<<size<<": ";
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }
    cout<<"Entered array: ";
    cout<<arr[0];
    for(int i = 1; i < size; i++){
        cout<<", "<<arr[i];
    }

    delete [] arr;
    return 0;
}