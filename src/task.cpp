#include "../include/task.h"
#include <iostream> //The cout stream is defined in this header file

Task::Task(const std::string& name, int priority)
    : name(name), priority(priority) {}

void Task::displayTask() const {
    std::cout << "Task name:" << name << "\tPriority:" << priority << "\n" << std:: endl;
}

void Task::adjustPriority(int newPriority) {
    priority = newPriority;
}

bool Task::operator<(const Task& other) const {
    return priority > other.priority;
}