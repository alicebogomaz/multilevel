#pragma once

#include "menu.hpp"

namespace ABogomaz {
    
    const MenuItem* show_menu(const MenuItem* current);
    const MenuItem* exit(const MenuItem* current);
    const MenuItem* go_back(const MenuItem* current); 

    const MenuItem* math_diff(const MenuItem* current);
    const MenuItem* math_integ(const MenuItem* current);

    const MenuItem* algebra_summ(const MenuItem* current);
    const MenuItem* algebra_subtract(const MenuItem* current);
    const MenuItem* algebra_multiply(const MenuItem* current);
    const MenuItem* algebra_divide(const MenuItem* current);
}
