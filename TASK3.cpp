#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class TaskManager {
private:
    vector<Task> tasks;

public:
    void addTask(const string& taskDescription) {
        tasks.push_back(Task(taskDescription));
        cout << "Task added: " << taskDescription << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks to display." << endl;
            return;
        }

        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            const Task& task = tasks[i];
            cout << i + 1 << ". " << task.description << " - " << (task.completed ? "Completed" : "Pending") << endl;
        }
    }

    void markTaskCompleted(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < static_cast<int>(tasks.size())) {
            tasks[taskIndex].completed = true;
            cout << "Task marked as completed: " << tasks[taskIndex].description << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < static_cast<int>(tasks.size())) {
            cout << "Task removed: " << tasks[taskIndex].description << endl;
            tasks.erase(tasks.begin() + taskIndex);
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};

int main() {
    TaskManager taskManager;

    while (true) {
        cout << "\nOptions:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    string taskDescription;
                    cout << "Enter the task: ";
                    cin.ignore(); // Clear the newline character from the previous input
                    getline(cin, taskDescription);
                    taskManager.addTask(taskDescription);
                }
                break;
            case 2:
                taskManager.viewTasks();
                break;
            case 3:
                int taskIndex;
                cout << "Enter the task index to mark as completed: ";
                cin >> taskIndex;
                taskManager.markTaskCompleted(taskIndex - 1);
                break;
            case 4:
                int removeIndex;
                cout << "Enter the task index to remove: ";
                cin >> removeIndex;
                taskManager.removeTask(removeIndex - 1);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
