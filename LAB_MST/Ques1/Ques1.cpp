#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        
        while (low <= high) {
            
            int mid = low + (high - low) / 2;
            long long operations = 0;
            
            for (int balls : nums) {
                operations += (balls - 1) / mid;
            }
            
            if (operations <= maxOperations) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};

int main() {
    Solution sol;

    int n, maxOperations;
    cout << "Enter number of bags: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter number of balls in each bag:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter max operations: ";
    cin >> maxOperations;

    int result = sol.minimumSize(nums, maxOperations);

    cout << "Minimum possible maximum balls in a bag: " << result << endl;

    return 0;
}
