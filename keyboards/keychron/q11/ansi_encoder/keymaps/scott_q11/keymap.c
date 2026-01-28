/* Copyright 2023 @ Keychron (https://www.keychron.com)
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
#include "config.h"


/**********************************************************************************************************
 *                                              Combos
 **********************************************************************************************************/

// define combo names
enum combos {
    COMBO_HOME,
    COMBO_REFRESH,
    COMBO_DELETE,
    COMBO_MINUS,
    COMBO_LBRC,
    COMBO_EQL,
    COMBO_END_KEY, // "COMBO_END" is already used in QMK source elsewhere
    COMBO_PLUS,
    COMBO_RBRC,
    COMBO_LYR0,
    COMBO_LYR1,
    COMBO_LYR2,
    COMBO_LYR3,

    COMBO_LENGTH // nifty trick to avoid manually specifying how many combos you have
};

uint16_t COMBO_LEN = COMBO_LENGTH; // nifty trick continued

// define keys that make up combos

// Left hand
const uint16_t PROGMEM fd_combo[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM ew_combo[] = {KC_E, KC_W, COMBO_END};
const uint16_t PROGMEM ds_combo[] = {KC_D, KC_S, COMBO_END};
const uint16_t PROGMEM vc_combo[] = {KC_V, KC_C, COMBO_END};
const uint16_t PROGMEM cx_combo[] = {KC_C, KC_X, COMBO_END};
//const uint16_t PROGMEM xz_combo[] = {KC_X, KC_Z, COMBO_END};
// Right hand
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM mcomm_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM commdot_combo[] = {KC_COMM, KC_DOT, COMBO_END};
//const uint16_t PROGMEM dotslsh_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
// Layers
const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM dk_combo[] = {KC_D, KC_K, COMBO_END};
const uint16_t PROGMEM sl_combo[] = {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM ascln_combo[] = {KC_A, KC_SCLN, COMBO_END};

// map combo names to their keys and the key they trigger
combo_t key_combos[] = {
    // Left hand
    [COMBO_DELETE]  = COMBO(fd_combo, KC_DELETE),
    [COMBO_HOME]    = COMBO(ds_combo, KC_HOME),
    [COMBO_REFRESH] = COMBO(ew_combo, KC_F5),
    [COMBO_MINUS]   = COMBO(vc_combo, KC_MINS),
    [COMBO_LBRC]    = COMBO(cx_combo, KC_LBRC),
    // Right hand
    [COMBO_EQL]     = COMBO(jk_combo, KC_EQL),
    [COMBO_END_KEY] = COMBO(kl_combo, KC_END),
    [COMBO_PLUS]    = COMBO(mcomm_combo, KC_PPLS),
    [COMBO_RBRC]    = COMBO(commdot_combo, KC_RBRC),
    // Layers
    [COMBO_LYR0]    = COMBO(fj_combo, TO(0)),
    [COMBO_LYR1]    = COMBO(dk_combo, TO(1)),
    [COMBO_LYR2]    = COMBO(sl_combo, TO(2)),
    [COMBO_LYR3]    = COMBO(ascln_combo, TO(3)),
};


/**********************************************************************************************************
 *                                              Custom Keycodes
 **********************************************************************************************************/

enum custom_keycodes_scott {
  CP_SIMP,
  PA_SIMP,
  PA_PEML,
  PA_WEML
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
    [LAYER_00] = LAYOUT_91_ansi(
        KC_MPLY,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_HOME,  KC_END,   KC_MUTE,
        CP_SIMP,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        PA_SIMP,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_DEL,
        _______,  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        KC_ENT,   KC_LCTL,  KC_LWIN,  KC_LALT,  MO(LAYER_01),       KC_BSPC,                       KC_SPC,             KC_RALT,  MO(LAYER_01),KC_RCTL, KC_LEFT,  KC_DOWN,  KC_RGHT),

    [LAYER_01] = LAYOUT_91_ansi(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  KC_PGUP,  KC_UP,    KC_PGDN,  _______,   _______,  KC_7,     KC_8,     KC_9,     _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,   _______,  KC_4,     KC_5,     KC_6,     _______,  _______,              _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  _______,  KC_1,     KC_2,     KC_3,     _______,              _______,  TO(2),
        _______,  _______,  _______,  _______,  _______,            KC_SPC,                        KC_0,               KC_DOT,   _______,    _______,  _______,  TO(0),    _______),

    [LAYER_02] = LAYOUT_91_ansi(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  PA_WEML,  _______,  _______,  _______,   _______,  _______,  _______,  PA_PEML,  _______,  _______,              _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,              _______,  TO(3),
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  TO(1),    _______),

    [LAYER_03] = LAYOUT_91_ansi(
        RM_TOGG,  _______,  KC_BRID,  KC_BRIU,  _______,  _______,  _______,   _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  RM_TOGG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,   _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  TO(0),
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  TO(2),    _______)
};


/**********************************************************************************************************
 *                                              Encoder
 **********************************************************************************************************/

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_00] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [LAYER_01] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [LAYER_02] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [LAYER_03] = { ENCODER_CCW_CW(RM_NEXT, RM_PREV), ENCODER_CCW_CW(RM_NEXT, RM_PREV) }
};
#endif // ENCODER_MAP_ENABLE

/**********************************************************************************************************
 *                                              Processing
 **********************************************************************************************************/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        case CP_SIMP:  // Simple copy to clipboard.
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("c"));
            }
            break;

        case PA_SIMP:  // Simple paste from clipboard.
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("v"));
            }
            break;

        case PA_PEML:  // Paste personal email
            if (record->event.pressed) {
                SEND_STRING("this.is.scotts.email.address@gmail.com");
            }
            break;

        case PA_WEML:  // Paste work email
            if (record->event.pressed) {
                SEND_STRING("scottmorgan@chevron.com");
            }
            break;
    }

    return true;
}

/**********************************************************************************************************
 *                                              Custom RGB
 **********************************************************************************************************/

// Use a bool to determine whether to show default RGB or custom colours based on layer
bool custom_layer_rgb = false;

// Set bool depending on state of Windows/Mac switch
bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if(active) {
                dprint("Dip switch active\n");
                custom_layer_rgb = true;
            } else {
                dprint("Dip switch not active\n");
                custom_layer_rgb = false;
            }
            break;
    }
    return true;
}

// Display custom RGB colours per layer if the custom mode is selected
bool rgb_matrix_indicators_user(void) {
    if (custom_layer_rgb == true) {
        switch (get_highest_layer(layer_state)) {
            case LAYER_00:
                rgb_matrix_set_color_all(0,255,255); // Cyan
                break;

            case LAYER_01:
                rgb_matrix_set_color_all(255,128,0); // Orange
                if (is_keyboard_master()) {
                    rgb_matrix_set_color(19,0,255,0);
                    rgb_matrix_set_color(25,0,255,0);
                    rgb_matrix_set_color(26,0,255,0);
                    rgb_matrix_set_color(27,0,255,0);
                } else {
                    rgb_matrix_set_color(59,0,255,0);
                    rgb_matrix_set_color(60,0,255,0);
                    rgb_matrix_set_color(61,0,255,0);
                    rgb_matrix_set_color(68,0,255,0);
                    rgb_matrix_set_color(69,0,255,0);
                    rgb_matrix_set_color(70,0,255,0);
                    rgb_matrix_set_color(76,0,255,0);
                    rgb_matrix_set_color(77,0,255,0);
                    rgb_matrix_set_color(78,0,255,0);
                    rgb_matrix_set_color(82,0,255,0);
                    rgb_matrix_set_color(83,0,255,0);
                }
                break;

            case LAYER_02:
                rgb_matrix_set_color_all(0,255,0); // Green
                break;

            case LAYER_03:
                rgb_matrix_set_color_all(255,0,255); // Magenta
                for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
                    for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                        uint8_t index = g_led_config.matrix_co[row][col];
                        uint8_t led_min = 0;
                        uint8_t led_max = 88;

                        if (index >= led_min && index < led_max && index != NO_LED &&
                        keymap_key_to_keycode(LAYER_03, (keypos_t){col,row}) > KC_TRNS) {
                            rgb_matrix_set_color(index, RGB_CYAN);
                        }
                    }
                }
                break;

            default:
                break;
        }
    }
    return true;
}


/**********************************************************************************************************
 *                                              Sync
 **********************************************************************************************************/
#include <transactions.h>

// Package up send/receive data in structs
typedef struct _master_to_slave_t {
    bool m2s_data;
} master_to_slave_t;

typedef struct _slave_to_master_t {
    bool s2m_data;
} slave_to_master_t;

// This function is called by the slave only.
void user_sync_a_slave_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    const master_to_slave_t *m2s = (const master_to_slave_t*)in_data;
    slave_to_master_t *s2m = (slave_to_master_t*)out_data;
    s2m->s2m_data = m2s->m2s_data; // update to match master data

    // Any variables being used by the master need to be updated for mirror functionality
    custom_layer_rgb = s2m->s2m_data;
}

void housekeeping_task_user(void) {
    if (is_keyboard_master()) {
        static uint32_t last_sync = 0;

        // Interact with slave every X ms
        if (timer_elapsed32(last_sync) > 500) {
            master_to_slave_t m2s = {custom_layer_rgb};
            slave_to_master_t s2m = {false};
            if(transaction_rpc_exec(USER_SYNC_A, sizeof(m2s), &m2s, sizeof(s2m), &s2m)) {
                last_sync = timer_read32();
                dprintf("Timer check B: %ld\tSlave value: %d\n", last_sync, s2m.s2m_data);
            } else {
                dprint("Slave sync failed!\n");
            }
        }
    }
}

/**********************************************************************************************************
 *                                              Debugging
 **********************************************************************************************************/

void keyboard_post_init_user(void) {
    //   Customise these values to desired behaviour
    //   debug_enable=true;
    //   debug_matrix=true;
    //   debug_keyboard=true;
    //   debug_mouse=true;

    // Sync data between master and slave
    transaction_register_rpc(USER_SYNC_A, user_sync_a_slave_handler);
}
