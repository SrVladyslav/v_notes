#include "./../basic_operations/lib.h"

using namespace std;

/*
THE MAIN PROBLEM HERE IS TO CORRECTLY CHOOSE THE HELPER PATTERN FUNCTIONS (MIDDLE, REVERSE...)

Time: O(n)
Memory: O(1)
*/
template <typename T>
bool is_palindrome(Node<T> *head)
{
    // ============================================================================
    // Stage 1: Partial reversal technique logic goes here:
    // - Find the middle point
    // - Reverse the list from the middle point to the end
    // - Compare the first and last nodes
    // ============================================================================

    /*
        Since we cannot use two pointers from sides like in two pointers pattern,
        we need to use some modifications to the linked list:
        1) We find the middle point of the list
        2) We do reverse the list from the middle point to the end, so now we can go from outside to towards the middle.
        3) Take into account that when the list is reversed, the middle point is pointing to nullptr

        1 -> 2 -> 3 <- 2 <- 1
                  |
                  v
                nullptr

        4) With two ptrs from the sides, we go towards the middle and check if the
        values are the same. If not, we return false and finish. Yep, the same pattern
        from day 1 is applied here too :)
    */

    // ============================================================================
    // Stage 2: Form and return the response
    // ============================================================================
}