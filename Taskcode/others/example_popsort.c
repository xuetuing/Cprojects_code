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
		printf("�������֣�");
		scanf("%d",&(p->n)); //��ֵд��
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

int pop_sort(struct listnode *head)   //����ð�����򣬽ڵ㽻���������л�ֵ����������ͷ�ڵ�ָ��   
{                           //������û���޸�ͷ�ڵ�ָ��ֵ��ֻ���޸�ָ������head->next��ֵ   
    struct listnode *pre,*p,*tail,*temp;  
    tail=NULL;  
    pre=head;  
      
    while((head->next->next)!=tail)//(head->next)!=tailͬ������ ����ִ�����һ�����Ƚ�   
    {  
        p=head->next;  
        pre=head;  
        while(p->next!=tail)  
        {  
            if((p->n)>(p->next->n))  
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