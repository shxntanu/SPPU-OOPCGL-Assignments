#include<iostream>
using namespace std;
int main()
{
	float a,b,c,d;

	cout<<"Enter a and b: ";
	cin>>a>>b;
	cout<<endl;

	cout<<"Enter c and d: ";
	cin>>c>>d;
	cout<<endl;

	cout<<"Complex Number 1: "<<a<<" + "<<b<<"i"<<endl;
	cout<<"Complex Number 2: "<<c<<" + "<<d<<"i"<<endl;

	int f;

	do
	{

		cout<<"Enter 1 for addition, 2 for subtraction, 3 for multiplication and 4 for division: ";
		cin>>f;

		switch(f)
		{
			case 1: cout<<"Addition of 1 and 2: "<<a+c<<" + "<<b+d<<"i"<<endl;
			break;

			case 2: cout<<"Subtraction of 1 and 2: "<<a-c<<" + "<<b-d<<"i"<<endl;
			break;

			case 3: cout<<"Multiplication of 1 and 2: "<<(a*c)-(b*d)<<" + "<<(a*d)+(b*c)<<"i"<<endl;
			break;

			case 4: cout<<"Division of 1 and 2: "<<((a*c)+(b*d))/((c*c)+(d*d))<<" + "<<((b*c)-(d*a))/((c*c)+(d*d))<<"i"<<endl;
			break;

			case 5: cout<<"Exit"<<endl;
			break;

			default: cout<<"Wrong input!"<<endl;

		}
    }
	while(f!=5);
	return 0;
}
