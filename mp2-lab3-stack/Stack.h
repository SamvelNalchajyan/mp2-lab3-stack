#pragma once
#define MAX_STACK_SIZE 1000000

template <class T>
class TStack
{
private:
	T *arr;
	int size, num;
public:
	TStack(int _size = 20);
	TStack(const TStack<T>& st);
	~TStack();
	bool IsEmpty() const;
	bool IsFull() const;
	void Push(const T& a);
	T Pop();
	T Top() const;
	void Clear();
	TStack<T>& operator=(const TStack<T>& st);
};

template <class T>
TStack<T>::TStack(int _size)
{
	if (_size > 0 && _size <= MAX_STACK_SIZE)
	{
		size = _size;
		arr = new T[size];
		num = -1;
	}
	else
	{
		throw 1;
	}
}

template <class T>
TStack<T>::TStack(const TStack<T>& st)
{
	size = st.size;
	arr = new T[size];
	num = st.num;
	for (int i = 0; i <= num; i++)
	{
		arr[i] = st.arr[i];
	}
}

template <class T>
TStack<T>::~TStack()
{
	delete[] arr;
}

template <class T>
bool TStack<T>::IsEmpty() const
{
	if (num == -1)
	{
		return true;
	}
	return false;
}

template <class T>
bool TStack<T>::IsFull() const
{
	if (num == size - 1)
	{
		return true;
	}
	return false;
}

template <class T>
void TStack<T>::Push(const T& a)
{
	if (IsFull())
	{
		throw 2;
	}
	arr[++num] = a;
}

template <class T>
T TStack<T>::Pop()
{
	if (IsEmpty())
	{
		throw 3;
	}
	return arr[num--];
}

template <class T>
T TStack<T>::Top() const
{
	if (IsEmpty())
	{
		throw 3;
	}
	return arr[num];
}

template <class T>
void TStack<T>::Clear()
{
	num = -1;
}

template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& st)
{
	if (size != st.size)
	{
		delete[] arr;
		size = st.size;
		arr = new T[size];
	}
	num = st.num;
	for (int i = 0; i <= num; i++)
	{
		arr[i] = st.arr[i];
	}
	return *this;
}