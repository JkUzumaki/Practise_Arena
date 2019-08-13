#include<iostream>

int print()
{
    std::cout << "Hello World!\n";
    return 0;
}

static int a = print();

int main()
{
    return 0;
}