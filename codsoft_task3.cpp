#include <iostream>
#include <vector>
#include <string>
using namespace std;
void displayMenu() {
    cout << "\n *-*-*-* TO-DO LIST MANAGER *-*-*-* \n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. remove Task\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

void addTask(vector<string> &tasks) {
    string task;
    cout << "Enter task: ";
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added successfully.\n";
}

void viewTasks(const vector<string> &tasks) {
    cout << "\n******Tasks*******\n";
    if (tasks.empty()) {
        cout << "No tasks available.\n";
    } else {
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
}

void removeTask(vector<string> &tasks) {
    viewTasks(tasks);
    if (!tasks.empty()) {
        int index;
        cout << "Enter the index of the task to delete: ";
        cin >> index;
        if (index > 0 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task deleted successfully.\n";
        } else {
            cout << "Invalid index.\n";
        }
    }
}
int main() {
    vector<string> tasks;
    char choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case '1':
                addTask(tasks);
                break;
            case '2':
                viewTasks(tasks);
                break;
            case '3':
                removeTask(tasks);
                break;
            case '4':
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != '4');

    return 0;
}

