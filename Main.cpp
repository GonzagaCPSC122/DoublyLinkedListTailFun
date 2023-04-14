#include "DoublyLinkedList.h"

int main() {
  DoublyLinkedList list; // start out empty list
	
	list.appendNode(12);
	list.appendNode(5);
	list.appendNode(3);
	list.displayList();
	list.displayListInReverse();

	// list.deleteAtFront();
	// list.displayList();
	// list.deleteAtFront();
	// list.displayList();
	// list.deleteAtFront();
	// list.displayList();
	// list.deleteAtFront();
	// list.displayList();
	
	list.deleteNode(3); // delete first node
	list.displayList();
	list.deleteNode(5);
	list.displayList();
	list.deleteNode(12);
	list.displayList();
	list.deleteNode(4);
	list.displayList();
   
   	return 0;
}
