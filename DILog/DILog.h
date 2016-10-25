//
//  DILog.h
//  DILog
//
//  Created by Back on 2016/10/25.
//  Copyright © 2016年 Back. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for DILog.
FOUNDATION_EXPORT double DILogVersionNumber;

//! Project version string for DILog.
FOUNDATION_EXPORT const unsigned char DILogVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <DILog/PublicHeader.h>

#ifndef DILog_h
#define DILog_h

#include "XCodeColors.h"

#define nsFileString [[NSString stringWithUTF8String:__FILE__] substringFromIndex:1+[[NSString stringWithUTF8String:__FILE__] rangeOfCharacterFromSet:[NSCharacterSet characterSetWithCharactersInString:@"/"] options:NSBackwardsSearch].location]
#define DILogString(logType,format,...) [NSString stringWithFormat:@"[%@ %d]\n%@ %@",nsStringOfYellow(nsFileString),__LINE__,logType,nsStringOfGreen(([NSString stringWithFormat:format, ##__VA_ARGS__]))]

//日志分级制度
//#define DEBUG//XCODE默认有Debug定义，即无论是否定义DEBUG，都会输出Debug
#define DI_INFO nsStringOfLight(@"[I]")
#define DI_WARN nsStringOfOrange(@"[W]")
#define DI_DEBUG nsStringOfCyan(@"[D]")
#define DI_ERROR nsStringOfMagent(@"[E]")
#define DI_FATAL nsStringOfRed(@"[F]")
//#define DI_NOTICE "[N]"

#ifdef DI_DEBUG //DEBUG Level指出细粒度信息事件对调试应用程序是非常有帮助的。
#define DebugLog(format, ...) NSLog(@"%@\n\n",DILogString(DI_DEBUG,format,##__VA_ARGS__))
#define DebugLogWhile(assert,format,...) if(assert)NSLog(@"%@",DILogString(DI_DEBUG,format,##__VA_ARGS__))
#else
#define DebugLog(format, ...)
#define DebugLogWhile(assert,format,...)
#endif

#ifdef DI_INFO //INFO level表明 消息在粗粒度级别上突出强调应用程序的运行过程。
#define InfoLog(format, ...) NSLog(@"%@",DILogString(DI_INFO,format,##__VA_ARGS__))
#define InfoLogWhile(assert,format,...) if(assert)NSLog(@"%@",DILogString(DI_INFO,format,##__VA_ARGS__))
#else
#define InfoLog(format, ...)
#define InfoLogWhile(assert,format,...)
#endif

#ifdef DI_WARN //WARN level表明会出现潜在错误的情形。
#define WarnLog(format, ...) NSLog(@"%@",DILogString(DI_WARN,format,##__VA_ARGS__))
#define WarnLogWhile(assert,format,...) if(assert)NSLog(@"%@",DILogString(DI_WARN,format,##__VA_ARGS__))
#else
#define WarnLog(format,...)
#define WarnLogWhile(assert,format,...)
#endif

#ifdef DI_ERROR //ERROR level指出虽然发生错误事件，但仍然不影响系统的继续运行。
#define ErrorLog(format, ...) NSLog(@"%@",DILogString(DI_ERROR,format,##__VA_ARGS__))
#define ErrorLogWhile(assert,format,...) if(assert)NSLog(@"%@",DILogString(DI_ERROR,format,##__VA_ARGS__))
#else
#define ErrorLog(format, ...)
#define ErrorLogWhile(assert,format,...)
#endif

#ifdef DI_FATAL //FATAL level指出每个严重的错误事件将会导致应用程序的退出。
#define FatalLog(format, ...) NSLog(@"%@",DILogString(DI_FATAL,format,##__VA_ARGS__))
#define FatalLogWhile(assert,format,...) if(assert)NSLog(@"%@",DILogString(DI_FATAL,format,##__VA_ARGS__))
#else
#define FatalLog(format, ...)
#define FatalLogWhile(assert,format,...)
#endif

#ifdef DI_NOTICE //NOTICE level基础消息。
#define NoticeLog(format, ...) NSLog(@"%@",DILogString(DI_NOTICE,format,##__VA_ARGS__))
#define NoticeLogWhile(assert,format,...) if(assert)NSLog(@"%@",DILogString(DI_NOTICE,format,##__VA_ARGS__))
#else
#define NoticeLog(format, ...)
#define NoticeLogWhile(assert,format,...)
#endif

#endif /* DILog_h */
