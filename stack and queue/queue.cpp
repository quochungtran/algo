#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reserveQueueFirstKElement(queue<int> *Q, int k)
{
    if (Q->empty() || k > Q->size())
    {
        return;
    }
    else if (k > 0)
    {
        stack<int> stk;
        for (int i = 0; i < k; i++)
        {
            stk.push(Q->front());
            Q->pop();
        }
        while (!stk.empty())
        {
            Q->push(stk.top());
            stk.pop();
        }
        //wrap the rest of elements
        for (int i = 0; i < Q->size() - k; i++)
        {
            Q->push(Q->front());
            Q->pop();
        }
    }
}

int main()
{
    queue<int> Q;

    Q.push(10);
    Q.push(20);
    Q.push(30);
    Q.push(40);
    Q.push(50);
    Q.push(60);
    Q.push(70);
    Q.push(80);
    Q.push(90);
    Q.push(100);

    // afficher queue

    std::cout << "-----------Reserve-----------" << endl;

    reserveQueueFirstKElement(&Q, 4);
    cout << "Queue size before printing the elements: "
         << Q.size() << endl;
    cout << "Queue element are..." << endl;
    while (!Q.empty())
    {
        cout << " " << Q.front();
        Q.pop();
    }

    cout << endl;
    cout << "Queue size after printing the elements: " << Q.size() << endl;
    return 0;
}