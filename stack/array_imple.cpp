#include <iostream>

class ArrayStack
{
private:
    int *array;
    int size;
    int capacity;

public:
    ArrayStack(int maxsize);

    ~ArrayStack();

    bool isEmptyStack();

    bool isFullStack();

    void push(int data);

    void pop();

    int top();

    void increaseCapacity();
};

ArrayStack::ArrayStack(int maxsize) : array(new int[maxsize]), capacity(maxsize), size(-1) { increaseCapacity(); }

ArrayStack::~ArrayStack() { delete[] array; }

bool ArrayStack::isEmptyStack() { return (size == -1); }

bool ArrayStack::isFullStack() { return (capacity - 1 == size); }

void ArrayStack::push(int data)
{
    if (isFullStack())
        increaseCapacity();

    array[++size] = data;
}

void ArrayStack::pop()
{
    if (isEmptyStack())
    {
        throw "the stack array is empty, it is impossible to pop the element";
    }
    else
    {
        --size;
    }
}

int ArrayStack::top()
{
    if (isEmptyStack())
    {
        throw "the stack array is empty, it is impossible to pop the element";
    }
    else
        return array[size];
}

void ArrayStack::increaseCapacity()
{
    if (capacity == size)
    {
        capacity += 5;
    }
}

int main()
{
    ArrayStack arr(5);
    try
    {
        arr.push(1);
        arr.push(2);
        arr.push(10);
        arr.pop();
        std::cout << arr.top();
    }
    catch (const char *message)
    {
        std::cerr << message << '\n';
    }

    return 0;
}