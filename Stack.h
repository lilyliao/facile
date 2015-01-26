#ifndef STACK_INCLUDED
#define STACK_INCLUDED

template <typename T>
class StackNode
{
  public:
  T data;
  StackNode<T>* next;
  StackNode(T d,StackNode<T>*  n)
  {
	  data = d;
	  next = n;
  }
};

template <typename T>
class Stack
{
public:
	Stack();
	void push(T x);
	void pop();
	T top() const;
	bool empty() const;

private:
	StackNode<T> * m_top;
};


template <typename T>
Stack<T>::Stack()
	{
	m_top = 0;
	}

template <typename T>
void Stack<T>::push(T x)
	{
      m_top = new  StackNode<T>(x,m_top);
	}

template <typename T>
void Stack<T>::pop()
	{
	m_top = m_top->next;
	}

template <typename T>
T Stack<T>::top() const
	{
	return m_top->data;
	}

template <typename T>
bool Stack<T>::empty() const
	{
	return m_top == 0;
	}


#endif

