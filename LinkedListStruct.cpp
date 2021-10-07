#ifndef __LinkedListStruct_cpp
#define __LinkedListStruct_cpp
#include <iostream>

template <class T>
struct sNode //struct node
{
    T data;
    sNode<T> *next;
};

// Insert
template <class T>
void push_front(sNode<T> **head, const T &data)
{
    sNode<T> *node = new sNode<T>;
    node->data = data;
    node->next = *head;
    *head = node;
}
template <class T>
void push_back(sNode<T> **head, const T &data)
{
    sNode<T> *nNode = new sNode<T>();
    nNode->data = data;
    nNode->next = NULL;
    if (*head == NULL)
    {
        *head = nNode;
    }
    else
    {
        sNode<T> *it; //iterator
        it = *head;
        while (it->next != NULL)
        {
            it = it->next;
        }
        it->next = nNode;
    }
}
template <class T>
void insert(sNode<T> **head, const T &data, size_t index)
{
    if (index == 0)
    {
        push_front(head, data);
        return;
    }
    size_t size_list = size(*head);
    if (index > size_list)
    {
        push_back(head, data);
        return;
    }
    sNode<T> *nNode = new sNode<T>();
    nNode->data = data;
    sNode<T> *it = *head;
    for (size_t i = 0; i < index - 1; i++)
    {
        it = it->next;
    }
    nNode->next = it->next;
    it->next = nNode;
}
//delete node
template <class T>
void pop_front(sNode<T> **head)
{
    if (empty(*head))
    {
        return;
    }
    size_t lSize = size(*head);
    if (lSize == 1)
    {
        sNode<T> *dNode = *head;
        (*head) = NULL;
        delete dNode;
    }
    else
    {
        sNode<T> *dNode = *head;
        (*head) = dNode->next;
        delete dNode;
    }
}
template <class T>
void pop_back(sNode<T> **head)
{
    if (empty(*head))
    {
        return;
    }
    size_t lSize = size(*head);
    if (lSize == 1)
    {
        sNode<T> *dNode = *head;
        (*head) = NULL;
        delete dNode;
    }
    else
    {
        sNode<T> *dNode = *head;
        for (int i = 0; i < lSize - 2; i++)
        {
            dNode = dNode->next;
        }
        sNode<T> *dNode2 = dNode->next;
        dNode->next = NULL;
        delete dNode2;
    }
}
template <class T>
void erase(sNode<T> **head, size_t index)
{
    if (empty(*head))
    {
        return;
    }
    size_t len = size(*head);
    if (index >= len)
    {
        return;
    }
    else
    {
        if (index == 0)
            pop_front(head);
        else if (index == len - 1)
            pop_back(head);
        else
        {
            sNode<T> *dNode = *head;
            for (int i = 0; i < index - 1; i++)
            {
                dNode = dNode->next;
            }
            sNode<T> *dNode2 = dNode->next;
            dNode->next = dNode2->next;
            delete dNode2;
        }
    }
}

//capacity
template <class T>
size_t size(sNode<T> *head)
{
    size_t count = 0;
    while (head->next != NULL)
    {
        count++;
        head = head->next;
    }
    return count + 1;
}
template <class T>
bool empty(sNode<T> *head)
{
    return (head == NULL);
}

//Access
template <class T>
T &front(sNode<T> *head)
{
    return head->data;
}
template <class T>
T &back(sNode<T> *head)
{
    sNode<T> *it = head;
    while (it->next != NULL)
    {
        it = it->next;
    }
    return it->data;
}

//Reverse a linked list
template <class T>
void Reverse(sNode<T> **head)
{
    sNode<T> *previous, *current, *next;
    previous = NULL;
    current = *head;
    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *head = previous;
}
//In list
template <class T>
void printList(sNode<T> *head)
{
    if (empty(head))
    {
        std::cout << "list is empty";
    }
    else
    {
        sNode<T> *it = head; //iterator
        std::cout << "List is ";
        while (it != NULL)
        {
            std::cout << it->data << " ";
            it = it->next;
        }
        std::cout << "\t" << size(head);
    }
    std::cout << std::endl;
}
template <class T>
void Print(sNode<T> *head)
{
    if (head == NULL)
        return;
    std ::cout << head->data << " ";
    Print(head->next);
}
#endif