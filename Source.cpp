#include<iostream>
#include<conio.h>
#include<string>
#include"conmanip.h"

#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESC_EXIT 27
#define KEY_F1 59
#define KEY_F2 60
#define KEY_F3 61
#define KEY_F4 62
#define KEY_BACKSPACE 8

using namespace std;
using namespace conmanip;

string value = "";
int intvalue = 0;
// static function to be added for storage of values
//class calculator
//{
//private:
	float array[50];
//	string value;
//	int intvalue;
//public:
//	calculator(){}
//	void setSvalue(string s){ value = s; }
//	string getSvalue(){ return value; }
//
//	void setintValue(int n){ intvalue = n; }
//	int getintValue(){ return intvalue; }
//	
//};

class viewCalculatorConsole
{

private:
	//calculator c;
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
		
			setX(0); setY(25);
			gotoxy(getX(), getY());
			cout
				<< "\tF1 : turn on Basic Arithmatic Mode" << endl
				<< "\tF2 : turn on Statistical Functionality Mode" << endl 
				<< "\tF3 : turn on Basic Calculus Mode" << endl 
				<< "\tF4 : turn on Linear Algebra Mode" << endl 
				<< endl << "\t  \tESC : EXIT";

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

	string key_enter()
	{
		if (getY() == 8)
		{
			if (getX() == 16)
				return "7";
			else if (getX() == 32)
				return "8";
			else if (getX() == 48)
				return "9";
		}
		else if (getY() == 10)
		{
			if (getX() == 16)
				return "4";
			else if (getX() == 32)
				return "5";
			else if (getX() == 48)
				return "6";
		}
		else if (getY() == 12)
		{
			if (getX() == 16)
				return "1";
			else if (getX() == 32)
				return "2";
			else if (getX() == 48)
				return "3";
		}
		else if (getY() == 14)
		{
			if (getX() == 16)
				return ".";
			else if (getX() == 32)
				return "0";
			else if (getX() == 48)
				return "=";
		}	
	}

	void backspace()
	{

		if (value != "\0")
		{
			cout << "\b \b";
			
			//value = "\0";
		}
		
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


class console
{
	int length, width;
public:
	console(){ length = 600; width = 600; }
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
	int x = 9 , y = 4;
	//calculator cal;
	//spreadsheet s; s.setConsoleSize();
	viewCalculatorConsole c;
	c.calculator_KEYS(); c.setY(8); c.setX(16); c.gotoxy(c.getX(), c.getY());
	string var;

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
				break;
			case KEY_DOWN:
				c.key_down();
				break;
			case KEY_LEFT:
				c.key_left();
				break;
			case KEY_RIGHT:
				c.key_right();
				break;
			case KEY_ENTER:
				
				var = c.key_enter();
				value = value + var;
				//cal.setSvalue(cal.getSvalue() + var);
				x++;
				c.gotoxy(x, y);
				
				cout << var;
				
				break;
			case KEY_BACKSPACE:
				x--;
				c.backspace();
				
				//c.gotoxy(x, y);
				break;
			case KEY_ESC_EXIT:
				c.gotoxy(0, 0);
				cout << "EXITING......";
				loop = false;
				break;	
			}	
		}
	}
	int intvalue = stoi(value);
	intvalue = intvalue + intvalue;
	cout << intvalue;
	//cal.setintValue(stoi(cal.getSvalue()));
	
	_getche();
	return 0;
}