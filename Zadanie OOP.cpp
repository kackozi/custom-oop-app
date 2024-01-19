#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>

using namespace std;

class Sort {
public:
    virtual void doSort(vector<int>& numbers_vector) = 0;
};

class BubbleSort : public Sort {
public:
    void doSort(vector<int>& numbers_vector) override {
            cout << "Rozpoczynanie sortowania bąbelkowego...\n";
            auto execStartTime = chrono::high_resolution_clock::now();
        int n = numbers_vector.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (numbers_vector[j] > numbers_vector[j + 1]) {
                    swap(numbers_vector[j], numbers_vector[j + 1]);
   
                }
            }
        }
        auto execEndTime = chrono::high_resolution_clock::now();
        auto execFinalTime = chrono::duration_cast<chrono::milliseconds>(execEndTime - execStartTime);
            cout << "Zakończono sortowanie. Zajęło to: " << execFinalTime.count() << " ms\n";
    }
};

class SelectionSort : public Sort {
public:
    void doSort(vector<int>& numbers_vector) override {
        cout << "Rozpoczynanie sortowania przez wybór...\n";
        auto execStartTime = chrono::high_resolution_clock::now();
            int n = numbers_vector.size();
            for (int i = 0; i < n - 1; i++) {
                int min_idx = i;
                for (int j = i + 1; j < n; j++) {
                    if (numbers_vector[j] < numbers_vector[min_idx]) {
                        min_idx = j;
                    }
                }
                swap(numbers_vector[min_idx], numbers_vector[i]);
            }
            auto execEndTime = chrono::high_resolution_clock::now();
            auto execFinalTime = chrono::duration_cast<chrono::milliseconds>(execEndTime - execStartTime);
                cout << "Zakończono sortowanie. Zajęło to: " << execFinalTime.count() << " ms\n";
        }
};

class InsertionSort : public Sort {
public:
    void doSort(vector<int>& numbers_vector) override {
        cout << "Rozpoczynanie sortowania przez wstawianie...\n";
        auto execStartTime = chrono::high_resolution_clock::now();
            int n = numbers_vector.size();
                for (int i = 1; i < n; i++) {
                int key = numbers_vector[i];
                int j = i - 1;
                while (j >= 0 && numbers_vector[j] > key) {
                    numbers_vector[j + 1] = numbers_vector[j];
                    j = j - 1;
            }
            numbers_vector[j + 1] = key;
        }
        auto execEndTime = chrono::high_resolution_clock::now();
        auto execFinalTime = chrono::duration_cast<chrono::milliseconds>(execEndTime - execStartTime);
            cout << "Zakończono sortowanie. Zajęło to: " << execFinalTime.count() << " ms\n";
    }
};

class QuickSort : public Sort {
public:
    void doSort(vector<int>& numbers_vector) override {
        cout << "Rozpoczynanie szybkiego sortowania...\n";
        auto execStartTime = chrono::high_resolution_clock::now();
        quicksort(numbers_vector, 0, numbers_vector.size() - 1);
        auto execEndTime = chrono::high_resolution_clock::now();
        auto execFinalTime = chrono::duration_cast<chrono::milliseconds>(execEndTime - execStartTime);
        cout << "Zakończono sortowanie. Zajęło to: " << execFinalTime.count() << " ms\n";
    }

private:
    void quicksort(vector<int>& numbers_vector, int low, int high) {
        if (low < high) {
            int pi = partition(numbers_vector, low, high);
            quicksort(numbers_vector, low, pi - 1);
            quicksort(numbers_vector, pi + 1, high);
        }
    }

    int partition(vector<int>& numbers_vector, int low, int high) {
        int pivot = numbers_vector[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (numbers_vector[j] < pivot) {
                i++;
                swap(numbers_vector[i], numbers_vector[j]);
            }
        }
        swap(numbers_vector[i + 1], numbers_vector[high]);
        return (i + 1);
    }
};


int main() {
    setlocale(LC_CTYPE, "Polish");
    vector<int> numbers_vector;
    int numbers_int;
    cout << "Sortowanie liczb | Kacper Kozieł | 310649 | Informatyka przemysłowa | Pierwszy semestr | Grupa 5\n\n";
    cout << "Wpisz teraz 0 aby załadować liczby z pliku liczby.txt znajdującego się w tym samym folderze co program.\n";
    cout << "Wprowadź pierwszą liczbę: ";
        cin >> numbers_int;
        if (numbers_int != 0) {
            numbers_vector.push_back(numbers_int);
            cout << "Poprawnie zapisano liczbę. ";
        }
        else {
            ifstream file("liczby.txt");
            if (file.is_open()) {
                while (file >> numbers_int) {

                    numbers_vector.push_back(numbers_int);
                }
                file.close();
                cout << "\nPoprawnie załadowano liczby z pliku. Możesz teraz dopisać kolejne liczby. \n";
            }
            else {
                cout << "\nTaki plik nie istnieje lub nie udało się go otworzyć. Wpisz liczby ręcznie.\n";
            }
        }
    cout << "W każdym momencie możesz wpisać 0 aby zakończyć wpisywanie.\n";
    cout << "\nWpisz kolejną liczbę: ";

    while (cin >> numbers_int && numbers_int != 0) {
        cout << "Wprowadź kolejną liczbę: ";
        numbers_vector.push_back(numbers_int);
    }

    int wybor;
    cout << "\nZakończono wpisywanie.\n\nWybierz metodę sortowania:\n- 1: Bąbelkowe \n- 2: Przez wybór\n- 3: Przez wstawianie\n- 4: Szybkie\n\nWybierz: ";
    cin >> wybor;
    cout << "\n";

    Sort* s;
    switch (wybor) {
    case 1:
        s = new BubbleSort();
        break;
    case 2:
        s = new SelectionSort();
        break;
    case 3:
        s = new InsertionSort();
        break;
    case 4:
        s = new QuickSort();
        break;
    default:
        cout << "Wprowadzono niepoprawną liczbę. Program zakończy działanie.";
        return 1;
    }

    s->doSort(numbers_vector);

    cout << "\nPosortowane liczby: ";
    for (int i : numbers_vector) {
        cout << i << " ";
    }
    cout << "\n\n";
    system("pause");
    return 0;
}