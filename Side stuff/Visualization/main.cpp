#include <windows.h>
#include "quick sort.h"


HINSTANCE hInst;
HWND    hwnd;

const size_t win_w =800;
const size_t win_h= 600;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//функция регистрации класса окон
BOOL RegClass(WNDPROC Proc, LPCTSTR szName, UINT brBackground)
{
    WNDCLASS wcex;
    wcex.style = wcex.cbClsExtra = wcex.cbWndExtra = 0;
    wcex.lpfnWndProc = Proc;
    wcex.hInstance = hInst;
    //wcex.hIcon=LoadIcon(NULL,MAKEINTRESOURCE(IDI_ICON1));
    wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = szName;
    return (RegisterClass(&wcex) != 0);
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
    MSG msg;
    hInst = hInstance;
    if (!RegClass(WndProc, "WinAPI Form", COLOR_WINDOW))
        return FALSE;


    hwnd = CreateWindowEx(0, "WinAPI Form", "WinAPI Test", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE,
                          0, 0,300, 300, nullptr, nullptr, hInstance, nullptr);


    ShowWindow(hwnd, SW_SHOWNORMAL);
    UpdateWindow(hwnd);
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;

}


LRESULT CALLBACK WndProc(HWND Hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_KEYDOWN:
            if (wParam != VK_ESCAPE)
                break;
        default:
            return DefWindowProc(Hwnd, msg, wParam, lParam);
    }
}