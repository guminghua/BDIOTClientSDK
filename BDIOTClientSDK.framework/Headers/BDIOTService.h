//
//  BDIOTService.h
//  BDIOTClientSDK
//
//  Created by guminghua on 15/11/10.
//  Copyright © 2015年 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BDIOTService : NSObject
@property (nonatomic, copy) NSString *  __nonnull name;
-(instancetype  __nonnull )initWithName:(NSString*  __nonnull )name;
@end
