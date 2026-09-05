""" 
Up to bottom recursion tree pattern 

Time: O(n)
Memory: O(h)
"""
from patterns.tree.lib import TreeNode

def sum_exists(root: TreeNode, target_sum: int = 0)-> bool: 
    def dfs(node: TreeNode, ...) -> bool:
        # =============================================================================
        # Stage 1: Base case, what to do for void leaf?
        # =============================================================================
        if node is None: 
            ... 

        # =============================================================================
        # Stage 2: Recursive call to the leaves
        # =============================================================================
        ... 

        # =============================================================================
        # Stage 3: Updating the result, knowing the response from the subtrees
        # BASE PROBLEM IS TO UNDERSTAND HOW TO FORM THE RESULT
        # =============================================================================
        return ...

    # BASE PROBLEM IS TO UNDERSTAND WHAT TO PASS TO THE CHILDREN AND HOW THE RECURSION SHOULD WORK
    return dfs(root, 0)
