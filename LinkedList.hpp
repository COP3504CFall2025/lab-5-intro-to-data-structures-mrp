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
	[[nodiscard]] unsigned int getCount() const{
		return count;
	}
	Node* getHead(){
		return head;
	}
	const Node* getHead() const{
		return head;
	}
	Node* getTail(){
		return tail;
	}
	const Node* getTail() const{
		return tail;
	}

	// Insertion
	void AddHead(const T& data){
		Node* newNode = new Node(data);
		if (head){
			newNode->next = head;
			head->prev = newNode;
		} else {
			tail = newNode;
		}

		head = newNode;
		
		count++;
	}
	void AddTail(const T& data){
		Node* newNode = new Node(data);
		if (tail){
			newNode->prev = tail;
			tail->next = newNode;
		} else {
			head = newNode;
		}
		
		tail = newNode;

		count++;
	}

	// Removal
	bool RemoveHead(){
		if (!head) return false;
		Node* temp = head;
		if (head == tail) {
			head == nullptr;
			tail == nullptr;
		} else {
			head = head->next;
			head->prev = nullptr;
		}

		delete temp;
		count--;
		
		return true;
	}
	bool RemoveTail(){
		if (!tail) return false;

		Node* temp = tail;

		if (tail == head) {
			tail == nullptr;
			head == nullptr;
		} else {
			tail = tail->prev;
			tail->next = nullptr;
		}

		delete temp;
		count--;
		
		return true;
	}
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


