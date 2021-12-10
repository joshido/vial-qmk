/* Copyright 2021 CapsUnlocked
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
                    KC_MPLY,
    KC_MPRV,        KC_MPLY,        KC_MNXT,
    KC_F13,         KC_F14,         MO(3)
  ),
  [1] = LAYOUT(
                    KC_MPLY,
    KC_HOME,        KC_UP,          KC_END,
    KC_LEFT,        KC_DOWN,        LT(3, KC_RGHT)
  ),
  [2] = LAYOUT(
                    KC_MPLY,
    C(S(KC_C)),     C(S(KC_R)),     KC_F6,
    C(KC_PAUS),     S(KC_F5),       LT(3, KC_F5)
  ),
  [3] = LAYOUT(
                    RESET,
    DF(0),          DF(1),          DF(2),
    C(S(KC_F13)),   C(S(KC_F14)),   _______
  )
};

const rgblight_segment_t PROGMEM _layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 6, HSV_AZURE}, {2, 1, HSV_GREEN}, {3, 1, HSV_GREEN});
const rgblight_segment_t PROGMEM _layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 6, HSV_AZURE}, {1, 1, HSV_GREEN}, {4, 1, HSV_GREEN});
const rgblight_segment_t PROGMEM _layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 6, HSV_AZURE}, {0, 1, HSV_GREEN}, {5, 1, HSV_GREEN});

const rgblight_segment_t* const PROGMEM _rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  _layer1_layer,
  _layer2_layer,
  _layer3_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = _rgb_layers;
    rgblight_set_layer_state(0, 1);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    dprintf("layer changed %s", state);
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    return state;
}

