//Betty Phipps 05/13/24
//This C++ script simulates a basic space invaders game where players defend against advancing ships by firing shots and strategically moving cannons. It prompts users to set up the game grid, manages the game mechanics, and determines victory conditions, providing an interactive gaming experience.

#include <iostream>

char** createGrid (int row, int col); //function that creates grid
void printGrid (char** grid, int row, int col); //print grid
void playGame (char** grid, int row, int col, int shotsPerCan); //plays game

using namespace std;

//prompting the user to input the dimensions of the game grid and the number of shots per cannon, then creates the grid and initiates the game simulation, ensuring memory deallocation upon completion.

int main(){
        
	int rows, cols, shotsPerCan;
        
        cout<<"Enter the number of rows in the grid: ";
        cin>> rows;
        cout<<"Enter the number of columns in the grid: ";
        cin>>cols;
        cout<<"Enter the number of shots per cannon for this level: ";
        cin>>shotsPerCan;

        char** grid = createGrid(rows,cols);
        playGame(grid, rows, cols, shotsPerCan);

        //deallocate memory
        for (int i =0; i< rows; ++i){
                delete[] grid[i];
        }

        delete[] grid;

        return 0;
}



char** createGrid (int row, int col){

//allocate memory
        char** grid = new char*[row];
        
        for (int i =0; i < row; i++){
                grid[i] = new char[col];
        }


//grid with space '.'
        for (int i =0; i < row; i++){
                for (int j =0; j < col; j++)
                        grid[i][j] = '.';
        }



//reading the number of cannons and positions
        int nCan;
        cout<<"Enter the number of cannons: ";
        cin>>nCan;
        cout<<"Enter the locations of the cannons: ";
        for (int i =0; i < nCan; i++){
                int cannonColumn;
                cin >> cannonColumn;
                grid[row - 1][cannonColumn] = 'C';
        }

//read number of ships and positions
 
        int nShips;
        cout<<"Enter the number of ships: ";
        cin>>nShips;
        cout<<"Enter the coordinates of the ships, and their sheild points (x,y), BP:\n";
 
       for (int i = 0; i < nShips; i++){
  	//printGrid(grid, row,col);
		int rowInput, colInput;
        	char shieldPoint;
                string index;
        
		cin>>index;
        	rowInput = index[1] - '0';
        	colInput = index[3] - '0';
        	shieldPoint = index[6]; 
                
        	grid[rowInput][colInput] = shieldPoint;
        
       }

        return grid;
}



void printGrid (char** grid, int row, int col){
	//printing the grid
        for (int i = 0; i < row; i++){  
                for (int j = 0; j <col; j++){
                        cout<<grid[i][j]<<" ";
                }
                cout<<endl;
        }
}

void playGame (char** grid, int row, int col, int shotsPerCan){
        
	cout<<"Game at the start:"<<endl;
        printGrid(grid, row, col);

        //while the game is still playing
        int rounds = 0;
        bool game = true;
        
        while (rounds < 100 && game){//while game is active
                cout<<"Enter the coordinates for "<<shotsPerCan<<" shots: ";

                for (int i = 0; i < shotsPerCan; i++){//for every shot
                        string inputLine;
                        cin>>inputLine;
                        cout<<endl;
                        int rowInp, colInp;
                        rowInp = inputLine[1]- '0';
                        colInp = inputLine[3]- '0';
                        
                        //if input is in bounds, excluding bottem row
                        if (rowInp >= 0 && rowInp < row - 1 && colInp >= 0 && colInp < col){ 
                                //decrease shieldpoint
                                if (grid[rowInp][colInp] != '.'){
                                        grid[rowInp][colInp] --;
                                        if (grid[rowInp][colInp] == '0')
                                                grid[rowInp][colInp] = '.';
                                }
                        }
                }
                
                //move ships down a row
                for (int i = row - 2; i >= 0; i--){
                        for (int j=0; j< col; j ++){
                                if (grid[i][j] != '.'){
                                        grid[i+1][j] = grid[i][j];
                                        grid[i][j] = '.';
                                }
                        }
                }
                rounds++;
                
                
                cout<<"Game after round "<<rounds<<endl;
                printGrid(grid, row, col);
        
                //check if invaders win
                int c = 0;
                while(c < col && game){
                        if (grid[row-1][c] != '.' && grid[row-1][c] != 'C'){
                                game = false;
                                cout<<"Space Invaders Win"<<endl;
                        }
                        c++;
                
                }
                
                //check number of ships and cannons
                int numShip = 0;
                for (int i = 0; i < row; i++){
                        for (int j = 0; j < col; j++){
                                if (grid[i][j] != '.' && grid[i][j] != 'C'){
                                        numShip++;
                                }
                        }
                }
                if (numShip == 0){
                        cout<<"Defenders win"<<endl;
                        game = false;
                }
        }
}

