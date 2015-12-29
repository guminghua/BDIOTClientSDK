//
//  BDIOTTaskStatus.h
//  BDIOTClientSDK
//
//  Created by guminghua on 15/11/10.
//  Copyright © 2015年 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BDIOTTaskStatus : NSObject

@property (nonatomic, assign) NSInteger SUSPENDED;

@property (nonatomic, assign) NSInteger ABORTED;

@property (nonatomic, assign) NSInteger PUBLISHED;

@property (nonatomic, assign) NSInteger RUNNING;

@property (nonatomic, assign) NSInteger RUNNABLE;

@property (nonatomic, assign) NSInteger DELETED;

@property (nonatomic, assign) NSInteger FINISHED;

@end
