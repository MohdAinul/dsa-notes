#include<iostream>
using namespace std;
#include<vector>;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandy = 0;
        for (int i : candies) {
            maxCandy = max(maxCandy, i);
        }
        vector<bool> result;
        for (int j : candies) {
            if (j + extraCandies >= maxCandy) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        return result;
    }
};