#include "vterm.h"

namespace vterm {

VTerm::VTerm()
{
    _init_buffer();
}

VTerm::VTerm(VTopt opts) :
    _options(opts)
{
    _init_buffer();
    _set_options(_options);
}

VTerm::~VTerm()
{
    _set_options({
        VTOPT_SCREEN_BUFFER_MAIN,
        VTOPT_CURSOR_BLINKING | VTOPT_CURSOR_SHOW
    });
}

void VTerm::put(const char *s, int x, int y)
{
	dwchar_t dwc = { (char *)s, x, y };
	std::cout << dwc;
}

void VTerm::put(const char *s, int x, int y, int z)
{
	dwchar_t dwc = { (char *)s, x, y };
	std::cout << dwc;
}

void VTerm::set_buffer(int x, int y)
{
    if (x > _cs.cs_col) x = 1;
	if (y > _cs.cs_row) y = 1;
    _buffer[_cs.cs_col * (y - 1) + (x - 1)] = 1;
}

void VTerm::unset_buffer(int x, int y)
{
    if (x > _cs.cs_col) x = 1;
	if (y > _cs.cs_row) y = 1;
    _buffer[_cs.cs_col * (y - 1) + (x - 1)] = 0;
}

const std::vector<int>& VTerm::get_screen_buffer(void) const
{
    return _buffer;
}

unsigned int VTerm::get_width(void) const
{
    return _cs.cs_col;
}

unsigned int VTerm::get_height(void) const
{
    return _cs.cs_row;
}

void VTerm::_init_buffer(void)
{
    _stdh = os::get_std_handle(_STDOUT_HANDLE);
	os::get_container_size(_stdh, &_cs);
	_buffer.resize(_cs.cs_col * _cs.cs_row, 0);
}

void VTerm::_set_options(VTopt opts)
{
    if ((_options.scr_buff & _OPT_SCREEN_BUFFER_MASK) == VTOPT_SCREEN_BUFFER_MAIN)
        set_screen_buffer(VTERM_MAIN_SCREEN_BUFFER);
    if ((_options.scr_buff & _OPT_SCREEN_BUFFER_MASK) == VTOPT_SCREEN_BUFFER_ALTERNATE)
        set_screen_buffer(VTERM_ALTERNATE_SCREEN_BUFFER);
    if ((_options.cursor_visibility & _OPT_CURSOR_BLI_MASK) == VTOPT_CURSOR_BLINKING)
        set_cursor_visibility(VTERM_CURSOR_BLINKING);
    if ((_options.cursor_visibility & _OPT_CURSOR_BLI_MASK) == VTOPT_CURSOR_NOT_BLINKING)
        set_cursor_visibility(VTERM_CURSOR_NOT_BLINKING);
    if ((_options.cursor_visibility & _OPT_CURSOR_VIS_MASK) == VTOPT_CURSOR_SHOW)
        set_cursor_visibility(VTERM_CURSOR_SHOW);
    if ((_options.cursor_visibility & _OPT_CURSOR_VIS_MASK) == VTOPT_CURSOR_HIDE)
        set_cursor_visibility(VTERM_CURSOR_HIDE);
}

} // namespace vterm
