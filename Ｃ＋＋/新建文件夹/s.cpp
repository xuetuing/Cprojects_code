#include <stdio.h> 
#include <winsock2.h> 
#include <time.h> 
#define iPort 80//Ŀ��Web Server�˿� 
#define szSign "500 13\r\nServer: Microsoft-IIS/5.0"//���ݴ˱�־�����Ŀ���Ƿ���©�� 
#pragma comment(lib,"ws2_32.lib") 
/////////////////////////////////////////////////////////////////////////// 
// 
//����&��ʼ��ȫ�ֱ��� 
char *SendBuff="GET /NULL.printer\n",//���͵�����buff 
CurrentTarget[52]={0},//������һ���߳̽�ɨ���Ŀ�� 
turn[4][2]={"-","��ʾ����ʱ���ַ�"}; 
int SendBuffLen=strlen(SendBuff),//���͵�buff���� 
iConnTimeout,//TCP Connect TimeOut 
ii=0,//ɨ����� 
������ iTotal;//���������� 
HANDLE hSemaphore=NULL,//�ű��ں˶����������������߳����� 
������������ hStdout;//console��׼����������������ʾ��ʱ���õ� 
struct timeval��timeout;//���ӡ����ͺͽ��յĳ�ʱֵ 
DWORD SleepTime;//ÿ��һ���̺߳�ȴ���ʱ�� 
������ /* 
SleepTimeֵ�����û�������߳�����[ThreadNum]��TCP ConnectTimeOut[ConNTIMEO]�����㡣ȷ����ConNTIMEOʱ�����ҿ�ThreadNum���̡߳�������ConNTIMEOʱ����������߳̿�ʼ½����ʱ�˳������Լ����ȶ��Ŀ��̣߳�������Ч�ı�֤ͬʱ��ThreadNum���߳������С�
*/ 
/////////////////////////////////////////////////////////////////////////// 
void ShowError(char *);//��ʾ������Ϣ����
BOOL ResetCursor(void);//���ù��λ�ã��߳������ʱ����õ� 
DWORD WINAPI ShowProInfo(LPVOID);//��ʾ������Ϣ 
DWORD WINAPI scan(LPVOID);//ɨ�躯�� 
void usage(char *);//�������� 
/////////////////////////////////////////////////////////////////////////// 
int main(int argc,char **argv) 
{ 
������ HANDLE hThread=NULL;//�߳̾�� 
������ DWORD dwThreadID;//�߳�ID 
������ struct sockaddr_in sa; 
������ int i, 
������������ MaxThread;//����߳����� 
������ WSADATA������ wsd; 
������ long PreviousCount; 
������ clock_t start,end;//�������е���ʼ�ͽ���ʱ�� 
������ double duration; 
������ //����û�������� 
������ if(argc!=5) 
������ { 
������������ usage(argv[0]); 
������������ return 1; 
������ } 
������ //get target range 
������ int StartNet=inet_addr(argv[1]); 
������ int StopNet=inet_addr(argv[2]); 
������ int StartHost=ntohl(StartNet); 
������ int StopHost=ntohl(StopNet); 
������ //ȡ���߳����� 
������ MaxThread=atoi(argv[3]); 
������ //ȡ��conn��ʱʱ�� 
������ iConnTimeout=atoi(argv[4]); 
������ //�������Ϸ��� 
������ if((iConnTimeout>6) || (iConnTimeout<2) || (MaxThread<1) || (MaxThread>500) || (StopHost<StartHost)) 
������ { 
������������ usage(argv[0]); 
������������ return 1; 
������ } 
������ //����ʱ�� 
������ SleepTime=1000*iConnTimeout/MaxThread; 
������ //�������ӳ�ʱֵ 
������ timeout.tv_sec = iConnTimeout; 
������ timeout.tv_usec =0; 
������ __try 
������ { 
������������ //��ʼ��ʱ 
������������ start=clock(); 
������������ //����winsock�� 
������������ if (WSAStartup(MAKEWORD(1,1), &wsd) != 0) 
������������ { 
������������ ������ ShowError("WSAStartup"); 
������������ ������ __leave; 
������������ } 
������������ //�����ű��ں˶����� 
������������ hSemaphore=CreateSemaphore(NULL,MaxThread,MaxThread,NULL); 
������������ if(hSemaphore==NULL) 
������������ { 
������������ ������ ShowError("CreateSemaphore"); 
������������ ������ __leave; 
������������ } 
������������ //ȡ��console��׼������ 
������������ hStdout=GetStdHandle(STD_OUTPUT_HANDLE); 
������������ if(hStdout==INVALID_HANDLE_VALUE) 
������������ { 
������������ ������ ShowError("GetStdHandle"); 
������������ ������ __leave; 
������������ } 
������������ //����Ŀ������ 
������������ iTotal=StopHost-StartHost; 
������������ //����������ʾ�߳� 
������������ hThread=CreateThread(NULL,0,ShowProInfo,NULL,0,&dwThreadID); 
������������ if(hThread==NULL) 
������������ { 
������������ ������ ShowError("1 CreateThread"); 
������������ ������ __leave; 
������������ } 
//�رվ�� 
������������ CloseHandle(hThread); 
������������ //ѭ������ɨ���߳� 
������������ for(i=StartHost;i<=StopHost;i++) 
������������ { 
�������������������� //�ȴ��ű��ں˶���֪ͨ 
������������ ������ WaitForSingleObject(hSemaphore,INFINITE); 
������������ ������ //create thread to scan 
������������ ������ hThread=CreateThread(NULL,0,scan,(LPVOID)i,0,&dwThreadID); 
������������ ������ if(hThread==NULL) 
�������������������� { 
������������������ ������ ShowError("2 CreateThread"); 
�������������������������� break; 
�������������������� } 
�������������������� //�����Լ�1 
������������ ������ ii++; 
�������������������� //�������һ���߳�ɨ���Ŀ�� 
������������ ������ sa.sin_addr.s_addr=htonl(i); 
������������ ������ strncpy(CurrentTarget,inet_ntoa(sa.sin_addr),sizeof(CurrentTarget)); 
������������������ //��Ϣһ��� ) 
������������ ������ Sleep(SleepTime); 
�������������������� //�ر��߳̾�� 
������������ ������ CloseHandle(hThread); 
������������ } 
������������ //�ȴ������߳̽��� 
������������ while(1) 
������������ { 
������������ ������ WaitForSingleObject(hSemaphore,INFINITE); 
������������ ������ if(!ReleaseSemaphore(hSemaphore,1,&PreviousCount)) 
�������������������� { 
�������������������������� ShowError("main() ReleaseSemaphore"); 
�������������������������� Sleep(5000); 
�������������������������� break; 
�������������������� } 
������������ ������ if(PreviousCount==(MaxThread-1)) 
������������ ������ { 
�������������������������� printf("\nAll done."); 
�������������������������� break; 
�������������������� } 
������������ ������ Sleep(500); 
������������ } 
������ }//end of try 
������ //�㶨���峡���չ� 
������ __finally 
������ { 
������������ //��ʱ���� 
������������ end=clock(); 
������������ //ת��ʱ���ʽ 
������������ duration = (double)(end - start) / CLOCKS_PER_SEC; 
������������ //��ʾ����ʱ�� 
������������ printf("\n\nComplete.Scan %d targets use %2.1f seconds.Speed %0.3g/s\n",iTotal,duration,iTotal/duration); 
������������ //�رվ�� 
������������ CloseHandle(hStdout); 
������������ CloseHandle(hSemaphore); 
������������ WSACleanup(); 
������ } 
������ return 0; 
} 
/////////////////////////////////////////////////////////////////////////// 
// 
//���Դ�����Ϣ���� 
// 
void ShowError(char *msg) 
{ 
������ MessageBox(NULL,msg,"ERROR",0); 
������ //printf("\n%s failed:%d",GetLastError()); 
} 
////////////////////////////////////////////////////////////////////////// 
// 
//���ù��λ�ú������Ա�ɨ���߳������� 
// 
BOOL ResetCursor() 
{ 
������ ConSOLE_SCREEN_BUFFER_INFO ConsoleScreenBufferInfo; 
������ //ȡ�õ�ǰ���λ�� 
������ if(!GetConsoleScreenBufferInfo(hStdout,&ConsoleScreenBufferInfo)) 
������ { 
������������ ShowError("GetConsoleScreenBufferInfo"); 
������������ return FALSE; 
������ } 
������ //���ù��X����Ϊ0 
������ ConsoleScreenBufferInfo.dwCursorPosition.X=0; 
������ //���õ�ǰ���λ�� 
������ SetConsoleCursorPosition(hStdout,ConsoleScreenBufferInfo.dwCursorPosition); 
������ return TRUE; 
} 
/////////////////////////////////////////////////////////////////////////// 
// 
//��ʾ������Ϣ���� 
// 
DWORD WINAPI ShowProInfo(LPVOID lp) 
{���� 
������ int j,k; 
������ ConSOLE_SCREEN_BUFFER_INFO ConsoleScreenBufferInfo; 
������ float m; 
������ for(j=0;ii<iTotal;j++) 
������ { 
������������ //��Ϣһ��� )) 
������������ Sleep(SleepTime); 
������������ //ȡ�õ�ǰ���λ�� 
������������ if(!GetConsoleScreenBufferInfo(hStdout,&ConsoleScreenBufferInfo)) 
������������ { 
������������ ������ ShowError("GetConsoleScreenBufferInfo"); 
������������ ������ return 1; 
������������ } 
������������ //���ðٷֱȽ�����ʾ��X���� 
������������ ConsoleScreenBufferInfo.dwCursorPosition.X=0; 
������������ //���õ�ǰ���λ�� 
������������ SetConsoleCursorPosition(hStdout,ConsoleScreenBufferInfo.dwCursorPosition); 
������������ //�Ѿ���ɵİٷֱ� 
������������ m=(ii+1)*100.00/iTotal; 
������������ //��ʾ���� 
������������ if(ii==iTotal) 
������������ { 
������������ ������ printf("******** 100%% Wait %d seconds to exit ********�� �������� \n",iConnTimeout); 
������������ ������ break; 
������������ } 
������������ else 
������������ { 
������������ ������ k=j%4; 
������������ ������ printf("%-15s %s [%d/%d] %s %%%0.3g",CurrentTarget,turn[k],ii,iTotal,turn[k],m); 
������������ } 
������ }//end of for 
������ return 0; 
} 
/////////////////////////////////////////////////////////////////////////// 
// 
//ɨ�躯�� 
// 
DWORD WINAPI scan(LPVOID lp) 
{ 
������ int i=(int)lp,iErr; 
������ struct sockaddr_in server; 
������ SOCKET s=INVALID_SOCKET; 
������ char RecvBuff[1024]={0},*ptr; 
������ int RecvBuffLen=sizeof(RecvBuff); 
������ u_long ul=1;//��ʼ��ΪΪ��0ֵ 
����fd_set��r,w; 
������ //create socket 
������ s=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); 
������ if(s==INVALID_SOCKET) 
������ { 
������������ printf("\nCreate socket failed:%d",GetLastError()); 
������������ ExitProcess(1); 
������ } 
������ //fill the addr struct 
������ server.sin_family=AF_INET; 
������ server.sin_port=htons(iPort); 
������ server.sin_addr.S_un.S_addr=htonl(i); 
������ __try 
������ { 
������������ //����socketΪ������ģʽ,ulΪ0ֵ�Ļ�����ôsoocket��������Ϊ����ģʽ 
������������ iErr=ioctlsocket(s,FIonBIO,(unsigned long*)&ul); 
������������ if(iErr==SOCKET_ERROR ) 
������������ { 
������������ ������ ResetCursor(); 
������������ ������ ShowError("ioctlsocket"); 
������������ ������ ExitProcess(1); 
������������ } 
������������ //printf("\n%X ioctl ok.strat conn",i); 
������������ //connect to target 
������������ connect(s,(struct sockaddr *)&server,sizeof(server)); 
������������ //printf("\n%X conn return,start select w",i); 
������������ //����select���� 
������������ FD_ZERO(&w); 
������������ FD_SET(s, &w); 
������������ //�ȴ�connect�ɹ�&socket��д 
������������ iErr=select(0, 0, &w, 0, &timeout); 
������������ //printf("\n%X select w return %d",i,iErr); 
������������ //�ȴ����غ�socket�Բ���д���˳� 
������������ if((iErr==SOCKET_ERROR) || (iErr==0)) 
������������ { 
������������ ������ //printf("\n%X select return w err,exit",i); 
������������ ������ __leave; 
������������ } 
������������ //socket��д����� 
������������ else 
������������ { 
������������ ������ //send buff to target 
������������ ������ //printf("\n%X send",i); 
������������ ������ iErr=send(s,SendBuff,SendBuffLen,0); 
������������ ������ //printf("\n%X send return",i); 
������������ ������ if(iErr==SOCKET_ERROR) 
�������������������������� __leave; 
������������ } 
������������ //�ȴ�socket�ɶ� 
������������ FD_ZERO(&r); 
������������ FD_SET(s, &r); 
������������ //printf("\n%X start select r",i); 
������������ iErr=select(0, &r, 0, 0, &timeout); 
������������ //printf("\n%X select r return %d",i,iErr); 
������������ if((iErr==SOCKET_ERROR) || (iErr==0)) 
������������ { 
������������ ������ //printf("\n%X select r err,exit",i); 
������������ ������ __leave; 
������������ } 
������������ else 
������������ { 
������������ ������ //recv buff from target 
������������ ������ //printf("\n%X start recv",i); 
������������ ������ iErr=recv(s,RecvBuff,RecvBuffLen,0); 
������������ ������ //printf("\n%X recv ret",i); 
������������ ������ if(iErr==SOCKET_ERROR) 
�������������������������� __leave; 
������������ } 
������������ //verify buff 
������������ ptr=strstr(RecvBuff,szSign); 
������������ if(ptr!=NULL) 
������������ { 
�������������������� //�߳����ǰҪ�ȵ���ResetCursor���� 
������������ ������ ResetCursor(); 
�������������������� //�����Ϣ����ؼ�һ�����ϻ��з��ţ����ǰ���ӻ��з��ţ�������ʾ���� 
������������ ������ printf("[%-15s] has .printer mapped.�������������� \n",inet_ntoa(server.sin_addr)); 
������������ } 
������ } 
������ __finally 
������ { 
������������ if(!ReleaseSemaphore(hSemaphore,1,NULL)) 
������������ ������ ShowError("thread ReleaseSemaphore failed"); 
������������ closesocket(s); 
������ } 
������ return 0; 
} 
/////////////////////////////////////////////////////////////////////////// 
void usage(char *proname) 
{ 
������ printf("\n%s v0.1 only can find IIS5 .Printer mapped" 
������������ "\nPower by ey4s<> 2001.5.20" 
������������ "\nhttp://www.patching.net" 
������������ "\n\nUsage:%s <StartIP> <EndIP> <ThreadNum> <ConNTIMEO>" 
������������ "\n\nNotice" 
������������ "\n��������StartIP StopIP ==>Don��t forgot StopIP must large than StartIP " 
������������ "\n��������ThreadNum ==>Thread number,please input between 1-500" 
������������ "\n��������ConNTIMEO ==>TCP connect timeout,please input between 2-6" 
������������ "\n\nExample" 
������������ "\n��������%s 192.168.0.0 192.168.255.255 200 2",proname,proname,proname); 
}
