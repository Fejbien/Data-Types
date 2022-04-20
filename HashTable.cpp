#include <iostream>

//	Data type: Queue
/*
	
*/

namespace HashTable
{
	template <class T>
	class HashTable
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
}