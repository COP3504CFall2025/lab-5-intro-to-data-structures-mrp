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
			head = nullptr;
			tail = nullptr;
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
			tail = nullptr;
			head = nullptr;
		} else {
			tail = tail->prev;
			tail->next = nullptr;
		}

		delete temp;
		count--;
		
		return true;
	}
	void Clear(){
		while (count>0){
			RemoveTail();
		}
	}

	// Operators
	LinkedList<T>& operator=(LinkedList<T>&& other) noexcept{
		if (this==&other) return *this;
		Clear();

		head = other.getHead();
		tail = other.getTail();
		count = other.getCount();

		other.Clear();
		return *this;
	}
	LinkedList<T>& operator=(const LinkedList<T>& rhs){

		if (this==&rhs) return *this;

		Clear();
		const Node* curr = rhs.getHead();
		
    	while (curr){
        	AddTail(curr->data);
        	curr = curr->next;
    	}

		return *this;
	}

	// Construction/Destruction
	LinkedList(){
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	LinkedList(const LinkedList<T>& list){
		head = nullptr;
		tail = nullptr;
		count = 0;
		
		const Node* curr = list.getHead();
		
    	while (curr){
        	AddTail(curr->data);
        	curr = curr->next;
    	}
	}
	LinkedList(LinkedList<T>&& other) noexcept{
		head = other.getHead();
		tail = other.getTail();
		count = other.getCount();

		other.Clear();
	}
	~LinkedList(){
		Clear();
	}

private:
	// Stores pointers to first and last nodes and count
	Node* head;
	Node* tail;
	unsigned int count;

};


