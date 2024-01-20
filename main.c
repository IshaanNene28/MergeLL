#include<stdio.h>
#include<math.h>

struct ListNode {
      int val;
      struct ListNode *next;
  };

void InsAtBack(struct ListNode** head, int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(!newNode){
        return;
    }
    newNode->val = value;
    newNode->next = NULL;
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    struct ListNode* current = *head;
    while (current->next != NULL) 
    {
        current = current->next;
    }
    current->next = newNode;
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* nope = list1;
    struct ListNode* newnope = list2;
    struct ListNode* newnewnope = NULL;

    while ((newnope != NULL) && (nope != NULL)) {
        if (newnope->val == nope->val) 
        {
            InsAtBack(&newnewnope, nope->val);
            InsAtBack(&newnewnope, nope->val);
            newnope = newnope->next;
            nope = nope->next;
        } 
        else if (newnope->val > nope->val) 
        {
            InsAtBack(&newnewnope, nope->val);
            nope = nope->next;
        } 
        else 
        {
            InsAtBack(&newnewnope, newnope->val);
            newnope = newnope->next;
        }
    }
    while (newnope != NULL) 
    {
        InsAtBack(&newnewnope, newnope->val);
        newnope = newnope->next;
    }
    while (nope != NULL) 
    {
        InsAtBack(&newnewnope, nope->val);
        nope = nope->next;
    }
    return newnewnope;
}
