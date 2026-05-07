

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k) 
{
    typedef struct ListNode node;
    if (head == NULL) return head;
    int cnt = 0;
    node* cur = head;
    node* pre = NULL;
    while (cur->next) 
    {
        cnt++;
        cur = cur->next;
    }
    node* last = cur;
    cnt++;
    if (cnt == 1) return head;
    k = k % cnt;
    if (k == 0) return head;
    int n = 0;
    cur = head;
    while (1) 
    {
        int m = cnt - n;
        if (m == k) 
        {
            pre->next = NULL;
            last->next = head;
            head = cur;
            return head;
        }
        pre = cur;
        cur = cur->next;
        n++;
    }
    return head;
}