//
//  BDIOTAccountService.h
//  BDIOTClientSDK
//
//  Created by guminghua on 15/11/11.
//  Copyright © 2015年 baidu. All rights reserved.
//

#import "BDIOTService.h"
#import "BDIOTAccountInfo.h"
#import "BDIOTSDKManager.h"
#import <UIKit/UIKit.h>
#import "BDIOTLoginWebViewController.h"
#import "BDIOTServerErrorInfo.h"
#import "BDIOTPagingInfo.h"

@class BDIOTErrorWrapper;
typedef void (^GetAccountInfoHandleBlock)(BDIOTErrorWrapper*  __nonnull  errorWrapper, BDIOTAccountInfo*  __nullable  info);


@protocol BDIOTAccountServiceDelegate <NSObject>
@required
/**
 *  登录结束回调。如果没有收到此回调说明登录还没有完成或者已经登录失败。
 *
 *  @param accountInfo 登录结束后拿到的账户信息
 *  @param token       登录结束后拿到的token
 */
-(void)didLoginFinished:(BDIOTAccountInfo*  __nonnull )accountInfo
				  token:(NSString* __nonnull )token;
@end




@interface BDIOTAccountService : BDIOTService<BDIOTLoginWebViewDelegate>

@property id<BDIOTAccountServiceDelegate>   __nonnull delegate;

/**
 *  登录接口，调用后会弹出百度登录webview。要求outViewController的navigationcontroller存在。
 *
 *  @param outViewController 外部viewcontroller
 *  @param state             oauth2 中的state字段
 */
-(void)login:(UIViewController* __nonnull )outViewController
navigationViewController:(UINavigationController*  __nullable )navigationViewController
	   state:(NSString*  __nonnull )state
webViewUpdatingBlock:(BDIOTEmptyBlock __nullable)webViewUpdatingBlock
webViewUpdateFinishBlock:(BDIOTEmptyBlock __nullable)webViewUpdateFinishBlock;

/**
 *  获取账户信息。需要提前设置BDIOTSDKManager.token变量。
 *
 *  @param handleBlock 接收回调。
 */
-(void)getAccountInfo:(GetAccountInfoHandleBlock  __nonnull )handleBlock;

@end
