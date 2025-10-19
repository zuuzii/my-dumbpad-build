#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_LBRC, KC_RBRC) },  // Layer 0 → [ dan ]
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },  // Layer 1 → tidak berubah
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },  // Layer 2 → tidak berubah
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },  // Layer 3 → tidak berubah
};
#endif
