#include<iostream>
#include<vector>
#include <algorithm>

int main()
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    std::reverse(v.begin(), v.end());
    std::vector<int>::iterator it = v.begin();
    while(it != v.end()){
        std::cout << *it << std::endl;
        it++;
    }
    std::cout << "\n" << v[0] << std::endl;
    return 0;
}//
