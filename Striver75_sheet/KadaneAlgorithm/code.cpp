#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // Function to find maximum sum of subarrays
    int maxSubArray(vector<int>& nums) {
        /* Initialize maximum sum with
        the smallest possible integer*/
        int maxi = INT_MIN;

        // Iterate over each starting index of subarrays
        for (int i = 0; i < nums.size(); i++) {
            /* Variable to store the sum
            of the current subarray*/
            int sum = 0;

            /* Iterate over each ending index
            of subarrays starting from i*/
            for (int j = i; j < nums.size(); j++) {
                /* Add the current element nums[j] to
                the sum i.e. sum of nums[i...j-1]*/
                sum += nums[j];

                /* Update maxi with the maximum of its current
                value and the sum of the current subarray*/
                maxi = max(maxi, sum);
            }
        }

        // Return the maximum subarray sum found
        return maxi;
    }

    // Function to find maximum sum of subarrays
    int maxSubArrayy(vector<int>& nums) {
        // maximum sum
        long long maxi = LLONG_MIN;

        // current sum of subarray
        long long sum = 0;

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            // Add current element to the sum
            sum += nums[i];

            // Update maxi if current sum is greater
            if (sum > maxi) {
                maxi = sum;
            }

            // Reset sum to 0 if it becomes negative
            if (sum < 0) {
                sum = 0;
            }
        }

        // Return the maximum subarray sum found
        return maxi;
    }
};

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Create an instance of Solution class
    Solution sol;

    int maxSum = sol.maxSubArray(arr);
    int maxSubArray = sol.maxSubArrayy(arr);

    // Print the max subarray sum
    cout << "The maximum subarray sum is: " << maxSum << endl;
    cout << "The maximum subarray sum is: " << maxSubArray << endl;

    return 0;
}