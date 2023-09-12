#pragma once

namespace Log {
void custom(char letter, const char *tag, const char *message, ...);

void debug(const char *tag, const char *message, ...);
void verbose(const char *tag, const char *message, ...);
void warning(const char *tag, const char *message, ...);
void error(const char *tag, const char *message, ...);
}; // namespace Log