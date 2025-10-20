# 🧩 LeetCode 707 — Design Linked List（C 版本專案）

---

## 📘 題目介紹

> **題目來源**：LeetCode 707 — *Design Linked List*
> **目標**：自行實作一個鏈結串列（Linked List），不使用任何內建容器。
>
> 支援以下操作：
>
> | 函數                       | 功能說明                                |
> | ------------------------ | ----------------------------------- |
> | `get(index)`             | 回傳第 index 個節點的值（0-based）            |
> | `addAtHead(val)`         | 在鏈結串列頭部插入節點                         |
> | `addAtTail(val)`         | 在鏈結串列尾部插入節點                         |
> | `addAtIndex(index, val)` | 在 index 前插入節點，若 index == size 則加在尾部 |
> | `deleteAtIndex(index)`   | 刪除第 index 個節點                       |
> | `free()`                 | 釋放整個鏈結串列記憶體                         |

---

## 🧱 檔案結構

```bash
leetcode707/
├── Makefile
├── linklist.h
├── linklist.c
└── main.c
```

### 執行
```
git clone https://github.com/macchen-yu/leetcode707.git
cd leetcode707
make
```
> 建議在電腦上帶有linux作業系統上執行




