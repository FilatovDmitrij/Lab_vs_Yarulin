#include <iostream>
using namespace std;

int main()
{
	float a, b, *pa = &a, *pb = &b;

	cin >> *pa >> *pb;

	cout << "*pa + *pb = " << *pa + *pb;

	return 0;
}