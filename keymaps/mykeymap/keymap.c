#include QMK_KEYBOARD_H

// 🧩 Custom keycodes
enum custom_keycodes {
    CTRL_SHIFT = SAFE_RANGE,  // key khusus untuk Ctrl + Shift
};

// 🎛️ Keymap (4x4, 1 layer contoh)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_4x4(
        KC_1,     KC_2,      KC_3,      KC_4,
        KC_Q,     KC_W,      KC_E,      KC_R,
        KC_A,     KC_S,      KC_D,      KC_F,
        KC_Z,     KC_X,      CTRL_SHIFT, KC_ENT
    ),
};

// 🎚️ Encoder Map (jumlah layer harus sama dengan keymaps)
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(LCTL(KC_MINUS), LCTL(KC_EQUAL)) } // Ctrl + - / +
};
#endif

// ⚙️ Custom behavior
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTRL_SHIFT:
            if (record->event.pressed) {
                register_code(KC_LCTRL);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LCTRL);
                unregister_code(KC_LSFT);
            }
            return false;

        // Tambahan contoh tombol: Ctrl+S via rotary klik (jika ada tombol mouse)
        case KC_BTN1:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_S));
            }
            return false;
    }
    return true;
}
