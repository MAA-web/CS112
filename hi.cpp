#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Structure to hold tool information
struct Tool {
    char name[20];
    int quantity;
    double cost;
};

// Function to initialize the hardware.dat file with empty records
void initializeFile() {
    Tool emptyTool = {"", 0, 0.0};

    ofstream outFile("hardware.dat", ios::binary);

    if (!outFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    for (int i = 0; i < 100; ++i) {
        outFile.write(reinterpret_cast<const char*>(&emptyTool), sizeof(Tool));
    }

    outFile.close();
}

// Function to add a new tool record to the file
void addTool() {
    Tool tool;

    cout << "Enter tool name: ";
    //cin.getline(tool.name, 20);
    cin >> tool.name;

    cout << "Enter quantity: ";
    cin >> tool.quantity;

    cout << "Enter cost: ";
    cin >> tool.cost;

    cin.ignore(); // Ignore the newline character

    // Open the file in binary append mode
    fstream file("hardware.dat", ios::binary | ios::in | ios::out | ios::app);

    if (!file) {
        cerr << "Error opening file." << endl;
        return;
    }

    file.write(reinterpret_cast<const char*>(&tool), sizeof(Tool));

    file.close();
}

// Function to list all the tools in the file
void listTools() {
    Tool tool;

    ifstream inFile("hardware.dat", ios::binary);

    if (!inFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    cout << left << setw(5) << "Record#" << setw(20) << "Tool name"
         << setw(10) << "Quantity" << setw(10) << "Cost" << endl;

    while (inFile.read(reinterpret_cast<char*>(&tool), sizeof(Tool))) {
        if (tool.name[0] != '\0') {
            cout << setw(5) << inFile.tellg() / sizeof(Tool) - 1
                 << setw(20) << tool.name
                 << setw(10) << tool.quantity
                 << setw(10) << fixed << setprecision(2) << tool.cost << endl;
        }
    }

    inFile.close();
}

// Function to delete a tool record from the file
void deleteTool() {
    int recordNumber;
    cout << "Enter the record number of the tool to delete: ";
    cin >> recordNumber;

    fstream file("hardware.dat", ios::binary | ios::in | ios::out);

    if (!file) {
        cerr << "Error opening file." << endl;
        return;
    }

    Tool emptyTool = {"", 0, 0.0};

    file.seekp(recordNumber * sizeof(Tool));
    file.write(reinterpret_cast<const char*>(&emptyTool), sizeof(Tool));

    file.close();
}

// Function to update tool information in the file
void updateTool() {
    int recordNumber;
    cout << "Enter the record number of the tool to update: ";
    cin >> recordNumber;

    Tool tool;

    cout << "Enter tool name: ";
    cin.ignore();
    cin.getline(tool.name, 20);

    cout << "Enter quantity: ";
    cin >> tool.quantity;

    cout << "Enter cost: ";
    cin >> tool.cost;

    fstream file("hardware.dat", ios::binary | ios::in | ios::out);

    if (!file) {
        cerr << "Error opening file." << endl;
        return;
    }

    file.seekp(recordNumber * sizeof(Tool));
    file.write(reinterpret_cast<const char*>(&tool), sizeof(Tool));

    file.close();
}

int main() {
    initializeFile();

    while (true) {
        int choice;
        cout << endl;
        cout << "1. Add a tool" << endl;
        cout << "2. List all tools" << endl;
        cout << "3. Delete a tool" << endl;
        cout << "4. Update tool information" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTool();
                break;
            case 2:
                listTools();
                break;
            case 3:
                deleteTool();
                break;
            case 4:
                updateTool();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
