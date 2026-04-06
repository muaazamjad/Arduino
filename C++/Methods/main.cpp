#include <iostream>
#define COUNT 10

int addNumber(int a, int b)
{
    return a + b;
}

int main(int argc, char const *argv[])
{
    int first_number{3};  // statement -> declaration + initialization
    int second_number{5}; // statement

    std::cout << "First numnber : " << first_number << std::endl;
    std::cout << "Second number : " << second_number << std::endl;

    std::cout << "Sum : " << addNumber(first_number, second_number) << std::endl;
    return 0;
}
