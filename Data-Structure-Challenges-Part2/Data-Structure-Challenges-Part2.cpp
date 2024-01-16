#include <iostream>
#include "clsVector.h"

using namespace std;

int main() {

	clsVector <int> v(10);

	for (int i = 0; i < 10; ++i)
		v.set(i, i);

	v.print();

	cout << v.get_size() << " " << v.back() << endl;

	v.insert(5, 100);


	v.print();
	//cout << v.get_size() << " " << v.back() << endl;



	return 0;
}
