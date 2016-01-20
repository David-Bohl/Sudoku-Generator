//
//  Sudoku Generator
//
//  Created by David Bohl on 2/13/14.
//  Copyright (c) 2014 David Bohl. All rights reserved.
//
//  Description: Generates and displays a unique correct Sudoku board each time the program
//  is run.
//
//  Purpose : To solve Sudoku using recursion and backtracking.
//
//  Usage : Generates random correct Sudoku boards.  Could easily be modified to allow the
//  user to input Sudoku boards to solve.
//

#include <vector>
using namespace std;

class Sudoku{
    
public:
    
    Sudoku(); /* Creates an instance of the Sudoku class with a 9x9 grid.  Fills the 9x9 grid with zeros to represent empty cells.  Fills the vector "numbers1to9" with nums 1-9.  Shuffles the nums 1-9 into a random order.  This random order is the order that numbers 1-9 will be tested for correctness in each empty cell.  Uses the first random number from numbers1to9 in cell [0][0] as a starter value. */
    
    bool generateBoard();/* Uses recursion and backtracking to solve the Sudoku puzzle.  First, it tests to see if the puzzle has already been solved.  Next, it finds the next empty cell.  Then, it uses a for loop to iterate over the numbers1to9 (which has been shuffled randomly) and tries each number to see if it is a correct number to place in that empty cell.  It places the first correct number that it finds.  It then recursivlely calls itself to see if this choice can generate a correct solution.  If so, it returns true and stops.  If not, it backtracks by one cell and tries the next number in the sequence, again recursively calling itself until a correct solution is found. */
    
    void printBoard();/* Displays the grid on screen as a Sudoku board.  */
    
private:
    
    int grid[9][9];
    int currentXpos, currentYpos;
    vector <int> numbers1to9;

    void findNextEmptyCell(); /* Checks entire board and finds the next empty cell.  Assigns Sudoku Class variables currentXpos and currentYpos to the next empty cell.  */
    
    bool numberIsOK(int number);/* Tests whether a number is already used in the current row, column and 3x3 box. If it is not used, returns true.  */
    
    bool alreadyInRow(int yCoordinate, int num);/* Takes in a number, and a row. Checks to see if the number already appears in that row.  */
    
    bool alreadyInColumn(int xCoordinate, int num); /* Takes in a number, and a column.  Checks to see if the number is already used in the column.  */
    
    bool alreadyInBox(int xCoordinate, int yCoordinate, int num); /* Takes in a number and x y coordinates.  Checks to see if the number already appears in the same 3x3 box as the x y coordinates.  */
    
    static int random(int i); /* Allows the random_shuffle to be truly random.  */ 
    
};