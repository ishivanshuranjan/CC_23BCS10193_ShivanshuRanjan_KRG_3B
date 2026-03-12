#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        
        vector<long long> cnt(31, 0);
        
        for (int x : nums) {
            for (int b = 0; b < 31; b++) {
                if (x & (1 << b)) cnt[b]++;
            }
        }

        long long ans = 0;

        for (int i = 0; i < k; i++) {
            long long cur = 0;

            for (int b = 0; b < 31; b++) {
                if (cnt[b] > 0) {
                    cur |= (1LL << b);
                    cnt[b]--;
                }
            }

            ans = (ans + (cur * cur) % MOD) % MOD;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    int result = sol.maxSum(nums, k);

    cout << "Maximum sum: " << result << endl;

    return 0;
}
