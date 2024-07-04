// Copyright (c) 2021 - 2022, Nemes <nemes@nemez.net>
// SPDX-License-Identifier: MIT
// 
// MIT License
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software andassociated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, andto permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// 
// The above copyright notice andthis permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef LOGGER_H
#define LOGGER_H

#ifdef __cplusplus
extern "C" {
#endif

#define LOG_PLAIN(format, ...)          LoggerLogMessage(format, ##__VA_ARGS__)
#define LOG(header, format, ...)        LoggerLogMessage("[" header "] " format, ##__VA_ARGS__)
#define INFO(format, ...)               LOG("INFO ", format, ##__VA_ARGS__)
#define TRACE(format, ...)              LOG("TRACE", format, ##__VA_ARGS__)
#define DEBUG(format, ...)              LOG("DEBUG", format, ##__VA_ARGS__)
#define WARNING(format, ...)            LOG("WARN ", format, ##__VA_ARGS__)
#define FATAL(format, ...)              LOG("FATAL", format, ##__VA_ARGS__)
#define ABORT(code)                     LOG("ABORT", "0x%08lx %s\n", code, LoggerLookUpError(code))
#define SEPARATOR()                     LoggerLogMessage("[SEPAR] ------------------------------------------\n")
#define LOG_RESULT(id, key_fmt, value_fmt, key, value)  LOG("RESLT", "%lu: " key_fmt " = " value_fmt "\n", id, key, value)

test_status LoggerLogMessage(const char *format, ...);
const char *LoggerLookUpError(test_status status);

#ifdef __cplusplus
}
#endif
#endif