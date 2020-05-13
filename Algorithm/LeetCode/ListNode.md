  ### 解题思路
  **相交的情况**
  - (在不循环的情况下)相交的结点的地址肯定是相等的,且都在链表的后半段
  - 我们把两条单链表的结点分别压入栈中
  - 则相交的结点肯定都在靠近栈顶的部分
  - 一边进行判断,一边进行出栈,当不满足相等条件的时候说明已经不再是相交部分了。


  ![image.png](https://pic.leetcode-cn.com/95c75803026ed484848f99bc9b3eec182b4f7065325ff3c247d66e84f9cc32a4-image.png)
  **不相交的情况**
  - 当两个链表没有交点的时候说明没有相等的结点地址


  ```cpp
  /***
  *Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */
   class Solution {
     public:
       ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         if(headA==nullptr  || headB==nullptr ){
           return nullptr;

         }

         ListNode* nextA=headA;
         ListNode* nextB=headB;



         while(nextA!=nullptr || nextB!=nullptr){
           if(nextA!=nullptr){
             s1.push(nextA);
             nextA=nextA->next;

           }

           if(nextB!=nullptr){
             s2.push(nextB);
             nextB=nextB->next;

           }

         }

         ListNode* ret=nullptr;
         while(!s1.empty() && !s2.empty()){

           if(s1.top()==s2.top()){
             ret=s1.top();
             s1.pop();
             s2.pop();

           }else{
             break;

           }

         }

         return ret;


       }

     private:
       stack<ListNode*> s1;
       stack<ListNode*> s2;

   };
   ```
