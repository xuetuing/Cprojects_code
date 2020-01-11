struct ListNode {

  int val;

  ListNode *next;

  ListNode(int x) : val(x), next(NULL) {}

  };

//�������򷨣��������
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL || head->next == NULL)return head;
        ListNode *p = head->next, *pstart = new ListNode(0), *pend = head;
        pstart->next = head; //Ϊ�˲������㣬���һ��ͷ���
        while(p != NULL)
        {
            ListNode *tmp = pstart->next, *pre = pstart;
            while(tmp != p && p->val >= tmp->val) //�ҵ�����λ��
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

//ѡ������ֻ����valֵ��
class Solution {
public:
    ListNode *selectSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //ѡ������
        if(head == NULL || head->next == NULL)return head;
        ListNode *pstart = new ListNode(0);
        pstart->next = head; //Ϊ�˲������㣬���һ��ͷ���
        ListNode*sortedTail = pstart;//ָ�����ź���Ĳ��ֵ�β��
        
        while(sortedTail->next != NULL)
        {
            ListNode*minNode = sortedTail->next, *p = sortedTail->next->next;
            //Ѱ��δ���򲿷ֵ���С�ڵ�
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

//�����partition���ǲο��������partition�ĵڶ���д��(ѡȡ��һ��Ԫ����Ϊ��ŦԪ�İ汾����Ϊ����ѡ�����һԪ����Ҫ����һ��)��
//������Բο�here
//�������ǻ���Ҫע���һ���������partition���������ֱ�����������ʼλ�ã����߶��Ǳ����䣬������������������У�
void quicksort(vector<int>&arr, int low, int high)
{
  if(low < high)
  {
   int middle = mypartition(arr, low, high);
   quicksort(arr, low, middle-1);
   quicksort(arr, middle+1, high);

  }
}
//���������������ʱ���������ұ߽���middle-1���������Ҳ���������߶��Ǳ�����Ļ����ҵ��ָ����ŦԪmiddle���ҵ�middle-1������
//�α������飬��������partition����ǰ�պ󿪵����䣨��������������Ҳ��Ҫǰ�պ����䣩�������Ϳ��Ա�����������
//��������ֻ����valֵ��
class Solution {
public:
    ListNode *quickSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //�����������
        if(head == NULL || head->next == NULL)return head;
        qsortList(head, NULL);
        return head;
    }
    void qsortList(ListNode*head, ListNode*tail)
    {
        //����Χ��[low, high)
        if(head != tail && head->next != tail)
        {
            ListNode* mid = partitionList(head, tail);
            qsortList(head, mid);
            qsortList(mid->next, tail);
        }
    }
    ListNode* partitionList(ListNode*low, ListNode*high)
    {
        //����Χ��[low, high)
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
//��������2���������
//�����partition������ѡȡ��һ���ڵ���Ϊ��ŦԪ��Ȼ���С����Ŧ�Ľڵ�ŵ�һ�����У��Ѳ�С����Ŧ�ļ��ڵ�ŵ���һ�����У�����������
//�Լ���Ŧ���ӳ�һ����������������Ҫע����ǣ�1.�ڶ�һ����������partitionʱ�����ڽڵ��˳�򶼴����ˣ����Եñ���������ϳ�һ��������ʱ��
//Ҫ�͸��������ǰ�󲿷�����������������ǵ�partition������������������������ķ�Χ��Ҳ��ǰ�պ����䣩����Ҫ����������ͷ����ǰ��
//2.partition�������ͷ�������Ѿ��ı�
class Solution {
public:
    ListNode *quickSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //�����������
        if(head == NULL || head->next == NULL)return head;
        ListNode tmpHead(0); tmpHead.next = head;
        qsortList(&tmpHead, head, NULL);
        return tmpHead.next;
    }
    void qsortList(ListNode *headPre, ListNode*head, ListNode*tail)
    {
        //����Χ��[low, high)
        if(head != tail && head->next != tail)
        {
            ListNode* mid = partitionList(headPre, head, tail);//ע������head���ܲ���ָ������ͷ��
            qsortList(headPre, headPre->next, mid);
            qsortList(mid, mid->next, tail);
        }
    }
    ListNode* partitionList(ListNode* lowPre, ListNode* low, ListNode* high)
    {
        //����Χ��[low, high)
        int key = low->val;
        ListNode node1(0), node2(0);//��keyС������ͷ��㣬��key�������ͷ���
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
        big->next = high;//��֤������[low,high)�ͺ���Ĳ�������
        little->next = low;
        low->next = node2.next;
        lowPre->next = node1.next;//Ϊ�˱�֤������[low,high)��ǰ��Ĳ�������
        return low;
    }
};
//�鲢���򣺽������
//�����ÿ���ָ��ķ����ҵ������м�ڵ㣬Ȼ��ݹ�Ķ��������������򣬰������ź����������ϲ���һ������������鲢����Ӧ��������
//��������ѵ�ѡ���ˣ���֤����ú��ʱ�临�Ӷȶ���nlogn�������������������й���ڸ���Ŀռ临�Ӷ�������������Ҳ��O(n)������O(1)
class Solution {
public:
    ListNode *mergeSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //����鲢����
        if(head == NULL || head->next == NULL)return head;
        else
        {
            //����ָ���ҵ��м�ڵ�
            ListNode *fast = head,*slow = head;
            while(fast->next != NULL && fast->next->next != NULL)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            fast = slow;
            slow = slow->next;
            fast->next = NULL;
            fast = sortList(head);//ǰ�������
            slow = sortList(slow);//��������
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
//ð�����򣺽���ֵ
class Solution {
public:
    ListNode *bubbleSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //�����������
        if(head == NULL || head->next == NULL)return head;
        ListNode *p = NULL;
        bool isChange = true;
        while(p != head->next && isChange)
        {
            ListNode *q = head;
            isChange = false;//��־��ǰ��һ������û�з���Ԫ�ؽ��������û�����ʾ�����Ѿ�����
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
// ð�����򽻻����
int pop_sort(Node *head)   //����ð�����򣬽ڵ㽻���������л�ֵ����������ͷ�ڵ�ָ��   
{                           //������û���޸�ͷ�ڵ�ָ��ֵ��ֻ���޸�ָ������head->next��ֵ   
    Node *pre,*p,*tail,*temp;  
    tail=NULL;  
    pre=head;  
      
    while((head->next->next)!=tail)//(head->next)!=tailͬ������ ����ִ�����һ�����Ƚ�   
    {  
        p=head->next;  
        pre=head;  
        while(p->next!=tail)  
        {  
            if((p->data)>(p->next->data))  
            {  
            /*  pre->next=p->next; //�����ڵ㷽��һ 
                p->next = p->next->next; 
                pre->next->next = p; 
                p = pre->next; */  
                  
                pre->next=p->next; //�����ڵ㷽����   
                temp=p->next->next;  
                p->next->next=p;  
                p->next=temp;  
                p=pre->next;  //p����һ���ڵ�   
                  
            }  
            p=p->next;  //p��ǰ��һ���ڵ�   
            pre=pre->next;     
        }  
        tail=p;  
    }  
    return 0 ;  
}  