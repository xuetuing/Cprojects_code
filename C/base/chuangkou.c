#include <windows.h>
#include <wingdi.h>
//�ص�����
LRESULT WINAPI WinProc(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam)
{
    switch(Msg)//������Ϣ���̣�ʲô����Ϣ���½��ٽ�
    {
    case WM_DESTROY://��Ӧ��굥���رհ�ť�¼�
        PostQuitMessage(0);//�˳���Ϣ���У�����ʲô����Ϣ���У��½�˵
        return 0;//�˳�����
    }
    return DefWindowProc(hWnd,Msg,wParam,lParam);
}
//������
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
    char *cName = "myWindow";
    WNDCLASSEX wc;
    HWND hand;
    MSG Msg;

    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//ͨ������������һ����ɫ�ı���������������ΪNULL�����������Ȥ��
    wc.hCursor = NULL;//������
    wc.hIcon = NULL;//������
    wc.hIconSm = NULL;//������
    wc.hInstance = hInstance;//��ǰ����ľ����hInstance����ϵͳ�����ݵ�
    wc.lpfnWndProc = WinProc;//���ڴ�����̵Ļص�������
    wc.lpszClassName =(LPSTR)cName;//����������֡�
    wc.lpszMenuName = NULL;//Ŀ¼����������
    wc.style = CS_HREDRAW | CS_VREDRAW; 

    RegisterClassEx(&wc);//��ϵͳ��ע��

    hand = CreateWindowEx(WS_EX_CLIENTEDGE,cName,"�ҵĴ�����ϲ��",WS_OVERLAPPEDWINDOW,
        200,100,600,400,NULL,NULL,hInstance,NULL);//�������ڣ����ڱ���Ϊ"�ҵĴ�����ϲ��"
    if(hand == NULL)
    {//�ݴ���
        MessageBox(NULL,"There's an Error","Error Title",MB_ICONEXCLAMATION|MB_OK);
        return 0;
    }
    ShowWindow(hand ,nShowCmd);//��ʾ����
    UpdateWindow(hand);

    //�����Ƕ���Ϣ��ѭ����������Ȳ��ع���Щ���½ڿ��һ�ϸ˵��
	while(GetMessage(&Msg,NULL,0,0))
    {
        TranslateMessage(&Msg);//������Ϣ
        DispatchMessage(&Msg);//������Ϣ
    }
    return Msg.message;
}
