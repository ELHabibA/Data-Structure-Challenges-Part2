#include <iostream>
#include "Vector/clsVector.h"
#include "DoublyLinkedList/clsNode.h"
#include "DoublyLinkedList/clsDoublyLinkedList.h"

using namespace std;

int main() {

	
	clsDoublyLinkedList<int>* List = new clsDoublyLinkedList<int>();

  List->insert_end(10);
	List->insert_end(20);
	List->insert_end(30);
	List->insert_end(40);
	List->insert_end(50);
	
	List->print();

	clsDoublyLinkedList<int>* other = new clsDoublyLinkedList<int>();

	other->insert_end(15);
	other->insert_end(17);
	other->insert_end(22);
	other->insert_end(24);
	other->insert_end(60);

  other->print();

 

	List->merge_2sorted_lists(other);
		

  List->print();

 cout << "Length: " << List->get_Length() << endl;
 cout << "Head: " << List->get_head() << endl;
 cout << "Tail: " << List->get_tail() << endl;

	return 0;
}

 	/*clsLinkedList<int>* other = new clsLinkedList<int>();

	other->insert_end(1);
	other->insert_end(2);
	other->insert_end(3);
	other->insert_end(8);



  other->print();*/
