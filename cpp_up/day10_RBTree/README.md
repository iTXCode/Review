### 红黑树

- [ ] cur,parent,uncle

#### uncle存在且为红

- parent,uncle变黑
- gparent:红
- cur=gparent:继续向上调整
#### uncle存在且为黑/不存在

- 需要旋转
- cur,parent在同一边的时候需要进行单旋
- cur,parent不在同一边的时候进行双旋:通过第一次旋转转换为第一种情况 -->单旋
- parent:黑
- gparent:红
- cur=parent:继续进行调整

### 红黑树改造
_header->parent=root; root->parent=_header;
_header->left=leftMost();
_header->right==rightMost();

### 迭代器:(中序遍历)
- begin: _header->left
- end: _header
- ++:_node看是否有右子树
>右子树存在:往右子树的最左结点
>右子树存在:向上回溯,找到一个结点,它的孩子不是它的右子树
死循环:没有右子树,需要判断,node->right=parent:不用赋值

map,multimap: RBTree<k,pair<K,V>,KeyOfValue>

map:operator[]:插入操作,读写--->pair<iterator,bool> ret=Insert(K,V());
return ret.first->second-->V&
set,multiset:RBTree<K,K,KeyOfValue>

