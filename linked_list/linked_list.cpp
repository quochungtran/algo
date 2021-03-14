#include <iostream>

struct List
{
    int item;
    struct List *next;
    List() : item(0), next(NULL) {}
    List(int x) : item(x), next(nullptr) {}
    List(int x, List *nodeNext) : item(x), next(nodeNext){};
};

// searching a list
List *searchList(List *l, int x)
{
    if (l == NULL)
        return NULL;

    if (l->item == x)
        return l;
    else
        return (searchList(l->next, x));
}

List *predecessorList(List *l, int x)
{
    if (l == NULL || (l->next == NULL))
    {
        std::cout << ("Error: predecessor sought on null list.\n");
        return (NULL);
    }

    if ((l->next)->item == x)
        return l;
    else
        return (predecessorList(l->next, x));
}

// insert in the begin into a List
void insertList(List **l, int x)
{
    List *p;

    p = new List();
    p->item = x;
    p->next = *l;
    *l = p;
}

// insert in the middle of the list
void insertInList(List **l, int x, int pos)
{
    List *newNode = new List();
    List *head;
    List *pred;
    int k = 1;

    newNode->item = x;
    head = *l;

    if (pos == 1)
    {
        insertList(l, x);
    }
    else
    {
        while (head != NULL && k < pos)
        {
            head = head->next;
            k++;
        }
        std::cout << pred->item;
        pred->next = newNode;
        newNode->next = head;
    }
}

//Deletion from a list
void deleteList(List **l, int x)
{
    List *p;
    List *pred;

    p = searchList(*l, x);
    if (p != NULL)
    {
        pred = predecessorList(*l, x);
        if (pred == NULL)
        {
            *l = p->next;
        }
        else
        {
            pred->next = p->next;
        }
        delete (p);
    }
}

// print List
void printList(List *l)
{
    List *head = l;

    while (head != NULL)
    {
        std::cout << head->item << " ";
        head = head->next;
    }
}

//length of the list
int listLength(List *l)
{
    int count = 0;
    while (l != NULL)
    {
        count++;
        l = l->next;
    }
    return count;
}

int main()
{
    List *l = new List();
    l = NULL;

    /*insert item into List*/
    insertList(&l, 1);
    insertList(&l, 2);
    insertList(&l, 3);
    insertInList(&l, 5, 1);
    insertInList(&l, 20, 4);

    printList(l);

    /*delete item in List*/
    std::cout << "\n----------------\n";
    deleteList(&l, 2);
    printList(l);

    /*Lenght of the List*/
    std::cout << "\n----------------\n";
    std::cout << "Length of the list : ";
    std::cout << listLength(l);
    delete (l);
    return 0;
}
