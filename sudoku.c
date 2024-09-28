#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Size 9 // Sudoku grid size 9x9

// Function
void initGrid(int grid[Size][Size]);
void printGrid(int grid[Size][Size]);
void userInput(int grid[Size][Size]);

int main(){
    int Grid[Size][Size];

    initGrid(Grid);
    printGrid(Grid);
    userInput(Grid);

    return 0;
}

void initGrid(int grid[Size][Size]){
    for(int i = 0 ; i < Size;i++){
        for(int j = 0; j < Size; j++){
            grid[i][j] = 0;
        }
    }
}

void printGrid(int grid[Size][Size]){
    for(int i = 0 ; i < Size;i++){
        for(int j = 0; j < Size; j++){
            printf("%d ", grid[i][j]);
            if((j+1)%3 == 0 && j < Size -1){
                printf("| ");
            }
        }
        printf("\n");
        if((i+1)%3 == 0 && i < Size -1){
            printf("---------------------\n");
        }
    }
}

void userInput(int grid[Size][Size]){
    int row, collumn, num;
    printf("Enter the row, collumn and number: ");
    scanf("%d %d %d", &row, &collumn, &num);
    grid[row][collumn] = num;
    printGrid(grid);
}