from typing import TypeVar
from collections import deque

T = TypeVar("T")


class TreeNode:
    def __init__(self, value: T, left: "TreeNode" = None, right: "TreeNode" = None):
        self.value = value

        self.left = left
        self.right = right


def build_tree(arr: list[int | None]) -> TreeNode | None:
    if not arr or arr[0] is None:
        return None

    root = TreeNode(arr[0])
    queue = deque([root])
    i = 1
    while queue and i < len(arr):
        node = queue.popleft()

        # Left child
        if i < len(arr) and arr[i] is not None:
            node.left = TreeNode(arr[i])
            queue.append(node.left)

        i += 1

        # Right child
        if i < len(arr) and arr[i] is not None:
            node.right = TreeNode(arr[i])
            queue.append(node.right)

        i += 1

    return root
