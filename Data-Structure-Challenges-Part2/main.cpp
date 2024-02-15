#include <iostream>
#include "Vector/clsVector.h"
#include "SinglyLinkedList/clsNode.h"
#include "SinglyLinkedList/clsLinkedList.h"

using namespace std;

int main() {

	
	clsLinkedList<int>* List = new clsLinkedList<int>();

  List->insert_end(11);
	List->insert_end(33);
	List->insert_end(55);
	List->insert_end(4);
	List->insert_end(50);
	List->insert_end(17);
	List->insert_end(8);
	
	List->print();

	//List->Remove_duplicates();

  List->Arrange_odd_and_even_nodes();
   
	List->print();

	//cout << List->get_Head() << endl;

 cout << List->get_Tail() << endl;
 cout << List->get_Head() << endl;

	return 0;
}

 	/*clsLinkedList<int>* other = new clsLinkedList<int>();

	other->insert_end(1);
	other->insert_end(2);
	other->insert_end(3);
	other->insert_end(8);



  other->print();*/
