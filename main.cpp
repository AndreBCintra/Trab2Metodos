#include <iostream>
#include "./Utils.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Box Box1;
    double volume = 0.0; 
    
    Box1.height = 5.0; 
    Box1.length = 6.0; 
    Box1.breadth = 7.0;

    volume = Box1.height * Box1.length * Box1.breadth;
    cout << "Volume of Box1 : " << volume <<endl;
    return 0;
}
