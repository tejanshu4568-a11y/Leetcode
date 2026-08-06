class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to act as the head of the merged list
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        
        // Attach the remaining nodes of whichever list is not empty
        curr->next = list1 ? list1 : list2;
        
        ListNode* head = dummy->next;
        delete dummy; // Clean up memory
        return head;
    }
};