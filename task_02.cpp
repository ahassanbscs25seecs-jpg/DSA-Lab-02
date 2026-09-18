#include <iostream>
#include <iomanip>


int main() {
    int *marks = nullptr;
    int n = 0;
    int n_at_least_50 = 0;
    int total = 0;
    float average = 0.0f;

    do {
        std::cout << "Number of students: ";
        std::cin >> n;

        if (n <= 0) {
            std::cout << "Number of students have to be positive and non-zero" << std::endl;
        }
    } while (n <= 0);

    marks = new int[n];
    
    for (size_t i = 0; i < n; i++) {
        std::cout << "Enter marks for student " << i+1 << ": ";
        std::cin >> *(marks + i);
    }

    /* Find total, average and pass count */

    for (size_t i = 0; i < n; i++) {
        total += *(marks + i);
        if (*(marks + i) >= 50) {
            n_at_least_50++;
        }
    }
    average = total / n;

    /* Display all the marks entered */
    std::cout << "Marks entered: ";
    for (size_t i = 0; i < n; i++) {
        std::cout << *(marks + i) << ' ';
    }
    std::cout << std::endl;
    
    std::cout << "Total " << total
              << std::fixed << std::setprecision(3) << "; average " << average
              << "; pass count " << n_at_least_50 << std::endl;

    delete[] marks;
    marks = nullptr;

    return 0;
}