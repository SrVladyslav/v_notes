/**
Given two linked lists, we need to merge them in a single ordered list and return the head.

e.g.
list1 = 1->2->3
list2 = 2->2->7->8

output = 1->2->2->2->3->7->8

The idea here is to create a dummy node, and them apply the pattern pointer for every one.
 */

#include "./../lib.h"
#include <iostream>

using namespace std;

template <typename T>
Node<T> *merge_lists(Node<T> *head_1, Node<T> *head_2)
{
    // Stage 1: Initialization or the dummy node
    Node<T> *dummy_node = new Node<T>(0, nullptr); // Used in the pattern to store the result
    Node<T> *current_node = dummy_node;            // Goes through the list

    // Stage 2: Creating the response, forming the result here.
    // With the dummy node we can use the pointers for everyone or floating window approach
    while (head_1 != nullptr || head_2 != nullptr)
    {

        if (head_2 == nullptr || (head_1 != nullptr && head_1->data <= head_2->data))
        {
            current_node->next = head_1;
            head_1 = head_1->next;
        }
        else
        {
            current_node->next = head_2;
            head_2 = head_2->next;
        }
        current_node = current_node->next;
    }

    // Stage 3: Return the response. Do not forget to return the next in order to delete th edummy node
    Node<T> *result = dummy_node->next;
    delete dummy_node;
    return result;
}

int main()
{
    Node<int> *list_1 = new Node<int>(1, new Node<int>(2, new Node<int>(3, nullptr)));
    Node<int> *list_2 = new Node<int>(2, new Node<int>(2, new Node<int>(7, new Node<int>(8, nullptr))));

    Node<int> *merged_list = merge_lists(list_1, list_2);

    cout << "Merged list:\n";
    while (merged_list != nullptr)
    {
        cout << merged_list->data << " -> ";
        merged_list = merged_list->next;
    }
    cout << endl;

    // Yeap, all <new> need its happy executioner :)!
    delete list_1;
    delete list_2;
    delete merged_list;
    return 0;
}