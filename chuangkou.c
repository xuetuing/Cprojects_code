#include <windows.h>
#include <wingdi.h>
//回调函数
LRESULT WINAPI WinProc(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam)
{
    switch(Msg)//处理消息过程，什么是消息，下节再讲
    {
    case WM_DESTROY://响应鼠标单击关闭按钮事件
        PostQuitMessage(0);//退出消息队列，至于什么是消息队列，下节说
        return 0;//退出函数
    }
    return DefWindowProc(hWnd,Msg,wParam,lParam);
}
//主函数
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
    char *cName = "myWindow";
    WNDCLASSEX wc;
    HWND hand;
    MSG Msg;

    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//通过函数来设置一个白色的背景，这里大家设置为NULL看看，会很有趣的
    wc.hCursor = NULL;//不设置
    wc.hIcon = NULL;//不设置
    wc.hIconSm = NULL;//不设置
    wc.hInstance = hInstance;//当前程序的句柄，hInstance是有系统给传递的
    wc.lpfnWndProc = WinProc;//窗口处理过程的回调函数。
    wc.lpszClassName =(LPSTR)cName;//窗口类的名字。
    wc.lpszMenuName = NULL;//目录名，不设置
    wc.style = CS_HREDRAW | CS_VREDRAW; 

    RegisterClassEx(&wc);//在系统中注册

    hand = CreateWindowEx(WS_EX_CLIENTEDGE,cName,"我的窗口我喜欢",WS_OVERLAPPEDWINDOW,
        200,100,600,400,NULL,NULL,hInstance,NULL);//创建窗口，窗口标题为"我的窗口我喜欢"
    if(hand == NULL)
    {//容错处理
        MessageBox(NULL,"There's an Error","Error Title",MB_ICONEXCLAMATION|MB_OK);
        return 0;
    }
    ShowWindow(hand ,nShowCmd);//显示窗口
    UpdateWindow(hand);

    //下面是对消息的循环处理，大家先不必管这些，下节课我会细说的
	while(GetMessage(&Msg,NULL,0,0))
    {
        TranslateMessage(&Msg);//翻译消息
        DispatchMessage(&Msg);//分派消息
    }
    return Msg.message;
}
