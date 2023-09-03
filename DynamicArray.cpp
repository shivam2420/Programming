#include <iostream>
#include <ctime>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

public:
    DynamicArray() {
        size = 0;
        capacity = 2;
        arr = new int[capacity];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void insert(int element) {
        if (size == capacity) {
            capacity *= 2;
            int* new_arr = new int[capacity];
            for (int i = 0; i < size; i++) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
        }
        arr[size++] = element;
    }

    void remove() {
        if (size > 0) {
            size--;

            if (size < capacity / 2) {
                capacity /= 2;
                int* new_arr = new int[capacity];
                for (int i = 0; i < size; i++) {
                    new_arr[i] = arr[i];
                }
                delete[] arr;
                arr = new_arr;
            }
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray dynamicArray;

    clock_t start_time = clock();

    for (int i = 0; i < 900; i++) {
        dynamicArray.insert(i);
    }

    for (int i = 0; i < 100; i++) {
        dynamicArray.remove();
    }

    clock_t end_time = clock();
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Time taken: " << time_taken << " seconds" <<endl;

    return 0;
}

