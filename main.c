#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"


int main() {
    printf("=== LeetCode 707 - Design Linked List Test ===\n");
    MyLinkedList* myLinkedList = myLinkedListCreate();
    // 新增頭部節點
    myLinkedListAddAtHead(myLinkedList,5);
    printf("值:%d\n",myLinkedList->head->val);
    printf("鏈表大小%d\n",myLinkedList->size);
    
}