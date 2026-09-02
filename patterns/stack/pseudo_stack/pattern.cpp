/**
 * Pseudo stack pattern, the base idea is to change the stack to a counter.
 *
 * Time: O(n)
 * Memory: O(1)
 */

#include <string>

bool is_valid(std::string &str)
{
    // ============================================================================
    // Stage 1: Initialization
    // MAIN PROBLEM IS TO UNDERSTAND THAT FROM THE STACK WE NEED IT LENGTH AND
    // NOT THE ACTUAL VALUES
    // ============================================================================
    int counter = 0;

    // ============================================================================
    // Stage 2: Main loop
    // ============================================================================
    for (;;)
    {
        // =========================================================================
        // Stage 3: Counter modification logic goes here
        // =========================================================================
    }

    return counter == 0;
}