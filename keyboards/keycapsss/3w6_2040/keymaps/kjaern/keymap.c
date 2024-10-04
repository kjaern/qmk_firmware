// Highly inspired by
// https://www.youtube.com/watch?v=8wZ8FRwOzhU
// https://github.com/benvallack/34-QMK-Ferris-Sweep
//
// https://docs.google.com/document/d/1Ic-h8UxGe5-Q0bPuYNgE3NoWiI8ekeadvSQ5YysrwII/edit
//
// also great resourse collection made by Folke:
// https://github.com/folke/zmk-config

// // strategies: (https://youtu.be/dg2TT1OJlQs?si=F65zSeE0pRMy-Fo9&t=878)
// thumb keys switch layers
// thumb keys as modifiers
// enter and backspace

#include QMK_KEYBOARD_H
#include "keymap_danish.h"
enum layers {
    _ALPHA = 0,
    _ALPHA2,
    _LAYERSW,
    _DANE,
    _SYM,
    _NAV,
    _NUM,
    _NUM2,
    _ADJUST,
    /*_GAME,*/
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    //  NOOB HERE, I need the docs link close by
    //      https://docs.qmk.fm/keycodes_basic
    //      https://github.com/qmk/qmk_firmware/blob/master/docs/feature_layers.md
    //
    //      OSM    One Shot Keys https://github.com/qmk/qmk_firmware/blob/master/docs/one_shot_keys.md
    //      MT     Mod-Taps      https://docs.qmk.fm/mod_tap#caveats
    //      MO   momentarily activates layer
    //      LT  momentarily activates layer when held, and sends kc when tapped ~

    [_ALPHA] = LAYOUT_split_3x5_3(
        KC_Q,               KC_W,                 KC_E,                KC_R,                  KC_T,                        KC_Y,    KC_U,                  KC_I,                KC_O,                 KC_P, //MT(DK_ARNG,KC_P),
        MT(MOD_LGUI,KC_A),  MT(MOD_LALT,KC_S),    MT(MOD_LCTL,KC_D),   MT(MOD_LSFT, KC_F),    KC_G,                        KC_H,    MT(MOD_RSFT, KC_J),    MT(MOD_RCTL, KC_K),  MT(MOD_LALT,KC_L),    MT(MOD_LGUI,DK_AE), // MT(DK_AE,KC_ENT),
        LT(_DANE,KC_Z),     LT(_NAV, KC_X),       LT(_SYM,KC_C),       LT(_NUM,KC_V),         LT(_NUM2, KC_B),             KC_N,    LT(_NUM,KC_M),                  LT(_SYM,KC_COMM),             LT(_NAV,KC_DOT),               KC_SLSH, //MT(DK_OSTR, KC_SLSH),
                             LT(_ADJUST, KC_TAB), LT(_NAV,KC_SPC), OSM(MOD_LSFT),                MO(_LAYERSW), KC_BSPC,    KC_DEL
    ),

    [_ALPHA2] = LAYOUT_split_3x5_3(
        KC_Q,  KC_W,    KC_E,   KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, //MT(DK_ARNG,KC_P),
        KC_A,  KC_S,    KC_D,   KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    DK_AE,
        KC_Z,  KC_X,    KC_C,   KC_V,    KC_B,                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, //MT(DK_OSTR, KC_SLSH),
                             LT(_ADJUST, KC_TAB), KC_SPC, OSM(MOD_LSFT),                MO(_LAYERSW), KC_BSPC,    KC_DEL
    ),

    /*[_LAYERSW] = LAYOUT_split_3x5_3(*/
    /*    DK_EXLM,   DK_DQUO,  DK_HASH,  DK_CURR,  DK_PERC,                                DK_AMPR, DK_LCBR, DK_RCBR, KC_PPLS, DK_QUES,*/
    /*    OSM(MOD_LGUI),   DK_AT,    DK_PND,   DK_DLR,   DK_EURO,                                DK_LABK, DK_LPRN, DK_RPRN, DK_RABK, KC_ENT,*/
    /*    DK_SLSH,  DK_PIPE,  DK_BSLS,  TO(_ALPHA),   TO(_ALPHA2),                         XXXXXXX, DK_LBRC, DK_RBRC, DK_CIRC, DK_TILD,*/
    /*                                XXXXXXX, XXXXXXX, KC_ESC,                XXXXXXX, XXXXXXX, XXXXXXX*/
    /*),*/

    [_LAYERSW] = LAYOUT_split_3x5_3(
        DK_EXLM,   DK_DQUO,  DK_HASH,  DK_CURR,  DK_PERC,                                DK_AMPR, DK_LCBR, DK_RCBR, KC_PPLS, DK_QUES,
        DK_QUOT,   DK_AT,    DK_PND,   DK_DLR,   DK_EURO,                                DK_LABK, DK_LPRN, DK_RPRN, DK_RABK, KC_ENT,
        DK_SLSH,  DK_PIPE,  DK_BSLS,  TO(_ALPHA),   TO(_ALPHA2),                         XXXXXXX, DK_LBRC, DK_RBRC, DK_CIRC, DK_TILD,
                                    XXXXXXX, OSM(MOD_LGUI), KC_ESC,                XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_SYM] = LAYOUT_split_3x5_3(
        DK_EXLM,   DK_DQUO,  DK_HASH,  DK_CURR,  DK_PERC,                                DK_AMPR, DK_LCBR, DK_RCBR, KC_PPLS, DK_QUES,
        DK_QUOT,   DK_AT,    DK_PND,   DK_DLR,   DK_EURO,                                DK_LABK, DK_LPRN, DK_RPRN, DK_RABK, DK_CIRC,
        XXXXXXX,   DK_SLSH,  DK_PIPE,  DK_BSLS,  XXXXXXX,                                XXXXXXX, DK_LBRC, DK_RBRC, XXXXXXX, DK_TILD,
                                    XXXXXXX, XXXXXXX, KC_ESC,                XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_NAV] = LAYOUT_split_3x5_3(
        KC_ESC,              KC_MS_WH_LEFT,  KC_MS_UP,      KC_MS_WH_RIGHT, XXXXXXX,                   KC_HOME, KC_PGDN,    KC_PGUP, KC_END, KC_DEL,
        MT(MOD_LGUI,XXXXXXX), KC_MS_LEFT,     KC_MS_DOWN,    KC_MS_RIGHT,    KC_MS_WH_UP,             KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ENT,
        KC_MS_ACCEL0,         KC_MS_ACCEL1,   KC_MS_ACCEL2,  KC_MS_WH_DOWN,  KC_MS_WH_DOWN,           XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX,
                                    KC_MS_BTN2, XXXXXXX, KC_MS_BTN1,                XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_NUM] = LAYOUT_split_3x5_3(
        KC_P7,  KC_F7,  KC_F8,  KC_F9,  KC_F10,                                         KC_PSLS,    KC_7,  KC_8,  KC_9, DK_EQL,
        KC_P3,  KC_F4,  KC_F5,  KC_F6,  KC_F11,                                         KC_PAST,    KC_4,  KC_5,  KC_6, KC_PPLS,
        KC_P1,  KC_F1,  KC_F2,  KC_F3,  KC_F12,                                         KC_0,       MT(KC_P1,KC_1),  KC_2,  KC_3, KC_DOT,
                                            KC_TAB, KC_SPC, KC_ESC,                KC_ENT, KC_BSPC,  KC_COMM
    ),

    [_NUM2] = LAYOUT_split_3x5_3(
        KC_P7,  KC_F7,  KC_F8,  KC_F9,  KC_F10,                                         KC_PSLS,    KC_P7,  KC_P8,  KC_P9, DK_EQL,
        KC_P3,  KC_F4,  KC_F5,  KC_F6,  KC_F11,                                         KC_PAST,    KC_P4,  KC_P5,  KC_P6, KC_PPLS,
        KC_P1,  KC_F1,  KC_F2,  KC_F3,  KC_F12,                                         KC_P0,       KC_P1,  KC_P2,  KC_P3, KC_DOT,
                                            KC_TAB, KC_SPC, KC_ESC,                KC_ENT, KC_BSPC,  KC_COMM
    ),

    [_DANE] = LAYOUT_split_3x5_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DK_ARNG,
        XXXXXXX, XXXXXXX, XXXXXXX, MT(MOD_LSFT, XXXXXXX), XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DK_OSTR,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                    XXXXXXX, XXXXXXX, XXXXXXX,                XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_ADJUST] = LAYOUT_split_3x5_3(
        XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX,                                KC_HOME, KC_PGDN,    KC_PGUP, KC_END, KC_DEL,
        MT(MOD_LGUI,XXXXXXX), MT(MOD_LALT,KC_MPRV),  KC_MSTP,  KC_MPLY, KC_MNXT,                              XXXXXXX, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP, XXXXXXX,XXXXXXX,
        KC_WWW_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                KC_CAPS_LOCK, KC_APP,LALT(KC_PRINT_SCREEN), LGUI(LCTL(LSFT(KC_PRINT_SCREEN))), KC_PRINT_SCREEN,
                                    XXXXXXX, XXXXXXX, OSM(MOD_LSFT),                XXXXXXX, XXXXXXX, XXXXXXX
    ),

    /*[_GAME] = LAYOUT_split_3x5_3(*/
    /*    K,  KC_W,  KC_E,   KC_R,    KC_T,                        KC_Y,    KC_U,  KC_I,       KC_O,    KC_P, //MT(DK_ARNG,KC_P),*/
    /*    KC_A,  KC_S,  KC_D,   KC_F,    KC_G,                        KC_H,    KC_J,  KC_K,       KC_L,    KC_ENT, // MT(DK_AE,KC_ENT),*/
    /*    KC_Z,  KC_X,  KC_C,   KC_V,    KC_B,                        KC_N,    KC_M,  KC_COMM,    KC_DOT,  KC_SLSH, //MT(DK_OSTR, KC_SLSH),*/
    /*                                XXXXXXX, KC_SPC, XXXXXXX,                XXXXXXX, MT(_ALPHA), XXXXXXX*/
    /*)*/
    /*[_GAME] = LAYOUT_split_3x5_3(*/
    /*    XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX,                                XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,*/
    /*    KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                                XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,*/
    /*    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,*/
    /*                                XXXXXXX, XXXXXXX, XXXXXXX,                XXXXXXX, XXXXXXX, XXXXXXX*/
    /*)*/



    // clang-format on
};

void eeconfig_init_user(void) {  // EEPROM is getting reset!
  // use the non noeeprom versions, to write these values to EEPROM too
  rgblight_enable(); // Enable RGB by default
  /*rgblight_sethsv_white();  // Set it to white by default*/
  rgblight_mode(RGBLIGHT_MODE_BREATHING); // set to breathing by default
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_config_t rgblight_config;
  switch(biton32(state)) {
  case 1:
    // Green
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_GREEN);
    break;
  case 2:
    // Red
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_RED);
    break;
  case 3:
    // Blue
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_BLUE);
    break;
  case 4:
    // Orange
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_PURPLE);
    break;
  default:
    // White
    //Read RGB Light State
    rgblight_config.raw = eeconfig_read_rgblight();
    //If enabled, set white
    if (rgblight_config.enable) {
		rgblight_sethsv_noeeprom(HSV_WHITE);
	} else { //Otherwise go back to disabled
		rgblight_disable_noeeprom();
	}
    break;
}
return state;
}
