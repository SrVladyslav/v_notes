from patterns.linked_lists.lib import Node

""" 
Given two linked lists, we need to merge them in a single ordered list and return the head.

e.g. 
list1 = 1->2->3
list2 = 2->2->7->8

output = 1->2->2->2->3->7->8

The idea here is to create a dummy node, and them apply the pattern pointer for every one.
"""


def merge_lists(ptr_1: Node, ptr_2: Node) -> Node:
    # Stage 1: Initialization
    dummy_node: Node = Node(0, None)  # Will be used as a result
    curr: Node = dummy_node  # Goes through the list

    # Stage 2: Loop over the lists and merge them using the well know pattern pointer for everyone
    while ptr_1 is not None or ptr_2 is not None:
        if ptr_2 is None or (ptr_1 is not None and ptr_1.data <= ptr_2.data):
            curr.next = ptr_1
            ptr_1 = ptr_1.next
        else:
            curr.next = ptr_2
            ptr_2 = ptr_2.next
        curr = curr.next

    # Stage 3: Delete the dummy node by returnin the next pointer of himself
    return dummy_node.next


if __name__ == "__main__":
    list_1: Node = Node(1, Node(2, Node(3, None)))
    list_2: Node = Node(2, Node(2, Node(7, Node(8, None))))

    merged_list: Node = merge_lists(list_1, list_2)
    print(f"Merged list:")
    s_str: str = ""
    while merged_list is not None:
        s_str += f"{merged_list.data} -> "
        merged_list = merged_list.next
    print(s_str)

    list_3: Node = Node(2, Node(2, Node(7, Node(9, None))))
    list_4: Node = Node(1, Node(2, Node(7, Node(8, Node(9, None)))))
    merged_list_2: Node = merge_lists(list_3, list_4)
    print(f"\nMerged list 2:")
    s_str = ""
    while merged_list_2 is not None:
        s_str += f"{merged_list_2.data} -> "
        merged_list_2 = merged_list_2.next
    print(s_str)
