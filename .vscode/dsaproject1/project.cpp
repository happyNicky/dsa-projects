#include<iostream>
using namespace std;


void searchMenu(int list[], int size);
void sortMenu(int list[], int size);
void linearSearch(int list[], int size);
void binarySearch(int list[], int size);
void simpleSort(int list[], int size);
void bubbleSort(int list[], int size);
void selectionSort(int list[], int size);
void insertionSort(int list[], int size);
void binaryInsertionSort(int list[], int size);
void displayList(int list[], int size) {
    for (int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}




int main() {
    int size;
    const int MAX_SIZE = 50;
    int list[MAX_SIZE];
     A:cout << "Enter the number of elements: ";
    cin >> size;
    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++) {
        cin >> list[i];
    }
    
     // Current number of elements in the listay
    int choice;

    do {
        cout << "\nMain Menu:\n";
        cout << "1. Search\n";
        cout << "2. Sort\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (size == 0) {
                cout << "You need to input numbers first before searching!\n";
                goto A;
                 
            }
            searchMenu(list, size);
            break;
        case 2:
              // Ask user to input numbers for sorting
            sortMenu(list, size);
            break;
        case 3:
            cout << "Goodbye\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

// Search Menu
void searchMenu(int list[], int size) {
    int choice;
    do {
        cout << "\nSearch Menu:\n";
        cout << "1. Linear Search\n";
        cout << "2. Binary Search\n";
        cout << "3. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            linearSearch(list, size);
            break;
        case 2:
            binarySearch(list, size);
            break;
        case 3:
            return;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 3);
}

// Linear Search
void linearSearch(int list[], int size) {
    int key;
    cout << "Enter number to search: ";
    cin >> key;

    for (int i = 0; i < size; i++) {
        if (list[i] == key) {
            cout << "Number " << key << " found at index " << i << endl;
            return;
        }
    }
    cout << "Number " << key << " not found.\n";
}


void binarySearch(int list[], int size) {
   
   
    int left = 0, right = size - 1, key,mid;

    cout << "Enter number to search: ";
    cin >> key;

    while (left <= right) {
         mid = left+(right-left)  / 2;

        if (list[mid] == key) {
            cout << "Number " << key << " found at index " << mid << endl;
            return;
        }
        if (list[mid] < key)
            left = mid+1;
        else
            right = mid-1;
    }
    cout << "Number " << key << " not found.\n";
}

// Sort Menu
void sortMenu(int list[], int size) {
    int choice;
    do {
        cout << "\nSort Menu:\n";
        cout << "1. Simple Sort\n";
        cout << "2. Bubble Sort\n";
        cout << "3. Selection Sort\n";
        cout << "4. Insertion Sort\n";
        cout << "5. Binary Insertion Sort\n";
        cout << "6. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

switch (choice) {
        case 1:
            simpleSort(list, size);
            displayList(list, size);
            break;
        case 2:
            bubbleSort(list, size);
            displayList(list, size);
            break;
        case 3:
            selectionSort(list, size);
            displayList(list, size);
            break;
        case 4:
            insertionSort(list, size);
            displayList(list, size);
            break;
        case 5:
            binaryInsertionSort(list, size);
            displayList(list, size);
            break;
        case 6:
            return;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 6);
}


void simpleSort(int list[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (list[i] > list[j]) {
                
                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}


void bubbleSort(int list[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                // Swap list[j] and list[j + 1]
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int list[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (list[j] < list[minIndex])
                minIndex = j;
        }
        // Swap list[i] and list[minIndex]
        int temp = list[i];
        list[i] = list[minIndex];
        list[minIndex] = temp;
    }
}
//[2,5,9,1]

void insertionSort(int list[], int size) {
    for (int i = 1; i < size; i++) {
        int key = list[i];
        int j = i - 1;
        while (j >= 0 && list[j] > key) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = key;
    }
}

//[5, 2, 9, 1, 5, 6]
//[2,5,9,1,5,6]
void binaryInsertionSort(int list[], int size) {
    for (int i = 1; i < size; i++) {
        int key = list[i];
        int left = 0, right = i - 1; 
        while (left <= right) {
            int mid = left + (right - left) / 2; 
            if (list[mid] > key)
                right = mid - 1;  
            else
                left = mid + 1;  
        }
        for (int j = i - 1; j >= left; j--) {  
        }
        list[left] = key;
        
    }
}