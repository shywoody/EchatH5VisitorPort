//
//  Echat_unReadMsg.h
//  EchatVisitorPort
//
//  Created by mac on 2019/3/28.
//  Copyright © 2019年 mac. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, Echat_MsgType){
    EchatVisitorMsgType = 1 << 0,    //访客发送消息
    EchatCustomerMsgType = 1 << 1,   //客服消息
    EchatSystemMsgType = 1 << 2,     //系统消息
    EchatAllMsgType = 1 << 3,     //所有类型
};

@interface Echat_MsgModel : NSObject

///标题
@property(nonatomic,copy) NSString * title;

///内容
@property(nonatomic,copy) NSString * content;

///获取未读消息中判断是否需要进行本地推送
@property(nonatomic,assign) BOOL isNeededLocalPush;

///类型
@property(nonatomic,assign) Echat_MsgType msgType;

@end
