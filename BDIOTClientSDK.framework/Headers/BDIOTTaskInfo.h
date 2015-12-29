//
//  BDIOTDeviceTaskStatus.h
//  BDIOTClientSDK
//
//  Created by guminghua on 15/11/10.
//  Copyright © 2015年 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

#define BDIOTTaskInfoStatusRunnable @"RUNNABLE"
#define BDIOTTaskInfoStatusRunning @"RUNNING"
#define BDIOTTaskInfoStatusSuspended @"SUSPENDED"
#define BDIOTTaskInfoStatusFinished @"FINISHED"
#define BDIOTTaskInfoStatusAborted @"ABORTED"

@interface BDIOTTaskInfo : NSObject

@property (nonatomic, assign) NSInteger taskId;

@property (nonatomic, assign) NSInteger deviceId;

@property (nonatomic, copy) NSString *status;

@property (nonatomic, copy) NSString *deviceResponse;

@property (nonatomic, copy) NSString *code;

@property (nonatomic, copy) NSString *uuid;

@property (nonatomic, copy) NSString *message;

@property (nonatomic, copy) NSDate *createTime;

@property (nonatomic, copy) NSString *relativeUri;

@property (nonatomic, copy) NSString *content;
@end
