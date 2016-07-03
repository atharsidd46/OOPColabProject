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

//string value = "";
//int intvalue = 0;
 //static function to be added for storage of values
class calculator
{
private:
	
	static string value ;
	static int intvalue ;
public:

	void setSvalue(string s){ value = s; }
	string getSvalue(){ return value; }

	void setintValue(int n){ intvalue = n; }
	int getintValue(){ return intvalue; }
	
};

int calculator::intvalue = 0;
string calculator::value = " ";

class viewCalculatorConsole
{

private:
	calculator c;
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
			<< endl << "\t ==============================================================="
			<< endl << "\t|\t\t\t\t\t\t\t\t|" << endl << "\t|\t\t\t\t\t\t\t\t|"
			<< endl << "\t|\t\t\t\t\t\t\t\t|" << endl << "\t|\t\t\t\t\t\t\t\t|"
			<< endl << "\t|\t\t\t\t\t\t\t\t|" << endl << "\t|\t\t\t\t\t\t\t\t|"
			<< endl << "\t|\t\t\t\t\t\t\t\t|" << endl << "\t|\t\t\t\t\t\t\t\t|"
			<< endl << "\t|===============================================================|"
			<< endl << "\t|\t7\t||\t8\t||\t9\t||\t+\t|"
			<< endl << "\t|===============================================================|"
			<< endl << "\t|\t4\t||\t5\t||\t6\t||\t-\t|"
			<< endl << "\t|===============================================================|"
			<< endl << "\t|\t1\t||\t2\t||\t3\t||\t/\t|"
			<< endl << "\t|===============================================================|"
			<< endl << "\t|\t.\t||\t0\t||\t=\t||\tx\t|"
			<< endl << "\t|===============================================================|";
		
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
		if (getY() > 12)
		{
			setY(getY() - 2);
			gotoxy(getX(), getY());
		}
	}
	void key_down()
	{
		if (getY() < 18)
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
		if (getY() == 12)
		{
			if (getX() == 16)
				return "7";
			else if (getX() == 32)
				return "8";
			else if (getX() == 48)
				return "9";
		}
		else if (getY() == 14)
		{
			if (getX() == 16)
				return "4";
			else if (getX() == 32)
				return "5";
			else if (getX() == 48)
				return "6";
		}
		else if (getY() == 16)
		{
			if (getX() == 16)
				return "1";
			else if (getX() == 32)
				return "2";
			else if (getX() == 48)
				return "3";
		}
		else if (getY() == 18)
		{
			if (getX() == 16)
				return ".";
			else if (getX() == 32)
				return "0";
			else if (getX() == 48)
				return "=";
		}	
	}

	int backspace(int backCurserPos)
	{

		if (c.getSvalue() != "\0" && c.getSvalue().size() > 0)
		{
			backCurserPos--;
			string news = c.getSvalue().substr(0, c.getSvalue().size() - 1);
			c.setSvalue(news);
			cout << "\b \b";
			//c.getSvalue().resize(c.getSvalue().size() - 1);
			//c.setSvalue(c.getSvalue().erase(c.getSvalue().end-1));
		}
		return backCurserPos;
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

class linearAlgebra
{
private:
	viewCalculatorConsole c;
	int numOfCols, numOfRows;
	int **array;

public:
	linearAlgebra()
	{
		numOfCols = 0;
		numOfRows = 0;
	}

	void setNumOfCols(int c){ numOfCols = c; }
	int getNumOfCols(){ return numOfCols; }

	void setNumOfRows(int r){ numOfRows = r; }
	int getNumOfRows(){ return numOfRows; }

	int menu()
	{
		bool loop = true;
		while (loop)
		{
			c.gotoxy(10, 5);
			cout << "Enter your chioce for matrix: " << endl
				<< "\t  1: 4 x 4" << endl
				<< "\t  2: 3 x 3" << endl
				<< "\t  3: 2 x 2" << endl
				<< "\t  4: 1 x 1" << endl
				<< "\t  Chioce: ";
			int choice;
			cin >> choice;
			if (choice == 1)
			{
				return 4;
				loop = false;
			}
			else if (choice == 2)
			{
				return 3;
				loop = false;
			}
			else if (choice == 3)
			{
				return 2;
				loop = false;
			}
			else if (choice == 4)
			{
				return 1;
				loop = false;
			}
			else
			{
				cout << "wrong choice;";
				loop = true;
			}
		}
	}

	void memory(int x, int y)
	{
		array = new int*[x];//getNumOfRows()=x
		for (int i = 0; i < x; i++)//getNumOfRows()=y
			array[i] = new int[y];
	}

	void fill_matrix()
	{
		memory(getNumOfRows(), getNumOfCols());
		for (int i = 0; i < getNumOfRows(); i++)
		{
			std::cout << "row " << i + 1 << "\n";
			for (int j = 0; j < getNumOfCols(); j++)
			{
				std::cout << "column " << j + 1 << "\t";
				std::cout << "Enter values: ";

				std::cin >> array[i][j];
			}
		}
	}

	void print_matrix()
	{
		for (int i = 0; i < getNumOfRows(); ++i)
		{
			for (int j = 0; j < getNumOfCols(); ++j)
				std::cout << array[i][j] << "\t";
			std::cout << "\t\n\t";
		}
	}

	void crossProduct(linearAlgebra m)
	{
		linearAlgebra newM; newM.setNumOfCols(m.getNumOfCols()); newM.setNumOfRows(this->getNumOfRows());
		newM.memory(newM.getNumOfRows(), newM.getNumOfCols());

		if (this->getNumOfCols() == m.getNumOfRows())
		{
			for (int i = 0; i < getNumOfRows(); ++i)
			{
				for (int j = 0; j < m.getNumOfCols(); ++j)
				{
					newM.array[i][j] = 0;
					for (int k = 0; k < getNumOfCols(); ++k)
						newM.array[i][j] = newM.array[i][j] + (this->array[i][k] * m.array[k][j]);
					std::cout << newM.array[i][j] << "\t";
				}
				std::cout << "\n \t";
			}
		}
		else
		{
			std::cout << "Multiplication does not exists. ";
		}

	}

	void dotProduct(linearAlgebra m)
	{
		linearAlgebra newM; newM.setNumOfCols(this->getNumOfCols()); newM.setNumOfRows(this->getNumOfRows());
		newM.memory(newM.getNumOfRows(), newM.getNumOfCols());

		if (this->getNumOfCols() == m.getNumOfCols() && this->getNumOfRows() == m.getNumOfRows())
		{
			for (int i = 0; i < getNumOfRows(); ++i)
			{
				for (int j = 0; j < m.getNumOfCols(); ++j)
				{
					newM.array[i][j] = this->array[i][j] * m.array[i][j];
					std::cout << newM.array[i][j] << "\t";
				}
				std::cout << "\n \t";
			}
		}
		else
		{
			std::cout << "Dot product does not exists.\n"
				<< "For dot product\n"
				<< "Matrix 1 rows number    should be equal to   Matrix 1 rows number\n"
				<< "Matrix 1 Column number  should be equal to   Matrix 1 column number";

		}
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
	int x = 9, y = 10, n ;
	calculator cal;
	//spreadsheet s; s.setConsoleSize();
	viewCalculatorConsole c;
	c.calculator_KEYS(); c.setY(12); c.setX(16); c.gotoxy(c.getX(), c.getY());
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
				cal.setSvalue(cal.getSvalue() + var);
				x++;
				c.gotoxy(x, y);
				
				cout << var;
				
				break;
			case KEY_BACKSPACE:
				//x--;
				n = x;
				x = c.backspace(n);
				
				//c.gotoxy(x, y);
				break;
			case KEY_ESC_EXIT:
				c.gotoxy(0, 0);
				cout << "EXITING......";
				loop = false;
				break;	
			case KEY_F4:
				c.gotoxy(9, 3);
				cout << "Linear Algebra Mode on...";
				linearAlgebra l;
				int i = l.menu();
				break;
			}	
		}
	}
	cal.setintValue(stoi(cal.getSvalue()));
	
	cout << cal.getintValue();
	////cal.setintValue(stoi(cal.getSvalue()));
	
	_getche();
	return 0;
}