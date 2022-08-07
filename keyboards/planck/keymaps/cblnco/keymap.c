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
  ADJUST,
  WIN,
  MAC,
  OS_GUI,
  OS_CTL
};

#define MOBILITY MO(_MOBILITY)
#define NUMBERS MO(_NUMBERS)
#define SYMBOLS MO(_SYMBOLS)

static bool type_os_key_events(uint8_t keycode, bool is_pressed);

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
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,   KC_Y,   KC_U,     KC_I,     KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,     KC_G,   KC_H,   KC_J,     KC_K,     KC_L,    KC_SCLN, KC_QUOT,
    KC_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,   KC_N,   KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, KC_ENT,
    KC_LSFT, KC_LALT, OS_GUI,  OS_CTL,  NUMBERS,  KC_SPC, KC_SPC, MOBILITY, KC_RCTRL, KC_RALT, KC_RGUI, KC_RSFT
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
    _______, _______, KC_VOLD, KC_UP,   KC_VOLU,  _______, _______, _______, KC_HOME, KC_UP,   KC_END,   _______,
    _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______,
    _______, KC_MUTE, _______, _______, _______,  _______, _______, _______, _______, _______, _______,  _______,
    _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,  _______
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
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, KC_1,    KC_2,    KC_3,    KC_3,    _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, KC_4,    KC_5,    KC_6,    KC_6,    _______,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_0,    KC_7,    KC_8,    KC_9,    KC_9,    _______,
    SYMBOLS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  KC_BSPC,
    _______, _______, _______, _______, KC_AMPR, KC_ASTR, _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_LSFT, _______, _______, _______, _______, _______, _______, _______
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
 * | WIN  |      |      |      |      |             |      |      |      |      | MAC  |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    WIN,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MAC
)

};

#ifdef AUDIO_ENABLE
float adjust[][2] = ADJUST_SONG;
float capslock_on[][2] = CAPSLOCK_ON_SONG;
float capslock_off[][2] = CAPSLOCK_OFF_SONG;
float win_mode[][2] = WIN_SONG;
float mac_mode[][2] = MAC_SONG;
#endif

static bool is_capslock_on = false;
static bool is_mac = false;
uint8_t keycode_os_gui = KC_LGUI;
uint8_t keycode_os_ctl = KC_LCTL;


bool type_os_key_events(uint8_t keycode, bool is_pressed) {
  if (is_pressed) {
    register_code(keycode);
  }
  else {
    unregister_code(keycode);
  }

  return false;
}

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
    case KC_CAPS:
      if (record->event.pressed) {
        is_capslock_on = !is_capslock_on;

        if (is_capslock_on) {
          #ifdef AUDIO_ENABLE
            PLAY_SONG(capslock_on);
          #endif
        } else {
          #ifdef AUDIO_ENABLE
            PLAY_SONG(capslock_off);
          #endif
        }
      }
      return true;
      break;
    case OS_GUI:
      keycode_os_gui = is_mac ? KC_LCTL : KC_LGUI;
      type_os_key_events(keycode_os_gui, record->event.pressed);
      break;
    case OS_CTL:
      keycode_os_ctl = is_mac ? KC_LGUI : KC_LCTL;
      type_os_key_events(keycode_os_ctl, record->event.pressed);
      break;
    case WIN:
      if (record->event.pressed) {
        is_mac = false;
        #ifdef AUDIO_ENABLE
          PLAY_SONG(win_mode);
        #endif
      }
      return false;
      break;
    case MAC:
      if (record->event.pressed) {
        is_mac = true;
        #ifdef AUDIO_ENABLE
          PLAY_SONG(mac_mode);
        #endif
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;
