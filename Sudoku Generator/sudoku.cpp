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

#include <iostream>
#include "sudoku.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//---------------------------------------------------------------------
Sudoku :: Sudoku(){  
    
    currentXpos = 0;
    currentYpos = 0;
    
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            grid [i][j] = 0;
        }
    }
    
    for (int i = 1; i <= 9; i++)
        numbers1to9.push_back(i);
    
    srand((unsigned)time(NULL));
    random_shuffle(numbers1to9.begin(), numbers1to9.end(), random );
    grid [0][0] = numbers1to9[0];
    };

//---------------------------------------------------------------------
bool Sudoku :: generateBoard(){
    
    if (grid[8][8]!=0)
        return true;
    
    findNextEmptyCell();

    for (int i = 0; i < 9; i++) {
        if ( numberIsOK(numbers1to9[i]) ){
            grid[currentXpos][currentYpos]= numbers1to9[i];
            if ( generateBoard() )
                return true;
            
            if(currentXpos == 0){
                currentYpos -=1;
                currentXpos = 8;
            }
            else
                currentXpos -= 1;
            
            grid[currentXpos][currentYpos]=0;
        }
    }
    return false;
};

//---------------------------------------------------------------------
void Sudoku :: findNextEmptyCell (){ 
   
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid [j][i] == 0) {
                currentXpos = j;
                currentYpos = i;
                return;
            }
        }
    }
};
//---------------------------------------------------------------------
bool Sudoku :: numberIsOK(int number){ 
    
    if ( alreadyInRow(currentYpos, number)||alreadyInColumn(currentXpos, number)
        ||alreadyInBox(currentXpos, currentYpos, number) )
        return false;
   
    return true;

};
//---------------------------------------------------------------------
bool Sudoku :: alreadyInRow(int yCoordinate, int num){
    
        for (int i = 0; i < 9; i++) {
        if(grid[i][yCoordinate] == num)
            return true;
        }
    return false;
};
//---------------------------------------------------------------------
bool Sudoku :: alreadyInColumn(int xCoordinate, int num){
    
    for (int i = 0; i < 9; i++) {
        if(grid[xCoordinate][i] == num)
            return true;
    }
    return false;
};
//---------------------------------------------------------------------
bool Sudoku :: alreadyInBox(int xCoordinate, int yCoordinate, int num){
    
    int xStartPos = xCoordinate - xCoordinate%3;
    int yStartPos = yCoordinate - yCoordinate%3;
    
    for (int i = yStartPos; i < yStartPos + 3; i++) {
        for (int j = xStartPos; j < xStartPos + 3; j++) {
            if(grid [j][i] == num)
                return true;
        }
    }
    return false;
};

//---------------------------------------------------------------------

void Sudoku :: printBoard(){
    
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cout << grid [j][i] << " ";
            if (j==2)
                cout << "|" << " ";
            if (j==5)
                cout << "|" << " ";
        }
        cout << endl;
        if (i==2)
            cout << "---------------------" << endl;
        if (i==5)
            cout << "---------------------" << endl;
    }
};

//---------------------------------------------------------------------

int Sudoku :: random(int i){
    return rand() % i;
};
