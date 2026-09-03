from patterns.linked_lists.lib import Node

""" 
We need 3 pointers: 
- prev: to point to the previous node
- curr: to point to the current node
- tmp: to point to the next node


Time: O(n)
Memory: O(1)
"""


def reverse(head: Node) -> Node:
    prev: Node = None
    curr: Node = head

    while curr is not None:
        # Save the curr
        tmp: Node = curr

        # Move the curr to the next
        curr = curr.next

        # Break the pointer in order to point to reversed list
        tmp.next = prev

        # Point to the other side
        prev = tmp

    return prev


if __name__ == "__main__":
    linked_list: Node = Node(1, Node(2, Node(3, Node(4, Node(5, None)))))

    reversed_list: Node = reverse(linked_list)

    curr = reversed_list
    print(f"Reversed list:")
    l_str: str = ""
    while curr is not None:
        l_str += f"{curr.data} -> "
        curr = curr.next
    print(l_str)
