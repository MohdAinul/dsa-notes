#include <iostream>
using namespace std;
#include <vector>

// Brute Force try all possible pair

int maxArea(vector<int>& height) {
    int maxi = 0;
    for (int i = 0; i < height.size(); i++) {
        for (int j = i + 1; j < height.size(); j++) {
            int h = min(height[i], height[j]);
            int w = j - i;
            maxi = max(maxi, h * w);
        }
    }
    return maxi;
}

// optimal solution
int optimal(vector<int>& height) {
    int l = 0;
    int r = height.size() - 1;
    int maxi = 0;
    while (l < r) {
        int w = r - l;
        int h = min(height[l], height[r]);
        maxi = max(maxi, w * h);

        if (height[l] < height[r]) {
            l++;
        } else {
            r--;
        }
    }
    return maxi;
}
int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Maximum Water is : " << maxArea(height) << endl;
    cout << "Maximum Water is : " << optimal(height) << endl;
    return 0;
}