### 哈希:位置映射--->O(1)
#### 计算位置
###### 直接定址法:线性函数-->x*key+1---->适用于小范围
###### 除留余数法:取模-->key%容器的size 
##### 哈希冲突:不同的key影射到相同的位置
      - [ ] 闭散列:线性探测,二次探测
      - [ ] 开散列:拉链法(哈希桶)

- 线性探测:index + i;
- 二次探测:index+i^2-->减少哈希冲突
  
哈希:O(1)

#### 闭散列:开放定址法 线性探测 二次探测

哈希算法: 除留余数法 index=num%size 

插入:计算位置
   查看当前位置的状态:存在，删除,空
   空:直接插入
   非空:继续向后查找合适位置
         删除:直接插入
         存在: 判断key 是否和待插入的key相同 
             不相同:继续走
             相同:结束插入

删除:假删除(修改状态:删除) 
增容:重新计算元素在新表中的位置
      开新表:遍历原来的表中元素,调用插入接口

   
#### 开散列:数组+单链表
    数组:指针数组:单链表的头结点指针
##### 插入:计算位置
      判断key是否已经存在,如果存在,插入失败
                          如果不存在:头插 
##### 查找:计算位置,单链表的查找
##### 删除:计算位置 
           找到对应的key,如果删除的结点为头结点
              修改头结点:新头= 原来的头的->next
              如果不为头结点,prev->next=cur->next;
              删除结点
#### unordered_map:底层是哈希表
     HashTable<K,pair<K,V>,MapKeyOfValue,HashFun> _ht;
     MapKeyOfValue 获取pair的first:key
     HashFun 把key转成整形
#### unordered_set:底层是哈希表
     HashTable<K,K,SetKeyOfValue,HashFun> _ht;

     SetKeyOfValue:获取K的值
#### 哈希迭代器:_HashIterator<K,T,KeyOfValue,HashFun>
     ==使用之前需要先进行前置声明哈希表HashTable==
     成员:链表结点listNode<T>* _node;
     HashTable<K,T,KeyOfValue,HashFun>* _ht;
     ->：&_node->_data 
     *: _node->_data 
     ++:if(_node->next){_node=_node->_next;}
     else寻找下一个非空链表的头结点
##### begin():第一个非空链表的头结点,
     return iterator(node,this);
##### end():retur(nullptr,this);
     
#### 素数表:保证哈希表大小是一个素数,减少哈希冲突 

### 应用
#### 位图:以bit为单位的hashtable,判断海量数据中的某一个数是否存在
##### 插入:Set(num):
- [ ] 数组中位置:num/32-->num>>5,
- [ ]定位数组中位置的bit位:num%32
- [ ]bit位置1:table[位置] |=(1<<bits位)

##### 删除:ReSet
- [ ] bit位置0:table[位置] &= ~(1<< bits位)

#### 布隆过滤器:位图+多个hash函数
- [ ]多个哈希函数-->多个位置保存存在与否的信息
- Test:存在1 1 1 1 1  ：误判
- 不存在:只要有一个位置为0 ：正确

