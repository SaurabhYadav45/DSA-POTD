/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     void deleteNode(ListNode* node) {
//         ListNode*target = head;
//         ListNode*prev = NULL;
//         while(target.val != node){
//             prev = target;
//             target->next = target->next;
//         }
//         prev->next = target->next;
//     }
// };


class Solution 
{
public:
    void deleteNode(ListNode* node) 
    {
         node->val=(node->next)->val;
         node->next=(node->next)->next;
    }
};