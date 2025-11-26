#include<iostream> 
using namespace std;

void reverseArray(vector<int>& a) {
    int i=0, j=a.size()-1;
    while(i<j) swap(a[i++], a[j--]);
}

int main() {
    vector<int> a = {1,2,3,4,5};
    reverseArray(a);
    for(int x: a) cout<<x<<" ";
    cout<<"\n";
    return 0;
};

