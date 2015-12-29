//
//  BDIOTWebViewController.h
//  BDIOTClientSDK
//
//  Created by guminghua on 15/11/12.
//  Copyright © 2015年 baidu. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef  void (^BDIOTEmptyBlock)();
@protocol BDIOTLoginWebViewDelegate <NSObject>

-(void)didLoginSucceed:(NSString*)token;

@end

@interface BDIOTLoginWebViewController : UIViewController <UIWebViewDelegate>
@property (nonatomic, weak) id<BDIOTLoginWebViewDelegate> delegate;
@property (nonatomic, copy) NSString *url;
@property (nonatomic, strong) UIWebView *webView;
@property (nonatomic, strong) UIButton *closeBtn;
@property (nonatomic, strong) BDIOTEmptyBlock updatingBlock;
@property (nonatomic, strong) BDIOTEmptyBlock updateFinishBlock;
@end
