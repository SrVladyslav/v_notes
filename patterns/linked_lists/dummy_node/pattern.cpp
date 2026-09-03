/**
 * Pattern for dummy nodes
 *
 * Time: O(n+m)
 * Memory: O(1)
 */

#include "./../lib.h"

using namespace std;

template <typename T>
Node<T> *merge_lists(Node<T> *head_1, Node<T> *head_2)
{
    // ============================================================================
    // Stage 1: Initialization and dummy node creation
    // ============================================================================
    Node<T> *dummy_node = new Node<T>(0, nullptr);

    // ============================================================================
    // Stage 2: Creating the response, forming the result here
    // Normally here we should use the two pointers or floating window approach
    // ============================================================================
    Node<T> *curr = dummy_node;
    while (head_1 != nullptr && head_2 != nullptr)
    {
        // ...
    }

    // ============================================================================
    // Stage 3: Return the dummy.next, in order to delete the dummy node
    // DO NOT FORGET TO DELETE THE DUMMY NODE KEK!
    // ============================================================================
    Node *result = dummy_node->next;
    delete dummy_node;
    return result;
}