#include "../head/duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void printData(ElemType e){
        printf(" %d",e);
}
void printMenu(){
        printf("输入你的选择：\n");
        printf("退出\t\t\t0\n");
        printf("初始化链表\t\t1\n");
        printf("销毁链表\t\t2\n");
        printf("插入节点\t\t3\n");
        printf("删除节点\t\t4\n");
        printf("遍历链表\t\t5\n");
}

DuLNode* searchNodeByData(DuLinkedList *L,int data){
        DuLNode *p1 = *L;
        while(p1 != NULL){
                if(data == p1->data)break;
                p1 = p1->next;
        }
        return p1;
}
int main(){
        int choice;
        DuLinkedList *L = (DuLinkedList*)malloc(sizeof(DuLNode));
        int a4,*e = (ElemType*)malloc(sizeof(ElemType));
        DuLNode *p3;
        void (*f)(ElemType e)= printData;
        printMenu();
        while(scanf("%d",&choice)&&choice != 0){
                switch(choice){
                        case 1:if(InitList_DuL(L))printf("初始化成功\n");
                                else printf("初始化失败");
                                break;
                        case 2:DestroyList_DuL(L);
                                break;
                        case 3:{
                                p3 = (DuLinkedList)malloc(sizeof(DuLNode));
                                Status (*Insert)(DuLNode *p, DuLNode *q);

                                if((*L)->next == NULL){
                                        printf("目前链表为空，请增加值为？的节点\n");
                                        int a3;
                                        scanf("%d",&a3);
                                        p3->data = a3;
                                        if(InsertAfterList_DuL(*L,p3))printf("插入成功\n");
                                        else printf("插入失败");
                                }
                                else{
                                        printf("请选择你想要的插入方式：\n在前面插\t\t1\n在后面插\t\t2\n");
                                        int c;
                                        if(scanf("%d",&c)&&c == 1)Insert = InsertBeforeList_DuL;
                                        else if(c == 2)Insert = InsertAfterList_DuL;
                                        else {printf("请检查输入\n");break;}
                                        printf("你想在值为？的节点前/后面插入？ 请输入值\n");
                                        int a3,b3;
                                        if(searchNodeByData(L,(scanf("%d %d",&a3,&b3),a3))==NULL)printf("请检查输入\n");
                                        else {
                                                p3->data = b3;
                                                p3->next = NULL;
                                                if(Insert(searchNodeByData(L,a3),p3))printf("插入成功\n");
                                                else printf("插入失败");
                                        }
                                }
                        }
                                break;
                        case 4:
                                printf("你想删除在值为？的节点后面的第一个节点 请输入值\n");
                                if(searchNodeByData(L,(scanf("%d",&a4),a4))==NULL)printf("请检查输入");
                                else{
                                        if(DeleteList_DuL(searchNodeByData(L,a4),e))printf("删除成功，您删除的节点值为%d\n",*e);
                                        else printf("删除失败");
                                }
                                break;
                        case 5:
                                TraverseList_DuL(*L,f);
                                printf("\n");
                                break;

                        default:printf("请检查数字\n");
                }
                system("pause");
                system("cls");
                printMenu();
        }
        return 0;
}
