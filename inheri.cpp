#include<bits/stdc++.h>
using namespace std;

class Accounts{

	private:
		int balance;
		string name;

	protected:
		int no_man;

	public:
		int sdf;
		Accounts(int balance = 0, string name = "")
		{
			this->balance = balance;
			this->name = name;
		}

		void set_account_vals(int balance, string name)
		{
			this->balance = balance;
			this->name = name;
		}

		void get_account_vals()
		{
			cout<<(this->balance)<<" "<<(this->name)<<endl;
		}


};

class Savings: public Accounts{

	public:
		void setter()
		{
			this->no_man = 45;
		}

};


int main()
{

	Savings x;
	x.set_account_vals(45,"mohit");
	x.get_account_vals();
	x.setter();
	return 0;
}