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

    // Временный массив для параллельного накопления сумм по всем 'n' столбцам
    std::vector<u64> col_sums(n, 0);

    const u64* __restrict p_matrix = vec.data();
    u64* __restrict p_sums = col_sums.data();

    // ОПТИМАЛЬНЫЙ ВАРИАНТ: Внешний цикл по СТРОКАМ (i)
    for (size_t i = 0; i < n; ++i) {
        // Внутренний цикл по СТОЛБЦАМ (j). Память читается идеально ПОДРЯД.
        for (size_t j = 0; j < n; ++j) {
            p_sums[j] += p_matrix[i * n + j]; 
        }
    }

    // Находим максимум среди накопленных сумм столбцов
    u64 max_col_sum = *std::max_element(col_sums.begin(), col_sums.end());

    std::cout << "L1-norm (Max col sum): " << max_col_sum << std::endl;
}

int main() {
    size_t n = 1000; 
    std::vector<u64> data(n * n, 1);
    
    process(data);
    
    return 0;
}
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

    // Временный массив для параллельного накопления сумм по всем 'n' столбцам
    std::vector<u64> col_sums(n, 0);

    const u64* __restrict p_matrix = vec.data();
    u64* __restrict p_sums = col_sums.data();

    // ОПТИМАЛЬНЫЙ ВАРИАНТ: Внешний цикл по СТРОКАМ (i)
    for (size_t i = 0; i < n; ++i) {
        // Внутренний цикл по СТОЛБЦАМ (j). Память читается идеально ПОДРЯД.
        for (size_t j = 0; j < n; ++j) {
            p_sums[j] += p_matrix[i * n + j]; 
        }
    }

    // Находим максимум среди накопленных сумм столбцов
    u64 max_col_sum = *std::max_element(col_sums.begin(), col_sums.end());

    std::cout << "L1-norm (Max col sum): " << max_col_sum << std::endl;
}

int main() {
    size_t n = 1000; 
    std::vector<u64> data(n * n, 1);
    
    process(data);
    
    return 0;
}
