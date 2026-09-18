#include <iostream>

int main() {
    int *marks = nullptr;
    int n;

    do {
        std::cout << "Enter number of students (1-10): ";
        std::cin >> n;

        if (n < 1 || n > 10) {
            std::cout << "n must be between 1 and 10.\n";
        }
    } while (n < 1 || n > 10);

    marks = new int[n];

    std::cout << "Enter " << n << " marks:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Mark " << i + 1 << ": ";
        std::cin >> *(marks + i);   /* pointer notation, same as marks[i] */
    }

    /* Part 1 */
    int *newBlock = new int[n + 1];

    for (int i = 0; i < n; i++) {
        *(newBlock + i) = *(marks + i);   /* copy old values using pointer notation */
    }

    std::cout << "Enter the new student's mark: ";
    std::cin >> *(newBlock + n);   /* read new mark into final position */

    /* Part 2 */
    delete[] marks;      /* release the old block */
    marks = newBlock;    /* make the original pointer refer to the new block */
    n = n + 1;            /* update the stored size */

    std::cout << "\nUpdated marks: ";
    for (int i = 0; i < n; i++) {
        std::cout << *(marks + i) << " ";
    }
    std::cout << "\n";

    /* Part 3 */
    delete[] marks;
    marks = nullptr;

    return 0;
}