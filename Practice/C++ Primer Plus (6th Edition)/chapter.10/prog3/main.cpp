#include <iostream>
#include "golf.h"
int main()
{
    Golf tb("Tyler Brock", 18);
    Golf mo;

    tb.showgolf();
    mo.showgolf();

    tb.set_handicap(3);
    mo.set_handicap(6);

    tb.showgolf();
    mo.showgolf();
    return 0;
}