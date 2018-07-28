#include <bits/stdc++.h>
using namespace std;

class Base{

	protected:
		int x;

	public:
		Base()
		{
			x = 0;
			cout<<"base constructor1"<<endl;
		}
		Base(int val)
		{
			x = val;
			cout<<"base constructor2"<<endl;
		}

};

class Derived: public Base{

	private:
		int y;

	public:
		Derived(int val = 0)
		{
			cout<<"Derived constructor"<<endl;
			y = val;
		}

		void get_vals()
		{
			cout<<x<<" "<<y<<endl;
		}
};


int main()
{

	Derived x(10);
	x.get_vals();


	return 0;
}