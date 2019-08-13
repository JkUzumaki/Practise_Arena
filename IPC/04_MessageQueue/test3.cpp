#include<iostream>
#include<string>

int main()
{
    std::string strA;
    std::string strB;
    bool status = false;
    std::cin >> strA;
    std::cin >> strB;
    
    for(int i = 0; i < strA.length(); i++){
        for(int j = 0; j < strB.length(); j++){
            if(strB[j] == strA[j+i]){
                status = true;
            }else{
                status = false;
                break;
            }
        }
        if(status == true){
            std::cout << "status is true\n";
            return 1;
        }
    }
    std::cout << "status is false\n";
    return 0;
}