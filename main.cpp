#include <iostream>
#include "vterm.h"

using namespace std;
using namespace vterm;

int main()
{
    vterm::VTerm vt({ VTOPT_SCREEN_BUFFER_ALTERNATE, VTOPT_CURSOR_HIDE });
    std::cout << "HOLA";
    vt.text_color(130);
    vt.background_color(55);
    // int n = vterm::text::FG_BLUE;
    // std::string s = vterm::text::DEFAULT + ";" + vterm::text::BOLD_BRIGHT;
    // std::string s = "38;5;1;100;1;";
    // vt.text_format(s);
    vt.put(u8"\u2803", 10, 10);
    vt.text_color(7);
    vt.background_color(0);
    std::getchar();

    return 0;
}
