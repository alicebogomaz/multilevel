#include <cstddef>

#include "menu_items.hpp"
#include "menu_functions.hpp"


const ABogomaz::MenuItem ABogomaz::MATH_DIFF = {
    "1 - ...дифференциальных исчислений!", ABogomaz::math_diff, &ABogomaz::MATH
};
const ABogomaz::MenuItem ABogomaz::MATH_INTEG = {
    "2 - ...интегральных исчислений!", ABogomaz::math_integ, &ABogomaz::MATH
};
const ABogomaz::MenuItem ABogomaz::MATH_GO_BACK = {
    "0 - ...а когда перерыв? (вернуться к предметам) ", ABogomaz::go_back,  &ABogomaz::MATH
};

namespace {
    const ABogomaz::MenuItem* const math_children[] = {
        &ABogomaz::MATH_GO_BACK,
        &ABogomaz::MATH_DIFF,
        &ABogomaz::MATH_INTEG
    };
    const int math_size = sizeof(math_children) / sizeof(math_children[0]);
    const char* math_greeting = "Бочкарёв Анатолий Олегович: Здравствуйте. Я буду вести у Вас курс математического анализа. Сегодня мы затронем тему..." + '\0';
}

const ABogomaz::MenuItem ABogomaz::ALGEBRA_SUMM = {
    "1 - ...сложение!", ABogomaz::algebra_summ, &ABogomaz::ALGEBRA
};
const ABogomaz::MenuItem ABogomaz::ALGEBRA_SUBTRACT = {
    "2 - ...вычитание!", ABogomaz::algebra_subtract, &ABogomaz::ALGEBRA
};
const ABogomaz::MenuItem ABogomaz::ALGEBRA_MULTIPLY = {
    "3 - ...умножение!", ABogomaz::algebra_multiply, &ABogomaz::ALGEBRA
};
const ABogomaz::MenuItem ABogomaz::ALGEBRA_DIVIDE = {
    "4 - ...деление!", ABogomaz::algebra_divide, &ABogomaz::ALGEBRA
};
const ABogomaz::MenuItem ABogomaz::ALGEBRA_GO_BACK = {
    "0 - ...а когда перерыв? (вернуться к предметам)", ABogomaz::go_back,  &ABogomaz::ALGEBRA
};

namespace {
    const ABogomaz::MenuItem* const algebra_children[] = {
        &ABogomaz::ALGEBRA_GO_BACK,
        &ABogomaz::ALGEBRA_SUMM,
        &ABogomaz::ALGEBRA_SUBTRACT,
        &ABogomaz::ALGEBRA_MULTIPLY,
        &ABogomaz::ALGEBRA_DIVIDE
    };
    const int algebra_size = sizeof(algebra_children) / sizeof(algebra_children[0]);
    const char* algebra_greeting = "Утешев Алексей Юрьевич: Здравствуйте. Я буду вести у Вас курс алгебры. Запишем сегодняшнюю тему..."+ '\0';
}

const ABogomaz::MenuItem ABogomaz::STUDY_GO_BACK = {
    "0 - хочу обратно в меню! ", ABogomaz::go_back,  &ABogomaz::STUDY
};
const ABogomaz::MenuItem ABogomaz::ALGEBRA = {
    "1 - хочу изучать алгебру!", ABogomaz::show_menu, &ABogomaz::STUDY, algebra_greeting, algebra_children, algebra_size
};
const ABogomaz::MenuItem ABogomaz::MATH = {
    "2 - хочу изучать математеческий анализ! ", ABogomaz::show_menu,  &ABogomaz::STUDY, math_greeting, math_children, math_size

};

namespace {
    const ABogomaz::MenuItem* const study_children[] = {
        &ABogomaz::STUDY_GO_BACK,
        &ABogomaz::ALGEBRA,
        &ABogomaz::MATH
    };
    const int study_size = sizeof(study_children) / sizeof(study_children[0]);
    const char* study_greeting = "что будем изучать сегодня?" + '\0';
}

const ABogomaz::MenuItem ABogomaz::STUDY = {
    "1 - вперед за знаниями!", ABogomaz::show_menu, &ABogomaz::MAIN, study_greeting, study_children, study_size
};
const ABogomaz::MenuItem ABogomaz::EXIT = {
    "0 - майнкрафт ждет меня...", ABogomaz::exit, &ABogomaz::MAIN
};


namespace {
    const ABogomaz::MenuItem* const main_children[] = {
      &ABogomaz::EXIT,
      &ABogomaz::STUDY
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
    const char* main_greeting = "привет-привет! саморазвитие is the real punk rock! :)" + '\0';
}

const ABogomaz::MenuItem ABogomaz::MAIN = {
    nullptr, ABogomaz::show_menu, nullptr, main_greeting, main_children, main_size
};