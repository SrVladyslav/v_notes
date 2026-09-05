""" 
Given a root for a binary tree, check if it is a balanced tree, 
meaning that the difference between the left and right subtree of any node is at most 1.

e.g. 

root = [3,9,20,null, null, 15, 7]

    3
   / \\
  9  20
    /  \\
   15   7

response = True   
"""

from patterns.tree.lib import TreeNode
from collections import deque


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


def is_balanced_tree(arr: list[int | None]) -> bool:
    tree: TreeNode | None = build_tree(arr)
    if tree is None:
        return False

    last_deep: int = 0

    def dfs(node: TreeNode) -> int:
        if node is None:
            return 0

        left = dfs(node.left)
        right = dfs(node.right)

        # Now we should check which is the difference and return the difference I think
        nonlocal last_deep
        last_deep = max(last_deep, abs(right - left))

        return max(left, right) + 1

    dfs(tree)
    return last_deep <= 1


if __name__ == "__main__":
    tree: list[int] = [3, 9, 20, None, None, 15, 7]
    print(f"Is balanced tree {tree}: {is_balanced_tree(tree)}")

    tree = [1, 2, 3, 4, None, None, None, 5]
    print(f"Is balanced tree {tree}: {is_balanced_tree(tree)}")
