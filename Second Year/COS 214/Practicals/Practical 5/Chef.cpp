#include "Chef.h"

Chef::Chef() {
}

Order* Chef::getOrder() {
    return this->curOrder;
}

void Chef::setOrder(Order* o) {
    this->curOrder = o;
}
