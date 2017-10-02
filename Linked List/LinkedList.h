// Linked List class
#include <memory>

using namespace std;

template <class T>
class LinkedList
{
public:
	class Node
	{
		// Make the LinkedList class its friend so that the LinkedList class can access these private pointers
		friend class LinkedList;

		// Next and previous nodes are now private which prevents them from being changed from outside the LinkedList class
		shared_ptr<typename LinkedList<T>::Node> previousNode;
		shared_ptr<typename LinkedList<T>::Node> nextNode;

	public:
		shared_ptr<typename LinkedList<T>::Node> getPreviousNode() const
		{
			return previousNode;
		}
		shared_ptr<typename LinkedList<T>::Node> getNextNode() const
		{
			return nextNode;
		}

		T data;
	};

	LinkedList(){}

	shared_ptr<typename LinkedList<T>::Node> find(T dataToFind) const
	{ 
		// Nothing is in the list, so the data can't be found
		if (isEmpty())
		{
			return NULL;
		}

		// Make a temporary pointer for an "iterator" to go through starting at the first node
		shared_ptr<typename LinkedList<T>::Node> currentNode = firstNode;
		// Loop through while there are still nodes left to go through
		while (currentNode != NULL)
		{
			// Check if the current node's data is what we're looking for
			if (currentNode->data == dataToFind)
			{
				return currentNode;
			}
			
			currentNode = currentNode->nextNode;
		}

		// The data reached the end of the list and nothing was found so return NULL
		return NULL;
	}

	void insertAtEnd(T newData)
	{
		// Make a temporary pointer to a node to hold the new data
		shared_ptr<typename LinkedList<T>::Node> tempNode = make_shared<typename LinkedList<T>::Node>();

		// Set the previous node to the last node
		tempNode->previousNode = lastNode;
		// Assign the data in the node
		tempNode->data = newData;
		// Set the next node to NULL since it won't be created yet
		tempNode->nextNode = NULL;

		// If there's already a last node, set that one's next node to this new one
		if (lastNode != NULL)
		{
			lastNode->nextNode = tempNode;
		}

		// Set the new last node to this node since it is the most-previously created
		lastNode = tempNode;

		// If the first node hasn't yet been created, set this node to the first node as well
		if (firstNode == NULL)
		{
			firstNode = tempNode;
		}
	}

	void insertAtBeginning(T newData)
	{
		// Make a temporary pointer to a node to hold the new data
		shared_ptr<typename LinkedList<T>::Node> tempNode = make_shared<typename LinkedList<T>::Node>();

		// Set the previous node to NULL since it is the beginning of the list
		tempNode->previousNode = NULL;
		// Assign the data in the node
		tempNode->data = newData;
		// Set the next node to the first node
		tempNode->nextNode = firstNode;

		// If there's already a first node, set that one's next node to this new one
		if (firstNode != NULL)
		{
			firstNode->previousNode = tempNode;
		}

		// Set the new first node to this node
		firstNode = tempNode;

		// If the last node hasn't yet been created, set this node to the last node as well
		if (lastNode == NULL)
		{
			lastNode = tempNode;
		}
	}

	void deleteNode(shared_ptr<typename LinkedList<T>::Node> delNode)
	{
		// If the node is the only node in the list, set first and last nodes to NULL
		if (delNode == firstNode && delNode == lastNode)
		{
			firstNode = NULL;
			lastNode = NULL;

			return;
		}

		// If this node is specifically the first node, just set the 2nd node's previous node to null (making it the first node)
		if (delNode == firstNode)
		{
			firstNode = delNode->nextNode;
			(delNode->nextNode)->previousNode = NULL;

			return;
		}

		// If this node is specifically the last node, set the 2nd-to-last node's next node to null (making it the last node)
		if (delNode == lastNode)
		{
			lastNode = delNode->previousNode;
			(delNode->previousNode)->nextNode = NULL;

			return;
		}
		
		// This node is somewhere in the middle, so set the previous node's next node to this node's next node,
		// and the next node's previous node to this node's previous node
		(delNode->previousNode)->nextNode = delNode->nextNode;
		(delNode->nextNode)->previousNode = delNode->previousNode;
	}

	T minimum() const
	{
		// If there is nothing in the list, return 0
		if (isEmpty())
		{
			return 0;
		}

		// Variable to store minimum
		T min = firstNode->data;

		// Make a temporary pointer for an "iterator" to go through starting at the first node
		shared_ptr<typename LinkedList<T>::Node> currentNode = firstNode;
		// Loop through while there are still nodes left to go through
		while (currentNode != NULL)
		{
			// Check if the current node's data is less than the current found minimum value
			if (currentNode->data < min)
			{
				min = currentNode->data;
			}

			currentNode = currentNode->nextNode;
		}

		return min;
	}

	T maximum() const
	{
		// If there is nothing in the list, return 0
		if (isEmpty())
		{
			return 0;
		}

		// Variable to store maximum
		T max = firstNode->data;

		// Make a temporary pointer for an "iterator" to go through starting at the first node
		shared_ptr<typename LinkedList<T>::Node> currentNode = firstNode;
		// Loop through while there are still nodes left to go through
		while (currentNode != NULL)
		{
			// Check if the current node's data is greater than the current found maximum value
			if (currentNode->data > max)
			{
				max = currentNode->data;
			}

			currentNode = currentNode->nextNode;
		}

		return max;
	}

	shared_ptr<typename LinkedList<T>::Node> head() const
	{
		return firstNode;
	}

	shared_ptr<typename LinkedList<T>::Node> tail() const
	{
		return lastNode;
	}

	bool isEmpty() const
	{
		// If first and last node are both null, it's empty
		return firstNode == NULL && lastNode == NULL;
	}

private:
	shared_ptr<typename LinkedList<T>::Node> firstNode = NULL;
	shared_ptr<typename LinkedList<T>::Node> lastNode = NULL;
};
