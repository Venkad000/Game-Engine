#include <core/log.h>
#include <platform/platform.h>

int main(void) {
    VFATAL("A test messag: %f", 3.14f);
    VWARN("A test messag: %f", 3.14f);
    VINFO("A test messag: %f", 3.14f);
    VDEBUG("A test messag: %f", 3.14f);
    VTRACE("A test messag: %f", 3.14f);

    platform_state state;
    if (platform_startup(&state, "game engine testbed", 100,100,1280,720)) {
        while(TRUE) {
            platform_pump_message(&state);
        }
    }
    platform_shutdown(&state);

    return 0;
}