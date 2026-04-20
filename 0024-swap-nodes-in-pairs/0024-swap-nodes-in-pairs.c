/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void swap(struct ListNode* slow, struct ListNode* mid, struct ListNode* fast){
    slow -> next = fast;
    mid -> next = fast -> next;
    fast -> next = mid;
}
struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL || head -> next == NULL){
        return head;
    }
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* temp = &dummy;
    while(temp -> next != NULL && temp -> next -> next != NULL){
        swap(temp, temp -> next, temp -> next -> next);
        temp = temp -> next -> next;
    }
    return dummy.next;

}