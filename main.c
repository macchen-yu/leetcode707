#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
void printList(MyLinkedList* list) {
    printf("LinkedList: ");
    for (int i = 0; i < list->size; i++)
        printf("%d -> ", myLinkedListGet(list, i));
    printf("NULL\n");
}

int main() {
    printf("=== LeetCode 707 - Design Linked List Test ===\n");
    MyLinkedList* myLinkedList = myLinkedListCreate();
    // 新增頭部節點
    myLinkedListAddAtHead(myLinkedList,5);
    myLinkedListAddAtHead(myLinkedList,8);
    myLinkedListAddAtHead(myLinkedList,10);
    
    printList(myLinkedList);
    /*
    === LeetCode 707 - Design Linked List Test ===
    LinkedList: 10 -> 8 -> 5 -> NULL
     */
    myLinkedListAddAtTail(myLinkedList,18);
    myLinkedListAddAtTail(myLinkedList,50);
    printList(myLinkedList);
    /*LinkedList: 10 -> 8 -> 5 -> 18 -> 50 -> NULL*/
}