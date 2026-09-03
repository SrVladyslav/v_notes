/**
 * We are provided with the head of a linked list.
 * We need to intercalate the list in order of:
 * first element, last one, second element, etc...
 *
 * e.g.
 * head = 1->2->3->4->5
 * response = 1->5->2->4->3
 *
 * The approach used here will be thepartial reversal technique.
 */

#include "./../basic_operations/lib.h"
#include <iostream>

using namespace std;

template <typename T>
Node<T> *intercalate(Node<T> *head)
{
    // Stage 1: Obtain the middle point of the linked list
    Node<T> *middle_point = middle(head); // O(n)

    // Stage 2: Reverse the second part, so we can apply the two sided ptrs approac
    // If we read multiple nodos for the different next pointers, we should deleter the middle.next
    Node<T> *end_pointer = reverse_list(middle_point->next); // O(n)
    middle_point->next = nullptr;                            // O(1)

    // Stage 3: Create a new linked list with dummy node and helper pointers
    Node<T> *dummy_node = new Node<T>(0, nullptr); // for the response
    Node<T> *curr = dummy_node;                    // Just to go through the list
    Node<T> *ptr_1 = head;                         // Left pointer
    Node<T> *ptr_2 = end_pointer;                  // right pointer

    // Stage 4: Apply the pattern pointer for every one, intercalate one from each side
    // To form the response, we just need to iterate over the list and create the response
    while (ptr_1 != nullptr || ptr_2 != nullptr)
    {
        // Starting from the first elements
        if (ptr_1 != nullptr)
        {
            curr->next = ptr_1;
            ptr_1 = ptr_1->next;
            curr = curr->next;
        }

        // Add the elements from the end of the list
        if (ptr_2 != nullptr)
        {
            curr->next = ptr_2;
            ptr_2 = ptr_2->next;
            curr = curr->next;
        }
    }

    Node<T> *result = dummy_node->next;
    delete dummy_node;
    return result;
}

int main()
{
    Node<int> *head = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5, nullptr)))));
    Node<int> *response = intercalate(head);

    cout << "Linked list: 1->2->3->4->5 | Intercalated:" << endl;
    while (response != nullptr)
    {
        cout << response->data << " -> ";
        response = response->next;
    }
    cout << endl;

    delete head;
    return 0;
}