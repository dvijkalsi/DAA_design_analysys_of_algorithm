#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	// Take any string
	string s1 = "bb";

	// Copy two characters of s1 (starting
	// from position 3)
	string r = s1.substr(1,1);

	// prints the result
	cout << "String is: " << r;

	return 0;
}