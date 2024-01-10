#include <iostream>
#include <queue>
#include <string>
#include "../include/task.h"

int main() {
    std::priority_queue<Task> taskQueue;
    std::string name;
    int priority;
    char choice;

    while (true) {
        std::cout << "Welcome to the Task Management System!\n";
        std::cout << "Choose an option from the following:\n";
        std::cout << "1. Add a task\n";
        std::cout << "2. Display tasks\n";
        std::cout << "3. Remove completed task\n";
        std::cout << "4. Exit\n";

        std::cin >> choice;

        // Clear the input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == '1') {
            do {
                std::cout << "Enter task name:\n";
                std::getline(std::cin, name);
                
                std::cout << "Enter task priority:\n";
                std::cin >> priority;
                
                Task task(name, priority);
                taskQueue.push(task);
                std::cout << "Task added to the queue.\n";

                std::cout << "Do you want to add another task? (y/n): ";
                std::cin >> choice;

                // Clear the input buffer
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } while (choice == 'y' || choice == 'Y');
        } 

        else if (choice == '2') {
            std::cout << "\nTasks in priority order:\n";
            std::priority_queue<Task> tempQueue = taskQueue;  // Create a copy to avoid modifying the original queue
            while (!tempQueue.empty()) {
                Task currentTask = tempQueue.top();
                currentTask.displayTask();
                tempQueue.pop();
            }
        }

        else if (choice == '3') {
            std::cout << "Enter the name of the completed task:\n";
            std::getline(std::cin, name);

            // Create a temporary priority queue to hold tasks that are not completed
            std::priority_queue<Task> tempQueue;

            // Remove completed task from the original queue
            while (!taskQueue.empty()) {
                Task currentTask = taskQueue.top();
                taskQueue.pop();

                if (currentTask == name) {
                    // Skip the task, marking it as completed
                    std::cout << "Task '" << name << "' marked as completed.\n";
                } else {
                    tempQueue.push(currentTask);
                }
            }

            // Copy tasks back to the original queue
            taskQueue = tempQueue;
        }

        else if (choice == '4') {
            std::cout << "Exiting...\n";
            break;  // Exit the loop and end the program
        }

        else {
            std::cout << "Invalid input. Please try again.\n";
        }
    }

    return 0;
}
