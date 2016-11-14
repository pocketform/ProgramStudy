#include <iostream>

using namespace std;

template <typename T>
class Stack
{
public:
	Stack();
	~Stack();
	void push(T new_value);
	void pop();
	size_t getsize();
	bool check();
private:
	T value;
};

template <typename T>
Stack<T>::Stack()
{

}

template <typename T>
Stack<T>::~Stack()
{

}

template <typename T>
void Stack<T>::push(T new_value)
{
	value = new_value;
}

template <typename T>
void Stack<T>::pop()
{
	value = NULL;
}

template <typename T>
size_t Stack<T>::getsize()
{
	return sizeof(value);
}

template <typename T>
bool Stack<T>::check()
{
	if (value == NULL)
	{
		return false;
	}

	else if (value != NULL )
	{
		return true;
	}
}

int main()
{
	int a = 11;
	bool check;
	size_t size;
	Stack<int> my_int;

	check = my_int.check();
	my_int.push(a);
	check = my_int.check();
	size = my_int.getsize();
	my_int.pop();
	check = my_int.check();

	int exit;
	cin >> exit;


}
