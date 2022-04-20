#include <iostream>

//	Data type: Queue
/*
	Fixed array:
	Enqueue()	+
	Dequeue()	+
	Empty()		+
	Full()		+
	Size()		+

	Linked list:
	Enqueue()	+
	Dequeue()	+
	Empty()		+
*/

namespace QueueFixedArray
{
	template <class T>
	class Queue
	{
	public:
		Queue(int size);
		~Queue();

		void Enqueue(T value);
		T Dequeue();
		bool Empty();
		bool Full();
		int Size();

	private:
		T* array;
		int size;

		int write;
		int read;
	};

	template<class T>
	Queue<T>::Queue(int _size)
	{
		size = (_size <= 16) ? 16 : _size;
		array = new T[size];
		write = 0;
		read = 0;
	}

	template<class T>
	Queue<T>::~Queue()
	{
		delete[] array;
	}

	template<class T>
	void Queue<T>::Enqueue(T value)
	{
		if (Full())
		{
			return;
		}

		array[write] = value;

		if (write + 1 > size)
		{
			write = 0;
		}
		else
		{
			write++;
		}
	}

	template<class T>
	T Queue<T>::Dequeue()
	{
		if (Empty())
			return NULL;

		T returing = array[read];
		array[read] = NULL;

		if (read + 1 > size)
		{
			read = 0;
		}
		else
		{
			read++;
		}

		return returing;
	}

	template<class T>
	bool Queue<T>::Empty()
	{
		return read == write;
	}

	template<class T>
	bool Queue<T>::Full()
	{
		if (write + 1 > size)
		{
			return 0 == read;
		}
		else
		{
			return write + 1 == read;
		}
	}

	template<class T>
	int Queue<T>::Size()
	{
		return size;
	}
}

namespace QueueLinkedList
{
	#include "LinkedList.cpp"

	template <class T>
	class Queue
	{
	public:
		Queue();
		~Queue();

		void Enqueue(T value);
		T Dequeue();
		bool Empty();

	private:
		LinkedList::LinkedList<T>* list;
	};

	template<class T>
	Queue<T>::Queue()
	{
		list = new LinkedList::LinkedList<T>;
	}

	template<class T>
	Queue<T>::~Queue()
	{
		delete list;
	}

	template<class T>
	void Queue<T>::Enqueue(T value)
	{
		list->PushBack(value);
	}

	template<class T>
	T Queue<T>::Dequeue()
	{
		return list->PopFront();
	}

	template<class T>
	bool Queue<T>::Empty()
	{
		return list->Empty();
	}
}