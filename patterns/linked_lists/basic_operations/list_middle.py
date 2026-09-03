from patterns.linked_lists.lib import Node


def middle(head: Node) -> Node:
    """
    The approach here is to use two pointer, the slow and the fast one, so we can do it in one n pass.
    The slow will increase in one while the fast in two.

    Time: O(n)
    Memory: O(1)
    """
    fast_ptr: Node = head
    slow_ptr: Node = head

    while head is not None:
        if fast_ptr and fast_ptr.next:
            fast_ptr = fast_ptr.next.next
            slow_ptr = slow_ptr.next
        else:
            break

    return slow_ptr


if __name__ == "__main__":
    linked_list: Node = Node(1, Node(2, Node(3, Node(4, Node(5, None)))))
    linked_list_2: Node = Node(1, Node(2, Node(3, Node(4, None))))
    linked_list_3: Node = Node(1, None)

    print(f"Middle 5 elements: {middle(linked_list).data}")
    print(f"Middle 4 elements: {middle(linked_list_2).data}")
    print(f"Middle 1 elements: {middle(linked_list_3).data}")
