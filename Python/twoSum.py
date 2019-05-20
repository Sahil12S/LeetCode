"""
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
"""
from typing import List, Dict


def twoSum(nums, target):
    map = dict()
    idx1 = 0
    idx2 = 0

    for i in range(len(nums)):
        idx2 = i
        if (target - nums[i]) not in map:
            map[nums[i]] = i
        else:
            idx1 = map[target-nums[i]]
            break

    return [idx1, idx2]


def main():
    nums = [2, 7, 11, 15]
    target = 9

    print(twoSum(nums, target))


if __name__ == '__main__':
    main()
