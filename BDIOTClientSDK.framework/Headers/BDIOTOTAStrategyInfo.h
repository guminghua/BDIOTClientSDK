//
//  BDIOTDeviceStrategy.h
//  BDIOTClientSDK
//
//  Created by guminghua on 15/11/10.
//  Copyright © 2015年 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BDIOTOTAStrategyInfo : NSObject

@property (nonatomic, copy) NSString *status;

@property (nonatomic, assign) NSInteger id;

@property (nonatomic, copy) NSString *updateTime;

@property (nonatomic, assign) NSInteger batchId;

@property (nonatomic, assign) NSInteger packageId;

@property (nonatomic, copy) NSString *type;

@property (nonatomic, copy) NSDate *createTime;

@end
