/*
 * =================================================================
 *
 *       Filename:  smart_mtp_s6e3.h
 *
 *    Description:  Smart dimming algorithm implementation
 *
 *        Company:  Samsung Electronics
 *
 * ================================================================
 */
/*
<one line to give the program's name and a brief idea of what it does.>
Copyright (C) 2012, Samsung Electronics. All rights reserved.

*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
*/
#ifndef _SS_DSI_SMART_DIMMING_S6E3HF2_AMB509EG01_H_
#define _SS_DSI_SMART_DIMMING_S6E3HF2_AMB509EG01_H_

#include "../ss_dsi_panel_common.h"
#include "../ss_dsi_smart_dimming_common.h"

/*
*	From 4.8 inch model use AID function
*	CASE#1 is used for now.
*/
#define AID_OPERATION

enum {
	GAMMA_CURVE_1P9 = 0,
	GAMMA_CURVE_2P15,
	GAMMA_CURVE_2P2,
};

#define LUMINANCE_MAX 65
#define GAMMA_SET_MAX 35
#define BIT_SHIFT 22
/*
	it means BIT_SHIFT is 22.  pow(2,BIT_SHIFT) is 4194304.
	BIT_SHIFT is used for right bit shfit
*/
#define BIT_SHFIT_MUL 4194304

#define GRAY_SCALE_MAX 256

/*6.4*4194304 */
#define VREG0_REF_6P4 26843546

/*6.3*4194304 */
#define VREG0_REF_6P3 26424115

/*6.2*4194304 */
#define VREG0_REF_6P2 26004685

/*V0,V3,V11,V23,V35,V51,V87,V151,V203,V255*/
#define ARRAY_MAX 11

/* PANEL DEPENDENT THINGS */
#define MIN_CANDELA	2

/*
*	ID 0x20
*/
#define V255_300CD_R_MSB_20 0x01
#define V255_300CD_R_LSB_20 0x00

#define V255_300CD_G_MSB_20 0x01
#define V255_300CD_G_LSB_20 0x00

#define V255_300CD_B_MSB_20 0x01
#define V255_300CD_B_LSB_20 0x00

#define V203_300CD_R_20 0x80
#define V203_300CD_G_20 0x80
#define V203_300CD_B_20 0x80

#define V151_300CD_R_20 0x80
#define V151_300CD_G_20 0x80
#define V151_300CD_B_20 0x80

#define V87_300CD_R_20 0x80
#define V87_300CD_G_20 0x80
#define V87_300CD_B_20 0x80

#define V51_300CD_R_20 0x80
#define V51_300CD_G_20 0x80
#define V51_300CD_B_20 0x80

#define V35_300CD_R_20 0x80
#define V35_300CD_G_20 0x80
#define V35_300CD_B_20 0x80

#define V23_300CD_R_20 0x80
#define V23_300CD_G_20 0x80
#define V23_300CD_B_20 0x80

#define V11_300CD_R_20 0x80
#define V11_300CD_G_20 0x80
#define V11_300CD_B_20 0x80

#define V3_300CD_R_20 0x80
#define V3_300CD_G_20 0x80
#define V3_300CD_B_20 0x80

#define V0_300CD_R_20 0x00
#define V0_300CD_G_20 0x00
#define V0_300CD_B_20 0x00

#define VT_300CD_R_20 0x00
#define VT_300CD_G_20 0x00
#define VT_300CD_B_20 0x00

#define PANEL_REVA 0x11
#define PANEL_REVB 0x12
#define PANEL_REVD 0x13
#define PANEL_REVE 0x14
#define PANEL_YM4 0x01

#define AOR_FIX_CD		172
#define AOR_ADJUST_CD		111
#define AOR_DIM_BASE_CD		116
#define AOR_DIM_BASE_CD_REVA	110
#define AOR_DIM_BASE_CD_REVB	112
#define AOR_DIM_BASE_CD_REVD	114

#define AOR_DIM_BASE_CD_REVC	117
#define AOR_DIM_BASE_CD_REVF	119
#define AOR_DIM_BASE_CD_REVH	113


/* PANEL DEPENDENT THINGS END*/

enum {
	V1_INDEX = 0,
	V3_INDEX = 1,
	V11_INDEX = 2,
	V23_INDEX = 3,
	V35_INDEX = 4,
	V51_INDEX = 5,
	V87_INDEX = 6,
	V151_INDEX = 7,
	V203_INDEX = 8,
	V255_INDEX = 9,
};

struct GAMMA_LEVEL {
	int level_0;
	int level_1;
	int level_3;
	int level_11;
	int level_23;
	int level_35;
	int level_51;
	int level_87;
	int level_151;
	int level_203;
	int level_255;
} __packed;

struct RGB_OUTPUT_VOLTARE {
	struct GAMMA_LEVEL R_VOLTAGE;
	struct GAMMA_LEVEL G_VOLTAGE;
	struct GAMMA_LEVEL B_VOLTAGE;
} __packed;

struct GRAY_VOLTAGE {
	/*
		This voltage value use 14bit right shit
		it means voltage is divied by 16384.
	*/
	int R_Gray;
	int G_Gray;
	int B_Gray;
} __packed;

struct GRAY_SCALE {
	struct GRAY_VOLTAGE TABLE[GRAY_SCALE_MAX];
	struct GRAY_VOLTAGE VT_TABLE;
} __packed;

/*V0,V1,V3,V11,V23,V35,V51,V87,V151,V203,V255*/

struct MTP_SET {
	char OFFSET_255_MSB;
	char OFFSET_255_LSB;
	char OFFSET_203;
	char OFFSET_151;
	char OFFSET_87;
	char OFFSET_51;
	char OFFSET_35;
	char OFFSET_23;
	char OFFSET_11;
	char OFFSET_3;
	char OFFSET_0;
	char OFFSET_T;
} __packed;

struct MTP_SET_R {
	char OFFSET_255_MSB;
	char OFFSET_255_LSB;
	char OFFSET_203;
	char OFFSET_151;
	char OFFSET_87;
	char OFFSET_51;
	char OFFSET_35;
	char OFFSET_23;
	char OFFSET_11;
	char OFFSET_3;
	char OFFSET_0;
} __packed;

struct MTP_OFFSET {
	struct MTP_SET_R R_OFFSET;
	struct MTP_SET G_OFFSET;
	struct MTP_SET B_OFFSET;
} __packed;

struct illuminance_table {
	int lux;
	char gamma_setting[GAMMA_SET_MAX];
} __packed;

struct SMART_DIM {
	struct MTP_OFFSET MTP_ORIGN;
	struct MTP_OFFSET MTP;
	struct RGB_OUTPUT_VOLTARE RGB_OUTPUT;
	struct GRAY_SCALE GRAY;

	/* Because of AID funtion, below members are added*/
	int lux_table_max;
	int *plux_table;
	struct illuminance_table gen_table[LUMINANCE_MAX];

	int brightness_level;
	int ldi_revision;
	int vregout_voltage;
} __packed;


#define CANDELA_MAX_TABLE 64
#define RGB_COMPENSATION 24

static int candela_table[][2] = {
	{2, 0},
	{3, 1},
	{4, 2},
	{5, 3},
	{6, 4},
	{7, 5},
	{8, 6},
	{9, 7},
	{10, 8},
	{11, 9},
	{12, 10},
	{13, 11},
	{14, 12},
	{15, 13},
	{16, 14},
	{17, 15},
	{19, 16},
	{20, 17},
	{21, 18},
	{22, 19},
	{24, 20},
	{25, 21},
	{27, 22},
	{29, 23},
	{30, 24},
	{32, 25},
	{34, 26},
	{37, 27},
	{39, 28},
	{41, 29},
	{44, 30},
	{47, 31},
	{50, 32},
	{53, 33},
	{56, 34},
	{60, 35},
	{64, 36},
	{68, 37},
	{72, 38},
	{77, 39},
	{82, 40},
	{87, 41},
	{93, 42},
	{98, 43},
	{105, 44},
	{111, 45},
	{119, 46},
	{126, 47},
	{134, 48},
	{143, 49},
	{152, 50},
	{162, 51},
	{172, 52},
	{183, 53},
	{195, 54},
	{207, 55},
	{220, 56},
	{234, 57},
	{249, 58},
	{265, 59},
	{282, 60},
	{300, 61},
	{316, 62},
	{333, 63},
	{360, 64},
};

static int gradation_offset_revA[][9] = {
/*	V255 V203 V151 V87 V51 V35 V23 V11 V3 */
	{0, 10, 15, 23, 31, 35, 38, 34, 33},
	{0, 7, 12, 18, 22, 27, 30, 34, 33},
	{0, 6, 10, 14, 18, 22, 26, 29, 29},
	{0, 5, 9, 12, 15, 19, 22, 26, 28},
	{0, 5, 7, 11, 14, 17, 19, 24, 20},
	{0, 4, 7, 10, 12, 15, 18, 22, 21},
	{0, 4, 6, 9, 11, 13, 16, 20, 21},
	{0, 4, 6, 8, 10, 12, 15, 18, 20},
	{0, 4, 5, 7, 9, 11, 14, 17, 19},
	{0, 4, 5, 7, 9, 11, 13, 17, 17},
	{0, 3, 4, 6, 7, 10, 12, 15, 19},
	{0, 3, 4, 6, 7, 9, 11, 15, 14},
	{0, 3, 4, 6, 7, 9, 10, 14, 17},
	{0, 3, 4, 5, 7, 8, 10, 14, 16},
	{0, 3, 4, 5, 6, 8, 9, 13, 16},
	{0, 3, 4, 5, 6, 8, 9, 13, 15},
	{0, 3, 3, 4, 5, 7, 8, 12, 13},
	{0, 3, 3, 4, 5, 6, 8, 12, 9},
	{0, 3, 3, 4, 5, 6, 7, 11, 14},
	{0, 3, 3, 4, 4, 6, 7, 11, 11},
	{0, 3, 3, 4, 4, 5, 7, 10, 13},
	{0, 3, 3, 4, 4, 5, 7, 10, 12},
	{0, 3, 3, 3, 4, 5, 6, 10, 9},
	{0, 3, 3, 3, 3, 5, 6, 9, 10},
	{0, 3, 3, 3, 3, 5, 6, 9, 9},
	{0, 3, 3, 3, 3, 4, 5, 8, 12},
	{0, 3, 3, 3, 3, 4, 5, 8, 9},
	{0, 3, 3, 3, 3, 3, 4, 7, 9},
	{0, 3, 2, 2, 2, 3, 4, 7, 7},
	{0, 3, 2, 2, 2, 3, 4, 7, 5},
	{0, 3, 2, 2, 2, 3, 4, 6, 8},
	{0, 2, 2, 2, 2, 2, 3, 6, 5},
	{0, 3, 2, 2, 2, 2, 3, 5, 7},
	{0, 2, 2, 2, 1, 2, 3, 5, 4},
	{0, 2, 2, 2, 1, 2, 3, 4, 7},
	{0, 2, 2, 2, 1, 1, 2, 4, 5},
	{0, 2, 2, 1, 1, 1, 2, 4, 3},
	{0, 2, 1, 1, 1, 1, 2, 3, 7},
	{0, 2, 1, 1, 1, 1, 2, 3, 4},
	{0, 2, 1, 1, 1, 1, 2, 3, 2},
	{0, 2, 2, 2, 1, 1, 2, 3, 3},
	{0, 2, 3, 2, 1, 1, 2, 3, 5},
	{0, 2, 3, 2, 1, 1, 2, 2, 4},
	{0, 2, 3, 3, 2, 2, 2, 2, 6},
	{0, 2, 3, 3, 2, 2, 2, 2, 7},
	{0, 2, 3, 3, 2, 1, 2, 2, 5},
	{0, 1, 3, 2, 2, 1, 1, 2, 1},
	{0, 2, 3, 3, 2, 2, 2, 2, 3},
	{0, 1, 4, 3, 2, 1, 2, 2, 2},
	{0, 2, 4, 3, 2, 1, 2, 2, 3},
	{0, 1, 4, 3, 2, 2, 2, 2, 3},
	{0, 2, 3, 3, 1, 1, 1, 1, 2},
	{0, 2, 4, 3, 1, 1, 2, 1, 3},
	{0, 2, 4, 3, 1, 1, 1, 1, 2},
	{0, 2, 3, 2, 1, 0, 1, 1, 0},
	{0, 2, 3, 2, 0, 0, 0, 0, 4},
	{0, 2, 2, 2, 0, 0, 0, 0, 3},
	{0, 1, 2, 2, 0, 0, 0, 0, 1},
	{0, 1, 2, 1, 0, 0, 0, 0, 0},
	{0, 1, 2, 1, 0, 0, 0, 0, 1},
	{0, 1, 1, 1, 0, 0, 0, -1, 0},
	{0, 1, 1, 0, 0, 0, -1, -1, 2},
	{0, 0, -1, 0, -1, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0, -1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
};

static int gradation_offset_revD[][9] = {
/*	V255 V203 V151 V87 V51 V35 V23 V11 V3 */
	{0, 10, 20, 26, 34, 36, 37, 39, 42},
	{0, 5, 10, 15, 19, 22, 26, 29, 32},
	{0, 7, 10, 14, 17, 20, 24, 28, 31},
	{0, 4, 8, 12, 15, 17, 20, 24, 27},
	{0, 5, 6, 10, 12, 13, 16, 20, 23},
	{0, 4, 5, 8, 11, 13, 16, 19, 23},
	{0, 5, 7, 12, 12, 13, 16, 18, 21},
	{0, 4, 1, 6, 7, 9, 12, 15, 18},
	{0, 4, 5, 7, 9, 10, 13, 15, 19},
	{0, 2, 3, 5, 7, 8, 11, 14, 18},
	{0, 3, 4, 6, 8, 8, 13, 15, 19},
	{0, 5, 8, 7, 8, 9, 11, 14, 17},
	{0, 2, 4, 6, 7, 8, 10, 13, 16},
	{0, 3, 4, 6, 6, 7, 9, 12, 16},
	{0, 5, 4, 6, 6, 7, 9, 12, 15},
	{0, 5, 4, 5, 5, 6, 8, 11, 14},
	{0, 3, 3, 4, 5, 6, 8, 11, 14},
	{0, 4, 5, 6, 5, 5, 7, 10, 13},
	{0, 3, 4, 6, 6, 6, 8, 11, 13},
	{0, 4, 5, 5, 5, 5, 7, 10, 13},
	{0, 4, 3, 4, 4, 4, 6, 9, 12},
	{0, 2, 4, 4, 4, 4, 6, 9, 12},
	{0, 4, 5, 4, 3, 3, 5, 8, 10},
	{0, 3, 4, 4, 3, 3, 5, 8, 10},
	{0, 4, 5, 4, 4, 4, 6, 8, 10},
	{0, 4, 4, 3, 3, 3, 5, 7, 8},
	{0, 2, 3, 4, 2, 3, 5, 7, 9},
	{0, 4, 3, 3, 3, 3, 5, 7, 10},
	{0, 3, 4, 4, 3, 2, 4, 6, 8},
	{0, 3, 2, 3, 2, 2, 4, 5, 7},
	{0, 2, 2, 3, 2, 2, 4, 5, 7},
	{0, 2, 2, 2, 2, 2, 4, 5, 8},
	{0, 3, 4, 3, 2, 1, 3, 4, 7},
	{0, 3, 5, 3, 2, 1, 3, 4, 7},
	{0, 3, 2, 3, 2, 1, 3, 4, 6},
	{0, 1, 0, 2, 2, 1, 3, 4, 6},
	{0, 3, 3, 2, 2, 1, 3, 3, 5},
	{0, 3, 3, 2, 1, 1, 3, 3, 5},
	{0, 3, 3, 1, 1, 0, 2, 2, 4},
	{0, 3, 3, 2, 1, 1, 2, 2, 3},
	{0, 3, 3, 3, 1, 1, 2, 3, 4},
	{0, 2, 2, 2, 1, 1, 2, 3, 5},
	{0, 2, 4, 3, 1, 1, 1, 1, 3},
	{0, 3, 4, 3, 1, 1, 2, 2, 4},
	{0, 3, 4, 4, 0, 1, 2, 2, 4},
	{0, 2, 5, 3, 0, 1, 1, 2, 4},
	{0, 2, 4, 3, 1, 1, 2, 2, 4},
	{0, 0, 4, 3, 1, 1, 1, 1, 4},
	{0, 2, 6, 4, 1, 1, 1, 1, 4},
	{0, 2, 6, 2, 1, 1, 1, 2, 4},
	{0, 3, 6, 4, 1, 1, 1, 2, 3},
	{0, 2, 4, 3, 1, 1, 1, 1, 2},
	{0, 1, 3, 3, 0, 1, 1, 1, 2},
	{0, 2, 2, 2, 1, 1, 0, 0, 0},
	{0, 2, 4, 2, 1, 1, 0, 0, 0},
	{0, 2, 4, 3, 1, 1, 0, 0, 2},
	{0, 2, 3, 2, 0, 0, 0, 0, 0},
	{0, 2, 4, 3, 1, 1, 0, 0, 0},
	{0, 2, 3, 1, 0, 0, -1, 0, 0},
	{0, 3, 3, 1, 1, 0, 1, 0, 0},
	{0, 1, 3, 1, 1, 0, 0, -1, 0},
	{0, 1, 2, 2, 0, 0, 0, -1, 0},
	{0, 1, 2, 1, -1, 0, -1, -1, 0},
	{0, 0, 0, -1, -1, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
};

static int gradation_offset_revE[][9] = {
/*	V255 V203 V151 V87 V51 V35 V23 V11 V3 */
	{0, 8, 13, 19, 25, 29, 34, 30, 29},
	{0, 7, 10, 15, 18, 22, 27, 30, 29},
	{0, 6, 9, 13, 15, 19, 22, 26, 29},
	{0, 6, 7, 11, 13, 15, 19, 23, 25},
	{0, 5, 7, 10, 11, 13, 17, 21, 20},
	{0, 5, 6, 9, 10, 12, 16, 19, 21},
	{0, 5, 5, 8, 9, 11, 14, 17, 21},
	{0, 4, 5, 8, 8, 10, 13, 16, 20},
	{0, 4, 5, 7, 7, 9, 12, 15, 14},
	{0, 4, 4, 6, 6, 8, 11, 14, 13},
	{0, 4, 4, 6, 6, 8, 10, 14, 16},
	{0, 4, 4, 6, 5, 7, 9, 13, 16},
	{0, 4, 4, 5, 5, 7, 9, 13, 14},
	{0, 4, 4, 5, 5, 6, 9, 12, 16},
	{0, 4, 4, 5, 5, 6, 8, 12, 12},
	{0, 4, 4, 5, 4, 5, 8, 11, 15},
	{0, 4, 4, 5, 4, 5, 7, 10, 9},
	{0, 4, 4, 4, 4, 5, 7, 10, 9},
	{0, 4, 3, 5, 4, 5, 7, 10, 11},
	{0, 4, 3, 5, 4, 4, 7, 10, 11},
	{0, 4, 3, 4, 4, 4, 7, 9, 8},
	{0, 4, 3, 4, 3, 4, 6, 9, 11},
	{0, 4, 3, 4, 3, 3, 6, 8, 12},
	{0, 4, 3, 4, 3, 3, 5, 8, 9},
	{0, 4, 3, 4, 3, 3, 5, 8, 8},
	{0, 4, 3, 4, 3, 3, 5, 7, 10},
	{0, 3, 3, 4, 3, 3, 5, 7, 8},
	{0, 3, 3, 4, 2, 2, 5, 6, 10},
	{0, 3, 3, 3, 2, 2, 5, 6, 8},
	{0, 3, 3, 3, 2, 2, 4, 6, 6},
	{0, 3, 3, 3, 2, 2, 4, 5, 9},
	{0, 3, 2, 3, 2, 2, 4, 5, 6},
	{0, 3, 2, 3, 2, 1, 4, 4, 3},
	{0, 3, 2, 3, 2, 1, 3, 4, 7},
	{0, 3, 2, 3, 2, 1, 3, 4, 5},
	{0, 3, 2, 3, 2, 1, 3, 3, 2},
	{0, 3, 2, 2, 1, 1, 3, 3, 6},
	{0, 3, 2, 2, 1, 1, 3, 3, 4},
	{0, 3, 2, 2, 1, 1, 2, 3, 1},
	{0, 3, 2, 2, 1, 0, 2, 2, 5},
	{0, 2, 1, 2, 1, 1, 2, 2, 6},
	{0, 2, 2, 2, 1, 1, 2, 3, 1},
	{0, 1, 3, 3, 1, 0, 2, 2, 2},
	{0, 2, 3, 3, 0, 1, 2, 2, 2},
	{0, 1, 3, 2, 1, 1, 1, 2, 3},
	{0, 2, 3, 2, 0, 1, 1, 2, 3},
	{0, 2, 3, 2, 1, 1, 2, 2, 5},
	{0, 1, 3, 3, 1, 1, 1, 1, 6},
	{0, 1, 4, 3, 1, 1, 2, 1, 5},
	{0, 1, 3, 2, 1, 1, 1, 2, 1},
	{0, 2, 4, 3, 1, 1, 2, 2, 1},
	{0, 1, 4, 3, 1, 1, 1, 1, 0},
	{0, 3, 3, 3, 1, 1, 1, 1, 0},
	{0, 2, 3, 2, 1, 1, 0, 1, 0},
	{0, 2, 3, 2, 1, 1, 0, 1, 0},
	{0, 0, 2, 1, 0, 0, 0, 0, 2},
	{0, 0, 2, 1, 0, 0, 0, 0, 0},
	{0, 0, 2, 1, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 0, 0, 0, 0, 0},
	{0, 0, 2, 1, 0, 0, 0, 0, 2},
	{0, 1, 1, 0, -1, 0, 0, -1, 2},
	{0, 1, 0, 0, -1, -1, 0, 0, 0},
	{0, 0, 0, 0, -1, 0, -1, 0, 0},
	{0, 0, 0, 0, -1, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
};


static int gradation_offset_ym4[][9] = {
	{0, 13, 24, 34, 39, 41, 44, 36, 56},
	{0, 10, 20, 28, 32, 34, 35, 36, 56},
	{0, 9, 17, 25, 28, 29, 31, 31, 40},
	{0, 8, 15, 22, 24, 25, 27, 27, 42},
	{0, 8, 15, 21, 22, 24, 25, 25, 23},
	{0, 7, 13, 19, 20, 21, 22, 23, 21},
	{0, 7, 13, 18, 18, 19, 20, 21, 20},
	{0, 6, 12, 17, 17, 18, 19, 19, 28},
	{0, 6, 11, 16, 16, 17, 18, 19, 19},
	{0, 5, 10, 14, 15, 15, 17, 17, 17},
	{0, 6, 11, 14, 14, 14, 16, 16, 15},
	{0, 5, 9, 13, 14, 14, 16, 15, 22},
	{0, 5, 8, 13, 13, 13, 15, 15, 14},
	{0, 5, 9, 12, 12, 12, 14, 14, 15},
	{0, 5, 8, 11, 11, 12, 13, 14, 13},
	{0, 5, 8, 11, 11, 12, 13, 13, 14},
	{0, 4, 8, 10, 10, 10, 12, 12, 13},
	{0, 4, 8, 10, 10, 10, 11, 12, 12},
	{0, 4, 7, 10, 9, 10, 11, 11, 12},
	{0, 4, 7, 9, 9, 9, 11, 11, 12},
	{0, 4, 7, 9, 8, 9, 10, 10, 11},
	{0, 4, 7, 9, 8, 9, 10, 10, 11},
	{0, 4, 7, 8, 7, 8, 9, 9, 10},
	{0, 4, 6, 8, 7, 8, 8, 9, 8},
	{0, 4, 6, 8, 7, 8, 8, 9, 7},
	{0, 4, 6, 8, 7, 7, 8, 8, 10},
	{0, 4, 6, 7, 6, 7, 8, 8, 8},
	{0, 3, 5, 7, 6, 6, 7, 7, 9},
	{0, 3, 5, 6, 5, 6, 7, 7, 7},
	{0, 3, 5, 6, 5, 6, 7, 7, 5},
	{0, 3, 5, 6, 5, 5, 6, 6, 7},
	{0, 3, 5, 5, 4, 5, 6, 6, 5},
	{0, 3, 5, 5, 4, 5, 6, 5, 9},
	{0, 3, 4, 5, 3, 4, 5, 5, 4},
	{0, 3, 4, 5, 3, 4, 5, 4, 6},
	{0, 3, 4, 4, 3, 3, 5, 4, 3},
	{0, 3, 4, 4, 2, 3, 4, 4, 1},
	{0, 2, 4, 4, 2, 3, 4, 3, 5},
	{0, 2, 3, 3, 2, 2, 4, 3, 2},
	{0, 2, 3, 3, 1, 2, 3, 3, 1},
	{0, 3, 4, 3, 2, 2, 3, 3, 1},
	{0, 2, 3, 3, 2, 2, 3, 3, 1},
	{0, 2, 4, 3, 2, 2, 2, 2, 1},
	{0, 2, 4, 4, 2, 2, 3, 2, 2},
	{0, 2, 4, 3, 2, 2, 2, 2, 5},
	{0, 2, 4, 4, 2, 2, 2, 2, 5},
	{0, 1, 4, 4, 2, 2, 2, 2, 1},
	{0, 0, 3, 3, 2, 2, 2, 2, 1},
	{0, 1, 4, 4, 2, 2, 2, 2, 1},
	{0, 0, 3, 3, 2, 2, 2, 2, 1},
	{0, 0, 4, 4, 2, 2, 2, 2, 3},
	{0, 1, 3, 3, 2, 1, 1, 1, 2},
	{0, 1, 4, 3, 2, 1, 2, 1, 4},
	{0, 1, 3, 3, 2, 1, 1, 2, 1},
	{0, 1, 3, 3, 1, 1, 1, 2, 0},
	{0, 1, 2, 2, 1, 0, 1, 1, 1},
	{0, 1, 2, 2, 0, 0, 0, 1, 0},
	{0, 0, 1, 1, 0, 0, 0, 1, 0},
	{0, 0, 1, 1, 0, -1, 0, 0, 2},
	{0, 0, 0, 0, 0, 0, -1, 0, 3},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, -1, -1, -1, 0, 0},
	{0, -1, 0, 0, -1, -1, 0, 0, 0},
	{0, -1, -1, -1, -1, -2, -1, -1, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
};

static int rgb_offset_revA[][RGB_COMPENSATION] = {
/*	R255 G255 B255 R203 G203 B203 R151 G151 B151
	R87 G87 B87 R51 G51 B51 R35 G35 B35
	R23 G23 B23 R11 G11 B11
*/
	{-2, 0, -2, -3, 0, -2, -3, 0, 0, -12, 0, 0, -13, 4, -8, -12, 4, -10, 0, 4, -7, 5, 4, -10,},
	{0, 0, -1, -1, 0, 0, -2, 0, -1, -7, 0, 0, -19, 3, -7, -4, 3, -6, 0, 3, -7, 5, 4, -10,},
	{1, 0, 0, 0, 0, 0, -3, 0, -1, -5, 0, -1, -11, 1, -3, -13, 3, -8, -7, 3, -8, 0, 0, 0,},
	{0, 0, 0, 0, 0, 0, -1, 0, 0, -4, 0, 0, -10, 1, -4, -13, 3, -7, -3, 3, -11, 3, 1, -3,},
	{1, 0, 0, 0, 0, 0, -1, 0, 0, -4, 0, 0, -12, 1, -3, -6, 3, -6, -7, 3, -11, 1, 6, -12,},
	{1, 0, 1, 1, 0, 0, -1, 0, 0, -3, 0, 0, -9, 0, -2, -10, 3, -6, -11, 3, -11, 1, 8, -17,},
	{1, 0, 1, 0, 0, 0, -1, 0, 0, -3, 0, 0, -8, 0, -2, -10, 3, -7, -9, 3, -10, -4, 10, -21,},
	{1, 0, 1, 1, 0, 0, -1, 0, 1, -2, 0, 0, -5, 0, -1, -11, 3, -7, -12, 3, -8, 0, 11, -22,},
	{1, 0, 1, 0, 0, 0, 0, 0, 1, -2, 0, 0, -3, 0, 0, -11, 3, -7, -11, 3, -10, 0, 10, -21,},
	{2, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, -6, 0, -1, -8, 2, -6, -11, 2, -12, 0, 10, -22,},
	{2, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, -6, 0, -1, -5, 2, -5, -12, 2, -9, 1, 12, -26,},
	{2, 0, 1, 1, 0, 0, 0, 0, 1, -1, 0, 1, -5, 0, -1, -6, 2, -4, -8, 2, -8, 0, 10, -21,},
	{2, 0, 1, 0, 0, 0, 1, 0, 1, -1, 0, 1, -4, 0, 0, -6, 1, -4, -8, 1, -14, 0, 7, -14,},
	{3, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, -4, 0, 0, -5, 2, -4, -7, 2, -12, -3, 11, -22,},
	{2, 0, 1, 2, 0, 1, 0, 0, 1, -1, 0, 0, -3, 0, 0, -6, 1, -3, -7, 1, -10, -4, 11, -22,},
	{2, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, -2, 0, 0, -6, 1, -2, -6, 1, -12, -2, 13, -27,},
	{2, 0, 2, 1, 0, 0, 1, 0, 1, 0, 0, 1, -3, 0, 0, -6, 0, -2, -3, 0, -12, -3, 9, -19,},
	{2, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, -1, 0, 1, -5, 0, -2, -5, 0, -10, 0, 13, -26,},
	{2, 0, 2, 2, 0, 0, 0, 0, 1, 0, 0, 1, -1, 0, 1, -5, 1, -2, -5, 1, -12, 0, 6, -14,},
	{2, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 1, -5, 0, -2, -6, 0, -12, 0, 9, -20,},
	{2, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 2, -4, 0, -2, -1, 0, -10, -1, 12, -24,},
	{2, 0, 2, 2, 0, 0, 0, 0, 1, 0, 0, 1, -1, 0, 1, -2, 1, -2, -4, 1, -11, -6, 10, -21,},
	{2, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, -1, 0, 1, -2, 0, -1, -4, 0, -12, -3, 12, -24,},
	{2, 0, 2, 1, 0, 0, 1, 0, 1, 1, 0, 2, 0, 0, 1, -4, 0, -1, 0, 0, -9, -1, 11, -23,},
	{2, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 2, -2, 0, -1, 1, 0, -8, -2, 11, -23,},
	{2, 0, 2, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 2, -2, 0, -1, 0, 0, -8, 0, 13, -26,},
	{2, 0, 2, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 2, -1, 0, 0, 0, 0, -10, -2, 11, -23,},
	{1, 0, 1, 2, 0, 1, 1, 0, 1, 1, 0, 2, 0, 0, 1, -1, 0, 0, 1, 0, -8, 1, 11, -24,},
	{1, 0, 1, 2, 0, 1, 0, 0, 1, 2, 0, 2, 0, 0, 1, 0, 0, 0, 3, 0, -6, 0, 13, -27,},
	{1, 0, 1, 2, 0, 1, 2, 0, 1, 0, 0, 2, 0, 0, 1, 0, 0, 0, 1, 0, -6, 0, 11, -24,},
	{1, 0, 1, 2, 0, 1, 1, 0, 1, 1, -1, 2, 0, 0, 1, 0, 0, 0, 4, 0, -6, 0, 14, -28,},
	{1, 0, 1, 2, 0, 1, 1, 0, 1, 1, 0, 2, 1, 0, 2, -1, 0, -1, 3, 0, -7, -1, 12, -25,},
	{1, 0, 1, 2, 0, 1, 1, 0, 1, 1, -1, 2, 0, 0, 0, 0, 0, 0, 5, 0, -6, 0, 10, -21,},
	{1, 0, 1, 2, 0, 1, 0, 0, 1, 1, -1, 2, 1, 0, 1, 1, 0, 0, 4, 0, -6, 1, 10, -22,},
	{1, 0, 1, 1, 0, 1, 1, 0, 0, 1, -1, 2, 2, 0, 2, 0, 0, 0, 5, 0, -6, 3, 10, -20,},
	{1, 0, 1, 0, 0, 1, 3, 0, 1, 1, -1, 2, 0, 0, 1, 0, 0, 0, 7, 0, -5, 5, 9, -19,},
	{0, 0, 1, 0, 0, 1, 4, 0, 1, 1, -1, 2, 2, 0, 2, 0, 0, -1, 5, 0, -5, 9, 8, -16,},
	{1, 0, 1, 1, 0, 1, 2, 0, 1, 1, -1, 2, 2, 0, 2, 0, 0, 0, 8, 0, -6, 10, 6, -14,},
	{1, 0, 1, 1, 0, 1, 2, 0, 1, 1, 0, 2, 2, 0, 2, 2, 0, -1, 8, 0, -5, 16, 5, -10,},
	{0, 0, 1, 1, 0, 1, 2, 0, 1, 2, 0, 2, 2, 0, 2, 3, 0, 0, 8, 0, -5, 13, 4, -10,},
	{1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 2, 1, 0, 1, 1, 0, 0, 9, 0, -5, 15, 5, -11,},
	{0, 0, 1, 0, 0, 1, 2, 0, 1, 1, 0, 2, 2, 0, 2, 1, 0, 0, 7, 0, -4, 14, 5, -11,},
	{1, 0, 1, 1, 0, 1, 2, 0, 1, 0, 0, 1, 2, -1, 2, 1, 0, 0, 11, 0, -4, 12, 5, -11,},
	{0, 0, 1, 1, 0, 1, 2, 0, 1, 0, 0, 2, 2, 0, 2, 1, 0, 1, 8, 0, -4, 16, 5, -11,},
	{1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 2, 0, 1, 1, 0, 0, 7, 0, -3, 12, 6, -12,},
	{1, 0, 1, 0, 0, 1, 1, 0, 1, 2, 0, 2, 1, 0, 1, 0, 0, 0, 9, 0, -3, 12, 4, -10,},
	{0, 0, 1, 0, 0, 1, 1, 0, 1, 2, 0, 0, 2, 0, 1, 1, 0, 1, 6, 0, -3, 13, 4, -10,},
	{1, 0, 1, 1, 0, 1, 0, 0, 1, 2, 0, 1, 1, -1, 2, 0, 0, 0, 7, 0, -2, 15, 4, -10,},
	{0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 2, 7, 0, -2, 15, 4, -8,},
	{0, 0, 1, 1, 0, 1, 0, 0, 1, 2, 0, 0, 2, 0, 2, 1, 0, 0, 5, 0, 0, 14, 4, -10,},
	{0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 5, 0, -1, 9, 5, -11,},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 1, -1, 2, 1, -1, 2, 1, 0, 0, 5, 0, 0, 9, 5, -11,},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 2, 0, 0, 1, 3, 0, -1, 13, 4, -9,},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 1, -1, 2, 1, 0, 1, 4, 0, -1, 13, 4, -8,},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 1, -1, 2, 0, 0, 0, 5, 0, 0, 16, 2, -5,},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 2, 0, 2, 0, 0, 0, 5, 0, 0, 18, 2, -4,},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 5, 0, 0, 20, 2, -4,},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 2, 1, 0, 0, 5, 0, 0, 21, 1, -2,},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
	};

static int rgb_offset_ym4[][RGB_COMPENSATION] = {
/*	R255 G255 B255 R203 G203 B203 R151 G151 B151
	R87 G87 B87 R51 G51 B51 R35 G35 B35
	R23 G23 B23 R11 G11 B11
*/
	{-14, 2, -12, -9, 2, -8, -14, 2, -11, -23, 7, -14, -33, 9, -18, -28, 5, -12, -36, 5, -12, -27, 5, -10},
	{-9, 1, -8, -7, 1, -6, -11, 2, -9, -21, 6, -14, -31, 8, -18, -24, 6, -13, -36, 6, -12, -27, 5, -10},
	{-7, 1, -6, -5, 1, -5, -9, 1, -8, -19, 6, -14, -28, 7, -16, -25, 6, -14, -36, 6, -13, -37, 6, -14},
	{-4, 1, -4, -5, 1, -4, -9, 1, -7, -16, 5, -12, -26, 7, -16, -26, 7, -15, -35, 7, -14, -44, 7, -16},
	{-4, 0, -4, -5, 0, -4, -7, 1, -6, -15, 5, -12, -25, 7, -16, -24, 6, -13, -32, 6, -14, -41, 9, -18},
	{-4, 0, -4, -4, 0, -3, -8, 1, -7, -13, 5, -10, -22, 6, -14, -24, 7, -14, -34, 7, -16, -40, 9, -19},
	{-3, 0, -3, -3, 0, -3, -8, 1, -6, -12, 5, -10, -21, 7, -14, -24, 6, -14, -34, 6, -16, -40, 10, -22},
	{-3, 0, -3, -3, 0, -3, -6, 1, -5, -11, 4, -9, -21, 6, -14, -23, 6, -12, -31, 6, -16, -46, 11, -23},
	{-1, 0, -2, -4, 0, -3, -5, 1, -5, -11, 4, -9, -21, 6, -14, -21, 5, -12, -33, 5, -18, -46, 10, -22},
	{-2, 0, -3, -2, 0, -2, -4, 1, -4, -11, 4, -9, -18, 6, -12, -23, 6, -13, -28, 6, -16, -44, 12, -24},
	{-2, 0, -2, -2, 0, -2, -4, 1, -4, -10, 4, -8, -17, 6, -12, -22, 5, -12, -28, 5, -16, -44, 12, -24},
	{-2, 0, -2, -1, 0, -2, -5, 0, -4, -10, 3, -8, -17, 5, -12, -22, 5, -12, -26, 5, -15, -47, 13, -28},
	{-2, 0, -2, 0, 0, -1, -5, 0, -4, -10, 3, -8, -17, 5, -12, -20, 5, -11, -28, 5, -17, -43, 12, -24},
	{-1, 0, -2, -1, 0, -1, -4, 0, -3, -8, 3, -7, -17, 5, -12, -21, 5, -12, -26, 5, -16, -46, 12, -26},
	{-1, 0, -2, -1, 0, -1, -4, 0, -3, -8, 3, -7, -17, 6, -12, -17, 4, -10, -30, 4, -18, -43, 11, -24},
	{-1, 0, -2, -3, 0, -3, -2, 0, -1, -7, 3, -6, -17, 5, -12, -16, 4, -10, -27, 4, -16, -49, 13, -27},
	{-1, 0, -1, -3, 0, -3, -1, 0, 0, -7, 3, -6, -14, 5, -10, -16, 5, -10, -24, 5, -14, -50, 13, -28},
	{-1, 0, -1, -2, 0, -3, -2, 0, 0, -7, 2, -6, -14, 4, -10, -17, 5, -11, -27, 5, -16, -46, 12, -26},
	{0, 0, -1, -3, 0, -3, -1, 0, 0, -6, 2, -5, -14, 5, -10, -15, 4, -10, -26, 4, -15, -48, 13, -28},
	{0, 0, -1, -2, 0, -2, -1, 0, 0, -6, 2, -5, -14, 4, -10, -16, 4, -10, -23, 4, -13, -48, 13, -28},
	{0, 0, -1, -2, 0, -2, -1, 0, 0, -5, 2, -4, -14, 4, -10, -14, 4, -9, -25, 4, -14, -47, 14, -29},
	{0, 0, -1, -2, 0, -2, -1, 0, 0, -5, 1, -4, -14, 4, -10, -14, 4, -9, -24, 4, -14, -46, 13, -28},
	{0, 0, -1, -1, 0, -2, -2, 0, 0, -4, 2, -4, -12, 4, -9, -12, 4, -8, -23, 4, -13, -47, 13, -28},
	{0, 0, 0, -1, 0, -2, -2, 0, -1, -4, 2, -4, -11, 4, -8, -12, 4, -8, -24, 4, -14, -43, 12, -26},
	{0, 0, 0, -1, 0, -2, -2, 0, -1, -4, 2, -4, -11, 3, -8, -12, 4, -8, -24, 4, -14, -38, 12, -24},
	{0, 0, 0, -1, 0, -2, -2, 0, -3, -4, 1, -2, -11, 3, -8, -12, 4, -8, -23, 4, -12, -43, 13, -27},
	{0, 0, 0, -1, 0, -1, -2, 0, -3, -4, 1, -3, -10, 3, -8, -12, 3, -8, -21, 3, -11, -42, 12, -26},
	{0, 0, 0, 0, 0, -1, -2, 0, -3, -5, 1, -2, -9, 3, -7, -11, 3, -8, -19, 3, -11, -42, 12, -26},
	{0, 0, 0, 0, 0, -1, -2, 0, -3, -5, 0, -2, -9, 3, -7, -11, 3, -8, -17, 3, -10, -42, 12, -25},
	{0, 0, 0, 0, 0, -1, -2, 0, -3, -4, 0, -1, -9, 3, -7, -9, 3, -7, -18, 3, -10, -38, 11, -24},
	{0, 0, 0, 0, 0, -1, -2, 0, -2, -4, 0, -2, -7, 3, -6, -9, 3, -6, -18, 3, -10, -40, 12, -25},
	{0, 0, 0, 0, 0, -1, -1, 0, -2, -5, 0, -2, -8, 2, -6, -8, 2, -6, -17, 2, -9, -37, 11, -24},
	{0, 0, 0, 0, 0, -1, -1, 0, -2, -4, 0, -1, -7, 2, -6, -9, 2, -6, -16, 2, -8, -40, 12, -25},
	{0, 0, 0, 0, 0, -1, -1, 0, -2, -4, 0, 0, -6, 2, -5, -7, 2, -6, -16, 2, -8, -34, 11, -24},
	{0, 0, 0, 0, 0, -1, -1, 0, -2, -3, 0, 0, -6, 2, -4, -7, 2, -6, -14, 2, -7, -35, 11, -24},
	{0, 0, 0, 0, 0, -1, -1, 0, -2, -3, 0, 0, -5, 2, -4, -6, 2, -5, -13, 2, -6, -33, 10, -22},
	{0, 0, 0, 0, 0, -1, 0, 0, -1, -4, 0, -1, -5, 2, -4, -5, 1, -4, -13, 1, -7, -31, 9, -20},
	{0, 0, 0, 0, 0, -1, -1, 0, -1, -2, 0, 0, -5, 2, -4, -4, 1, -4, -12, 1, -6, -27, 11, -24},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -5, 1, -4, -4, 1, -3, -10, 1, -4, -23, 10, -22},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -5, 1, -4, -3, 1, -3, -8, 1, -4, -18, 9, -19},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -4, 1, -3, -4, 1, -4, -9, 1, -4, -20, 10, -20},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -4, 1, -3, -3, 1, -3, -9, 1, -4, -21, 9, -20},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -2, 0, 0, -4, 1, -2, -2, 1, -3, -9, 1, -3, -19, 8, -18},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -2, 0, 0, -4, 1, -3, -2, 1, -3, -8, 1, -2, -20, 9, -18},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, -2, -4, 0, -2, -3, 1, -3, -9, 1, -3, -21, 9, -18},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, -2, -3, 0, -1, -1, 1, -3, -8, 1, -2, -20, 8, -17},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, -1, 1, -2, -2, 1, -3, -7, 1, -1, -19, 6, -13},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, -3, 0, 0, -1, 1, -2, -8, 1, -1, -18, 6, -13},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, -3, 0, -2, -1, 1, -2, -8, 1, -2, -19, 6, -12},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, -2, 0, -1, -2, 1, -2, -6, 1, -2, -19, 5, -12},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, -3, 0, -1, -1, 1, -2, -6, 1, -2, -19, 5, -12},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, -2, 0, 0, -1, 1, -2, -5, 1, -1, -19, 5, -11},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -3, 0, -1, -2, 1, -2, -5, 1, -1, -18, 5, -10},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -3, 0, -2, -3, 0, -2, -6, 0, -2, -17, 4, -10},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -3, 0, -1, -2, 0, -2, -5, 0, -2, -13, 3, -8},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -3, 0, -1, 0, 0, -1, -4, 0, -1, -13, 3, -8},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, 0, 0, -1, -3, 0, 0, -11, 3, -7},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, 0, 0, -1, -3, 0, 0, -8, 2, -6},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

#endif