#include <bits/stdc++.h>
using namespace std;


class Complex{

	private:
		int real;
		int imaginary;

	public:
		Complex(int real = 0, int imaginary = 0)
		{
			this->real = real;
			this->imaginary = imaginary;
		}

		Complex operator +(Complex b)
		{
			cout<<real<<" "<<imaginary<<endl;
			Complex temp;
			temp.real = this->real + b.real;
			temp.imaginary = this->imaginary + b.imaginary;
			return temp;
		}	

		Complex operator -()
		{
			Complex temp;
			temp.real = -(this->real);
			temp.imaginary = -(this->imaginary);

			return temp;
		}

		Complex operator -(Complex b)
		{
			Complex temp;
			temp.real = this->real - b.real;
			temp.imaginary = this->imaginary - b.imaginary;

			return temp;
		}

		Complex operator *(Complex b)
		{
			Complex temp;
			temp.real = ((this->real) * b.real) - ((this->imaginary) * b.imaginary);
			temp.imaginary = ((this->real) * b.imaginary) + ((this->imaginary) * b.real);

			return temp;
		}

		Complex operator ++()
		{
			Complex temp;
			temp.real = this->real = (this->real) + 1;
			temp.imaginary = this->imaginary = (this->imaginary) + 1;
			return temp;

		}

		Complex operator ++(int)
		{
			Complex temp;
			temp.real = (this->real);
			temp.imaginary = (this->imaginary);
			this->real = (this->real) + 1;
			this->imaginary = (this->imaginary) + 1;

			return temp;
		}

		// Complex operator <<(Complex b)
		// {
		// 	Complex temp;
		// 	temp.real = (this->real + b.imaginary);
		// 	temp.imaginary = (this->imaginary + b.real);

		// 	return temp;
		// }

		void operator <<(int b)
		{
			cout<<(this->real)<<" "<<(this->imaginary)<<endl;
		}

		void operator =(Complex b)
		{
			this->real = b.imaginary;
			// b.imaginary = (this->real);
			this->imaginary = b.real;
			// Complex temp; 
			// temp.real = (this->imaginary);
			// temp.imaginary = (this->real);

			// return temp;
		}

		void display_objects_val()
		{
			cout<<real<<" "<<imaginary<<endl;
		}



};


int main()
{


	Complex x(1, 3);
	Complex y(2, 5);
	Complex z = x;
	// z = x;
	// z.display_objects_val();
	// Complex z = x +y;
	// ++x;
	// Complex z = x++;
	// x.display_objects_val();
	// z.display_objects_val();
	// z.display_objects_val();
	
	// z=  -z;
	// z.display_objects_val();

	// Complex r = x - y;
	// r.display_objects_val();
	// r = x<<y;
	// r.display_objects_val();

	return 0;
}