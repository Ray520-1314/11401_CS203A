# 讀書筆記：Graph（圖）

## 基本概念
**Graph（圖）** 由 **頂點（Vertices）** 與 **邊（Edges）** 組成，用來表示實體之間的關係。

圖可以：
- 有向 / 無向  
- 允許或不允許循環（cycle）  
- 不一定連通（與樹不同）

**常見應用**：社交網路、交通路線、網頁連結、相依關係

---

## 離散數學中的正式定義

### 無向圖（Undirected Graph）
\[
G = (V, E)
\]
- \( V \)：非空有限頂點集合  
- \( E \subseteq \{\{u, v\} \mid u, v \in V,\ u \neq v\} \)

### 有向圖（Digraph）
\[
G = (V, E)
\]
- \( E \subseteq V \times V \)，由有序對 \((u, v)\) 組成

---

## 重要名詞

### Adjacent（相鄰）
- 無向圖：\(\{u, v\} \in E\)
- 有向圖：\((u, v) \in E\)

### Degree（度數）
- 無向圖：\(\deg(v)\)
- 有向圖：
  - In-degree：\(\deg^{-}(v)\)
  - Out-degree：\(\deg^{+}(v)\)

### Walk / Trail / Path
- **Walk**：允許重複頂點與邊  
- **Trail**：不重複邊  
- **Path**：不重複頂點  

### Cycle
- 起點 = 終點的 path

### Graph 類型
- **Simple Graph**：無 self-loop、無重邊  
- **Multigraph**：允許重邊  
- **Pseudograph**：允許 self-loop  

---

## Handshaking Lemma（無向圖）
\[
\sum_{v \in V} \deg(v) = 2|E|
\]

**推論**：
- 奇數度數的頂點個數一定是偶數

---

## 圖的表示法（Representation）
- Adjacency Matrix（鄰接矩陣）
- Adjacency List（鄰接串列）
- Edge List（邊清單）

---

## 抽象資料型別（ADT）

**常見操作**：
- Create  
- Add Vertex  
- Add Edge  
- Remove Vertex  
- Remove Edge  
- Get Neighbors  
- Has Edge  
- Get Vertices / Get Edges
