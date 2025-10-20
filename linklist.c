#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

/* 建立 LinkedList */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

/* 在頭部插入節點 */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = obj->head;
    obj->head = node;
    obj->size++;
}

/* 取得 index 節點的值 */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return -1;
    Node* cur = obj->head;
    for (int i = 0; i < index; i++)
        cur = cur->next;
    return cur->val;
}
/* 在尾部插入節點 */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;

    if (obj->head == NULL) {
        obj->head = node;
    } else {
        Node* cur = obj->head;
        while (cur->next)
            cur = cur->next;
        cur->next = node;
    }
    obj->size++;
}
/* 在 index 前插入節點 */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size)
        return;
    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;

    Node* cur = obj->head;
    for (int i = 0; i < index - 1; i++)
        cur = cur->next;

    node->next = cur->next;
    cur->next = node;
    obj->size++;
}