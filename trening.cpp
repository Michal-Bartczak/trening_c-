#include <iostream>
#include <fstream>
#include <string>
#include <utility>

// Funkcja zmieniająca wartość zmiennej przy użyciu referencji
void modifyValueByReference(int& ref) {
    ref = 100;  // Zmienia wartość zmiennej
}

// Funkcja zmieniająca wartość zmiennej przy użyciu wskaźnika
void modifyValueByPointer(int* ptr) {
    *ptr = 200;  // Zmienia wartość zmiennej
}

// Funkcja zapisująca liczby do pliku
void writeNumbersToFile(const std::string& filename, const int arr[], int size) {
    std::ofstream writeFile(filename);
    if (!writeFile) {
        std::cout << "Nie udalo sie otworzyc strumienia" << std::endl;
        return;
    }

    for (int j = 0; j < size; j++) {
        writeFile << arr[j] << " ";
        std::cout << "Liczba do pliku z tabeli: " << arr[j] << std::endl;
    }

    writeFile.close();
}
//Sortowanie bombelkowe
void bubbleSort(int arr[], int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - 1 - i; ++j){
            if (arr[j] > arr[j+1]){
                std::swap(arr[j],arr[j+1]);
            }
        }
    }
}

//Wyświetlanie danych z pliku cała linia 
void displayLineFromFile(const std::string& fileName){
    std::ifstream getLineFile(fileName);
    if (!getLineFile){
        std::cout << "Nie mozna otworzyc pliku" << std::endl;
        return;
    }
    std::string lane;
    while(std::getline(getLineFile,lane)){
        std::cout << "Linia z pliku: " << lane << std::endl;
    }
    getLineFile.close();
}

//Wyświetlanie danych z pliku każda liczba osobno
void displayEachNumber(const std::string& fileName){

    std::ifstream getNumberFromFile(fileName);
    if (!getNumberFromFile){
        std::cout << "Nie można otworzyć pliku" << std::endl;
        return;
    }
    int number;
    while(getNumberFromFile >> number){
        std::cout << "Liczba z pliku to:" << number << std::endl; 
    }

    getNumberFromFile.close();
}

//Zapis danych z pliku do tabeli
void saveDataFromFileToTable(int arr[], int size, const std::string& fileName) {
    std::ifstream dataToTable(fileName);
    if (!dataToTable) {
        std::cout << "Nie można otworzyć pliku" << std::endl;
        return;
    }
    int number;
    int countMaxSizeTable = 0;
    while (dataToTable >> number && countMaxSizeTable < size) {
        arr[countMaxSizeTable] = number;
        countMaxSizeTable++;
    }
    if (countMaxSizeTable == size && dataToTable >> number) {
        std::cout << "Tablica jest pełna. Nie wszystkie dane z pliku zostały zapisane." << std::endl;
    }
    dataToTable.close();
}

//Switch
void performAction(int option) {
    switch (option) {
        case 1:
            std::cout << "Opcja 1: Wybór A" << std::endl;
            break;
        case 2:
            std::cout << "Opcja 2: Wybór B" << std::endl;
            break;
        case 3:
            std::cout << "Opcja 3: Wybór C" << std::endl;
            break;
        default:
            std::cout << "Nieprawidłowa opcja" << std::endl;
            break;
    }
}



int main() {


    int x = 10; 
    std::cout << "Przed modyfikacją (referencja): x = " << x << std::endl;

    modifyValueByReference(x); 
    std::cout << "Po modyfikacji (referencja): x = " << x << std::endl;  // Wypisze: x = 100

    int y = 20;  
    int* yPtr = &y;
    std::cout << "Przed modyfikacją (wskaźnik): y = " << y << std::endl;

    modifyValueByPointer(yPtr); 
    std::cout << "Po modyfikacji (wskaźnik): y = " << y << std::endl; 

    // Poprawna deklaracja tablicy
    const int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int sizeTable = 8;

    // Poprawne wywołanie funkcji writeNumbersToFile
    writeNumbersToFile("dane.txt", array, sizeTable);


    int myArray[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    std::cout << "Tablica przed sortowaniem: ";
    for (int i = 0; i < size; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    bubbleSort(myArray, size);

    std::cout << "Tablica po sortowaniu: ";
    for (int i = 0; i < size; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;


 

}
