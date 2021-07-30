#include "leetcode.h"


using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ret;
    queue<int> q;
    int max = INT_MIN;
    for(int i = 0; i < k; i++) {
        max = max > nums[i] ? max : nums[i];
        q.push(nums[i]);
    }

    ret.push_back(max);
    for (int i = k; i < nums.size(); i++) {
        if (!q.empty()) {
            int t = q.front();
            max = max > t ? max : t;
            q.pop();
            max = max > nums[i] ? max : nums[i];
            q.push(nums[i]);
        }
        ret.push_back(max);
    }

    return ret;
}