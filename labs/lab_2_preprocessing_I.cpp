#include <iostream>
#define SIZE 10
#define MIN(n,m) (n < m)? n:m
#define MAX(n,m) (n > m)? n:m
int v,c;
int a[SIZE];// = {0,2,3,4,5,6,9,8,9,10};
using namespace std;
void funcky(int[]);
int main(){
    cout<<"Add the values to array of size 10: ";
    for(int k = 0; k < SIZE ; k++){
        cin>>a[k];
    }
    cout<<"The min and the max of the array: ";
    //v, c = funcky(a);
    funcky(a);
    cout<<v<<" "<<c;
    return 0;
}

void funcky(int b[]){
    int min = b[0], max = b[0];
    for (int i = 0 ; i < SIZE ; i++){
        min = MIN(min, b[i]);
        max = MAX(max, b[i+1]);
        //cout<<" "<<min<<" ";
    }
    v = min;
    c = max;

}