#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(LCTL(KC_MINUS), LCTL(KC_EQUAL)) },  // Ctrl + - dan Ctrl + +
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // tambahkan keycode khusus untuk tombol encoder click
        case KC_BTN1:  // jika tombol rotary terdaftar sebagai KC_BTN1
            if (record->event.pressed) {
                tap_code16(LCTL(KC_S));  // tekan Ctrl+S
            }
            return false; // jangan teruskan ke QMK
    }
    return true;
}
