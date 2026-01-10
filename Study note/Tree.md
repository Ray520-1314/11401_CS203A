**讀書筆記：Tree（樹狀結構）

基本概念

Tree（樹） 是一種非線性、階層式（hierarchical）資料結構，由節點（node）與邊（edge）所組成，不存在循環（cycle）。
每個節點可以有零個或多個子節點，用來表示父子關係，常見應用包含檔案系統、組織架構、決策模型等。

⸻

從 Linked List 到 Tree 的轉換思維

連結串列（Linked List） 是最簡單的指標式結構：
	•	每個節點只有一個 next 指標
	•	形成一條線性的序列（1D）

Tree 是其推廣版本：
	•	每個節點可指向多個子節點
	•	結構從線性變為階層式、多層次

核心轉換：
	•	Linked List：一個 next 指標 → 線性
	•	Tree：多個 child 指標 → 階層

樹的基本特性：
	•	有且只有一個 root（根節點）
	•	除 root 外，每個節點恰有一個父節點
	•	指標向外分支，形成子樹（subtree）

⸻

結構與術語
	•	Root：根節點
	•	Internal node：內部節點（非葉子）
	•	Leaf：葉節點（無子節點）
	•	Edge：節點之間的連線
	•	Subtree：某節點及其所有後代
	•	Level / Depth / Height：層級、深度、高度

⸻

二元樹（Binary Tree）
	•	每個節點最多有兩個子節點：left、right
	•	是最常見、最重要的樹結構之一

Binary Search Tree（BST）
	•	滿足順序性質：
	•	左子樹 < 根 < 右子樹
	•	可進行有序搜尋、最小值、最大值等操作
	•	若不平衡，效能可能退化

⸻

樹的表示方式
	•	指標表示法
	•	節點儲存指向子節點的指標
	•	常用於 BST、一般樹
	•	陣列表示法
	•	適合完全二元樹（如 Heap）
	•	可能浪費空間
	•	左子右兄（LCRS）表示法
	•	用二元樹指標表示一般樹

⸻

抽象資料型別（ADT）

二元樹常見操作
	•	建立空樹
	•	判斷是否為空
	•	以左右子樹與根節點建構新樹
	•	取得左子樹、右子樹
	•	取得根節點資料

⸻

樹的走訪（Traversal）
	•	Preorder：根 → 左 → 右
	•	Inorder：左 → 根 → 右（BST 會得到排序結果）
	•	Postorder：左 → 右 → 根
	•	Level-order：逐層走訪（BFS）

⸻

複雜度分析

時間複雜度

平衡 BST
	•	搜尋 / 插入 / 刪除：O(log n)

不平衡樹（最壞）
	•	搜尋 / 插入 / 刪除：O(n)

⸻

空間複雜度
	•	指標式表示：O(n)
	•	陣列式表示：O(capacity)，可能浪費
	•	遞迴走訪：O(h)，h 為樹高

⸻

特性與限制

特性
	•	非線性、階層式
	•	單一根節點
	•	支援多種走訪方式
	•	適合表示父子關係

限制
	•	效能高度依賴樹形
	•	不平衡時會退化成連結串列
	•	維持平衡需要較複雜的演算法
	•	深層遞迴可能造成堆疊風險

⸻

優缺點

優點
	•	自然表達階層結構
	•	平衡時搜尋效率高（O(log n)）
	•	多種走訪方式支援不同需求
	•	適用問題類型廣泛
	•	可將操作限制在子樹中（divide and conquer）

缺點
	•	結構較線性資料結構複雜
	•	額外指標與維護成本
	•	樹形選錯會導致效能不佳

⸻

常見變形（考試重點）

一般樹（General / k-ary Tree）
	•	每個節點可有 0..k 個子節點
	•	常用左子右兄表示法

二元樹特殊型態
	•	Full Binary Tree：每個內部節點有 2 個子節點
	•	Perfect Binary Tree：滿且所有葉節點同層
	•	Complete Binary Tree：最後一層靠左填滿

⸻

自我平衡 BST
	•	AVL Tree：嚴格平衡，查詢快
	•	Red–Black Tree：較鬆平衡，插刪成本低，實務常用

⸻

Heap（堆積樹）
	•	完全二元樹
	•	滿足 heap-order
	•	適合實作 priority queue

⸻

B-Tree 家族
	•	多路、平衡
	•	適合磁碟與資料庫
	•	B-Tree、B+ Tree

⸻

Trie（字首樹）
	•	以字元為節點
	•	操作時間與字串長度有關
	•	適合字串查詢與字典

⸻

特殊用途樹
	•	Expression Tree
	•	Segment Tree
	•	Fenwick Tree（BIT）
	•	k-d Tree / Quadtree
	•	Decision Tree
**
