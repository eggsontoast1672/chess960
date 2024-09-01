#pragma once

/**
 * Utility function for logging error messages to stderr. It works just like
 * printf since the format and arguments are forwarded to vfprintf. It will
 * insert a newline after the supplied format, so there is no need to provide
 * one.
 */
void log_error(const char *format, ...);

/**
 * Utility function for logging SDL-specific error messages to stderr. It gets
 * the error message by calling SDL_GetError. Like other logging functions in
 * this file, it forwards the arguments it receives to vfprintf.
 */
void log_sdl_error(const char *format, ...);
