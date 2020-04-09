//
//  EchatInfo.h
//  EchatSDKDemo
//
//  Created by xll on 2018/3/30.
//  Copyright © 2018年 xielang. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "EchatSDK.h"
UIKIT_EXTERN NSString * const EchatWebUrl;

UIKIT_EXTERN NSString * const EchatDBFileName;

UIKIT_EXTERN NSString * const EchatWSMessageTableName;

UIKIT_EXTERN NSString * const EchatTalkIdTableName;

UIKIT_EXTERN NSString * const EchatConfigureTableName;

UIKIT_EXTERN NSString * const EchatStaffsTableName;

UIKIT_EXTERN NSString * const EchatLocalRuleTableName;

UIKIT_EXTERN NSString * const Echat_CloseChat;

UIKIT_EXTERN NSString * const Echat_EndHistoryFromDBNoti;

UIKIT_EXTERN NSString * const Echat_NetStatusNoti;

UIKIT_EXTERN NSString * const Echat_ReconnectWSNoti;

UIKIT_EXTERN NSString * const Echat_AppID;///appId

UIKIT_EXTERN NSString * const Echat_AppSecret;///appSecret

UIKIT_EXTERN NSString * const Echat_encryptVID;///encryptVID

UIKIT_EXTERN NSString * const Echat_companyId;///companyId

UIKIT_EXTERN NSString * const Echat_messageGroupId;///messageGroupId

UIKIT_EXTERN NSString * const Echat_talkId;///talkId

UIKIT_EXTERN NSString * const Echat_talkType;///talkType

UIKIT_EXTERN NSString * const Echat_mid; ///mid

UIKIT_EXTERN NSString * const Echat_visitorId;///用户id

UIKIT_EXTERN NSString * const Echat_conversationStatus;///对话状态

UIKIT_EXTERN NSString * const Echat_BizStatus;///业务状态

UIKIT_EXTERN NSString * const Echat_isOnChatWeb;///是否在聊天页面

UIKIT_EXTERN NSString * const Echat_isNeededConnect4netColse;///是否需要断网重连

UIKIT_EXTERN NSString * const Echat_isReceive10009;///是否收到10009消息

UIKIT_EXTERN NSString * const Echat_isEnterBackGround;//是否退到后台

UIKIT_EXTERN NSString * const Echat_unReadcount;

UIKIT_EXTERN NSString * const EchatlocalVersion;

UIKIT_EXTERN NSString * const EchatHtmlLocalVersion;

UIKIT_EXTERN NSString * const EchatUnReadVersion;

UIKIT_EXTERN NSString * const Echat_Crash;

UIKIT_EXTERN NSString * const Echat_apiServerDomain;

UIKIT_EXTERN NSString * const Echat_uploadOverSize;

UIKIT_EXTERN NSString * const Echat_lastMsg;


//fucName2H5
UIKIT_EXTERN NSString * const Echat_Fuc_getMessage;
UIKIT_EXTERN NSString * const Echat_Fuc_msgFromDB;
UIKIT_EXTERN NSString * const Echat_Fuc_deliverTalkId2H5;

///Echat_UserStatus
typedef NS_ENUM (NSInteger, EChatNetStatus) {
    EchatNotReach = 0,//无网
    EchatWifi = 1, //wifi
    EChatwwan = 2, //wwan

};

///对话状态状态
typedef NS_ENUM (NSInteger, EChatConversationStatus) {
    EchatConversationStatusNone = 1,//无状态
    EchatConversationWait2Connect = 2,//等待连接（握手成功）
    EchatConversationIsChatting = 3, //正在对话
    EchatConversationLeaveMsg = 4, //留言
    EChatConversationRobot = 5, //机器人
    EChatConversationCannotLeaveMsg = 6, //禁止留言状态
    //    EChatConversationCannotStaffNotOnLine = 6, //客服离线
    Echat10009Close = 7,//10009关闭
    EchatUserClose = 8,//用户关闭对话
    EchatSerClose = 9,//服务器关闭对话
    EChatCloseWS = 10,//关闭WS
    EchatReContectWS = 11, //重连WS
    EchatWait4Serve = 12,//排队状态
    EchatReconnectChat = 13, //重连对话
    EchatDisConnect = 14,
    EChatConversationThirdURL = 15,//留言跳转
};

///上传文件类型
typedef NS_ENUM (NSInteger, Echat_UPLoadFileType) {
    EchatUPLoad_ScreenShotType =1,
    EchatUPLoad_FilesOrImageType =2,
    EchatUPLoad_VoiceType =3,
    EchatUPLoad_VideoType =4,
    EchatUPLoad_base64Image =5
};

///业务状态
typedef NS_ENUM (NSInteger, EChatBizStatus) {
    ///无状态
    EChatBizNone = 1,
    ///等待接入
    EChatBizWait2Connect = 2,
    ///普通会话中
    EChatBizNormalChat = 3,
    ///留言
    EChatBizLeaveMsg = 4,
    ///禁止留言
    EChatBizCannotLeaveMsg = 5,
    ///机器人会话中
    EchatBizRobot = 8,
};

//偏好
#define EchatPerference [NSUserDefaults standardUserDefaults]

//本地化
#define EchatLocalized(x) [NSBundle Echat_localizedStringForKey:x]

//回到主线程
#ifndef Echat_dispatch_main_async_safe
#define Echat_dispatch_main_async_safe(block)\
if (strcmp(dispatch_queue_get_label(DISPATCH_CURRENT_QUEUE_LABEL), dispatch_queue_get_label(dispatch_get_main_queue())) == 0) {\
block();\
} else {\
dispatch_async(dispatch_get_main_queue(), block);\
}
#endif

#define EchatDebug [EchatSDK share].openDebug
#ifdef DEBUG
#define EchatLog(fmt, ...)  if(EchatDebug) {\
NSLog((@"ECHATLOG--> %s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);\
}else {}
#else
#define EchatLog(...)
#endif

//---------------------------------------------------------------------
//#define EchatTabBarHeight ([[UIApplication sharedApplication] statusBarFrame].size.height>20?83:49)

