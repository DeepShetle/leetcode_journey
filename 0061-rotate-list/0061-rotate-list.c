/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(k == 0) return head;
    if(head == NULL) return head;
    int count = 0;
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* test = &dummy;
    struct ListNode* ptr1 = &dummy;
    while(test -> next != NULL){
        test = test -> next;
        count++;                  
    }
    if(count == 1) return head;
    k = k % count;
    if(k == 0) return head;
    k = count - k;
    if(test -> next == NULL){
        test -> next = head;
    }
    for(int i = 0; i < k; i++){
        ptr1 = ptr1 -> next;
    }
    head = ptr1 -> next;
    ptr1 -> next = NULL;
    return head;
}



