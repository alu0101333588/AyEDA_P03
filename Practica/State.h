#ifndef STATE_H
#define STATE_H
#include <fstream>
#include <iostream>
#include <string>

// Clase Base

class Grid;
class State {
    public:
        State() {}
        virtual void neighbors (const Grid&, int, int) = 0;
        virtual State* nextState() = 0;
        virtual char getState() const = 0;
        virtual ~State() = default; //{delete[] State_;}
                
    protected:
        char State_;
        int neighbors_;

};

#endif