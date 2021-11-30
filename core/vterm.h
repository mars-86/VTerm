#ifndef _VTERM_CORE_VTERM_INCLUDED_H_
#define _VTERM_CORE_VTERM_INCLUDED_H_
#pragma once

#include <cmath>
#include <vector>
#include "../internal/command.h"
#include "../os/os.h"

#ifdef _WIN32
#define _STDOUT_HANDLE STD_OUTPUT_HANDLE
#else
#define _STDOUT_HANDLE 1
#endif // _WIN32

namespace vterm {

typedef struct _VTopt {
    std::string screen_buff;
    std::string cursor_visibility;
    std::string mode;
} VTopt;

class VTerm : public Command {
public:
	VTerm();
    VTerm(VTopt options);
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
    std::vector<int> _points_buffer;
#ifdef _WIN32
    HANDLE _stdh;
#else
    void *_stdh;
#endif // _WIN32
    os::ContainerSize _cs;
    VTopt _options;
    void _init_buffer(void);
    friend std::ostream& operator<<(std::ostream& out, const dwchar_t& symbol)
	{
		// std::flush for cursor fluency
		return out << VTERM_ESCAPE << "[" << symbol.y << ";" << symbol.x << "H" << symbol.val << std::flush;
	}

};

} // namespace vterm

#endif // !_VTERM_CORE_VTERM_INCLUDED_H_
