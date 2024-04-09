#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>

#include "../../Log.h"
#include "../../Event.h"

#include <X11/Xlib.h>
#include <X11/keysym.h>

#define VLK_KEY_SPACE                         0x0020  /* U+0020 SPACE */
#define VLK_KEY_EXCLAM                        0x0021  /* U+0021 EXCLAMATION MARK */
#define VLK_KEY_QUOTEDBL                      0x0022  /* U+0022 QUOTATION MARK */
#define VLK_KEY_NUMBERSIGN                    0x0023  /* U+0023 NUMBER SIGN */
#define VLK_KEY_DOLLAR                        0x0024  /* U+0024 DOLLAR SIGN */
#define VLK_KEY_PERCENT                       0x0025  /* U+0025 PERCENT SIGN */
#define VLK_KEY_AMPERSAND                     0x0026  /* U+0026 AMPERSAND */
#define VLK_KEY_APOSTROPHE                    0x0027  /* U+0027 APOSTROPHE */
#define VLK_KEY_QUOTERIGHT                    0x0027  /* deprecated */
#define VLK_KEY_PARENLEFT                     0x0028  /* U+0028 LEFT PARENTHESIS */
#define VLK_KEY_PARENRIGHT                    0x0029  /* U+0029 RIGHT PARENTHESIS */
#define VLK_KEY_ASTERISK                      0x002a  /* U+002A ASTERISK */
#define VLK_KEY_PLUS                          0x002b  /* U+002B PLUS SIGN */
#define VLK_KEY_COMMA                         0x002c  /* U+002C COMMA */
#define VLK_KEY_MINUS                         0x002d  /* U+002D HYPHEN-MINUS */
#define VLK_KEY_PERIOD                        0x002e  /* U+002E FULL STOP */
#define VLK_KEY_SLASH                         0x002f  /* U+002F SOLIDUS */
#define VLK_KEY_0                             0x0030  /* U+0030 DIGIT ZERO */
#define VLK_KEY_1                             0x0031  /* U+0031 DIGIT ONE */
#define VLK_KEY_2                             0x0032  /* U+0032 DIGIT TWO */
#define VLK_KEY_3                             0x0033  /* U+0033 DIGIT THREE */
#define VLK_KEY_4                             0x0034  /* U+0034 DIGIT FOUR */
#define VLK_KEY_5                             0x0035  /* U+0035 DIGIT FIVE */
#define VLK_KEY_6                             0x0036  /* U+0036 DIGIT SIX */
#define VLK_KEY_7                             0x0037  /* U+0037 DIGIT SEVEN */
#define VLK_KEY_8                             0x0038  /* U+0038 DIGIT EIGHT */
#define VLK_KEY_9                             0x0039  /* U+0039 DIGIT NINE */
#define VLK_KEY_COLON                         0x003a  /* U+003A COLON */
#define VLK_KEY_SEMICOLON                     0x003b  /* U+003B SEMICOLON */
#define VLK_KEY_LESS                          0x003c  /* U+003C LESS-THAN SIGN */
#define VLK_KEY_EQUAL                         0x003d  /* U+003D EQUALS SIGN */
#define VLK_KEY_GREATER                       0x003e  /* U+003E GREATER-THAN SIGN */
#define VLK_KEY_QUESTION                      0x003f  /* U+003F QUESTION MARK */
#define VLK_KEY_AT                            0x0040  /* U+0040 COMMERCIAL AT */
#define VLK_KEY_A                             0x0041  /* U+0041 LATIN CAPITAL LETTER A */
#define VLK_KEY_B                             0x0042  /* U+0042 LATIN CAPITAL LETTER B */
#define VLK_KEY_C                             0x0043  /* U+0043 LATIN CAPITAL LETTER C */
#define VLK_KEY_D                             0x0044  /* U+0044 LATIN CAPITAL LETTER D */
#define VLK_KEY_E                             0x0045  /* U+0045 LATIN CAPITAL LETTER E */
#define VLK_KEY_F                             0x0046  /* U+0046 LATIN CAPITAL LETTER F */
#define VLK_KEY_G                             0x0047  /* U+0047 LATIN CAPITAL LETTER G */
#define VLK_KEY_H                             0x0048  /* U+0048 LATIN CAPITAL LETTER H */
#define VLK_KEY_I                             0x0049  /* U+0049 LATIN CAPITAL LETTER I */
#define VLK_KEY_J                             0x004a  /* U+004A LATIN CAPITAL LETTER J */
#define VLK_KEY_K                             0x004b  /* U+004B LATIN CAPITAL LETTER K */
#define VLK_KEY_L                             0x004c  /* U+004C LATIN CAPITAL LETTER L */
#define VLK_KEY_M                             0x004d  /* U+004D LATIN CAPITAL LETTER M */
#define VLK_KEY_N                             0x004e  /* U+004E LATIN CAPITAL LETTER N */
#define VLK_KEY_O                             0x004f  /* U+004F LATIN CAPITAL LETTER O */
#define VLK_KEY_P                             0x0050  /* U+0050 LATIN CAPITAL LETTER P */
#define VLK_KEY_Q                             0x0051  /* U+0051 LATIN CAPITAL LETTER Q */
#define VLK_KEY_R                             0x0052  /* U+0052 LATIN CAPITAL LETTER R */
#define VLK_KEY_S                             0x0053  /* U+0053 LATIN CAPITAL LETTER S */
#define VLK_KEY_T                             0x0054  /* U+0054 LATIN CAPITAL LETTER T */
#define VLK_KEY_U                             0x0055  /* U+0055 LATIN CAPITAL LETTER U */
#define VLK_KEY_V                             0x0056  /* U+0056 LATIN CAPITAL LETTER V */
#define VLK_KEY_W                             0x0057  /* U+0057 LATIN CAPITAL LETTER W */
#define VLK_KEY_X                             0x0058  /* U+0058 LATIN CAPITAL LETTER X */
#define VLK_KEY_Y                             0x0059  /* U+0059 LATIN CAPITAL LETTER Y */
#define VLK_KEY_Z                             0x005a  /* U+005A LATIN CAPITAL LETTER Z */
#define VLK_KEY_BRACKETLEFT                   0x005b  /* U+005B LEFT SQUARE BRACKET */
#define VLK_KEY_BACKSLASH                     0x005c  /* U+005C REVERSE SOLIDUS */
#define VLK_KEY_BRACKETRIGHT                  0x005d  /* U+005D RIGHT SQUARE BRACKET */
#define VLK_KEY_ASCIICIRCUM                   0x005e  /* U+005E CIRCUMFLEX ACCENT */
#define VLK_KEY_UNDERSCORE                    0x005f  /* U+005F LOW LINE */
#define VLK_KEY_GRAVE                         0x0060  /* U+0060 GRAVE ACCENT */
#define VLK_KEY_QUOTELEFT                     0x0060  /* deprecated */
#define VLK_KEY_LOWERCASE_A                   0x0061  /* U+0061 LATIN SMALL LETTER A */
#define VLK_KEY_LOWERCASE_B                   0x0062  /* U+0062 LATIN SMALL LETTER B */
#define VLK_KEY_LOWERCASE_C                   0x0063  /* U+0063 LATIN SMALL LETTER C */
#define VLK_KEY_LOWERCASE_D                   0x0064  /* U+0064 LATIN SMALL LETTER D */
#define VLK_KEY_LOWERCASE_E                   0x0065  /* U+0065 LATIN SMALL LETTER E */
#define VLK_KEY_LOWERCASE_F                   0x0066  /* U+0066 LATIN SMALL LETTER F */
#define VLK_KEY_LOWERCASE_G                   0x0067  /* U+0067 LATIN SMALL LETTER G */
#define VLK_KEY_LOWERCASE_H                   0x0068  /* U+0068 LATIN SMALL LETTER H */
#define VLK_KEY_LOWERCASE_I                   0x0069  /* U+0069 LATIN SMALL LETTER I */
#define VLK_KEY_LOWERCASE_J                   0x006a  /* U+006A LATIN SMALL LETTER J */
#define VLK_KEY_LOWERCASE_K                   0x006b  /* U+006B LATIN SMALL LETTER K */
#define VLK_KEY_LOWERCASE_L                   0x006c  /* U+006C LATIN SMALL LETTER L */
#define VLK_KEY_LOWERCASE_M                   0x006d  /* U+006D LATIN SMALL LETTER M */
#define VLK_KEY_LOWERCASE_N                   0x006e  /* U+006E LATIN SMALL LETTER N */
#define VLK_KEY_LOWERCASE_O                   0x006f  /* U+006F LATIN SMALL LETTER O */
#define VLK_KEY_LOWERCASE_P                   0x0070  /* U+0070 LATIN SMALL LETTER P */
#define VLK_KEY_LOWERCASE_Q                   0x0071  /* U+0071 LATIN SMALL LETTER Q */
#define VLK_KEY_LOWERCASE_R                   0x0072  /* U+0072 LATIN SMALL LETTER R */
#define VLK_KEY_LOWERCASE_S                   0x0073  /* U+0073 LATIN SMALL LETTER S */
#define VLK_KEY_LOWERCASE_T                   0x0074  /* U+0074 LATIN SMALL LETTER T */
#define VLK_KEY_LOWERCASE_U                   0x0075  /* U+0075 LATIN SMALL LETTER U */
#define VLK_KEY_LOWERCASE_V                   0x0076  /* U+0076 LATIN SMALL LETTER V */
#define VLK_KEY_LOWERCASE_W                   0x0077  /* U+0077 LATIN SMALL LETTER W */
#define VLK_KEY_LOWERCASE_X                   0x0078  /* U+0078 LATIN SMALL LETTER X */
#define VLK_KEY_LOWERCASE_Y                   0x0079  /* U+0079 LATIN SMALL LETTER Y */
#define VLK_KEY_LOWERCASE_Z                   0x007a  /* U+007A LATIN SMALL LETTER Z */
#define VLK_KEY_BRACELEFT                     0x007b  /* U+007B LEFT CURLY BRACKET */
#define VLK_KEY_BAR                           0x007c  /* U+007C VERTICAL LINE */
#define VLK_KEY_BRACERIGHT                    0x007d  /* U+007D RIGHT CURLY BRACKET */
#define VLK_KEY_ASCIITILDE                    0x007e  /* U+007E TILDE */
#define VLK_KEY_NOBREAKSPACE                  0x00a0  /* U+00A0 NO-BREAK SPACE */
#define VLK_KEY_EXCLAMDOWN                    0x00a1  /* U+00A1 INVERTED EXCLAMATION MARK */
#define VLK_KEY_CENT                          0x00a2  /* U+00A2 CENT SIGN */
#define VLK_KEY_STERLING                      0x00a3  /* U+00A3 POUND SIGN */
#define VLK_KEY_CURRENCY                      0x00a4  /* U+00A4 CURRENCY SIGN */
#define VLK_KEY_YEN                           0x00a5  /* U+00A5 YEN SIGN */
#define VLK_KEY_BROKENBAR                     0x00a6  /* U+00A6 BROKEN BAR */
#define VLK_KEY_SECTION                       0x00a7  /* U+00A7 SECTION SIGN */
#define VLK_KEY_DIAERESIS                     0x00a8  /* U+00A8 DIAERESIS */
#define VLK_KEY_COPYRIGHT                     0x00a9  /* U+00A9 COPYRIGHT SIGN */
#define VLK_KEY_ORDFEMININE                   0x00aa  /* U+00AA FEMININE ORDINAL INDICATOR */
#define VLK_KEY_GUILLEMOTLEFT                 0x00ab  /* U+00AB LEFT-POINTING DOUBLE ANGLE QUOTATION MARK */
#define VLK_KEY_NOTSIGN                       0x00ac  /* U+00AC NOT SIGN */
#define VLK_KEY_HYPHEN                        0x00ad  /* U+00AD SOFT HYPHEN */
#define VLK_KEY_REGISTERED                    0x00ae  /* U+00AE REGISTERED SIGN */
#define VLK_KEY_MACRON                        0x00af  /* U+00AF MACRON */
#define VLK_KEY_DEGREE                        0x00b0  /* U+00B0 DEGREE SIGN */
#define VLK_KEY_PLUSMINUS                     0x00b1  /* U+00B1 PLUS-MINUS SIGN */
#define VLK_KEY_TWOSUPERIOR                   0x00b2  /* U+00B2 SUPERSCRIPT TWO */
#define VLK_KEY_THREESUPERIOR                 0x00b3  /* U+00B3 SUPERSCRIPT THREE */
#define VLK_KEY_ACUTE                         0x00b4  /* U+00B4 ACUTE ACCENT */
#define VLK_KEY_MU                            0x00b5  /* U+00B5 MICRO SIGN */
#define VLK_KEY_PARAGRAPH                     0x00b6  /* U+00B6 PILCROW SIGN */
#define VLK_KEY_PERIODCENTERED                0x00b7  /* U+00B7 MIDDLE DOT */
#define VLK_KEY_CEDILLA                       0x00b8  /* U+00B8 CEDILLA */
#define VLK_KEY_ONESUPERIOR                   0x00b9  /* U+00B9 SUPERSCRIPT ONE */
#define VLK_KEY_MASCULINE                     0x00ba  /* U+00BA MASCULINE ORDINAL INDICATOR */
#define VLK_KEY_GUILLEMOTRIGHT                0x00bb  /* U+00BB RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK */
#define VLK_KEY_ONEQUARTER                    0x00bc  /* U+00BC VULGAR FRACTION ONE QUARTER */
#define VLK_KEY_ONEHALF                       0x00bd  /* U+00BD VULGAR FRACTION ONE HALF */
#define VLK_KEY_THREEQUARTERS                 0x00be  /* U+00BE VULGAR FRACTION THREE QUARTERS */
#define VLK_KEY_QUESTIONDOWN                  0x00bf  /* U+00BF INVERTED QUESTION MARK */
#define VLK_KEY_AGRAVE                        0x00c0  /* U+00C0 LATIN CAPITAL LETTER A WITH GRAVE */
#define VLK_KEY_AACUTE                        0x00c1  /* U+00C1 LATIN CAPITAL LETTER A WITH ACUTE */
#define VLK_KEY_ACIRCUMFLEX                   0x00c2  /* U+00C2 LATIN CAPITAL LETTER A WITH CIRCUMFLEX */
#define VLK_KEY_ATILDE                        0x00c3  /* U+00C3 LATIN CAPITAL LETTER A WITH TILDE */
#define VLK_KEY_ADIAERESIS                    0x00c4  /* U+00C4 LATIN CAPITAL LETTER A WITH DIAERESIS */
#define VLK_KEY_ARING                         0x00c5  /* U+00C5 LATIN CAPITAL LETTER A WITH RING ABOVE */
#define VLK_KEY_AE                            0x00c6  /* U+00C6 LATIN CAPITAL LETTER AE */
#define VLK_KEY_CCEDILLA                      0x00c7  /* U+00C7 LATIN CAPITAL LETTER C WITH CEDILLA */
#define VLK_KEY_EGRAVE                        0x00c8  /* U+00C8 LATIN CAPITAL LETTER E WITH GRAVE */
#define VLK_KEY_EACUTE                        0x00c9  /* U+00C9 LATIN CAPITAL LETTER E WITH ACUTE */
#define VLK_KEY_ECIRCUMFLEX                   0x00ca  /* U+00CA LATIN CAPITAL LETTER E WITH CIRCUMFLEX */
#define VLK_KEY_EDIAERESIS                    0x00cb  /* U+00CB LATIN CAPITAL LETTER E WITH DIAERESIS */
#define VLK_KEY_IGRAVE                        0x00cc  /* U+00CC LATIN CAPITAL LETTER I WITH GRAVE */
#define VLK_KEY_IACUTE                        0x00cd  /* U+00CD LATIN CAPITAL LETTER I WITH ACUTE */
#define VLK_KEY_ICIRCUMFLEX                   0x00ce  /* U+00CE LATIN CAPITAL LETTER I WITH CIRCUMFLEX */
#define VLK_KEY_IDIAERESIS                    0x00cf  /* U+00CF LATIN CAPITAL LETTER I WITH DIAERESIS */
#define VLK_KEY_ETH                           0x00d0  /* U+00D0 LATIN CAPITAL LETTER ETH */
#define VLK_KEY_ETH                           0x00d0  /* deprecated */
#define VLK_KEY_NTILDE                        0x00d1  /* U+00D1 LATIN CAPITAL LETTER N WITH TILDE */
#define VLK_KEY_OGRAVE                        0x00d2  /* U+00D2 LATIN CAPITAL LETTER O WITH GRAVE */
#define VLK_KEY_OACUTE                        0x00d3  /* U+00D3 LATIN CAPITAL LETTER O WITH ACUTE */
#define VLK_KEY_OCIRCUMFLEX                   0x00d4  /* U+00D4 LATIN CAPITAL LETTER O WITH CIRCUMFLEX */
#define VLK_KEY_OTILDE                        0x00d5  /* U+00D5 LATIN CAPITAL LETTER O WITH TILDE */
#define VLK_KEY_ODIAERESIS                    0x00d6  /* U+00D6 LATIN CAPITAL LETTER O WITH DIAERESIS */
#define VLK_KEY_MULTIPLY                      0x00d7  /* U+00D7 MULTIPLICATION SIGN */
#define VLK_KEY_OSLASH                        0x00d8  /* U+00D8 LATIN CAPITAL LETTER O WITH STROKE */
#define VLK_KEY_OOBLIQUE                      0x00d8  /* U+00D8 LATIN CAPITAL LETTER O WITH STROKE */
#define VLK_KEY_UGRAVE                        0x00d9  /* U+00D9 LATIN CAPITAL LETTER U WITH GRAVE */
#define VLK_KEY_UACUTE                        0x00da  /* U+00DA LATIN CAPITAL LETTER U WITH ACUTE */
#define VLK_KEY_UCIRCUMFLEX                   0x00db  /* U+00DB LATIN CAPITAL LETTER U WITH CIRCUMFLEX */
#define VLK_KEY_UDIAERESIS                    0x00dc  /* U+00DC LATIN CAPITAL LETTER U WITH DIAERESIS */
#define VLK_KEY_YACUTE                        0x00dd  /* U+00DD LATIN CAPITAL LETTER Y WITH ACUTE */
#define VLK_KEY_THORN                         0x00de  /* U+00DE LATIN CAPITAL LETTER THORN */
#define VLK_KEY_THORN                         0x00de  /* deprecated */
#define VLK_KEY_SSHARP                        0x00df  /* U+00DF LATIN SMALL LETTER SHARP S */
#define VLK_KEY_AGRAVE                        0x00e0  /* U+00E0 LATIN SMALL LETTER A WITH GRAVE */
#define VLK_KEY_AACUTE                        0x00e1  /* U+00E1 LATIN SMALL LETTER A WITH ACUTE */
#define VLK_KEY_ACIRCUMFLEX                   0x00e2  /* U+00E2 LATIN SMALL LETTER A WITH CIRCUMFLEX */
#define VLK_KEY_ATILDE                        0x00e3  /* U+00E3 LATIN SMALL LETTER A WITH TILDE */
#define VLK_KEY_ADIAERESIS                    0x00e4  /* U+00E4 LATIN SMALL LETTER A WITH DIAERESIS */
#define VLK_KEY_ARING                         0x00e5  /* U+00E5 LATIN SMALL LETTER A WITH RING ABOVE */
#define VLK_KEY_AE                            0x00e6  /* U+00E6 LATIN SMALL LETTER AE */
#define VLK_KEY_CCEDILLA                      0x00e7  /* U+00E7 LATIN SMALL LETTER C WITH CEDILLA */
#define VLK_KEY_EGRAVE                        0x00e8  /* U+00E8 LATIN SMALL LETTER E WITH GRAVE */
#define VLK_KEY_EACUTE                        0x00e9  /* U+00E9 LATIN SMALL LETTER E WITH ACUTE */
#define VLK_KEY_ECIRCUMFLEX                   0x00ea  /* U+00EA LATIN SMALL LETTER E WITH CIRCUMFLEX */
#define VLK_KEY_EDIAERESIS                    0x00eb  /* U+00EB LATIN SMALL LETTER E WITH DIAERESIS */
#define VLK_KEY_IGRAVE                        0x00ec  /* U+00EC LATIN SMALL LETTER I WITH GRAVE */
#define VLK_KEY_IACUTE                        0x00ed  /* U+00ED LATIN SMALL LETTER I WITH ACUTE */
#define VLK_KEY_ICIRCUMFLEX                   0x00ee  /* U+00EE LATIN SMALL LETTER I WITH CIRCUMFLEX */
#define VLK_KEY_IDIAERESIS                    0x00ef  /* U+00EF LATIN SMALL LETTER I WITH DIAERESIS */
#define VLK_KEY_ETH                           0x00f0  /* U+00F0 LATIN SMALL LETTER ETH */
#define VLK_KEY_NTILDE                        0x00f1  /* U+00F1 LATIN SMALL LETTER N WITH TILDE */
#define VLK_KEY_OGRAVE                        0x00f2  /* U+00F2 LATIN SMALL LETTER O WITH GRAVE */
#define VLK_KEY_OACUTE                        0x00f3  /* U+00F3 LATIN SMALL LETTER O WITH ACUTE */
#define VLK_KEY_OCIRCUMFLEX                   0x00f4  /* U+00F4 LATIN SMALL LETTER O WITH CIRCUMFLEX */
#define VLK_KEY_OTILDE                        0x00f5  /* U+00F5 LATIN SMALL LETTER O WITH TILDE */
#define VLK_KEY_ODIAERESIS                    0x00f6  /* U+00F6 LATIN SMALL LETTER O WITH DIAERESIS */
#define VLK_KEY_DIVISION                      0x00f7  /* U+00F7 DIVISION SIGN */
#define VLK_KEY_OSLASH                        0x00f8  /* U+00F8 LATIN SMALL LETTER O WITH STROKE */
#define VLK_KEY_OOBLIQUE                      0x00f8  /* U+00F8 LATIN SMALL LETTER O WITH STROKE */
#define VLK_KEY_UGRAVE                        0x00f9  /* U+00F9 LATIN SMALL LETTER U WITH GRAVE */
#define VLK_KEY_UACUTE                        0x00fa  /* U+00FA LATIN SMALL LETTER U WITH ACUTE */
#define VLK_KEY_UCIRCUMFLEX                   0x00fb  /* U+00FB LATIN SMALL LETTER U WITH CIRCUMFLEX */
#define VLK_KEY_UDIAERESIS                    0x00fc  /* U+00FC LATIN SMALL LETTER U WITH DIAERESIS */
#define VLK_KEY_YACUTE                        0x00fd  /* U+00FD LATIN SMALL LETTER Y WITH ACUTE */
#define VLK_KEY_THORN                         0x00fe  /* U+00FE LATIN SMALL LETTER THORN */
#define VLK_KEY_YDIAERESIS                    0x00ff  /* U+00FF LATIN SMALL LETTER Y WITH DIAERESIS */

namespace Velkro
{
   	typedef void (*EventCallback)(std::unique_ptr<Event> event);

   	class Window
   	{
   	public:
    	Window(const char* title, unsigned int width, unsigned int height)
      	{
      		m_Display = XOpenDisplay(NULL);
      		if (m_Display == NULL) 
      		{
      		   VLK_FATAL("Cannot open display!");
      		}

      		m_Screen = DefaultScreen(m_Display);
      		m_Window = XCreateSimpleWindow(m_Display, RootWindow(m_Display, m_Screen), 10, 10, width, height, 1,
      		                               BlackPixel(m_Display, m_Screen), WhitePixel(m_Display, m_Screen));
      		XSelectInput(m_Display, m_Window, ExposureMask | KeyPressMask);
      		XMapWindow(m_Display, m_Window);

      		XGetWindowAttributes(m_Display, m_Window, &m_WinAttributes);

      		XStoreName(m_Display, m_Window, title);

			XSelectInput(m_Display, m_Window, KeyPressMask | KeyReleaseMask);
      	}
      	~Window()
      	{
      	  	XCloseDisplay(m_Display);
      	}

      	void Update()
      	{
      	  	while (XPending(m_Display))
      	   	{
				XEvent event;
      	      	XNextEvent(m_Display, &event);
				
				KeySym keysym = XKeycodeToKeysym(m_Display, event.xkey.keycode, 0);

      	    	if (event.type == KeyPress)
      	      	{
					if (!m_KeyHeld)
					{
						m_EventCallback(std::make_unique<KeyEvent>(VLK_PRESS, keysym));
					}
					else
					{
						m_EventCallback(std::make_unique<KeyEvent>(VLK_HELD, keysym));
					}					
      	      	}
				else if (event.type == KeyRelease)
				{
					char keys[32];
            		XQueryKeymap(m_Display, keys);

            		if(!(keys[event.xkey.keycode>>3] & (0x1 << (event.xkey.keycode % 8))))
					{
						m_KeyHeld = false;

   						m_EventCallback(std::make_unique<KeyEvent>(VLK_RELEASE, keysym));
					}
					else
					{
						m_KeyHeld = true;
					}
				}
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

      	static void SetEventCallback(EventCallback callback)
		{
			m_EventCallback = callback;
		}

   	private:
      	Display* m_Display;
      	XID m_Window;
      	XWindowAttributes m_WinAttributes;      	
      	int m_Screen;

      	static inline EventCallback m_EventCallback;

		bool m_KeyHeld;
   };
}