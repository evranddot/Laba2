#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;

 const int arrLength = 10;
 const int maxOfArr = 99;
 const int minOfArr = -99;

 void bubbleSort(int* arr) {
     for (int i = 0; i < arrLength - 1; ++i) {
         for (int j = 0; j < arrLength - i - 1; ++j) {
             if (arr[j] > arr[j + 1]) {
                 swap(arr[j], arr[j + 1]);
             }
         }
     }
 }

void shakerSort(int* arr) {
        int left = 0, right = arrLength - 1;
        while (left <= right) {
            // Проход слева направо
            for (int i = left; i < right; ++i) {
                if (arr[i] > arr[i + 1]) {
                    swap(arr[i], arr[i + 1]);
                }
            }
            --right;

            // Проход справа налево
            for (int i = right; i > left; --i) {
                if (arr[i] < arr[i - 1]) { 
                    swap(arr[i], arr[i - 1]); 
                }
            }
            ++left;
        }
}


void insertionSort(int* arr) {
    for (int i = 1; i < arrLength; ++i) {
        int key = arr[i];
        int j = i - 1;
        // Сдвигаем элементы, пока не найдем позицию для key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}


void gnomeSort(int* arr) {
    int i = 0;
    while (i < arrLength) {
        if (i == 0 || arr[i - 1] <= arr[i]) {
            ++i;  // Движение вперед
        }
        else {
            swap(arr[i], arr[i - 1]);
            --i;  // Движение назад
        }
    }
}

void shellSort(int* arr) {
    for (int gap = arrLength / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < arrLength; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}


int binarySearch(int arr[], int value, int start, int end) {
    if (end >= start) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == value) {
            return mid;
        }

        if (arr[mid] > value) {
            return binarySearch(arr, value, start, mid - 1);
        }

        return binarySearch(arr, value, mid + 1, end);
    }
    
    return -1;
}

void writeArr(int* arr) {

     for (int i = 0; i < arrLength; i++) {
         arr[i] = rand() % (maxOfArr - minOfArr + 1) + minOfArr;
     }
 }

void printArr(int* arr) {
     cout << "\nМассив выглядит так:\n";
     for (int i = 0; i < arrLength; i++) {
         cout << arr[i] << ' ';
     }
     cout << '\n';
 }



int main() {
    setlocale(LC_ALL, "Russian");

    int menuNumber;
    int arr[arrLength];

    int bubbleArr[arrLength], shakerArr[arrLength], gnomeArr[arrLength], insertionArr[arrLength], shellArr[arrLength], randomArr[arrLength], swapArr[arrLength];

    do {

        cout << "Введите номер задания от 1 до 8, либо 9 для ИДЗ, либо 0 для завершения программы\n";
        cin >> menuNumber;

        if (menuNumber == 1) {

            int sortNumber;
            cout << "Выберите как вводить массив: 1 - вручную, 2 - рандомный массив\n";
            cin >> sortNumber;

            if (sortNumber == 1) {
                cout << "Значения принимаются от -99 до 99\n";
                for (int i = 0; i < arrLength; ++i) {
                    cin >> arr[i];
                    cin.sync();
                    if (arr[i] > 99 || arr[i] < -99) {
                        cout << "Значение не входит в диапазон!\n";
                        break;
                    }
                }
                cout << "\nМассив выглядит так: ";
                for (int i = 0; i < arrLength; ++i) {
                    cout << arr[i] << ' ';
                }
                cout << '\n';
            }

            if (sortNumber == 2) {
                writeArr(arr);
                printArr(arr);
                cout << "\n\n";
            }
            for (int i = 0; i < arrLength; ++i)
            {
                bubbleArr[i] = arr[i];
            }
            for (int i = 0; i < arrLength; ++i)
            {
                shakerArr[i] = arr[i];
            }
            for (int i = 0; i < arrLength; ++i)
            {
                gnomeArr[i] = arr[i];
            }
            for (int i = 0; i < arrLength; ++i)
            {
                insertionArr[i] = arr[i];
            }
            for (int i = 0; i < arrLength; ++i)
            {
                shellArr[i] = arr[i];
            }
            for (int i = 0; i < arrLength; ++i)
            {
                randomArr[i] = arr[i];
            }
        }

        if (menuNumber == 2) {
            auto start1 = high_resolution_clock::now();
            bubbleSort(bubbleArr);
            auto end1 = high_resolution_clock::now();
            auto duration1 = duration_cast<nanoseconds>(end1 - start1).count();
            cout << "Сортировка bubbleSort завершилась за " << duration1 << " наносекунд.\n";

            auto start2 = high_resolution_clock::now();
            shakerSort(shakerArr);
            auto end2 = high_resolution_clock::now();
            auto duration2 = duration_cast<nanoseconds>(end2 - start2).count();
            cout << "Сортировка shakerSort завершилась за " << duration2 << " наносекунд.\n";

            auto start3 = high_resolution_clock::now();
            insertionSort(insertionArr);
            auto end3 = high_resolution_clock::now();
            auto duration3 = duration_cast<nanoseconds>(end3 - start3).count();
            cout << "Сортировка insertionSort завершилась за " << duration3 << " наносекунд.\n";

            auto start4 = high_resolution_clock::now();
            gnomeSort(gnomeArr);
            auto end4 = high_resolution_clock::now();
            auto duration4 = duration_cast<nanoseconds>(end4 - start4).count();
            cout << "Сортировка gnomeSort завершилась за " << duration4 << " наносекунд.\n";

            auto start5 = high_resolution_clock::now();
            shellSort(shellArr);
            auto end5 = high_resolution_clock::now();
            auto duration5 = duration_cast<nanoseconds>(end5 - start5).count();
            cout << "Сортировка shellSort завершилась за " << duration5 << " наносекунд.\n";

            cout << "Отсортированный массив выглядит так:";
            for (int i = 0; i < arrLength; ++i) {
                cout << gnomeArr[i] << ' ';
            }
            cout << "\n\n";
        }

        if (menuNumber == 3) {
            auto start6 = high_resolution_clock::now();

            int minNumber = randomArr[0], maxNumber = randomArr[arrLength - 1];

            for (int i = 1; i < arrLength; ++i) {
                if (randomArr[i] > maxNumber) {
                    maxNumber = randomArr[i];
                }
            }
            for (int i = 1; i < arrLength; ++i) {
                if (randomArr[i] < minNumber) {
                    minNumber = randomArr[i];
                }
            }
            cout << "Неотсортированный массив: " << "Минимальный элемент: " << minNumber << '\n' << "Максимальный элемент: " << maxNumber << '\n';

            auto end6 = high_resolution_clock::now();
            auto duration6 = duration_cast<nanoseconds>(end6 - start6).count();

            cout << "На поиск максимального и минимального элементов в неотсортированном массиве ушло " << duration6 << " наносекунд.\n";

            auto start8 = high_resolution_clock::now();

            cout << "Сортированный массив: " << "Минимальный элемент:" << gnomeArr[0] << '\n' << "Максимальный элемент: " << gnomeArr[arrLength - 1] << '\n';

            auto end8 = high_resolution_clock::now();
            auto duration8 = duration_cast<nanoseconds>(end8 - start8).count();

            cout << "На поиск максимального и минимального элементов в отсортированном массиве ушло " << duration8 << " наносекунд.\n\n";

        }

        if (menuNumber == 4) {

            // СОРТИРОВАННЫЙ МАССИВ
            cout << "Сортированный массив: \n";
            auto start10 = high_resolution_clock::now();
            int minNumber = gnomeArr[0], maxNumber = gnomeArr[arrLength - 1];
            int k = 0;

            int midNumber = minNumber + maxNumber;

            if (abs(midNumber) % 2 == 1) {
                midNumber = (abs(midNumber) / 2) + 1;
                
            }
            else {
                midNumber = midNumber / 2;
            }

            if (minNumber + maxNumber < 0) {
                midNumber *= -1;
            }
            
            cout << "Среднее значение массива = " << midNumber << '\n';

            cout << "Значения индексов, числа которых совпадают со средним значением массива: ";
            for (int i = 0; i < arrLength; ++i) {
                if (gnomeArr[i] == midNumber) {
                    k += 1;
                    cout << i << ' ';

                }
            }
            cout <<"\nКоличество чисел, совпадающих со средним значением = " << k << '\n';
            auto end10 = high_resolution_clock::now();
            auto duration10 = duration_cast<nanoseconds>(end10 - start10).count();
            cout << "Операция в отсортированном массиве завершилась за " << duration10 << " наносекунд.\n\n";

            // НЕСОРТИРОВАННЫЙ МАССИВ

            cout << "Несортированный массив: \n";

            auto start11 = high_resolution_clock::now();

            int minNumber1 = randomArr[0], maxNumber1 = randomArr[0];
            int k1 = 0, midNumber1;

            for (int i = 1; i < arrLength; ++i) {
                if (randomArr[i] < minNumber1) {
                    minNumber1 = randomArr[i];
                }
            }
            for (int i = 1; i < arrLength; ++i) {
                if (randomArr[i] > maxNumber1) {
                    maxNumber1 = randomArr[i];
                }
            }

            midNumber1 = maxNumber1 + minNumber1;

            if ((abs(midNumber1) % 2) == 1) {

                midNumber1 = abs(midNumber1) / 2 + 1;

            }
            else {

                midNumber1 = midNumber1 / 2;
            }

            if (minNumber1 + maxNumber1 < 0) {
                midNumber1 *= -1;
            }

            cout << "Среднее значение массива = " << midNumber1 << '\n';

            cout << "Значения индексов, числа которых совпадают со средним значением массива: ";
            for (int i = 0; i < arrLength; ++i) {
                if (randomArr[i] == midNumber1) {
                    k1 += 1;
                    cout << i << ' ';

                }
            }
            cout << "\nКоличество чисел, совпадающих со средним значением = " << k1 << '\n';

            auto end11 = high_resolution_clock::now();
            auto duration11 = duration_cast<nanoseconds>(end11 - start11).count();
            cout << "Операция в неотсортированном массиве завершилась за " << duration11 << " наносекунд.\n\n";

        }

        if (menuNumber == 5) {

            float number5;

            cout << "Введите число, с которым хотите сравнить массив ";

            cin >> number5;

            int k = 0;
            for (int i = 0; i < arrLength; ++i) {
                if (gnomeArr[i] < number5)
                {
                    k += 1;
                }
            }

            cout << "В массиве " <<  k << " меньше числа " << number5 << "\n\n";

        }

        if (menuNumber == 6) {

            float number6;

            cout << "Введите число, с которым хотите сравнить массив ";

            cin >> number6;

            int k = 0;
            for (int i = 0; i < arrLength; ++i) {
                if (gnomeArr[i] > number6)
                {
                    k += 1;
                }
            }

            cout << "В массиве " << k << " больше числа " << number6 << "\n\n";
        }

        if (menuNumber == 7) {

            int wantedNumber, k = 0;

            cout << "Введите число, которое хотите найти ";

            cin >> wantedNumber;

            auto start7 = high_resolution_clock::now();
            for (int i = 0; i < arrLength; ++i) {
                if (randomArr[i] == wantedNumber) {
                    cout << "Такое число в массиве есть\n";
                    k += 1;
                    break;
                }
            }
            if (k == 0) {
                cout << "Такого числа в массиве нет\n";
            }

            auto end7 = high_resolution_clock::now();
            auto duration7 = duration_cast<nanoseconds>(end7 - start7).count();
            cout << "Поиск числа перебором закончилось за " << duration7 << " наносекунд.\n";


            int number71;
            cout << "Бинарный поиск, введите число, котрое хотите найти ";
            cin >> number71;

            auto start71 = high_resolution_clock::now();
            binarySearch(gnomeArr, number71, 0, arrLength - 1);
            auto end71 = high_resolution_clock::now();
            auto duration71 = duration_cast<nanoseconds>(end71 - start71).count();


            int resualtOfSearch = binarySearch(gnomeArr, number71, 0, arrLength - 1);

            if (resualtOfSearch == -1) {
                cout << "Такого элемента в массиве нет\n";
            }
            else {
                cout << "Элемент в массиве присутствует\n";
            }
            cout << "Поиск числа с помощью бинарного поиска закончилось за " << duration71 << " наносекунд.\n\n";
        }

        if (menuNumber == 8) {
            int firstNumber, secondNumber, firstNumber1, secondNumber1;

            cout << "Введите индексы чисел, которые хотите поменять местами\n";
            for (int i = 0; i < arrLength; ++i)
            {
                swapArr[i] = gnomeArr[i];
            }


            cin >> firstNumber;
            cin >> secondNumber;

            auto start9 = high_resolution_clock::now();
            if (0 < firstNumber && firstNumber < arrLength + 1 && 0 < secondNumber && secondNumber < arrLength + 1) {
                
                firstNumber1 = firstNumber - 1;
                secondNumber1 = secondNumber - 1;
                swap(swapArr[firstNumber1], swapArr[secondNumber1]);

            }
            else {
                cout << "Один из индексов не существует, попробуйте еще раз, пока что ";
            }

            auto end9 = high_resolution_clock::now();
            auto duration9 = duration_cast<nanoseconds>(end9 - start9).count();

            cout << "Массив выглядит так: ";
            for (int i = 0; i < arrLength; ++i) {
                cout << swapArr[i] << ' ';
            }
            cout << '\n';


            cout << "Перестановка чисел заняла " << duration9 << " наносекунд.\n\n";
        }

        if (menuNumber == 9) {
            int k = 0;

            /* int n;
            *
            cout << "Введите n ";

            cin >> n;

            for (int i = 1; i < n + 1; ++i) {
                if (gnomeArr[i - 1] == i) {
                    k += 1;
                }
            }
            if (k == n) {
                cout << "yes\n\n";
            }

            else {
                cout << "no\n\n";
            }*/

            for (int i = -99; i < 100; ++i) {
                if (gnomeArr[i - 1] == i) {
                    k += 1;
                }
            }
            if (k == 199) {
                cout << "Да\n\n";
            }
            else {
                cout << "Нет\n\n";
            }
        }


        if (menuNumber > 9 || menuNumber < 0) {
            cout << "Такого числа в перечне нет, попробуйте еще раз\n";
        }

    }

    while (menuNumber != 0);
}
