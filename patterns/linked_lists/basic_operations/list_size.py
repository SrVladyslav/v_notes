from patterns.linked_lists.lib import Node


# Time: O(n)
# Memory: O(1)
def size(head: Node) -> int:
    count: int = 0
    curr: Node = head

    while curr is not None:
        count += 1
        curr = curr.next

    return count


if __name__ == "__main__":
    linked_list: Node = Node(1, Node(2, Node(3, None)))
    print(f"Size: {size(linked_list)}")
