#include<iostream>
using namespace std;

class Box{

	private:
		int l, b, h;

	public:
		void set_data(int l, int b, int h)
		{
			this->l = l;
			this->b = b;
			this->h = h;
		}

		void get_data()
		{
			cout<<(this->l)<<" "<<(this->b)<<" "<<(this->h)<<endl;
		}

};



int main()
{

	Box small_box;
	small_box.set_data(10, 23, 54);
	small_box.get_data();

	Box *ptr;
	ptr = &small_box;

	(*ptr).set_data(43, 54, 45);
	(*ptr).get_data();

	return 0;
}