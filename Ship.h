#include "Ship.h"

Ship::Ship() {
    name = "";
    size = 0;
    symbol = ' ';
}

Ship::Ship(std::string shipName, int shipSize, char shipSymbol) {
    name = shipName;
    size = shipSize;
    symbol = shipSymbol;
}

std::string Ship::getName() const {
    return name;
}

int Ship::getSize() const {
    return size;
}

char Ship::getSymbol() const {
    return symbol;
}
