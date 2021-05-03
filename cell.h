#ifndef CELL_H
#define CELL_H

class cell
{
private:
    bool state;  

public:
    cell();
    cell(const cell& cel);   //nie skompiluje siê poni¿ej standartu 2011 (umieœciæ w dokumentacji)
    cell& operator=(const cell& cell1);
    virtual ~cell();

    friend class engine;
};
#endif

