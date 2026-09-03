#include "./../lib.h"

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
