# 经典的题目

### 队列
### 优先队列（堆）
topK问题  

### 位图
位图是用一块内存区域的每个比特位表示一个对象的数据结构。在索引、数据压缩等方面应用广泛，有点是速度快，内存空间占用小。
譬如有亿级别数据，数据范围是1-1000w，统计缺失的数据，一般情况需要开1000w的数组，数组类型是bool，占用内存就是10M。但如果用位图实现，每个bit位代表一个数，那么只要1000wbit位,占用内存1.24M, 大大降低内存使用量

### 链表
- 单链表反转
- 获取单链表倒数K个元素  
1.先遍历链表，获取总长度，然后再次遍历N-K+1就得到倒数K个元素
2.声明两个指针，第一个指针先移动跳过K-1个元素，然后两个指针同时移动，当第一个指针移动到末尾时，第二个就是倒数K个元素  
- 给定链表头和节点，在O(1)时间复杂度内删除该节点  
只要把节点的next内容赋值给当前节点，然后删除其下个节点即可；如果是表头直接删除并返回新表头；如果是表尾，还需要遍历表到其前一个位置。 所以整个复杂度在O[((N - 1) * O(1) + O(N)) / N] = O(1)
- 查找单链表中间节点
声明两个指针，一个指针跳两次，一个指针跳一次，跳两次结束后，跳一次就是中间点  
- 判断单链表是否有环
声明两个指针，一个指针跳两次，一个指针跳一次，如果有环，两个指针会碰到  
- 判断两个单链表是否相交
找到两个单链表的尾部，如果相交，尾部一定相同  
- 求两个单链表相交的第一个节点
对第一个链表遍历，计算长度len1，同时保存最后一个节点的地址。对第二个链表遍历，计算长度len2，同时检查最后一个节点是否和第一个链表的最后一个节点相同，若不相同，不相交，结束。两个链表均从头节点开始，假设len1大于len2，那么将第一个链表先遍历len1-len2个节点，此时两个链表当前节点到第一个相交节点的距离就相等了，然后一起向后遍历，知道两个节点的地址相同。 时间复杂度，O(len1+len2)
- 已知一个单链表中存在环，求进入环中的第一个节点
首先判断是否存在环，若不存在结束。
1. 在环中的一个节点处断开（当然函数结束时不能破坏原链表），这样就形成了两个相交的单链表，求进入环中的第一个节点也就转换成了求两个单链表相交的第一个节点
2. 当找到上面的快慢的点时，再从head开始，让快慢交点和head每次前进一个，相交点就是入口点

### 查找

### 排序

### 树
#### 二叉查找树(BST)
#### AVL树(二叉平衡树)
#### 伸展树
#### 红黑树
#### B树
#### B+树
