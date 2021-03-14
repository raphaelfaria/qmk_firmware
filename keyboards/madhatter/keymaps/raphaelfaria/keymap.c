/* Copyright 2019 %YOUR_NAME%
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

enum madhatter_layers {
  _BASE,
  _FUNCTION,
  _NAV
};

#define C_ESC CTL_T(KC_ESC)
#define MO_FN1 MO(_FUNCTION)

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT( /* Base */
        KC_INS,     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL, \
        KC_PGUP,    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          \
        KC_PGDN,    C_ESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           \
                    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO_FN1,           \
                    KC_LALT,          KC_LGUI,          KC_ENT,  MO(_NAV),         KC_SPC,           KC_RALT,                            KC_RCTL           \
    ),
    [_NAV] = LAYOUT(
        _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______,    _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, _______, _______,          \
        _______,    _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,          _______,          \
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          \
                    _______,          _______,          _______, _______,          _______,          _______,                            _______           \
    ),
    [_FUNCTION] = LAYOUT(
        KC_MUTE,    KC_PSCR, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, \
        KC_VOLU,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          \
        KC_VOLD,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          \
                    _______, RESET,   DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          \
                    _______,          KC_MPRV,          KC_MPLY, KC_MNXT,          _______,          _______,                            _______           \
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

/*void matrix_init_user(void) {*/

/*}*/

/*void matrix_scan_user(void) {*/

/*}*/

/*void led_set_user(uint8_t usb_led) {*/

/*}*/


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  /*debug_enable=true;*/
  /*debug_matrix=true;*/
  //debug_keyboard=true;
  //debug_mouse=true;
}
