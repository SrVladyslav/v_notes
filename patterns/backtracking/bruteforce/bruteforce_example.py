"""
* Given a list of a unique numbers nums. We should find all the possible combinations between them,
* including the basic list and the nums. The order inside the combinations doesn't matter.
* Same combinations should not repeat.
*
* e.g.
* nums = [3,6,17]
*
* output = [[], [3], [6], [3,6], [17], [3,17], [6,17], [3,6,17]]
*
* Time: O(n*2^n)
* Memory: O(n*2^n)
"""


def get_all_not_repeated_combinations(nums: list[int]) -> list[list[int]]:
    if len(nums) <= 0:
        return []

    result: list[list[int]] = [[]]
    # We need this list in order to have the running state of the combination and know when to end the loop
    running_state: list[tuple[list[int], int]] = [([], 0)]

    while running_state and len(running_state[0][0]) < len(nums):
        # Now we should obtain the prefix from the front and drop it
        prefix: list[int] = running_state.pop(0)

        # Once we have the next prefix, we should iterate over the nums in the
        # original list and add the new combinations to the running state so we can combine all
        for i in range(prefix[1], len(nums)):
            # Creating the new prefix combination
            new_prefix: list[int] = prefix[0] + [nums[i]]

            # Now we should add the combinations to the result
            result.append(new_prefix)

            # And finally add the new combination as a State to the state list
            running_state.append((new_prefix, i + 1))

    return result


if __name__ == "__main__":
    print("Combinations for: 3 6 17:")
    nums: list[int] = [3, 6, 17]
    res: list[list[int]] = get_all_not_repeated_combinations(nums)

    print(res)
