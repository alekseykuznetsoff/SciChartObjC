//
//  KADataManager.h
//  SciChartObjC
//
//  Created by Kuznetsov Aleksey on 11.06.17.
//  Copyright © 2017 Kuznetsov Aleksey. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Macro.h"

@interface KADataManager : NSObject

+ (instancetype)sharedInstance;

- (void)loadPointsWithCount:(NSUInteger)count
                   callback:(KACallbackBlock)callback;

- (void)loadDataWithCallback:(KACallbackBlock)callback;
- (void)abortLoadingData;

@end
