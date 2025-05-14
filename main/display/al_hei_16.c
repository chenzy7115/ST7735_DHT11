/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --no-compress --font 阿里汉仪智能黑体.ttf --symbols 温度湿度:%°C: 0123456789 --format lvgl -o al_hei_16.c
 ******************************************************************************/


#include "lvgl.h"


#ifndef AL_HEI_16
#define AL_HEI_16 1
#endif

#if AL_HEI_16

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0025 "%" */
    0xfc, 0x23, 0xf1, 0x8f, 0xc4, 0x3f, 0x30, 0xfc,
    0x83, 0xf6, 0xf, 0xf0, 0x0, 0xff, 0x6, 0xfc,
    0x1b, 0xf0, 0xcf, 0xc2, 0x3f, 0x18, 0xfc, 0x43,
    0xf0,

    /* U+0030 "0" */
    0xff, 0xf8, 0x7e, 0x1f, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0x87, 0xe1, 0xf8, 0x7e, 0x1f, 0x87, 0xe1,
    0xff, 0xf0,

    /* U+0031 "1" */
    0xf7, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77,

    /* U+0032 "2" */
    0xff, 0x81, 0xc0, 0xe0, 0x70, 0x38, 0x1f, 0xff,
    0xc0, 0xe0, 0x70, 0x38, 0x1c, 0xe, 0x7, 0xfc,

    /* U+0033 "3" */
    0xff, 0x81, 0xc0, 0xe0, 0x70, 0x38, 0x1d, 0xfe,
    0x7, 0x3, 0x81, 0xc0, 0xe0, 0x70, 0x3f, 0xfc,

    /* U+0034 "4" */
    0xe1, 0xf8, 0x7e, 0x1f, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0x87, 0xe7, 0xfe, 0x70, 0x1c, 0x7, 0x1,
    0xc0, 0x70,

    /* U+0035 "5" */
    0xff, 0xf0, 0x38, 0x1c, 0xe, 0x7, 0x3, 0xfe,
    0x7, 0x3, 0x81, 0xc0, 0xe0, 0x70, 0x3f, 0xfc,

    /* U+0036 "6" */
    0xff, 0xf8, 0xe, 0x3, 0x80, 0xe0, 0x38, 0xff,
    0xff, 0x87, 0xe1, 0xf8, 0x7e, 0x1f, 0x87, 0xe1,
    0xff, 0xf0,

    /* U+0037 "7" */
    0xff, 0xc0, 0x70, 0x38, 0xe, 0x7, 0x81, 0xc0,
    0x70, 0x3c, 0xe, 0x3, 0x81, 0xc0, 0x70, 0x3c,
    0xe, 0x0,

    /* U+0038 "8" */
    0xff, 0xf8, 0x7e, 0x1f, 0x87, 0xe1, 0xf8, 0x7f,
    0xff, 0x87, 0xe1, 0xf8, 0x7e, 0x1f, 0x87, 0xe1,
    0xff, 0xf0,

    /* U+0039 "9" */
    0xff, 0xf8, 0x7e, 0x1f, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0xff, 0x1, 0xc0, 0x70, 0x1c, 0x7, 0x1,
    0xff, 0xf0,

    /* U+003A ":" */
    0xff, 0x80, 0x7, 0xfc,

    /* U+0043 "C" */
    0xff, 0xdc, 0x3, 0x80, 0x70, 0xe, 0x1, 0xc0,
    0x38, 0x7, 0x0, 0xe0, 0x1c, 0x3, 0x80, 0x70,
    0xe, 0x7f, 0xf8, 0x0,

    /* U+00B0 "°" */
    0xfb, 0xbf,

    /* U+5EA6 "度" */
    0x7f, 0xfe, 0xe0, 0x1, 0xdc, 0xe3, 0xb9, 0xc7,
    0xff, 0xee, 0xe7, 0x1d, 0xce, 0x38, 0x60, 0x7f,
    0xfc, 0xe0, 0x79, 0xdc, 0xe3, 0x9f, 0x87, 0x1e,
    0x1e, 0x7e, 0x3d, 0xde, 0x0,

    /* U+6E29 "温" */
    0xe7, 0xfc, 0xee, 0x39, 0xdc, 0x70, 0x3f, 0xe6,
    0x71, 0xce, 0xe3, 0x9d, 0xff, 0x38, 0x0, 0x7,
    0xfc, 0xed, 0x59, 0xda, 0xb3, 0xb5, 0x67, 0x6a,
    0xcc, 0xd5, 0xbb, 0xff, 0x80,

    /* U+6E7F "湿" */
    0xe7, 0xfc, 0xee, 0x39, 0xdc, 0x70, 0x3f, 0xee,
    0x71, 0xcc, 0xe3, 0x9d, 0xff, 0x38, 0xd8, 0x5,
    0xb4, 0xeb, 0x69, 0xd6, 0xd3, 0xad, 0xa7, 0x5b,
    0x5c, 0x36, 0x3b, 0xff, 0x80
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 102, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 260, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 26, .adv_w = 197, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 44, .adv_w = 99, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 51, .adv_w = 179, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 67, .adv_w = 183, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 83, .adv_w = 192, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 101, .adv_w = 180, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 117, .adv_w = 199, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 135, .adv_w = 164, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 153, .adv_w = 196, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 171, .adv_w = 204, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 189, .adv_w = 87, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 193, .adv_w = 190, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 213, .adv_w = 89, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 215, .adv_w = 256, .box_w = 15, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 244, .adv_w = 256, .box_w = 15, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 273, .adv_w = 256, .box_w = 15, .box_h = 15, .ofs_x = 0, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x5, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15,
    0x16, 0x17, 0x18, 0x19, 0x1a, 0x23, 0x90, 0x5e86,
    0x6e09, 0x6e5f
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 28256, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 18, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
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
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t al_hei_16 = {
#else
lv_font_t al_hei_16 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 15,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if AL_HEI_16*/

