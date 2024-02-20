#include <iostream>
#include "Vector/clsVector.h"
#include "SinglyLinkedList/clsNode.h"
#include "SinglyLinkedList/clsLinkedList.h"

using namespace std;

int main() {

	
	clsLinkedList<int>* List = new clsLinkedList<int>();

  List->insert_end(1);
	List->insert_end(2);
	List->insert_end(3);
	List->insert_end(4);
	
	
	List->print();
	/*clsLinkedList<int>* other = new clsLinkedList<int>();

	other->insert_end(4);
	other->insert_end(5);
	other->insert_end(3);

  other->print();*/

  List->reverse_chains(9);
   
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
