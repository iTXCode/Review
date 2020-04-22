#### 关联式容器底层实现

|底层实现方式 | 容器|
|-|-|
|红黑树|map,set,multi_map,multi_set|
|Hash|unordered_map,unordered_set,unordered_multimap,unordered_multiset|

#### 区别
**其中红黑树的迭代器遍历==有序==:==中序遍历==**
增删查性能:O(logN)
##### 哈希
**哈希:迭代器遍历==无序==:==中序遍历==**
增删查性能:O(1)

##### 哈希冲突:
###### 闭散列:开放定址法

- [ ]解决哈希冲突:线性探测,二次探测()
###### 开散列:拉链法(哈希桶)
