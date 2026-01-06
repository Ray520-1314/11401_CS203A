讀書筆記：Heap（堆積）

基本概念

Heap（堆積） 是一種完全二元樹（Complete Binary Tree），通常以陣列儲存，並滿足堆積性質（heap-order property）：
	•	Max Heap：每個父節點 ≥ 子節點，最大值在根
	•	Min Heap：每個父節點 ≤ 子節點，最小值在根

Heap 可在 O(1) 時間取得極值（根節點），並在 O(log n) 時間完成插入與刪除，因此非常適合用來實作優先佇列（Priority Queue）與Heap Sort。

⸻

結構性質（Shape Property）

Heap 一定是完全二元樹：
	•	除最後一層外，每一層皆填滿
	•	最後一層由左至右依序填入
	•	不會有中間空洞

此性質使 Heap 能以陣列高效儲存。

⸻

順序性質（Heap Property）

Max Heap
	•	父節點的值 ≥ 子節點
	•	根節點一定是最大值

Min Heap
	•	父節點的值 ≤ 子節點
	•	根節點一定是最小值

注意：
Heap 只保證父子關係，不保證整體排序。

⸻

抽象資料型別（ADT）

Heap 常見支援操作：
	•	Insert：插入新元素
	•	ExtractMax / ExtractMin：移除並回傳根節點
	•	Peek：查看根節點（不移除）
	•	IncreaseKey / DecreaseKey：更新某元素的鍵值
	•	Delete：刪除指定位置的元素
	•	BuildHeap：將一個陣列轉換成 Heap

⸻

複雜度分析

時間複雜度
	•	Insert：O(log n)
	•	Extract Max / Min：O(log n)
	•	Peek：O(1)
	•	Heapify（恢復堆積性質）：O(log n)
	•	Build Heap（自底向上）：O(n)

⸻

空間複雜度
	•	陣列儲存：O(n)
	•	不需要額外指標（相較於一般樹結構）
	•	父子索引關係（概念層級）：
	•	父節點
	•	左子節點
	•	右子節點

⸻

特性總結
	•	完全二元樹
	•	根節點永遠是極值（最大或最小）
	•	插入與刪除只影響樹高（log n）
	•	不支援快速搜尋任意元素

⸻

優缺點

優點
	•	極值存取快：Peek 為 O(1)
	•	插入與刪除效率佳：O(log n)
	•	空間利用率高：陣列表示，快取友善
	•	非常適合優先佇列：排程、事件模擬、Top-k 問題
	•	可原地排序：Heap Sort 為 O(n log n)，額外空間 O(1)

⸻

缺點
	•	無法快速搜尋特定元素：通常為 O(n)
	•	不支援有序操作：前驅、後繼、區間查詢效率差
	•	刪除／更新需知道位置：常需搭配額外結構（如 index map）
	•	Heap Sort 不穩定
	•	常數因子較大：某些情境下可能不如平衡 BST
