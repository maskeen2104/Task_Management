#include "../include/task.h"
#include <iostream> //The cout stream is defined in this header file

Task::Task() {
    std::cout << "Enter the name of the task:";
    std::getline(std::cin, name); //Get the whole line entered by the user

    std::cout << "Enter priority of the task:";
    std::cin >> priority;
    std::cin.ignore(); // To consume the newline character left in the stream
}

Task::Task(const std::string& name, int priority)
    : name(name), priority(priority) {}

void Task::displayTask() const {
    std::cout << "Task name:" << name << "\tPriority:" << priority << "\n" << std:: endl;
}

void Task::adjustPriority(int newPriority) {
    priority = newPriority;
}