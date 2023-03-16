/* Copyright 2021 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"

// clang-format off

/**********************************************************************************************************
 *                                              Combos
 **********************************************************************************************************/

// define combo names
enum combos {
    COMBO_LCTL,
    COMBO_LALT,
    COMBO_RCTL,
    COMBO_RALT,
    COMBO_BSPC,
    COMBO_LYR0,
    COMBO_LYR1,
    COMBO_LYR2,
    COMBO_LYR3,
    // more here...

    COMBO_LENGTH // nifty trick to avoid manually specifying how many combos you have
};

uint16_t COMBO_LEN = COMBO_LENGTH; // nifty trick continued

// define keys that make up combos

// Left hand
const uint16_t PROGMEM fd_combo[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM fs_combo[] = {KC_F, KC_S, COMBO_END};
// Right hand
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM jkl_combo[] = {KC_J, KC_K, KC_L, COMBO_END};
// Layers
const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM dk_combo[] = {KC_D, KC_K, COMBO_END};
const uint16_t PROGMEM sl_combo[] = {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM ascln_combo[] = {KC_A, KC_SCLN, COMBO_END};

// map combo names to their keys and the key they trigger
combo_t key_combos[] = {
    // Left hand
    [COMBO_LCTL] = COMBO(fd_combo, KC_LCTL),
    [COMBO_LALT] = COMBO(fs_combo, KC_LALT),
    // Right hand
    [COMBO_RCTL] = COMBO(jk_combo, KC_RCTL),
    [COMBO_RALT] = COMBO(jl_combo, KC_RALT),
    [COMBO_BSPC] = COMBO(jkl_combo, KC_BSPC),
    // Layers
    [COMBO_LYR0] = COMBO(fj_combo, TO(0)),
    [COMBO_LYR1] = COMBO(dk_combo, TO(1)),
    [COMBO_LYR2] = COMBO(sl_combo, TO(2)),
    [COMBO_LYR3] = COMBO(ascln_combo, TO(3)),
    // more here...
};

/**********************************************************************************************************
 *                                              Layers
 **********************************************************************************************************/

enum layers{
    LAYER_00,
    LAYER_01,
    LAYER_02,
    LAYER_03
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_00] = LAYOUT_ansi_67(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI,  KC_LALT,                             KC_SPC,                             KC_RALT,  MO(LAYER_01), MO(LAYER_02), KC_LEFT, KC_DOWN, KC_RGHT),

    [LAYER_01] = LAYOUT_ansi_67(
        KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        _______, _______,  _______,  KC_UP,   _______, _______, _______, KC_7,    KC_8,    KC_9,    _______,  _______,  _______,  _______,          _______,
        _______, _______,  KC_LEFT,  KC_DOWN, KC_RGHT, _______, _______, KC_4,    KC_5,    KC_6,    _______,  _______,            _______,          KC_END,
        _______,           _______,  _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,     _______,            _______, TO(2),
        _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, TO(0),   _______),

    [LAYER_02] = LAYOUT_ansi_67(
        KC_GRV,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,          _______,
        _______,           _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______, TO(3),
        _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, TO(1),   _______),

    [LAYER_03] = LAYOUT_ansi_67(
        _______, KC_BRID,  KC_BRIU,  KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______,  _______,            _______,          _______,
        _______,           _______,  _______, _______, _______, _______, NK_TOGG, _______, _______, _______,  _______,            _______, TO(0),
        _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, TO(2),   _______)
};


bool rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {
        case LAYER_00:
            rgb_matrix_set_color_all(0,255,255); // Cyan
            break;
        case LAYER_01:
            rgb_matrix_set_color_all(255,128,0); // Orange
            break;
        case LAYER_02:
            rgb_matrix_set_color_all(0,255,0); // Green
            break;
        case LAYER_03:
            rgb_matrix_set_color_all(255,0,255); // Magenta
            break;
        default:
            break;
    }
    return true;
}

/**********************************************************************************************************
 *                                              Encoder
 **********************************************************************************************************/

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [LAYER_00] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_01] = { ENCODER_CCW_CW(_______, _______)},
    [LAYER_02] = { ENCODER_CCW_CW(_______, _______)},
    [LAYER_03] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)}
};
#endif // ENCODER_MAP_ENABLE


/**********************************************************************************************************
 *                                              Processing
 **********************************************************************************************************/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron(keycode, record)) {
        return false;
    }
    return true;
}
