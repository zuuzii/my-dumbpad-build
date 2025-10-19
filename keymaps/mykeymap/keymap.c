#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(LCTL(KC_MINUS), LCTL(KC_EQUAL)) },  // Ctrl + - dan Ctrl + +
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },  // Layer 1 → tidak berubah
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },  // Layer 2 → tidak berubah
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },  // Layer 3 → tidak berubah
};
#endif
bool encoder_button_pressed(uint8_t index, bool pressed) {
    if (pressed && index == 0) {  // encoder pertama ditekan
        tap_code16(LCTL(KC_S));   // Ctrl + S
    }
    return false;
}
