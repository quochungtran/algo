class ArrayQueue
{
private:
    int front, rear;
    int capacity;
    int sizeQueue;
    int *array;

public:
    ArrayQueue(int size);

    ~ArrayQueue();

    int isEmptyQueue();

    int isFullQueue();

    void reSize();

    void enQueue(int data);

    int deQueue();

    void deleteQueue();
};

ArrayQueue::ArrayQueue(int size) : capacity(size), sizeQueue(0), front(-1), rear(-1)
{
    array = new int[capacity];
}

ArrayQueue::~ArrayQueue()
{
    deleteQueue();
}

int ArrayQueue::isEmptyQueue()
{
    return (sizeQueue == 0);
}

int ArrayQueue::isFullQueue()
{
    return sizeQueue == capacity;
}

void ArrayQueue::reSize()
{
}

void ArrayQueue::enQueue(int data)
{
    if (isFullQueue())
        throw "Queue overflow ";
    else
    {
        rear = (rear + 1) % capacity;
        array[rear] = data;
        sizeQueue++;
    }
}

int ArrayQueue::deQueue()
{
    int x;

    if (isEmptyQueue)
    {
        throw "Empty queue deque";
    }
    else
    {
        x = array[front];
        front = (front + 1) % capacity;
        sizeQueue--;
    }

    return x;
}

void ArrayQueue::deleteQueue()
{
    sizeQueue = 0;
    capacity = 0;
    front = rear = -1;
    delete[] array;
}
