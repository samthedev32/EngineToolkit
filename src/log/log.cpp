#include <EngineToolkit/log/log.hpp>
#include <cstdarg>
#include <cstdio>

using namespace Log;

void custom(char type, const char *tag, const char *message, ...) {
  va_list args;
  va_start(args, message);

  va_end(args);
}

void debug(const char *tag, const char *message, ...) {}

void verbose(const char *tag, const char *message, ...) {}

void warning(const char *tag, const char *message, ...) {}

void error(const char *tag, const char *message, ...) {}

// #include <Cutil/log.h>

// #include <stdio.h>
// #include <string.h>
// #include <time.h>

// // Enable/Disable Logging
// int log_enable_system = 1;
// int log_enable_debug = 1;
// int log_enable_warning = 1;
// int log_enable_error = 1;

// void log_show_system(int en) { log_enable_system = en; }
// void log_show_debug(int en) { log_enable_debug = en; }
// void log_show_warning(int en) { log_enable_warning = en; }
// void log_show_error(int en) { log_enable_error = en; }

// // Get Time as String
// void stime(char *str) {
//   time_t rawtime;
//   struct tm *timeinfo;
//   time(&rawtime);
//   timeinfo = localtime(&rawtime);

//   sprintf(str, "%d.%d.%d %d:%d:%d", timeinfo->tm_year + 1900,
//           timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour,
//           timeinfo->tm_min, timeinfo->tm_sec);
// }

// void log_vcustom(char type, const char *tag, const char *message,
//                  va_list args) {
//   // TODO: tag cutting

//   char msg[1024];
//   char date[32];
//   stime(date);

//   sprintf(msg, "[%s] %s [%c]  %s\n", date, tag, type, message);

//   // Print Out
//   vprintf(msg, args);

//   // TODO: Write to File
// }

// void log_system(const char *tag, const char *message, ...) {
//   va_list args;
//   va_start(args, message);

//   if (log_enable_system)
//     log_vcustom('S', tag, message, args);

//   va_end(args);
// }

// void log_debug(const char *tag, const char *message, ...) {
//   va_list args;
//   va_start(args, message);

//   if (log_enable_debug)
//     log_vcustom('D', tag, message, args);

//   va_end(args);
// }

// void log_warning(const char *tag, const char *message, ...) {
//   va_list args;
//   va_start(args, message);

//   if (log_enable_warning)
//     log_vcustom('W', tag, message, args);

//   va_end(args);
// }

// void log_error(const char *tag, const char *message, ...) {
//   va_list args;
//   va_start(args, message);

//   if (log_enable_error)
//     log_vcustom('E', tag, message, args);

//   va_end(args);
// }