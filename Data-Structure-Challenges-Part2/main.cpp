#include <iostream>
#include "Vector/clsVector.h"
#include "SinglyLinkedList/clsNode.h"
#include "SinglyLinkedList/clsLinkedList.h"

using namespace std;

int main() {

	
	clsLinkedList<int>* List = new clsLinkedList<int>();

  List->insert_sorted(1);
	List->insert_sorted(2);
	List->insert_sorted(2);
	List->insert_sorted(3);
	List->insert_sorted(3);
	List->insert_sorted(3);
	List->insert_sorted(5);
	List->insert_sorted(3);

	
	List->print();

	//List->Remove_duplicates();

  List->Move_to_back(2);
   
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
