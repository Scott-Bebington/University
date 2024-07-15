#include "openGLWindow.h"

string openGLWindow::printAllPrimitiveToStrings() {
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

string openGLWindow::toString() {
    return "OpenGL window " 
    + to_string(screenWidth) + "x" + to_string(screenHeight) 
    + ":\n" + printAllPrimitiveToStrings();
}

openGLPrimitive *openGLWindow::getOpenGLPrimitives()
{
    return this->primitives;
}

void openGLWindow::setOpenGLPrimitives(openGLPrimitive * prims)
{
    this->primitives = prims;
}

void openGLWindow::addPrimitive(openGLPrimitive prim)
{
    if(this->primitiveCount == 0) {
        this->primitives = new openGLPrimitive[1];
        this->primitives[0] = prim;
        this->primitiveCount++;
        return;
    }

    if (this->primitiveCount == 3) {
        cout << "Cannot add more than 3 primitives to an openGLWindow" << endl;
        return;
    }

    openGLPrimitive* newPrimitives = new openGLPrimitive[this->primitiveCount + 1];
    for (int i = 0; i < this->primitiveCount; ++i) {
        newPrimitives[i] = this->primitives[i];
    }
    newPrimitives[this->primitiveCount] = prim;
    primitiveCount++;
    this->primitives = newPrimitives;
}
