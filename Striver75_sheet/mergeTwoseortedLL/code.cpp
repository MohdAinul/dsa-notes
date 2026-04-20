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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // dummy node to start result list
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        // compare both lists
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                temp->next = list1;   // attach list1 node
                list1 = list1->next;  // move list1
            } else {
                temp->next = list2;   // attach list2 node
                list2 = list2->next;  // move list2
            }
            temp = temp->next;  // move temp
        }

        // attach remaining nodes
        if (list1) temp->next = list1;
        if (list2) temp->next = list2;

        return dummy->next;  // return merged list head
    }
};

int main() {
    // List1: 1 → 2 → 4
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    // List2: 1 → 3 → 4
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    cout << "List1: ";
    printList(l1);

    cout << "List2: ";
    printList(l2);

    Solution obj;
    ListNode* result = obj.mergeTwoLists(l1, l2);

    cout << "Merged List: ";
    printList(result);

    return 0;
}