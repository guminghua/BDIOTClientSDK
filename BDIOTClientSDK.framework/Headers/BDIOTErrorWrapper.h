//
//  BDIOTErrorWrapper.h
//  BDIOTClientSDK
//
//  Created by guminghua on 15/11/27.
//  Copyright © 2015年 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, BDIOTError) {
	BDIOTErrorOk = 0,
	BDIOTErrorLocalError,
	BDIOTErrorHttpError,
	BDIOTErrorServerError,
	
	BDIOTErrorTokenNill = 100
};

typedef NS_ENUM(NSInteger, BDIOTLocalError) {
	BDIOTLocalErrorTokenNil = 0
};

@interface BDIOTErrorWrapper : NSObject<NSCopying>
@property (nonatomic, assign) BDIOTError errorType;
@property (nonatomic, assign) BDIOTLocalError   localErrorCode; //todo
@property (nonatomic, copy) NSString*  __nonnull localErrorMessage;
@property (nonatomic, assign) NSInteger   serverErrorCode; //todo
@property (nonatomic, copy) NSString*  __nonnull serverErrorMessage;


-(instancetype __nonnull ) initWithLocalError:(BDIOTLocalError)code
						   message:(NSString* __nonnull )message;
@end
