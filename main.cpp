#include <iostream>
#include <fstream> // For file operations

using namespace std;

// Function to read numbers
void readNums(int numsArr[], int Plithos) {
    for (int i = 0; i < Plithos; i++) {
        cout << "Dose arithmo " << i+1 << ": ";
        cin >> numsArr[i];
    }
}

// Function to display numbers
void displayNums(int numsArr[], int Plithos) {
    cout << "\nThe numbers are: ";
    for (int i = 0; i < Plithos; i++) {
        cout << numsArr[i] << " ";
    }
}

// Function to calculate average
float avg(int numsArr[], int Plithos) {
    float sum = 0;
    for (int i = 0; i < Plithos; i++) {
        sum += numsArr[i];
    }
    return sum / Plithos;
}

// Function to find maximum number
int findMax(int numsArr[], int Plithos) {
    int max = numsArr[0];
    for (int i = 1; i < Plithos; i++) {
        if (numsArr[i] > max) {
            max = numsArr[i];
        }
    }
    return max;
}

// Function to save results to a file
void saveToFile(int numsArr[], int Plithos, float average, int maximum) {
    ofstream outputFile("apotelesmata.txt"); // Open file for writing
    if (outputFile.is_open()) {
        outputFile << "Numbers: ";
        for (int i = 0; i < Plithos; i++) {
            outputFile << numsArr[i] << " ";
        }
        outputFile.close();
        cout << "Results saved to 'results.txt'." << endl;
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}
// Function to read numbers from a file
void readFromFile(int numsArr[], int& Plithos) {
    ifstream inputFile("apotelesmata.txt"); // Open file for reading
    if (inputFile.is_open()) {
        inputFile >> Plithos; // Read the number of elements
        for (int i = 0; i < Plithos; i++) {
            inputFile >> numsArr[i]; // Read each element
        }
        inputFile.close();
        cout << "Data read from 'data.txt'." << endl;
    } else {
        cout << "Unable to open file for reading." << endl;
    }
}

int main() {
    int NumsArr[20]; // Array to store numbers
    int Plithos;     // Variable to store the number of elements
    float Aver;      // Variable to store the average
    int Maxi;        // Variable to store the maximum value

    // Ask for the number of elements
    cout << "Dose to plithos: ";
    cin >> Plithos;

    // Call function to read numbers
    readNums(NumsArr, Plithos);

    // Call function to display numbers
    displayNums(NumsArr, Plithos);

    // Call function to calculate average
    Aver = avg(NumsArr, Plithos);

    // Call function to find maximum value
    Maxi = findMax(NumsArr, Plithos);

    // Display results
    cout << "\nThe average is: " << Aver;
    cout << "\nThe maximum is: " << Maxi;

    // Save results to file
    saveToFile(NumsArr, Plithos, Aver, Maxi);

    return 0;
}
