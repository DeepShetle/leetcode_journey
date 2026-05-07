/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* merge2lists(struct ListNode* head1, struct ListNode* head2){
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;
    struct ListNode* curr = &dummy;
    while(head1 != NULL && head2 != NULL){
        if(head1 -> val >= head2 -> val){
            curr -> next = head2;
            head2 = head2 -> next;
        }
        else if(head2 -> val > head1 -> val){
            curr -> next = head1;
            head1 = head1 -> next;
        }
        curr = curr -> next;
    }
    if(head1 != NULL){
        curr -> next = head1;
    }
    else if(head2 != NULL){
        curr -> next = head2;
    }
    return dummy.next;
}
//toi uu bang cach dung divide to conquer
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(listsSize == 0){
        return NULL;
    }
    int interval = 1;
    while(interval < listsSize){
        for(int i = 0; i + interval < listsSize; i += interval * 2){
            lists[i] = merge2lists(lists[i], lists[i + interval]);
        }
        interval *= 2;
    }
    return lists[0];
}