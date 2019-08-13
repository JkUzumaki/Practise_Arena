#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main()
{
    int Tdigit = 0;
    std::vector<int> v;
    int Tentry = 0;
    int test = 0;
    int data = 0;
    int Tdata = 0;
    std::cout << "Enter the total entry for finding the next palindrome:\n";
    std::cin >> Tentry;
    test = Tentry;
    //Loop to get the next palindrome based on the n input
    while(test--){
        std::cout << "Enter the data from which next palindrome is calculated\n";
        std::cin >> data;
        Tdata = data;
        Tdigit = 0;
        int flag = 0;
        while(1){
            v.push_back(Tdata % 10);
            Tdigit++;
            if((Tdata = Tdata / 10) < 0)
                break;
        }
        std::reverse(v.begin(), v.end());//Arrange the number in correct order

        if(Tdigit % 2 != 0){    //ODD
            std::cout << "Odd number\n";   
            for(int i = 0; i < (Tdigit/2); i++){
                if(v[i] == v[Tdigit - i]){
                    flag = 1;
                    continue;
                }else{
                    flag = 0;
                    if(v[i] > v[Tdigit-i]){
                        while(1){
                            if(v[i] == v[Tdigit-i])
                                break;
                            v[Tdigit-i] += 1;
                        }
                    }else{
                        while(1){
                            if(v[i] == v[Tdigit-i])
                                break;
                            v[i] += 1;
                            v[Tdigit-i] -=1; 
                        }
                    }
                }
            }
            if(flag = 1)
                v[Tdigit/2] += 1;
        }else{                  //EVEN
            std::cout << "Even number\n";
        }
    }
    return 0;
}