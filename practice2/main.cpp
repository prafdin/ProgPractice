#include <iostream>
#include<cstdlib>
class Stack
{
public:
	virtual void push(double number) = 0;
	virtual double pop() = 0;
	virtual double read() const = 0;
	virtual double& read() = 0;
	virtual void clear() = 0;
	virtual void print() const = 0;
	virtual ~Stack() {};
};

class List :public Stack {
	struct Node {
		double data;
		Node* next;
		Node(double data,Node* next):data(data),next(next){}
	};
	Node* head;
public:
	List(): head(nullptr){}
	virtual void push(double number) {
		head = new Node(number, head);
	}
	virtual double pop() {
		if (head == nullptr)
			throw 1;
		Node* tmp=head;
		double value = tmp->data;
		head = head->next;
		delete tmp;
		return value;
	}
	virtual double& read()   {
		if (head == nullptr)
			throw 1;
		return head->data;
	}
	virtual double read() const {
		if (head == nullptr)
			throw 1;
		return head->data;
	}
	virtual void clear() {
		while (head != nullptr){
			Node* tmp = head->next;
			delete head;
			head = tmp;
		}
	}
	virtual void print() const {
		Node* tmp = head;
		while (tmp != nullptr) {
			printf("%f ",tmp->data);
			tmp = tmp->next;
		}
	}
	virtual ~List() {
		clear();
	}
};
int main(void) {
	
}