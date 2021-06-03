#include <iostream>
using namespace std;
class Solution{
public:
    int climbStairs(int n){
        int ret;
        if(n == 1){
            return 1;
        }
        int* dp = new int[n+1];
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

int main(){
    int n;
    Solution mysol;
    while( cin >> n){
        int ret = mysol.climbStairs(n);
        cout << ret << endl;
    }
}