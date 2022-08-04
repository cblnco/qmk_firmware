/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _MOBILITY,
  _NUMBERS,
  _SYMBOLS,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  MOBILITY,
  NUMBERS,
  SYMBOLS,
  ADJUST
};

#define MOBILITY MO(_MOBILITY)
#define NUMBERS MO(_NUMBERS)
#define SYMBOLS MO(_SYMBOLS)
#define FUNCTION MO(_FUNCTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Sft  | GUI  | Alt  | Ctrl | NUMB |    Space    | MOB  | Ctrl | Alt  | Sys  | Sft  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,     KC_P,     KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,     KC_G,   KC_H,   KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,
    LSFT_T(KC_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  KC_ENT ,
    SYMBOLS, KC_LALT, KC_LGUI, KC_LCTL, NUMBERS, KC_SPC, KC_SPC, MOBILITY, KC_RCTRL, KC_RALT, KC_RGUI,  KC_RSFT
),

/* Mobility
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  | VolD |   Up | VolU |   T  |   Y  | Home |  Up  |  End |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  | Left | Down | Rght |   (  |   )  | Left | Down | Right|   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |   Z  |   X  |   C  |   [  |   {  |   }  |   ]  |  Del |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Sft  | GUI  | Ctrl | Alt  |   ▽  |    Space    | MOB  | Alt  | Sft  | Ctrl | SYMB |
 * `-----------------------------------------------------------------------------------'
 */
[_MOBILITY] = LAYOUT_planck_grid(
    KC_ESC,  KC_VOLD, KC_UP,   KC_VOLU,  KC_R,    KC_T,   KC_Y,   KC_U,     KC_HOME,  KC_UP,   KC_END,   KC_BSPC,
    KC_TAB,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_F,    KC_G,   KC_H,   KC_J,     KC_LEFT,  KC_DOWN, KC_RIGHT, KC_QUOT,
    LSFT_T(KC_CAPS), KC_MUTE, KC_X,    KC_C,     KC_V,    KC_B,   KC_N,   KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_ENT ,
    SYMBOLS, KC_LALT, KC_LGUI, KC_LCTL,  NUMBERS, KC_SPC, KC_SPC, KC_TRNS, KC_RCTRL, KC_RALT, KC_RGUI,  KC_RSFT
),

/* Numbers / Functions
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   1  |   2  |   3  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   4  |   5  |   6  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |   Z  |   X  |   C  |   V  |   [  |   ]  |   7  |   8  |   9  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Sft  | GUI  | Ctrl | Alt  | NUMB |    Space    |   ▽  | Alt  |  Sft | Ctrl | SYMB |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBERS] = LAYOUT_planck_grid(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_T,   KC_Y,   KC_U,     KC_1,     KC_2,    KC_3,    KC_BSPC,
    KC_TAB,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_G,   KC_H,   KC_J,     KC_4,     KC_5,    KC_6,    KC_QUOT,
    LSFT_T(KC_CAPS), KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_B,   KC_N,   KC_0,     KC_7,     KC_8,    KC_9,    KC_ENT ,
    SYMBOLS, KC_LALT, KC_LGUI, KC_LCTL, KC_TRNS, KC_SPC, KC_SPC, MOBILITY, KC_RCTRL, KC_RALT, KC_RGUI, KC_RSFT
),

/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |  _-  |  +=  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |  `~  |   |\ |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  DEL |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Sft  | GUI  | Ctrl | Alt  | NUMB |    Space    | MOB  | Alt  | Sft  | Ctrl |   ▽  |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOLS] = LAYOUT_planck_grid(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  KC_CIRC,   KC_LPRN, KC_RPRN,    KC_MINS,     KC_EQL,     KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_AMPR, KC_ASTR, KC_H,   KC_LCBR, KC_RCBR,    KC_LBRC,  KC_RBRC,  KC_BSLASH,
    LSFT_T(KC_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  KC_ENT ,
    KC_TRNS, KC_LALT, KC_LGUI, KC_LCTL, NUMBERS, KC_SPC,  KC_SPC, MOBILITY, KC_RCTRL, KC_RALT, KC_RGUI,  KC_RSFT
),

/* Adjust (Lower + Raise)
 * Swap GUI keys (Win/macOS)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | SWAP |      |      |      |      |             |      |      |      |      | NORM |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, _______,   _______,   _______, _______, _______, _______, _______, _______,  _______, _______, _______ ,
    _______, _______, _______,  _______,   _______,  _______, _______, _______,  _______,  _______,  _______,  _______,
    _______, _______,  _______,  _______,   _______,  _______,   _______,  _______, _______, _______, _______, _______,
    LCG_NRM, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, LCG_SWP
)

};

#ifdef AUDIO_ENABLE
float adjust[][2] = ADJUST_SONG;
float lcg_norm[][2] = LCG_NORM_SONG;
float lcg_swap[][2] = LCG_SWAP_SONG;
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  static bool is_adjust_on = false;
  layer_state_t newState = update_tri_layer_state(state, _NUMBERS, _MOBILITY, _ADJUST);

  is_adjust_on = layer_state_cmp(newState, _ADJUST);

  if (is_adjust_on) {
    #ifdef AUDIO_ENABLE
      PLAY_SONG(adjust);
    #endif
  }

  return newState;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case AG_NORM:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(lcg_norm);
        #endif
      }
      return true;
      break;
    case AG_SWAP:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(lcg_swap);
        #endif
      }
      return true;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;
