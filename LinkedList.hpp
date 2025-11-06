#pragma once
#include <iostream>
using namespace std;



template <typename T>
class LinkedList {
public:

	struct Node {
		T data;
		Node* next;
		Node* prev;

		Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}
	};

	// Behaviors
	void printForward() const{
		Node* curr = head;
    	while (curr){
        	std::cout << curr->data << std::endl;
        	curr = curr->next;
    	}
	}

	void PrintReverse() const{
		Node* curr = tail;
		while (curr){
			std::cout << curr->data << std::endl;
			curr = curr->prev;
		}
	}

	// Accessors
	[[nodiscard]] unsigned int getCount() const;
	Node* getHead();
	const Node* getHead() const;
	Node* getTail();
	const Node* getTail() const;

	// Insertion
	void AddHead(const T& data){
		Node* newNode = new Node(data);
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	void AddTail(const T& data){
		Node* newNode = new Node(data);
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}

	// Removal
	bool RemoveHead();
	bool RemoveTail();
	void Clear();

	// Operators
	LinkedList<T>& operator=(LinkedList<T>&& other) noexcept;
	LinkedList<T>& operator=(const LinkedList<T>& rhs);

	// Construction/Destruction
	LinkedList();
	LinkedList(const LinkedList<T>& list);
	LinkedList(LinkedList<T>&& other) noexcept;
	~LinkedList();

private:
	// Stores pointers to first and last nodes and count
	Node* head;
	Node* tail;
	unsigned int count;

};


