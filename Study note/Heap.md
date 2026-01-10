# 讀書筆記：Heap（堆積）

## 基本概念
**Heap（堆積）** 是一種 **完全二元樹（Complete Binary Tree）**，通常以**陣列**儲存，並滿足 **堆積性質（heap-order property）**：

- **Max Heap**：父節點 ≥ 子節點，最大值在根
- **Min Heap**：父節點 ≤ 子節點，最小值在根

Heap 可在 `O(1)` 取得極值（根節點），並在 `O(log n)` 時間完成插入與刪除，常用於：
- Priority Queue
- Heap Sort

---

## 結構性質（Shape Property）
Heap 一定是 **完全二元樹**：
- 除最後一層外，每層皆填滿
- 最後一層由左至右填入
- 不會出現中間空洞

此性質使 Heap 能以陣列高效儲存。

---

## 順序性質（Heap Property）

### Max Heap
- 父節點值 ≥ 子節點
- 根節點為最大值

### Min Heap
- 父節點值 ≤ 子節點
- 根節點為最小值

**注意**：  
Heap 只保證父子關係，不保證整體排序。

---

## 抽象資料型別（ADT）
Heap 常見操作：
- Insert
- ExtractMax / ExtractMin
- Peek
- IncreaseKey / DecreaseKey
- Delete
- BuildHeap

---

## 複雜度分析

### 時間複雜度
- Insert：`O(log n)`
- Extract Max / Min：`O(log n)`
- Peek：`O(1)`
- Heapify：`O(log n)`
- Build Heap（自底向上）：`O(n)`

---

## 空間複雜度
- 陣列儲存：`O(n)`
- 不需額外指標（相較一般樹）
- 索引關係（概念）：
  - parent
  - left child
  - right child

---

## 特性總結
- 完全二元樹
- 根節點永遠是極值
- 插入與刪除只影響樹高（`log n`）
- 不支援快速搜尋任意元素

---

## 優缺點

### 優點
- 極值存取快：Peek 為 `O(1)`
- 插入 / 刪除效率佳：`O(log n)`
- 陣列表示，快取友善
- 非常適合 Priority Queue
- Heap Sort：`O(n log n)`，額外空間 `O(1)`

### 缺點
- 搜尋特定元素慢：`O(n)`
- 不支援有序操作（前驅 / 後繼 / 區間查詢）
- 刪除或更新需知道位置（常需 index map）
- Heap Sort 不穩定
- 常數因子較大，部分情境不如平衡 BST
