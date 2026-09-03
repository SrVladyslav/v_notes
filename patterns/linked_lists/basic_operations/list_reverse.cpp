#include "./../lib.h"
#include <iostream>

using namespace std;

/**
We need 3 pointers:
- prev: to point to the previous node
- curr: to point to the current node
- tmp: to point to the next node


Time: O(n)
Memory: O(1)
 */
Node<int> *reverse_list(Node<int> *head)
{
    Node<int> *prev = nullptr;
    Node<int> *curr = head;

    while (curr != nullptr)
    {
        // Save the current pointer
        Node<int> *tmp = curr;

        // Set the new current pointer to the next one
        curr = curr->next;

        // De-reference the current pointer and set it to the new direction
        tmp->next = prev;

        // Move the prev pointer to the next position
        prev = tmp;
    }
    // Now the prev pointer is pointing to the last node which is the frst node now
    return prev;
}

int main()
{
    Node<int> *head = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5, nullptr)))));

    Node<int> *reversed_list = reverse_list(head);

    cout << "Reversed list:\n";
    while (reversed_list != nullptr)
    {
        cout << reversed_list->data << " -> ";
        reversed_list = reversed_list->next;
    }
    cout << endl;

    delete head;
}