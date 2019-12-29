﻿/*
 * MIT License
 *
 * Copyright (c) 2019 xiongziliang <771730766@qq.com>
 *
 * This file is part of ZLMediaKit(https://github.com/xiongziliang/ZLMediaKit).
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef MK_UTIL_H
#define MK_UTIL_H

#include <stdlib.h>
#include "mk_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 获取本程序可执行文件路径
 * @return 文件路径，使用完后需要自己free
 */
API_EXPORT char* API_CALL mk_util_get_exe_path();

/**
 * 获取本程序可执行文件相同目录下文件的绝对路径
 * @param relative_path 同目录下文件的路径相对,可以为null
 * @return 文件路径，使用完后需要自己free
 */
API_EXPORT char* API_CALL mk_uitl_get_exe_dir(const char *relative_path);

/**
 * 获取unix标准的系统时间戳
 * @return 当前系统时间戳
 */
API_EXPORT uint64_t API_CALL mk_uitl_get_current_millisecond();

/**
 * 获取时间字符串
 * @param fmt 时间格式，譬如%Y-%m-%d %H:%M:%S
 * @return 时间字符串，使用完后需要自己free
 */
API_EXPORT char* API_CALL mk_uitl_get_current_time_string(const char *fmt);

/**
 * 打印二进制为字符串
 * @param buf 二进制数据
 * @param len 数据长度
 * @return 可打印的调试信息，使用完后需要自己free
 */
API_EXPORT char* API_CALL mk_uitl_hex_dump(const void *buf, int len);
///////////////////////////////////////////日志/////////////////////////////////////////////

/**
 * 打印日志
 * @param level 日志级别,支持0~4
 * @param file __FILE__
 * @param function __FUNCTION__
 * @param line __LINE__
 * @param fmt printf类型的格式控制字符串
 * @param ... 不定长参数
 */
API_EXPORT void API_CALL mk_log_printf(int level, const char *file, const char *function, int line, const char *fmt, ...);

// 以下宏可以替换printf使用
#define log_trace(fmt,...) mk_log_printf(0,__FILE__,__FUNCTION__,__LINE__,fmt,##__VA_ARGS__)
#define log_debug(fmt,...) mk_log_printf(1,__FILE__,__FUNCTION__,__LINE__,fmt,##__VA_ARGS__)
#define log_info(fmt,...) mk_log_printf(2,__FILE__,__FUNCTION__,__LINE__,fmt,##__VA_ARGS__)
#define log_warn(fmt,...) mk_log_printf(3,__FILE__,__FUNCTION__,__LINE__,fmt,##__VA_ARGS__)
#define log_error(fmt,...) mk_log_printf(4,__FILE__,__FUNCTION__,__LINE__,fmt,##__VA_ARGS__)
#define log_printf(lev,fmt,...) mk_log_printf(lev,__FILE__,__FUNCTION__,__LINE__,fmt,##__VA_ARGS__)

#ifdef __cplusplus
}
#endif
#endif //MK_UTIL_H