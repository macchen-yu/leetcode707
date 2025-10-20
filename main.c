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

    myLinkedListAddAtIndex(myLinkedList,2,23);
    myLinkedListAddAtIndex(myLinkedList,5,23);
    printList(myLinkedList);
    /*LinkedList: 10 -> 8 -> 23 -> 5 -> 18 -> 23 -> 50 -> NULL*/
    myLinkedListDeleteAtIndex(myLinkedList,2);
    myLinkedListDeleteAtIndex(myLinkedList,4);
    printList(myLinkedList);
    /*LinkedList: 10 -> 8 -> 5 -> 18 -> 50 -> NULL*/
    myLinkedListFree(myLinkedList);
    printList(myLinkedList);
    /*Segmentation fault (core dumped)*/
}