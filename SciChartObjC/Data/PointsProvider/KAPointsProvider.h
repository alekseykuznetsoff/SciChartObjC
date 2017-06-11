//
//  KAPointsProvider.h
//  SciChartObjC
//
//  Created by Kuznetsov Aleksey on 11.06.17.
//  Copyright © 2017 Kuznetsov Aleksey. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Macro.h"

@interface KAPointsProvider : NSObject

- (void)loadPointsWithCount:(NSUInteger)count
                   callback:(KACallbackBlock)callback;

- (void)startWithCallback:(KACallbackBlock)callback;
- (void)startWithDate:(NSDate *)date
                 rate:(NSNumber *)rate
             callback:(KACallbackBlock)callback;
- (void)abort;

@end
