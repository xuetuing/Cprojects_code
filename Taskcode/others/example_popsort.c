#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct listnode {
	int n;
	struct listnode *next;
};

int pop_sort(struct listnode *head);
void main()
{
	int i =0;
	struct listnode *q,*head = NULL,*tail=NULL;
	head = (struct listnode*)malloc(sizeof(struct listnode));
	tail = head;
	tail->next = NULL;
	for(
		;i<=5;i++)
	{
		struct listnode *p = NULL;
		p = (struct listnode *)malloc(sizeof(struct listnode));
		if(NULL == p)
			perror("ERROR\n");
		printf("输入数字：");
		scanf("%d",&(p->n)); //数值写法
		tail->next = p;
		p->next = NULL;
		tail = p;
	};
	pop_sort(head);
	q = head->next;
	while(q != NULL)
	{	
		printf("%d ",q->n);
		q = q->next;
	};
};

int pop_sort(struct listnode *head)   //链表冒泡排序，节点交换法（还有换值法）；传入头节点指针   
{                           //排序中没有修改头节点指针值，只是修改指针内容head->next的值   
    struct listnode *pre,*p,*tail,*temp;  
    tail=NULL;  
    pre=head;  
      
    while((head->next->next)!=tail)//(head->next)!=tail同样适用 ，多执行最后一个步比较   
    {  
        p=head->next;  
        pre=head;  
        while(p->next!=tail)  
        {  
            if((p->n)>(p->next->n))  
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