#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define Size 9 // Sudoku grid size 9x9

// Function
bool initGrid(int grid[Size][Size]);
void removeNums(int grid[Size][Size], int Rn);
void printGrid(int grid[Size][Size]);
void userInput(int grid[Size][Size], int copy[Size][Size]);
bool isSafe(int grid[Size][Size], int row, int col, int num);
void shuffle(int *array, int n);

int main(){
    srand(time(NULL));
    int Grid[Size][Size] = {0};

    if(initGrid(Grid)){
        // Create a dup grid
        int copy_grid[Size][Size];
        memcpy(copy_grid, Grid, sizeof(Grid));
        
        removeNums(Grid,1); //Change the number to increase/decrease difficulty 
        printGrid(Grid);
        userInput(Grid, copy_grid);
    } else {
        printf("No solution.");
    }
    //userInput(Grid);
    

    return 0;
}

bool isSafe(int grid[Size][Size], int row, int col, int num){
    for(int i=0; i < Size; i++){
        if(grid[row][i] == num || grid[i][col] == num){
            return false;
        }
    }

    // Check number in 3x3 
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[i + startRow][j +startCol] == num){
                return false;
            }
        }
    }
    return true;
}

void shuffle(int *array, int n){
    for(int i = n-1; i > 0; i--){
        int j = rand() % (i+1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

bool initGrid(int grid[Size][Size]){
    int array_nums[Size] = {1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < Size; i++){
        for(int j = 0; j < Size; j++){
            if(grid[i][j] == 0){
                shuffle(array_nums, Size);
                for(int k = 0; k < Size; k++){
                    if(isSafe(grid,i,j,array_nums[k])){
                        grid[i][j] = array_nums[k];
                        if(initGrid(grid)){
                            return true;
                        }
                        grid[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void removeNums(int grid[Size][Size], int Rn){
    int count = 0;
    while(Rn >= count){
        int row = rand() % Size;
        int col = rand() % Size;
        if(grid[row][col] != 0){
            grid[row][col] = 0;
            count++;
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

void userInput(int grid[Size][Size], int copy[Size][Size]){
    int row, collumn, num;
    do{
        printf("Enter the row, collumn and number: ");
        scanf("%d %d %d", &row, &collumn, &num);
        if(row >= 0 && row <=8 && collumn >= 0 && collumn <= 8 && num >= 1 && num <= 9){
            if(isSafe(grid, row, collumn, num)){
                grid[row][collumn] = num;
                printGrid(grid);
            } else{
                printf("Cannot place %d at (%d,%d)\n",num,row,collumn);
            }
        } else{
            printf("Invalid . Try again.\n");
        }

        bool filled = false;
        for(int i = 0; i < Size; i++){
            for(int j = 0; j < Size; j++){
                if(grid[i][j] != 0){
                    filled = true;
                    break;
                }
            }
        }

        if(filled){
            printf("Complete");
            break;
        }
        
    } while (true);
}