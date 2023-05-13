#include <iostream>
#include <fstream>
//#include <ctime>

using namespace std;

void display_matrix(int **, int, int);
//void add_polynomials(int **, int, int);

int main()
{
    string filename = "example1-10x5.txt";

    ifstream input_file(filename);      // Open file and read input

    if (!input_file)
    {
        cout << "Error opening file " << filename << endl;
        return -1;
    }

    int num_polynomials, num_variables;
    input_file >> num_polynomials >> num_variables;

    int **matrix = new int *[num_polynomials];      // Allocate memory for the matrix and initialize to zero

    for (int i = 0; i < num_polynomials; i++)
    {
        matrix[i] = new int[num_variables];
        for (int j = 0; j < num_variables; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < num_polynomials; i++)           // Read the matrix from the file
    {
        for (int j = 0; j < num_variables; j++)
        {
            input_file >> matrix[i][j];
        }
    }

    display_matrix(matrix, num_polynomials, num_variables);         // Display the matrix with vertical and horizontal scrolling

    //add_polynomials(matrix, num_polynomials, num_variables);        // Perform polynomial addition and store the result in the first row of the matrix

    ofstream output_file("result_addition.txt");        // Write the result to a file and display it on the console
    output_file << filename << endl;

    for (int j = 0; j < num_variables; j++)
    {
        output_file << matrix[0][j] << " ";
        cout << matrix[0][j] << " ";
    }

    output_file.close();
    cout << endl;

    int non_zero_count = 0;             // Display the required message on the console

    for (int i = 0; i < num_polynomials; i++)
    {
        for (int j = 0; j < num_variables; j++)
        {
            if (matrix[i][j] != 0)
            {
                non_zero_count++;
            }
        }
    }

    cout << "File name: " << filename << endl;
    cout << "Number of polynomials: " << num_polynomials << endl;
    cout << "Number of variables: " << num_variables << endl;
    cout << "Number of non-zero values: " << non_zero_count << endl;
    cout << "Data structure used: 2D matrix" << endl;

    for (int i = 0; i < num_polynomials; i++)           // Free memory allocated for the matrix
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

void display_matrix(int **matrix, int rows, int cols)
{
    int start_row = 0, start_col = 0, end_row = 10, end_col = 10;           // Display the matrix with vertical and horizontal scrolling

    while (start_row < rows)
    {
        for (int i = start_row; i < end_row && i < rows; i++)
        {
            for (int j = start_col; j < end_col && j < cols; j++)
            {
                cout << matrix[i][j] << " ";
            }
        }
    }
}