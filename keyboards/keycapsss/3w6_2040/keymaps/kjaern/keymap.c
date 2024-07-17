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
    _DANE,
    _SYM,
    _NAV,
    _NUM,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    //  NOOB HERE, I need the docs link close by
    //      https://docs.qmk.fm/keycodes_basic
    //      https://github.com/qmk/qmk_firmware/blob/master/docs/feature_layers.md
    //
    //      OSM    One Shot Keys https://github.com/qmk/qmk_firmware/blob/master/docs/one_shot_keys.md
    //      MT     Mod-Taps      https://docs.qmk.fm/mod_tap#caveats
    //      MO   momentarily activates layer
    //      LM
    //      LT  momentarily activates layer when held, and sends kc when tapped

    [_ALPHA] = LAYOUT_split_3x5_3(
        KC_Q,               KC_W,                 KC_E,                KC_R,                  KC_T,                        KC_Y,    KC_U,                  KC_I,                KC_O,                 KC_P, //MT(DK_ARNG,KC_P),
        MT(MOD_LGUI,KC_A),  MT(MOD_LALT,KC_S),    MT(MOD_LCTL,KC_D),   MT(MOD_LSFT, KC_F),    KC_G,                        KC_H,    MT(MOD_LSFT, KC_J),    MT(MOD_LCTL, KC_K),  MT(MOD_LALT,KC_L),    MT(MOD_RGUI,KC_ENT), // MT(DK_AE,KC_ENT),
        LT(_DANE,KC_Z),     KC_X,                 KC_C,                KC_V,                  KC_B,                        KC_N,    KC_M,                  KC_COMM,             KC_DOT,               KC_SLSH, //MT(DK_OSTR, KC_SLSH),
                             LT(_ADJUST, KC_TAB), KC_SPC, LT(_NUM, KC_ESC),                MO(_SYM), LT(_NAV,KC_BSPC),   LT(_NAV, KC_DEL)
    ),

    [_DANE] = LAYOUT_split_3x5_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DK_ARNG,
        XXXXXXX, XXXXXXX, XXXXXXX, MT(MOD_LSFT, XXXXXXX), XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DK_AE,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DK_OSTR,
                                    XXXXXXX, XXXXXXX, XXXXXXX,                XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_SYM] = LAYOUT_split_3x5_3(
        DK_EXLM,   DK_DQUO,  DK_HASH,  DK_CURR,  DK_PERC,                                DK_AMPR, DK_LBRC, DK_RBRC, KC_PPLS, DK_QUES,
        XXXXXXX,   DK_AT,    DK_PND,   DK_DLR,   DK_EURO,                                DK_LABK, DK_LPRN, DK_RPRN, DK_RABK, XXXXXXX,
        XXXXXXX,   DK_SLSH,  DK_PIPE,  DK_BSLS,  XXXXXXX,                                XXXXXXX, DK_LCBR, DK_RCBR, XXXXXXX, XXXXXXX,
                                    XXXXXXX, XXXXXXX, XXXXXXX,                XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_NAV] = LAYOUT_split_3x5_3(
        XXXXXXX,              KC_MS_WH_LEFT,  KC_MS_UP,      KC_MS_WH_RIGHT, XXXXXXX,                   KC_HOME, KC_PGDN,    KC_PGUP, KC_END, KC_DEL,
        MT(MOD_LGUI,XXXXXXX), KC_MS_LEFT,     KC_MS_DOWN,    KC_MS_RIGHT,    KC_MS_WH_UP,             KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ENT,
        KC_MS_ACCEL0,         KC_MS_ACCEL1,   KC_MS_ACCEL2,  KC_MS_WH_DOWN,  KC_MS_WH_DOWN,           XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX,
                                    KC_MS_BTN2, XXXXXXX, KC_MS_BTN1,                XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_NUM] = LAYOUT_split_3x5_3(
        XXXXXXX,                KC_F7,  KC_F8,  KC_F9,  KC_F10,                                         KC_PSLS,    KC_7,  KC_8,  KC_9, XXXXXXX,
        MT(MOD_LGUI, XXXXXXX),  MT(MOD_LALT,KC_F4),  MT(MOD_LCTL,KC_F5),  KC_F6,  KC_F11,               KC_PAST,    MT(MOD_LSFT,KC_4),  MT(MOD_LCTL,KC_5),  MT(MOD_LALT,KC_6), DK_EQL,
        XXXXXXX,                KC_F1,  KC_F2,  KC_F3,  KC_F12,                                         KC_0,       KC_1,  KC_2,  KC_3, KC_PPLS,
                                            KC_TAB, KC_SPC, KC_ESC,                KC_ENT, KC_BSPC, KC_DEL
    ),

    [_ADJUST] = LAYOUT_split_3x5_3(
        XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX,                                KC_HOME, KC_PGDN,    KC_PGUP, KC_END, KC_DEL,
        MT(MOD_LGUI,XXXXXXX), MT(MOD_LALT,KC_MPRV),  KC_MSTP,  KC_MPLY, KC_MNXT,                              XXXXXXX, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP, XXXXXXX,XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                KC_CAPS_LOCK, KC_APP,LALT(KC_PRINT_SCREEN), LGUI(LCTL(LSFT(KC_PRINT_SCREEN))), KC_PRINT_SCREEN,
                                    XXXXXXX, XXXXXXX, OSM(MOD_LSFT),                XXXXXXX, XXXXXXX, XXXXXXX
    )
    // clang-format on
};
