//
//  BLEResource.h
//  BDIOTClientSDK
//
//  Created by guminghua on 15/12/5.
//  Copyright © 2015年 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BDIOTBLEServices,BDIOTBLECharacteristics;
@interface BDIOTBLEResource : NSObject

@property (nonatomic, strong) NSArray<BDIOTBLEServices *> *services;

@end
@interface BDIOTBLEServices : NSObject

@property (nonatomic, copy) NSString *name;

@property (nonatomic, strong) NSArray<BDIOTBLECharacteristics *> *Characteristics;

@property (nonatomic, copy) NSString *uuid;

@end

@interface BDIOTBLECharacteristics : NSObject

@property (nonatomic, copy) NSString *type;

@property (nonatomic, copy) NSString *name;

@property (nonatomic, copy) NSString *desc;

@property (nonatomic, copy) NSString *uuid;

@end

