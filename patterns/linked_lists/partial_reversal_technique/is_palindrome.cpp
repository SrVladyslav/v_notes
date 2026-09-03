/**
We have a linked list of int numbers, and we need to check if this linked list
is a palindrome.

e.g.
list = 1->2->3->2->1
output = True

list = 1->2->3->4->5
output = False
 */

#include <iostream>
#include "./../basic_operations/lib.h"

using namespace std;

bool is_palindrome(Node<int> *head)
{
    // Obtain the middle point of the linked list
    Node<int> *middle_point = middle(head);

    // Now we reverse the linked liost from the middle towards the end
    Node<int> *end_point = reverse_list(middle_point);

    /*Now we have something like that, so we can apply the multi ptr approach
    1 -> 2 -> 3 <- 2 <- 1
              |
              v
            nullptr
    */
    Node<int> *ptr_1 = head, *ptr_2 = end_point;
    while (ptr_2 != nullptr)
    {
        if (ptr_1->data != ptr_2->data)
            return false;

        ptr_1 = ptr_1->next;
        ptr_2 = ptr_2->next;
    }

    return true;
}

int main()
{
    Node<int> *linked_list = new Node<int>(1, new Node<int>(2, new Node<int>(2, new Node<int>(1, nullptr))));
    Node<int> *linked_list_2 = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(2, new Node<int>(1, nullptr)))));
    Node<int> *bad_linked_list = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5, nullptr)))));

    cout << "Linked list 1->2->2->1: " << (is_palindrome(linked_list) ? "True" : "False") << endl;
    cout << "Linked list 1->2->3->2->1: " << (is_palindrome(linked_list_2) ? "True" : "False") << endl;
    cout << "Linked list 1->2->3->4->5: " << (is_palindrome(bad_linked_list) ? "True" : "False") << endl;

    delete linked_list;
    delete linked_list_2;
    delete bad_linked_list;

    return 0;
}