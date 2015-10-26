#include <iostream>

using namespace std;
int output()
{
	//final output once all calculations are done(not used yet)
	//some of these are constant, camber and tire pressure
	cout << "Front Camber: -5\nRear Camber: -1\nFront Tires: 28PSI\nRear Tires: 25psi\n";	
}
int springstiffnessfront(double high, double low, double weight)
{
	//front springs
	double frontstiff;
	frontstiff = high - low;
	frontstiff = frontstiff * weight;
	frontstiff += low;
	return (frontstiff);
	
}
int springstiffnessrear(double high, double low, double weight)
{
	//rear springs
	double frontstiff;
	double weightrear;
	weightrear = 1.0 - weight;
	frontstiff = high - low;
	frontstiff = frontstiff * weightrear;
	frontstiff += low;
	return (frontstiff);
	
}

int antirollbarsfront(double high, double low, double weight)
{
	//front anti rollbars
	///these should return decimal numbers, but do not in my tests
	double frontbars;
	frontbars = high - low;
	frontbars = frontbars * weight;
	frontbars += low;
	return (frontbars);
	
}
int antirollbarsrear(double high, double low, double weight)
{
	//rear antirollbars
	//these should also return decimals, but alas, also return whole numbers
	double rearbars;
	double weightrear;
	weightrear = 1.0 - weight;
	rearbars = high - low;
	rearbars = rearbars * weightrear;
	rearbars += low;
	return (rearbars);
	
}
int main()
{
	//all my variables are doubles instead of int
	double weight;
	double spring1;
	double spring2;
	double rollbar1;
	double rollbar2; 
	double springsfront;
	double springsrear;
	double rollbarsfront;
	double rollbarsrear;
	//these are for a test, they output a decimal
	
	
	double test1;
	double test2;
	double testanswer;
	test1 = 1;
	test2 = 19;
	testanswer = test1/test2;
	
	cout << "Please enter the following data:\n";
	cout << "Weight distribution\nLowest spring setting\nHighest spring setting\nLowest Anti Rollbar Setting\nHighest Anti Rollbar Setting\n";
	//take input, currently refuses null input
	cin >> weight >> spring1 >> spring2 >> rollbar1 >> rollbar2;
	//case the weight distribution is given in percent instead of decimal
	if(weight > 1){weight = weight/100;}
	//test output
	//call spring front and return stiffness
	springsfront = springstiffnessfront(spring2,spring1,weight);
	cout << springsfront << "\n";
	//call spring rear frunction and return stiffness
	springsrear = springstiffnessrear(spring2, spring1, weight);
	cout << springsrear << "\n";
	//call antirollbar front, return rollbar setting
	rollbarsfront = antirollbarsfront(rollbar2,rollbar1, weight);
	cout << rollbarsfront << "\n";
	//call antirollbar rear, return rollbar setting
	rollbarsrear = antirollbarsrear(rollbar2, rollbar1, weight);
	cout << rollbarsrear << "\n";
	//my test variable
	cout << testanswer;
}
