#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    /*  std::cin is a high way which takes in input from the user
    and stores it in a variable.

    */

    /* Data input from the user

     std::string name; // initialize a string variable name
     int age;          // initialize an integer variable age

     std::cout << "Please enter your name and age!" << std::endl;
     std::cin >> name;                                                                  // input from the user
     std::cin >> age;                                                                   // input from the user
     std::cout << "Hello " << name << " you are " << age << " years old!" << std::endl; // output the name and age to the console.
    */

    std::string full_name;
    int age2;

    std::cout << "Please enter your full name and age!" << std::endl;
    // this will only take the full name with space in between
    std::getline(std::cin, full_name);
    std::cin >> age2;

    std::cout << "Hello " << full_name << " you are " << age2 << " years old!" << std::endl;

    return 0;
}
