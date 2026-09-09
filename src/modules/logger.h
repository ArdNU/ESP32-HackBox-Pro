#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>
#include "../config.h"

class Logger {
public:
    enum LogLevel { DEBUG = 0, INFO = 1, WARN = 2, ERROR = 3 };
    
    Logger() : current_level(LOG_LEVEL) {}
    
    void setLevel(LogLevel level) {
        current_level = level;
    }
    
    void debug(const char* format, ...) {
        if (current_level <= DEBUG) log("[DEBUG]", format);
    }
    
    void info(const char* format, ...) {
        if (current_level <= INFO) log("[INFO]", format);
    }
    
    void warn(const char* format, ...) {
        if (current_level <= WARN) log("[WARN]", format);
    }
    
    void error(const char* format, ...) {
        if (current_level <= ERROR) log("[ERROR]", format);
    }
    
private:
    LogLevel current_level;
    
    void log(const char* level, const char* format) {
        char buffer[256];
        va_list args;
        va_start(args, format);
        vsnprintf(buffer, sizeof(buffer), format, args);
        va_end(args);
        
        Serial.print(level);
        Serial.print(" ");
        Serial.println(buffer);
    }
};

#endif // LOGGER_H
