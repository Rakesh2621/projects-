#include <iostream>
#include <vector>
using namespace std;


struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    
    void addTask(const string& description) {
        Task newTask(description);
        tasks.push_back(newTask);
        cout << "Task added: " << description << endl;
    }

    void completeTask(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            tasks[taskIndex].completed = true;
            cout << "Task completed: " << tasks[taskIndex].description << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            cout << "Task removed: " << tasks[taskIndex].description << endl;
            tasks.erase(tasks.begin() + taskIndex);
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void displayTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the to-do list." << endl;
        } else {
            cout << "To-Do List:" << endl;
            for (size_t i = 0; i < tasks.size(); i++) {
                cout << "[" << i << "] " << (tasks[i].completed ? "[X] " : "[ ] ") << tasks[i].description << endl;
            }
        }
    }
};

int main() {
    ToDoList toDoList;
    int choice;
    string description;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Complete Task" << endl;
        cout << "3. Remove Task" << endl;
        cout << "4. Display Tasks" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, description);
                toDoList.addTask(description);
                break;
            case 2:
                toDoList.displayTasks();
                cout << "Enter the task index to mark as completed: ";
                cin >> choice;
                toDoList.completeTask(choice);
                break;
            case 3:
                toDoList.displayTasks();
                cout << "Enter the task index to remove: ";
                cin >> choice;
                toDoList.removeTask(choice);
                break;
            case 4:
                toDoList.displayTasks();
                break;
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
