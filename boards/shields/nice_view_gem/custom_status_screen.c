#include "widgets/screen.h"

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include "assets/quinquefive_24.c"
#include "assets/quinquefive_18.c"
#include "assets/quinquefive_12.c"
#include "assets/quinquefive_8.c"
#include "assets/custom_fonts.h"

#if IS_ENABLED(CONFIG_NICE_VIEW_WIDGET_STATUS)
#if !IS_ENABLED(CONFIG_ZMK_SPLIT) || IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
static struct zmk_widget_screen screen_widget;
#endif
#endif

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen;
    screen = lv_obj_create(NULL);

#if IS_ENABLED(CONFIG_NICE_VIEW_WIDGET_STATUS)
#if !IS_ENABLED(CONFIG_ZMK_SPLIT) || IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
    zmk_widget_screen_init(&screen_widget, screen);
    lv_obj_align(zmk_widget_screen_obj(&screen_widget), LV_ALIGN_TOP_LEFT, 0, 0);
#else
    lv_obj_t *label = lv_label_create(screen);
    lv_label_set_text(label, "Toucan");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
#endif
#endif

    return screen;
}
