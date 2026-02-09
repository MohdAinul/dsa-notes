class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> count;
        set<int> seen;
        
        for (int i=0; i<arr.size();i++){
        count[arr[i]]++;
        }

        for (auto it : count){
            int freq =it.second;
            if(seen.find(freq)!=seen.end()){
                return false;
            }
            seen.insert(freq);
        }
    return true;    
    }
};