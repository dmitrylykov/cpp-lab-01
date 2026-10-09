#include <iostream>
#include <limits>

int main() {
    int n = 0;
    if (!(std::cin >> n)) {
        return 0;
    }

    long long sum = 0;
    int min_val = 0;
    int max_val = 0;
    int positive_count = 0;
    bool has_numbers = false;

    for (int i = 0; i < n; ++i) {
        int current_value = 0;
        std::cin >> current_value;

        sum += current_value;

        if (current_value > 0) {
            positive_count++;
        }

        if (!has_numbers) {
            min_val = current_value;
            max_val = current_value;
            has_numbers = true;
        } else {
            if (current_value < min_val) {
                min_val = current_value;
            }
            if (current_value > max_val) {
                max_val = current_value;
            }
        }
    }

    std::cout << "sum: " << sum << "\n";
    
    if (has_numbers) {
        std::cout << "min: " << min_val << "\n";
        std::cout << "max: " << max_val << "\n";
    } else {
        std::cout << "min: none\n";
        std::cout << "max: none\n";
    }
    
    std::cout << "positive: " << positive_count << "\n";

    return 0;
}

