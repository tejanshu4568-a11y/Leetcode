class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        Node* curr = root;

        while (curr->left) {
            Node* head = curr;

            while (head) {
                head->left->next = head->right;

                if (head->next) {
                    head->right->next = head->next->left;
                }

                head = head->next;
            }

            curr = curr->left;
        }

        return root;
    }
};