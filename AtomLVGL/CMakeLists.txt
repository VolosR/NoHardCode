SET(SOURCES ui_Screen1.c
    ui.c
    ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    fonts/ui_font_BIG.c
    fonts/ui_font_MED.c)

add_library(ui ${SOURCES})
