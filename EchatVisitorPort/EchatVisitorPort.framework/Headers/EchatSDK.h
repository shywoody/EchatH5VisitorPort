//
//  EchatSDK.h
//  EchatSDKDemo
//
//  Created by mac on 2018/7/19.
//  Copyright © 2018年 xielang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Echat_MsgModel.h"
#import "EchatSubscribeMsgModel.h"

@class EchatWSManager;
@class EchatViewController;
@class Echat_accessConditions;
@class Echat_visEvtModel;

typedef void(^UnReadMsgBlock)(Echat_MsgModel * unReadMsg);
typedef void(^LastMsgBlock)(Echat_MsgModel * model);
typedef void(^UnReadMsgCountBlock)(NSUInteger count);
typedef void(^SubscribeMsgCountBlock)(EchatSubscribeMsgModel * model);


@interface EchatSDK : NSObject
@property(nonatomic,readonly,assign) BOOL openDebug;
@property(nonatomic,assign) double tm;


+(instancetype)share;

/**
* @brief 初始化
*/
+(void)AppID:(NSString *)appid AppSecret:(NSString *)appsecret;


/**
* @brief 关闭默认推送UI
* @param isClose 是否关闭SDK默认推送UI
*/
+(void)echat_closeDefaultNotification:(BOOL)isClose;


/**
* @brief 上传gif
* @param isOpen 是否关闭位置信息功能,需要引用EchatCommen和引入高德地图
*/
+(void)echat_OpenDefaultLocationFunction:(BOOL)isOpen;


/**
* @brief 远程推送注入token
* @param deviceToken 如果需要Echat来推送未读消息需要调用该方法传入Token
*/
+(void)echat_registPushInfo:(NSData *)deviceToken;


/**
* @brief 静态获取未读消息总数
* @return 返回未读消息总数
*/
+(NSUInteger)getUnReadMsgCount;


/**
* @brief 动态获取未读消息数
* @param callBack 回调动态返回msgModel
* @return 返回未读消息总数
*/
+(NSUInteger)getUnReadMsgCountCallBack:(UnReadMsgCountBlock)callBack;


/**
* @brief 静态获取最后一条消息
* @return 返回最后一条消息
*/
+(Echat_MsgModel *)getLastMsg;


/**
* @brief 动态获取最后一条消息
* @param type 选择最后一条消息的类型
* @param callBack 回调动态返回msgmodel
*/
+(void)getLastMsgByMsgType:(Echat_MsgType)type Compete:(LastMsgBlock)callBack;


/**
* @brief 动态获取未读消息。(用于开发者自行接管推送)
* @param callBack 回调动态返回msgmodel
*/
+(void)getUnReadMsgCallBack:(UnReadMsgBlock)callBack;


/**
* @brief 订阅消息
* @param type 选择订阅的消息类型,目前只支持排队信息的订阅
* @param complete 回调动态返回subScribeMsgmodel
*/
+(void)subscribeMessageByMsgType:(EchatSubscribeMsgType)type Complete:(SubscribeMsgCountBlock)complete;


/**
* @brief 发送位置信息
* @param info 位置消息字典,格式见文档
*/
+(void)sendLocationInfo:(NSDictionary *)info;


/**
* @brief 获取上一次的身份信息(取最近一次身份)
* @return 返回一个身份model
*/
+(Echat_accessConditions *)getLastCondition;


/**
* @brief 远程推送消息处理(Echat接管)
* @param info 远程推送需要传入info用于更精准的读取未读消息数
*/
+(void)increaseunReadCountWithRemoteInfo:(NSDictionary *)info;

/**
* @brief 远程推送消息处理(客户服务器接管)
* @param jsonString 为Echat推送给客户服务器的echatNotifyData属性字段
* @param content 为Echat推送给客户服务器的远程推送消息内容
*/
+(void)increaseunReadCountWithEchatNotifyDataJsonString:(NSString *)jsonString andContent:(NSString * )content;


/**
* @brief 发送图文
* @param model 图文消息模型
* @param metaData 如果有会员信息需要传入metaData如果没可以传nil
* @param complete 成功回调
* @param failure 失败回调
*/
+(void)echat_sendVisEvtWithVisEventModel:(Echat_visEvtModel *)model MetaData:(NSString * )metaData Complete:(dispatch_block_t)complete Failure:(dispatch_block_t)failure;

/**
* @brief 获取服务端未读消息数
* @param metaData 如果有会员信息需要传入metaData如果没可以传nil
* @param complete 成功回调
*/
+(void)echat_getUnReadMsgCountWithMetaData:(NSString * )metaData Complete:(void (^)(NSInteger count))complete;

/**
* @brief 匿名访客转VIP
* @param metaStr 会员信息加密字符串
* @param myDataStr 额外业务参数
*/
+(void)echat_registMetaData:(NSString *)metaStr myData:(NSString *)myDataStr;

/**
* @brief 获取当前控制器(Echat用于远程推送点击跳转示例方法)
* @return 返回控制器
*/
+(id)getCurrentViewController;

/**
* @brief SDK缓存资源大小
* @return 返回大小
*/
+(double)getMemorySize;

/**
* @brief 清除大文件
*/
+(void)cleanMemory;

/**
* @brief 清除所有文件
*/
+(void)cleanAllMemory;


/**
* @brief 关闭连接
*/
+(void)closeConnect;


/**
* @brief 登出（当退出登陆的时候需要调用）
*/
+(void)logout;

@end
