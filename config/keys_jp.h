/*
 * keys_jp.h - Japanese (JIS / Windows 106/109) locale key definitions for ZMK
 *
 * OS 側のキーボードレイアウトが「日本語キーボード (106/109キー)」のときに、
 * 名前どおりの文字が入力されるよう US の HID キーコードへ割り当てたものです。
 * (zmk-locale-generator には日本語配列が含まれていないため手動作成)
 *
 * 使い方: .keymap で <dt-bindings/zmk/keys.h> の後に #include "keys_jp.h"
 *         例) &kp JP_AT   &kp JP_COLON   &mt RIGHT_SHIFT JP_UNDER
 */

#pragma once

#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/modifiers.h>

/* ---- 数字段 (Shift 付き) ---- */
#define JP_EXCL   LS(N1)            /* ! */
#define JP_DQT    LS(N2)            /* " */
#define JP_HASH   LS(N3)            /* # */
#define JP_DLLR   LS(N4)            /* $ */
#define JP_PRCT   LS(N5)            /* % */
#define JP_AMPS   LS(N6)            /* & */
#define JP_SQT    LS(N7)            /* ' */
#define JP_LPAR   LS(N8)            /* ( */
#define JP_RPAR   LS(N9)            /* ) */

/* ---- 記号キー ---- */
#define JP_MINUS  MINUS             /* - */
#define JP_EQUAL  LS(MINUS)         /* = */
#define JP_CARET  EQUAL             /* ^ */
#define JP_TILDE  LS(EQUAL)         /* ~ */
#define JP_YEN    INT3              /* ¥ (Windows では \ として扱われることが多い) */
#define JP_PIPE   LS(INT3)          /* | */
#define JP_AT     LBKT              /* @ */
#define JP_GRAVE  LS(LBKT)          /* ` */
#define JP_LBKT   RBKT              /* [ */
#define JP_LBRC   LS(RBKT)          /* { */
#define JP_SEMI   SEMI              /* ; */
#define JP_PLUS   LS(SEMI)          /* + */
#define JP_COLON  SQT               /* : */
#define JP_ASTRK  LS(SQT)           /* * */
#define JP_RBKT   BSLH              /* ] (JIS の「む」キー。Windows では NUHS と同じスキャンコード) */
#define JP_RBRC   LS(BSLH)          /* } */
#define JP_COMMA  COMMA             /* , */
#define JP_LT     LS(COMMA)         /* < */
#define JP_DOT    DOT               /* . */
#define JP_GT     LS(DOT)           /* > */
#define JP_SLASH  SLASH             /* / */
#define JP_QMARK  LS(SLASH)         /* ? */
#define JP_BSLH   INT1              /* \ (「ろ」キー) */
#define JP_UNDER  LS(INT1)          /* _ */

/* ---- 日本語入力関連キー ---- */
#define JP_HANZEN GRAVE             /* 半角/全角 (IME トグル) */
#define JP_MHEN   INT5              /* 無変換 */
#define JP_HENK   INT4              /* 変換 */
#define JP_KANA   INT2              /* カタカナ/ひらがな/ローマ字 */
#define JP_EISU   CAPS              /* 英数 (CapsLock 位置) */
