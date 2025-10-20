#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"


int main() {
    printf("=== LeetCode 707 - Design Linked List Test ===\n");
    MyLinkedList* myLinkedList = myLinkedListCreate();
    // 新增節點
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = 5;
    node->next = myLinkedList->head;
    myLinkedList->head = node;
    myLinkedList->size++;
    printf("值:%d\n",myLinkedList->head->val);
    printf("鏈表大小%d\n",myLinkedList->size);
    
}