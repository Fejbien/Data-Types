#include <iostream>

//	Data type: Vector
/*
	size()      +
	capacity()  +
	is_empty()  +
	at()        +
	push()      +
	insert()    +
	prepend()   +
	pop()       +
	delete()    +
	remove()    +
	find()      +
	resize()    +
*/

namespace Vector
{
	template <class T>
	class Vector
	{
	public:
		Vector();
		~Vector();

		int Size();
		int Capacity();
		bool IsEmpty();
		T At(int index);
		void Push(T item);
		void Instert(int index, T item);
		void Prepend(T item);
		T Pop();
		void Delete(int index);
		void Remove(T item);
		int Find(T item);

	private:
		void Resize();

		int size;
		int capacity;

		T* array;
	};

	template <class T>
	Vector<T>::Vector()
	{
		size = 0;
		capacity = 16;

		array = new T[capacity];
	}

	template <class T>
	Vector<T>::~Vector()
	{
		delete[] array;
	}

	template<class T>
	int Vector<T>::Size()
	{
		return size;
	}

	template<class T>
	int Vector<T>::Capacity()
	{
		return capacity;
	}

	template<class T>
	bool Vector<T>::IsEmpty()
	{
		if (size == 0)
			return true;
		else
			return false;
	}

	template<class T>
	T Vector<T>::At(int index)
	{
		return array[index];
	}

	template<class T>
	void Vector<T>::Push(T item)
	{
		array[size] = item;
		size++;

		Resize();
	}

	template<class T>
	void Vector<T>::Instert(int index, T item)
	{
		size++;
		Resize();
		for (int i = size - 1; i > index; i--)
		{
			array[i] = array[i - 1];
		}

		array[index] = item;
	}

	template<class T>
	void Vector<T>::Prepend(T item)
	{
		Instert(0, item);
	}

	template<class T>
	T Vector<T>::Pop()
	{
		size--;
		T temp = array[size];
		array[size] = NULL;
		Resize();
		return temp;
	}

	template<class T>
	void Vector<T>::Delete(int index)
	{
		size--;
		for (int i = index; i < size; i++)
			array[i] = array[i + 1];

		Resize();
	}

	template<class T>
	void Vector<T>::Remove(T item)
	{
		int tempSize = size;
		for (int i = 0; i < tempSize; i++)
		{
			if (array[i] == item)
			{
				Delete(i);
				i--;
				tempSize--;
			}
		}
	}

	template<class T>
	int Vector<T>::Find(T item)
	{
		for (int i = 0; i < size; i++)
		{
			if (item == array[i])
				return i;
		}

		return -1;
	}

	template<class T>
	void Vector<T>::Resize()
	{
		if (capacity <= size)
			capacity *= 2;
		else if (capacity / 4 > size && capacity > 16)
			capacity /= 2;
		else
			return;

		T* temp = new T[capacity];

		for (int i = 0; i < size; i++)
		{
			temp[i] = array[i];
		}

		delete[] array;
		array = temp;
	}
}