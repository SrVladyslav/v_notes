from patterns.tree.lib import TreeNode

"""
Pattern bottom up

Time: O(n)
Memory: O(n)
"""


def find_diameter(node: TreeNode) -> int:
    def dfs(node: TreeNode) -> int:
        # =============================================================================
        # Stage 1: Base case, what to do for void leaf?
        # =============================================================================
        if node is None:
            return ...

        # =============================================================================
        # Stage 2: Recursive call to the leaves
        # =============================================================================
        ...

        # =============================================================================
        # Stage 3: Updating the result, knowing the response from the subtrees
        # BASE PROBLEM IS TO UNDERSTAND HOW TO FORM THE RESULT
        # =============================================================================
        ...

        # =============================================================================
        # Stage 4: Return the result to the parent
        # AND WHAT WE SHOULD RETURN TO THE PARENT
        # ===========================================================================
        return ...

    return dfs(node)
