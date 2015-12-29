//
//  BDIOTSDKManager.h
//  BDIOTClientSDK
//
//  Created by guminghua on 15/11/10.
//  Copyright © 2015年 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>


@class BDIOTAccountService;
@class BDIOTDeviceService;
@class BDIOTAIService;
@class BDIOTOTAService;
@class BDIOTAppInfo;

typedef NS_ENUM(NSUInteger, BDIOTLogLevel) {
	BDIOTLogLevelOff       = 0,
	BDIOTLogLevelError,
	BDIOTLogLevelInfo,
	BDIOTLogLevelAll
};

@interface BDIOTSDKManager : NSObject
@property (nonatomic, assign) BDIOTLogLevel logLevel;
@property (nonatomic, strong, readonly) BDIOTAccountService*  __nonnull accountService;
@property (nonatomic, strong, readonly) BDIOTDeviceService* __nonnull  deviceService;
@property (nonatomic, strong, readonly) BDIOTAIService*  __nonnull AIService;
@property (nonatomic, strong, readonly) BDIOTOTAService* __nonnull  OTAService;
@property (nonatomic, copy) NSString* __nullable token;

/**
 *  设置app的信息。
 *
 *  @param appId     appid
 *  @param secretKey secretid
 */
-(void)setAppInfo:(NSString* __nonnull )appKey;

/**
 *  获得BDIOTSDKManager实例
 *
 *  @return BDIOTSDKManager实例
 */
+ (BDIOTSDKManager* __nonnull ) sharedInstance;
@end
