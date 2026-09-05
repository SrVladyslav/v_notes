""" 
Given a root for a binary tree. Yout should return all the values 
by levels, starting from the root and going to the leaves.

e.g. 

root = [3,9,20,null, null, 15, 7]

    3
   / \\
  9  20
    /  \\
   15   7

response0 [[3], [9,20], [15,7]]
"""

from patterns.tree.lib import TreeNode, build_tree


def values_by_level(node: TreeNode) -> list[list[int]]:
    result: dict[int, list[int]] = {}

    def dfs(node: TreeNode, level: int) -> bool:
        if node is None:
            return False

        # Add the value to the list
        nonlocal result
        if node.value is not None:
            result[level] = result.get(level, []) + [node.value]

        # Recursive call to the leaves
        dfs(node.left, level + 1)
        dfs(node.right, level + 1)

    dfs(node, 0)
    return list(result.values())


if __name__ == "__main__":
    tree_list: list[int | None] = [3, 9, 20, None, None, 15, 7]
    tree: TreeNode = build_tree(tree_list)

    print(f"Tree {tree_list} has values: {values_by_level(tree)}")
