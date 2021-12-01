#ifndef _VTERM_INTERNAL_COMMAND_INCLUDED_H_
#define _VTERM_INTERNAL_COMMAND_INCLUDED_H_
#pragma once

#include <iostream>
#include "sequences.h"
#include "colors.h"

namespace vterm {

class Command {
public:
	Command() {}

	virtual ~Command() {}

	inline void set_cursor_visibility(const char *visibility)
	{
		std::cout << visibility;
	}

	inline void set_cursor_pos(const char pos, short n)
	{
		switch (pos){
		case 'U':
			std::cout << VTERM_CURSOR_POSITION_UP(n);
			break;
		case 'D':
			std::cout << VTERM_CURSOR_POSITION_DOWN(n);
			break;
		case 'F':
			std::cout << VTERM_CURSOR_POSITION_FWARD(n);
			break;
		case 'B':
			std::cout << VTERM_CURSOR_POSITION_BWARD(n);
			break;
		default:
			;
		}
	}

	inline void text_format(const std::string &fmt)
	{
        std::cout << VTERM_ESCAPE << "[" + fmt.substr(0, fmt.size() - 1) + "m";
	}

	inline void text_color(short r, short g, short b)
	{
        std::cout << VTERM_ESCAPE << "[38;2;" << r << ";" << g << ";" << b << "m";
	}

	inline void background_color(short r, short g, short b)
	{
        std::cout << VTERM_ESCAPE << "[48;2;" << r << ";" << g << ";" << b << "m";
	}

	inline void text_color(short number)
	{
        std::cout << VTERM_ESCAPE << "[38;5;" << number << "m";
	}

	inline void background_color(short number)
	{
        std::cout << VTERM_ESCAPE << "[48;5;" << number << "m";
	}

	inline void set_cursor_pos(short x, short y)
	{
		std::cout << VTERM_ESCAPE << "[" << y << ";" << x << "H";
	}

	inline void set_cursor_pos(int x, int y)
	{
		std::cout << VTERM_ESCAPE << "[" << y << ";" << x << "H";
	}

	inline void set_screen_buffer(const char* s_buffer)
	{
		std::cout << s_buffer;
	}

	inline void set_charset(const char* charset)
	{
		std::cout << charset;
	}

	inline void set_icon_title(const char* title)
	{
		std::cout << VTERM_ESCAPE << "]0;" << title << VTERM_BELL;
	}

	inline void set_title(const char* title)
	{
		std::cout << VTERM_ESCAPE << "]2;" << title << VTERM_BELL;
	}

};

} // namespace vterm

#endif // !_VTERM_INTERNAL_COMMAND_INCLUDED_H_
