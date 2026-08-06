class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        stack<ListNode*> st;
        ListNode* curr = head;
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->next;
        }
        ListNode* newHead = st.top();
        st.pop();
        ListNode* tail = newHead;
        while (!st.empty()) {
            tail->next = st.top();
            st.pop();
            tail = tail->next;
        }
        tail->next = nullptr;
        return newHead;
    }
};