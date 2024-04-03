#pragma once

#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace Velkro
{
   class Window
   {
   public:
      Window(const char* title, unsigned int width, unsigned int height)
      {
         m_Display = XOpenDisplay(NULL);
         if (m_Display == NULL) 
         {
            fprintf(stderr, "Cannot open display\n");
            exit(1);
         }

         m_Screen = DefaultScreen(m_Display);
         m_Window = XCreateSimpleWindow(m_Display, RootWindow(m_Display, m_Screen), 10, 10, width, height, 1,
                                        BlackPixel(m_Display, m_Screen), WhitePixel(m_Display, m_Screen));
         XSelectInput(m_Display, m_Window, ExposureMask | KeyPressMask);
         XMapWindow(m_Display, m_Window);

         XGetWindowAttributes(m_Display, m_Window, &m_WinAttributes);

         XStoreName(m_Display, m_Window, title);
      }
      ~Window()
      {
         XCloseDisplay(m_Display);
      }

      void Update()
      {
         XNextEvent(m_Display, &m_Event);

         if (m_Event.type == Expose) 
         {
            XFillRectangle(m_Display, m_Window, DefaultGC(m_Display, m_Screen), 20, 20, 10, 10);
         }
      }

      void SetTitle(const char* title)
      {
         XStoreName(m_Display, m_Window, title);
      }
      const char* GetTitle()
      {
         char* title;
         XFetchName(m_Display, m_Window, &title);
         return title;
      }

      void SetSize(unsigned int width, unsigned int height)
      {
         XResizeWindow(m_Display, m_Window, width, height);
      }
      void GetSize(unsigned int& width, unsigned int& height)
      {
         width = m_WinAttributes.width;
         height = m_WinAttributes.height;
      }

   private:
      Display* m_Display;
      XID m_Window;
      XWindowAttributes m_WinAttributes;
      XEvent m_Event;
      int m_Screen;
   };
}