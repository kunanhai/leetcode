#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
        int maxArea(vector<int>& height){
            int head = 0;
            int tail = height.size() - 1;
            int tempArea;
            int maxArea = 0;
            while (head <= tail)
            {
                tempArea = height[head] > height[tail] ? \
                           (tail - head) * height[tail]: \
                           (tail - head) * height[head];
                maxArea = maxArea > tempArea ? maxArea : tempArea;

                if(height[head] < height[tail]){
                    head++;
                }else{
                    tail--;
                }
            }
            return maxArea;
        }
};

int main(){
    vector<int> test{1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution mysol;
    int maxArea = mysol.maxArea(test);
    cout << maxArea << endl;
}