/*
Copyright 2020 Cole Smith <cole@boadsource.xyz>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "split_util.h"

#define _______ KC_TRNS

#define LG_ESC  LGUI_T(KC_ESC)      // Super key if held, Escape if tapped
#define LS_TAB  LSFT_T(KC_TAB)      // Shift if held, Tab if tapped
#define LAYER2  LT(2, KC_LBRC)      // Activate layer 2 if held, left bracket if tapped
#define LAYER3  LT(3, KC_SPC)       // Activate layer 3 if held, space if tapped
#define LAYER4  LT(4, KC_SPC)       // Activate layer 4 if held, space if tapped
#define LAYER5  LT(5, KC_RBRC)      // Activate layer 5 if held, right bracket if tapped

#define SUPER_1 LGUI(KC_1)          // Super + 1
#define SUPER_2 LGUI(KC_2)          // Super + 2
#define SUPER_3 LGUI(KC_3)          // Super + 3
#define SUPER_4 LGUI(KC_4)          // Super + 4
#define SUPER_5 LGUI(KC_5)          // Super + 5
#define SUPER_6 LGUI(KC_6)          // Super + 6
#define SUPER_7 LGUI(KC_7)          // Super + 7
#define SUPER_8 LGUI(KC_8)          // Super + 8
#define SUPER_9 LGUI(KC_9)          // Super + 9
#define SUPER_0 LGUI(KC_0)          // Super + 0

#define ALT_1   LALT(KC_1)          // Alt + 1
#define ALT_2   LALT(KC_2)          // Alt + 2
#define ALT_3   LALT(KC_3)          // Alt + 3
#define ALT_4   LALT(KC_4)          // Alt + 4
#define ALT_5   LALT(KC_5)          // Alt + 5
#define ALT_6   LALT(KC_6)          // Alt + 6
#define ALT_7   LALT(KC_7)          // Alt + 7
#define ALT_8   LALT(KC_8)          // Alt + 8
#define ALT_9   LALT(KC_9)          // Alt + 9

#define ALT_X   LALT(KC_X)          // Alt + x: mainly for Emacs

#define SSHIFT1 SGUI(KC_1)          // Super + Shift + 1
#define SSHIFT2 SGUI(KC_2)          // Super + Shift + 2
#define SSHIFT3 SGUI(KC_3)          // Super + Shift + 3
#define SSHIFT4 SGUI(KC_4)          // Super + Shift + 4
#define SSHIFT5 SGUI(KC_5)          // Super + Shift + 5
#define SSHIFT6 SGUI(KC_6)          // Super + Shift + 6
#define SSHIFT7 SGUI(KC_7)          // Super + Shift + 7
#define SSHIFT8 SGUI(KC_8)          // Super + Shift + 8
#define SSHIFT9 SGUI(KC_9)          // Super + Shift + 9
#define SSHIFT0 SGUI(KC_0)          // Super + Shift + 0

#define WKSPC11 LCAG(KC_1)          // Super + Control + Alt + 1
#define WKSPC12 LCAG(KC_2)          // Super + Control + Alt + 2
#define WKSPC13 LCAG(KC_3)          // Super + Control + Alt + 3
#define WKSPC14 LCAG(KC_4)          // Super + Control + Alt + 4
#define WKSPC15 LCAG(KC_5)          // Super + Control + Alt + 5
#define WKSPC16 LCAG(KC_6)          // Super + Control + Alt + 6
#define WKSPC17 LCAG(KC_7)          // Super + Control + Alt + 7
#define WKSPC18 LCAG(KC_8)          // Super + Control + Alt + 8
#define WKSPC19 LCAG(KC_9)          // Super + Control + Alt + 9
#define WKSPC20 LCAG(KC_0)          // Super + Control + Alt + 0

#define MVETO11 HYPR(KC_1)          // Super + Control + Alt + Shift + 1
#define MVETO12 HYPR(KC_2)          // Super + Control + Alt + Shift + 2
#define MVETO13 HYPR(KC_3)          // Super + Control + Alt + Shift + 3
#define MVETO14 HYPR(KC_4)          // Super + Control + Alt + Shift + 4
#define MVETO15 HYPR(KC_5)          // Super + Control + Alt + Shift + 5
#define MVETO16 HYPR(KC_6)          // Super + Control + Alt + Shift + 6
#define MVETO17 HYPR(KC_7)          // Super + Control + Alt + Shift + 7
#define MVETO18 HYPR(KC_8)          // Super + Control + Alt + Shift + 8
#define MVETO19 HYPR(KC_9)          // Super + Control + Alt + Shift + 9
#define MVETO20 HYPR(KC_0)          // Super + Control + Alt + Shift + 0

#define OPENST  LGUI(KC_ENT)        // Super + Enter

enum custom_keycodes {

  /* i3 macros */
  SPLHOR,
  SPLVER,
  RELOAD,
  RESTART,

  /* Emacs macros */
  OPENFIL,
  SAVEFIL,
  KILLFIL

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x5_3 (
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,
                         MO(1),  LAYER2,  LAYER3,           LAYER4,  LAYER5,    MO(6)
    ),

  [1] = LAYOUT_split_3x5_3 (
      LG_ESC, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
      LS_TAB, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
     KC_LCTL, _______, _______, _______, _______,          _______, _______, _______, _______, KC_DQUO,
                       _______, _______, KC_LCBR,          KC_RCBR, _______, KC_LCTL
    ),

  [2] = LAYOUT_split_3x5_3 (
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
     _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,           SPLHOR, _______, _______, _______, _______,
     _______, KC_VOLD, KC_MUTE, KC_VOLU, _______,          _______, _______, _______, _______, KC_PIPE,
                       _______, _______, _______,          _______, _______, _______
    ),

  [3] = LAYOUT_split_3x5_3 (
     SUPER_1, SUPER_2, SUPER_3, SUPER_4, SUPER_5,          SUPER_6, SUPER_7, SUPER_8, SUPER_9, SUPER_0,
       ALT_1,   ALT_2,   ALT_3,   ALT_4,   ALT_5,            ALT_6,   ALT_7,   ALT_8,   ALT_9, _______,
     WKSPC11, WKSPC12, WKSPC13, WKSPC14, WKSPC15,          WKSPC16, WKSPC17, WKSPC18, WKSPC19, WKSPC20,
                       _______, _______, _______,          _______, _______, _______
    ),

  [4] = LAYOUT_split_3x5_3 (
     SSHIFT1, SSHIFT2, SSHIFT3, SSHIFT4, SSHIFT5,          SSHIFT6, SSHIFT7, SSHIFT8, SSHIFT9, SSHIFT0,
     MVETO11, MVETO12, MVETO13, MVETO14, MVETO15,          MVETO16, MVETO17, MVETO18, MVETO19, MVETO20,
     _______, _______, _______,  SPLVER, _______,          _______, _______, _______, _______, _______,
                       _______, _______, _______,          _______, _______, _______
    ),

  [5] = LAYOUT_split_3x5_3 (
     KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
     _______, _______, _______, _______, _______,          KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
     _______, _______,   ALT_X, _______, _______,          _______, _______, _______, _______, KC_BSLS,
                       _______, _______, _______,          _______, _______, _______
    ),

  [6] = LAYOUT_split_3x5_3 (
     KC_TILD, _______, _______, _______, _______,          _______, _______, _______, _______, KC_BSPC,
     KC_CAPS, _______, _______, _______, _______,          _______, _______, _______, _______,  KC_ENT,
     _______, _______, _______, _______, _______,          _______, _______, _______, _______, KC_QUOT,
                       KC_LSFT, _______, KC_PGUP,          KC_PGDN, _______, _______
    ),

  [7] = LAYOUT_split_3x5_3 (
     _______, SAVEFIL, _______, RESTART, _______,          _______, _______, KC_MINS,  KC_EQL, _______,
     _______, _______, _______, OPENFIL, _______,          _______, _______, KC_UNDS, KC_PLUS, _______,
     _______, KILLFIL,  RELOAD, _______, _______,          _______, _______, _______, _______,   RESET,
                       _______, _______, _______,          _______, _______, _______
    )
};

layer_state_t layer_state_set_user (layer_state_t state) {
  return update_tri_layer_state (state, 1, 6, 7);
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master())
    return OLED_ROTATION_180;
  return rotation;
}

static void render_logo(void) {
  static const char PROGMEM qmk_logo[] = {
     0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
    0
  };
  oled_write_P(qmk_logo, false);
}                                                                                 

static void render_status(void) {
   switch (get_highest_layer(layer_state)) {
    case 0:
      oled_write_P(PSTR("0 2 3 4 5\n"), false);
      oled_write_P(PSTR("^\n"), false);
      oled_write_P(PSTR("Layer: 0\n"), false);
      break;
    case 2:
      oled_write_P(PSTR("0 2 3 4 5\n"), false);
      oled_write_P(PSTR("^\n"), false);
      oled_write_P(PSTR("Layer: 2\n"), false);
      break;
    case 3:
      oled_write_P(PSTR("0 2 3 4 5\n"), false);
      oled_write_P(PSTR("^\n"), false);
      oled_write_P(PSTR("Layer: 3\n"), false);
      break;
    case 4:
      oled_write_P(PSTR("0 2 3 4 5\n"), false);
      oled_write_P(PSTR("^\n"), false);
      oled_write_P(PSTR("Layer: 4\n"), false);
      break;
    case 5:
      oled_write_P(PSTR("0 2 3 4 5\n"), false);
      oled_write_P(PSTR("^\n"), false);
      oled_write_P(PSTR("Layer: 5\n"), false);
      break;
    default:
      oled_write_P(PSTR("0 2 3 4 5"), false);
      oled_write_P(PSTR("        ^\n"), false);
      oled_write_P(PSTR("Layer: Other\n"), false);
  }
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else {
    render_logo();
    oled_scroll_left();
  }
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    /* i3 macros */
    // Split windows horizontally in i3
    case SPLHOR:
      if (record->event.pressed) {
        //when SPLHOR is pressed
        SEND_STRING (SS_DOWN(X_LGUI)SS_DOWN(X_LCTL)SS_TAP(X_H)SS_UP(X_LCTL)SS_UP(X_LGUI));
      } else {
        //when SPLHOR is released
      }
      break;
    // Split windows vertically in i3
    case SPLVER:
      if (record->event.pressed) {
        //when SPLVER is pressed
        SEND_STRING (SS_DOWN(X_LGUI)SS_DOWN(X_LCTL)SS_TAP(X_V)SS_UP(X_LCTL)SS_UP(X_LGUI));
      } else {
        //when SPLVER is released
      }
      break;
    // Reload i3 configuration file
    case RELOAD:
      if (record->event.pressed) {
        //when RELOAD is pressed
        SEND_STRING (SS_DOWN(X_LGUI)SS_DOWN(X_LSFT)SS_TAP(X_C)SS_UP(X_LSFT)SS_UP(X_LGUI));
      } else {
        //when RELOAD is released
      }
      break;
    // Restart i3 in place
    case RESTART:
      if (record->event.pressed) {
        //when RESTART is pressed
        SEND_STRING (SS_DOWN(X_LGUI)SS_DOWN(X_LSFT)SS_TAP(X_R)SS_UP(X_LSFT)SS_UP(X_LGUI));
      } else {
        //when RESTART is released
      }
      break;

    /* Emacs macros */
    // Open file in Emacs
    case OPENFIL:
      if (record->event.pressed) {
        //when OPENFIL is pressed
        SEND_STRING (SS_DOWN(X_LCTL)SS_TAP(X_X)SS_TAP(X_F)SS_UP(X_LCTL));
      } else {
        //when OPENFIL is released
      }
      break;
    // Save file in Emacs
    case SAVEFIL:
      if (record->event.pressed) {
        //when SAVEFIL is pressed
        SEND_STRING (SS_DOWN(X_LCTL)SS_TAP(X_X)SS_TAP(X_W)SS_UP(X_LCTL));
      } else {
        //when SAVEFIL is released
      }
      break;
    // Kill file in Emacs
    case KILLFIL:
      if (record->event.pressed) {
        //when KILLFIL is pressed
        SEND_STRING (SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_TAP(X_K));
      } else {
        //when KILLFIL is released
      }
      break;

  }
  return true;
}
