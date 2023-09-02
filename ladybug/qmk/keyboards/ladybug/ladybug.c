#include "ladybug.h"

void keyboard_pre_init_kb(void) {
    setPinOutput(CAPS_LOCK_PIN);
    writePin(CAPS_LOCK_PIN, false);

    keyboard_pre_init_user();
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res) {
        writePin(CAPS_LOCK_PIN, led_state.caps_lock);
    }
    return res;
}
