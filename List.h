#pragma once
#include <iostream>
using namespace std;

template <typename TYPE>
struct Node
{
	TYPE value;
	Node* next;
	Node()
	{
		value = nullptr;
		next = nullptr;
	}
	Node(TYPE value)
	{
		this->value = value;
		this->next = nullptr;
	}
};
template <typename TYPE>
class List
{
private:
	Node<TYPE>* head;
public:
	List()
	{
		this->head = nullptr;
	}
	List(Node<TYPE>* head)
	{
		this->head = head;
	}
	List(TYPE value)
	{
		this->head = new Node<TYPE>(value);
	}
	TYPE read(int index)
	{
		Node<TYPE>* current = this->head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		return current->value;
	}
	Node<TYPE>* search(TYPE value)
	{
		Node<TYPE>* current = this->head;
		while (current->value != value && current != nullptr)
		{
			current = current->next;
		}
		return current;
	}
	void insert(TYPE value, int index)
	{
		Node<TYPE>* noob = new Node<TYPE>(value);
		if (this->head == nullptr)
		{
			this->head = noob;
			return;
		}
		Node<TYPE>* current = this->head;
		for (int i = 0; i < index - 1 && current != nullptr && current->next != nullptr; i++)
		{
			current = current->next;
		}
		if (index == 0)
		{
			noob->next = this->head;
			this->head = noob;
		}
		else
		{
			noob->next = current->next;
			current->next = noob;
		}
	}
	void remove(int index)
	{
		Node<TYPE>* current = this->head;
		for (int i = 0; i < index - 1 && current != nullptr; i++)
		{
			current = current->next;
		}
		Node<TYPE>* prepareToDie = current->next;
		if (index == 0)
		{
			this->head = prepareToDie;
			delete current;
		}
		else
		{
			current->next = current->next->next;
			delete prepareToDie;
		}
	}
	void remove(TYPE value)
	{
		Node<TYPE>* current = this->search(value);
		if (current == nullptr)
		{
			return;
		}
		Node<TYPE>* prepareToDie = current->next;
		if (current == this->head)
		{
			this->head = prepareToDie;
			delete current;
		}
		else
		{
			current->value = current->next->value;
			current->next = prepareToDie->next;
			delete prepareToDie;
		}
	}
	void print()
	{
		cout << "[ ";
		Node<TYPE>* current = this->head;
		while (current != nullptr)
		{
			cout << current->value << " ";
			current = current->next;
		}
		cout << " ]" << endl;
	}
};
