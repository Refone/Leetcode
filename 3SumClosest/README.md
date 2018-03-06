# [3Sum Closest](https://leetcode.com/problems/3sum-closest/)

## Description

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

## Example

```
For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```

## Solution

* Sort - 3 Pointer

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if (size == 3) {
            return nums[0] + nums[1] + nums[2];
        }

        int i=0;
        int j=1;
        int k=2;
        int sum;
        int ret = 999999;

        for (;k<size;k++) {
            for (j=1;j<k;j++) {
                for (i=0;i<j;i++) {
                    sum = nums[i] + nums[j] + nums[k];
                    if (abs(sum-target) < abs(ret-target)) {
                        ret = sum;
                    }
                    if (sum >= target) {
                        break;
                    }
                }
                if ((i==0) && (sum>=target)) {
                    break;
                }
            }
            if ((i==0) && (j==1) && (sum>=target)) {
                break;
            }
        }

        return ret;
    }
};
```

![](./168ms.png)

* Recurse

```cpp
class Solution {
private:
    vector<int> arr;
    int recurse(vector<int>& nums, int size, int have_to_choose, int cursum, int target) {
        if (size < have_to_choose) {
            return 999999;
        }
        if (have_to_choose == 0) {
            return cursum;
        }
        if (size == have_to_choose) {
            int sum = 0;
            for (int i=0; i<size; i++) {
                sum += nums[i];
            }
            return sum+cursum;
        }

        int last_num = nums[size-1];
        int res_abort_last = recurse(nums, size-1, have_to_choose, cursum, target);
        int res_accept_last = recurse(nums, size-1, have_to_choose-1, cursum+last_num, target);
        if (abs(res_accept_last - target) < abs(res_abort_last - target)) {
            return res_accept_last;
        } else {
            return res_abort_last;
        }
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
        return recurse(nums, nums.size(), 3, 0, target);
    }
};
```
![](./1240ms.png)

## Best Solution

```cpp

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int min_abs = numeric_limits<int>::max();
        int closest_sum = 0;
        for (int p1 = 0; p1 < n; ++p1) {
            int p2 = p1+1;
            int p3 = n-1;
            while (p2 < p3) {
                int sum = nums[p1] + nums[p2] + nums[p3];
                //cout << sum << endl;
                int dist = abs(sum - target);
                if (dist < min_abs) {
                    min_abs = dist;
                    closest_sum = sum;
                }
                if (sum < target) ++p2;
                else if (sum > target) --p3;
                else return target;
            }
        }
        return closest_sum;
    }
};
```
