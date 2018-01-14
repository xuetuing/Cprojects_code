struct icmp{
     unsigned char type; //类型
	 unsigned char code; //代码
	      unsigned short checksum; //校验和
          unsigned short id; //标识码
          unsigned short sequence; //序号
		  struct timeval timestamp; //时间戳
};   //ICMP报文实现

struct ip{
	unsigned char version:4;  //版本
	unsigned char hlen:4;  //首部长度
	unsigned char tos;  //服务类型
    unsigned short len;  //总长度
	unsigned short id;  //标识符
	unsigned short offset;  //标志和片偏移
    unsigned char ttl;  //生存时间
	unsigned char protocol;  //协议
	unsigned short checksum;  //校验和
    struct in_addr ipsrc;  //32位源ip地址
	struct in_addr ipdst;  //32位目的ip地址
};    //IP报文首部实现

//地址信息表示：地址族，IP，端口号
struct sockaddr_in{

    sa_family_t  sin_family;        //地址族
	uint16_t     sin_port;          //端口号
	struct in_addr  sin_addr;  //32位IP地址
	char         sin_zero[8];       //不使用
};  // 地址信息

struct in_addr{
    in_addr_t    s_addr;          //32位IP地址
};                                               #define in_addr_t  uint32_t



//  struct sockaddr{
//          sa_family_t    sin_family;
//         char          sa_data[14]; }; //也可表示地址信息的结构体

//不同CPU保存4字节整形数值1的方式不同（正倒序）
转换字节序的函数有：
unsigned short  htons(unsigned short);
unsigned short  htons(unsigned short);
unsigned long   htons(unsigned long);
unsigned long   htons(unsigned long);


//函数介绍：
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
//实例
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
//inet_addr函数  该函数的作用是将用点分十进制字符串格式表示的IP地址转换成32位大端序整型。
#include<arpa/inet.h>
in_addt_t inet_addt(const char *string);

//实例
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

//inet_ntoa函数  该函数的作用与inet_addr正好相反。将32位大端序整型格式IP地址转换为点分十进制格式。

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

//gethostbyname函数

#include <netdb.h>
struct hostent * gethostbyname(const char * hostname);

truct hostent{
    char *          h_name;
    char **     h_aliases;
    char         h_addrtype;
    char         h_length;
    char **     h_addr_list;
};
//实例

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
