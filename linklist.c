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




