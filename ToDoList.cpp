#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to hold a task
struct Task {
    string title;
    bool isDone;
};

// Display the menu
void showMenu() {
    cout << "\n====== TO-DO LIST MENU ======\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Done\n";
    cout << "4. Delete Task\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

// View all tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks found.\n";
        return;
    }

    cout << "\n------ Tasks ------\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].title;
        if (tasks[i].isDone) cout << " [Done]";
        cout << endl;
    }
}

// Main function
int main() {
    vector<Task> tasks;
    int choice;

    do {
        showMenu();
        cin >> choice;
        cin.ignore();  // Clear newline from buffer

        switch (choice) {
            case 1: {
                Task newTask;
                cout << "Enter task title: ";
                getline(cin, newTask.title);
                newTask.isDone = false;
                tasks.push_back(newTask);
                cout << "Task added!\n";
                break;
            }
            case 2: {
                viewTasks(tasks);
                break;
            }
            case 3: {
                int num;
                viewTasks(tasks);
                cout << "Enter task number to mark as done: ";
                cin >> num;
                if (num >= 1 && num <= tasks.size()) {
                    tasks[num - 1].isDone = true;
                    cout << "Task marked as done.\n";
                } else {
                    cout << "Invalid task number.\n";
                }
                break;
            }
            case 4: {
                int num;
                viewTasks(tasks);
                cout << "Enter task number to delete: ";
                cin >> num;
                if (num >= 1 && num <= tasks.size()) {
                    tasks.erase(tasks.begin() + num - 1);
                    cout << "Task deleted.\n";
                } else {
                    cout << "Invalid task number.\n";
                }
                break;
            }
            case 5: {
                cout << "Goodbye!\n";
                break;
            }
            default: {
                cout << "Invalid option. Try again.\n";
                break;
            }
        }

    } while (choice != 5);

    return 0;
}