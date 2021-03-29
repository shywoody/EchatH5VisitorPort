//
//  Echat_accessConditions.h
//  EchatSDKDemo
//
//  Created by xll on 2018/6/22.
//  Copyright © 2018年 xielang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Echat_visEvtModel.h"
@interface Echat_accessConditions : NSObject<NSCoding>
///会员数据参数
@property (nonatomic,copy) NSString  * metaData;

///唯一标识,解除绑定会员绑定需要传递
@property (nonatomic,copy) NSString * uid;

///自定义扩展参数
@property (nonatomic,copy) NSString  * myData;

///消息推送字段
@property (nonatomic,copy) NSString  * pushInfo;

///入口/入口标签
@property (nonatomic,copy) NSString  * echatTag;

///自定义对话窗口语言
@property (nonatomic,copy) NSString  * lan;

///图文消息
@property (nonatomic,strong) Echat_visEvtModel  * visEvt;

///指派接待客服的ID
@property (nonatomic,copy) NSString * acdStaffId;

///分配优先级，0-优先，1-指派
@property (nonatomic,copy) NSString * acdType;

///咨询入口id
@property (nonatomic,copy) NSString * routeEntranceId;


@end
