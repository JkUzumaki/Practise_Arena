#include<iostream>

int main()
{
	struct a{
		private:
		int var1;
		public:
		int var2;
		void set(int v)
		{
			var1 = v;
		}
		int get()
		{
			return var1;
		}
	};
	a obj;
	obj.set(300);
	obj.var2 = 100;
	std::cout << "var1 = " << obj.get() << std::endl;
	std::cout << "var2 = " << obj.var2 << std::endl;
	
	
}
