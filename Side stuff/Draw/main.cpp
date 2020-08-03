#include <windows.h>
#include <cmath>
#include <vector>
#include <fstream>

int xView, yView;
char Buf[2];

std::vector<std::pair<int,int>> graph_array{};

bool InitArray();

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
BOOL Line(HDC hdc, int x1, int y1, int x2, int y2);

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpszCmdLine,int nCmdShow){


    if(InitArray()) {
        HWND hWnd;
        MSG lpMsg;
        WNDCLASS w;

        w.lpszClassName = (char *) "WinAPI Form";
        w.hInstance = hInstance;
        w.lpfnWndProc = WndProc;
        w.hCursor = LoadCursorA(nullptr, IDC_ARROW);
        w.hIcon = LoadIcon(w.hInstance, IDI_APPLICATION);
        w.lpszMenuName = nullptr;
        w.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH); // (HBRUSH)(COLOR_WINDOW)
        w.style = CS_HREDRAW | CS_VREDRAW;
        w.cbClsExtra = 0;
        w.cbWndExtra = 0;

        if (!RegisterClass(&w)) return 0;

        hWnd = CreateWindowEx(0, "WinAPI Form", "WinAPI Draw Graph", WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU, 100, 100,
                              800, 600, nullptr, nullptr, hInstance, nullptr);

        ShowWindow(hWnd, SW_SHOWNORMAL);
        UpdateWindow(hWnd);

        while (GetMessage(&lpMsg, nullptr, 0, 0)) {
            TranslateMessage(&lpMsg);
            DispatchMessage(&lpMsg);
        }
        return(lpMsg.wParam);
    }
    return 0;
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

        case WM_PAINT: {
            hdc = BeginPaint(hWnd, &ps);
            SetMapMode(hdc, MM_ISOTROPIC); //logic ones as physics
            SetWindowExtEx(hdc, 800, 600, nullptr); //Length
            SetViewportExtEx(hdc, xView, -yView, nullptr); //Start point
            SetViewportOrgEx(hdc, xView / 8, yView / 8 * 7, nullptr); //O(0,0)

            Line(hdc, 0, yView / 8 * 7, 0, -10); //Y
            Line(hdc, -10, 0, xView / 8 * 7, 0); //X
            MoveToEx(hdc, 0, 0, nullptr);

            //RedPen
            hPen = CreatePen(1, 4, RGB(255, 25, 0));
            SelectObject(hdc, hPen);
            //Getting Sizes
            int max_x = (graph_array.end() - 1)->first;
            double kx = floor(  ((double)xView / 8 * 7) / (double)max_x);
            double ky = floor(((double)yView / 8 * 7) / (double) (graph_array.end() - 1)->second);
            //Draw func
            for (auto dot:graph_array) LineTo(hdc,kx*dot.first,ky*dot.second);
            //Black pen
            hPen = CreatePen(1, 1, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            /*
            //Lines
            for(i=-100; i<500; i+=100)
            {
                Line(hdc, i, 3,i,-3);
                Line(hdc, -3, i,3,i);
                itoa(i, Buf, 10);
                TextOut(hdc, i-5, -5, Buf , strlen(Buf));
                TextOut(hdc, -5, i, Buf , strlen(Buf));
            }
*/
            ValidateRect(hWnd, nullptr); // Window update
            EndPaint(hWnd, &ps);
            break;
        }
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

bool InitArray()
{
    std::ifstream _file("..\\sum.txt");
    std::pair<int,int> dot{0,0};
    int buf;
    while(!_file.eof())
    {
        _file >> dot.second;
        for (int iter = 0 ;iter<3;iter++) {_file >> buf;dot.first+=buf/3;}
        for (int iter = 0 ;iter<9;iter++) _file >> buf;
        if (dot.second!=0) graph_array.push_back(dot);
        dot = {0,0};
    }
    graph_array.shrink_to_fit();
    return true;
}