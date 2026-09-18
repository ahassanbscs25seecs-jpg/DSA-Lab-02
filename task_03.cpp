#include <iostream>
#include <iomanip>

int main() {
    int sales[2][3]{};
    int (*rowPtr)[3] = sales;

    // Get input from the user to fill the arrays
    for (size_t i = 0; i < 2; i++) {
        for (size_t j = 0; j < 3; j++) {
            do {
                std::cout << "Enter sale " << j+1 << " for branch " << i+1 << ": ";
                std::cin >> *(*(rowPtr + i) + j);
                if (*(*(rowPtr + i) + j) < 0) {
                    std::cout << "Input is not non-negative" << std::endl;
                }
            } while (*(*(rowPtr + i) + j) < 0);
        }
    }
    
    std::cout << "         ";
    for (int i = 0; i < 3; i++) {
        std::cout << std::setw(6) << "Day " << i+1;
    }
    std::cout << std::endl;

    for (size_t i = 0; i < 2; i++) {
        std::cout << std::setw(9) << "Branch " << i+1;
        for (size_t j = 0; j < 3; j++) {
            std::cout << std::setw(6) << *(*(rowPtr + i) + j) << ' ';
        }
        std::cout << std::endl;
    }

    int day_totals[3]{};
    int branch_totals[2]{};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            *(branch_totals + i) += *(*(rowPtr + i) + j);
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            *(day_totals + j) += *(*(rowPtr + i) + j);
        }
    }

    std::cout << "Day totals: " << *day_totals << ' '
        << *(day_totals + 1) << ' '
        << *(day_totals + 2) << ' ' << std::endl;
        
    std::cout << "Branch totals: " << *branch_totals << ' '
        << *(branch_totals + 1) << ' ' << std::endl;

    return 0;
}