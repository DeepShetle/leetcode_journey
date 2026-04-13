/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* curr = &dummy;
    while(list1 != NULL && list2 != NULL){
        if(list1 -> val >= list2 -> val){
            curr -> next = list2;
            list2 = list2 -> next;
        }
        else if(list1 -> val < list2 -> val){
            curr -> next = list1;
            list1 = list1 -> next;
        }
        curr = curr -> next;
    }
    if(list1 != NULL){
        curr -> next = list1;
    }
    if(list2 != NULL){
        curr -> next = list2;
    }
    return dummy.next;
}