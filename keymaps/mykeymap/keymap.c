#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {
        ENCODER_CCW_CW(KC_LBRC, KC_RBRC), // Encoder kiri: [ dan ]
    },
};
#endif
