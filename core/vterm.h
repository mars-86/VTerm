#ifndef _VTERM_CORE_VTERM_INCLUDED_H_
#define _VTERM_CORE_VTERM_INCLUDED_H_
#pragma once

#include <cmath>
#include <vector>
#include "../internal/command.h"
#include "../internal/vtopts.h"
#include "../os/os.h"

#ifdef _WIN32
#define _STDOUT_HANDLE STD_OUTPUT_HANDLE
#else
#define _STDOUT_HANDLE 1
#endif // _WIN32

namespace vterm {

class VTerm : public Command {
public:
	VTerm();
    VTerm(VTopt opts);
	virtual ~VTerm();
	virtual void put(const char *s, int x, int y);
	virtual void put(const char *s, int x, int y, int z);
	virtual void set_buffer(int x, int y);
	virtual void unset_buffer(int x, int y);
	const std::vector<int>& get_screen_buffer(void) const;
	unsigned int get_width(void) const;
	unsigned int get_height(void) const;

protected:
	typedef struct _Symbol {
		char* val;
		int x;
		int y;
	} dwchar_t;

    std::vector<int> _buffer;
private:
#ifdef _WIN32
    HANDLE _stdh;
#else
    void *_stdh;
#endif // _WIN32
    os::ContainerSize _cs;
    VTopt _options;

    const int _OPT_SCREEN_BUFFER_MASK = 0x0003;
    const int _OPT_CURSOR_BLI_MASK = 0x0030;
    const int _OPT_CURSOR_VIS_MASK = 0x00C0;

    void _init_buffer(void);
    void _set_options(VTopt opts);
    friend std::ostream& operator<<(std::ostream& out, const dwchar_t& symbol)
	{
		// std::flush for cursor fluency
		return out << VTERM_ESCAPE << "[" << symbol.y << ";" << symbol.x << "H" << symbol.val << std::flush;
	}

};

} // namespace vterm

#endif // !_VTERM_CORE_VTERM_INCLUDED_H_
