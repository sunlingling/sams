#include "list.h"
#include "malloc.h"

// 创建结点
Node* create_node(void* data)
{
    Node* node = malloc(sizeof(Node));
    node->prev = NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

// 初始化链表
void list_init(List* list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// 释放链表
void list_deinit(List* list)
{
    while(!list_empty(list)) list_pop(list);
}

// 插入尾结点
void list_push(List* list,void* data)
{
    Node* node = create_node(data);
    
    if(list_empty(list))
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
    
    list->size++;
}

// 删除头结点
void list_pop(List* list)
{

}

// 删除任意位置结点
bool list_delete(List* list,int index);
// 判断链表是否为空
bool list_empty(List* list)
{
    return !list->size;
}

#define swap(a,b) {void* t=a; a=b; b=t;}
void list_quick(Node* head,Node* tail,int (*comptr)(void* data1,void* data2))
{
    if(head == tail || head->next == tail) return;
    
    Node* flag = head;
    Node* prev = head;
    Node* cur  = head->next;
    
    while(cur != tail->next)
    {
        if(comptr(flag->data,cur->data))
        {
            prev = prev->next;
            swap(prev->data,cur->data);
        }
        
        cur = cur->next;
    }
    
    swap(flag->data,prev->data);
    list_quick(flag,prev,comptr);
    list_quick(prev->next,tail,comptr);
}

// 遍历
void list_show(List* list,void (*show_data)(void* data))
{
    for(Node* node=list->head; node!=list->tail->next; node=node->next)
    {
        show_data(node->data);
    }
    printf("\n");
}

void show_data(void* data)
{
    printf("%d ",*(int*)data);
}

int comptr(void* data1,void* data2)
{
    return *(int*)data1 > *(int*)data2;
}
