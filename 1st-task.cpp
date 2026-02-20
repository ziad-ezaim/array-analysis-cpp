#include <iostream>     // Allows input/output operations (cout, endl)
#include <cstdlib>      // Includes rand() and srand()
#include <ctime>        // Includes time() for random seed
using namespace std;    // Allows us to use names like cout without std::

// Function to fill the array with random values
void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {    // Loop through the array
        arr[i] = rand() % 1501;          // Store a random number between 0 and 100 in each element
    }
}

// Function to display the array values
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i ++) {    // Loop through the array
        cout << arr[i] << " ";          // Print each value followed by a space
    }
    cout << endl;                        // Move to the next line after printing all values
}

// Function to find the minimum and maximum values in the array
void findMinMax(int arr[], int size, int &minVal, int &maxVal) {
    minVal = arr[0];                     // Start min value as the first array element
    maxVal = arr[0];                     // Start max value as the first array element

    for (int i = 1; i < size; i++) {     // Loop starting from the second element
        if (arr[i] < minVal)             // If current value is smaller than current minimum
            minVal = arr[i];             // Update the minimum value

        if (arr[i] > maxVal)             // If current value is larger than current maximum
            maxVal = arr[i];             // Update the maximum value
    }
}

int main() {
    srand(time(0));                      // Set a random seed based on current time

    int arr[500];                        // Declare an array of 500 integers
    int minVal, maxVal;                  // Variables to store min and max values

    fillArray(arr, 500);                 // Call function to fill the array with random numbers
    displayArray(arr, 500);              // Call function to display all the values

    findMinMax(arr, 500, minVal, maxVal);// Call function to find min and max

    cout << "Minimum value: " << minVal << endl;  // Print the minimum value
    cout << "Maximum value: " << maxVal << endl;  // Print the maximum value

    return 0;                            // End of the program
}
 
