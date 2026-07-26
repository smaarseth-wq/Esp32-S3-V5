#pragma once

#include <stdint.h>

/*----------------------------------------------------------
 * ST77916 Commands
 *---------------------------------------------------------*/

#define CMD_NOP             0x00
#define CMD_SWRESET         0x01

#define CMD_SLPIN           0x10
#define CMD_SLPOUT          0x11

#define CMD_INVOFF          0x20
#define CMD_INVON           0x21

#define CMD_DISPOFF         0x28
#define CMD_DISPON          0x29

#define CMD_CASET           0x2A
#define CMD_RASET           0x2B
#define CMD_RAMWR           0x2C
#define CMD_RAMRD           0x2E

#define CMD_MADCTL          0x36
#define CMD_COLMOD          0x3A

#define CMD_RDDID           0x04

#define CMD_IDMOFF          0x38
#define CMD_IDMON           0x39

#define CMD_RDMEMC          0x3C
/*----------------------------------------------------------
 * MADCTL Bits
 *---------------------------------------------------------*/

#define MAD_MY              0x80
#define MAD_MX              0x40
#define MAD_MV              0x20
#define MAD_ML              0x10
#define MAD_BGR             0x08
#define MAD_MH              0x04
/*----------------------------------------------------------
 * Pixel Formats
 *---------------------------------------------------------*/

#define RGB565_2BYTE        0x55
#define RGB666_3BYTE        0x66
/*----------------------------------------------------------
 * QSPI Opcodes
 *---------------------------------------------------------*/

#define LCD_OPCODE_WRITE_CMD    0x02
#define LCD_OPCODE_WRITE_COLOR  0x32
#define LCD_OPCODE_READ_CMD     0x0B
/*----------------------------------------------------------
 * LCD Init Command Structure
 *---------------------------------------------------------*/

typedef struct
{
    uint8_t cmd;
    const uint8_t *data;
    uint8_t data_bytes;
    uint16_t delay_ms;
} lcd_init_cmd_t;
/*----------------------------------------------------------
 * ST77916 Initialization Table
 *---------------------------------------------------------*/

static const uint8_t cmd_01[] = { 0x00 };
static const uint8_t cmd_11[] = { };
static const uint8_t cmd_F0[] = { 0xC3 };
static const uint8_t cmd_F0_2[] = { 0x96 };

static const lcd_init_cmd_t st77916_vendor_init_cmds[] =
{
    /* Software reset */
    {
        .cmd = CMD_SWRESET,
        .data = NULL,
        .data_bytes = 0,
        .delay_ms = 120,
    },

    /* Sleep Out */
    {
        .cmd = CMD_SLPOUT,
        .data = NULL,
        .data_bytes = 0,
        .delay_ms = 120,
    },

    /* Enable command set */
    {
        .cmd = 0xF0,
        .data = cmd_F0,
        .data_bytes = sizeof(cmd_F0),
        .delay_ms = 0,
    },

    {
        .cmd = 0xF0,
        .data = cmd_F0_2,
        .data_bytes = sizeof(cmd_F0_2),
        .delay_ms = 0,
    },
        {0xF0, (uint8_t[]){0x28}, 1, 0},
        {0xF2, (uint8_t[]){0x28}, 1, 0},
        {0x73, (uint8_t[]){0xF0}, 1, 0},
        {0x7C, (uint8_t[]){0xD1}, 1, 0},
        {0x83, (uint8_t[]){0xE0}, 1, 0},
        {0x84, (uint8_t[]){0x61}, 1, 0},
        {0xF2, (uint8_t[]){0x82}, 1, 0},
        {0xF0, (uint8_t[]){0x00}, 1, 0},
        {0xF0, (uint8_t[]){0x01}, 1, 0},
        {0xF1, (uint8_t[]){0x01}, 1, 0},
        {0xB0, (uint8_t[]){0x56}, 1, 0},
        {0xB1, (uint8_t[]){0x4D}, 1, 0},
        {0xB2, (uint8_t[]){0x24}, 1, 0},
        {0xB4, (uint8_t[]){0x87}, 1, 0},
        {0xB5, (uint8_t[]){0x44}, 1, 0},
        {0xB6, (uint8_t[]){0x8B}, 1, 0},
        {0xB7, (uint8_t[]){0x40}, 1, 0},
        {0xB8, (uint8_t[]){0x86}, 1, 0},
        {0xBA, (uint8_t[]){0x00}, 1, 0},
        {0xBB, (uint8_t[]){0x08}, 1, 0},
        {0xBC, (uint8_t[]){0x08}, 1, 0},
        {0xBD, (uint8_t[]){0x00}, 1, 0},
        {0xC0, (uint8_t[]){0x80}, 1, 0},
        {0xC1, (uint8_t[]){0x10}, 1, 0},
        {0xC2, (uint8_t[]){0x37}, 1, 0},
        {0xC3, (uint8_t[]){0x80}, 1, 0},
        {0xC4, (uint8_t[]){0x10}, 1, 0},
        {0xC5, (uint8_t[]){0x37}, 1, 0},
        {0xC6, (uint8_t[]){0xA9}, 1, 0},
        {0xC7, (uint8_t[]){0x41}, 1, 0},
        {0xC8, (uint8_t[]){0x01}, 1, 0},
        {0xC9, (uint8_t[]){0xA9}, 1, 0},
        {0xCA, (uint8_t[]){0x41}, 1, 0},
        {0xCB, (uint8_t[]){0x01}, 1, 0},
        {0xD0, (uint8_t[]){0x91}, 1, 0},
        {0xD1, (uint8_t[]){0x68}, 1, 0},
        {0xD2, (uint8_t[]){0x68}, 1, 0},
        {0xF5, (uint8_t[]){0x00, 0xA5}, 2, 0},
        {0xDD, (uint8_t[]){0x4F}, 1, 0},
        {0xDE, (uint8_t[]){0x4F}, 1, 0},
        {0xF1, (uint8_t[]){0x10}, 1, 0},
        {0xF0, (uint8_t[]){0x00}, 1, 0},
        {0xF0, (uint8_t[]){0x02}, 1, 0},
        {0xE0, (uint8_t[]){0xF0, 0x0A, 0x10, 0x09, 0x09, 0x36, 0x35, 0x33, 0x4A, 0x29, 0x15, 0x15, 0x2E, 0x34}, 14, 0},
        {0xE1, (uint8_t[]){0xF0, 0x0A, 0x0F, 0x08, 0x08, 0x05, 0x34, 0x33, 0x4A, 0x39, 0x15, 0x15, 0x2D, 0x33}, 14, 0},
        {0xF0, (uint8_t[]){0x10}, 1, 0},
        {0xF3, (uint8_t[]){0x10}, 1, 0},
        {0xE0, (uint8_t[]){0x07}, 1, 0},
        {0xE1, (uint8_t[]){0x00}, 1, 0},
        {0xE2, (uint8_t[]){0x00}, 1, 0},
        {0xE3, (uint8_t[]){0x00}, 1, 0},
        {0xE4, (uint8_t[]){0xE0}, 1, 0},
        {0xE5, (uint8_t[]){0x06}, 1, 0},
        {0xE6, (uint8_t[]){0x21}, 1, 0},
        {0xE7, (uint8_t[]){0x01}, 1, 0},
        {0xE8, (uint8_t[]){0x05}, 1, 0},
        {0xE9, (uint8_t[]){0x02}, 1, 0},
        {0xEA, (uint8_t[]){0xDA}, 1, 0},
        {0xEB, (uint8_t[]){0x00}, 1, 0},
        {0xEC, (uint8_t[]){0x00}, 1, 0},
        {0xED, (uint8_t[]){0x0F}, 1, 0},
        {0xEE, (uint8_t[]){0x00}, 1, 0},
        {0xEF, (uint8_t[]){0x00}, 1, 0},
        {0xF8, (uint8_t[]){0x00}, 1, 0},
        {0xF9, (uint8_t[]){0x00}, 1, 0},
        {0xFA, (uint8_t[]){0x00}, 1, 0},
        {0xFB, (uint8_t[]){0x00}, 1, 0},
        {0xFC, (uint8_t[]){0x00}, 1, 0},
        {0xFD, (uint8_t[]){0x00}, 1, 0},
        {0xFE, (uint8_t[]){0x00}, 1, 0},
        {0xFF, (uint8_t[]){0x00}, 1, 0},
        {0x60, (uint8_t[]){0x40}, 1, 0},
        {0x61, (uint8_t[]){0x04}, 1, 0},
        {0x62, (uint8_t[]){0x00}, 1, 0},
        {0x63, (uint8_t[]){0x42}, 1, 0},
        {0x64, (uint8_t[]){0xD9}, 1, 0},
        {0x65, (uint8_t[]){0x00}, 1, 0},
        {0x66, (uint8_t[]){0x00}, 1, 0},
        {0x67, (uint8_t[]){0x00}, 1, 0},
        {0x68, (uint8_t[]){0x00}, 1, 0},
        {0x69, (uint8_t[]){0x00}, 1, 0},
        {0x6A, (uint8_t[]){0x00}, 1, 0},
        {0x6B, (uint8_t[]){0x00}, 1, 0},
        {0x70, (uint8_t[]){0x40}, 1, 0},
        {0x71, (uint8_t[]){0x03}, 1, 0},
        {0x72, (uint8_t[]){0x00}, 1, 0},
        {0x73, (uint8_t[]){0x42}, 1, 0},
        {0x74, (uint8_t[]){0xD8}, 1, 0},
        {0x75, (uint8_t[]){0x00}, 1, 0},
        {0x76, (uint8_t[]){0x00}, 1, 0},
        {0x77, (uint8_t[]){0x00}, 1, 0},
        {0x78, (uint8_t[]){0x00}, 1, 0},
        {0x79, (uint8_t[]){0x00}, 1, 0},
        {0x7A, (uint8_t[]){0x00}, 1, 0},
        {0x7B, (uint8_t[]){0x00}, 1, 0},
        {0x80, (uint8_t[]){0x48}, 1, 0},
        {0x81, (uint8_t[]){0x00}, 1, 0},
        {0x82, (uint8_t[]){0x06}, 1, 0},
        {0x83, (uint8_t[]){0x02}, 1, 0},
        {0x84, (uint8_t[]){0xD6}, 1, 0},
        {0x85, (uint8_t[]){0x04}, 1, 0},
        {0x86, (uint8_t[]){0x00}, 1, 0},
        {0x87, (uint8_t[]){0x00}, 1, 0},
        {0x88, (uint8_t[]){0x48}, 1, 0},
        {0x89, (uint8_t[]){0x00}, 1, 0},
        {0x8A, (uint8_t[]){0x08}, 1, 0},
        {0x8B, (uint8_t[]){0x02}, 1, 0},
        {0x8C, (uint8_t[]){0xD8}, 1, 0},
        {0x8D, (uint8_t[]){0x04}, 1, 0},
        {0x8E, (uint8_t[]){0x00}, 1, 0},
        {0x8F, (uint8_t[]){0x00}, 1, 0},
        {0x90, (uint8_t[]){0x48}, 1, 0},
        {0x91, (uint8_t[]){0x00}, 1, 0},
        {0x92, (uint8_t[]){0x0A}, 1, 0},
        {0x93, (uint8_t[]){0x02}, 1, 0},
        {0x94, (uint8_t[]){0xDA}, 1, 0},
        {0x95, (uint8_t[]){0x04}, 1, 0},
        {0x96, (uint8_t[]){0x00}, 1, 0},
        {0x97, (uint8_t[]){0x00}, 1, 0},
        {0x98, (uint8_t[]){0x48}, 1, 0},
        {0x99, (uint8_t[]){0x00}, 1, 0},
        {0x9A, (uint8_t[]){0x0C}, 1, 0},
        {0x9B, (uint8_t[]){0x02}, 1, 0},
        {0x9C, (uint8_t[]){0xDC}, 1, 0},
        {0x9D, (uint8_t[]){0x04}, 1, 0},
        {0x9E, (uint8_t[]){0x00}, 1, 0},
        {0x9F, (uint8_t[]){0x00}, 1, 0},
        {0xA0, (uint8_t[]){0x48}, 1, 0},
        {0xA1, (uint8_t[]){0x00}, 1, 0},
        {0xA2, (uint8_t[]){0x05}, 1, 0},
        {0xA3, (uint8_t[]){0x02}, 1, 0},
        {0xA4, (uint8_t[]){0xD5}, 1, 0},
        {0xA5, (uint8_t[]){0x04}, 1, 0},
        {0xA6, (uint8_t[]){0x00}, 1, 0},
        {0xA7, (uint8_t[]){0x00}, 1, 0},
        {0xA8, (uint8_t[]){0x48}, 1, 0},
        {0xA9, (uint8_t[]){0x00}, 1, 0},
        {0xAA, (uint8_t[]){0x07}, 1, 0},
        {0xAB, (uint8_t[]){0x02}, 1, 0},
        {0xAC, (uint8_t[]){0xD7}, 1, 0},
        {0xAD, (uint8_t[]){0x04}, 1, 0},
        {0xAE, (uint8_t[]){0x00}, 1, 0},
        {0xAF, (uint8_t[]){0x00}, 1, 0},
        {0xB0, (uint8_t[]){0x48}, 1, 0},
        {0xB1, (uint8_t[]){0x00}, 1, 0},
        {0xB2, (uint8_t[]){0x09}, 1, 0},
        {0xB3, (uint8_t[]){0x02}, 1, 0},
        {0xB4, (uint8_t[]){0xD9}, 1, 0},
        {0xB5, (uint8_t[]){0x04}, 1, 0},
        {0xB6, (uint8_t[]){0x00}, 1, 0},
        {0xB7, (uint8_t[]){0x00}, 1, 0},

        {0xB8, (uint8_t[]){0x48}, 1, 0},
        {0xB9, (uint8_t[]){0x00}, 1, 0},
        {0xBA, (uint8_t[]){0x0B}, 1, 0},
        {0xBB, (uint8_t[]){0x02}, 1, 0},
        {0xBC, (uint8_t[]){0xDB}, 1, 0},
        {0xBD, (uint8_t[]){0x04}, 1, 0},
        {0xBE, (uint8_t[]){0x00}, 1, 0},
        {0xBF, (uint8_t[]){0x00}, 1, 0},
        {0xC0, (uint8_t[]){0x10}, 1, 0},
        {0xC1, (uint8_t[]){0x47}, 1, 0},
        {0xC2, (uint8_t[]){0x56}, 1, 0},
        {0xC3, (uint8_t[]){0x65}, 1, 0},
        {0xC4, (uint8_t[]){0x74}, 1, 0},
        {0xC5, (uint8_t[]){0x88}, 1, 0},
        {0xC6, (uint8_t[]){0x99}, 1, 0},
        {0xC7, (uint8_t[]){0x01}, 1, 0},
        {0xC8, (uint8_t[]){0xBB}, 1, 0},
        {0xC9, (uint8_t[]){0xAA}, 1, 0},
        {0xD0, (uint8_t[]){0x10}, 1, 0},
        {0xD1, (uint8_t[]){0x47}, 1, 0},
        {0xD2, (uint8_t[]){0x56}, 1, 0},
        {0xD3, (uint8_t[]){0x65}, 1, 0},
        {0xD4, (uint8_t[]){0x74}, 1, 0},
        {0xD5, (uint8_t[]){0x88}, 1, 0},
        {0xD6, (uint8_t[]){0x99}, 1, 0},
        {0xD7, (uint8_t[]){0x01}, 1, 0},
        {0xD8, (uint8_t[]){0xBB}, 1, 0},
        {0xD9, (uint8_t[]){0xAA}, 1, 0},
        {0xF3, (uint8_t[]){0x01}, 1, 0},
        {0xF0, (uint8_t[]){0x00}, 1, 0},
        {0x21, (uint8_t[]){0x00}, 1, 0},
        {0x11, (uint8_t[]){0x00}, 1, 120},
        {0x29, (uint8_t[]){0x00}, 1, 0},
    };