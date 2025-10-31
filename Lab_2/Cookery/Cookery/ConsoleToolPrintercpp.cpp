#include "ConsoleToolPrinter.h"

void ConsoleToolPrinter::print(const Tool& tool) const {
    cout << "Tool: " << tool.getName() << endl;
    cout << "Condition: " << tool.getConditionName() << endl;
    cout << "Purpose: " << tool.getPurposeName() << endl;
    cout << "Material: " << tool.getMaterial() << endl;
    cout << "Weight: " << tool.getWeight() << endl;
    cout << "Brand: " << tool.getBrand() << endl;
    cout << "Color: " << tool.getColor() << endl;
    cout << "Durability: " << tool.getDurability() << endl;
    cout << "Length: " << tool.getLength() << endl;
    cout << "Width: " << tool.getWidth() << endl;
}
