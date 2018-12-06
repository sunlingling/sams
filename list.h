#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdbool.h>

typedef struct Node
{
    struct Node* prev;
    void* data;
    struct Node* next;
}Node;

typedef struct List
{
    Node* head;
    Node* tail;
    size_t size;
}List;

// 创建结点
Node* create_node(void* data);
// 初始化链表
void list_init(List* list);
// 释放链表
void list_deinit(List* list);
// 插入尾结点
void list_push(List* list,void* data);
// 删除头结点
void list_pop(List* list);
// 删除任意位置结点
bool list_delete(List* list,int index);
// 判断链表是否为空
bool list_empty(List* list);
// 排序
void list_sort(List* list,int (*comptr)(void* data1,void* data2));
// 遍历
void list_show(List* list,void (*show_data)(void* data));

#endif//LIST_H
