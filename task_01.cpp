#include <iostream>

/* In order to avoid magic numbers */
#define SIZE 5

/* Display the array using *(p + i) notation */
void display_array(int arr[], size_t len) {
    for (size_t i = 0; i < len; i++) {
        std::cout << *(arr + i) << ' ';
    }
    std::cout << std::endl;
}

int calc_total(int arr[], size_t len) {
    int total = 0;

    for (size_t i = 0; i < len; i++) {
        total += *(arr + i);
    }

    return total;
}

int main() {
    
    /* -- PART 1 -- */

    int sales[SIZE]{}; /* Define the array in the stack */
    int total = 0;
    int *p = sales; /* Define a pointer to that array */

    /* Read the array from the user using the *(p + i) notation */
    for (int i = 0; i < SIZE; i++) {
        do {

            std::cout << "> ";
            std::cin >> *(p + i);

            if (*(p+i) < 0) {
                std::cout << "Number must be non-negative" << std::endl;
            }
        } while (*(p + i) < 0);
    }

    /* Display the final array */
    std::cout << "Input array: ";
    display_array(sales, SIZE);

    std::cout << "Total: " << calc_total(sales, SIZE) << std::endl;
    std::cout << std::endl;

    /* -- PART 2 -- */

    std::cout << "Old value of third element: " << *(p + 2) << std::endl;
    std::cout << "Old total: " << calc_total(p, SIZE) << std::endl;

    /* Update the third entry of sales */
    *(p + 2) += 2;

    std::cout << "New value of third element: " << *(p + 2) << std::endl;
    std::cout << "New total: " << calc_total(p, SIZE) << std::endl;

    return 0;
}
