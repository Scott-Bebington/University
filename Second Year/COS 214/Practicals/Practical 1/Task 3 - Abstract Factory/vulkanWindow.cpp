#include "vulkanWindow.h"

string vulkanWindow::printAllPrimitiveToStrings() {
    string result;
    for (int i = 0; i < primitiveCount; ++i) {
        string temp = primitives[i].toString();
        // replace all \n with \n\t
        for (size_t j = 0; j < temp.length(); ++j) {
            if (temp[j] == '\n') {
                temp.insert(j + 1, "\t");
            }
        }
        result += "\t" + temp + "\n";
    }
    return result;
}

string vulkanWindow::toString() {
    return "Vulkan window " 
    + to_string(screenWidth) + "x" + to_string(screenHeight) 
    + ":\n" + printAllPrimitiveToStrings();
}

vulkanPrimitive *vulkanWindow::getVulkanPrimitives()
{
    return nullptr;
}

void vulkanWindow::setVulkanPrimitives(vulkanPrimitive *)
{
}

void vulkanWindow::addPrimitive(vulkanPrimitive prim)
{
    if(this->primitiveCount == 0) {
        this->primitives = new vulkanPrimitive[1];
        this->primitives[0] = prim;
        this->primitiveCount++;
        return;
    }

    if (this->primitiveCount == 7) {
        cout << "Cannot add more than 7 primitives to an vulkanWindow" << endl;
        return;
    }

    vulkanPrimitive* newPrimitives = new vulkanPrimitive[this->primitiveCount + 1];
    for (int i = 0; i < this->primitiveCount; ++i) {
        newPrimitives[i] = this->primitives[i];
    }
    newPrimitives[this->primitiveCount] = prim;
    primitiveCount++;
    this->primitives = newPrimitives;
}
