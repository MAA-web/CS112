#include <iostream>

int main()
{
    char character = 'a';
    int int_A = 10;
    float float_B = 10.5;
    
    std::cout<<"char to int (adding 10 to 'a'): "<< character + int_A; // as character is added to int it converts to int
    
    std::cout<<"\nint to float (adding 10.5): "<< int_A + float_B; // as int is added to float it converts to float (this is based on hierarchy)
    return 0;
}
