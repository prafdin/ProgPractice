#include <iostream>
#include<string>
class Pair {
	char* key;
	double val;
public:
	Pair():key(nullptr),val(0){}
	Pair(const char* k, double v) {
		key = strdup(k);
		val = v;
	}
	Pair(const Pair& pair) {
		key = strdup(pair.key);
		val = pair.val;
	}
	const char* get_key() const {
		return key;
	}
	~Pair() {
		if (key) free(key);
		double val = 0;
	}
};
class Elem {
	Pair _pair;
	Elem* _next;
	friend class List;
	friend List operator+(const List& lhs, const List& rhs);
public:
	Elem():_pair(),_next(nullptr){}
	Elem(const Pair& pair, Elem* next) : _pair(pair), _next(next) {}
	Pair get() const {
		return _pair;
	}
};
class List {
	Elem* head;
	friend List& operator+(const Pair& lhs, List& rhs);
public:
	List() : head(nullptr) {}
	List(Elem* head) : head(head) {}
	const Elem* get()const {
		return head;
	}
	List& operator+(const Pair& rhs) {
		auto tmp = new Elem(rhs, nullptr);
		Elem* tail = nullptr;
		while (tail!=nullptr || tail->_next != nullptr) {
			tail = tail->_next;
		}
		tail->_next = tmp;
		return *this;
	}
	List& operator+=(const Pair& rhs) {
		return *this + rhs;
	}
	List& operator +=(const List& rhs) {
		List tmp=*this+rhs;
		clear();
		head = tmp.head;
		tmp.head = nullptr;
	}
	Elem& operator[](size_t index) {
		Elem* tmp = head;
		for (size_t i = 0; i < index; ++i) {
			tmp=tmp->_next;
		}
		return *tmp;
	}
	Elem& operator [](const char* key) {
		Elem* elem = head;
		while(elem!=nullptr) {
			if (key == elem->_pair.get_key()) {
				return *elem;
			}
			else
				elem = elem->_next;
		}
		return Elem();
	}
	void clear() {
		do {
			auto tmp = head->_next;
			delete head;
			head = tmp;

		} while (head != nullptr);
		head = nullptr;
	}
};
List& operator+(const Pair& lhs, List& rhs) {
	auto tmp = new Elem(lhs, rhs.head);
	rhs.head = tmp;
	return rhs;
}
List operator+(const List& lhs, const List& rhs) {
	List tmp;
	auto src1 = lhs.get();
	auto src2 = rhs.get();
	while (src1 != nullptr) {
		tmp = tmp + src1->get();
		src1 = src1->_next;
	}
	while (src2 != nullptr) {
		tmp = tmp + src2->get();
		src2 = src2->_next;
	}
	return tmp;
}

int main(void) {

}