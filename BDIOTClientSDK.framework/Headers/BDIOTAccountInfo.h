//
//  BDIOTAccountInfo.h
//  BDIOTClientSDK
//
//  Created by guminghua on 15/11/10.
//  Copyright © 2015年 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
//todo
//NSString* const BDIOTUserTypeEnum[] = {
//    @"APP",
//    @"ACCOUNT_DEVICE_BIND",
//    @"ACCOUNT_APP_BIND",
//    @"USER_BAIDU_PASSPORT",
//};
//
//BOOL IsInBDIOTUserTypeEnum(NSString* str){
//    for(int i = 0; i < countof(BDIOTUserTypeEnum); i++){
//        if([str isEqualToString:BDIOTUserTypeEnum[i]]){
//            return YES;
//        }
//    }
//    return FALSE;
//}

@interface BDIOTAccountInfo : NSObject

@property (nonatomic, copy) NSString *userName;

@property (nonatomic, copy) NSString *displayName;

@property (nonatomic, copy) NSString *uuid;

@end
