#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
// float imp_march_song[][2] = SONG(IMPERIAL_MARCH);
// uint8_t my_tempo = 50;
// audio_set_tempo(my_tempo);
#endif
#include "eeprom.h"
#include "keymap_german.h"


#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)

#define KC_DEL KC_DELETE
#define WEB_PAI WEBUSB_PAIR
#define AUD_UP KC_AUDIO_VOL_UP
#define AUD_DN KC_AUDIO_VOL_DOWN
#define AUD_MUT KC_AUDIO_MUTE

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  DE_LSPO,
  DE_RSPC,
  PLY_IMP,
  PLY_BLD,
  LAYER_QWERTZ,
  LAYER_BASE
};


enum planck_layers {
  _BASE,      // 0
  _LOWER,     // 1
  _RAISE,     // 2
  _ADJUST,    // 3
  _SYMBOLS_R, // 4
  _SYMBOLS_L, // 5
  _NAVNUM,    // 6
  _F_KEYS,    // 7
  _QWERTZ,    // 8
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
        /* ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
         * │   ~  │   1  │   2  │   3  │   4  │   5  │   6  │   7  │   8  │   9  │   0  │ DEL  │
         * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
         * │   `  │   !  │   @  │   #  │   $  │   %  │   ^  │   &  │   *  │   ü  │   ö  │   ä  │
         * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
         * │ SINS │   …  │   ’  │   “  │   ”  │   ←  │   →  │   €  │   ß  │   Ü  │   Ö  │   Ä  │
         * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
         * │ Rset │ BLSt │  F1  │ Home │ End  │ PgUp │ PgDn │ Left │ Down │  Up  │ Rght │      │
         * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
         */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_planck_grid(
  //┌────┬────┬────┬────┬────┬────┐    ┌────┬────┬────┬────┬────┬────┐
  //├────┼────┼────┼────┼────┼────┤    ├────┼────┼────┼────┼────┼────┤
  //└────┴────┴────┴────┴────┴────┘    └────┴────┴────┴────┴────┴────┘
    LT(_F_KEYS,KC_TAB),    KC_X,           KC_V,           KC_L,           KC_C,                 KC_W,           KC_K ,           KC_H,           KC_G,           KC_F,           KC_Q,           KC_BSPACE,
    LT(_SYMBOLS_R,KC_ESCAPE), KC_U,           KC_I,           KC_A,           KC_E,                 KC_O,           KC_S,           KC_N,           KC_R,           KC_T,           KC_D,           LT(_SYMBOLS_L,DE_Y),
    KC_LSHIFT,       DE_UDIA,        DE_ODIA,        DE_ADIA,        KC_P,                 DE_Z,           KC_B,           KC_M,           KC_COMMA,       KC_DOT,         KC_J,           MT(MOD_RSFT, DE_SS),
    KC_LCTRL,        TG(_QWERTZ),          KC_LALT,        KC_RGUI,        LT(_LOWER, KC_BACKSPACE), LT(_NAVNUM,KC_SPACE), KC_NO,          LT(_RAISE, KC_ENTER),KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT
  ),

  [_LOWER] = LAYOUT_planck_grid(
    _______, KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,   KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP, KC_MS_WH_RIGHT, KC_NO,          KC_MEDIA_PLAY_PAUSE,
    _______, KC_NO,   KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, KC_NO,   KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,    KC_MS_RIGHT,    KC_NO,          KC_MEDIA_STOP,
    _______, KC_NO,   KC_PC_CUT,    KC_PC_COPY,   KC_PC_PASTE,  KC_NO,   KC_NO,          KC_NO,          KC_NO,       KC_NO,          KC_NO,          KC_MEDIA_NEXT_TRACK ,
    _______, _______, _______,      _______,      _______,      _______, KC_NO,          KC_MS_BTN3,     KC_MS_BTN2,  KC_NO,          KC_NO,          KC_MEDIA_PREV_TRACK
  ),

  [_RAISE] = LAYOUT_planck_grid(
    //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐ ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
        AUD_UP  , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,   KC_HOME, KC_PGDOWN, KC_PGUP , KC_END  , KC_NO   , _______ ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        AUD_MUT , KC_NO   , KC_NO   , KC_NO   , _______ , KC_NO   ,   KC_LEFT, KC_DOWN  , KC_UP   , KC_RIGHT, KC_NO   , KC_ENTER,
    //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        AUD_DN  , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,   KC_NO  , KC_NO    , KC_NO   , KC_NO   , KC_NO   , _______ ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        _______ , _______ , _______ , _______ , _______ , _______ ,   KC_NO  , _______  , KC_NO   , KC_NO   , KC_NO   , KC_NO
    //└─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘ └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐ ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
        PLY_IMP , PLY_BLD , _______ , _______ , _______ , _______ ,   _______ , _______ , RGB_SPI , RGB_SPD , _______ , _______ ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        KC_DEL  , _______ , AU_ON   , AU_OFF  ,  AU_TOG , _______ ,   _______ , RGB_TOG , RGB_VAI , RGB_VAD , _______ , _______ ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        _______ , _______ , MU_ON   , MU_OFF  ,  MU_TOG , _______ ,   _______ , RGB_MOD , RGB_HUI , RGB_HUD , _______ , _______ ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        WEB_PAI , RESET   , _______ , _______ , _______ , _______ ,   KC_NO   , _______ , _______ , _______ , _______ , _______
    //└─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘ └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
  ),

  [_SYMBOLS_R] = LAYOUT_planck_grid(
    //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐ ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
        _______ , DE_EURO , DE_UNDS , DE_LBRC , DE_RBRC , DE_CIRC ,   DE_EXLM , DE_LABK , DE_RABK , DE_EQL  , DE_AMPR , _______ ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        _______ , DE_BSLS , DE_SLSH , DE_LCBR , DE_RCBR , DE_ASTR ,   DE_QUES , DE_LPRN , DE_RPRN , DE_MINS , DE_COLN , DE_AT   ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        _______ , DE_HASH , DE_DLR  , DE_PIPE , DE_TILD , DE_GRV  ,   DE_PLUS , DE_PERC , DE_DQUO , DE_QUOT , DE_SCLN , _______ ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        _______ , _______ , _______ , _______ , _______ , _______ ,   KC_NO   , _______ , _______ , _______ , _______ , _______
    //└─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘ └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
  ),

  [_SYMBOLS_L] = LAYOUT_planck_grid(
    //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐ ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
        _______ , DE_EURO , DE_UNDS , DE_LBRC , DE_RBRC , DE_CIRC ,   DE_EXLM , DE_LABK , DE_RABK , DE_EQL  , DE_AMPR , _______ ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        _______ , DE_BSLS , DE_SLSH , DE_LCBR , DE_RCBR , DE_ASTR ,   DE_QUES , DE_LPRN , DE_RPRN , DE_MINS , DE_COLN , _______ ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        _______ , DE_HASH , DE_DLR  , DE_PIPE , DE_TILD , DE_GRV  ,   DE_PLUS , DE_PERC , DE_DQUO , DE_QUOT , DE_SCLN , _______ ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        _______ , _______ , _______ , _______ , _______ , _______ ,   KC_NO   , _______ , _______ , _______ , _______ , _______
    //└─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘ └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
  ),

  [_NAVNUM] = LAYOUT_planck_grid(
    //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐ ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
        _______ , KC_HOME , KC_DEL  , KC_UP,      KC_BSPACE,   KC_PGUP,     DE_SLSH,    KC_7,     KC_8,    KC_9,    DE_MINS, KC_DEL,
        _______ , KC_END  , KC_LEFT ,   KC_DOWN,    KC_RIGHT,    KC_PGDOWN,   DE_ASTR,    KC_4,     KC_5,    KC_6,    DE_PLUS,  DE_COLN,
        _______ , _______ , KC_PC_CUT, KC_PC_COPY, KC_PC_PASTE, S(DE_CIRC) , KC_0,       KC_1,     KC_2,    KC_3,    KC_COMMA, KC_DOT,
        _______ , _______ , _______,   _______,    _______,     _______,     KC_NO,      _______,  KC_0,    _______, _______,  _______
  ),

  [_F_KEYS] = LAYOUT_planck_grid(
    //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐ ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
        _______ , _______ , _______ , _______ , _______ , _______ ,   _______ , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        _______ , _______ , _______ , _______ , KC_NO   , KC_NO   ,   KC_NO   , KC_F4   , KC_F5   , KC_F6   , KC_F12  , KC_F13  ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,   KC_NO   , KC_F1   , KC_F2   , KC_F3   , _______ , KC_NO   ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        WEB_PAI , _______ , _______ , _______ , _______ , _______ ,   KC_NO   , _______ , _______ , _______ , _______ , _______
    //└─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘ └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
  ),

  [_QWERTZ] = LAYOUT_planck_grid(
    //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐ ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
        _______ , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    ,   DE_Z    , KC_U    , KC_I    , KC_O    , KC_P    , _______ ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        _______ , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    ,   KC_H    , KC_J    , KC_K    , KC_L    , DE_ODIA , DE_ADIA ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        _______ , DE_Y    , KC_X    , KC_C    , KC_V    , KC_B    ,   KC_N    , KC_M    , _______ , _______ , DE_UDIA , _______ ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        _______ , _______ , _______ , _______ , _______ , _______ ,   KC_NO   , _______ , _______ , _______ , _______ , _______
    //└─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘ └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
  ),

};

// extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

#define BLACK {0, 0, 0}
#define CYAN1 {31, 255, 255}
#define ORANG {255, 165, 0}
#define WHITE {255, 255, 255}
#define RED11 {238, 10, 40}
#define AUDIO {24, 170, 200}
#define NUMBE {18, 209, 55}
#define SYMBO {212, 173, 255}
#define YELLO {255, 255, 10}
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [_LOWER] = {
        //┌───────┬───────┬───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┬───────┬───────┐
            BLACK , BLACK , BLACK , BLACK , BLACK , BLACK ,   CYAN1 , CYAN1 , CYAN1 , CYAN1 , BLACK , AUDIO ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            BLACK , BLACK , RED11 , RED11 , RED11 , BLACK ,   RED11 , RED11 , RED11 , RED11 , BLACK , AUDIO ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            BLACK , BLACK , BLACK , BLACK , BLACK , BLACK ,   BLACK , BLACK , BLACK , BLACK , BLACK , AUDIO ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            BLACK , BLACK , BLACK , BLACK , BLACK , BLACK ,           BLACK , BLACK , BLACK , BLACK , AUDIO ,
        //└───────┴───────┴───────┴───────┴───────┴───────┘ └───────┴───────┴───────┴───────┴───────┴───────┘
        },

    [_RAISE] = {
        //┌───────┬───────┬───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┬───────┬───────┐
            AUDIO , BLACK , BLACK , BLACK , BLACK , BLACK ,   CYAN1 , CYAN1 , CYAN1 , CYAN1 , BLACK , BLACK ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            AUDIO , BLACK , BLACK , BLACK , BLACK , BLACK ,   RED11 , RED11 , RED11 , RED11 , BLACK , BLACK ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            AUDIO, BLACK , BLACK , BLACK , BLACK , BLACK ,    BLACK , BLACK , BLACK , BLACK , BLACK , BLACK ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            BLACK , BLACK , BLACK , BLACK , BLACK , BLACK ,           BLACK , BLACK , BLACK , BLACK , BLACK ,
        //└───────┴───────┴───────┴───────┴───────┴───────┘ └───────┴───────┴───────┴───────┴───────┴───────┘
        },

    [_ADJUST] = {
        //┌───────┬───────┬───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┬───────┬───────┐
            BLACK , BLACK , BLACK , BLACK , BLACK , BLACK ,   BLACK , YELLO , YELLO , YELLO , BLACK , BLACK ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            BLACK , BLACK , AUDIO , AUDIO , AUDIO , BLACK ,   BLACK , YELLO , YELLO , YELLO , BLACK , BLACK ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            BLACK , BLACK , AUDIO , AUDIO , AUDIO , BLACK ,   BLACK , YELLO , YELLO , YELLO , BLACK , BLACK ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            RED11 , RED11 , BLACK , BLACK , BLACK , BLACK ,           BLACK , BLACK , BLACK , BLACK , BLACK ,
        //└───────┴───────┴───────┴───────┴───────┴───────┘ └───────┴───────┴───────┴───────┴───────┴───────┘
        },

    [_SYMBOLS_R] = {
        //┌───────┬───────┬───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┬───────┬───────┐
            BLACK , BLACK , BLACK , SYMBO , SYMBO , BLACK ,   BLACK , SYMBO , SYMBO , BLACK , BLACK , BLACK ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            BLACK , BLACK , BLACK , SYMBO , SYMBO , BLACK ,   BLACK , SYMBO , SYMBO , BLACK , BLACK , BLACK ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            BLACK , BLACK , BLACK , BLACK , BLACK , BLACK ,   BLACK , BLACK , BLACK , BLACK , BLACK , BLACK ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            BLACK , BLACK , BLACK , BLACK , BLACK , BLACK ,           BLACK , BLACK , BLACK , BLACK , BLACK ,
        //└───────┴───────┴───────┴───────┴───────┴───────┘ └───────┴───────┴───────┴───────┴───────┴───────┘
            },

    [_SYMBOLS_L] = {
        //┌───────┬───────┬───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┬───────┬───────┐
            BLACK , BLACK , BLACK , SYMBO , SYMBO , BLACK ,   BLACK , SYMBO , SYMBO , BLACK , BLACK , BLACK ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            BLACK , BLACK , BLACK , SYMBO , SYMBO , BLACK ,   BLACK , SYMBO , SYMBO , BLACK , BLACK , BLACK ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            BLACK , BLACK , BLACK , BLACK , BLACK , BLACK ,   BLACK , BLACK , BLACK , BLACK , BLACK , BLACK ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            BLACK , BLACK , BLACK , BLACK , BLACK , BLACK ,           BLACK , BLACK , BLACK , BLACK , BLACK ,
        //└───────┴───────┴───────┴───────┴───────┴───────┘ └───────┴───────┴───────┴───────┴───────┴───────┘
        },

    [_NAVNUM] = {
        //┌───────┬───────┬───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┬───────┬───────┐
            BLACK , BLACK , BLACK , CYAN1 , BLACK , BLACK ,   BLACK , NUMBE , NUMBE , NUMBE , BLACK , RED11 ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            BLACK , BLACK , CYAN1 , CYAN1 , CYAN1 , BLACK ,   BLACK , NUMBE , NUMBE , NUMBE , BLACK , BLACK ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            BLACK , BLACK , BLACK , BLACK , BLACK , BLACK ,   NUMBE , NUMBE , NUMBE , NUMBE , BLACK , BLACK ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            BLACK , BLACK , BLACK , BLACK , BLACK , BLACK ,           BLACK , NUMBE , BLACK , BLACK , BLACK ,
        //└───────┴───────┴───────┴───────┴───────┴───────┘ └───────┴───────┴───────┴───────┴───────┴───────┘
        },

    [_F_KEYS] = {
        //┌───────┬───────┬───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┬───────┬───────┐
            BLACK , BLACK , BLACK , BLACK , BLACK , BLACK ,   BLACK , AUDIO , AUDIO , AUDIO , AUDIO , AUDIO ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            BLACK , BLACK , BLACK , BLACK , BLACK , BLACK ,   BLACK , AUDIO , AUDIO , AUDIO , AUDIO , AUDIO ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            BLACK , BLACK , BLACK , BLACK , BLACK , BLACK ,   BLACK , AUDIO , AUDIO , AUDIO , BLACK , BLACK ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            RED11 , BLACK , BLACK , BLACK , BLACK , BLACK ,           BLACK , BLACK , BLACK , BLACK , BLACK ,
        //└───────┴───────┴───────┴───────┴───────┴───────┘ └───────┴───────┴───────┴───────┴───────┴───────┘
        },

    [_QWERTZ] = {
        //┌───────┬───────┬───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┬───────┬───────┐
            ORANG , ORANG , ORANG , ORANG , ORANG , ORANG ,   ORANG , ORANG , ORANG , ORANG , ORANG , ORANG ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            ORANG , ORANG , ORANG , ORANG , ORANG , ORANG ,   ORANG , ORANG , ORANG , ORANG , ORANG , ORANG ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            ORANG , ORANG , ORANG , ORANG , ORANG , ORANG ,   ORANG , ORANG , ORANG , ORANG , ORANG , ORANG ,
        //├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
            ORANG , WHITE , ORANG , ORANG , ORANG , ORANG,            ORANG , ORANG , ORANG , ORANG , ORANG ,
        //└───────┴───────┴───────┴───────┴───────┴───────┘ └───────┴───────┴───────┴───────┴───────┴───────┘
        },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    uint8_t r = pgm_read_byte(&ledmap[layer][i][0]);
    uint8_t g = pgm_read_byte(&ledmap[layer][i][1]);
    uint8_t b = pgm_read_byte(&ledmap[layer][i][2]);
    rgb_matrix_set_color( i, r, g, b );
  }
}


void set_layer_color_hsv(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
//   if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  if (keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
    case 8:
      set_layer_color(8);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}
#ifdef AUDIO_ENABLE
    /*
    #undef IMPERIAL_MARCH
    #define IMPERIAL_MARCH \
		HD_NOTE(_A4), HD_NOTE(_A4), HD_NOTE(_A4), QD_NOTE(_F4), QD_NOTE(_C5), \
		HD_NOTE(_A4), QD_NOTE(_F4),  QD_NOTE(_C5), WD_NOTE(_A4), \
		HD_NOTE(_E5), HD_NOTE(_E5), HD_NOTE(_E5), QD_NOTE(_F5), QD_NOTE(_C5), \
		HD_NOTE(_A4), QD_NOTE(_F4),  QD_NOTE(_C5), WD_NOTE(_A4)
        */
    #ifdef TO_BOLDLY_GO
    #undef TO_BOLDLY_GO
    #endif
	#define TO_BOLDLY_GO \
		W__NOTE(_BF3 ), Q__NOTE(_EF4 ), WD_NOTE(_AF4 ), W__NOTE(_REST), \
		H__NOTE(_G4  ), Q__NOTE(_EF4 ), H__NOTE(_C4  ), W__NOTE(_REST), \
		QD_NOTE(_F4  ), M__NOTE(_BF4, 128),
float tone_qwerty[][2] = SONG(QWERTY_SOUND);
float music_impr[][2] = SONG(IMPERIAL_MARCH);
float music_vic[][2] = SONG(TO_BOLDLY_GO);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // case LAYER_BASE:
    //   if (record->event.pressed) {
    //       set_single_persistent_default_layer(_BASE);
    //       return false;
    // }
    // case LAYER_QWERTZ:
    //   if (record->event.pressed) {
    //       set_single_persistent_default_layer(_QWERTZ);
    //       return false;
    // }
    case PLY_IMP:
		if (record->event.pressed) {
			PLAY_SONG(music_impr);
		}
		return true;
    case PLY_BLD:
		if (record->event.pressed) {
			PLAY_SONG(music_vic);
		}
		return true;
    case DE_LSPO:
        perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_8);
        return false;
    case DE_RSPC:
      perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_9);
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


// const key_override_t ctrl_a = ko_make_basic(MOD_MASK_CTRL, KC_U, C(KC_A));
// const key_override_t ctrl_c = ko_make_basic(MOD_MASK_CTRL, DE_ADIA, C(KC_C));
// const key_override_t ctrl_x = ko_make_basic(MOD_MASK_CTRL, DE_ODIA, C(KC_X));
// const key_override_t ctrl_z = ko_make_basic(MOD_MASK_CTRL, DE_UDIA, C(KC_Z));
const key_override_t ctrl_c = ko_make_with_layers_negmods_and_options(MOD_MASK_CTRL, DE_ADIA,
											C(KC_C), ~0, MOD_MASK_SA, ko_option_no_reregister_trigger);
const key_override_t ctrl_p = ko_make_with_layers_negmods_and_options(MOD_MASK_CTRL, KC_P,
											C(KC_V), ~0, MOD_MASK_SA, ko_option_no_reregister_trigger);
const key_override_t ctrl_x = ko_make_with_layers_negmods_and_options(MOD_MASK_CTRL, DE_ODIA,
											C(KC_X), ~0, MOD_MASK_SA, ko_option_no_reregister_trigger);
const key_override_t ctrl_z = ko_make_with_layers_negmods_and_options(MOD_MASK_CTRL, DE_UDIA,
											C(KC_Z), ~0, MOD_MASK_SA, ko_option_no_reregister_trigger);

const key_override_t up_key_override = ko_make_basic(MOD_MASK_CTRL, KC_UP, KC_PGUP);
const key_override_t dn_key_override = ko_make_basic(MOD_MASK_CTRL, KC_DOWN, KC_PGDN);
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPACE, KC_DELETE);

const key_override_t **key_overrides = (const key_override_t *[]){
    &ctrl_c,
    &ctrl_p,
    &ctrl_x,
    &ctrl_z,
    &up_key_override,
    &dn_key_override,
    &delete_key_override,
    NULL
};
