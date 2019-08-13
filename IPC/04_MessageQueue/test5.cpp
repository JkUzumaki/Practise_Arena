//Finding the number of the braces
#include<iostream>
#include<string>

int main()
{
    int counterOpen = 0;
    int counterClose = 0;
    std::string exp = "(a+b)*(c+d)";
    int index = 0;
    while(exp[index] != '\0'){
        if(exp[index] == '('){
            counterOpen++;
        }else if(exp[index] == ')'){
            counterClose++;
        }
        index++;
    }
    std::cout << "The number of the ( : " << counterOpen << std::endl;
    std::cout << "The number of the ) : " << counterClose << std::endl;
    return 0;
}