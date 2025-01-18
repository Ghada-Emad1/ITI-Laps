#include <iostream>
#include <string.h> // Use <cstring> for strcmp
using namespace std;

void SelectionSort(char arr[][10], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minimum = i;
        for (int j = i + 1; j < size; j++) {
            if (strcmp(arr[minimum], arr[j]) > 0) {
                minimum = j;
            }
        }
        if (minimum != i) {
            char temp[10];
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[minimum]);
            strcpy(arr[minimum], temp);
        }
    }
}

int main() {
    char arr[4][10] = {"ghada", "rokaya", "ali"};
    SelectionSort(arr, 3);
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
