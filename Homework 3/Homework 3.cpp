#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void insertionSort(int arr[], int size) {
    int key;
    int j = 0;
    for (int i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < (size - i - 1); j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int* myarray;
    int size = 0;
    int x = 0;

    while (x != 3) {
        cout << "[1]Insertion sort" << endl << "[2]Bubble sort" << endl << "[3]Exit" << endl;
        cin >> x;
        switch (x)
        {
        case 1 :
        {
            cout << "Enter the size of an array: " << endl;
            cin >> size;
            myarray = new int[size];
            cout << "Enter " << size << " integers in any order : " << endl;

            for (int i = 0; i < size; i++) {
                cin >> myarray[i];
            }

            cout << endl << "Initial data: " << endl;
            for (int i = 0; i < size; i++) {
                cout << myarray[i] << " ";
            }

            cout << endl << endl << "-----------------------------------" << endl;

            auto startIns = high_resolution_clock::now();
            insertionSort(myarray,size); //sorting by insertion
            auto stopIns = high_resolution_clock::now();
            auto durationIns = duration_cast<microseconds>(stopIns - startIns);

            cout << endl << "Sorted by Insertion Sort: " << endl << endl;

            for (int i = 0; i < size; i++) {
                cout << myarray[i] << " ";
            }

            cout << endl << endl << "Time taken by function : "
                << durationIns.count() << " microseconds" << endl << endl;
        }
            break;

        case 2:
        {
            cout << "Enter the size of an array: " << endl;
            cin >> size;
            myarray = new int[size];

            cout << "Enter " << size << " integers in any order : " << endl;
            for (int i = 0; i < size; i++) {
                cin >> myarray[i];
            }

            cout << endl << "Initial data: " << endl;
            for (int i = 0; i < size; i++) {
                cout << myarray[i] << " ";
            }

            cout << endl << endl << "-----------------------------------" << endl;

            auto startBubble = high_resolution_clock::now();
            bubbleSort(myarray,size); // sorting by bubble
            auto stopBubble = high_resolution_clock::now();
            auto durationBubble = duration_cast<microseconds>(stopBubble - startBubble);

            cout << endl << "Sorted by Bubble Sort: " << endl;
            for (int i = 0; i < size; i++) {
                cout << myarray[i] << " ";
            }

            cout << endl << endl << "Time taken by function: "
                << durationBubble.count() << " microseconds" << endl;
        }
            break;

        case 3:
            break;
            exit;
        }
    }
    return 0;
}
