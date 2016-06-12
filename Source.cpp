#include<iostream>
#include<conio.h>
#include"conmanip.h"

#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_ENTER 13

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
			<< endl << "\t       Scientific Calculator"
			<< endl << " ==============================================="
			<< endl << "|\t\t\t\t\t\t|" << endl << "|\t\t\t\t\t\t|"
			<< endl << "|\t\t\t\t\t\t|" << endl << "|\t\t\t\t\t\t|"
			<< endl << "|===============================================|"
			<< endl << "|\t7\t||\t8\t||\t9\t|"
			<< endl << "|===============================================|"
			<< endl << "|\t4\t||\t5\t||\t6\t|"
			<< endl << "|===============================================|"
			<< endl << "|\t1\t||\t2\t||\t3\t|"
			<< endl << "|===============================================|"
			<< endl << "|\t.\t||\t0\t||\t=\t|"
			<< endl << "|===============================================|";
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
		if (getX() > 8)
		{
			setX(getX() - 16);
			gotoxy(getX(), getY());
			setCols(getCols() - 1);
		}
	}
	void key_right()
	{
		if (getX() < 32)
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

int main()
{
	viewCalculatorConsole c;
	c.calculator_KEYS(); c.setY(8); c.setX(8); c.gotoxy(c.getX(), c.getY());


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
				
			}
		}
	}
	

	_getch();
	return 0;
}