#include "linkedList.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	*L = (LinkedList)malloc(sizeof(LNode));
	if(L == NULL)return ERROR;
	else {
                (*L)->next = NULL;
                (*L)->data = 0;
                return SUCCESS;
	}
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList p=(*L);
	while(p != NULL){
                *L = p->next;
                free(p);
                p = *L;
	}
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
        if(p->next == NULL)return ERROR;
        LNode *o = p->next->next;
        *e = p->next->data;
        free(p->next);
        p->next = o;
        return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
        LNode *p = L;
        while(p!=NULL){
                visit(p->data);
                p = p->next;
        }
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
        LNode *p = L;
        while(p!=NULL){
                if(p->data == e){
                        return SUCCESS;
                }
                p = p->next;
        }
        return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
        LNode *p1,*p2,*p3;
        p1 = (*L)->next;                   if(p1 == NULL)return SUCCESS;
        p2 = (*L)->next->next;             if(p2 == NULL)return SUCCESS;
        p3 = (*L)->next->next->next;//确保链表超过3个节点
        p1->next = NULL;
        p2->next = p1;
        while(p3 != NULL){
                p1 = p2;
                p2 = p3;
                p3 = p3->next;
                p2->next = p1;
        }
        (*L)->next = p2;
        return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
        LNode *fast,*slow;
        fast=slow=L;
        while(1){
                fast = fast->next->next;
                slow = slow->next;
                if(fast == NULL)return ERROR;
                else if(fast == slow) break;
        }
        return SUCCESS;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
        LNode *p1 = *L,*p2,*p3 = *L;
        while(1){
                p1 = p1->next;
                if(p1 == NULL)break;
                p2 = p1->next;
                if(p2 == NULL)break;
                p1->next = p2->next;
                p2->next = p1;
                p3->next = p2;
                p3 = p2->next;
        }
        return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
        LNode *mid,*fast;
        mid = fast = *L;
        while(1){
                mid = mid->next;
                fast = fast->next;
                if(fast == NULL)break;
                fast = fast->next;
                if(fast == NULL)break;
        }
        return mid;
}