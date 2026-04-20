#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;        // move 1 step
            fast = fast->next->next;  // move 2 steps

            if (slow == fast) {  // IMPORTANT: check inside loop
                return true;     // cycle found
            }
        }

        return false;  // no cycle
    }
};

int main() {
    // Create nodes
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);

    // Connect nodes: 1 → 2 → 3 → 4
    head->next = second;
    second->next = third;
    third->next = fourth;

    //  Create cycle manually
    // 4 → 2 (cycle starts at node 2)
    fourth->next = second;

    Solution obj;

    if (obj.hasCycle(head)) {
        cout << "Cycle detected " << endl;
    } else {
        cout << "No cycle " << endl;
    }

    return 0;
}