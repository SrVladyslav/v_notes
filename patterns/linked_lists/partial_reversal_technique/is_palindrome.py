"""
We have a linked list of int numbers, and we need to check if this linked list
is a palindrome.

e.g.
list = 1->2->3->2->1
output = True

list = 1->2->3->4->5
output = False
"""

from patterns.linked_lists.lib import Node
from patterns.linked_lists.basic_operations.list_reverse import reverse
from patterns.linked_lists.basic_operations.list_middle import middle


# THE MAIN PROBLEM HERE IS TO CORRECTLY CHOOSE THE HELPER PATTERN FUNCTIONS (MIDDLE, REVERSE...)
def is_palindrome(head: Node) -> bool:
    # Stage 1
    first_half_end: Node = middle(head)
    second_half_begin = reverse(first_half_end)
    ptr_1, ptr_2 = head, second_half_begin

    while ptr_2:
        if ptr_1.data != ptr_2.data:
            return False

        ptr_1 = ptr_1.next
        ptr_2 = ptr_2.next

    return True


if __name__ == "__main__":
    linked_list: Node = Node(1, Node(2, Node(3, Node(2, Node(1, None)))))
    bad_linked_list: Node = Node(1, Node(2, Node(3, Node(4, Node(5, None)))))

    print(f"LInked list 1->2->3->2->1: {is_palindrome(linked_list)}")
    print(f"LInked list 1->2->3->4->5: {is_palindrome(bad_linked_list)}")
