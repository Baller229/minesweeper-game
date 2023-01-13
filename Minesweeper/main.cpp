#include <iostream>
#include <string>
#include <vector>
using namespace std;

// =======================================================

struct Node
{
	string label;
	int bombs_around = 0;
	int max_bombs = 0;
	int probability = 0;

};

// =======================================================

int ROWS;
int COLS;
int BOMBS;
vector<vector<Node>> GRID;

// =======================================================
// Check index out of bounds
// =======================================================
bool isOutOfGrid(int row, int col)
{
	if (row < 0 || row >= ROWS)
	{
		return true;
	}
	if (col < 0 || row >= COLS)
	{
		return true;
	}
	return false;

}

// ====================================================================
// INCREMENT Node 'O' probability | U | D | L | R | UL | UR | DL | DR |
// ====================================================================

void incrementO(int row, int col)
{
	// | UP | row - 1 | col |
	if (!(isOutOfGrid(row - 1, col)))
	{
		if (GRID[row - 1][col].label == "o")
		{
			GRID[row - 1][col].probability++;
		}
	}

	// | DOWN | row + 1 | col |
	if (!(isOutOfGrid(row + 1, col)))
	{
		if (GRID[row + 1][col].label == "o")
		{
			GRID[row + 1][col].probability++;
		}
	}

	// | LEFT | row | col - 1 |
	if (!(isOutOfGrid(row, col - 1)))
	{
		if (GRID[row][col - 1].label == "o")
		{
			GRID[row][col - 1].probability++;
		}
	}

	// | RIGHT | row | col + 1 |
	if (!(isOutOfGrid(row, col + 1)))
	{
		if (GRID[row][col + 1].label == "o")
		{
			GRID[row][col + 1].probability++;
		}

	}

	// | UP LEFT | row - 1 | col - 1 |
	if (!(isOutOfGrid(row - 1, col - 1)))
	{
		if (GRID[row - 1][col - 1].label == "o")
		{
			GRID[row - 1][col - 1].probability++;
		}
	}

	// | UP RIGHT | row - 1 | col + 1 |
	if (!(isOutOfGrid(row - 1, col + 1)))
	{
		if (GRID[row - 1][col + 1].label == "o")
		{
			GRID[row - 1][col + 1].probability++;
		}
	}

	// | DOWN LEFT | row + 1 | col - 1 |
	if (!(isOutOfGrid(row + 1, col - 1)))
	{
		if (GRID[row + 1][col - 1].label == "o")
		{
			GRID[row + 1][col - 1].probability++;
		}
	}

	// | UP RIGHT | row + 1 | col + 1|
	if (!(isOutOfGrid(row + 1, col + 1)))
	{
		if (GRID[row + 1][col + 1].label == "o")
		{
			GRID[row + 1][col + 1].probability++;
		}
	}
}
// =======================================================
// ANALYZE Node 'O' | U | D | L | R | UL | UR | DL | DR |
// =======================================================

int analyzeO(int row, int col)
{
	// | UP | row - 1 | col |
	if (!(isOutOfGrid(row - 1, col)))
	{
		if (GRID[row - 1][col].label == "o")
		{
			cout << "STEP " << row - 1 << " " << col << endl;
			return 1;
		}
	}

	// | DOWN | row + 1 | col |
	if (!(isOutOfGrid(row + 1, col)))
	{
		if (GRID[row + 1][col].label == "o")
		{
			cout << "STEP " << row + 1 << " " << col << endl;
			return 1;
		}
	}

	// | LEFT | row | col - 1 |
	if (!(isOutOfGrid(row, col - 1)))
	{
		if (GRID[row][col - 1].label == "o")
		{
			cout << "STEP " << row << " " << col - 1 << endl;
			return 1;
		}
	}

	// | RIGHT | row | col + 1 |
	if (!(isOutOfGrid(row, col + 1)))
	{
		if (GRID[row][col + 1].label == "o")
		{
			cout << "STEP " << row << " " << col + 1 << endl;
			return 1;
		}

	}

	// | UP LEFT | row - 1 | col - 1 |
	if (!(isOutOfGrid(row - 1, col - 1)))
	{
		if (GRID[row - 1][col - 1].label == "o")
		{
			cout << "STEP " << row - 1 << " " << col - 1 << endl;
			return 1;
		}
	}

	// | UP RIGHT | row - 1 | col + 1 |
	if (!(isOutOfGrid(row - 1, col + 1)))
	{
		if (GRID[row - 1][col + 1].label == "o")
		{
			cout << "STEP " << row - 1 << " " << col + 1 << endl;
			return 1;
		}
	}

	// | DOWN LEFT | row + 1 | col - 1 |
	if (!(isOutOfGrid(row + 1, col - 1)))
	{
		if (GRID[row + 1][col - 1].label == "o")
		{
			cout << "STEP " << row + 1 << " " << col - 1 << endl;
			return 1;
		}
	}

	// | UP RIGHT | row + 1 | col + 1|
	if (!(isOutOfGrid(row + 1, col + 1)))
	{
		if (GRID[row + 1][col + 1].label == "o")
		{
			cout << "STEP " << row + 1 << " " << col + 1 << endl;
			return 1;
		}
	}
	return 0;
}

// =======================================================
// ANALYZE BOMBS U | D | L | R | UL | UR | DL | DR |
// =======================================================
void analyzeBombs(int row, int col)
{
	// | UP | row - 1 | col |
	if (!(isOutOfGrid(row - 1, col)))
	{
		if (GRID[row - 1][col].label == "p")
		{
			GRID[row][col].bombs_around++;
		}
	}

	// | DOWN | row + 1 | col |
	if (!(isOutOfGrid(row + 1, col)))
	{
		if (GRID[row + 1][col].label == "p")
		{
			GRID[row][col].bombs_around++;
		}
	}

	// | LEFT | row | col - 1 |
	if (!(isOutOfGrid(row, col - 1 )))
	{
		if (GRID[row][col - 1].label == "p")
		{
			GRID[row][col].bombs_around++;
		}
	}

	// | RIGHT | row | col + 1 |
	if (!(isOutOfGrid(row, col + 1)))
	{
		if (GRID[row][col + 1].label == "p")
		{
			GRID[row][col].bombs_around++;
		}

	}

	// | UP LEFT | row - 1 | col - 1 |
	if (!(isOutOfGrid(row - 1, col - 1)))
	{
		if (GRID[row - 1][col - 1].label == "p")
		{
			GRID[row][col].bombs_around++;
		}
	}

	// | UP RIGHT | row - 1 | col + 1 |
	if (!(isOutOfGrid(row - 1, col + 1)))
	{
		if (GRID[row - 1][col + 1].label == "p")
		{
			GRID[row][col].bombs_around++;
		}
	}

	// | DOWN LEFT | row + 1 | col - 1 |
	if (!(isOutOfGrid(row + 1, col - 1)))
	{
		if (GRID[row + 1][col - 1].label == "p")
		{
			GRID[row][col].bombs_around++;
		}
	}

	// | DOWN RIGHT | row + 1 | col + 1|
	if (!(isOutOfGrid(row + 1, col + 1)))
	{
		if (GRID[row + 1][col + 1].label == "p")
		{
			GRID[row][col].bombs_around++;
		}
	}

}
// =======================================================
// ANALYZE NODE 
// =======================================================

int analyzeNode(int row, int col) 
{
	// Node <1-8> priradim kolko moze mat max bomb okolo seba
	GRID[row][col].max_bombs = stoi(GRID[row][col].label);
	
	// potom pozriem ci ma bomby okolo seba
	analyzeBombs(row, col);
		//ak ma vsetky co moze mat
		if (GRID[row][col].max_bombs == GRID[row][col].bombs_around)
		{
			/* potom pozriem na vsetky 'o' okolo seba
			   ak ma tak zoberiem prve a dam STEP
			   ak nema tak poracujem v iterateGrid na dalsi */
			if (analyzeO(row, col) == 1)
			{
				//spravil som step
				return 1;
			}
			else 
			{
				// nespravil som ziadny krok tak musim iterovat dalej
				return 0;
			}	
		}
		    
		//ak NEMA vsetky bomby co moze mat 		
		else 
		{
			/* potom pozriem na vsetky 'o' okolo seba
			   a vsetky inkrementujem o 1 (probability++)
			   a pokracujem v iterateGrid na dalsi */
			incrementO(row, col);

			// nespravil som ziadny krok tak musim iterovat dalej
			return 0;
		}
}

// =======================================================
// CHECK DIGITS IN STRING GRID
// =======================================================

bool checkDigitsNode(const string& arg)
{
	bool isDigit;
	isDigit = arg.find_first_not_of("0123456789") == string::npos;
	if (!(isDigit))
	{
		return false;
	}
	return true;
}

// =======================================================
// CHECK DIGITS IN ARGS
// =======================================================

void checkDigits(const string& arg)
{
	bool isDigit;
	isDigit = arg.find_first_not_of("0123456789") == string::npos;
	if (!(isDigit))
	{
		cout << "ERR: nie su to len cisla: " << arg << endl;
		exit(1);
	}
}

// =======================================================
// ITERATE GRID
// =======================================================
void testPrintGrid()
{
	for (size_t i = 0; i < GRID.size(); i++)
	{
		for (size_t j = 0; j < GRID[i].size(); j++)
		{
			cout << GRID[i][j].label;
		}
		cout << endl;
	}
}
// =======================================================
// ITERATE GRID
// =======================================================
int iterateGrid() 
{
	for (size_t i = 0; i < GRID.size(); i++)
	{
		for (size_t j = 0; j < GRID[i].size(); j++)
		{
			string lbl = GRID[i][j].label;
			if (checkDigitsNode(lbl))
			{
				analyzeNode((int)i, (int)j);
				//cout << "d: " << lbl << endl;
			}
		}
	}
	return 0;
}

// =======================================================
// PLAY
// =======================================================

void play() 
{
	iterateGrid();
}


// =======================================================
// STDIN FOR GRID
// =======================================================

vector<vector<Node>> createVectorGrid()
{
	vector<vector<Node>> v (ROWS, vector<Node>(COLS));
	return v;
}

// =======================================================
// CLEAR GRID
// =======================================================

void clearVectorGrid()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			GRID[i][j].label.pop_back();
			GRID[i][j].bombs_around = 0;
			GRID[i][j].max_bombs = 0;
			GRID[i][j].probability = 0;


		}
	}
}
// =======================================================
// LOAD GRID
// =======================================================

void loadVectorGrid(int currRow, string row)
{
	for (size_t i = 0; i < row.size(); i++)
	{
		GRID[currRow][i].label.push_back(row[i]);
	}
}

// =======================================================
// CHECK LABELS IN GETLINE INPUT
// =======================================================

void checkLabels(const string& inputRow)
{
	bool containsLabels;
	containsLabels = inputRow.find_first_not_of("op.12345678") == string::npos;
	if (!(containsLabels))
	{
		cout << "ERR: neobsahuje len dane labels: " << inputRow << endl;
		exit(1);
	}
	if ((int)inputRow.size() != COLS)
	{
		if ((int)inputRow.size() == 0)
		{
			cout << "KONIEC HRY: " << inputRow.size() << endl;
			exit(0);
		}
		cout << "ERR: dlzka vstupneho riadku vacsia ako COLS size: " << inputRow.size() << endl;
		exit(1);
	}
}

// =======================================================
// STDIN FOR GRID
// =======================================================
void gridInput()
{
	 
	
	
	for (int i = 0; i < ROWS; i++)
	{
		string input_row;
		getline(cin, input_row);
		checkLabels(input_row);
		loadVectorGrid(i, input_row);
		//cout << "row:" << input_row << endl;

	}
}

// =======================================================
// CHECK ARGUMENTS
// =======================================================
void checkArguments(int argc, char* argv[])
{
	// pocet argc musi byt 4
	if (argc != 4) 
	{
		cout << "ERR: pocet argumentov: " << argc << endl;
		exit(1);
	}
	
	// argv musia byt len cisla
	checkDigits(argv[1]);
	checkDigits(argv[2]);
	checkDigits(argv[3]);

	ROWS = stoi(argv[1]);
	COLS = stoi(argv[2]);
	BOMBS = stoi(argv[3]);

	if (ROWS < 2 || ROWS > 100)
	{
		cout << "ERR: pocet riadkov mimo rozsah: " << ROWS << endl;
		exit(1);
	}
	if (COLS < 2 || COLS > 100)
	{
		cout << "ERR: pocet stlpcov mimo rozsah: " << COLS << endl;
		exit(1);
	}
	if (BOMBS <= 0 || BOMBS >= (ROWS*COLS))
	{
		cout << "ERR: pocet bomb mimo rozsah: " << BOMBS << endl;
		exit(1);
	}

}

// =======================================================
// MAIN
// =======================================================

int main(int argc, char* argv[])
{
	cout << "*** Minesweeper Bot ***" << endl;
	checkArguments(argc, argv);
	GRID = createVectorGrid();
	gridInput(); 
	//testPrintGrid();
	play();
	//clearVectorGrid();
	//gridInput();

	return 0;
}

// =======================================================
