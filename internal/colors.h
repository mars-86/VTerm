#ifndef _VTERM_INTERNAL_COLORS_INCLUDED_H_
#define _VTERM_INTERNAL_COLORS_INCLUDED_H_
#pragma once

namespace vterm {

namespace text {

const std::string DEFAULT = "0;";               // Returns all attributes to the default state prior to modification
const std::string BOLD_BRIGHT = "1;";           // Applies brightness/intensity flag to foreground color
const std::string UNDERLINE = "4;";             // Adds underline
const std::string NEGATIVE = "7;";              // Swaps foreground and background colors
const std::string NO_BOLD_BRIGHT = "22;";       // Removes brightness/intensity flag from foreground color
const std::string NO_UNDERLINE = "24;";         // Removes underline
const std::string POSITIVE = "27;";             // Returns foreground/background to normal

const std::string FG_BLACK = "30;";             // Applies non-bold/bright black to foreground
const std::string FG_RED = "31;";               // Applies non-bold/bright red to foreground
const std::string FG_GREEN = "32;";             // Applies non-bold/bright green to foreground
const std::string FG_YELLOW = "33;";            // Applies non-bold/bright yellow to foreground
const std::string FG_BLUE = "34;"; 	            // Applies non-bold/bright blue to foreground
const std::string FG_MAGENTA = "35;"; 	        // Applies non-bold/bright magenta to foreground
const std::string FG_CYAN = "36;"; 	            // Applies non-bold/bright cyan to foreground
const std::string FG_WHITE = "37;"; 	        // Applies non-bold/bright white to foreground
const std::string FG_EXTENDED = "38;"; 	        // Applies extended color value to the foreground (see details below)
const std::string FG_DEFAULT = "39;"; 	        // Applies only the foreground portion of the defaults (see 0)

const std::string FG_BLACK_BRIGHT = "90;";      // Applies bold/bright black to foreground
const std::string FG_RED_BRIGHT = "91;";        // Applies bold/bright red to foreground
const std::string FG_GREEN_BRIGHT = "92;";      // Applies bold/bright green to foreground
const std::string FG_YELLOW_BRIGHT = "93;";     // Applies bold/bright yellow to foreground
const std::string FG_BLUE_BRIGHT = "94;";       // Applies bold/bright blue to foreground
const std::string FG_MAGENTA_BRIGHT = "95;";    // Applies bold/bright magenta to foreground
const std::string FG_CYAN_BRIGHT = "96;";       // Applies bold/bright cyan to foreground
const std::string FG_WHITE_BRIGHT = "97;";      // Applies bold/bright white to foreground

const std::string BG_BLACK = "40;"; 	        // Applies non-bold/bright black to background
const std::string BG_RED = "41;";               // Applies non-bold/bright red to background
const std::string BG_GREEN = "42;"; 	        // Applies non-bold/bright green to background
const std::string BG_YELLOW = "43;"; 	        // Applies non-bold/bright yellow to background
const std::string BG_BLUE = "44;"; 	            // Applies non-bold/bright blue to background
const std::string BG_MAGENTA = "45;";           // Applies non-bold/bright magenta to background
const std::string BG_CYAN = "46;"; 	            // Applies non-bold/bright cyan to background
const std::string BG_WHITE = "47;"; 	        // Applies non-bold/bright white to background
const std::string BG_EXTENDED = "48;"; 	        // Applies extended color value to the background (see details below)
const std::string BG_DEFAULT = "49;"; 	        // Applies only the background portion of the defaults (see 0)

const std::string BG_BLACK_BRIGHT = "100;";     // Applies bold/bright black to background
const std::string BG_RED_BRIGHT = "101;"; 	    // Applies bold/bright red to background
const std::string BG_GREEN_BRIGHT = "102;"; 	// Applies bold/bright green to background
const std::string BG_YELLOW_BRIGHT = "103;"; 	// Applies bold/bright yellow to background
const std::string BG_BLUE_BRIGHT = "104;"; 	    // Applies bold/bright blue to background
const std::string BG_MAGENTA_BRIGHT = "105;";   // Applies bold/bright magenta to background
const std::string BG_CYAN_BRIGHT = "106;"; 	    // Applies bold/bright cyan to background
const std::string BG_WHITE_BRIGHT = "107;";     // Applies bold/bright white to background

} // namespace text

} // namespace vterm

#endif // !_VTERM_INTERNAL_COLORS_INCLUDED_H_
