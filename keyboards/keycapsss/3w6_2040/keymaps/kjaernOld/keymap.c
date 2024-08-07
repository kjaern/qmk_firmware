// Highly inspired by
// https://www.youtube.com/watch?v=8wZ8FRwOzhU
// https://github.com/benvallack/34-QMK-Ferris-Sweep
//
// also great resourse collection made by Folke:
// https://github.com/folke/zmk-config

#include QMK_KEYBOARD_H
#include "keymap_danish.h"
enum layers {
    _ALPHA = 0,
    _SYM,
    _NAV,
    _NUM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    //  NOOB HERE, need the docs link close by
    //      https://docs.qmk.fm/keycodes_basic
    //      https://github.com/qmk/qmk_firmware/blob/master/docs/feature_layers.md
    //
    //      OSM    One Shot Keys https://github.com/qmk/qmk_firmware/blob/master/docs/one_shot_keys.md
    //      MT     Mod-Taps      https://docs.qmk.fm/mod_tap#caveats
    //      MO   momentarily activates layer
    //


    [_ALPHA] = LAYOUT_split_3x5_3(
        KC_Q,         KC_W,    KC_E,                KC_R,                  KC_T,                        KC_Y,    KC_U,                  KC_I,                KC_O,    KC_P, //MT(DK_ARNG,KC_P),
        KC_A,         KC_S,    MT(MOD_LALT,KC_D),   MT(MOD_LGUI, KC_F),    KC_G,                        KC_H,    MT(MOD_RGUI, KC_J),    MT(MOD_RALT, KC_K),  KC_L,    KC_ENT, // MT(DK_AE,KC_ENT),
        KC_Z,         KC_X,    KC_C,                KC_V,                  KC_B,                        KC_N,    KC_M,                  KC_COMM,             KC_DOT,  KC_SLSH, //MT(DK_OSTR, KC_SLSH),
                             KC_LALT, KC_SPC, OSM(MOD_LSFT),                MO(_SYM), KC_BSPC,   OSM(MOD_RCTL)
    ),
    [_SYM] = LAYOUT_split_3x5_3(
        KC_EXCLAIM,       KC_QUOTE,  KC_AT,   KC_DLR, KC_TILD,                                KC_AMPR, KC_EXLM, KC_PIPE, KC_UNDS, KC_HASH,
        KC_TAB,     KC_LBRC,  MT(MOD_LALT, KC_LCBR), KC_LPRN,  KC_EQL,                                KC_ASTR, KC_RPRN, KC_RCBR, KC_RBRC, KC_BSLS,
        KC_ESC,     KC_QUES,  KC_PLUS, KC_PERC, XXXXXXX,                                DK_AE, XXXXXXX, KC_MINS, TO(_NAV), TO(_NUM),
                             KC_LALT,  TO(_ALPHA),  OSM(MOD_LSFT),                 TO(_SYM), KC_BSPC,   OSM(MOD_RCTL)
    ),
    [_NAV] = LAYOUT_split_3x5_3(
        XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX,                                KC_HOME, KC_PGDN,    KC_PGUP, KC_END, KC_DEL,
        XXXXXXX, KC_MPRV,  KC_MSTP,  KC_MPLY, KC_MNXT,                                 KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ENT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             KC_LALT,  TO(_ALPHA), OSM(MOD_LSFT),                  TO(_SYM),   KC_BSPC,   OSM(MOD_RCTL)
    ),
    [_NUM] = LAYOUT_split_3x5_3(
        XXXXXXX,  KC_F9, KC_F10, KC_F11, KC_F12,                                    KC_PPLS,  KC_P7,  KC_P8,  KC_P9, KC_PSLS,
        XXXXXXX,  KC_F5,  KC_F6,  KC_F7,  KC_F8,                                    KC_P0,  KC_P4,  KC_P5,  KC_P6, KC_PDOT,
        XXXXXXX,  KC_F1,  KC_F2,  KC_F3,  KC_F4,                                    KC_PMNS,  KC_P1,  KC_P2,  KC_P3, KC_PAST,
                             KC_LALT,  KC_SPC, OSM(MOD_LSFT),                  TO(_SYM), KC_BSPC,  OSM(MOD_RCTL)
    )
    // clang-format on
};
