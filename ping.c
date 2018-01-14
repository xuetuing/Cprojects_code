struct icmp{
     unsigned char type; //����
	 unsigned char code; //����
	      unsigned short checksum; //У���
          unsigned short id; //��ʶ��
          unsigned short sequence; //���
		  struct timeval timestamp; //ʱ���
};   //ICMP����ʵ��

struct ip{
	unsigned char version:4;  //�汾
	unsigned char hlen:4;  //�ײ�����
	unsigned char tos;  //��������
    unsigned short len;  //�ܳ���
	unsigned short id;  //��ʶ��
	unsigned short offset;  //��־��Ƭƫ��
    unsigned char ttl;  //����ʱ��
	unsigned char protocol;  //Э��
	unsigned short checksum;  //У���
    struct in_addr ipsrc;  //32λԴip��ַ
	struct in_addr ipdst;  //32λĿ��ip��ַ
};    //IP�����ײ�ʵ��

//��ַ��Ϣ��ʾ����ַ�壬IP���˿ں�
struct sockaddr_in{

    sa_family_t  sin_family;        //��ַ��
	uint16_t     sin_port;          //�˿ں�
	struct in_addr  sin_addr;  //32λIP��ַ
	char         sin_zero[8];       //��ʹ��
};  // ��ַ��Ϣ

struct in_addr{
    in_addr_t    s_addr;          //32λIP��ַ
};                                               #define in_addr_t  uint32_t



//  struct sockaddr{
//          sa_family_t    sin_family;
//         char          sa_data[14]; }; //Ҳ�ɱ�ʾ��ַ��Ϣ�Ľṹ��

//��ͬCPU����4�ֽ�������ֵ1�ķ�ʽ��ͬ��������
ת���ֽ���ĺ����У�
unsigned short  htons(unsigned short);
unsigned short  htons(unsigned short);
unsigned long   htons(unsigned long);
unsigned long   htons(unsigned long);


//�������ܣ�
1. gettimeofday()
#include<sye/time.h>
int gettimeofday(struct timeval *tv,struct timezone *tz);

struct timeval
{
   long int tv_sec;
   long int tv_usec;
}
struct timezone
{
   int tz_minuteswest;
   int tz_dsttime;
}
//ʵ��
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/time.h>

float timediff(struct timeval *begin,struct timeval *end)
{
   int n;
   n=(end->tv_sec - begin->tv_sec)*1000000+(end->tv_usec-begin->tv_usec);
   return (float)(n/1000);
}

int main(void)
{
   struct timeval begin,end;
   gettimeofday(&begin,0);

   printf("do something here.....");
   sleep(1);
   gettimeofday(&end,0);
   printf("running time: %fms\n",timediff(&begin,&end));

   return 0;
}
//inet_addr����  �ú����������ǽ��õ��ʮ�����ַ�����ʽ��ʾ��IP��ַת����32λ��������͡�
#include<arpa/inet.h>
in_addt_t inet_addt(const char *string);

//ʵ��
#include<stdio.h>
#include<arpa/inet.h>

int main(void)
{
   char *addr1 ="1.2.3.4";
   char *addr2 ="192.168.1.1";
   int_addr_t data;
   
   data=inet_addr(addr1);
   printf("%s -> %#lx\n",addr1,(long)data);

   data=inet_addr(addr2);
   printf("%s -> %#lx\n",addr2,(long)data);

    return 0;
}

//inet_ntoa����  �ú�����������inet_addr�����෴����32λ��������͸�ʽIP��ַת��Ϊ���ʮ���Ƹ�ʽ��

#include <stdio.h>
#include <arpa/inet.h>

int main(void){
    struct in_addr addr1, addr2;
    char * str1, * str2;

    addr1.s_addr  = htonl(0x1020304);
    addr2.s_addr  = htonl(0xc0a80101);

    str1 = inet_ntoa(addr1);
    str2 = inet_ntoa(addr2);

    printf("%#lx -> %s \n", (long)addr1.s_addr, str1);
    printf("%#lx -> %s \n", (long)addr2.s_addr, str2);

    return 0;
}

//gethostbyname����

#include <netdb.h>
struct hostent * gethostbyname(const char * hostname);

truct hostent{
    char *          h_name;
    char **     h_aliases;
    char         h_addrtype;
    char         h_length;
    char **     h_addr_list;
};
//ʵ��

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]){
    int i;
    struct hostent *host;

    if(argc < 2){
        printf("Use : %s <hostname> \n", argv[0]);
        exit(1);
    }

    host = gethostbyname(argv[1]);
     for(i = 0; host->h_addr_list[i]; i++){
        printf("IP addr %d : %s \n", i+1,
                inet_ntoa(*(struct in_addr *)host->h_addr_list[i]));
    }

    return 0;
}
