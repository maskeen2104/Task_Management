#include <iostream>
#include <queue>
#include <string>
#include "../include/task.h"

// int main() {
//     std::priority_queue<Task> taskQueue;

//     char choice;
//     do {
//         std::string description;
//         int priority;

//         std::cout << "Enter task description: ";
//         std::getline(std::cin, description);

//         std::cout << "Enter task priority: ";
//         while (!(std::cin >> priority)) {
//             std::cin.clear();
//             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//             std::cout << "Invalid input. Enter a valid priority: ";
//         }
//         std::cin.ignore(); // Consume the newline character left in the stream

//         // Create a new task and add it to the priority queue
//         Task newTask(description, priority);
//         taskQueue.push(newTask);

//         std::cout << "Task added to the queue.\n";

//         std::cout << "Do you want to add another task? (y/n): ";
//         std::cin >> choice;
//         std::cin.ignore(); // Consume the newline character left in the stream

//     } while (choice == 'y' || choice == 'Y');

//     // Display tasks in priority order
//     std::cout << "\nTasks in priority order:\n";
//     while (!taskQueue.empty()) {
//         Task currentTask = taskQueue.top();
//         currentTask.displayTask();
//         taskQueue.pop();
//     }

//     return 0;
// }


// int main() {
//     std::priority_queue<Task> taskQueue;
//     std::string name;
//     int priority;
//     int choice;

//     std::cout << "Welcome to the Task Management System!\n";
//     std::cout << "Choose an option from the following:\n";
//     std::cout << "1. Add a task\n";
//     std::cout << "2. Display tasks\n";
//     std::cout << "3. Exit\n";

//     std::cin >> choice;

//     char choice2;
//     if (choice == 1) {
//         do {
//             std::cout << "Enter task name:\n";
//             std::getline(std::cin, name);
            
//             std::cout << "Enter task priority:\n";
//             std::cin >> priority;
//             std::cin.ignore();
            
//             Task task(name, priority);
//             taskQueue.push(task);
//             std::cout << "Task added to the queue.\n";

//             std::cout << "Do you want to add another task? (y/n): ";
//             std::cin >> choice2;
//         } while (choice2 == 'y' || choice2 == 'Y');
        
//         std::cout << "Welcome to the Task Management System!\n";
//         std::cout << "Choose an option from the following:\n";
//         std::cout << "1. Add a task\n";
//         std::cout << "2. Display tasks\n";
//         std::cout << "3. Exit\n";
        
//         std::cin >> choice;
//     } 

//     else if (choice == 2) {
//         std::cout << "\nTasks in priority order:\n";
//         while (!taskQueue.empty()) {
//             Task currentTask = taskQueue.top();
//             currentTask.displayTask();
//             taskQueue.pop();
//         }
//         std::cout << "Welcome to the Task Management System!\n";
//         std::cout << "Choose an option from the following:\n";
//         std::cout << "1. Add a task\n";
//         std::cout << "2. Display tasks\n";
//         std::cout << "3. Exit\n";
        
//         std::cin >> choice;
//     }

//     else if (choice == 3) {
//         std::cout << "Exiting...\n";
//     }

//     else  {
//         std::cout << "Invalid input. Please try again.\n";

//         std::cout << "Welcome to the Task Management System!\n";
//         std::cout << "Choose an option from the following:\n";
//         std::cout << "1. Add a task\n";
//         std::cout << "2. Display tasks\n";
//         std::cout << "3. Exit\n";
        
//         std::cin >> choice;
//     }

//     return 0;

// }


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
        std::cout << "3. Exit\n";

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
            std::cout << "Exiting...\n";
            break;  // Exit the loop and end the program
        }
        else {
            std::cout << "Invalid input. Please try again.\n";
        }
    }

    return 0;
}
