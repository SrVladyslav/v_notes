""" 
Given the tree root, you should find its diameter: 
the diameter is the length of the longest path between any two nodes in a tree. 

e.g. 

            1
        / 
        2
    /      \\
    3      4
    \\       \\ 
    5        6

5->3->2->4->6 = 4
solution= 4
"""

from patterns.tree.lib import TreeNode


def find_tree_diameter(node: TreeNode) -> int:
    diameter: int = 0

    # Lets do a recursion

    def dfs(node: TreeNode) -> int:
        # Base case ALWAYS
        if node is None:
            return 0

        # Base case, we add how many nodes we have in the branches
        left = dfs(node.left)
        right = dfs(node.right)

        # Obtain the max diameter, this is the key response here
        nonlocal diameter
        diameter = max(diameter, left + right)

        # Now we should select the maximum nodes in the subtree
        return max(left, right) + 1

    dfs(node)
    return diameter


if __name__ == "__main__":
    root: TreeNode = TreeNode(
        1,
        TreeNode(
            2,
            TreeNode(3, TreeNode(5, None, None), None),
            TreeNode(4, None, TreeNode(6, None, None)),
        ),
        None,
    )

    print("Diameter:", find_tree_diameter(root))
