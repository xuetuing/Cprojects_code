#include <stdio.h> 
#include <winsock2.h> 
#include <time.h> 
#define iPort 80//目标Web Server端口 
#define szSign "500 13\r\nServer: Microsoft-IIS/5.0"//根据此标志来检查目标是否有漏洞 
#pragma comment(lib,"ws2_32.lib") 
/////////////////////////////////////////////////////////////////////////// 
// 
//定义&初始化全局变量 
char *SendBuff="GET /NULL.printer\n",//发送的请求buff 
CurrentTarget[52]={0},//存放最后一个线程将扫描的目标 
turn[4][2]={"-","显示进度时的字符"}; 
int SendBuffLen=strlen(SendBuff),//发送的buff长度 
iConnTimeout,//TCP Connect TimeOut 
ii=0,//扫描进度 
　　　 iTotal;//服务器总数 
HANDLE hSemaphore=NULL,//信标内核对象句柄，用来控制线程数量 
　　　　　　 hStdout;//console标准输出句柄，做进度显示的时候用的 
struct timeval　timeout;//连接、发送和接收的超时值 
DWORD SleepTime;//每个一个线程后等待的时间 
　　　 /* 
SleepTime值根据用户输入的线程数量[ThreadNum]和TCP ConnectTimeOut[ConNTIMEO]来计算。确保在ConNTIMEO时间左右开ThreadNum个线程。这样在ConNTIMEO时间后，所开的线程开始陆续超时退出，可以继续稳定的开线程，可以有效的保证同时有ThreadNum个线程在运行。
*/ 
/////////////////////////////////////////////////////////////////////////// 
void ShowError(char *);//显示出错信息函数
BOOL ResetCursor(void);//重置光标位置，线程输出的时候调用的 
DWORD WINAPI ShowProInfo(LPVOID);//显示进度信息 
DWORD WINAPI scan(LPVOID);//扫描函数 
void usage(char *);//帮助函数 
/////////////////////////////////////////////////////////////////////////// 
int main(int argc,char **argv) 
{ 
　　　 HANDLE hThread=NULL;//线程句柄 
　　　 DWORD dwThreadID;//线程ID 
　　　 struct sockaddr_in sa; 
　　　 int i, 
　　　　　　 MaxThread;//最大线程数量 
　　　 WSADATA　　　 wsd; 
　　　 long PreviousCount; 
　　　 clock_t start,end;//程序运行的起始和结束时间 
　　　 double duration; 
　　　 //检查用户输入参数 
　　　 if(argc!=5) 
　　　 { 
　　　　　　 usage(argv[0]); 
　　　　　　 return 1; 
　　　 } 
　　　 //get target range 
　　　 int StartNet=inet_addr(argv[1]); 
　　　 int StopNet=inet_addr(argv[2]); 
　　　 int StartHost=ntohl(StartNet); 
　　　 int StopHost=ntohl(StopNet); 
　　　 //取得线程数量 
　　　 MaxThread=atoi(argv[3]); 
　　　 //取得conn超时时间 
　　　 iConnTimeout=atoi(argv[4]); 
　　　 //检查参数合法性 
　　　 if((iConnTimeout>6) || (iConnTimeout<2) || (MaxThread<1) || (MaxThread>500) || (StopHost<StartHost)) 
　　　 { 
　　　　　　 usage(argv[0]); 
　　　　　　 return 1; 
　　　 } 
　　　 //计算时间 
　　　 SleepTime=1000*iConnTimeout/MaxThread; 
　　　 //设置连接超时值 
　　　 timeout.tv_sec = iConnTimeout; 
　　　 timeout.tv_usec =0; 
　　　 __try 
　　　 { 
　　　　　　 //开始计时 
　　　　　　 start=clock(); 
　　　　　　 //加载winsock库 
　　　　　　 if (WSAStartup(MAKEWORD(1,1), &wsd) != 0) 
　　　　　　 { 
　　　　　　 　　　 ShowError("WSAStartup"); 
　　　　　　 　　　 __leave; 
　　　　　　 } 
　　　　　　 //创建信标内核对象句柄 
　　　　　　 hSemaphore=CreateSemaphore(NULL,MaxThread,MaxThread,NULL); 
　　　　　　 if(hSemaphore==NULL) 
　　　　　　 { 
　　　　　　 　　　 ShowError("CreateSemaphore"); 
　　　　　　 　　　 __leave; 
　　　　　　 } 
　　　　　　 //取得console标准输出句柄 
　　　　　　 hStdout=GetStdHandle(STD_OUTPUT_HANDLE); 
　　　　　　 if(hStdout==INVALID_HANDLE_VALUE) 
　　　　　　 { 
　　　　　　 　　　 ShowError("GetStdHandle"); 
　　　　　　 　　　 __leave; 
　　　　　　 } 
　　　　　　 //设置目标总数 
　　　　　　 iTotal=StopHost-StartHost; 
　　　　　　 //创建进度显示线程 
　　　　　　 hThread=CreateThread(NULL,0,ShowProInfo,NULL,0,&dwThreadID); 
　　　　　　 if(hThread==NULL) 
　　　　　　 { 
　　　　　　 　　　 ShowError("1 CreateThread"); 
　　　　　　 　　　 __leave; 
　　　　　　 } 
//关闭句柄 
　　　　　　 CloseHandle(hThread); 
　　　　　　 //循环创建扫描线程 
　　　　　　 for(i=StartHost;i<=StopHost;i++) 
　　　　　　 { 
　　　　　　　　　　 //等待信标内核对象通知 
　　　　　　 　　　 WaitForSingleObject(hSemaphore,INFINITE); 
　　　　　　 　　　 //create thread to scan 
　　　　　　 　　　 hThread=CreateThread(NULL,0,scan,(LPVOID)i,0,&dwThreadID); 
　　　　　　 　　　 if(hThread==NULL) 
　　　　　　　　　　 { 
　　　　　　　　　 　　　 ShowError("2 CreateThread"); 
　　　　　　　　　　　　　 break; 
　　　　　　　　　　 } 
　　　　　　　　　　 //进度自加1 
　　　　　　 　　　 ii++; 
　　　　　　　　　　 //重设最后一个线程扫描的目标 
　　　　　　 　　　 sa.sin_addr.s_addr=htonl(i); 
　　　　　　 　　　 strncpy(CurrentTarget,inet_ntoa(sa.sin_addr),sizeof(CurrentTarget)); 
　　　　　　　　　 //休息一会儿 ) 
　　　　　　 　　　 Sleep(SleepTime); 
　　　　　　　　　　 //关闭线程句柄 
　　　　　　 　　　 CloseHandle(hThread); 
　　　　　　 } 
　　　　　　 //等待所有线程结束 
　　　　　　 while(1) 
　　　　　　 { 
　　　　　　 　　　 WaitForSingleObject(hSemaphore,INFINITE); 
　　　　　　 　　　 if(!ReleaseSemaphore(hSemaphore,1,&PreviousCount)) 
　　　　　　　　　　 { 
　　　　　　　　　　　　　 ShowError("main() ReleaseSemaphore"); 
　　　　　　　　　　　　　 Sleep(5000); 
　　　　　　　　　　　　　 break; 
　　　　　　　　　　 } 
　　　　　　 　　　 if(PreviousCount==(MaxThread-1)) 
　　　　　　 　　　 { 
　　　　　　　　　　　　　 printf("\nAll done."); 
　　　　　　　　　　　　　 break; 
　　　　　　　　　　 } 
　　　　　　 　　　 Sleep(500); 
　　　　　　 } 
　　　 }//end of try 
　　　 //搞定，清场，收工 
　　　 __finally 
　　　 { 
　　　　　　 //计时结束 
　　　　　　 end=clock(); 
　　　　　　 //转换时间格式 
　　　　　　 duration = (double)(end - start) / CLOCKS_PER_SEC; 
　　　　　　 //显示所用时间 
　　　　　　 printf("\n\nComplete.Scan %d targets use %2.1f seconds.Speed %0.3g/s\n",iTotal,duration,iTotal/duration); 
　　　　　　 //关闭句柄 
　　　　　　 CloseHandle(hStdout); 
　　　　　　 CloseHandle(hSemaphore); 
　　　　　　 WSACleanup(); 
　　　 } 
　　　 return 0; 
} 
/////////////////////////////////////////////////////////////////////////// 
// 
//回显错误信息函数 
// 
void ShowError(char *msg) 
{ 
　　　 MessageBox(NULL,msg,"ERROR",0); 
　　　 //printf("\n%s failed:%d",GetLastError()); 
} 
////////////////////////////////////////////////////////////////////////// 
// 
//重置光标位置函数，以便扫描线程输出结果 
// 
BOOL ResetCursor() 
{ 
　　　 ConSOLE_SCREEN_BUFFER_INFO ConsoleScreenBufferInfo; 
　　　 //取得当前光标位置 
　　　 if(!GetConsoleScreenBufferInfo(hStdout,&ConsoleScreenBufferInfo)) 
　　　 { 
　　　　　　 ShowError("GetConsoleScreenBufferInfo"); 
　　　　　　 return FALSE; 
　　　 } 
　　　 //设置光标X坐标为0 
　　　 ConsoleScreenBufferInfo.dwCursorPosition.X=0; 
　　　 //设置当前光标位置 
　　　 SetConsoleCursorPosition(hStdout,ConsoleScreenBufferInfo.dwCursorPosition); 
　　　 return TRUE; 
} 
/////////////////////////////////////////////////////////////////////////// 
// 
//显示进度信息函数 
// 
DWORD WINAPI ShowProInfo(LPVOID lp) 
{　　 
　　　 int j,k; 
　　　 ConSOLE_SCREEN_BUFFER_INFO ConsoleScreenBufferInfo; 
　　　 float m; 
　　　 for(j=0;ii<iTotal;j++) 
　　　 { 
　　　　　　 //休息一会儿 )) 
　　　　　　 Sleep(SleepTime); 
　　　　　　 //取得当前光标位置 
　　　　　　 if(!GetConsoleScreenBufferInfo(hStdout,&ConsoleScreenBufferInfo)) 
　　　　　　 { 
　　　　　　 　　　 ShowError("GetConsoleScreenBufferInfo"); 
　　　　　　 　　　 return 1; 
　　　　　　 } 
　　　　　　 //设置百分比进度显示的X坐标 
　　　　　　 ConsoleScreenBufferInfo.dwCursorPosition.X=0; 
　　　　　　 //设置当前光标位置 
　　　　　　 SetConsoleCursorPosition(hStdout,ConsoleScreenBufferInfo.dwCursorPosition); 
　　　　　　 //已经完成的百分比 
　　　　　　 m=(ii+1)*100.00/iTotal; 
　　　　　　 //显示进度 
　　　　　　 if(ii==iTotal) 
　　　　　　 { 
　　　　　　 　　　 printf("******** 100%% Wait %d seconds to exit ********　 　　　　 \n",iConnTimeout); 
　　　　　　 　　　 break; 
　　　　　　 } 
　　　　　　 else 
　　　　　　 { 
　　　　　　 　　　 k=j%4; 
　　　　　　 　　　 printf("%-15s %s [%d/%d] %s %%%0.3g",CurrentTarget,turn[k],ii,iTotal,turn[k],m); 
　　　　　　 } 
　　　 }//end of for 
　　　 return 0; 
} 
/////////////////////////////////////////////////////////////////////////// 
// 
//扫描函数 
// 
DWORD WINAPI scan(LPVOID lp) 
{ 
　　　 int i=(int)lp,iErr; 
　　　 struct sockaddr_in server; 
　　　 SOCKET s=INVALID_SOCKET; 
　　　 char RecvBuff[1024]={0},*ptr; 
　　　 int RecvBuffLen=sizeof(RecvBuff); 
　　　 u_long ul=1;//初始化为为非0值 
　　fd_set　r,w; 
　　　 //create socket 
　　　 s=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); 
　　　 if(s==INVALID_SOCKET) 
　　　 { 
　　　　　　 printf("\nCreate socket failed:%d",GetLastError()); 
　　　　　　 ExitProcess(1); 
　　　 } 
　　　 //fill the addr struct 
　　　 server.sin_family=AF_INET; 
　　　 server.sin_port=htons(iPort); 
　　　 server.sin_addr.S_un.S_addr=htonl(i); 
　　　 __try 
　　　 { 
　　　　　　 //设置socket为非锁定模式,ul为0值的话，那么soocket将被设置为锁定模式 
　　　　　　 iErr=ioctlsocket(s,FIonBIO,(unsigned long*)&ul); 
　　　　　　 if(iErr==SOCKET_ERROR ) 
　　　　　　 { 
　　　　　　 　　　 ResetCursor(); 
　　　　　　 　　　 ShowError("ioctlsocket"); 
　　　　　　 　　　 ExitProcess(1); 
　　　　　　 } 
　　　　　　 //printf("\n%X ioctl ok.strat conn",i); 
　　　　　　 //connect to target 
　　　　　　 connect(s,(struct sockaddr *)&server,sizeof(server)); 
　　　　　　 //printf("\n%X conn return,start select w",i); 
　　　　　　 //设置select参数 
　　　　　　 FD_ZERO(&w); 
　　　　　　 FD_SET(s, &w); 
　　　　　　 //等待connect成功&socket可写 
　　　　　　 iErr=select(0, 0, &w, 0, &timeout); 
　　　　　　 //printf("\n%X select w return %d",i,iErr); 
　　　　　　 //等待返回后，socket仍不可写则退出 
　　　　　　 if((iErr==SOCKET_ERROR) || (iErr==0)) 
　　　　　　 { 
　　　　　　 　　　 //printf("\n%X select return w err,exit",i); 
　　　　　　 　　　 __leave; 
　　　　　　 } 
　　　　　　 //socket可写则继续 
　　　　　　 else 
　　　　　　 { 
　　　　　　 　　　 //send buff to target 
　　　　　　 　　　 //printf("\n%X send",i); 
　　　　　　 　　　 iErr=send(s,SendBuff,SendBuffLen,0); 
　　　　　　 　　　 //printf("\n%X send return",i); 
　　　　　　 　　　 if(iErr==SOCKET_ERROR) 
　　　　　　　　　　　　　 __leave; 
　　　　　　 } 
　　　　　　 //等待socket可读 
　　　　　　 FD_ZERO(&r); 
　　　　　　 FD_SET(s, &r); 
　　　　　　 //printf("\n%X start select r",i); 
　　　　　　 iErr=select(0, &r, 0, 0, &timeout); 
　　　　　　 //printf("\n%X select r return %d",i,iErr); 
　　　　　　 if((iErr==SOCKET_ERROR) || (iErr==0)) 
　　　　　　 { 
　　　　　　 　　　 //printf("\n%X select r err,exit",i); 
　　　　　　 　　　 __leave; 
　　　　　　 } 
　　　　　　 else 
　　　　　　 { 
　　　　　　 　　　 //recv buff from target 
　　　　　　 　　　 //printf("\n%X start recv",i); 
　　　　　　 　　　 iErr=recv(s,RecvBuff,RecvBuffLen,0); 
　　　　　　 　　　 //printf("\n%X recv ret",i); 
　　　　　　 　　　 if(iErr==SOCKET_ERROR) 
　　　　　　　　　　　　　 __leave; 
　　　　　　 } 
　　　　　　 //verify buff 
　　　　　　 ptr=strstr(RecvBuff,szSign); 
　　　　　　 if(ptr!=NULL) 
　　　　　　 { 
　　　　　　　　　　 //线程输出前要先调用ResetCursor函数 
　　　　　　 　　　 ResetCursor(); 
　　　　　　　　　　 //输出信息后务必加一个以上换行符号，输出前请别加换行符号，以免显示混乱 
　　　　　　 　　　 printf("[%-15s] has .printer mapped.　　　　　　　 \n",inet_ntoa(server.sin_addr)); 
　　　　　　 } 
　　　 } 
　　　 __finally 
　　　 { 
　　　　　　 if(!ReleaseSemaphore(hSemaphore,1,NULL)) 
　　　　　　 　　　 ShowError("thread ReleaseSemaphore failed"); 
　　　　　　 closesocket(s); 
　　　 } 
　　　 return 0; 
} 
/////////////////////////////////////////////////////////////////////////// 
void usage(char *proname) 
{ 
　　　 printf("\n%s v0.1 only can find IIS5 .Printer mapped" 
　　　　　　 "\nPower by ey4s<> 2001.5.20" 
　　　　　　 "\nhttp://www.patching.net" 
　　　　　　 "\n\nUsage:%s <StartIP> <EndIP> <ThreadNum> <ConNTIMEO>" 
　　　　　　 "\n\nNotice" 
　　　　　　 "\n　　　　StartIP StopIP ==>Don‘t forgot StopIP must large than StartIP " 
　　　　　　 "\n　　　　ThreadNum ==>Thread number,please input between 1-500" 
　　　　　　 "\n　　　　ConNTIMEO ==>TCP connect timeout,please input between 2-6" 
　　　　　　 "\n\nExample" 
　　　　　　 "\n　　　　%s 192.168.0.0 192.168.255.255 200 2",proname,proname,proname); 
}
