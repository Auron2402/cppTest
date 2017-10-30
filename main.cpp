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

void ausgabe(int array[], int j, int i) {
    std::cout << "perfekte zahl: " << i << " teiler: ";
    do {
        std::cout << array[j] << " ";
        j++;
    } while (array[j] != 0);
    std::cout << std::endl;
}

void berechnung(int *i, std::time_t *time2) {
    int array[500] = {0};
    int j = 0;
    if (isPerfect(*i, array)) {
        ausgabe(array, j, *i);
        *time2 = std::time(nullptr);
    }
    (*i)++;
}

void TimeCheckLoop(std::time_t time2, int* pI) {
    do {
        std::time_t *pTime2 = &time2;
        berechnung(pI, pTime2);
        auto after2 = std::time(nullptr);
        if ((after2 - time2) >= 120) {
            break;
        }
    } while (true);
}

int main() {
    int i = 0;
    int* pI = &i;
    auto time2 = std::time(nullptr);
    TimeCheckLoop(time2, pI);
    std::cout << "Letzte Zahl: " << i;
    //std::cin.get();
    return 0;
}

