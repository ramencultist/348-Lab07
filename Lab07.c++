#include <iostream>
using namespace std;


const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
    int data[SIZE][SIZE]; // 2D array for matrix data (using int for simplicity)

public:
// 1. Read values from stdin into a matrix
    void readFromStdin();
        for (int i = 0; 1 < SIZE; i++) {
            for (int j = 0; j < SIZE; j++){
                cin >> data[i][j]; // reads from standard input
            }
        }

    void readFromFile(const string& filename) {
        ifstream file(filename); // open file to read
        if (file.is_open()) { // checking if file actually opened
            for (int i = 0; i < SIZE; i++) {
                for (int j= 0; j < SIZE; j++) {
                    file >> data[i][j];
                }
            }
            file.close() // close after reading file
        } else {
            cerr << "Error when opening file: " << filename << endl; //outputs error if failure to open the file
        }
    }

// 2. Display a matrix
    void display() const;{
        for (int = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                cout << setw(5) << data[i][j] // displays each element aligned by the right to 5 spaces
            }
            cout << end1; // adds a new line after each row to make it readable
        }
    }

// 3. Add two matrices (operator overloading for +)
    Matrix operator+(const Matrix& other) const; {
        Matrix final_matrix; // New matrix to store the sum
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                final_matrix.data[i][j] = data[i][j] + other.data[i][j];// Add elements from both matrices
            }
        }
        return final_matrix; // Returns result
    }
    }


// 4. Multiply two matrices (operator overloading for *)
    Matrix operator*(const Matrix& other) const; {
        Matrix final_matrix; // New matrix to store the product
        for (int i = 0; i < SIZE; i++) { // initializes eveyrthing to zero
            for (int j = 0; j < SIZE; j++) {
                final_matrix.data[i][j] = 0;
                // Calculate each element of result
                for (int k = 0; k < SIZE; k++) {
                    // Accumulate sum of products for the multiplication
                    final_matrix.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return final_matrix; // Return the resulting matrix
    }


// 5. Compute the sum of matrix diagonal elements
    int sumOfDiagonals() const; {
        int sum = 0; // Variable for sum
        for (int i = 0; i < SIZE; i++) {
            sum += data[i][i]; // Add main diagonal
            sum += data[i][SIZE - i - 1]; // Add secondary diagonal
        }
        return sum; // Return sum
}


// 6. Swap matrix rows
    void swapRows(int row1, int row2);{
        if (row1 >= 0 && row1 < SIZE && row2 >= 0 && row2 < SIZE) {// Check if row indices are within valid range
            for (int i = 0; i < SIZE; i++) {
                swap(data[row1][i], data[row2][i]);// Swap elements of row1 and row2
            }
        } else {
            cout << "Invalid row indices for swap operation." << endl;// error if indices don't line up
        }
    }

};


int main() {
// Example usage:
    Matrix matrix_1, matrix_2; // Create two matrix objects for usage
    char choice;

    // Ask user for input choice, the code template had read from standard input but the instructions said to read from file, so i implemented both and gave the user free will
    cout << "Enter 'm' to input matrices manually, or 'f' to read from files: ";
    cin >> choice;

    if (choice == 'm') {
        // Manually input matrices from standard input
        cout << "Enter values for Matrix 1:" << endl;
        matrix_1.readFromStdin();
        cout << "Enter values for Matrix 2:" << endl;
        matrix_2.readFromStdin();
    } else if (choice == 'f') {
        // Read matrices from files
        string file1, file2;
        cout << "Enter filename for Matrix 1: ";
        cin >> file1;
        matrix_1.readFromFile(file1);

        cout << "Enter filename for Matrix 2: ";
        cin >> file2;
        matrix_2.readFromFile(file2);
    } else {
        cout << "Invalid choice. Exiting." << endl;
        return 1; // Exit if invalid choice
    }

    // Display both matrices
    cout << "Matrix 1:" << endl;
    matrix_1.display();
    cout << "Matrix 2:" << endl;
    matrix_2.display();

    // Sum of two matrices
    Matrix sum = matrix_1 + matrix_2;
    cout << "Sum of matrices:" << endl;
    sum.display();

    // Product of two matrices
    Matrix product = matrix_1 * matrix_2;
    cout << "Product of matrices:" << endl;
    product.display();

    // Sum of diagonal elements of Matrix 1
    cout << "Sum of diagonals of Matrix 1: " << matrix_1.sumOfDiagonals() << endl;

    // Swapping rows in Matrix 1
    matrix_1.swapRows(0, 2);
    cout << "Matrix 1 after swapping rows:" << endl;
    matrix_1.display();

    return 0;
}
