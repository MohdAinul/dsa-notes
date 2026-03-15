#include <iostream>
using namespace std;

class Solution {
   public:
    string optimal(vector<int>& arr, int target) {
        vector<pair<int, int>> v;
        for (int i = 0; i < arr.size() - 1; i++) {
            v.push_back({arr[i], i});
        }
        sort(v.begin(), v.end());
        int left = 0, right = v.size() - 1;
        while (left < right) {
            int sum = v[left].first + v[right].first;
            if (sum == target) {
                return "yes";
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return "no";
    }

    // variant 2
    vector<int> optimalSol(vector<int>& arr, int target) {
        vector<pair<int, int>> v;
        for (int i = 0; i < arr.size() - 1; i++) {
            v.push_back({arr[i], i});
        }
        sort(v.begin(), v.end());
        int left = 0, right = v.size() - 1;
        while (left < right) {
            int sum = v[left].first + v[right].first;
            if (sum == target) {
                return {v[left].second, v[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {-1, -1};
    }
};
int main() {
    Solution sol;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    cout << sol.optimal(arr, target) << endl;
    vector<int> result = sol.optimalSol(arr, target);
    cout << result[0] << "," << result[1] << endl;
    return 0;
}