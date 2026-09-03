#include "./../lib.h"
#include <iostream>

using namespace std;

template <typename T>
Node<T> *middle(Node<T> *head)
{
    Node<T> *fast_ptr = head;
    Node<T> *slow_ptr = head;

    while (fast_ptr != nullptr && fast_ptr->next != nullptr)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    return slow_ptr;
}

int main()
{
    Node<int> *head = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5, nullptr)))));
    Node<int> *head_2 = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, nullptr))));
    Node<int> *head_3 = new Node<int>(1, nullptr);

    cout << "Middle 5 elements: " << middle(head)->data << endl;
    cout << "Middle 4 elements: " << middle(head_2)->data << endl;
    cout << "Middle 1 elements: " << middle(head_3)->data << endl;

    delete head;
    delete head_2;
    return 0;
}