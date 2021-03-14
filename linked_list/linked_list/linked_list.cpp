#include <iostream>

struct List
{
    int item;
    struct List *next;
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

// insert in the begin into a List
void insertList(List **l, int x)
{
    List *p;

    p = new List();
    p->item = x;
    p->next = *l;
    *l = p;
}

//Deletion from a list
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

int main()
{
    List *l = new List();
    l = NULL;

    /*insert item into List*/
    insertList(&l, 1);
    insertList(&l, 2);
    insertList(&l, 3);
    printList(l);

    std::cout << "\n----------------\n";
    /*delete item in List*/
    deleteList(&l, 2);
    printList(l);

    delete (l);
    return 0;
}
