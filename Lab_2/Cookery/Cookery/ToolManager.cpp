#include "ToolManager.h"

void ToolManager::use(ITool& tool) const {
    if (tool.getConditionName() == "working")
        cout << tool.getName() << " is being used for " << tool.getPurposeName() << endl;
    else
        cout << tool.getName() << " can't be used — it's " << tool.getConditionName() << endl;
}

void ToolManager::repair(ITool& tool) const {
    if (tool.getConditionName() == "broken") {
        tool.setCondition("working");
        cout << tool.getName() << " has been repaired and is now working!" << endl;
    }
    else {
        cout << tool.getName() << " doesn't need repair." << endl;
    }
}

void ToolManager::breakTool(ITool& tool) const {
    tool.setCondition("broken");
    cout << tool.getName() << " has broken!" << endl;
}
