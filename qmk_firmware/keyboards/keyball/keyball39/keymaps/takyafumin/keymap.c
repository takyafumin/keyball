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

#include QMK_KEYBOARD_H

#include "quantum.h"

// keymap layer number
enum keymap_layer {
    _BASE  = 0,
    _LEFT  = 1,
    _RIGHT = 2,
    _EXTRA = 3,
    _LBALL = 4,
};

enum custom_keycodes {
    MAC_PRSC = SAFE_RANGE,
    MY_SCRL,
};

// --------------------
// キーのalias
// --------------------
// basic
#define SPC      KC_SPC
#define ESC      KC_ESC
#define ENT      KC_ENT
#define BS       KC_BSPC
#define DEL      KC_DEL
#define JP       KC_LNG1
#define EN       KC_LNG2

// modifier
#define S_SPC    LSFT_T(SPC)
#define S_ENT    LSFT_T(ENT)
#define S_BS     LSFT_T(BS)
#define GUIESC   LGUI_T(ESC)

// home mod key left
#define SFT_F    LSFT_T(KC_F)
#define ALT_D    RALT_T(KC_D)
#define GUI_S    LGUI_T(KC_S)
#define CTL_A    LCTL_T(KC_A)
#define SFT_Z    LSFT_T(KC_Z)

// home mod key right
#define SFT_J    LSFT_T(KC_J)
#define ALT_K    RALT_T(KC_K)
#define GUI_L    LGUI_T(KC_L)
#define CTLSCN   RCTL_T(KC_SCLN)
#define SFTSLSH  LSFT_T(KC_SLSH)

// Layer
#define LT_EN    LT(_LEFT, EN)
#define RT_JP    LT(_RIGHT, JP)
#define BALL     MO(_LBALL)
#define EXT0     LT(_EXTRA, KC_0)
#define EXTTAB   LT(_EXTRA, KC_TAB)

// OSM/OSL
#define OSM_SFT  OSM(MOD_LSFT)
#define OSM_CTL  OSM(MOD_LCTL)
#define OSM_ALT  OSM(MOD_LALT)
#define OSM_GUI  OSM(MOD_LGUI)

// --------------------
// custom keyterms
// --------------------
// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//
//     case ALT_D:
//     case ALT_K:
//     case GUI_S:
//     case GUI_L:
//       return TAPPING_TERM + 100;
//
//     default:
//       return TAPPING_TERM;
//   }
// }

// --------------------
// keymap
// --------------------
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [_BASE] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    CTL_A    , GUI_S    , ALT_D    , SFT_F    , KC_G     ,                            KC_H     , SFT_J    , ALT_K    , GUI_L    , CTLSCN   ,
    SFT_Z    , KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_N     , KC_M     , KC_COMM  , KC_DOT   , SFTSLSH  ,
    //|---------------------------------------------------.                         ,------------------------------------------------------.
    BALL     , XXXXXXX  , XXXXXXX  , GUIESC   , LT_EN    , S_SPC    ,      S_ENT    , RT_JP    , XXXXXXX  , XXXXXXX  , XXXXXXX  , BALL
  ),

  [_LEFT] = LAYOUT_universal(
    KC_1     , KC_2     , KC_3     , KC_4     , KC_5      ,                           KC_6     , KC_7     , KC_8     , KC_9     ,  KC_0     ,
    OSM_CTL  , OSM_GUI  , OSM_ALT  , OSM_SFT  , KC_BSLS   ,                           KC_LEFT  , KC_DOWN  , KC_UP    , KC_RIGHT ,  KC_COLN  ,
    KC_LSFT  , XXXXXXX  , XXXXXXX  , XXXXXXX  , KC_PIPE   ,                           KC_EQL   , KC_MINS  , KC_LT    , KC_GT    ,  KC_QUES  ,
    //|---------------------------------------------------.                         ,------------------------------------------------------.
    _______  , _______  , _______  , _______  , _______   , _______  ,     S_BS     , EXTTAB   , XXXXXXX  , XXXXXXX  , XXXXXXX  ,  DEL
  ),

  [_RIGHT] = LAYOUT_universal(
    KC_1     , KC_2     , KC_3     , KC_4     , KC_5      ,                           KC_6     , KC_7     , KC_8     , KC_9     ,  KC_0     ,
    KC_GRV   , KC_QUOT  , KC_LBRC  , KC_RBRC  , KC_BSLS   ,                           XXXXXXX  , OSM_SFT  , OSM_ALT  , OSM_GUI  ,  OSM_CTL  ,
    KC_TILD  , KC_DQT   , KC_LCBR  , KC_RCBR  , KC_PIPE   ,                           XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,  KC_LSFT  ,
    //|---------------------------------------------------.                         ,------------------------------------------------------.
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , EXT0      , _______  ,     _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,  XXXXXXX
  ),

  [_EXTRA] = LAYOUT_universal(
    //|---------------------------------------------------.                         ,------------------------------------------------------.
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5     ,                           KC_F6    , KC_F7    , KC_F8    , KC_F9    ,  KC_F10   ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX   ,                           KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   ,  KC_PSCR  ,
    KC_CAPS  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX   ,                           KC_PSCR  , KC_F11   , KC_F12   , XXXXXXX  ,  XXXXXXX  ,
    //|---------------------------------------------------.                         ,------------------------------------------------------.
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX   , XXXXXXX  ,     XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,  XXXXXXX
  ),

  [_LBALL] = LAYOUT_universal(
    //|---------------------------------------------------.                         ,------------------------------------------------------.
    RGB_TOG  , _______  , _______  , _______  ,  _______  ,                           _______  , SCRL_DVD , SCRL_DVI , _______  , _______  ,
    KC_LCTL  , KC_BTN4  , KC_BTN2  , KC_BTN1  ,  KC_BTN5  ,                           KC_WH_R  , KC_WH_U  , KC_WH_D  , KC_WH_L  , KC_LCTL  ,
    _______  , _______  , KC_BTN4  , KC_BTN5  ,  SCRL_DVD ,                           CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    //|---------------------------------------------------.                         ,------------------------------------------------------.
    _______  , _______  , _______  , _______  ,  MY_SCRL  , _______  ,     _______  , _______  , _______  , _______  , _______  ,  _______
  ),
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
    // Left Ctrlが押されているか
    bool lctrl = keyboard_report->mods & MOD_BIT(KC_LCTL);

    switch (keycode) {

        // Ctrl + j = Enter
        case SFT_J:
            if (record->event.pressed) {
                if (lctrl) {
                    unregister_code(KC_LCTL);
                    tap_code(KC_ENT);
                    register_code(KC_LCTL);
                    return false;
                }
            }
            break;

        // Ctrl + h = Backspace
        case KC_H:
            if (record->event.pressed) {
                if (lctrl) {
                    unregister_code(KC_LCTL);
                    tap_code(KC_BSPC);
                    register_code(KC_LCTL);
                    return false;
                }
            }
            break;

        // MAC_PRSC
        case MAC_PRSC:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LGUI);
                tap_code(KC_4);
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
            }
            return false;
            break;

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

// --------------------
// QUICK_TAP_TERM
// --------------------
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT_EN:
    case RT_JP:
      // レイヤー切り替えの場合はQUICK_TAP_TERMを無効にする
      return 0;
    default:
      return QUICK_TAP_TERM;
  }
}

// --------------------
// レイヤー切り替え時のRGB設定
// --------------------
// layer_state_t layer_state_set_user(layer_state_t state) {
//   // 現在のレイヤーを変更前のレイヤーとして保持
//   previous_layer = current_layer;
//
//   // 現在のレイヤーを更新
//   current_layer = biton32(state);
//
//   switch (current_layer) {
//     case _BASE:
//       rgblight_sethsv(HSV_OFF);
//       break;
//     case _LEFT:
//       rgblight_sethsv(HSV_CYAN);
//       break;
//     case _RIGHT:
//       rgblight_sethsv(HSV_BLUE);
//       break;
//     case _EXTRA:
//       rgblight_sethsv(HSV_GREEN);
//       break;
//     case _NUMS:
//       rgblight_sethsv(HSV_GREEN);
//       break;
//     case _LBALL:
//       rgblight_sethsv(HSV_PURPLE);
//       break;
//   }
//
//   return state;
// }

