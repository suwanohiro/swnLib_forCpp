#include <iostream>

#include "./swnLib_forCpp/swnLib_forCpp.hpp"

int main()
{
    swn::vector<int> array;

    std::vector<int> aaa = array;

    array = aaa;

    array.push_back(10);
    array.push_back(10);
    array.push_back(10);
    array.push_back(10);
    array.push_back(10);


    printf_s("%d\n", array.length());

    return 0;
}
