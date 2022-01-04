#ifndef _COLOR_H_
#define _COLOR_H_

// Only Effective for Linux / Unix

/** Reset all the Attributes */
extern const char* RESET;

/** Set Font Color
 * Format: "\033[BackColor;FrontColormString\033[0m"
*/
extern const char* FRONT_BLACK;
extern const char* FRONT_RED;
extern const char* FRONT_GREEN;
extern const char* FRONT_YELLOW;
extern const char* FRONT_BLUE;
extern const char* FRONT_PURPLR;
extern const char* FRONT_DARKGREEN;
extern const char* FRONT_WHITE;

extern const char* BACK_BLACK;
extern const char* BACK_RED;
extern const char* BACK_GREEN;
extern const char* BACK_YELLOW;
extern const char* BACK_BLUE;
extern const char* BACK_PURPLR;
extern const char* BACK_DARKGREEN;
extern const char* BACK_WHITE;

/** Set Font Effect */
extern const char* BOLD;
extern const char* UNDERLINE;
extern const char* TWINKLING;
extern const char* REVERSE;
extern const char* HIDE;

#endif
