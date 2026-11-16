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
// Idea is simple
class Solution {
public:
    ListNode* Revers_LL(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nextNode = NULL;

        while (curr != NULL) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    ListNode* getkthNode(ListNode* head, int k) {
        //why k>1 as we need kth node there exist already one node which is non countable
        
        while (k>1 && head != NULL) {
            head = head->next;
            k--;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev_last = NULL;

        while (temp != NULL) {
            ListNode* kthNode = getkthNode(temp, k);
            if (kthNode == NULL) {
                if(prev_last) prev_last->next=temp;
                break;
            }
            ListNode* group_next = kthNode->next;
            kthNode->next = NULL;
            Revers_LL(temp);
            if (temp == head) {
                head = kthNode;
            } else {
               prev_last->next=kthNode;
            }
                prev_last = temp;
                temp = group_next;
        }
        return head;
    }
};