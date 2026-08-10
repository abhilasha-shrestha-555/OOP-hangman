#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to store a task
// It holds task description and its completion status
struct Task {
    string description;  // stores task text
    bool completed;      // true if task is done, false if not
};

// Function to display menu options
// Shows all choices available to user
void showMenu() {
    cout << "\n===== TO-DO LIST MENU =====\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Delete Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}	

// Function to add a new task into the list
void addTask(vector<Task>& tasks) {
    Task newTask;

    cin.ignore(); // clears input buffer so getline works properly

    cout << "Enter task description: ";
    getline(cin, newTask.description); // takes full sentence input

    newTask.completed = false; // new task is always not completed

    tasks.push_back(newTask); // adds task to vector list

    cout << "Task added successfully!\n";
}

// Function to display all tasks
void viewTasks(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\nYour Tasks:\n";

    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description;

        // shows task status
        if (tasks[i].completed)
            cout << " [Completed]";
        else
            cout << " [Not Completed]";

        cout << endl;
    }
}

// Function to mark a task as completed
void markCompleted(vector<Task>& tasks) {
    int index;

    cout << "Enter task number to mark as completed: ";
    cin >> index;

    // check if input is valid
    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

// Function to delete a task from list
void deleteTask(vector<Task>& tasks) {
    int index;

    cout << "Enter task number to delete: ";
    cin >> index;

    // validate index before deleting
    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted successfully!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

// Main function where program starts
int main() {
    vector<Task> tasks; // stores all tasks dynamically
    int choice;

    do {
        showMenu(); // show menu to user
        cin >> choice;

        // perform action based on user choice
        switch (choice) {
            case 1:
                addTask(tasks);
                break;

            case 2:
                viewTasks(tasks);
                break;

            case 3:
                markCompleted(tasks);
                break;

            case 4:
                deleteTask(tasks);
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5); // loop until user exits

    return 0;
}