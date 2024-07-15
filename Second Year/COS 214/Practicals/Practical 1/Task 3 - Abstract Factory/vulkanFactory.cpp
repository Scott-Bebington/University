#include "vulkanFactory.h"
#include "vulkanWindow.h"
#include "vulkanPrimitive.h"

Window* vulkanFactory::createWindow() {
    return new vulkanWindow();
}

Primitive* vulkanFactory::createPrimitive() {
    return new vulkanPrimitive();
}

