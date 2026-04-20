/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* temp1 = &dummy;
    struct ListNode* temp2 = &dummy;
    for(int i = 0; i <= n; i++){
        temp1 = temp1 -> next;
    }
    while(temp1 != NULL){
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    struct ListNode* nodedelete = temp2 -> next;
    temp2 -> next = temp2 -> next -> next;
    free(nodedelete);
    return dummy.next;
}