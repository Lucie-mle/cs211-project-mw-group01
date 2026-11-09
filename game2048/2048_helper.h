#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

void move_left(int board[][5], int numrows = 5)
{
	 for (int r = 0; r < numrows; r++)
    {
        int temp[5] = {0};
        int index = 0;

        // Move non-zero numbers to the left
        for (int c = 0; c < 5; c++)
        {
            if (board[r][c] != 0)
                temp[index++] = board[r][c];
        }

        // Merge equal adjacent numbers
        for (int i = 0; i < 4; i++)
        {
            if (temp[i] != 0 && temp[i] == temp[i + 1])
            {
                temp[i] *= 2;

                for (int j = i + 1; j < 4; j++)
                    temp[j] = temp[j + 1];

                temp[4] = 0;
            }
        }

        // Copy back to board
        for (int c = 0; c < 5; c++)
            board[r][c] = temp[c];
    }
}

void move_right(int board[][5], int numrows = 5)
{
	for (int r = 0; r < numrows; r++)
    {
        int temp[5] = {0};
        int index = 4;

        // Move non-zero numbers to the right
        for (int c = 4; c >= 0; c--)
        {
            if (board[r][c] != 0)
                temp[index--] = board[r][c];
        }

        // Merge equal adjacent numbers
        for (int i = 4; i > 0; i--)
        {
            if (temp[i] != 0 && temp[i] == temp[i - 1])
            {
                temp[i] *= 2;

                for (int j = i - 1; j > 0; j--)
                    temp[j] = temp[j - 1];

                temp[0] = 0;
            }
        }

        // Copy back to board
        for (int c = 0; c < 5; c++)
            board[r][c] = temp[c];
    }
}

void move_up(int board[][5], int numrows = 5)
{
	 for (int c = 0; c < 5; c++)
    {
        int temp[5] = {0};
        int index = 0;

        // Move non-zero numbers upward
        for (int r = 0; r < numrows; r++)
        {
            if (board[r][c] != 0)
                temp[index++] = board[r][c];
        }

        // Merge equal adjacent numbers
        for (int i = 0; i < 4; i++)
        {
            if (temp[i] != 0 && temp[i] == temp[i + 1])
            {
                temp[i] *= 2;

                for (int j = i + 1; j < 4; j++)
                    temp[j] = temp[j + 1];

                temp[4] = 0;
            }
        }

        // Copy back to board
        for (int r = 0; r < numrows; r++)
            board[r][c] = temp[r];
    }
}

void move_down(int board[][5], int numrows = 5)
{
	for (int c = 0; c < 5; c++)
    {
        int temp[5] = {0};
        int index = 4;

        // Move non-zero numbers downward
        for (int r = numrows - 1; r >= 0; r--)
        {
            if (board[r][c] != 0)
                temp[index--] = board[r][c];
        }

        // Merge equal adjacent numbers
        for (int i = 4; i > 0; i--)
        {
            if (temp[i] != 0 && temp[i] == temp[i - 1])
            {
                temp[i] *= 2;

                for (int j = i - 1; j > 0; j--)
                    temp[j] = temp[j - 1];

                temp[0] = 0;
            }
        }

        // Copy back to board
        for (int r = 0; r < numrows; r++)
            board[r][c] = temp[r];
    }
}


void print_board(int board[][5], int numrows = 5)
{
	cout << endl << "\t-----------------------------------------" << endl;

	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if(board[r][c] > 0)
				cout << "\t|" << right << setw(6) << setfill(' ') << board[r][c];
			else
				cout << "\t|" << right << setw(6) << setfill(' ') << " ";

			//cout << board[r][c] << "\t|\t";
		}
		cout << "\t|" << endl;
		cout << "\t-----------------------------------------" << endl;
	}

	cout << "\t" << endl << endl;
}


void insert_random(int board[][5], int numrows = 5)
{
	int r, c;
	//count empty
	int empty_count = 0;
	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if (board[r][c] == 0)
				empty_count++;
		}
	}

	if (empty_count > 0)
	{
		while (true)
		{
			//generate random location r, c
			r = rand() % numrows;
			c = rand() % numrows;
			//check if empty
			if (board[r][c] == 0)
			{
				//add number randomly {2,4}
				board[r][c] = 2 * (1 + (rand() % 2));
				break;
			}
		}

	}
}

