#pragma once

#include "defines.h"

typedef struct platform_state {
    void* internal_state;
} platform_state;

__declspec(dllexport) b8 platform_startup (
    platform_state* plat_state,
    const char* application_name,
    i32 x,
    i32 y,
    i32 widght,
    i32 height
);

__declspec(dllexport) void platform_shutdown(platform_state* plat_state);

__declspec(dllexport) b8 platform_pump_message(platform_state* plat_state);

void* platform_allocation(u64 size, b8 aligned);
void* plafrom_free(void* block, b8 aligned);
void* platform_zero_memory(void* block, u64 size);
void* platform_copy_memory(void* dest, const void* source, u64 size);
void* platform_set_memory(void* dest, i32 value, u64 size);

void platform_console_write(const char*message, u8 color);
void platform_console_write_error(const char*message, u8 color);

f64 platform_get_absolute_time();

void platform_sleep(u64 ms);