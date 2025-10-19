#ifdef ENCODER_MAP_ENABLE
// 🌀 Rotary encoder (putaran)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    // Layer 0 → Ctrl + - dan Ctrl + +
    [0] = { ENCODER_CCW_CW(LCTL(KC_MINUS), LCTL(KC_EQUAL)) },
    // Layer lain tetap transparan
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif


// 🧩 Custom keycode
enum custom_keycodes {
    CTRL_SHIFT = SAFE_RANGE,  // tombol khusus Ctrl + Shift bersamaan
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        // 🌀 Klik Rotary → Ctrl + S
        case MS_BTN1:  // gunakan MS_BTN1, bukan KC_BTN1
            if (record->event.pressed) {
                tap_code16(LCTL(KC_S));  // Tekan Ctrl+S saat rotary ditekan
            }
            return false; // hentikan, jangan diteruskan ke QMK default


        // ⚡ Tombol khusus Ctrl + Shift bersamaan
        case CTRL_SHIFT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            return false; // jangan kirim key lain

    }
    return true;
}
