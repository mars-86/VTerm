#ifndef _VTERM_INTERNAL_VTOPTS_INCLUDED_H_
#define _VTERM_INTERNAL_VTOPTS_INCLUDED_H_
#pragma once

#define VTOPT_SCREEN_BUFFER_MAIN 0x0001
#define VTOPT_SCREEN_BUFFER_ALTERNATE 0x0002

#define VTOPT_CURSOR_BLINKING 0x0010
#define VTOPT_CURSOR_NOT_BLINKING 0x0020
#define VTOPT_CURSOR_SHOW 0x0040
#define VTOPT_CURSOR_HIDE 0x0080

namespace vterm {

typedef struct _VTopt {
    int scr_buff = 0;
    int cursor_visibility = 0;
} VTopt;

} // namespace vterm


#endif // !_VTERM_INTERNAL_VTOPTS_INCLUDED_H_
