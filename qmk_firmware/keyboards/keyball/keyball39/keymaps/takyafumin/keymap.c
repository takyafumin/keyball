/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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
#include <stdint.h>
#include <stdbool.h>

#include QMK_KEYBOARD_H

#include "quantum.h"

// keymap layer number
enum keymap_layer {
    _BASE  = 0,
    _MARK  = 1,
    _NUMS  = 2,
    _EXTRA = 3,
    _BALL  = 4,
};

enum custom_keycodes {
    MAC_PRSC = SAFE_RANGE,
    MY_SCRL,
};

// --------------------
// キーのalias
// --------------------
// basic
#define DEL      KC_DEL

// modifier
#define S_SPC    LSFT_T(KC_SPC)
#define S_ENT    LSFT_T(KC_ENT)
#define S_BS     LSFT_T(KC_BSPC)
#define MT_ESC   LT(_NUMS, KC_ESC)

// home mod key left
#define MT_F    LSFT_T(KC_F)
#define MT_D    RALT_T(KC_D)
#define MT_S    LGUI_T(KC_S)
#define MT_A    LCTL_T(KC_A)
#define MT_Z    LSFT_T(KC_Z)

// home mod key right
#define MT_J    RSFT_T(KC_J)
#define MT_K    RALT_T(KC_K)
#define MT_L    RGUI_T(KC_L)
#define MT_MINS RCTL_T(KC_MINS)
#define MT_SLSH LSFT_T(KC_SLSH)

// Layer
#define LT_EN    LT(_MARK, KC_LNG2)
#define LT_JP    LT(_NUMS, KC_LNG1)
#define BALL     MO(_BALL)
#define EXT0     LT(_EXTRA, KC_0)
#define EXTTAB   LT(_EXTRA, KC_TAB)

// --------------------
// keymap
// --------------------
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [_BASE] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    MT_A     , MT_S     , MT_D     , MT_F     , KC_G     ,                            KC_H     , MT_J     , MT_K     , MT_L     , MT_MINS  ,
    MT_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_N     , KC_M     , KC_COMM  , KC_DOT   , MT_SLSH  ,
    BALL     , MY_SCRL  , MY_SCRL  , MT_ESC   , LT_EN    , S_SPC    ,      S_ENT    , LT_JP    , XXXXXXX  , XXXXXXX  , XXXXXXX  , BALL
  ),

  [_MARK] = LAYOUT_universal(
    KC_EXLM  , KC_AT    , KC_HASH  , KC_DLR   , KC_PERC   ,                           KC_CIRC  , KC_AMPR  , KC_ASTR  , KC_LPRN  ,  KC_RPRN  ,
    KC_TAB   , _______  , KC_PIPE  , KC_COLN  , KC_SCLN   ,                           KC_LEFT  , KC_DOWN  , KC_UP    , KC_RIGHT ,  KC_UNDS  ,
    _______  , _______  , KC_BSLS  , KC_TILD  , KC_GRV    ,                           KC_EQL   , KC_QUOT  , KC_LT    , KC_GT    ,  KC_QUES  ,
    _______  , _______  , _______  , _______  , _______   , _______  ,     S_BS     , EXTTAB   , XXXXXXX  , XXXXXXX  , XXXXXXX  ,  DEL
  ),

  [_NUMS] = LAYOUT_universal(
    KC_1     , KC_2     , KC_3     , KC_4     , KC_5      ,                           KC_6     , KC_7     , KC_8     , KC_9     ,  KC_0     ,
    XXXXXXX  , XXXXXXX  , KC_LBRC  , KC_RBRC  , XXXXXXX   ,                           XXXXXXX  , KC_4     , KC_5     , KC_6     ,  _______  ,
    XXXXXXX  , XXXXXXX  , KC_LCBR  , KC_RCBR  , XXXXXXX   ,                           KC_EQL   , KC_1     , KC_2     , KC_3     ,  _______  ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , EXT0      , _______  ,     S_BS     , EXT0     , XXXXXXX  , XXXXXXX  , XXXXXXX  ,  XXXXXXX
  ),

  [_EXTRA] = LAYOUT_universal(
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5     ,                           KC_F6    , KC_F7    , KC_F8    , KC_F9    ,  KC_F10   ,
    KC_CAPS  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX   ,                           KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   ,  XXXXXXX  ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX   ,                           KC_PSCR  , KC_F11   , KC_F12   , XXXXXXX  ,  XXXXXXX  ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX   , XXXXXXX  ,     XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,  XXXXXXX
  ),

  [_BALL] = LAYOUT_universal(
    RGB_TOG  , _______  , KC_WH_D  , KC_WH_U  ,  _______  ,                           _______  , KC_WH_U  , KC_WH_D  , SCRL_DVD , SCRL_DVI ,
    KC_LCTL  , KC_LGUI  , KC_RALT  , KC_LSFT  ,  _______  ,                           KC_BTN4  , KC_BTN1  , KC_BTN2  , KC_BTN5  , KC_LCTL  ,
    _______  , _______  , SCRL_DVI , SCRL_DVD ,  _______  ,                           CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    _______  , _______  , _______  , _______  ,  SCRL_MO  , _______  ,     _______  , _______  , _______  , _______  , _______  ,  _______
  ),
  //[_BALL] = LAYOUT_universal(
  //  //|---------------------------------------------------.                         ,------------------------------------------------------.
  //  RGB_TOG  , _______  , _______  , _______  ,  _______  ,                           _______  , SCRL_DVD , SCRL_DVI , _______  , _______  ,
  //  KC_LCTL  , KC_BTN4  , KC_BTN2  , KC_BTN1  ,  KC_BTN5  ,                           KC_WH_L  , KC_WH_D  , KC_WH_U  , KC_WH_R  , KC_LCTL  ,
  //  _______  , _______  , KC_BTN4  , KC_BTN5  ,  SCRL_DVD ,                           CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
  //  //|---------------------------------------------------.                         ,------------------------------------------------------.
  //  _______  , _______  , _______  , _______  ,  MY_SCRL  , _______  ,     _______  , _______  , _______  , _______  , _______  ,  _______
  //),
  //KC_CAPS  , XXXXXXX  , QK_RBT   , EE_CLR   , QK_BOOT   ,                           KC_PSCR  , KC_F11   , KC_F12   , XXXXXXX  ,  XXXXXXX  ,
  //[_EXTRA] = LAYOUT_universal(
  //  RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  ,                            _______  , _______  , SSNP_HOR , SSNP_VRT , SSNP_FRE ,
  //  RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , SCRL_DVI ,                            _______  , _______  , _______  , _______  , _______  ,
  //  RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , SCRL_DVD ,                            CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
  //  QK_BOOT  , KBC_RST  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , KBC_RST  , QK_BOOT
  //),

};
// clang-format on


// --------------------
// クリック時イベント
// --------------------
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case MY_SCRL:
          if (record->event.pressed) {
            keyball_set_scroll_mode(true);
          } else {
            keyball_set_scroll_mode(false);
          }
          return false;
          break;
    }

    return true;
}
