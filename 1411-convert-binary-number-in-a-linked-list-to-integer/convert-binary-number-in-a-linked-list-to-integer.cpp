/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector<int> bits;
        while (head) {
            bits.push_back(head->val);
            head = head->next;
        }

        int result = 0;
        int n = bits.size();
        for (int i = 0; i < n; ++i) {
            result += bits[i] * pow(2, n - i - 1);  // No bitwise ops
        }

        return result;
    }
};