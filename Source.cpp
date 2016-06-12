#include<iostream>
#include<conio.h>
#include"conmanip.h"

#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESC_EXIT 27

using namespace std;
using namespace conmanip;


class viewCalculatorConsole
{

private:
	
	int x_axis, y_axis; //for X-Y COORDINATES and Cursor movement.
	int rows, cols;  // for printing numbers in ROWS and COLUMNS.

public:
	
	viewCalculatorConsole() { rows = 0; cols = 1; }
	void setX(int x){ x_axis = x; }
	int getX(){ return x_axis; }
	void setY(int y){ y_axis = y; }
	int getY(){ return y_axis; }
	void setRows(int r){ rows = r; }
	int getRows(){ return rows; }
	void setCols(int c){ cols = c; }
	int getCols(){ return cols; }
	

	void calculator_KEYS()
	{
		setX(0); setY(0);
		gotoxy(getX(), getY());
		cout
			//		<< settextcolor(console_text_colors::light_white)
			<< endl << "\t\t       Scientific Calculator"
			<< endl << "\t ==============================================="
			<< endl << "\t|\t\t\t\t\t\t|" << endl << "\t|\t\t\t\t\t\t|"
			<< endl << "\t|\t\t\t\t\t\t|" << endl << "\t|\t\t\t\t\t\t|"
			<< endl << "\t|===============================================|"
			<< endl << "\t|\t7\t||\t8\t||\t9\t|"
			<< endl << "\t|===============================================|"
			<< endl << "\t|\t4\t||\t5\t||\t6\t|"
			<< endl << "\t|===============================================|"
			<< endl << "\t|\t1\t||\t2\t||\t3\t|"
			<< endl << "\t|===============================================|"
			<< endl << "\t|\t.\t||\t0\t||\t=\t|"
			<< endl << "\t|===============================================|";
		gotoxy(0,17);

		cout
			<< "1- Press ESC to exit" << endl
			<< "2- Press F1 to turn on Statistical Functionality Mode" << endl
			<< "3- Press F2 to turn on Basic Calculus Mode" << endl
			<< "4- Press F3 to turn on Linear Algebra Mode" << endl;
	}


	void key_up()
	{
		if (getY() > 8)
		{
			setY(getY() - 2);
			gotoxy(getX(), getY());
		}
	}

	void key_down()
	{
		if (getY() < 14)
		{
			setY(getY() + 2);
			gotoxy(getX(), getY());
		}
	}
	void key_left()
	{
		if (getX() > 16)
		{
			setX(getX() - 16);
			gotoxy(getX(), getY());
			setCols(getCols() - 1);
		}
	}
	void key_right()
	{
		if (getX() < 48)
		{
			setX(getX() + 16);
			gotoxy(getX(), getY());
			setCols(getCols() + 1);
		}
	}

	void key_enter()
	{

	}

	void gotoxy(int cols, int rows)
	{
		HANDLE hConsoleOutput;
		COORD cursor_position;
		cout.flush();
		cursor_position.X = cols;			cursor_position.Y = rows;
		hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsoleOutput, cursor_position);
	}

};


class spreadsheet
{
	int length, width;
public:
	spreadsheet(){ length = 600; width = 600; }
	void setConsoleSize()
	{
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r); //stores the console's current dimensions
		MoveWindow(console, r.left, r.top, this->length, this->width, TRUE); // 800 width, 100 height
	}
};


int main()
{
	spreadsheet s; s.setConsoleSize();
	viewCalculatorConsole c;
	c.calculator_KEYS(); c.setY(8); c.setX(16); c.gotoxy(c.getX(), c.getY());


	int X = 1, Y = 1;
	char key;
	bool loop = true;
	while (loop)
	{
		if (_kbhit())//checks if key is pressed
		{
			key = _getch();//stores key value
			switch (key)
			{
			case KEY_UP:
				c.key_up();
				Y -= 1;
				break;
			case KEY_DOWN:
				c.key_down();
				Y += 1;
				break;
			case KEY_LEFT:
				c.key_left();
				X -= 1;
				break;
			case KEY_RIGHT:
				c.key_right();
				X += 1;
				break;
			case KEY_ENTER:

				break;
			case KEY_ESC_EXIT:
				c.gotoxy(0, 0);
				cout << "EXITING......";
				loop = false;
				break;
				
			}
		}
	}
	return 0;
}