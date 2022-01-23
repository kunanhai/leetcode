#include <iostream>
#include <vector>
using namespace std;

// 二分法

int lj_bin_search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size();
    while (left < right) {
        int middle = left + ((right - left) >> 1);
        if (nums[middle] < target) {
            left =  middle + 1;
        } else if (nums[middle] > target) {
            right = middle;
        } else {
            return middle;
        }
    }
    return -1;
};

    int removeElement(vector<int>& nums, int val) {
        int slow;
        int fast;
        slow = fast =0;
        while (fast < nums.size()){
            while (nums[fast] == val) {
                if (fast == nums.size() -1) {
                    break;
                }
                fast++;
            }
            nums[slow] = nums[fast];
            fast++;
            slow++;
        }

        return slow -1;
    }

    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> res(nums.size(), 0);
        for (int i = nums.size() -1; i >= 0; i--) {
            if (nums[left] * nums[left] >= nums[right] * nums[right]) {
                res[i] = nums[left] * nums[left];
                left++;
            } else {
                res[i] = nums[right] * nums[right];
                right--;
            }
        }
        return res;
    };
// 山峰数组


int main()
{
        vector<int> nums {-4, -1, 0, 3, 10};
        vector<int>  res = sortedSquares(nums);
        cout << "hello" <<endl;
}

