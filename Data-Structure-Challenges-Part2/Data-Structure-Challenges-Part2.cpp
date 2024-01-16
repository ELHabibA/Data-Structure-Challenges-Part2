#include <iostream>
#include "clsVector.h"

using namespace std;

int main() {

	clsVector <int> v(10);

	for (int i = 0; i < 10; ++i)
		v.set(i, i);

	v.print();

	cout << v.get_size() << " " << v.back() << endl;


	cout << v.find_transposition(3) << endl;

	v.print();
	


	return 0;
}
