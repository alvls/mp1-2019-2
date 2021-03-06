#define _CRT_SECURE_NO_WARNINGS

#include "windows.h"
#include "stdio.h"
#include "locale.h"
#include "conio.h"
#include "memory.h"
#include "time.h"

#define true 1
#define false 0

int S_width = 70;
int S_height = 30;

char del[] = "____\n____\n____\n____\n____\n____";
char s0[] = "_##_\n#__#\n#__#\n#__#\n#__#\n_##_";
char s1[] = "__#_\n_##_\n#_#_\n__#_\n__#_\n__#_";
char s2[] = "###_\n___#\n___#\n__#_\n_#__\n####";
char s3[] = "###_\n___#\n###_\n___#\n___#\n###_";
char s4[] = "__#_\n_##_\n#_#_\n####\n__#_\n__#_";
char s5[] = "####\n#___\n###_\n___#\n___#\n###_";
char s6[] = "_##_\n#__#\n#___\n###_\n#__#\n_##_";
char s7[] = "####\n___#\n__#_\n_#__\n_#__\n_#__";
char s8[] = "_##_\n#__#\n_##_\n#__#\n#__#\n_##_";
char s9[] = "_##_\n#__#\n#__#\n_###\n___#\n_##_";
char bull_pic[] = "W_BBBBB_W\n_WB#B#BW_\n__BBBBB__\n__BYBYB__\n___YYY___";
char cow_pic[] = "__B__B__\nWWWWWWWW\n_W_WW_W_\n_WWPPWW_\n_WWPPWW_";
char palka[] = "____\n____\n____\n____\n____\n####";

char* numbers[10] = { s0,s1,s2,s3,s4,s5,s6,s7,s8,s9 };
char* pics[2] = { bull_pic, cow_pic };

enum TColor {BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY,
             DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED,
             LIGHTMAGENTA, YELLOW, WHITE};

//-----------------------------------------------------------------------------
int wherex(void)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return -1;

  CONSOLE_SCREEN_BUFFER_INFO buf;

  GetConsoleScreenBufferInfo(Console, &buf);
  return buf.dwCursorPosition.X;
}

//-----------------------------------------------------------------------------
int wherey(void)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return - 1;

  CONSOLE_SCREEN_BUFFER_INFO buf;

  GetConsoleScreenBufferInfo(Console, &buf);
  return buf.dwCursorPosition.Y;
}

//-----------------------------------------------------------------------------
COORD WhereXY(void)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD pos = {-1, -1};
  if (!Console)
    return pos;

  CONSOLE_SCREEN_BUFFER_INFO buf;

  GetConsoleScreenBufferInfo(Console, &buf);
  return buf.dwCursorPosition;
}

//-----------------------------------------------------------------------------
void clrscr(void)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return;

  CONSOLE_SCREEN_BUFFER_INFO buf;
  GetConsoleScreenBufferInfo(Console, &buf);

  WORD Attr;
  DWORD Count;
  COORD pos = buf.dwCursorPosition;
  ReadConsoleOutputAttribute(Console, &Attr, 1, pos, &Count);

  int col = Attr;
  int width = buf.dwSize.X;
  int height = buf.dwSize.Y;

  COORD zpos;
  zpos.X = 0;
  zpos.Y = 0;
  SetConsoleCursorPosition(Console, zpos);

  FillConsoleOutputAttribute(Console, col, width * height, zpos, &Count);
  FillConsoleOutputCharacter(Console, ' ', width * height, zpos, &Count);
}

//-----------------------------------------------------------------------------
void gotoxy(int x, int y)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return;

  COORD pos;
  pos.X = x;
  pos.Y = y;

  SetConsoleCursorPosition(Console, pos);
}

//-----------------------------------------------------------------------------
void textcolor(int color)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return;

  CONSOLE_SCREEN_BUFFER_INFO buf;
  GetConsoleScreenBufferInfo(Console, &buf);

  WORD Attr;
  DWORD Count;
  COORD pos = buf.dwCursorPosition;
  ReadConsoleOutputAttribute(Console, &Attr, 1, pos, &Count);

  int bk_col = Attr / 16;
  int col = color % 16;
  col = col + bk_col * 16;

  SetConsoleTextAttribute(Console, col);

  char ch;
  pos = WhereXY();
  ReadConsoleOutputCharacter(Console, &ch, 1, pos, &Count);
  printf("%c", ch);
  gotoxy(pos.X, pos.Y);
}

//-----------------------------------------------------------------------------
void textbackground(int color)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return;

  CONSOLE_SCREEN_BUFFER_INFO buf;
  GetConsoleScreenBufferInfo(Console, &buf);

  WORD Attr;
  DWORD Count;
  COORD pos = buf.dwCursorPosition;
  ReadConsoleOutputAttribute(Console, &Attr, 1, pos, &Count);

  int text_col = Attr % 16;
  int col = color % 16;
  col = color * 16 + text_col;

  SetConsoleTextAttribute(Console, col);

  char ch;
  pos = WhereXY();
  ReadConsoleOutputCharacter(Console, &ch, 1, pos, &Count);
  printf("%c", ch);
  gotoxy(pos.X, pos.Y);
}

//-----------------------------------------------------------------------------
void textattr(int color)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return;

  SetConsoleTextAttribute(Console, color);

  DWORD Count;
  char ch;
  COORD pos = WhereXY();
  ReadConsoleOutputCharacter(Console, &ch, 1, pos, &Count);
  printf("%c", ch);
  gotoxy(pos.X, pos.Y);
}

//-----------------------------------------------------------------------------
void setwindow(int width, int height)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return;

  DWORD Mode;

  SMALL_RECT rect;
  rect.Left = 0;
  rect.Right = width - 1;
  rect.Top= 0;
  rect.Bottom = height - 1;
  COORD size;
  size.X = width;
  size.Y = height;
  SetConsoleWindowInfo(Console, true, &rect);
  GetConsoleMode(Console, &Mode);
  SetConsoleMode(Console, Mode);
//  printf("%d %d %d %d", rect.Left, rect.Top, rect.Right, rect.Bottom);
  SetConsoleScreenBufferSize(Console, size);
//  printf("%d %d", size.X, size.Y);
}

//-----------------------------------------------------------------------------
void SetWindow(SMALL_RECT rect, COORD size)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return;

  SetConsoleScreenBufferSize(Console, size);
  SetConsoleWindowInfo(Console, true, &rect);
}

//-----------------------------------------------------------------------------
void GetWindow(SMALL_RECT *rect, COORD *size)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return;

  CONSOLE_SCREEN_BUFFER_INFO buf;
  GetConsoleScreenBufferInfo(Console, &buf);

  *rect = buf.srWindow;
  size->X = buf.dwSize.X;
  size->Y = buf.dwSize.Y;
}

//-----------------------------------------------------------------------------
void HideCursor(void)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return;

  CONSOLE_CURSOR_INFO buf;
  GetConsoleCursorInfo(Console, &buf);
  buf.bVisible = false;
  SetConsoleCursorInfo(Console, &buf);
}

//-----------------------------------------------------------------------------
void ShowCursor(void)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return;

  CONSOLE_CURSOR_INFO buf;
  GetConsoleCursorInfo(Console, &buf);
  buf.bVisible = true;
  SetConsoleCursorInfo(Console, &buf);
}

//-----------------------------------------------------------------------------
void Init(SMALL_RECT &window, COORD &buf, int w, int h)
{
	GetWindow(&window, &buf);
	setwindow(S_width = w, S_height = h);
	system("title GusGraph");
}

//-----------------------------------------------------------------------------
void RenderButton(const char title[], int x0, int y0, bool trig = false)
{
	gotoxy(x0, y0);
	int w = strlen(title) + 4;

	if (trig)
		textcolor(RED);

	for (int i = 0; i < 3; i++)
	{
		char s[1000] = "";
		if ((i == 0) || (i == 2))
		{
			for (int j = 0; j < w; j++)
			{
				strcat(s, "#");
			}
		}
		else
		{
			strcat(s, "# ");
			strcat(s, title);
			strcat(s, " #");
		}
		printf("%s\n", s);
		gotoxy(x0, y0 + i+1);
	}

	textcolor(WHITE);
}

//-----------------------------------------------------------------------------
class MenuElement
{
public:
	char title[200];
	bool trig;
	void (*func)();
	MenuElement(const char t[], void(*f)(), bool b = false)
	{
		SetParam(t, b, f);
	}
	void SetParam(const char t[], bool b, void(*f)())
	{
		strcpy(title, t);
		trig = b;
		func = f;
	}
};

//-----------------------------------------------------------------------------
void RenderEl(MenuElement El, int margin_left, int margin_top)
{
	char s[10000] = "";
	int padding = (S_width - strlen(El.title) - 2*margin_left) / 2;
	int w = 2*padding + strlen(El.title);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < padding; j++)
		{
			strcat(s, " ");
		}
		if (i == 1)
			strcat(s, El.title);
		else
			for (int j = 0; j < strlen(El.title); j++)
			{
				strcat(s, " ");
			}
		for (int j = 0; j < padding; j++)
		{
			strcat(s, " ");
		}
		gotoxy(margin_left, margin_top + i);
		if (El.trig)
			textbackground(RED);
		else
			textbackground(WHITE);
		textcolor(BLACK);
		puts(s);
		textbackground(BLACK);
		textcolor(WHITE);
		strcpy(s, "");
	}
}

//-----------------------------------------------------------------------------
void RenderMenu(MenuElement Menu[], int len)
{
	clrscr();
	HideCursor();
	for (int i = 0; i < len; i++)
	{
		RenderEl(Menu[i] , 20, 3+5*(i));
	}
}

//-----------------------------------------------------------------------------
void Switcher(MenuElement Menu[], int len)
{
	int state = 0;
	bool state_changed = true;
	SMALL_RECT window;
	COORD buf;

	while (true)
	{
		GetWindow(&window, &buf);
		char kb = 0;
		if (_kbhit())
		{
			kb = _getch();
			if (kb == 13)
			{
				clrscr();
				Menu[state].func();
				state_changed = true;
			}
			if (kb == 27)
			{
				clrscr();
				break;
			}
			if (kb == 224)
				kb = _getch();
		}
		Menu[state].trig = false;
		if ((kb == 72) && (state > 0))
		{

			state--;
			state_changed = true;
		}
		if ((kb == 80) && (state < len - 1))
		{
			state++;
			state_changed = true;
		}
		Menu[state].trig = true;
		if (state_changed)
		{
//			setwindow(70, 20);
//			clrscr();
//			setwindow(70, 20);
			RenderMenu(Menu, len);
			GetWindow(&window, &buf);

		}
		state_changed = false;
	}

}

//-----------------------------------------------------------------------------
void draw(char s[], int x0, int y0)
{
	int c = 1;
	gotoxy(x0, y0);
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == '#')
		{
			textbackground(WHITE);
			textcolor(WHITE);
		}
		if (s[i] == 'P')
		{
			textbackground(LIGHTMAGENTA);
			textcolor(LIGHTMAGENTA);
		}
		if (s[i] == 'B')
		{
			textbackground(BROWN);
			textcolor(BROWN);
		}
		if (s[i] == 'W')
		{
			textbackground(WHITE);
			textcolor(WHITE);
		}
		if (s[i] == '_')
		{
			textbackground(BLACK);
			textcolor(BLACK);
		}
		if (s[i] == 'Y')
		{
			textbackground(YELLOW);
			textcolor(YELLOW);
		}
		printf("%c", s[i]);
		if (s[i] == '\n')
		{
			gotoxy(x0, y0 + c);
			c++;
		}
		textbackground(BLACK);
		textcolor(WHITE);
	}
}
//----------------------------------------------------------------------------

void number_input(int x0, int y0, int n, int *input)
{
	char kb;
	int t = clock();
	int input_state = 0;
	bool flag = false;
	HideCursor();
	while (true)
	{
		if (_kbhit())
		{
			kb = _getch();
			if ((47 < kb) && (kb < 58) && (input_state < n))
			{
				draw(del, x0 + (input_state) * 6, y0);
				draw(numbers[kb - 48], x0 + input_state * 6, y0);
				input[input_state] = kb - 48;
				input_state++;
			}
			if ((kb == 8) && (input_state>0))
			{
				draw(del, x0 + (input_state) * 6, y0);
				draw(del, x0 + (input_state - 1) * 6, y0);
				input[input_state] = -1;
				input_state--;
			}
			if (kb == 13)
			{
				if (input_state == n)
					break;
			}
			if (kb == 27)
			{
				input[0] = -1;
				break;
			}

		}
		if (clock() - t > 400)
		{
			if ((flag) && (input_state<n))
			{
				draw(palka, x0 + (input_state) * 6, y0);
				flag = false;
				t = clock();
				continue;
			}
			if (!flag)
			{
				draw(del, x0 + (input_state) * 6, y0);
				flag = true;
				t = clock();
			}
		}

	}
	for (int i = 0; i <= input_state; i++)
	{
		draw(del, x0 + i * 6, y0);
	}
}
//- end of file ---------------------------------------------------------------
