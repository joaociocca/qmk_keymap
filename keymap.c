#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _AUX,
    _SYMBLS,
    _FUNCS,
    _NUMPAD
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _AUX:
            oled_write_P(PSTR("FN\n"), false);
            break;
        case _SYMBLS:
            oled_write_P(PSTR("ADJ\n"), false);
            break;
        case _FUNCS:
            oled_write_P(PSTR("ADJ\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("ADJ\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
    return false;
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [0] = LAYOUT_split_3x6_3(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, SC_RCPC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, SC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC, KC_LGUI, LT(1,KC_LBRC), KC_SPC, KC_ENT, LT(2,KC_NO), KC_RALT),
        [1] = LAYOUT_split_3x6_3(KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_LCTL, KC_NO, KC_NO, KC_INS, KC_HOME, KC_PGUP, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_LSFT, KC_TAB, KC_LALT, KC_DEL, KC_END, KC_PGDN, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TG(4), KC_LGUI, KC_TRNS, KC_APP, KC_ENT, MO(3), KC_RALT),
        [2] = LAYOUT_split_3x6_3(LALT(KC_TAB), KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, LSA(KC_TAB), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV, KC_LSFT, KC_NUBS, KC_INT1, KC_NO, KC_NO, KC_NO, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD, KC_LGUI, MO(3), KC_SPC, KC_ENT, KC_TRNS, KC_RALT),
        [3] = LAYOUT_split_3x6_3(QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_NO, KC_VOLU, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO, KC_MPLY, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO, KC_VOLD, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_NO, KC_MNXT, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_MUTE, KC_LGUI, KC_TRNS, KC_SPC, KC_ENT, KC_TRNS, KC_RALT),
        [4] = LAYOUT_split_3x6_3(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P7, KC_P8, KC_P9, KC_PSLS, KC_PAST, KC_BSPC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_PPLS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P1, KC_P2, KC_P3, KC_PCMM, KC_PDOT, TG(4), KC_NO, KC_NO, KC_PENT, KC_P0, KC_NO, KC_NO)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)