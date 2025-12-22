#pragma once

namespace ABogomaz {
    struct MenuItem {
        const char* const title;

        const MenuItem* (*func)(const MenuItem* current);

        const MenuItem* parent;

        const char* const greeting;

        const MenuItem* const *children;
        const int children_count;
    };
}
