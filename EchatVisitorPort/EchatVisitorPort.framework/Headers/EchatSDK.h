//
//  EchatSDK.h
//  EchatSDKDemo
//
//  Created by mac on 2018/7/19.
//  Copyright © 2018年 xielang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Echat_unReadMsg.h"
@class EchatWSManager;
@class EchatViewController;
@class Echat_accessConditions;

typedef void(^UnReadMsgBlock)(Echat_unReadMsg * unReadMsg);
typedef void(^UnReadMsgCountBlock)(NSInteger count);
@interface EchatSDK : NSObject
@property(nonatomic,readonly,assign) BOOL openDebug;
@property(nonatomic,copy) UnReadMsgBlock unreadMsgCallBack;
@property (nonatomic,copy) UnReadMsgCountBlock unReadMsgCountCallBack;

+(instancetype)share;
+(void)AppID:(NSString *)appid AppSecret:(NSString *)appsecret;
+(void)setDebug:(BOOL)isdebug;
+(void)echat_closeDefaultNotification:(BOOL)isClose;
+(void)echat_OpenDefaultLocationFunction:(BOOL)isClose;
+(void)echat_registPushInfo:(NSData *)deviceToken isThirdPush:(BOOL)istp;
+(id)getCurrentViewController;//获取当前控制器
+(NSInteger)getUnReadMsgCount;
+(void)sendLocationInfo:(NSDictionary *)info;
+(Echat_accessConditions *)getLastCondition;
///远程推送含有未读消息总数的处理
+(void)increase:(NSInteger)count;

+(void)closeConnect;

///账号登出
+(void)logout;
///文件缓存大小
+(double)getMemorySize;
//清除缓存
-(void)cleanMemory;
@end
