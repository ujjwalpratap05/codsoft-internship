#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

std::vector<Task> toDoList;

// Function to add a task
void addTask() {
    Task newTask;
    std::cout << "Enter the task description: ";
    std::cin.ignore();
    std::getline(std::cin, newTask.description);
    newTask.completed = false;
    toDoList.push_back(newTask);
    std::cout << "Task added successfully.\n";
}

// Function to view all tasks
void viewTasks() {
    if (toDoList.empty()) {
        std::cout << "Your to-do list is empty.\n";
        return;
    }
    std::cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < toDoList.size(); ++i) {
        std::cout << i + 1 << ". " << toDoList[i].description
                  << " [" << (toDoList[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

// Function to mark a task as completed
void markTaskAsCompleted() {
    int taskNumber;
    std::cout << "Enter the task number to mark as completed: ";
    std::cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= static_cast<int>(toDoList.size())) {
        toDoList[taskNumber - 1].completed = true;
        std::cout << "Task marked as completed.\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

// Function to remove a task
void removeTask() {
    int taskNumber;
    std::cout << "Enter the task number to remove: ";
    std::cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= static_cast<int>(toDoList.size())) {
        toDoList.erase(toDoList.begin() + taskNumber - 1);
        std::cout << "Task removed successfully.\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

// Function to display menu options
void displayMenu() {
    std::cout << "\nTo-Do List Manager\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Mark Task as Completed\n";
    std::cout << "4. Remove Task\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskAsCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                std::cout << "Exiting To-Do List Manager. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
