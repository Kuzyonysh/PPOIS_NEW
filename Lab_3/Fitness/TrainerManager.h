#pragma once
#include <vector>
#include "Trainer.h"
using namespace std;

class TrainerManager {
private:
    vector<Trainer> trainers;

public:
    TrainerManager() = default;
    void addTrainer(const Trainer& t);
    vector<Trainer> getAll() const;
    int getAvailableCount() const;
};

