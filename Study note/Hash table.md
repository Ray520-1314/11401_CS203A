# 讀書筆記：Hash Table（雜湊表）

## 基本概念
**Hash Table（雜湊表）** 是一種 **key–value** 資料結構，透過 **雜湊函數（hash function）** 將 key 對應到陣列索引。

在雜湊函數設計良好、且 **負載因子（load factor）** 受控時：
- 查詢 / 插入 / 刪除的**期望時間複雜度**皆為 `O(1)`

由於不同 key 可能映射到相同索引，**碰撞（collision）** 無法避免，常見處理方式：
- **Separate Chaining**：每個索引位置維護一條串列
- **Open Addressing**：發生碰撞時以探測方式尋找空位

最壞情況（大量碰撞）下會退化為 `O(n)`，但實務上仍是最常用的查詢結構。

---

## 從陣列與連結串列到雜湊表的演進

### 陣列
- 已知索引可 `O(1)` 存取
- 無法直接用 key 找到索引

### 連結串列
- 插入 / 刪除方便
- 搜尋需線性掃描 `O(n)`

➡️ **雜湊表的目的**：結合陣列與串列的優點，避免各自缺點。

---

## 步驟一：只有陣列，索引是問題
- 陣列依索引讀寫為 `O(1)`
- 若以 key 存取：
  - 不知道 key 對應哪個索引
  - 只能線性搜尋 `(key, value)`
- 查詢仍為 `O(n)`

---

## 步驟二：桶子陣列 + 串列
- 建立陣列，每個位置稱為 **bucket**
- 每個 bucket 存放對應 key 的資料（通常是連結串列）

結果：
- 操作只在單一 bucket 內進行
- 成本取決於 bucket 長度

➡️ **Separate Chaining** 的核心概念

---

## 步驟三：加入雜湊函數
- 使用雜湊函數將 key 映射到 bucket
- 流程：
  1. 對 key 計算雜湊值
  2. 轉換成 bucket 索引
  3. 在該 bucket 內搜尋 / 更新

---

## 為什麼雜湊表「期望是 O(1)」
設：
- `n`：元素數量
- `m`：bucket 數量
- **負載因子** `α = n / m`

若：
- key 分布均勻
- 透過 resize / rehash 控制 α

則：
- 每個 bucket 平均很短
- 操作成本為 `O(1 + α)`

➡️ 當 α 有界時，視為 **期望 `O(1)`**

---

## Hash Table ADT 支援的操作
- **Insert / Put**：插入或更新  
  - 期望 `O(1)`，最壞 `O(n)`
- **Lookup / Get**：依 key 查詢  
  - 期望 `O(1)`，最壞 `O(n)`
- **Update**：更新 value  
  - 期望 `O(1)`，最壞 `O(n)`
- **Delete / Remove**：刪除 key  
  - 期望 `O(1)`，最壞 `O(n)`
- **Contains**：檢查 key 是否存在  
  - 期望 `O(1)`，最壞 `O(n)`
- **Traversal / Iteration**：遍歷所有資料  
  - `O(n)`，順序不保證
- **Resize / Rehash**：調整大小並重新雜湊  
  - `O(n)`（可攤銷）

---

## 雜湊函數設計（Hash Function Design）
索引計算：

良好雜湊函數的特性：
- 決定性（Deterministic）
- 均勻性（Uniform）
- 計算快速
- 低相關性（微小輸入變化造成大輸出差異）

---

## 常見雜湊方式
- **整數 key**
  - 乘法雜湊（實務常見）
  - 取餘數雜湊（需慎選表大小）
- **字串 key**
  - 多項式 Rolling Hash

---

## 表大小（m）的選擇
- **Separate Chaining**
  - 常選質數或規律成長
- **Open Addressing**
  - 常用 2 的冪次方
  - 雜湊函數需充分混合位元，避免低位偏差

---

## 碰撞處理策略（Collision Resolution）
設：
- `n`：元素數量
- `m`：slot / bucket 數量
- 負載因子 `α = n / m`
