export module Vector;

import <iostream>;
import <fstream>;
import <string>;
import <compare>;

template<typename X>
class Node {
public:
	X data;
	Node* next;

	Node(const X& value) :data(value), next(nullptr) {}
};

export template <typename X>
class Vector {
private:
	Node<X>* head;
	Node<X>* tail;
	size_t size;

	void delete_nodes() {
		Node<X>* current = head;
		while (current) {
			Node<X>* to_delete = current;
			current = current->next;
			delete to_delete;
		}
		head = tail = nullptr;
		size = 0;
	}

public:
	Vector() : head(nullptr), tail(nullptr), size(0) {}
	~Vector() { delete_nodes(); }

	void add(const X& value)
	{
		Node<X>* new_node = new Node<X>(value);
		if (tail) {
			tail->next = new_node;
		}
		else
			head = new_node;
		tail = new_node;
		++size;
	}

	void display(std::ostream& out) const {
		Node<X>* current = head;
		while (current)
		{
			out << current->data << ' ';
			current = current->next;
		}
		out << '\n';
	}

	void clear() { delete_nodes(); }

	void sort()
	{
		if (!head || !head->next) return;
		for (Node<X>* i = head; i; i = i->next)
		{
			for (Node<X>* j = i->next; j; j = j->next)
			{
				if (i->data > j->data) {
					std::swap(i->data, j->data);
				}
			}
		}
	}

	X max_value() const {
		if (head)
		{
			X max_val = head->data;
			for (Node<X>* current = head->next; current; current = current->next)
			{
				if (current->data > max_val)
					max_val = current->data;
			}
			return max_val;
		}
	}

	X min_value() const {
		if (head)
		{
			X min_val = head->data;
			for (Node<X>* current = head->next; current; current = current->next)
			{
				if (current->data < min_val)
					min_val = current->data;
			}
			return min_val;

		}
	}

	bool is_empty()const {
		return head == nullptr;
	}

	void remove_by_value(const X& value)
	{
		bool isDeleted=false;
		while (head && head->data == value && !isDeleted)
		{

		}

	}
};
