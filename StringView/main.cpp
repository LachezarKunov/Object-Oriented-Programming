#include <iostream>
#include "String.h"
#include "StringView.h"
using namespace std;

int main()
{
	String str1("Lachezar");

	StringView strView1(str1);
	StringView strView2(str1);

	cout << (strView1 == strView2) << endl;
	cout << strView1;
}
