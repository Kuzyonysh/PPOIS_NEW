#include "TrainerManager.h"

void TrainerManager::addTrainer(const Trainer& t) {
    trainers.push_back(t);
}

vector<Trainer> TrainerManager::getAll() const {
    return trainers;
}

int TrainerManager::getAvailableCount() const {
    int count = 0;
    for (const auto& t : trainers)
        if (t.getAvailability()) count++;
    return count;
}
