#include <iostream>
#include "Vector/clsVector.h"
#include "SinglyLinkedList/clsNode.h"
#include "SinglyLinkedList/clsLinkedList.h"

using namespace std;

int main() {

	
	clsLinkedList<int>* List = new clsLinkedList<int>();

  List->insert_end(6);
	List->insert_end(10);
	List->insert_end(8);
	List->insert_end(15);
   
	List->print();

  cout << List->search_improved_v2(8) << endl;

		List->print();

	return 0;
}
