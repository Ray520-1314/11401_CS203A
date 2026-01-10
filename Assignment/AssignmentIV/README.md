# Assignment IV – Hash Function Implementation

## 1. 文件架構

<img width="199" height="455" alt="{2674D641-1CF9-423A-BC0E-CD4A07B2CB00}" src="https://github.com/user-attachments/assets/77d3bb5a-9c73-4801-ac9c-cb0133046945" />


- `C/`：C 語言版本的 hash function 與測試程式  
- `CXX/`：C++ 版本的 hash function 與測試程式  
- `main.c / main.cpp`：觀察不同 table size 下的 hash 分布結果  

---

## 2. Hash Function 設計原理說明

### Integer Hash
- 將整數轉為 unsigned 型別
- 使用位元混合（bit mixing）與乘法擴散
- 降低相鄰整數造成的碰撞機率
- 最後使用 `mod m` 對應到 hash table 範圍

設計目標：  
> 改善單純 `key % m` 容易產生碰撞的問題，提升分布均勻性

---

### String Hash
- 採用 **DJB2 hash algorithm**
- 使用公式：`hash = hash * 33 + c`
- 計算效率高，對短字串分布效果良好
- 最後使用 `mod m` 取得索引值

設計目標：  
> 提供穩定且實作簡單的字串雜湊方法

---

## 3. 輸出格式截圖（示意）

### Integer Hash（m = 11）
<img width="172" height="192" alt="{B196DACB-6065-454E-8D1F-8DAA16817ED5}" src="https://github.com/user-attachments/assets/b3336a4a-00d6-4c96-a034-824cae5205ca" />

### String Hash（m = 37）
<img width="180" height="194" alt="{268EE3A2-B5C1-4D43-A222-74E7F58993A0}" src="https://github.com/user-attachments/assets/9e6a7271-0494-4671-b6f2-c5bdfbccc2a1" />
---

## Final Evaluation

- 改良後的 hash function 較基本除法法有更好的分布性  
- 在不同 table size（特別是質數）下表現穩定  
- 適合作為 hash table 實驗與學習用途


