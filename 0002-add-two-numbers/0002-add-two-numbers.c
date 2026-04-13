/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* curr = &dummy;
    int plus = 0;
    while(l1 != NULL || l2 != NULL || plus != 0){
        struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        int temp = plus;
        if(l1 != NULL){
            temp += (l1 -> val);
            l1 = l1 -> next;
        }
        if(l2 != NULL){
            temp += (l2 -> val);
            l2 = l2 -> next;
        }
        plus = 0;
        if(temp >= 10){
            plus = 1;
            temp = temp % 10;
        }
        newnode -> val = temp;
        newnode -> next = NULL;
        curr -> next = newnode;
        curr = curr -> next;
    }
    return dummy.next;
}