#include <iostream>
#include <windows.h>

HINSTANCE hInst;
HWND    hwnd;
HWND    hwnd_button;
HWND    hwnd_timer;
int winCode;

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

BOOL RegClass(WNDPROC Proc, LPCTSTR szName, HBRUSH bgbrush)
{
    WNDCLASS wcex;
    wcex.style = wcex.cbClsExtra = wcex.cbWndExtra = 0;
    wcex.lpfnWndProc = Proc;
    wcex.hInstance = hInst;
    //wcex.hIcon=LoadIcon(NULL,MAKEINTRESOURCE(IDI_ICON1));
    wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = bgbrush;
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = szName;
    return (RegisterClass(&wcex) != 0);
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
    MSG msg;
    hInst = hInstance;

    char class_name[] = "WinApi Green Form";

    HBRUSH bgbrush = CreateSolidBrush(RGB(0,255,0));

    if (!RegClass(WndProc,class_name,bgbrush)) return 0;

    winCode = 0;

    hwnd = CreateWindowEx(0, class_name, "WinAPI Timer", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE,
                          0, 0,
                          300, 300, nullptr, nullptr, hInstance, nullptr);


    ShowWindow(hwnd, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;

}


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_DESTROY:
            if (winCode==0) PostQuitMessage(0);
            return 0;

        case WM_CREATE:
            if (winCode==0) hwnd_button = CreateWindowEx(0, "button", "Timer start", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 10, 10, 90, 30, hWnd, (HMENU)10999, hInst, nullptr);
            break;

        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case 10999:
                    winCode = 1;
                    if (!hwnd_timer) hwnd_timer = CreateWindowEx(0,"WinApi Green Form","WinApi Pop Up", WS_OVERLAPPED | WS_VISIBLE,10,10,300,300,nullptr,nullptr,hInst,nullptr);
                    ShowWindow(hwnd_timer,SW_SHOWNORMAL);
                    break;
            }
            break;

    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}