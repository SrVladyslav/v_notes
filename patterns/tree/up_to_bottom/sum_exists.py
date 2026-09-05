"""
Given the root of a binary tree, and a value target_sum.
Your task is to find if there is a path from the root to a leaf
such that the sum of all the values along the path equals the target_sum.

e.g.

binary_tree = [5,3,1,2,4,null,null]
target_sum = 12

response = True
"""

from patterns.tree.lib import TreeNode, build_tree


def sum_exists(node: TreeNode, target_sum: int) -> bool:
    # In this approach we will be going from up to bottom

    def dfs(node: TreeNode, local_sum: int) -> bool:
        # Base case
        if node is None:
            return False

        # Recursive call to the leaves
        local_sum += node.value

        # Check for the target sum
        if node.left is None and node.right is None:
            return local_sum == target_sum

        # If is not the target, then continue the iteration
        return dfs(node.left, local_sum) or dfs(node.right, local_sum)

    return dfs(node, 0)


if __name__ == "__main__":
    tree_list: list[int | None] = [5, 3, 1, 2, 4, None, None]
    tree: TreeNode = build_tree(tree_list)

    print(
        f"Is there a path with sum {12} in the tree {tree_list}? {sum_exists(tree, 12)}"
    )
    print(
        f"Is there a path with sum {13} in the tree {tree_list}? {sum_exists(tree, 13)}"
    )
