#ifndef SHIP_H
#define SHIP_H

#include <string>

class Ship {
private:
    std::string name;
    int size;
    char symbol;

public:
    Ship();
    Ship(std::string shipName, int shipSize, char shipSymbol);

    std::string getName() const;
    int getSize() const;
    char getSymbol() const;
};

#endif
