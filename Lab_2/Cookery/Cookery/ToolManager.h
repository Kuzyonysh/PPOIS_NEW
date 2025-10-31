#pragma once
#include "ITool.h"
#include <iostream>
using namespace std;

class ToolManager {
public:
    void use(ITool& tool) const;
    void repair(ITool& tool) const;
    void breakTool(ITool& tool) const;
};

