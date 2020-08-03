#include <windows.h>
#include <cmath>

int i, xView, yView;
double y;
char Buf[2];

#define pi 3.1415

#define f(x) sin(x*2*pi/360)

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
BOOL Line(HDC hdc, int x1, int y1, int x2, int y2);

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpszCmdLine,int nCmdShow){

    HWND hWnd;
    MSG lpMsg;
    WNDCLASS w;

    w.lpszClassName = (char*)"WinAPI Form";
    w.hInstance = hInstance;
    w.lpfnWndProc=WndProc;
    w.hCursor=LoadCursorA(nullptr,IDC_ARROW);
    w.hIcon=LoadIcon(w.hInstance, IDI_APPLICATION);
    w.lpszMenuName=nullptr;
    w.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH); // (HBRUSH)(COLOR_WINDOW)
    w.style=CS_HREDRAW|CS_VREDRAW;
    w.cbClsExtra=0;
    w.cbWndExtra=0;

    if (!RegisterClass(&w)) return 0;

    hWnd = CreateWindowEx(0,"WinAPI Form","WinAPI Draw Graph",WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU ,100,100,500,400,nullptr,nullptr,hInstance,nullptr);

    ShowWindow(hWnd,SW_SHOWNORMAL);
    UpdateWindow(hWnd);

    while (GetMessage(&lpMsg, nullptr, 0, 0))
    {
        TranslateMessage(&lpMsg);
        DispatchMessage(&lpMsg);
    }
    return(lpMsg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
    HDC hdc; // context
    PAINTSTRUCT ps; //example structure of graph output
    HPEN hPen; // brush/Pen
    switch(msg)
    {
        case WM_SIZE:
            xView=LOWORD(lParam);
            yView=HIWORD(lParam);
            break;

        case WM_PAINT:
            hdc = BeginPaint(hWnd,&ps);
            SetMapMode(hdc,MM_ISOTROPIC); //logic ones as physics
            SetWindowExtEx(hdc,500,500,nullptr); //Length
            SetViewportExtEx(hdc,xView,-yView,nullptr); //Start point
            SetViewportOrgEx(hdc,xView/6,yView/2,nullptr); //O(0,0)

            Line(hdc,0,220,0,-220); //Y
            Line(hdc,-100,0,500,0); //X
            MoveToEx(hdc,0,0,nullptr);

            //RedPen
            hPen = CreatePen(1,4,RGB(255,25,0));
            SelectObject(hdc,hPen);
            //Draw func
            for(i=0; i<400; i++){
                y=f(i)*100;
                LineTo(hdc, i, (int)y);
            }
            //Black pen
            hPen=CreatePen(1,1,RGB(0,0,0));
            SelectObject(hdc, hPen);
            //Lines
            for(i=-100; i<500; i+=100)
            {
                Line(hdc, i, 3,i,-3);
                Line(hdc, -3, i,3,i);
                itoa(i, Buf, 10);
                TextOut(hdc, i-5, -5, Buf , strlen(Buf));
                TextOut(hdc, -5, i, Buf , strlen(Buf));
            }

            ValidateRect(hWnd,nullptr); // Window update
            EndPaint(hWnd,&ps);
            break;
        case WM_DESTROY:
            DeleteObject(hPen); //destroy pen
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProcA(hWnd,msg,wParam,lParam);
    }
    return 0;
}

BOOL Line(HDC hdc, int x1, int y1, int x2, int y2)
{
    MoveToEx(hdc,x1,y1,nullptr);
    return LineTo(hdc,x2,y2);
}