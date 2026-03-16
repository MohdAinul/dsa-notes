#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// Brute Force O(n²)
bool containsDuplicate(const vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
}

// Sorting Approach O(n log n)
bool containsDuplicatee(vector<int> nums) {
    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
            return true;
        }
    }
    return false;
}

// HashSet Approach O(n)
bool containDuplicateee(const vector<int>& arr) {
    unordered_set<int> s;

    for (int num : arr) {
        if (s.count(num)) return true;
        s.insert(num);
    }

    return false;
}

int main() {
    vector<int> nums{1, 2, 3, 1};

    cout << containsDuplicate(nums) << endl;
    cout << containsDuplicatee(nums) << endl;
    cout << containDuplicateee(nums) << endl;

    return 0;
}