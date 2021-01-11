/*
* @Author: Denghui
* @Date:   2021-01-08 16:11:47
* @Last Modified by:   Denghui
* @Last Modified time: 2021-01-08 16:38:01
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	string a = "123123";
	string b;

	b = a;
	b[0]--;

	cout << b[0]-1 << endl;
	return 0;
}