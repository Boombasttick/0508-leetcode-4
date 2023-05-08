/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* res = malloc(sizeof(struct ListNode));
    res->val = 0;
    res->next = NULL;
    struct ListNode* pre = res;
    while (list1 || list2)
    {
        struct ListNode* temp = malloc(sizeof(struct ListNode));
        if(! list1)
        {
            pre->next = list2;
            break;
        }
        else if(! list2)
        {
            pre->next = list1;
            break;
        }
        else if(list1->val<list2->val)
        {
            temp->val = list1->val;
            temp->next = NULL;
            pre->next = temp;

            pre = pre->next;
            list1 = list1 ? list1->next : NULL;
        }
        else
        {
            temp->val = list2->val;
            temp->next = NULL;
            pre->next = temp;

            pre = pre->next;
            list2 = list2 ? list2->next : NULL; 
        }
    }
    return res->next;
}


void addcontact(struct ListNode* pb,int* arr)
{
    int i=0;
    pb->val=arr[0];
    for (i=1;i<2;i++){
        struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = arr[i];
        temp->next = NULL;
        pb->next =  temp;
        pb = pb->next;
    }
}

int main(){
    int arr1[] = {1,2};
    int arr2[] = {1,3};
    struct ListNode l1;
	struct ListNode l2;
    addcontact(&l1,arr1);
    addcontact(&l2,arr2);
    struct ListNode* l3 = mergeTwoLists(&l1, &l2);
    return 0;
}