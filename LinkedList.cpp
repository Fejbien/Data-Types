#include <iostream>

//	Data type: LinkedList
/*
	size()			+
	empty()			+
	valueAt()		+
	pushFront()		+
	popFront()		+
	pushBack()		+
	popBack()		+
	front()			+
	back()			+
	insert()		+
	erase()			+
	valueNFromEnd()	+
	reverse()		+
	removeValue()	+
*/

namespace LinkedList
{
	template <typename T>
	struct Node
	{
		T value;
		Node* next;
	};

	template <class T>
	class LinkedList
	{
	public:
		LinkedList();
		~LinkedList();

		int Size();
		bool Empty();
		T ValueAt(int index);
		void PushFront(T value);
		T PopFront();
		void PushBack(T value);
		T PopBack();
		T Front();
		T Back();
		void Insert(int index, T value);
		void Erase(int index);
		T ValueNFromEnd(int n);
		void Reverse();
		void RemoveValue(T value);

	private:
		int size;
		Node<T>* head;
		Node<T>* tail;
	};


	template<class T>
	LinkedList<T>::LinkedList()
	{
		size = 0;
		head = NULL;
		tail = NULL;
	}

	template<class T>
	LinkedList<T>::~LinkedList()
	{
		Node<T>* temp;
		for (int i = 0; i < size; i++)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
	}

	template<class T>
	int LinkedList<T>::Size()
	{
		return size;
	}

	template<class T>
	bool LinkedList<T>::Empty()
	{
		return size == 0 ? true : false;
	}

	template<class T>
	T LinkedList<T>::ValueAt(int index)
	{
		if (index >= size)
			return NULL;

		Node<T>* temp = head;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		return temp->value;
	}

	template<class T>
	void LinkedList<T>::PushFront(T value)
	{
		Node<T>* temp = new Node<T>;
		temp->value = value;
		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			temp->next = head;
			head = temp;
		}

		size++;
	}

	template<class T>
	T LinkedList<T>::PopFront()
	{
		Node<T>* temp = head;
		T returningValue = temp->value;
		head = head->next;
		delete temp;
		size--;

		if (size == 0)
			tail = NULL;

		return returningValue;
	}

	template<class T>
	void LinkedList<T>::PushBack(T value)
	{
		Node<T>* temp = new Node<T>;
		temp->value = value;
		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = tail->next;
		}

		size++;
	}

	template<class T>
	T LinkedList<T>::PopBack()
	{
		Node<T>* temp = head;
		for (int i = 1; i < size - 1; i++) // penultimate node :D
			temp = temp->next;

		T returningValue = tail->value;

		delete temp->next;
		temp->next = NULL;
		tail = temp;
		size--;

		if (size == 0)
		{
			tail = NULL;
			head = NULL;
		}

		return returningValue;
	}

	template<class T>
	T LinkedList<T>::Front()
	{
		if (head == NULL)
			return NULL;

		return head->value;
	}

	template<class T>
	T LinkedList<T>::Back()
	{
		if (tail == NULL)
			return NULL;
		return tail->value;
	}

	template<class T>
	void LinkedList<T>::Insert(int index, T value)
	{
		if (index == 0)
		{
			Node<T>* temp = new Node<T>;
			temp->next = head;
			temp->value = value;
			head = temp;
			size++;
			return;
		}

		Node<T>* temp = head;
		for (int i = 0; i < index - 1; i++)
			temp = temp->next;

		Node<T>* tempAdd = new Node<T>;
		tempAdd->next = temp->next;
		temp->next = tempAdd;
		tempAdd->value = value;

		if (tempAdd->next == NULL)
			tail = tempAdd;

		size++;
	}

	template<class T>
	void LinkedList<T>::Erase(int index)
	{
		if (index == 0)
		{
			Node<T>* temp = head;
			head = temp->next;
			size--;
			delete temp;
			return;
		}

		Node<T>* temp = head;
		for (int i = 1; i < index - 1; i++)
			temp = temp->next;

		Node<T>* toDel = temp->next;
		temp->next = toDel->next;

		if (temp->next == NULL)
			tail = temp;

		size--;
		delete toDel;
	}

	template<class T>
	T LinkedList<T>::ValueNFromEnd(int n)
	{
		Node<T>* temp = head;
		for (int i = 1; i < size - n; i++)
			temp = temp->next;

		return temp->value;
	}

	template<class T>
	void LinkedList<T>::Reverse()
	{
		if (size <= 1) return;

		if (size == 2)
		{
			Node<T>* temp1 = head;
			Node<T>* temp2 = tail;

			temp2->next = head;
			temp1->next = NULL;

			tail = temp1;
			head = temp2;

			return;
		}

		Node<T>* current = head->next;
		Node<T>* prev = head;
		Node<T>* following = head->next->next;

		prev->next = NULL;
		tail = prev;

		while (following->next != NULL)
		{
			current->next = prev;
			prev = current;
			current = following;
			following = following->next;
		}

		current->next = prev;
		prev = current;
		following->next = current;
		head = following;
	}

	template<class T>
	void LinkedList<T>::RemoveValue(T value)
	{
		Node<T>* temp = head;
		if (head->value == value)
		{
			Node<T>* temp = head;
			head = temp->next;
			size--;
			delete temp;
			return;
		}

		for (int i = 1; i < size - 1; i++)
		{
			temp = temp->next;
			if (temp->next->value == value)
			{
				Node<T>* temp = head;
				for (int i = 1; i < size - 1; i++)
					temp = temp->next;

				Node<T>* toDel = temp->next;
				temp->next = toDel->next;

				if (temp->next == NULL)
					tail = temp;

				size--;
				delete toDel;
				return;
			}
		}
	}
}