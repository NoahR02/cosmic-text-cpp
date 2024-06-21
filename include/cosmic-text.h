#pragma once

/* Warning, this file is autogenerated by cbindgen. Don't modify this manually. */

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>


#ifdef __cplusplus
namespace cosmic_text {
#endif // __cplusplus

typedef enum Shaping {
    /**
     * Basic shaping with no font fallback.
     *
     * This shaping strategy is very cheap, but it will not display complex
     * scripts properly nor try to find missing glyphs in your system fonts.
     *
     * You should use this strategy when you have complete control of the text
     * and the font you are displaying in your application.
     */
    Basic,
    /**
     * Advanced text shaping and font fallback.
     *
     * You will need to enable this strategy if the text contains a complex
     * script, the font used needs it, and/or multiple fonts in your system
     * may be needed to display all of the glyphs.
     */
    Advanced,
} Shaping;

typedef enum Stretch {
    UltraCondensed,
    ExtraCondensed,
    Condensed,
    SemiCondensed,
    Normal,
    SemiExpanded,
    Expanded,
    ExtraExpanded,
    UltraExpanded,
} Stretch;

typedef enum Style {
    /**
     * A face that is neither italic not obliqued.
     */
    Normal,
    /**
     * A form that is generally cursive in nature.
     */
    Italic,
    /**
     * A typically-sloped version of the regular face.
     */
    Oblique,
} Style;

typedef struct Buffer Buffer;

typedef struct FontSystem FontSystem;

typedef struct SwashCache SwashCache;

typedef struct Color {
    uint32_t _0;
} Color;

typedef enum Family_Tag {
    /**
     * The name of a font family of choice.
     *
     * This must be a *Typographic Family* (ID 16) or a *Family Name* (ID 1) in terms of TrueType.
     * Meaning you have to pass a family without any additional suffixes like _Bold_, _Italic_,
     * _Regular_, etc.
     *
     * Localized names are allowed.
     */
    Name,
    /**
     * Serif fonts represent the formal text style for a script.
     */
    Serif,
    /**
     * Glyphs in sans-serif fonts, as the term is used in CSS, are generally low contrast
     * and have stroke endings that are plain — without any flaring, cross stroke,
     * or other ornamentation.
     */
    SansSerif,
    /**
     * Glyphs in cursive fonts generally use a more informal script style,
     * and the result looks more like handwritten pen or brush writing than printed letterwork.
     */
    Cursive,
    /**
     * Fantasy fonts are primarily decorative or expressive fonts that
     * contain decorative or expressive representations of characters.
     */
    Fantasy,
    /**
     * The sole criterion of a monospace font is that all glyphs have the same fixed width.
     */
    Monospace,
} Family_Tag;

typedef struct Family {
    Family_Tag tag;
    union {
        struct {
            const char *name;
        };
    };
} Family;

typedef struct Weight {
    uint16_t _0;
} Weight;

/**
 * Flags that change rendering
 */
typedef uint32_t CacheKeyFlags;
/**
 * Skew by 14 degrees to synthesize italic
 */
#define CacheKeyFlags_FAKE_ITALIC (uint32_t)1

typedef struct CacheMetrics {
    uint32_t font_size_bits;
    uint32_t line_height_bits;
} CacheMetrics;

typedef struct Attrs {
    const struct Color *color_opt;
    struct Family family;
    enum Stretch stretch;
    enum Style style;
    struct Weight weight;
    size_t metadata;
    CacheKeyFlags cache_key_flags;
    const struct CacheMetrics *metrics_opt;
} Attrs;

typedef struct Metrics {
    /**
     * Font size in pixels
     */
    float font_size;
    /**
     * Line height in pixels
     */
    float line_height;
} Metrics;

typedef struct ColorRGBA {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
} ColorRGBA;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

struct Attrs attrs_constructor(void);

struct Buffer *buffer_constructor(struct FontSystem **font_system, struct Metrics metrics);

void buffer_destructor(struct Buffer *buffer);

void buffer_draw(struct Buffer *buffer,
                 struct FontSystem *font_system,
                 struct SwashCache *swash_cache,
                 struct Color color,
                 void (*draw_fn)(int32_t, int32_t, uint32_t, uint32_t, struct Color));

void buffer_set_size(struct Buffer *buffer,
                     struct FontSystem *font_system,
                     float width,
                     float height);

void buffer_set_text(struct Buffer *buffer,
                     struct FontSystem *font_system,
                     const char *text,
                     struct Attrs attrs,
                     enum Shaping shaping);

void buffer_shape_until_scroll(struct Buffer *buffer, struct FontSystem *font_system, bool prune);

uint8_t color_a(struct Color self);

struct ColorRGBA color_as_rgba(struct Color self);

uint8_t color_b(struct Color self);

uint8_t color_g(struct Color self);

uint8_t color_r(struct Color self);

struct Color color_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

struct FontSystem *font_system_constructor(void);

void font_system_destructor(struct FontSystem *font_system);

struct Metrics metrics_constructor(float font_size, float line_height);

struct SwashCache *swash_cache_constructor(void);

void swash_cache_destructor(struct SwashCache *swash_cache);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#ifdef __cplusplus
} // namespace cosmic_text
#endif // __cplusplus
