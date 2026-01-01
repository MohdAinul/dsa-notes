#include<iostream>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string mergedString="";
        for (int i =0 ; i<word1.length() || i<word2.length();i++){
           if(i<word1.length()){
            mergedString += word1[i];
           }

           if(i<word2.length()){
            mergedString += word2[i];
           }


            
        }
        return mergedString;
        
    }
};