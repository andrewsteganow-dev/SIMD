#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using u64 = unsigned long long;

void process(std::vector<u64>& vec) {
    size_t n = static_cast<size_t>(std::sqrt(vec.size()));
    
    if (n * n != vec.size()) {
        std::cerr << "Ошибка: Вектор не является квадратной матрицей!" << std::endl;
        return;
    }

    u64 max_col_sum = 0;
    const u64* __restrict p_matrix = vec.data();

    // НЕОПТИМАЛЬНЫЙ ВАРИАНТ: Внешний цикл по СТОЛБЦАМ (j)
    for (size_t j = 0; j < n; ++j) {
        u64 current_col_sum = 0;

        // Внутренний цикл по СТРОКАМ (i) с шагом 'n'
        #pragma GCC ivdep
        for (size_t i = 0; i < n; ++i) {
            current_col_sum += p_matrix[i * n + j]; 
        }

        max_col_sum = std::max(max_col_sum, current_col_sum);
    }

    std::cout << "L1-norm (Max col sum): " << max_col_sum << std::endl;
}

int main() {
    size_t n = 1000; 
    std::vector<u64> data(n * n, 1);
    
    process(data);
    
    return 0;
}
