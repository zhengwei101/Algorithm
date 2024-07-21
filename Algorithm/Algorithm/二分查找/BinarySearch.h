#include <vector>

/**
 * @brief  binary search
 * 
 * @param nums : The integer array.
 * @param target :Target to find.
 * @return The first position of target.Position starts form 0.
 */
int binarySearch(std::vector<int> nums, int target) {
    if (nums.empty()) {
        return -1;
    }

    int start = 0;
    int end = nums.size() - 1;
    while (start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            end = mid;
        }
        else if (nums[mid] < target) {
            start = mid;
        }
        else {
            end = mid;
        }
        if (nums[start] == target) {
            return start;
        }
        if (nums[end] == target) {
            return end;
        }
        return -1;
    }
}