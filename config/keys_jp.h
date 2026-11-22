/*
 * keys_jp.h - US キー名を「Windows 日本語(JIS)配列」用に読み替えるヘッダ
 *
 * Keymap Editor では普段どおり US の記号名 (AT_SIGN, COLON, LEFT_BRACKET ...)
 * で「出したい文字」を配置してください。ビルド時にこのヘッダが US 名を
 * JIS 配列でその文字が出るキーコードへ置き換えます。
 *   例) Keymap Editor で "@" (AT_SIGN) を置く → JIS の「@」キー(US の [ 位置)を送信
 *
 * 別名 (AT, LBKT, SQT, DQT ...) は keys.h で元の名前を参照しているため、
 * 元の名前を置き換えるだけで別名も自動的に JIS 用になります。
 *
 * 置き換え後の値は HID の生コードで書いています (名前同士で参照すると
 * 置き換え後の名前が連鎖して別の文字になってしまうため)。
 *
 * 注意:
 *   - GRAVE (`) は JIS の ` に置き換わるので、半角/全角は送れなくなります。
 *     IME 切り替えには LANG1 / LANG2 / INT4(変換) / INT5(無変換) / LC(SPACE) などを使ってください。
 *   - .keymap の先頭で <dt-bindings/zmk/keys.h> の後に #include "keys_jp.h" が必要です。
 */

#pragma once

#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/modifiers.h>

#define JP__K(usage) (ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_##usage))

/* @  : JIS は US の [ 位置 */
#undef AT_SIGN
#define AT_SIGN JP__K(LEFT_BRACKET_AND_LEFT_BRACE)

/* ^  : US の = 位置 */
#undef CARET
#define CARET JP__K(EQUAL_AND_PLUS)

/* &  : Shift+6 */
#undef AMPERSAND
#define AMPERSAND (LS(JP__K(6_AND_CARET)))

/* *  : Shift+: (US の ' 位置) */
#undef ASTERISK
#define ASTERISK (LS(JP__K(APOSTROPHE_AND_QUOTE)))

/* (  : Shift+8 */
#undef LEFT_PARENTHESIS
#define LEFT_PARENTHESIS (LS(JP__K(8_AND_ASTERISK)))

/* )  : Shift+9 */
#undef RIGHT_PARENTHESIS
#define RIGHT_PARENTHESIS (LS(JP__K(9_AND_LEFT_PARENTHESIS)))

/* _  : Shift+ろ */
#undef UNDERSCORE
#define UNDERSCORE (LS(JP__K(INTERNATIONAL1)))

/* =  : Shift+- */
#undef EQUAL
#define EQUAL (LS(JP__K(MINUS_AND_UNDERSCORE)))

/* +  : Shift+; */
#undef PLUS
#define PLUS (LS(JP__K(SEMICOLON_AND_COLON)))

/* [  : US の ] 位置 */
#undef LEFT_BRACKET
#define LEFT_BRACKET JP__K(RIGHT_BRACKET_AND_RIGHT_BRACE)

/* {  : Shift+[ */
#undef LEFT_BRACE
#define LEFT_BRACE (LS(JP__K(RIGHT_BRACKET_AND_RIGHT_BRACE)))

/* ]  : JIS の「む」キー */
#undef RIGHT_BRACKET
#define RIGHT_BRACKET JP__K(NON_US_HASH_AND_TILDE)

/* }  : Shift+] */
#undef RIGHT_BRACE
#define RIGHT_BRACE (LS(JP__K(NON_US_HASH_AND_TILDE)))

/* \  : 「ろ」キー */
#undef BACKSLASH
#define BACKSLASH JP__K(INTERNATIONAL1)

/* |  : Shift+¥ */
#undef PIPE
#define PIPE (LS(JP__K(INTERNATIONAL3)))

/* :  : US の ' 位置 */
#undef COLON
#define COLON JP__K(APOSTROPHE_AND_QUOTE)

/* '  : Shift+7 */
#undef SINGLE_QUOTE
#define SINGLE_QUOTE (LS(JP__K(7_AND_AMPERSAND)))

/* "  : Shift+2 */
#undef DOUBLE_QUOTES
#define DOUBLE_QUOTES (LS(JP__K(2_AND_AT)))

/* `  : Shift+@ */
#undef GRAVE
#define GRAVE (LS(JP__K(LEFT_BRACKET_AND_LEFT_BRACE)))

/* ~  : Shift+^ */
#undef TILDE
#define TILDE (LS(JP__K(EQUAL_AND_PLUS)))

/*
 * 変更不要 (US と JIS で同じキー):
 *   ! # $ % - ; , < . > / ?  英数字
 *
 * テキストで書く場合の日本語キー (Keymap Editor では ⊘ 表示になります)
 */
#define JP_HANZEN JP__K(GRAVE_ACCENT_AND_TILDE) /* 半角/全角 */
#define JP_YEN    JP__K(INTERNATIONAL3)         /* ¥ */
