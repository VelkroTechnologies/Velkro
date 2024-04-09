#pragma once

#include <Windows.h>

#include <iostream>

#include "../../Log.h"

#include "../../Event.h"

#define VLK_LEFT_MOUSE_BUTTON 1
#define VLK_RIGHT_MOUSE_BUTTON 2
#define VLK_KEY_CANCEL 3
#define VLK_KEY_BACK 8
#define VLK_KEY_TAB 9
#define VLK_KEY_CLEAR 12
#define VLK_KEY_RETURN 13
#define VLK_KEY_SHIFT 16
#define VLK_KEY_CONTROL 17
#define VLK_KEY_MENU 18
#define VLK_KEY_PAUSE 19
#define VLK_KEY_CAPITAL 20
#define VLK_KEY_ESCAPE 27
#define VLK_KEY_SPACE 32
#define VLK_KEY_PRIOR 33
#define VLK_KEY_NEXT 34
#define VLK_KEY_END 35
#define VLK_KEY_HOME 36
#define VLK_KEY_LEFT 37
#define VLK_KEY_UP 38
#define VLK_KEY_RIGHT 39
#define VLK_KEY_DOWN 40
#define VLK_KEY_SELECT 41
#define VLK_KEY_PRINT 42
#define VLK_KEY_EXECUTE 43
#define VLK_KEY_SNAPSHOT 44
#define VLK_KEY_INSERT 45
#define VLK_KEY_DELETE 46
#define VLK_KEY_HELP 47
#define VLK_KEY_0 48
#define VLK_KEY_1 49
#define VLK_KEY_2 50
#define VLK_KEY_3 51
#define VLK_KEY_4 52
#define VLK_KEY_5 53
#define VLK_KEY_6 54
#define VLK_KEY_7 55
#define VLK_KEY_8 56
#define VLK_KEY_9 57
#define VLK_KEY_A 65
#define VLK_KEY_B 66
#define VLK_KEY_C 67
#define VLK_KEY_D 68
#define VLK_KEY_E 69
#define VLK_KEY_F 70
#define VLK_KEY_G 71
#define VLK_KEY_H 72
#define VLK_KEY_I 73
#define VLK_KEY_J 74
#define VLK_KEY_K 75
#define VLK_KEY_L 76
#define VLK_KEY_M 77
#define VLK_KEY_N 78
#define VLK_KEY_O 79
#define VLK_KEY_P 80
#define VLK_KEY_Q 81
#define VLK_KEY_R 82
#define VLK_KEY_S 83
#define VLK_KEY_T 84
#define VLK_KEY_U 85
#define VLK_KEY_V 86
#define VLK_KEY_W 87
#define VLK_KEY_X 88
#define VLK_KEY_Y 89
#define VLK_KEY_Z 90
#define VLK_KEY_LWIN 91
#define VLK_KEY_RWIN 92
#define VLK_KEY_APPS 93
#define VLK_KEY_SLEEP 95
#define VLK_KEY_NUMPAD0 96
#define VLK_KEY_NUMPAD1 97
#define VLK_KEY_NUMPAD2 98
#define VLK_KEY_NUMPAD3 99
#define VLK_KEY_NUMPAD4 100
#define VLK_KEY_NUMPAD5 101
#define VLK_KEY_NUMPAD6 102
#define VLK_KEY_NUMPAD7 103
#define VLK_KEY_NUMPAD8 104
#define VLK_KEY_NUMPAD9 105
#define VLK_KEY_MULTIPLY 106
#define VLK_KEY_ADD 107
#define VLK_KEY_SEPARATOR 108
#define VLK_KEY_SUBTRACT 109
#define VLK_KEY_DECIMAL 110
#define VLK_KEY_DIVIDE 111
#define VLK_KEY_F1 112
#define VLK_KEY_F2 113
#define VLK_KEY_F3 114
#define VLK_KEY_F4 115
#define VLK_KEY_F5 116
#define VLK_KEY_F6 117
#define VLK_KEY_F7 118
#define VLK_KEY_F8 119
#define VLK_KEY_F9 120
#define VLK_KEY_F10 121
#define VLK_KEY_F11 122
#define VLK_KEY_F12 123
#define VLK_KEY_F13 124
#define VLK_KEY_F14 125
#define VLK_KEY_F15 126
#define VLK_KEY_F16 127
#define VLK_KEY_F17 128
#define VLK_KEY_F18 129
#define VLK_KEY_F19 130
#define VLK_KEY_F20 131
#define VLK_KEY_F21 132
#define VLK_KEY_F22 133
#define VLK_KEY_F23 134
#define VLK_KEY_F24 135
#define VLK_KEY_NUMLOCK 144
#define VLK_KEY_SCROLL 145
#define VLK_KEY_LSHIFT 160
#define VLK_KEY_RSHIFT 161
#define VLK_KEY_LCONTROL 162
#define VLK_KEY_RCONTROL 163
#define VLK_KEY_LMENU 164
#define VLK_KEY_RMENU 165
#define VLK_KEY_BROWSER_BACK 166
#define VLK_KEY_BROWSER_FORWARD 167
#define VLK_KEY_BROWSER_REFRESH 168
#define VLK_KEY_BROWSER_STOP 169
#define VLK_KEY_BROWSER_SEARCH 170
#define VLK_KEY_BROWSER_FAVORITES 171
#define VLK_KEY_BROWSER_HOME 172
#define VLK_KEY_VOLUME_MUTE 173
#define VLK_KEY_VOLUME_DOWN 174
#define VLK_KEY_VOLUME_UP 175
#define VLK_KEY_MEDIA_NEXT_TRACK 176
#define VLK_KEY_MEDIA_PREV_TRACK 177
#define VLK_KEY_MEDIA_STOP 178
#define VLK_KEY_MEDIA_PLAY_PAUSE 179
#define VLK_KEY_LAUNCH_MAIL 180
#define VLK_KEY_LAUNCH_MEDIA_SELECT 181
#define VLK_KEY_LAUNCH_APP1 182
#define VLK_KEY_LAUNCH_APP2 183
#define VLK_KEY_OEM_1 186
#define VLK_KEY_OEM_PLUS 187
#define VLK_KEY_OEM_COMMA 188
#define VLK_KEY_OEM_MINUS 189
#define VLK_KEY_OEM_PERIOD 190
#define VLK_KEY_OEM_2 191
#define VLK_KEY_OEM_3 192
#define VLK_KEY_OEM_4 219
#define VLK_KEY_OEM_5 220
#define VLK_KEY_OEM_6 221
#define VLK_KEY_OEM_7 222
#define VLK_KEY_OEM_8 223
#define VLK_KEY_OEM_102 226
#define VLK_KEY_PROCESSKEY 229
#define VLK_KEY_PACKET 231
#define VLK_KEY_ATTN 246
#define VLK_KEY_CRSEL 247
#define VLK_KEY_EXSEL 248
#define VLK_KEY_EREOF 249
#define VLK_KEY_PLAY 250
#define VLK_KEY_ZOOM 251
#define VLK_KEY_NONAME 252
#define VLK_KEY_PA1 253
#define VLK_KEY_OEM_CLEAR 254

namespace Velkro
{
	typedef void (*EventCallback)(std::unique_ptr<Event> event);

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

			DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU;

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

			m_DeviceContext = GetDC(m_hWnd);

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

			SwapBuffers(m_DeviceContext);

			return true;
		}

		static void SetEventCallback(EventCallback callback)
		{
			m_EventCallback = callback;
		}

	private:
		static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
		{
			switch (uMsg)
			{
			case WM_CLOSE:
				DestroyWindow(hWnd);

				VLK_WARN("Velkro Engine is still running.");

				break;
			case WM_DESTROY:
				PostQuitMessage(0);
				return 0;
			case WM_KEYDOWN:
				if (!m_KeyHeld)
				{
					m_EventCallback(std::make_unique<KeyEvent>(KeyEvent(VLK_PRESS, static_cast<EventCode>(wParam))));
				}
				else
				{
					m_KeyRepeatCount++;
					m_EventCallback(std::make_unique<KeyEvent>(KeyEvent(VLK_HELD, static_cast<EventCode>(wParam))));
				}

				m_KeyHeld = true;

				break;
			case WM_KEYUP:
				m_KeyHeld = false;
				m_KeyRepeatCount = 0;

				m_EventCallback(std::make_unique<KeyEvent>(KeyEvent(VLK_RELEASE, static_cast<EventCode>(wParam))));
				break;
			case WM_LBUTTONDOWN:
				m_EventCallback(std::make_unique<MouseButtonEvent>(MouseButtonEvent(VLK_PRESS, VK_LBUTTON)));
				break;
			case WM_LBUTTONUP:
				m_EventCallback(std::make_unique<MouseButtonEvent>(MouseButtonEvent(VLK_RELEASE, VK_LBUTTON)));
				break;
			case WM_RBUTTONDOWN:
				m_EventCallback(std::make_unique<MouseButtonEvent>(MouseButtonEvent(VLK_PRESS, VK_RBUTTON)));
				break;
			case WM_RBUTTONUP:
				m_EventCallback(std::make_unique<MouseButtonEvent>(MouseButtonEvent(VLK_RELEASE, VK_RBUTTON)));
				break;
			}

			return DefWindowProc(hWnd, uMsg, wParam, lParam);
		}

		LPCWSTR className;
		HINSTANCE m_HInstance;
		HWND m_hWnd;
		HDC m_DeviceContext;

		static inline EventCallback m_EventCallback;

		static inline bool m_KeyHeld = false;
		static inline long m_KeyRepeatCount = 0;
	};
}