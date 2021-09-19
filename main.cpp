#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 3;
const int COLS = 3;
int i;
int j;

//declare function prototypes
void getChoice(char b[][COLS], bool playerToggle);
bool gameOver(char b[][COLS]);
void fillBoard(char b[][COLS]);
void showBoard(char b[][COLS]);
void Stupid_AI(char b[][COLS]);



int main()
{
    char board[ROWS][COLS];
    bool playerToggle = false;
    
    fillBoard(board);
    showBoard(board);
    
    while (!gameOver(board))
    {
        getChoice(board, playerToggle);
        showBoard(board);
        playerToggle = !playerToggle;
    }
    
    return 0;
}

void fillBoard(char stars[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            stars[i][j] = '*';
        }
        
    }
}
///TODO (0)
///Define fillBoard
///Use a nested for loop to Fill the 2D array with '*'s


///TODO (1)
///Define showBoard
///Use a nested for loop to print the board
///For each row, print the row number, then use an inner for loop to print each cell, separated by a space
///print a newline when the inner for loop is complete to move on to the next row

void showBoard(char b[][COLS])
{
    cout << " ";
    int counter[] = {1, 2, 3};
    cout << ' ';
    for (i = 0; i < ROWS; i++)
    {
        cout << counter[i] << ' ';
    }
    cout << endl;
    
    for (i = 0; i < ROWS; i++)
    {
        cout << counter[i] << ' ';
        
        for (j = 0; j < COLS; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}



void getChoice(char b[][COLS], bool playerToggle)
{
    string player;
    char c;
    int row, col;
    
    if (playerToggle == false)
    {
        player = "player 1";
        c = 'X';
    }
    else
    {
        player = "player 2";
        c = 'O';
    }
    
    
    if(player == "player 1")
    {
        
        do
        {
            do
            {
                cout << player << ',' << "Row: ";
                cin >> row;
                cout << endl;
                
                
                ///prompt the current player to enter the row
            }
            while(!((row >= 1) && (row <= 3)));   ///range for row is invalid?
            
            do
            {
                cout << player << ',' << "Column: ";
                cin >> col;
                cout << endl;
                
                ///prompt the current player to enter the column
            }
            while(!((col >= 1) && (col <= 3)));   ///range for col is invalid?
            
        }
        while(b[row - 1][col - 1] != '*');   ///the chosen cell is an X or an O?
        b[row - 1][col - 1] = c;
    }
    
    else
    {
        
        if (b[0][0] == 'O' && b[0][1] == 'O' && b[0][2] == '*')         /// win -- top horizontal
        {
            b[0][2] = 'O';
            return;
        }
        else if (b[0][0] == 'O' && b[0][2] == 'O' && b[0][1] == '*')
        {
            b[0][1] = 'O';
            return;
        }
        else if (b[0][2] == 'O' && b[0][1] == 'O' && b[0][0] == '*')
        {
            b[0][0] = 'O';
            return;
        }
        
        
        if (b[0][1] == 'O' && b[1][1] == 'O' && b[2][1] == '*')         /// win -- middle vertical
        {
            b[2][1] = 'O';
            return;
        }
        else if (b[0][1] == 'O' && b[2][1] == 'O' && b[1][1] == '*')
        {
            b[1][1] = 'O';
            return;
        }
        else if (b[1][1] == 'O' && b[2][1] == 'O' && b[0][1] == '*')
        {
            b[0][1] = 'O';
            return;
        }
        
        
        if (b[1][0] == 'O' && b[1][1] == 'O' && b[1][2] == '*')         /// win -- middle horizontal
        {
            b[1][2] = 'O';
            return;
        }
        else if (b[1][1] == 'O' && b[1][2] == 'O' && b[1][0] == '*')
        {
            b[1][0] = 'O';
            return;
        }
        else if (b[1][2] == 'O' && b[1][0] == 'O' && b[1][1] == '*')
        {
            b[1][1] = 'O';
            return;
        }
        
        
        
        if (b[1][0] == 'O' && b[0][0] == 'O' && b[2][0] != '*')      /// win -- left vertical
        {
            b[2][0] = 'O';
            return;
        }
        else if (b[1][0] == 'O' && b[2][0] == 'O' && b[0][0] != '*')
        {
            b[0][0] = 'O';
            return;
        }
        else if (b[0][0] == 'X' && b[2][0] == 'X' && b[1][0] != '*')
        {
            b[1][0] = 'O';
            return;
        }
        
        
        
        if (b[2][2] == 'O' && b[2][1] == 'O' && b[2][0] != '*')          /// win -- bottom horizontal
        {
            b[2][0] = 'O';
            return;
        }
        else if (b[2][2] == 'O' && b[2][0] == 'O' && b[2][1] != '*')
        {
            b[2][1] = 'O';
            return;
        }
        else if (b[2][1] == 'O' && b[2][0] == 'O' && b[2][2] != '*')
        {
            b[2][2] = 'O';
            return;
        }
        
        
        if (b[0][2] == 'O' && b[1][2] == 'O' && b[2][2] != '*')       /// win -- right vertical
        {
            b[2][2] = 'O';
            return;
        }
        else if (b[1][2] == 'O' && b[2][2] == 'O' && b[0][2] != '*')
        {
            b[0][2] = 'O';
            return;
        }
        else if (b[0][2] == 'O' && b[2][2] == 'O' && b[1][2] != '*')
        {
            b[1][2] = 'O';
            return;
        }
        
        
        
        if (b[0][0] == 'O' && b[2][2] == 'O' && b[1][1] != '*')       /// win -- diagonal (top left to bottom right)
        {
            b[1][1] = 'O';
            return;
        }
        else if (b[0][0] == 'O' && b[0][2] == 'O' && b[2][2] != '*')
        {
            b[2][2] = 'O';
            return;
        }
        else if (b[1][1] == 'O' && b[2][2] == 'O' && b[0][0] != '*')
        {
            b[0][0] = 'O';
            return;
        }
        
        
        if (b[0][2] == 'O' && b[2][0] == 'O' && b[1][1] != '*')       /// win -- diagonal (top right to bottom left)
        {
            b[1][1] = 'O';
            return;
        }
        else if (b[1][1] == 'O' && b[0][2] == 'O' && b[2][0] != '*')
        {
            b[2][0] = 'O';
            return;
        }
        else if (b[1][1] == 'O' && b[2][0] == 'O' && b[0][2] != '*')
        {
            b[0][2] = 'O';
            return;
        }
        
        
        
        
        
        
        
        
        
        if (b[1][1] == '*')  /// first move
        {
            b[1][1] = 'O';
            return;
        }
        
        
        
        if (b[0][1] == 'X' && b[1][1] == 'X' && b[2][1] == '*')         /// middle vertical
        {
            b[2][1] = 'O';
            return;
        }
        else if (b[0][1] == 'X' && b[2][1] == 'X' && b[1][1] == '*')
        {
            b[1][1] = 'O';
            return;
        }
        else if (b[1][1] == 'X' && b[2][1] == 'X' && b[0][1] == '*')
        {
            b[0][1] = 'O';
            return;
        }
        
        
        if (b[1][0] == 'X' && b[1][1] == 'X' && b[1][2] == '*')         /// middle horizontal
        {
            b[1][2] = 'O';
            return;
        }
        else if (b[1][1] == 'X' && b[1][2] == 'X' && b[1][0] == '*')
        {
            b[1][0] = 'O';
            return;
        }
        else if (b[1][2] == 'X' && b[1][0] == 'X' && b[1][1] == '*')
        {
            b[1][1] = 'O';
            return;
        }
        
        if (b[1][0] == 'X' && b[0][0] == 'X' && b[2][0] != 'O')      /// left vertical
        {
            b[2][0] = 'O';
            return;
        }
        else if (b[1][0] == 'X' && b[2][0] == 'X' && b[0][0] != 'O')
        {
            b[0][0] = 'O';
            return;
        }
        else if (b[0][0] == 'X' && b[2][0] == 'X' && b[1][0] != 'O')
        {
            b[1][0] = 'O';
            return;
        }
        
        
        if (b[0][2] == 'X' && b[0][0] == 'X' && b[0][1] != 'O')       /// top horizontal
        {
            b[0][1] = 'O';
            return;
        }
        else if (b[0][0] == 'X' && b[0][1] == 'X' && b[0][2] != 'O')
        {
            b[0][2] = 'O';
            return;
        }
        else if (b[0][2] == 'X' && b[0][1] == 'X' && b[0][0] != 'O')
        {
            b[0][0] = 'O';
            return;
        }
        
        
        
        if (b[2][2] == 'X' && b[2][1] == 'X' && b[2][0] != 'O')          /// bottom horizontal
        {
            b[2][0] = 'O';
            return;
        }
        else if (b[2][2] == 'X' && b[2][0] == 'X' && b[2][1] != 'O')
        {
            b[2][1] = 'O';
            return;
        }
        else if (b[2][1] == 'X' && b[2][0] == 'X' && b[2][2] != 'O')
        {
            b[2][2] = 'O';
            return;
        }
        
        
        if (b[0][2] == 'X' && b[1][2] == 'X' && b[2][2] != 'O')       /// right vertical
        {
            b[2][2] = 'O';
            return;
        }
        else if (b[1][2] == 'X' && b[2][2] == 'X' && b[0][2] != 'O')
        {
            b[0][2] = 'O';
            return;
        }
        else if (b[0][2] == 'X' && b[2][2] == 'X' && b[1][2] != 'O')
        {
            b[1][2] = 'O';
            return;
        }
        
        
        
        
        
        if (b[0][2] == 'X' && b[2][0] == 'X' && b[1][1] == 'O')             /// two X's diagonally surrounded 'O'
        {
            if(b[2][1] == '*')
            {
                b[2][1] = 'O';
                return;
            }
            else if (b[1][0] == '*')
            {
                b[1][0] = 'O';
                return;
            }
        }
        if (b[0][0] == 'X' && b[2][2] == 'X' && b[1][1] == 'O')
        {
            if(b[2][1] == '*')
            {
                b[2][1] = 'O';
                return;
            }
            else if (b[1][0] == '*')
            {
                b[1][0] = 'O';
                return;
            }
        }
        
        
        
        
        
        
        
        if (b[0][0] == 'X' && b[0][2] == 'X' && b[0][1] == '*')             /// if there is a '*' bounded by two 'X's
        {
            b[0][1] = 'O';
            return;
        }
        if (b[0][0] == 'X' && b[2][0] == 'X' && b[1][0] == '*')
        {
            b[1][0] = 'O';
            return;
        }
        if (b[2][0] == 'X' && b[2][2] == 'X' && b[2][1] == '*')
        {
            b[2][1] = 'O';
            return;
        }
        if (b[2][2] == 'X' && b[0][2] == 'X' && b[1][2] == '*')
        {
            b[1][2] = 'O';
            return;
        }
        if (b[2][0] == 'X' && b[0][2] == 'X' && b[1][1] == '*')
        {
            b[1][1] = 'O';
            return;
        }
        if (b[0][0] == 'X' && b[2][2] == 'X' && b[1][1] == '*')
        {
            b[1][1] = 'O';
            return;
        }
        
        if (b[0][0] == '*')               /// play the corners
        {
            b[0][0] = 'O';
            return;
        }
        else if (b[0][2] == '*')
        {
            b[0][2] = 'O';
            return;
        }
        else if (b[2][0] == '*')
        {
            b[2][0] = 'O';
            return;
        }
        else if (b[2][2] == '*')
        {
            b[2][2] = 'O';
            return;
        }
        
        else
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (b[i][j] == '*')
                    {
                        b[i][j] = 'O';
                        return;
                    }
                }
            }
        }
        
    }
}




///TODO (4)
///implement gameOver


bool gameOver(char b[][COLS])
{
    for (int i = 0; i < 3; i++)
    {
        if(b[i][0] == b[i][1] && b[i][0] == b[i][2])
        {
            if (b[i][0] == 'X')
            {
                cout << "Player 1 wins!" << endl;
                return true;
            }
            else if (b[i][0] == 'O')
            {
                cout << "------haha you suck you can't beat me lol------" << endl;
                return true;
            }
            
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if(b[0][i] == b[1][i] && b[0][i] == b[2][i])
        {
            if (b[0][i] == 'X')
            {
                cout << "Player 1 wins!" << endl;
                return true;
            }
            else if (b[0][i] == 'O')
            {
                cout << "------haha you suck you can't beat me lol------" << endl;
                return true;
            }
        }
    }
    
    if(b[0][0] == b[1][1] && b[1][1] == b[2][2])
    {
        if (b[0][0] == 'X')
        {
            cout << "Player 1 wins!" << endl;
            return true;
        }
        else if (b[0][0] == 'O')
        {
            cout << "------haha you suck you can't beat me lol------" << endl;
            return true;
        }
    }
    if(b[2][0] == b[1][1] && b[1][1] == b[0][2])
    {
        if (b[2][0] == 'X')
        {
            cout << "Player 1 wins!" << endl;
            return true;
        }
        else if (b[2][0] == 'O')
        {
            cout << "------haha you suck you can't beat me lol------" << endl;
            return true;
        }
    }
    for (int i = 0; i < 3; i++) /// tie
    {
        for(int j = 0; j < 3; j++)
        {
            if (b[i][j] == '*')
                return false;
        }
    }
    
    cout << "Tie!" << endl;
    return true;
}






