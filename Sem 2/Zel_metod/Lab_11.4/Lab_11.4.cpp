#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct Stack
{
	Node* top;
	int size;
	void init()
	{
		top = nullptr;
		size = 0;
	}
};

void push(Stack*& stack, int data)
{
	Node* tmp = new Node;
	tmp->data = data;
	tmp->next = stack->top;
	stack->top = tmp;
	stack->size++;
}

void pop(Stack*& stack)
{
	if (stack->top == nullptr)
	{
		return;
	}
	stack->top = stack->top->next;
	stack->size--;
}
void insert_element(Stack*& stack, int pos, int data)
{
	Stack* tmp = new Stack;
	tmp->init();
	int init_size = stack->size;
	if (pos == 1)
	{
		push(stack, data);
	}
	else
	{
		for (int i = 0; i <= init_size - pos; i++)
		{
			push(tmp, stack->top->data);
			pop(stack);
		}
		push(stack, data);
		init_size = tmp->size;
		for (int i = 0; i < init_size; i++)
		{
			push(stack, tmp->top->data);
			pop(tmp);
		}
	}
	delete tmp;
}
void insert_elements(Stack*& stack, int pos, int k)
{
	Stack* tmp = new Stack;
	tmp->init();
	int data;
	int init_size = stack->size;
	cout << "What elements to add: ";
	if (pos == 1)
	{
		for (int i = 0; i < k; i++)
		{
			cin >> data;
			push(stack, data);
		}
	}
	else
	{
		for (int i = 0; i <= init_size - pos; i++)
		{
			push(tmp, stack->top->data);
			pop(stack);
		}
		for (int i = 0; i < k; i++)
		{
			cin >> data;
			push(stack, data);
		}
		init_size = tmp->size;
		for (int i = 0; i < init_size; i++)
		{
			push(stack, tmp->top->data);
			pop(tmp);
		}
	}
	delete tmp;
}
void delete_element(Stack*& stack, int pos)
{
	Stack* tmp = new Stack;
	tmp->init();
	int init_size = stack->size;
	if (pos == 1)
	{
		pop(stack);
	}
	else
	{
		for (int i = 0; i < init_size - pos; i++)
		{
			push(tmp, stack->top->data);
			pop(stack);
		}
		pop(stack);
		init_size = tmp->size;
		for (int i = 0; i < init_size; i++)
		{
			push(stack, tmp->top->data);
			pop(tmp);
		}
	}
	delete tmp;
}

void delete_elements(Stack*& stack, int pos, int k)
{
	Stack* tmp = new Stack;
	tmp->init();
	int init_size = stack->size;
	if (pos == 1)
	{
		for (int i = 0; i < k; i++)
		{
			pop(stack);
		}
	}
	else
	{
		for (int i = 0; i < init_size - pos; i++)
		{
			push(tmp, stack->top->data);
			pop(stack);
		}
		for (int i = 0; i < k; i++)
		{
			pop(stack);
		}
		init_size = tmp->size;
		for (int i = 0; i < init_size; i++)
		{
			push(stack, tmp->top->data);
			pop(tmp);
		}
	}
	delete tmp;
}

void search_element(Stack*& stack, int element)
{
	Stack* curr = new Stack;
	curr->init();
	while (stack->top != nullptr)
	{
		if (stack->top->data == element)
		{
			cout << "Founded" << endl;
			return;
		}
		else
		{
			push(curr, stack->top->data);
			pop(stack);
		}
	}
	cout << "Not founded" << endl;
}


Stack* createStack(int n)
{
	Stack* stack = new Stack;
	stack->init();
	int data;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		push(stack, data);
	}
	return stack;
}

void printStack(Stack*& stack)
{
	Node* curr = stack->top;
	for (int i = 0; i < stack->size; i++)
	{
		cout << curr->data << ' ';
		curr = curr->next;
	}
	cout << endl;
}

int main()
{
	int size, data, pos, k, element;
	cout << "Type stack size: ";
	cin >> size;
	cout << "Type data" << endl;
	Stack* stack = createStack(size);
	cout << "Your stack is" << endl;
	printStack(stack);
	cout << "Type what element to add to top: ";
	cin >> data;
	push(stack, data);
	printStack(stack);
	pop(stack);
	printStack(stack);
	cout << "Type what element to add at which index: ";
	cin >> data;
	cin >> pos;
	insert_element(stack, pos, data);
	printStack(stack);
	cout << "Type what elements to add at which index: ";
	cin >> k;
	cin >> pos;
	insert_elements(stack, pos, k);
	printStack(stack);
	cout << "Type what element to delete: ";
	cin >> pos;
	delete_element(stack, pos);
	printStack(stack);
	cout << "Type index from which to delete elements: ";
	cin >> k;
	cin >> pos;
	delete_elements(stack, pos, k);
	printStack(stack);
	cout << "Which element to found: ";
	cin >> element;
	search_element(stack, element);
	return 0;
}

