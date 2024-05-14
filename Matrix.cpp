//Betty Phipps 05/13/24
//Computes the sums of elements in the upper and lower triangles of a matrix. It prompts the user to input the dimensions of the matrix and its elements, then calculates and prints the sums of the upper and lower triangles.

#include <iostream>

using namespace std;

int const ROWCAP = 100; //rowcap and colcap are now set to 100 and will not change
int const COLCAP = 100;

//functions to initialize the matrix, print the matrix, and to print the triangle sum. Initalized matrix with the column number, n row is number of rows, n col is number of columns

void initialize (float matrix[][COLCAP], float nRow, float nCol);
void print (float matrix[][COLCAP], float nRow, float nCol);
void printSums (float matrix[][COLCAP], float nRow, float nCol);

int main()
{
        float matrix[ROWCAP][COLCAP]; //Float matrix to recieve decimals from user
        float nRow, nCol;
        
        //promting the user to enter columns and rows numbers
        
	cout<<"Enter the number of rows: ";
        cin>>nRow;
        
        cout<<"Enter the number of columns: ";
        cin>>nCol;
        
        //calling funtions to take in the array, print it, then print the sums
        
	initialize(matrix, nRow, nCol);
        print(matrix, nRow, nCol);
        printSums(matrix, nRow, nCol);

        return 0;
}

void initialize (float matrix[][COLCAP], float nRow, float nCol)
{
        cout<<"Enter the matrix: "<<endl;
        
	//iterating through the column then row, accept numbers into the matrix
        
		for (int i =0; i < nRow; i++)
                	for (int j =0; j < nCol; j++)
                        	cin>>matrix[i][j];
}

void print (float matrix[][COLCAP], float nRow, float nCol)
{
        cout<<"You entered: "<<endl;
        
	//Iterating through the matrix and printing out the corresponding row, column

        	for (int i = 0; i < nRow; i++)
                	for (int j =0; j <nCol; j++){
                        	        cout<<matrix[i][j]<<" \n  "[j == nCol-1];
                        }
}

void printSums (float matrix[][COLCAP], float nRow, float nCol) {
        
	//Setting sums to 0 for incrementing

        	float upperSum = 0;
        	float lowerSum = 0;
        
        	for (int i = 0; i < nRow; i++)
                	for (int j = 0; j <nCol; j++){
                        	if (i <=j)
                        	upperSum += matrix[i][j]; //add the sum if the column number greater than the row number
                	}


        for (int i = 0; i < nRow; i++)
                for (int j = 0; j <nCol; j++){
                        if (i >=j)
                        lowerSum += matrix[i][j]; //add the sum if the column number is less than the row number
                }

        cout<<"Upper triangle sum: "<<upperSum<<endl;
        cout<<"Lower triangle sum: "<<lowerSum<<endl;
}

