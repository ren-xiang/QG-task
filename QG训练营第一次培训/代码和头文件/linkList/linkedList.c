#include "../head/linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
    *L = (LinkedList)malloc(sizeof(LNode));//动态申请内存
    (*L)->next = NULL;//安全指向
       if(L!= NULL)
      {
        (*L)->next=NULL;
        (*L)->data=0;
        return SUCCESS;
      }
        else return ERROR;
}



/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
        LinkedList *p,*t;
        p = (*L)->next;    //定义指针P指向链表要删除的链表List的第一个点节点
        (*L)->next = NULL;
            while (p != NULL)
        {
              t = (*p)->next; //临时t指向要删除的节点的下个节点
              free(p);    //释放指针P指向的节点
              p = t;      //重新赋值
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
        if (p!=NULL)
        {
            q->next=NULL;
            p->next=q;
        }
        else
        {
            q->next=p->next;
            p->next=q;
        }
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
        if(p->next == NULL)
                return ERROR;
        LNode *temp;
        temp=p->next->next;
        *e=p->next->data;
        free(p->next);
        p->next=temp;
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
        LNode *p=L;
        while(p!=NULL)
        {
                (visit)(p->data);// call the function vist
                p=p->next; // 指向下一个结点
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
        LNode *p=L;
        while(p!=NULL){
        if( p->data == e )
                return SUCCESS;
        p=p->next;
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
        LinkedList *p1,*p2;
        p1=(*L)->next;//p1记录头结点下一个结点的位置
        (*L)->next=NULL;
        while(p1!=NULL){
                p2=(*p1)->next;//p2是p1下一个结点位置
                (*p1)->next=(*L);//p1->next反向指向以前的结点
               //移动L和p1,到后面head重新变成头结点
                (*L)=p1;
                p1=p2;
        }
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
        LinkedList *slow,*fast;
        slow=L,fast=L;//安全指向，都先指向头指针
        while(slow!=NULL&&fast!=NULL)
        {
                slow=(*slow)->next;
                fast=(*fast)->next->next;
                if(fast==slow)
                return SUCCESS;
                else
                return ERROR;
        }
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
//LNode* ReverseEvenList(LinkedList *L) {

//}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
        LinkedList *p1,*p2;
        p1=L,p2=L;
        while(p2!=NULL){
                p1=(*p1)->next;//p1+1
                p2=(*p2)->next->next;//p2+2
        }
                return *p1 ;
}
