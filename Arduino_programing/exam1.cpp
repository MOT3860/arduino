#include<iostream>
using namespace std;
class Animal{
	protected :
		double leg,tail;
		public:
		void showLeg (double);
		void showTail(double);
};
class Dog :public Animal{
	public:
	void dogInput(){
		cout << "input dog's leg  :";cin >> leg;
	}
};