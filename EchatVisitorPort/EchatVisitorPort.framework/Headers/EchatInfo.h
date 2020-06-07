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

UIKIT_EXTERN NSString * const Echat_AppID;

UIKIT_EXTERN NSString * const Echat_AppSecret;

UIKIT_EXTERN NSString * const Echat_encryptVID;

UIKIT_EXTERN NSString * const Echat_companyId;

UIKIT_EXTERN NSString * const Echat_messageGroupId;

UIKIT_EXTERN NSString * const Echat_talkId;

UIKIT_EXTERN NSString * const Echat_talkType;

UIKIT_EXTERN NSString * const Echat_mid;

UIKIT_EXTERN NSString * const Echat_visitorId;

UIKIT_EXTERN NSString * const Echat_conversationStatus;

UIKIT_EXTERN NSString * const Echat_BizStatus;

UIKIT_EXTERN NSString * const Echat_isOnChatWeb;

UIKIT_EXTERN NSString * const Echat_isNeededConnect4netColse;

UIKIT_EXTERN NSString * const Echat_isReceive10009;

UIKIT_EXTERN NSString * const Echat_isEnterBackGround;

UIKIT_EXTERN NSString * const Echat_unReadcount;

UIKIT_EXTERN NSString * const EchatlocalVersion;

UIKIT_EXTERN NSString * const EchatHtmlLocalVersion;

UIKIT_EXTERN NSString * const EchatUnReadVersion;

UIKIT_EXTERN NSString * const Echat_Crash;

UIKIT_EXTERN NSString * const Echat_apiServerDomain;

UIKIT_EXTERN NSString * const Echat_uploadOverSize;

UIKIT_EXTERN NSString * const Echat_lastMsg;



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
    EchatConversationStatusNone = 1,
    EchatConversationWait2Connect = 2,
    EchatConversationIsChatting = 3,
    EchatConversationLeaveMsg = 4,
    EChatConversationRobot = 5,
    EChatConversationCannotLeaveMsg = 6,
    Echat10009Close = 7,
    EchatUserClose = 8,
    EchatSerClose = 9,
    EChatCloseWS = 10,
    EchatReContectWS = 11,
    EchatWait4Serve = 12,
    EchatReconnectChat = 13,
    EchatDisConnect = 14,
    EChatConversationThirdURL = 15,
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

    EChatBizNone = 1,

    EChatBizWait2Connect = 2,

    EChatBizNormalChat = 3,

    EChatBizLeaveMsg = 4,

    EChatBizCannotLeaveMsg = 5,

    EchatBizRobot = 8,
};


#define EchatPerference [NSUserDefaults standardUserDefaults]


#define EchatLocalized(x) [NSBundle Echat_localizedStringForKey:x]


#ifndef Echat_dispatch_main_async_safe
#define Echat_dispatch_main_async_safe(block)\
if (strcmp(dispatch_queue_get_label(DISPATCH_CURRENT_QUEUE_LABEL), dispatch_queue_get_label(dispatch_get_main_queue())) == 0) {\
block();\
} else {\
dispatch_async(dispatch_get_main_queue(), block);\
}
#endif

#define EchatDebug [EchatSDK share].openDebug
#ifdef RELEASE
#define EchatLog(fmt, ...)  if(EchatDebug) {\
NSLog((@"ECHATLOG--> %s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);\
}else {}
#else
#define EchatLog(...)
#endif


