// saurabh_shukla video
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Dummy{

	private:
		int a;
		int b;
		int *ptr;

	public:
		Dummy ()
		{
			ptr = new int;
		}
		Dummy(const Dummy &x)
		{
			this->a = x.a;
			this->b = x.b;
			this->ptr = x.ptr;
		}

		void set_data(int a, int b, int z)
		{
			this->a = a;
			this->b = b;
			*ptr = z;
		}

		void get_data()
		{
			cout<<(this->a)<<" "<<(this->b)<<" "<<(*ptr)<<" "<<ptr<<endl;
		}

		void operator =(const Dummy &x)
		{
			this->a = x.a;
			this->b = x.b;
			*(this->ptr) = *(x.ptr);
		}

};



int main()
{

	Dummy d1;
	d1.set_data(3, 4, 5);
	// Dummy d2 = d1;	

	// d1.get_data();
	// d2.get_data();
	// d2.set_data(4, 5, 9);
	// d2.get_data();
	// d1.get_data();

	Dummy d2;
	d2 = d1;
	d2.get_data();
	d1.get_data();	

	d2.set_data(6,7 ,9);
	d2.get_data();
	d1.get_data();	


	return 0;
}