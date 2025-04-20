#pragma once

enum { LOG_TRACE, LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_FATAL };

extern int verbose;

#define log_trace(...) if (verbose) log_def(LOG_TRACE,  __VA_ARGS__)
#define log_debug(...) if (verbose) log_def(LOG_DEBUG,  __VA_ARGS__)
#define log_info(...)  log_def(LOG_INFO,   __VA_ARGS__)
#define log_warn(...)  log_def(LOG_WARN,   __VA_ARGS__)
#define log_error(...) log_def(LOG_ERROR,  __VA_ARGS__)
#define log_fatal(...) log_def(LOG_FATAL,  __VA_ARGS__)

static const char *log_level_strings[] = {
    "TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL"
};

static void log_def(int level, const char *fmt, ...) {
    va_list ap;
    fprintf(stderr, "[%-8s]  ",log_level_strings[level]);

    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);

    fflush(stderr);
}