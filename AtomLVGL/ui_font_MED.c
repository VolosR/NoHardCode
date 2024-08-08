/*******************************************************************************
 * Size: 18 px
 * Bpp: 1
 * Opts: --bpp 1 --size 18 --font C:\Users\Danko\Documents\Arduino\AtomLVGL\assets\G7_Segment.ttf -o C:\Users\Danko\Documents\Arduino\AtomLVGL\assets\ui_font_MED.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_MED
#define UI_FONT_MED 1
#endif

#if UI_FONT_MED

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xbf, 0x83, 0xc0,

    /* U+0022 "\"" */
    0x96, 0xf7, 0xbd, 0x80,

    /* U+0023 "#" */
    0x4, 0x82, 0x40, 0x90, 0x24, 0x7f, 0xc4, 0x81,
    0x23, 0xfe, 0x24, 0x9, 0x4, 0x81, 0x20,

    /* U+0024 "$" */
    0x7e, 0xbd, 0xc3, 0x3, 0x3, 0x7f, 0x7e, 0x0,
    0x0, 0x0, 0x3c, 0x7e,

    /* U+0025 "%" */
    0x70, 0xa8, 0xfb, 0x76, 0xc, 0x18, 0x30, 0x6e,
    0xd5, 0x1b, 0x15, 0xe,

    /* U+0026 "&" */
    0x7e, 0xbd, 0xc3, 0x3, 0x3, 0x7f, 0x7e, 0x0,
    0x0, 0x0, 0x3c, 0x7e,

    /* U+0027 "'" */
    0xbf, 0xc0,

    /* U+0028 "(" */
    0x7e, 0xbd, 0xc3, 0x3, 0x3, 0x7f, 0x7e, 0x0,
    0x0, 0x0, 0x3c, 0x7e,

    /* U+0029 ")" */
    0x7e, 0xbd, 0xc3, 0x3, 0x3, 0x7f, 0x7e, 0x0,
    0x0, 0x0, 0x3c, 0x7e,

    /* U+002A "*" */
    0x7e, 0xbd, 0xc3, 0x3, 0x3, 0x7f, 0x7e, 0x0,
    0x0, 0x0, 0x3c, 0x7e,

    /* U+002B "+" */
    0x10, 0x20, 0x47, 0xf1, 0x2, 0x4, 0x0,

    /* U+002C "," */
    0xbf, 0x80,

    /* U+002D "-" */
    0xfb, 0xe0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x3, 0x7, 0xe, 0x1c, 0x38, 0x70, 0xe0, 0xc0,

    /* U+0030 "0" */
    0x7e, 0xbd, 0xc3, 0xc3, 0xc3, 0x81, 0x81, 0xc3,
    0xc3, 0xc3, 0xbd, 0x7e,

    /* U+0031 "1" */
    0xed, 0x33, 0x31, 0x3, 0x33, 0x31,

    /* U+0032 "2" */
    0x7e, 0xbd, 0xc3, 0x3, 0x3, 0x7f, 0x7e, 0xc0,
    0xc0, 0xc0, 0xbc, 0x7e,

    /* U+0033 "3" */
    0x7e, 0xbd, 0xc3, 0x3, 0x3, 0x7f, 0x7e, 0x3,
    0x3, 0xc3, 0xbd, 0x7e,

    /* U+0034 "4" */
    0x81, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0x7e, 0x3,
    0x3, 0x3, 0x3, 0x1,

    /* U+0035 "5" */
    0x7e, 0xbc, 0xc0, 0xc0, 0xc0, 0xfe, 0x7e, 0x3,
    0x3, 0xc3, 0xbd, 0x7e,

    /* U+0036 "6" */
    0x7e, 0xbd, 0xc3, 0xc0, 0xc0, 0xfe, 0x7e, 0xc3,
    0xc3, 0xc3, 0xbd, 0x7e,

    /* U+0037 "7" */
    0x7e, 0xbd, 0xc3, 0x3, 0x3, 0x1, 0x0, 0x3,
    0x3, 0x3, 0x3, 0x1,

    /* U+0038 "8" */
    0x7e, 0xbd, 0xc3, 0xc3, 0xc3, 0xff, 0x7e, 0xc3,
    0xc3, 0xc3, 0xbd, 0x7e,

    /* U+0039 "9" */
    0x7e, 0xbd, 0xc3, 0xc3, 0xc3, 0xff, 0x7e, 0x3,
    0x3, 0xc3, 0xbd, 0x7e,

    /* U+003A ":" */
    0xf0, 0x3c,

    /* U+003B ";" */
    0xf0, 0x3f, 0xc0,

    /* U+003C "<" */
    0x19, 0xdd, 0xc7, 0x1c, 0x60,

    /* U+003D "=" */
    0xfe, 0xfe, 0x0, 0xfe, 0xfe,

    /* U+003E ">" */
    0xc7, 0x1c, 0x77, 0x73, 0x0,

    /* U+003F "?" */
    0x7e, 0xbd, 0xc3, 0x3, 0x3, 0x7f, 0x7e, 0x0,
    0x0, 0x0, 0x3c, 0x7e,

    /* U+0040 "@" */
    0x7, 0xe0, 0x1c, 0x18, 0x30, 0xc, 0x67, 0x86,
    0x64, 0x43, 0xc0, 0x43, 0xc1, 0xc3, 0xc6, 0x43,
    0xc4, 0x43, 0xc4, 0x46, 0xc6, 0x4c, 0x63, 0xb8,
    0x60, 0x0, 0x30, 0x0, 0x1c, 0x18, 0x7, 0xe0,

    /* U+0041 "A" */
    0x7e, 0xbd, 0xc3, 0xc3, 0xc3, 0xff, 0x7e, 0xc3,
    0xc3, 0xc3, 0xc3, 0x81,

    /* U+0042 "B" */
    0x7e, 0xbd, 0xc3, 0xc3, 0xc3, 0xff, 0x7e, 0xc3,
    0xc3, 0xc3, 0xbd, 0x7e,

    /* U+0043 "C" */
    0x7f, 0x7b, 0x6, 0xc, 0x10, 0x20, 0x60, 0xc1,
    0x82, 0xf3, 0xf0,

    /* U+0044 "D" */
    0x7e, 0xbd, 0xc3, 0xc3, 0xc3, 0x81, 0x81, 0xc3,
    0xc3, 0xc3, 0xbd, 0x7e,

    /* U+0045 "E" */
    0x7f, 0x7b, 0x6, 0xc, 0x1f, 0xdf, 0xe0, 0xc1,
    0x82, 0xf3, 0xf0,

    /* U+0046 "F" */
    0x7f, 0x7b, 0x6, 0xc, 0x1f, 0xdf, 0xe0, 0xc1,
    0x83, 0x4, 0x0,

    /* U+0047 "G" */
    0x7e, 0xbc, 0xc0, 0xc0, 0xc0, 0x80, 0x81, 0xc3,
    0xc3, 0xc3, 0xbd, 0x7e,

    /* U+0048 "H" */
    0x81, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0x7e, 0xc3,
    0xc3, 0xc3, 0xc3, 0x81,

    /* U+0049 "I" */
    0x7f, 0xc7, 0xf4,

    /* U+004A "J" */
    0x1, 0x3, 0x3, 0x3, 0x3, 0x0, 0x81, 0xc3,
    0xc3, 0xc3, 0xbd, 0x7e,

    /* U+004B "K" */
    0x81, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0x7e, 0xc0,
    0xc0, 0xc0, 0xbc, 0x7e,

    /* U+004C "L" */
    0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0x0, 0x81, 0xc3,
    0xc3, 0xc3, 0xbd, 0x7e,

    /* U+004D "M" */
    0x7e, 0x3c, 0x0, 0x0, 0x0, 0x7e, 0x7e, 0xc3,
    0xc3, 0xc3, 0xc3, 0x81,

    /* U+004E "N" */
    0x7e, 0xbd, 0xc3, 0xc3, 0xc3, 0x81, 0x0, 0xc3,
    0xc3, 0xc3, 0xc3, 0x81,

    /* U+004F "O" */
    0x7e, 0xbd, 0xc3, 0xc3, 0xc3, 0x81, 0x81, 0xc3,
    0xc3, 0xc3, 0xbd, 0x7e,

    /* U+0050 "P" */
    0x7e, 0xbd, 0xc3, 0xc3, 0xc3, 0xff, 0x7e, 0xc0,
    0xc0, 0xc0, 0xc0, 0x80,

    /* U+0051 "Q" */
    0x7e, 0xbd, 0xc3, 0xc3, 0xc3, 0xff, 0x7e, 0x0,
    0x0, 0x0, 0x3c, 0x7e,

    /* U+0052 "R" */
    0x7f, 0x7b, 0x6, 0xc, 0x10, 0x0, 0x60, 0xc1,
    0x83, 0x4, 0x0,

    /* U+0053 "S" */
    0x7e, 0xbc, 0xc0, 0xc0, 0xc0, 0xfe, 0x7e, 0x3,
    0x3, 0x3, 0x3d, 0x7e,

    /* U+0054 "T" */
    0xfc, 0xf4, 0x18, 0x30, 0x60, 0x40, 0x3, 0x6,
    0xc, 0x18, 0x10,

    /* U+0055 "U" */
    0x81, 0xc3, 0xc3, 0xc3, 0xc3, 0x0, 0x81, 0xc3,
    0xc3, 0xc3, 0xbd, 0x7e,

    /* U+0056 "V" */
    0x81, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0x7e, 0x0,
    0x0, 0x0, 0x3c, 0x7e,

    /* U+0057 "W" */
    0x81, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0x7e, 0xc3,
    0xc3, 0xc3, 0xbd, 0x7e,

    /* U+0058 "X" */
    0xfd, 0xe0, 0x0, 0x3, 0xef, 0x80, 0x0, 0x7,
    0xbf,

    /* U+0059 "Y" */
    0x81, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0x7e, 0x3,
    0x3, 0x3, 0x3d, 0x7e,

    /* U+005A "Z" */
    0x7e, 0x3d, 0x3, 0x3, 0x3, 0x7f, 0x7e, 0xc0,
    0xc0, 0xc0, 0xbc, 0x7e,

    /* U+005B "[" */
    0x7e, 0xbd, 0xc3, 0x3, 0x3, 0x7f, 0x7e, 0x0,
    0x0, 0x0, 0x3c, 0x7e,

    /* U+005C "\\" */
    0x7e, 0xbd, 0xc3, 0x3, 0x3, 0x7f, 0x7e, 0x0,
    0x0, 0x0, 0x3c, 0x7e,

    /* U+005D "]" */
    0x7e, 0xbd, 0xc3, 0x3, 0x3, 0x7f, 0x7e, 0x0,
    0x0, 0x0, 0x3c, 0x7e,

    /* U+005E "^" */
    0x7e, 0xbd, 0xc3, 0x3, 0x3, 0x7f, 0x7e, 0x0,
    0x0, 0x0, 0x3c, 0x7e,

    /* U+005F "_" */
    0x7b, 0xf0,

    /* U+0060 "`" */
    0xbf, 0xc0,

    /* U+0061 "a" */
    0x7e, 0x3d, 0x3, 0x3, 0x3, 0x7f, 0x7e, 0xc3,
    0xc3, 0xc3, 0xbd, 0x7e,

    /* U+0062 "b" */
    0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0x7e, 0xc3,
    0xc3, 0xc3, 0xbd, 0x7e,

    /* U+0063 "c" */
    0x7e, 0xff, 0x6, 0xc, 0x17, 0x9f, 0x80,

    /* U+0064 "d" */
    0x1, 0x3, 0x3, 0x3, 0x3, 0x7f, 0x7e, 0xc3,
    0xc3, 0xc3, 0xbd, 0x7e,

    /* U+0065 "e" */
    0x7e, 0xbd, 0xc3, 0xc3, 0xc3, 0xff, 0x7e, 0xc0,
    0xc0, 0xc0, 0xbc, 0x7e,

    /* U+0066 "f" */
    0x7f, 0x7b, 0x6, 0xc, 0x1f, 0xdf, 0xe0, 0xc1,
    0x82, 0xf3, 0xf0,

    /* U+0067 "g" */
    0x7e, 0xbd, 0xc3, 0xc3, 0xc3, 0xff, 0x7e, 0x3,
    0x3, 0x3, 0x3d, 0x7e,

    /* U+0068 "h" */
    0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0x7e, 0xc3,
    0xc3, 0xc3, 0xc3, 0x81,

    /* U+0069 "i" */
    0x7f, 0x40,

    /* U+006A "j" */
    0x2, 0xc, 0x18, 0x30, 0x60, 0x0, 0x83, 0x6,
    0xd, 0xef, 0xe0,

    /* U+006B "k" */
    0x7e, 0xbc, 0xc0, 0xc0, 0xc0, 0xfe, 0x7e, 0xc3,
    0xc3, 0xc3, 0xc3, 0x81,

    /* U+006C "l" */
    0x81, 0x83, 0x6, 0xc, 0x0, 0x20, 0x60, 0xc1,
    0x82, 0xf3, 0xf0,

    /* U+006D "m" */
    0x7e, 0x3c, 0x0, 0x0, 0x0, 0x7e, 0x7e, 0xc3,
    0xc3, 0xc3, 0xc3, 0x81,

    /* U+006E "n" */
    0x7e, 0x7e, 0xc3, 0xc3, 0xc3, 0xc3, 0x81,

    /* U+006F "o" */
    0x7e, 0x7e, 0xc3, 0xc3, 0xc3, 0xbd, 0x7e,

    /* U+0070 "p" */
    0x7e, 0xbd, 0xc3, 0xc3, 0xc3, 0xff, 0x7e, 0xc0,
    0xc0, 0xc0, 0xc0, 0x80,

    /* U+0071 "q" */
    0x7e, 0xbd, 0xc3, 0xc3, 0xc3, 0xff, 0x7e, 0x3,
    0x3, 0x3, 0x3, 0x1,

    /* U+0072 "r" */
    0x7e, 0xff, 0x6, 0xc, 0x18, 0x20, 0x0,

    /* U+0073 "s" */
    0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0x7e, 0x3,
    0x3, 0x3, 0x3, 0x1,

    /* U+0074 "t" */
    0x81, 0x83, 0x6, 0xc, 0x1f, 0xdf, 0xe0, 0xc1,
    0x82, 0xf3, 0xf0,

    /* U+0075 "u" */
    0x81, 0xc3, 0xc3, 0xc3, 0xbd, 0x7e,

    /* U+0076 "v" */
    0x81, 0xc3, 0xc3, 0xc3, 0xc3, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3c, 0x7e,

    /* U+0077 "w" */
    0x81, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0x7e, 0xc3,
    0xc3, 0xc3, 0xbd, 0x7e,

    /* U+0078 "x" */
    0xfd, 0xe0, 0x0, 0x3, 0xef, 0x80, 0x0, 0x7,
    0xbf,

    /* U+0079 "y" */
    0x81, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0x7e, 0x3,
    0x3, 0x3, 0x3d, 0x7e,

    /* U+007A "z" */
    0x7e, 0x3d, 0x3, 0x3, 0x3, 0x7f, 0x7e, 0xc0,
    0xc0, 0xc0, 0xbc, 0x7e,

    /* U+007B "{" */
    0x7e, 0xbd, 0xc3, 0x3, 0x3, 0x7f, 0x7e, 0x0,
    0x0, 0x0, 0x3c, 0x7e,

    /* U+007C "|" */
    0x7e, 0xbd, 0xc3, 0x3, 0x3, 0x7f, 0x7e, 0x0,
    0x0, 0x0, 0x3c, 0x7e,

    /* U+007D "}" */
    0x7e, 0xbd, 0xc3, 0x3, 0x3, 0x7f, 0x7e, 0x0,
    0x0, 0x0, 0x3c, 0x7e,

    /* U+007E "~" */
    0x7e, 0xbd, 0xc3, 0x3, 0x3, 0x7f, 0x7e, 0x0,
    0x0, 0x0, 0x3c, 0x7e
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 71, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 58, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 98, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 8, .adv_w = 188, .box_w = 10, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 23, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 35, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 47, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 59, .adv_w = 57, .box_w = 2, .box_h = 5, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 61, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 73, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 85, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 97, .adv_w = 143, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 104, .adv_w = 50, .box_w = 2, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 106, .adv_w = 141, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 108, .adv_w = 58, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 109, .adv_w = 155, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 117, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 129, .adv_w = 155, .box_w = 4, .box_h = 12, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 135, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 147, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 159, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 171, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 183, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 195, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 207, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 219, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 231, .adv_w = 58, .box_w = 2, .box_h = 7, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 233, .adv_w = 58, .box_w = 2, .box_h = 9, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 236, .adv_w = 155, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 241, .adv_w = 155, .box_w = 8, .box_h = 5, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 246, .adv_w = 155, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 251, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 263, .adv_w = 284, .box_w = 16, .box_h = 16, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 295, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 307, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 319, .adv_w = 155, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 330, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 342, .adv_w = 155, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 353, .adv_w = 155, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 364, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 376, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 388, .adv_w = 155, .box_w = 2, .box_h = 11, .ofs_x = 6, .ofs_y = 1},
    {.bitmap_index = 391, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 403, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 415, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 427, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 439, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 451, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 463, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 475, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 487, .adv_w = 155, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 498, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 510, .adv_w = 155, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 521, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 533, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 545, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 557, .adv_w = 155, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 566, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 578, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 590, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 602, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 614, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 626, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 638, .adv_w = 155, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 640, .adv_w = 57, .box_w = 2, .box_h = 5, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 642, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 654, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 666, .adv_w = 155, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 673, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 685, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 697, .adv_w = 155, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 708, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 720, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 732, .adv_w = 155, .box_w = 2, .box_h = 5, .ofs_x = 6, .ofs_y = 1},
    {.bitmap_index = 734, .adv_w = 155, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 745, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 757, .adv_w = 155, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 768, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 780, .adv_w = 155, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 787, .adv_w = 155, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 794, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 806, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 818, .adv_w = 155, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 825, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 837, .adv_w = 155, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 848, .adv_w = 155, .box_w = 8, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 854, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 866, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 878, .adv_w = 155, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 887, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 899, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 911, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 923, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 935, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 947, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t ui_font_MED = {
#else
lv_font_t ui_font_MED = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 16,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_MED*/

