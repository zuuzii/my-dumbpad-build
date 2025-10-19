#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(LCTL(KC_MINUS), LCTL(KC_EQUAL)) },  // Ctrl + - dan Ctrl + +
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif

// 🧩 Tambahkan custom keycode di sini
enum custom_keycodes {
    CTRL_SHIFT = SAFE_RANGE,  // key khusus untuk Ctrl + Shift
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        // 🌀 Klik Rotary = Ctrl + S
        case KC_BTN1:  // jika tombol rotary terdaftar sebagai KC_BTN1
            if (record->event.pressed) {
                tap_code16(LCTL(KC_S));  // tekan Ctrl+S
            }
            return false; // hentikan di sini (tidak diteruskan ke QMK)

        // ⚡ Tombol khusus Ctrl + Shift bersamaan
        case CTRL_SHIFT:
            if (record->event.pressed) {
                register_code(KC_LCTRL);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LCTRL);
                unregister_code(KC_LSFT);
            }
            return false; // jangan kirim key lain

    }
    return true;
}
