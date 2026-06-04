#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Mission 1: Remove Duplicate Elements from Array
void mission1() {
    cout << "\n--- Mission 1: Remove the Twins ---" << endl;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    if (n <= 0) return;
    
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> uniqueArr;
    for(int i = 0; i < n; i++) {
        bool isDuplicate = false;
        for(size_t j = 0; j < uniqueArr.size(); j++) {
            if(arr[i] == uniqueArr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if(!isDuplicate) {
            uniqueArr.push_back(arr[i]);
        }
    }
    
    cout << "Unique values: ";
    for(size_t i = 0; i < uniqueArr.size(); i++) {
        cout << uniqueArr[i] << " ";
    }
    cout << endl;
}

// Mission 2: Find the Largest and Second Largest Element
void mission2() {
    cout << "\n--- Mission 2: Topper Finder ---" << endl;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    if (n < 2) {
        cout << "Array must have at least 2 elements." << endl;
        return;
    }
    
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    int secondLargest = INT_MIN;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] > secondLargest && arr[i] < largest) {
            secondLargest = arr[i];
            found = true;
        }
    }

    cout << "Largest Element: " << largest << endl;
    if (found) {
        cout << "Second Largest Element: " << secondLargest << endl;
    } else {
        cout << "No second largest element found (all elements might be duplicates)." << endl;
    }
}

// Mission 3: Sort in Ascending & Descending Order
void mission3() {
    cout << "\n--- Mission 3: Sort Squad ---" << endl;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    if (n <= 0) return;
    
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> ascArr = arr;
    // Bubble sort for ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ascArr[j] > ascArr[j + 1]) {
                int temp = ascArr[j];
                ascArr[j] = ascArr[j + 1];
                ascArr[j + 1] = temp;
            }
        }
    }

    vector<int> descArr = arr;
    // Selection sort for descending order
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (descArr[j] > descArr[maxIdx]) {
                maxIdx = j;
            }
        }
        int temp = descArr[i];
        descArr[i] = descArr[maxIdx];
        descArr[maxIdx] = temp;
    }

    cout << "Ascending Order: ";
    for (int i = 0; i < n; i++) cout << ascArr[i] << " ";
    cout << "\nDescending Order: ";
    for (int i = 0; i < n; i++) cout << descArr[i] << " ";
    cout << endl;
}

// Mission 4: Count Positive, Negative
void mission4() {
    cout << "\n--- Mission 4: Count values ---" << endl;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    if (n <= 0) return;
    
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    int posCount = 0, negCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) posCount++;
        else if (arr[i] < 0) negCount++;
    }

    cout << "Positive numbers count: " << posCount << endl;
    cout << "Negative numbers count: " << negCount << endl;
}

// Mission 5: Sort Even and Odd Numbers Separately
void mission5() {
    cout << "\n--- Mission 5: Magic Sorter ---" << endl;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    if (n <= 0) return;
    
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> evens, odds;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) evens.push_back(arr[i]);
        else odds.push_back(arr[i]);
    }

    // Sort evens in ascending
    for (size_t i = 0; i < evens.size(); i++) {
        for (size_t j = i + 1; j < evens.size(); j++) {
            if (evens[i] > evens[j]) {
                int temp = evens[i];
                evens[i] = evens[j];
                evens[j] = temp;
            }
        }
    }

    // Sort odds in descending
    for (size_t i = 0; i < odds.size(); i++) {
        for (size_t j = i + 1; j < odds.size(); j++) {
            if (odds[i] < odds[j]) {
                int temp = odds[i];
                odds[i] = odds[j];
                odds[j] = temp;
            }
        }
    }

    // Merge them: First Evens, then Odds
    vector<int> merged;
    for (size_t i = 0; i < evens.size(); i++) merged.push_back(evens[i]);
    for (size_t i = 0; i < odds.size(); i++) merged.push_back(odds[i]);

    cout << "Merged Array (Evens Ascending, Odds Descending): ";
    for (size_t i = 0; i < merged.size(); i++) cout << merged[i] << " ";
    cout << endl;
}

int main() {
    int choice;
    do {
        cout << "\n===================================" << endl;
        cout << "           SORTIFY PROJECT         " << endl;
        cout << "===================================" << endl;
        cout << "1. Mission: Remove the Twins" << endl;
        cout << "2. Mission: Topper Finder" << endl;
        cout << "3. Mission: Sort Squad" << endl;
        cout << "4. Mission: Count values" << endl;
        cout << "5. Mission: Magic Sorter" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
   
        switch (choice) {
            case 1: mission1(); break;
            case 2: mission2(); break;
            case 3: mission3(); break;
            case 4: mission4(); break;
            case 5: mission5(); break;
            case 0: cout << "Exiting Sortify..." << endl; break;
            default: cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
