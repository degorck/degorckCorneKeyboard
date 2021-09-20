#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

enum layers {
  _DVORAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  ADJUST,
  RGBRST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT(
       //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_TAB,  KC_DOT,   KC_COMM,  KC_SCLN,   KC_P,   KC_Y,                     KC_F,   KC_G,   KC_C,   KC_H,   KC_L,   KC_BSPC,
       //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LSFT, KC_A,   KC_O,  KC_E,   KC_U,   KC_I,                             KC_D,   KC_R,   KC_T,   KC_N,   KC_S, KC_QUOT,
       //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LCTL, KC_SLSH,   KC_Q,  KC_J,   KC_K,   KC_X,                          KC_B,   KC_M,   KC_W, KC_V, KC_Z, KC_ENT,
       //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                       KC_LGUI, MO(3), KC_SPC,       KC_SPC, MO(2), KC_ALGR
                                  //`--------------------------'  `--------------------------'

  ),

  [_QWERTY] = LAYOUT(
       //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_TAB,  KC_Q,   KC_W,  KC_E,   KC_R,   KC_T,                            KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSPC,
       //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LSFT, KC_A,   KC_S,  KC_D,   KC_F,   KC_G,                            KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_QUOT,
       //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LCTL, KC_Z,   KC_X,  KC_C,   KC_V,   KC_B,                            KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
       //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                       KC_LGUI, MO(3), KC_SPC,       KC_SPC, MO(2), KC_ALGR
                                  //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),      LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_NO,   KC_NO,   KC_UP,   KC_NO,  KC_NO,                      TO(1),   KC_GRV,  KC_EQL,  KC_QUOT,  KC_NUHS,  KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,  KC_NO,   KC_LEFT,  KC_DOWN, KC_RGHT, KC_NO,                      KC_NO,   KC_NO,   KC_CIRC, KC_MINS,  KC_RO,    KC_NUBS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_TRNS, KC_SPC,      KC_SPC, KC_NO, KC_ALGR
                                      //`--------------------------'  `--------------------------'
   ),

  [_RAISE] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NLCK,                      KC_PMNS,  KC_P7,   KC_P8,  KC_P9,   KC_PSLS,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_PPLS, KC_P4,    KC_P5,   KC_P6,   KC_PAST, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_PDOT, KC_P1,    KC_P2,   KC_P3,    KC_P0,  KC_PENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, TO(0), KC_SPC,         KC_SPC, TO(4), KC_ALGR
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT(
  //,-----------------------------------------.                ,-----------------------------------------.
      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,  KC_F6,                KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    RGB_TOG,RGB_HUI,RGB_SAI,RGB_VAI,RGB_SPI,KC_NO,               KC_NO,KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    RGB_MOD,RGB_HUD,RGB_SAD,RGB_VAD,RGB_SPD,KC_NO,               KC_NO , KC_NO, KC_NO, RGB_RMOD, RGBRST, RESET,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                            KC_LGUI, TO(0), KC_SPC,      KC_SPC, KC_TRNS, KC_ALGR
                              //`--------------------'  `--------------------'
  )
};

int RGB_current_mode;

void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (biton32(layer_state)) {
        case _DVORAK:
            oled_write_ln_P(PSTR("Dvorak"), false);
            break;
        case _QWERTY:
            oled_write_ln_P(PSTR("QWERTY"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Dvorak"), false);
            break;

    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}


void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE

void rgb_matrix_indicators_user(void) {
  #ifdef RGB_MATRIX_ENABLE
  switch (biton32(layer_state)) {
    case _RAISE:
      for (int i = 0; i < 6; i++) {
        rgb_matrix_set_color(i, 25, 0, 0);
      }
      if(!is_master){
        for (int i = 0; i < 6; i++) {
          rgb_matrix_set_color(i, 25, 0, 0);
        }
        for (int i =10; i < 13; i++) {
          rgb_matrix_set_color(i, 25, 0, 0);
        }
        for (int i =15; i < 21; i++) {
          rgb_matrix_set_color(i, 25, 0, 0);
        }
      }
    break;
    case _LOWER:
      for (int i = 0; i < 6; i++) {
        rgb_matrix_set_color(i, 0, 0, 25);
      }
      if(is_master){
        rgb_matrix_set_color(12, 0, 0, 25);
        rgb_matrix_set_color(15, 0, 0, 25);
        rgb_matrix_set_color(16, 0, 0, 25);
        rgb_matrix_set_color(20, 0, 0, 25);
      }
    break;
    case _ADJUST:
      for (int i = 0; i < 6; i++) {
        rgb_matrix_set_color(i, 25, 25, 25);
      }
    break;
    case _QWERTY:
      for (int i = 0; i < 6; i++) {
        rgb_matrix_set_color(i, 0, 25, 0);
      }
      if(is_master){
        rgb_matrix_set_color(17, 0, 25, 0);
        rgb_matrix_set_color(18, 0, 25, 0);
        rgb_matrix_set_color(23, 0, 25, 0);
      }
    break;
    case _DVORAK:
      for (int i = 0; i < 6; i++) {
        rgb_matrix_set_color(i, 0, 0, 0);
      }
    break;
  }
  #endif
}
