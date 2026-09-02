/**
Remember that stacks are LIFO (Last In First Out) data structures, so the last element added will be the first one to be removed.

Time: O(n)
Memory: O(n)

It has 3 main operations:

1. push(element): adds an element to the stack
2. pop(): removes the last element from the stack
3. peek(): returns the last element from the stack
 */

#include <vector>
#include <stack>

bool is_valid(const std::vector<char> &symbols)
{

    // ============================================================================
    // Stage 1: Initialization
    // THE MAIN PROBLEM IS TO UNDERSTAND WHAT TO SAVE INSIDE THE STACK
    // ============================================================================
    std::stack<char> stack{};

    // ============================================================================
    // Stage 2: Main loop
    // ============================================================================
    for (char c : symbols)
    {
        // =========================================================================
        // Stage 3: Logic to work with the stack
        // =========================================================================
        //...
    }

    return stack.empty();
}