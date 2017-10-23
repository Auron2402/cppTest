#include <iostream>
#include <vector>
#include <chrono>

using namespace std::chrono_literals;

bool isPerfect(int zahl, int array[]) {
    int zahl2 = 0;
    int j = 0;
    for (int i = 1; i < zahl; i++) {
        if (zahl % i == 0) {
            zahl2 += i;
            array[j] = i;
            j++;
        }
    }
    return zahl2 == zahl;
}

int main() {
    int i = 0;
    auto time = std::chrono::system_clock::now();
    auto time2 = std::time(nullptr);
    do {
        int array[500] = {0};
        int j = 0;
        if (isPerfect(i, array)) {
            std::cout << "perfekte zahl: " << i << " teiler: ";
            do{
                std::cout << array[j] << " ";
                j++;
            }while(array[j] != 0);
            std::cout << std::endl;
            time = std::chrono::system_clock::now();
            time2 = std::time(nullptr);
        }
        i++;
        auto after = std::chrono::system_clock::now();
        auto after2 = std::time(nullptr);
        if ((after2 - time2) >= 120) {
            break;
        }
    } while (true);
    //std::cin.get();
    return 0;
}

