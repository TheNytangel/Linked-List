/*
	Christopher Peterson
	Linked List Project
	5/23/17
*/

#include <ctime>
#include <iostream>
#include "LinkedList.h"

int main()
{
	srand(time(0));
	LinkedList<int> list;

	/**************
	Adding to the end and deleting ALL data from the list
	**************/
	{
		// Add 1-10 to the list
		for (int i = 0; i < 10; ++i)
		{
			list.insertAtEnd(i);
		}

		// Make a temporary pointer to a node and start at the beginning of the list
		shared_ptr<LinkedList<int>::Node> displayNode = list.head();

		// While there are more nodes in the list, delete the current node
		// This deletes ALL data in the list
		while (displayNode != NULL)
		{
			list.deleteNode(displayNode);
			displayNode = displayNode->getNextNode();
		}
	}
	
	/**************
	Adding to the beginning and deleting ALL data from the list in reverse order
	**************/
	{
		// Add 1-10 to the list in reverse order
		for (int i = 0; i < 10; ++i)
		{
			list.insertAtBeginning(i);
		}

		// Make a temporary pointer to a node and start at the beginning of the list
		shared_ptr<LinkedList<int>::Node> displayNode = list.tail();

		// While there are more nodes in the list, delete the current node
		// This deletes ALL data in the list
		while (displayNode != NULL)
		{
			list.deleteNode(displayNode);
			displayNode = displayNode->getPreviousNode();
		}
	}

	/**************
	Inserting a large number of nodes (1048576) (2^20)
	**************/
	{
		for (unsigned int i = 0; i < 1048576; ++i)
		{
			list.insertAtEnd(i);
		}

		// Empty the list for the next test
		while (!list.isEmpty())
		{
			list.deleteNode(list.tail());
		}
	}

	/**************
	Adding random numbers to the list, getting the max & min & finding the pointer to the max value
	**************/
	{
		// Insert 100 random numbers between 0 and 1000 at the end of the list
		for (int i = 0; i < 100; ++i)
		{
			list.insertAtEnd(rand() % 1000);
		}

		int max = list.maximum();

		cout << "Random list max: " << max << endl;
		cout << "Random list min: " << list.minimum() << endl;

		cout << "Memory address of max: " << list.find(max) << endl;

		cout << endl;
	}

	system("pause");
	return 0;
}
