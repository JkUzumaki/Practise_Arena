//Finding the number of the braces
#include<iostream>
#include<string>
#include<vector>
#include<iterator>

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
    index = 0;
    int stl = 0;
    int flag = 0;
    std::vector<std::vector<std::string>> v;
    while(exp[index] != '\0'){
        if(exp[index] == '('){
            flag = 1;
            continue;
        }
        if(exp[index] == ')'){
            flag = 0;
            stl++;
            continue;
        }
        if(flag == 1){
            v.push_back(exp[index]);
        }
        index++;
    }

    std::cout << "The number of the ( : " << counterOpen << std::endl;
    std::cout << "The number of the ) : " << counterClose << std::endl;
    return 0;
}