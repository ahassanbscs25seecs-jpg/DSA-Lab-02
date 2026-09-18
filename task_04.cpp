#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    /* Part 1 & 2 */
    cout << "Enter number of students: ";
    cin >> rows;
    cout << "Enter number of subjects: ";
    cin >> cols;

    if (rows <= 0 || cols <= 0) {
        cout << "Rows and columns must be positive.\n";
        return 1;
    }

    /* array of row pointers */
    int **marks = new int*[rows];
    /* allocate each row separately */
    for (int r = 0; r < rows; r++) {
        marks[r] = new int[cols];
    }

    /* Part 3 */
    cout << "Enter marks (0-100) for each student:\n";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << "Student " << r + 1 << ", Subject " << c + 1 << ": ";
            cin >> *(*(marks + r) + c);
        }
    }

    cout << "\nMarks matrix:\n";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << *(*(marks + r) + c) << "\t";
        }
        cout << "\n";
    }

    /* Part 4 */
    int bestTotal = 0;
    int bestStudent = 1;

    for (int c = 0; c < cols; c++) {
        bestTotal += *(*(marks + 0) + c);   /* first student's total, per the hint */
    }

    cout << "\nStudent totals:\n";
    cout << "Student 1: " << bestTotal << "\n";

    for (int r = 1; r < rows; r++) {
        int total = 0;
        for (int c = 0; c < cols; c++) {
            total += *(*(marks + r) + c);
        }
        cout << "Student " << r + 1 << ": " << total << "\n";

        if (total > bestTotal) {
            bestTotal = total;
            bestStudent = r + 1;
        }
    }

    cout << "\nTop student: " << bestStudent << " (total " << bestTotal << ")\n";

    /* Part 5*/
    for (int r = 0; r < rows; r++) {
        delete[] marks[r]; /* free each row */
    }
    delete[] marks; /* free the array of row pointers */
    marks = nullptr;
    
    return 0;
}