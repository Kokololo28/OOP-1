#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#define NL std::cout << '\n'
using namespace std;

class valueB
{
private:
	double x;
	double y;
	double z;

public:
	valueB(double X, double Y, double Z)
	{
		x = X; y = Y; z = Z;
	}
	
	double Calc()
	{
		double b = (x * x + z * z / (pow(tan(pow(fabs(x), 0.3)), 2))) / (3 + x + y * y / 2 + z * z * z / 6) + (pow(log(pow(fabs(y/z),1/3)),0.3));
		return b;
	}

	double getX()
	{
		return x;
	}

	double getY()
	{
		return y;
	}

	double getZ()
	{
		return z;
	}
};

class valueA : public valueB
{
private:
	double b;

public:
	valueA(double X, double Y, double Z, double B) : valueB(X, Y, Z)
	{
		b = B;
	}

	double Calc()
	{
		double a = (((2 * cos(pow(fabs(getX()), 1 / 3))) - getX() * getX() / 6) / (getZ() / b + (sin((getY() + getZ()) * (getY() + getZ()) * (getY() + getZ()))) * (sin((getY() + getZ()) * (getY() + getZ()) * (getY() + getZ()))))) + (pow(log(pow(fabs(getZ()), 0.6)), 2));
		return a;
	}

	double getB()
	{
		return b;
	}
};



void main()
{
	NL; NL; NL;
	double x = 0.48 * 5;
	double y = 0.47 * 5;
	double z = -1.32 * 5;

	cout << "Task 1:" << endl;
	valueB b(x, y, z);
	valueA a(x, y, z, b.Calc());
	cout << "b[x, y, z] = " << b.Calc(); NL;
	cout << "a[x, y, z, b] = " << a.Calc(); NL; NL;

	cout << "Task 2:"; NL;
	for (double x = -1.0; x <= 1.0; x += 0.2)
	{
		valueB b(x, y, z);
		valueA a(x, y, z, b.Calc());
		cout << "x = " << to_string(x).substr(0, 4) << setw(20) << "a[x, y, z, b] = " << to_string(a.Calc()).substr(0, 8) << setw(20) << "b[x, y, z] = " << to_string(b.Calc()).substr(0, 8) << endl;
	}
	NL; NL; NL;
}