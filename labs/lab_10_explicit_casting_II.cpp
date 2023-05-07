#include <iostream>

int main()
{
    const int *const_int_A = new int(6); // const int pointer with dynamic memory allocation
    //*const_int_A = 20; will not work as it is const
    
    int* non_const_int_A = const_cast<int*>(const_int_A); // this works as it is cast to non-const and the resultant value assigned to a non const int
    
    *non_const_int_A *= 10; // multiplied with 10 and assigned to it's self
    
    std::cout<<"result : "<<*non_const_int_A;
    
    delete const_int_A; // deleting the ponter

    return 0;
}