#include <iostream>
using namespace std;

typedef struct complex
{
	double real, imag;
}complex;

complex complex_sub(complex x, complex y);

int main()
{
	complex c1, c2;
	complex result_c1c2;
	cout << "c1�� �Ǽ��κа� ����κ��� �Է��Ͻÿ�" << endl;
	cin >> c1.real >> c1.imag;
	cout << "c2�� �Ǽ��κа� ����κ��� �Է��Ͻÿ�" << endl;
	cin >> c2.real >> c2.imag;
	
	result_c1c2 = complex_sub(c1, c2);
	
	cout << result_c1c2.real << "+" << result_c1c2.imag << "*i" << endl;
	
}

complex complex_sub(complex x, complex y)
{
	complex result;
	result.real = x.real - y.real;
	result.imag = x.imag - y.imag;

	return result;
}