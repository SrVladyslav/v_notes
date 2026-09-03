#include "./../lib.h"
#include <iostream>

using namespace std;

int size(Node<int> *head)
{
    int count = 0;
    Node<int> *curr = head;

    while (curr != nullptr)
    {
        count++;
        curr = curr->next;
    }

    return count;
}

int main()
{
    Node<int> *head = new Node<int>(1, new Node<int>(2, new Node<int>(3, nullptr)));

    cout << "Size: " << size(head) << endl;

    delete head;
    return 0;
}