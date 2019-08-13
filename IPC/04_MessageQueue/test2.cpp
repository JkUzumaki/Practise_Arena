
#include <iostream>
#include <vector>
#include <iterator>

int main()
{
    int count = 0;
    int start = 0, end = 0;
    std::cin >> count;
    while(count--){
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
