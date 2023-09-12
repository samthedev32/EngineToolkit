#include <EngineToolkit/log/log.hpp>
#include <bits/types/time_t.h>
#include <cstdarg>
#include <cstdio>
#include <ctime>

namespace Log {

void stime(char *str) {
  time_t rawtime;
  struct tm *timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);

  sprintf(str, "%d.%d.%d %d:%d:%d", timeinfo->tm_year + 1900,
          timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour,
          timeinfo->tm_min, timeinfo->tm_sec);
}

void vcustom(char type, const char *tag, const char *message, va_list args) {
  // TODO: tag cutting

  char msg[1024];
  char date[32];
  stime(date);

  sprintf(msg, "[%s] %s [%c]  %s\n", date, tag, type, message);

  // Print Out
  vprintf(msg, args);

  // TODO: Write to File
}

void debug(const char *tag, const char *message, ...) {
#ifndef NDEBUG
  va_list args;
  va_start(args, message);

  vcustom('D', tag, message, args);

  va_end(args);
#endif
}

void verbose(const char *tag, const char *message, ...) {
  va_list args;
  va_start(args, message);

  vcustom('V', tag, message, args);

  va_end(args);
}

void warning(const char *tag, const char *message, ...) {
  va_list args;
  va_start(args, message);

  vcustom('W', tag, message, args);

  va_end(args);
}

void error(const char *tag, const char *message, ...) {
  va_list args;
  va_start(args, message);

  vcustom('E', tag, message, args);

  va_end(args);
}

} // namespace Log

// #include <Cutil/log.h>

// #include <stdio.h>
// #include <string.h>
// #include <time.h>

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
