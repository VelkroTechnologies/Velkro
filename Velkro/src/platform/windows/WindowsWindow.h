#pragma once

#include <Windows.h>

#include <iostream>

namespace Velkro
{
    class Window
    {
    public:
        Window(const char* title, unsigned int width, unsigned int height)
            : m_HInstance(GetModuleHandle(nullptr))
        {
            className = L"Velkro Window";

            WNDCLASS wndClass = {};
            wndClass.lpszClassName = className;
            wndClass.hInstance = m_HInstance;
            wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
            wndClass.hbrBackground = GetSysColorBrush(COLOR_WINDOW);
            wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
            wndClass.lpfnWndProc = Window::WindowProc;

            RegisterClass(&wndClass);

            DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

            RECT rect;
            rect.left = 0;
            rect.top = 0;
            rect.right = rect.left + width;
            rect.bottom = rect.top + height;

            AdjustWindowRect(&rect, style, false);
            
            std::string titleStr = title;
            int wcharsNum = MultiByteToWideChar(CP_UTF8, 0, titleStr.c_str(), -1, NULL, 0);

            wchar_t* wstrTitle = new wchar_t[wcharsNum];

            MultiByteToWideChar(CP_UTF8, 0, titleStr.c_str(), -1, wstrTitle, wcharsNum);            

            m_hWnd = CreateWindowEx(
                0,
                className,
                wstrTitle,
                style,
                rect.left,
                rect.top,
                rect.right - rect.left,
                rect.bottom - rect.top,
                NULL,
                NULL,
                m_HInstance,
                NULL
            );

            delete[] wstrTitle;

            ShowWindow(m_hWnd, SW_SHOW);
        }
        ~Window()
        {
            UnregisterClass(className, m_HInstance);
        }
    
        bool Update()
        {
            MSG msg = {};

            while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE))
            {
                if (msg.message == WM_QUIT)
                {
                    return false;
                }

                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }

            return true;
        }

    private:
        static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
        {
            switch (uMsg)
            {
            case WM_CLOSE:
                DestroyWindow(hWnd);
                break;
            case WM_DESTROY:
                PostQuitMessage(0);
                return 0;
            }

            return DefWindowProc(hWnd, uMsg, wParam, lParam);
        }

        LPCWSTR className;
        HINSTANCE m_HInstance;
        HWND m_hWnd;
    };
}