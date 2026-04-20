#include <iostream>
using namespace std;

// Definition
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Print function
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // dummy node to handle edge case (remove head)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // move fast n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // move both pointers
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        // delete node
        ListNode* del = slow->next;
        slow->next = del->next;
        delete del;

        return dummy->next;
    }
};

int main() {
    // Create list: 1 → 2 → 3 → 4 → 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original: ";
    printList(head);

    Solution obj;
    head = obj.removeNthFromEnd(head, 2);

    cout << "After Removal: ";
    printList(head);

    return 0;
}