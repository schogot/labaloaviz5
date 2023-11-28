#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <locale.h>

// Функция для генерации случайного числа в заданном диапазоне
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    srand(time(0)); // Инициализация генератора случайных чисел

    int n;
    std::cout << "Введите размер матрицы: ";
    std::cin >> n;
    std::cout << "\n";

    // Генерация и вывод матрицы смежности
    std::vector<std::vector<int>> adjacencyMatrix(n, std::vector<int>(n));
    int edgesCount = 0; // Переменная для подсчета количества ребер
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            adjacencyMatrix[i][j] = generateRandomNumber(0, 1);
            adjacencyMatrix[j][i] = adjacencyMatrix[i][j];
            if (i == j) {
                adjacencyMatrix[i][j] = 0;
            }
            if (adjacencyMatrix[i][j] == 1) {
                edgesCount++;
            }
        }
    }
    edgesCount = edgesCount / 2;
    std::cout << "Матрица смежности:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << adjacencyMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    // Вывод размера графа (количество ребер)
    std::cout << "Размер графа (количество ребер): " << edgesCount << "\n";
    std::cout << "\n";

    // Поиск изолированных, конечных и доминирующих вершин
    std::vector<int> isolatedVertices, terminalVertices, dominatingVertices;
    for (int i = 0; i < n; ++i) {
        int degree = 0;
        for (int j = 0; j < n; ++j) {
            if (adjacencyMatrix[i][j] == 1) {
                degree++;
            }
        }

        if (degree == 0) {
            isolatedVertices.push_back(i);
        }
        else if (degree == 1) {
            terminalVertices.push_back(i);
        }
        else if (degree == n - 1) {
            dominatingVertices.push_back(i);
        }
    }

    // Вывод изолированных вершин
    std::cout << "Изолированные вершины: ";
    if (isolatedVertices.empty()) {
        std::cout << "нет";
    }
    else {
        for (const auto& vertex : isolatedVertices) {
            std::cout << vertex << " ";
        }
    }
    std::cout << "\n";

    // Вывод конечных вершин
    std::cout << "Концевые вершины: ";
    if (terminalVertices.empty()) {
        std::cout << "нет";
    }
    else {
        for (const auto& vertex : terminalVertices) {
            std::cout << vertex << " ";
        }
    }
    std::cout << "\n";

    // Вывод доминирующих вершин
    std::cout << "Доминирующие вершины: ";
    if (dominatingVertices.empty()) {
        std::cout << "нет";
    }
    else {
        for (const auto& vertex : dominatingVertices) {
            std::cout << vertex << " ";
        }
    }
    std::cout << "\n";

    return 0;
}