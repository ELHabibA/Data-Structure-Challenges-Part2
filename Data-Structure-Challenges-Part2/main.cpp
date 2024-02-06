#include <iostream>
#include "Vector/clsVector.h"
#include "SinglyLinkedList/clsNode.h"
#include "SinglyLinkedList/clsLinkedList.h"

using namespace std;

int main() {

	
	clsLinkedList<int>* List = new clsLinkedList<int>();

  List->insert_end(1);
	List->insert_end(7);
	List->insert_end(3);
	List->insert_end(8);

	List->print();

	cout << List->get_Tail() << endl;

  List->delete_last_node();
   
	List->print();

	cout << List->get_Tail() << endl;
  
 	/*clsLinkedList<int>* other = new clsLinkedList<int>();

	other->insert_end(1);
	other->insert_end(2);
	other->insert_end(3);
	other->insert_end(8);



  other->print();*/

	

	return 0;
}
