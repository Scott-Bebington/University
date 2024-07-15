#include "openGLFactory.h"
#include "openGLWindow.h"
#include "openGLPrimitive.h"

openGLFactory::openGLFactory()
{
}

Window *openGLFactory::createWindow()
{
    return new openGLWindow();
}

Primitive* openGLFactory::createPrimitive() {
    return new openGLPrimitive();
}

