// Program without using main function
#include <iostream>
#include<stdlib.h>
using namespace std;

class Demo
{
public:
	Demo()		// constructor
	{
		cout << "Inside Constructor " << endl;
		exit(0);
	}
};

static Demo s;

int main()
{
	cout << "Inside main() - never executed";
}
