#include <iostream>

int main()
{
    // Std::cout comes from the iostream lib
    // std:endl add another line
    std::cout << "Hellow World!" << std::endl;
    std::cout << "Servusssss";
    std::cout << "Suck it " << std::endl;
    int count = 10;
    for (size_t i = 0; i < count; i++)
    {
        std::cout << "Muaaz" << std::endl;
    }
    int bla[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (size_t i = 0; i < sizeof(bla) / sizeof(bla[0]); i++)
    {
        std::cout << bla[i] << std::endl;
    }

    // Clear any leftover characters in the buffer and wait for a new line
    std::cin.get();
    return 0;
}