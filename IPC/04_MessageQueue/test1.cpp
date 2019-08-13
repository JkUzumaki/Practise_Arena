/*
Peter wants to generate some prime numbers for his cryptosystem. Help him! 
Your task is to generate all prime numbers between two given numbers!

Input
The input begins with the number t of test cases in a single line (t<=10). 
In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

Output
For every test case print all prime numbers p such that m <= p <= n, one number per line, 
test cases separated by an empty line.

Example
Input:
2
1 10
3 5

Output:
2
3
5
7

3
5
*/
#include <iostream>
#include <vector>
#include <iterator>

int main()
{
    int count = 0;
    int start = 0, end = 0;
    std::cin >> count;
    for(int i = 0; i < count; i++){
        std::cin >> start >> end;
        std::vector<int> v;
        for(int j = start; j <= end; j++){
            int test = j;
            int chk = 0;
            while(test){
                if(j % test == 0)
                    chk++;
                test--;
            }
            if(chk == 2)
                v.push_back(j);
        }
        //Display the vector
        for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++){
            std::cout << *it << std::endl;
        }
        //Erase the vector
        v.clear();
    }
    return 0;
}
