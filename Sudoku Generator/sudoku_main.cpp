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



#include "sudoku.h"

int main(){
    
    Sudoku s;
    s.generateBoard();
    s.printBoard();

    return 0;
}

