/*  graphics.h

	�� VC ��ģ�� Borland BGI ��ͼ�⣬ʵ�ּ򵥵Ļ�ͼ

	2009-9-9 by yw80@msn.com
	http://hi.baidu.com/yangw80
*/

#pragma once

#pragma comment(lib,"graphics.lib")

/* debug ģʽʱ������ release ģʽ�Ŀ��ļ� */
#ifdef _DEBUG
#pragma comment(linker, "/NODEFAULTLIB:libc.lib")
#endif

#include "windows.h"

#define pointtype POINT
#define MAXCOLORS 0xffffff
#define PI 3.1415926535

/* Ϊ�˼��� Borland C++ 3.1 �����������嶨�� */
#define DETECT 0
#define VGA	0
#define VGAHI 0

/* ��ʼ������ */
enum init_flags
{
	SHOWCONSOLE = 1		// ����ͼ��ģʽʱ����������̨����ʾ
};

/* ��ɫ�������� */
enum COLORS
{
	BLACK	= 0,
	BLUE	= 0xA80000,
	GREEN	= 0x00A800,
	CYAN	= 0xA8A800,
	RED		= 0x0000A8,
	MAGENTA	= 0xA800A8,
	BROWN	= 0x0054A8,
	LIGHTGRAY	= 0xA8A8A8,
	DARKGRAY	= 0x545454,
	LIGHTBLUE	= 0xFC5454,
	LIGHTGREEN	= 0x54FC54,
	LIGHTCYAN	= 0xFCFC54,
	LIGHTRED	= 0x5454FC,
	LIGHTMAGENTA= 0xFC54FC,
	YELLOW	= 0x54FCFC,
	WHITE	= 0xFCFCFC
};

/* ��ͼ������Ϣ */
struct viewporttype
{
	int left, top, right, bottom;
	int clip;
};

/* ����ʽ */
enum line_styles
{
    SOLID_LINE   = 0,
    DOTTED_LINE  = 1,
    CENTER_LINE  = 2,
    DASHED_LINE  = 3,
    USERBIT_LINE = 4,   /* User defined line style */
};

/* �߿� */
enum line_widths
{
    NORM_WIDTH  = 1,
    THICK_WIDTH = 3,
};

/* ���� */
struct linesettingstype
{
    int linestyle;
    unsigned upattern;
    int thickness;
};

/* ���ģʽ */
enum fill_patterns
{
    EMPTY_FILL,		/* fills area in background color */
    SOLID_FILL,		/* fills area in solid fill color */
    LINE_FILL,		/* --- fill */
    LTSLASH_FILL,	/* /// fill */
    SLASH_FILL,		/* /// fill with thick lines */
    BKSLASH_FILL,	/* \\\ fill with thick lines */
    LTBKSLASH_FILL,	/* \\\ fill */
    HATCH_FILL,		/* light hatch fill */
    XHATCH_FILL,	/* heavy cross hatch fill */
    INTERLEAVE_FILL,/* interleaving line fill */
    WIDE_DOT_FILL,	/* Widely spaced dot fill */
    CLOSE_DOT_FILL,	/* Closely spaced dot fill */
    USER_FILL		/* user defined fill */
};

/* ������� */
struct fillsettingstype
{
    int pattern;
    int color;
};

/* Բ��������Ϣ��Ӧ���� getarccoords() */
struct arccoordstype
{
    int x, y;
    int xstart, ystart, xend, yend;
};

/* λ����ģʽ */
enum putimage_ops
{
	COPY_PUT = SRCCOPY,		/* MOV */
	XOR_PUT = SRCINVERT,	/* XOR */
	OR_PUT = SRCPAINT,		/* OR  */
	AND_PUT = SRCAND,		/* AND */
	NOT_PUT = NOTSRCCOPY	/* NOT */
};

/* ����ͼ�� */
class IMAGE
{
private:
	HBITMAP m_hBmp;
	HDC m_hDC;
	int m_width, m_height;
public:
	IMAGE();
	~IMAGE();
	void getimage(int left, int top, int right, int bottom);
	void getimage(const char *imagefile);
	void getimage(const IMAGE *imgsrc, int left, int top, int right, int bottom);
	void putimage(int left, int top, int op);

	friend void IMAGE::getimage(const IMAGE *imgsrc, int left, int top, int right, int bottom);
};



/* ��ͼģʽ��غ��� */

void initgraph(int* gdriver, int* gmode, char* path);	/* ���� Borland C++ 3.1 �����أ�Ĭ�� 640x480@24bit */
void initgraph(int Width, int Height);					/* ��ʼ��ͼ�λ��� */
void initgraph(int Width, int Height, int Flag);		/* ��ʼ��ͼ�λ��� */
void closegraph();										/* �ر�ͼ�λ��� */


/* ��ͼ�������� */

void cleardevice();					/* ���� */

COLORREF getcolor();				/* ��ȡ��ǰ��ͼǰ��ɫ */
void setcolor(COLORREF color);		/* ���õ�ǰ��ͼǰ��ɫ */
COLORREF getbkcolor();				/* ��ȡ��ǰ��ͼ����ɫ */
void setbkcolor(COLORREF color);	/* ���õ�ǰ��ͼ����ɫ */

void getviewsettings(struct viewporttype *viewport);					/* ��ȡ��ͼ��Ϣ */
void setviewport(int left, int top, int right, int bottom, int clip);	/* ������ͼ */
void clearviewport();													/* �����ͼ */

void getlinesettings(struct linesettingstype *lineinfo);				/* ��ȡ��ǰ���� */
void setlinestyle(int linestyle, unsigned int upattern, int thickness);	/* ���õ�ǰ���� */

void getfillsettings(struct fillsettingstype *fillinfo);	/* ��ȡ������� */
void setfillstyle(int pattern, int color);					/* ����������� */
void getfillpattern(char *pattern);							/* ��ȡ�Զ���������� */
void setfillpattern(const char *upattern, int color);		/* �����Զ���������� */

void getaspectratio(int *xasp, int *yasp);	/* ��ȡ��ǰ�������� */
void setaspectratio(int xasp, int yasp);	/* ���õ�ǰ�������� */

void setwritemode(int mode);				/* ���û�ͼλ����ģʽ */

void graphdefaults();						/* �������л�ͼ����ΪĬ��ֵ */


/* ��ͼ���� */

COLORREF getpixel(int x, int y);				/* ��ȡ�����ɫ */
void putpixel(int x, int y, COLORREF color);	/* ���� */

void moveto(int x, int y);						/* �ƶ���ǰ��(��������) */
void moverel(int dx, int dy);					/* �ƶ���ǰ��(�������) */

void line(int x1, int y1, int x2, int y2);		/* ���� */
void linerel(int dx, int dy);					/* ����(���������) */
void lineto(int x, int y);						/* ����(����������) */

void rectangle(int left, int top, int right, int bottom);	/* ������ */

void getarccoords(struct arccoordstype *arccoords);								/* ��ȡԲ��������Ϣ */
void arc(int x, int y, int stangle, int endangle, int radius);					/* ��Բ�� */
void circle(int x, int y, int radius);											/* ��Բ */
void pieslice(int x, int y, int stangle, int endangle, int radius);				/* �����Բ���� */
void ellipse(int x, int y, int stangle, int endangle, int xradius, int yradius);/* ����Բ���� */
void fillellipse(int x, int y, int xradius, int yradius);						/* �������Բ */
void sector(int x, int y, int stangle, int endangle, int xradius, int yradius);	/* �������Բ���� */

void bar(int left, int top, int right, int bottom);								/* ���ޱ߿������� */
void bar3d(int left, int top, int right, int bottom, int depth, int topflag);	/* ���б߿���ά������ */

void drawpoly(int numpoints, const int *polypoints);	/* ������� */
void fillpoly(int numpoints, const int *polypoints);	/* �����Ķ���� */
void floodfill(int x, int y, int border);				/* ������� */


/* ������غ��� */

void outtext(LPCTSTR textstring);					/* �ڵ�ǰλ��������� */
void outtextxy(int x, int y, LPCTSTR textstring);	/* ��ָ��λ��������� */
int textwidth(LPCTSTR textstring);					/* ��ȡ�ַ���ռ�õ����ؿ� */
int textheight(LPCTSTR textstring);					/* ��ȡ�ַ���ռ�õ����ظ� */

/* ���õ�ǰ������ʽ
		nHeight: �ַ���ƽ���߶�
		nWidth: �ַ���ƽ�����
		nEscapement: �ַ�������д�Ƕȣ���λ 0.1 �ȡ�
		nOrientation: ÿ���ַ�����д�Ƕȣ���λ 0.1 �ȡ�
		fnWeight: �ַ��ıʻ���ϸ�����õ��� 400��Ĭ�� 0 ���ɡ�
		fdwItalic: �Ƿ�б�壬TRUE / FALSE
		fdwUnderline: �Ƿ��»��ߣ�TRUE / FALSE
		fdwStrikeOut: �Ƿ�ɾ���ߣ�TRUE / FALSE
		lpszFace: �������� */
void SetFont(int nHeight,int nWidth,int nEscapement,int nOrientation,int fnWeight,BYTE fdwItalic,BYTE fdwUnderline,BYTE fdwStrikeOut,LPCTSTR lpszFace);
void SetFont(const LOGFONT *font);	/* ���õ�ǰ������ʽ */
void GetFont(LOGFONT *font);		/* ��ȡ��ǰ������ʽ */


/* ͼ������ */

void getimage(int left, int top, int right, int bottom, IMAGE *imgdst);			/* ����Ļ��ȡͼ�� */
void getimage(const char *imagefile, IMAGE *imgdst);							/* �� BMP �ļ���ȡͼ�� */
void getimage(const IMAGE *imgsrc, int left, int top, int right, int bottom, IMAGE *imgdst);	/* �� IMAGE �����ȡͼ�� */
void putimage(int left, int top, IMAGE *img, int op);							/* ����ͼ�� */



/* �������� */

int	getmaxcolor();	/* ��ȡ�����ɫֵ */
int	getmaxx();		/* ��ȡ��� x ���� */
int	getmaxy();		/* ��ȡ��� y ���� */
int	getx();			/* ��ȡ��ǰ x ���� */
int	gety();			/* ��ȡ��ǰ y ���� */
int GetGraphicsVer();		/* ��ȡ��ǰ�汾 */
char* GetGraphicsAuthor();	/* ���� */
