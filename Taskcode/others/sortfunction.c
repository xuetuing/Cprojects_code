struct ListNode {

  int val;

  ListNode *next;

  ListNode(int x) : val(x), next(NULL) {}

  };

//插入排序法：交换结点
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL || head->next == NULL)return head;
        ListNode *p = head->next, *pstart = new ListNode(0), *pend = head;
        pstart->next = head; //为了操作方便，添加一个头结点
        while(p != NULL)
        {
            ListNode *tmp = pstart->next, *pre = pstart;
            while(tmp != p && p->val >= tmp->val) //找到插入位置
                {tmp = tmp->next; pre = pre->next;}
            if(tmp == p)pend = p;
            else
            {
                pend->next = p->next;
                p->next = tmp;
                pre->next = p;
            }
            p = pend->next;
        }
        head = pstart->next;
        delete pstart;
        return head;
    }
};

//选择排序（只交换val值）
class Solution {
public:
    ListNode *selectSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //选择排序
        if(head == NULL || head->next == NULL)return head;
        ListNode *pstart = new ListNode(0);
        pstart->next = head; //为了操作方便，添加一个头结点
        ListNode*sortedTail = pstart;//指向已排好序的部分的尾部
        
        while(sortedTail->next != NULL)
        {
            ListNode*minNode = sortedTail->next, *p = sortedTail->next->next;
            //寻找未排序部分的最小节点
            while(p != NULL)
            {
                if(p->val < minNode->val)
                    minNode = p;
                p = p->next;
            }
            swap(minNode->val, sortedTail->next->val);
            sortedTail = sortedTail->next;
        }
        
        head = pstart->next;
        delete pstart;
        return head;
    }
};

//这里的partition我们参考数组快排partition的第二种写法(选取第一个元素作为枢纽元的版本，因为链表选择最后一元素需要遍历一遍)，
//具体可以参考here
//这里我们还需要注意的一点是数组的partition两个参数分别代表数组的起始位置，两边都是闭区间，这样在排序的主函数中：
void quicksort(vector<int>&arr, int low, int high)
{
  if(low < high)
  {
   int middle = mypartition(arr, low, high);
   quicksort(arr, low, middle-1);
   quicksort(arr, middle+1, high);

  }
}
//对左边子数组排序时，子数组右边界是middle-1，如果链表也按这种两边都是闭区间的话，找到分割后枢纽元middle，找到middle-1还得再
//次遍历数组，因此链表的partition采用前闭后开的区间（这样排序主函数也需要前闭后开区间），这样就可以避免上述问题
//快速排序（只交换val值）
class Solution {
public:
    ListNode *quickSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //链表快速排序
        if(head == NULL || head->next == NULL)return head;
        qsortList(head, NULL);
        return head;
    }
    void qsortList(ListNode*head, ListNode*tail)
    {
        //链表范围是[low, high)
        if(head != tail && head->next != tail)
        {
            ListNode* mid = partitionList(head, tail);
            qsortList(head, mid);
            qsortList(mid->next, tail);
        }
    }
    ListNode* partitionList(ListNode*low, ListNode*high)
    {
        //链表范围是[low, high)
        int key = low->val;
        ListNode* loc = low;
        for(ListNode*i = low->next; i != high; i = i->next)
            if(i->val < key)
            {
                loc = loc->next;
                swap(i->val, loc->val);
            }
        swap(loc->val, low->val);
        return loc;
    }
};
//快速排序2：交换结点
//这里的partition，我们选取第一个节点作为枢纽元，然后把小于枢纽的节点放到一个链中，把不小于枢纽的及节点放到另一个链中，最后把两条链
//以及枢纽连接成一条链。这里我们需要注意的是，1.在对一条子链进行partition时，由于节点的顺序都打乱了，所以得保正重新组合成一条新链表时，
//要和该子链表的前后部分连接起来，因此我们的partition传入三个参数，除了子链表的范围（也是前闭后开区间），还要传入子链表头结点的前驱
//2.partition后链表的头结点可能已经改变
class Solution {
public:
    ListNode *quickSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //链表快速排序
        if(head == NULL || head->next == NULL)return head;
        ListNode tmpHead(0); tmpHead.next = head;
        qsortList(&tmpHead, head, NULL);
        return tmpHead.next;
    }
    void qsortList(ListNode *headPre, ListNode*head, ListNode*tail)
    {
        //链表范围是[low, high)
        if(head != tail && head->next != tail)
        {
            ListNode* mid = partitionList(headPre, head, tail);//注意这里head可能不再指向链表头了
            qsortList(headPre, headPre->next, mid);
            qsortList(mid, mid->next, tail);
        }
    }
    ListNode* partitionList(ListNode* lowPre, ListNode* low, ListNode* high)
    {
        //链表范围是[low, high)
        int key = low->val;
        ListNode node1(0), node2(0);//比key小的链的头结点，比key大的链的头结点
        ListNode* little = &node1, *big = &node2;
        for(ListNode*i = low->next; i != high; i = i->next)
            if(i->val < key)
            {
                little->next = i;
                little = i;
            }
            else
            {
                big->next = i;
                big = i;
            }
        big->next = high;//保证子链表[low,high)和后面的部分连接
        little->next = low;
        low->next = node2.next;
        lowPre->next = node1.next;//为了保证子链表[low,high)和前面的部分连接
        return low;
    }
};
//归并排序：交换结点
//首先用快慢指针的方法找到链表中间节点，然后递归的对两个子链表排序，把两个排好序的子链表合并成一条有序的链表。归并排序应该算是链
//表排序最佳的选择了，保证了最好和最坏时间复杂度都是nlogn，而且它在数组排序中广受诟病的空间复杂度在链表排序中也从O(n)降到了O(1)
class Solution {
public:
    ListNode *mergeSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //链表归并排序
        if(head == NULL || head->next == NULL)return head;
        else
        {
            //快慢指针找到中间节点
            ListNode *fast = head,*slow = head;
            while(fast->next != NULL && fast->next->next != NULL)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            fast = slow;
            slow = slow->next;
            fast->next = NULL;
            fast = sortList(head);//前半段排序
            slow = sortList(slow);//后半段排序
            return merge(fast,slow);
        }
         
    }
    // merge two sorted list to one
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        if(head1 == NULL)return head2;
        if(head2 == NULL)return head1;
        ListNode *res , *p ;
        if(head1->val < head2->val)
            {res = head1; head1 = head1->next;}
        else{res = head2; head2 = head2->next;}
        p = res;
         
        while(head1 != NULL && head2 != NULL)
        {
            if(head1->val < head2->val)
            {
                p->next = head1;
                head1 = head1->next;
            }
            else
            {
                p->next = head2;
                head2 = head2->next;
            }
            p = p->next;
        }
        if(head1 != NULL)p->next = head1;
        else if(head2 != NULL)p->next = head2;
        return res;
    }
};
//冒泡排序：交换值
class Solution {
public:
    ListNode *bubbleSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //链表快速排序
        if(head == NULL || head->next == NULL)return head;
        ListNode *p = NULL;
        bool isChange = true;
        while(p != head->next && isChange)
        {
            ListNode *q = head;
            isChange = false;//标志当前这一轮中又没有发生元素交换，如果没有则表示数组已经有序
            for(; q->next && q->next != p; q = q->next)
            {
                if(q->val > q->next->val)
                {
                    swap(q->val, q->next->val);
                    isChange = true;
                }
            }
            p = q;
        }
        return head;
    }
};
// 冒泡排序交换结点
int pop_sort(Node *head)   //链表冒泡排序，节点交换法（还有换值法）；传入头节点指针   
{                           //排序中没有修改头节点指针值，只是修改指针内容head->next的值   
    Node *pre,*p,*tail,*temp;  
    tail=NULL;  
    pre=head;  
      
    while((head->next->next)!=tail)//(head->next)!=tail同样适用 ，多执行最后一个步比较   
    {  
        p=head->next;  
        pre=head;  
        while(p->next!=tail)  
        {  
            if((p->data)>(p->next->data))  
            {  
            /*  pre->next=p->next; //交换节点方法一 
                p->next = p->next->next; 
                pre->next->next = p; 
                p = pre->next; */  
                  
                pre->next=p->next; //交换节点方法二   
                temp=p->next->next;  
                p->next->next=p;  
                p->next=temp;  
                p=pre->next;  //p回退一个节点   
                  
            }  
            p=p->next;  //p再前进一个节点   
            pre=pre->next;     
        }  
        tail=p;  
    }  
    return 0 ;  
}  