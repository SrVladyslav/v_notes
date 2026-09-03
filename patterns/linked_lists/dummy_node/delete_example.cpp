/*
Given a linked list of int numbers and a value val.
You need to delete all the nodes with the value val in it and return the
head of the processed list.

e.g.
head = 1->2->5->4->5
val = 5

result = 1->2->4
*/

#include "./../lib.h"
#include <iostream>

using namespace std;

void print_list(Node<int> *head)
{
    Node<int> *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

Node<int> *delete_nodes(Node<int> *head, int val)
{
    // Used to store the new result of the list and as pointer to return
    // Since is only one list, we cam use the head there
    Node<int> *dummy_node = new Node<int>(0, head);
    // Stores the actual pointer over the list while traversing it
    Node<int> *curr = dummy_node;

    // Stage 2: Lets clean the list from the val values
    while (curr->next != nullptr)
    {
        if (curr->next->data == val)
        {
            Node<int> *node_to_delete = curr->next;
            curr->next = curr->next->next;

            // We delete the node, but we need to keep the pointer on the next value
            node_to_delete->next = nullptr;
            delete node_to_delete;
        }
        else
        {
            curr = curr->next;
        }
    }

    Node<int> *result = dummy_node->next;
    delete dummy_node;
    return result;
}

int main()
{
    Node<int> *head = new Node<int>(1, new Node<int>(2, new Node<int>(5, new Node<int>(4, new Node<int>(5, nullptr)))));
    int val = 5;

    printf("List to preprocess:\n");
    print_list(head);

    Node<int> *result = delete_nodes(head, val);

    printf("\nPreprocessd result:\n");
    print_list(result);

    return 0;
}