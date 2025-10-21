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
/* 
 * 函式名稱：myLinkedListAddAtHead
 * 功能：在鏈表頭部插入一個新節點
 * 參數：
 *   obj — 指向鏈表的指標
 *   val — 要插入的數值
 * 
 * 實作說明：
 *   1. 先動態配置一個新的節點(Node)，並將 val 賦值給它。
 *   2. 令新節點的 next 指向目前的頭節點 (obj->head)，
 *      也就是「原本整條鏈表」。
 *   3. 更新 obj->head 讓它指向這個新節點，
 *      因此新節點成為新的頭節點。
 *   4. 鏈表的節點總數 size 加 1。
 */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* node = (Node*)malloc(sizeof(Node));  // 建立新節點
    node->val = val;                           // 設定節點的值
    node->next = obj->head;                    // 新節點指向原本的頭節點
    obj->head = node;                          // 更新頭節點指標
    obj->size++;                               // 更新鏈表大小
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
/* 
 * 函式名稱：myLinkedListAddAtTail
 * 功能：在鏈表尾部插入一個新節點
 * 參數：
 *   obj — 指向鏈表的指標
 *   val — 要插入的數值
 * 
 * 實作步驟：
 *   1️ 建立新節點 node_tail，並將傳入的 val 存入其中；
 *       由於它將成為最後一個節點，因此 next 設為 NULL。
 *   2️ 如果目前鏈表為空 (head == NULL)，
 *       代表這是第一個節點，直接讓 head 指向它即可。
 *   3️ 若鏈表非空：
 *       從 head 開始走訪，使用 while 迴圈逐一找到「當前最後一個節點」，
 *       即 cur->next 為 NULL 的節點。
 *       將該節點的 next 指向新節點 node_tail。
 *   4️ 最後更新鏈表節點總數 size。
 */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    /* Step 1️ 建立新的尾節點 */
    Node* node_tail = (Node*)malloc(sizeof(Node));
    node_tail->val = val;       // 將傳入的 val 賦值給節點
    node_tail->next = NULL;     // 尾節點的 next 永遠是 NULL

    /* Step 2️ 檢查鏈表是否為空 */
    if (obj->head == NULL) {
        // 若為空，head 直接指向新節點
        obj->head = node_tail;
    } else {
        /* Step 3️ 從頭開始走訪，找到最後一個節點 */
        Node* cur = obj->head;
        while (cur->next)       // 一直走到 cur->next == NULL
            cur = cur->next;
        // 此時 cur 指向現有鏈表的尾節點
        cur->next = node_tail;  // 將新節點接到尾巴
    }

    /* Step 4️ 更新節點數量 */
    obj->size++;
}

/*
 * 函式名稱：myLinkedListAddAtIndex
 * 功能：在指定索引 (index) 前插入一個新節點
 * 參數：
 *   obj   — 指向鏈表的指標
 *   index — 插入位置的索引（從 0 開始）
 *   val   — 要插入的節點值
 *
 * 實作步驟：
 *   1️ 若 index < 0 或 index > size，代表索引無效，直接返回。
 *       （注意：等於 size 表示在尾部插入是允許的）
 *   2️ 若 index == 0，表示要插入在頭部，直接呼叫 AddAtHead()。
 *   3️ 否則：
 *       - 建立新節點 node_index，將 val 賦值。
 *       - 使用一個指標 cur，從 head 開始走訪，
 *         走 (index - 1) 次後，cur 會停在「插入點的前一個節點」。
 *       - 將新節點的 next 指向 cur->next（原本的第 index 節點）
 *       - 再讓 cur->next 指向新節點（插入完成）
 *   4️ 更新鏈表節點總數 size。
 */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    /* Step 1️ 檢查 index 合法性 */
    if (index < 0 || index > obj->size)
        return;

    /* Step 2️ 若 index == 0，插入到頭部 */
    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    /* Step 3️ 建立新節點 */
    Node* node_index = (Node*)malloc(sizeof(Node));
    node_index->val = val;

    /* Step 4️ 從頭開始走訪，找到插入點的前一個節點 */
    Node* cur = obj->head;
    for (int i = 0; i < index - 1; i++)
        cur = cur->next;

    /* Step 5️ 插入節點（改接指標） */
    node_index->next = cur->next;   // 新節點指向原本第 index 節點
    cur->next = node_index;         // 前一個節點指向新節點

    /* Step 6️ 更新鏈表大小 */
    obj->size++;
}

/*
 * 函式名稱：myLinkedListDeleteAtIndex
 * 功能：刪除鏈表中指定 index 位置的節點
 * 參數：
 *   obj   — 指向鏈表的指標
 *   index — 要刪除的節點索引（從 0 開始）
 *
 * 實作步驟：
 *   1️ 檢查 index 是否有效：
 *       若 index < 0 或 index >= size，表示越界，直接返回。
 *
 *   2️ 若 index == 0，表示要刪除頭節點：
 *       - 暫存目前的 head 節點指標 cur
 *       - 將 head 移到下一個節點 (obj->head->next)
 *       - 釋放原本的頭節點記憶體
 *
 *   3️ 若 index > 0：
 *       - 使用 cur 走訪到第 (index - 1) 個節點（即待刪除節點的前一個）
 *       - 使用 toDelete 暫存要刪除的節點 (cur->next)
 *       - 將 cur->next 改為 toDelete->next，跳過要刪除的節點
 *       - 釋放 toDelete 節點的記憶體
 *
 *   4️ 更新鏈表節點數量 size。
 */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    /* Step 1️：檢查 index 合法性 */
    if (index < 0 || index >= obj->size)
        return;

    Node* cur = obj->head;

    /* Step 2️：刪除頭節點 */
    if (index == 0) {
        obj->head = obj->head->next;  // head 指向下一個節點
        free(cur);                    // 釋放原本頭節點
    } 
    /* Step 3️：刪除非頭節點 */
    else {
        // 找到第 (index-1) 個節點
        for (int i = 0; i < index - 1; i++)
            cur = cur->next;

        Node* toDelete = cur->next;         // 要刪除的節點
        cur->next = cur->next->next;        // 跳過該節點
        free(toDelete);                     // 釋放記憶體
    }

    /* Step 4️⃣：更新鏈表大小 */
    obj->size--;
}

/* 釋放整個鏈結串列 */
void myLinkedListFree(MyLinkedList* obj) {
    Node* cur = obj->head;
    while (cur) {
        Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(obj);
}
