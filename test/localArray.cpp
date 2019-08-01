#include<iostream>

using namespace std;

int* myfun()
{
	int * y = new int;
	*y = 10;
	cout << *y << endl;
	delete y;
y= NULL;
	cout << *y << endl;
	

return y;
}

int main()
{
int *x = myfun();
cout << "X: " << *x << endl;
}
