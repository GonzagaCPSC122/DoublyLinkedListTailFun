#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() {
	head = NULL;
  tail = NULL;
  cout << "sizeof(int): " << sizeof(int) << endl;
  cout << "sizeof(Node *): " << sizeof(Node *) << endl;
  cout << "sizeof(Node): " << sizeof(Node) << endl;
}

DoublyLinkedList::~DoublyLinkedList() {
	// TODO: free each Node's memory in the list
	Node * currNode = head;
	Node * nextNode = NULL;
	
	while (currNode != NULL) {
		// save the link to the next node
		nextNode = currNode->next;
		// can safely delete currNode
		delete currNode;
		currNode = nextNode;
	}
	head = NULL; // for good practice
  tail = NULL; // for good practice
}

void DoublyLinkedList::displayList() {
	Node * currNode = head;
	
	cout << "head->";
	while (currNode != NULL) {
		cout << currNode->value << "<->";
		// progress towards BC being false
		currNode = currNode->next;
	}
	cout << "NULL" << endl;
  cout << "tail->";
  if (tail == NULL) {
    cout << "NULL" << endl;
  }
  else {
    cout << tail->value << endl;
  }
}

void DoublyLinkedList::displayListInReverse() {
	Node * currNode = tail;
	
	cout << "tail->";
	while (currNode != NULL) {
		cout << currNode->value << "<->";
		// progress towards BC being false
		currNode = currNode->prev;
	}
	cout << "NULL" << endl;
  cout << "head->";
  if (head == NULL) {
    cout << "NULL" << endl;
  }
  else {
    cout << head->value << endl;
  }
}

void DoublyLinkedList::appendNode(int newValue) {
	// make a new Node
	Node * newNode = new Node;
	newNode->value = newValue;
	newNode->next = NULL;
  newNode->prev = NULL;
	
	// 2 cases
	if (head == NULL) {
		head = newNode;
    tail = newNode;
	} 
	else {
		// list is not empty
		// tail points to the last node in the list
		tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
	}
}

void DoublyLinkedList::deleteAtFront() {
	// check to make sure there is something to delete
	if (head != NULL) {
		Node * nodeToDelete = head;
		head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    else {
      tail = NULL;
    }
		delete nodeToDelete;
	}
}

void DoublyLinkedList::deleteNode(int targetValue) {
	// check case 1
	if (head != NULL) {
		// list is not empty
		// need to traverse list, stopping at the last node
		Node * currNode = head;
		// check case 2... the node to delete is the first node
		if (head->value == targetValue)  {
			head = head->next;
      if (head != NULL) {
        head->prev = NULL;
      }
      else {
        tail = NULL;
      }
			delete currNode;
		}
		else { // case 3... the node to delete is not the first node, but might not even be in the list
			while (currNode != NULL && currNode->value != targetValue) {
				currNode = currNode->next;
			}
			// check if we found targetValue
			if (currNode != NULL) {
				// did find it
				currNode->prev->next = currNode->next;
        if (currNode->next != NULL) {
          currNode->next->prev = currNode->prev;
        }
        else {
          tail = currNode->prev;
        }
				delete currNode;
			}
		}
	}
}
// task 1: test out deleteAtFront() and deleteNode()
// task 2: define/call displayListInReverse()