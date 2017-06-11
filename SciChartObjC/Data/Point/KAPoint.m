//
//  KAPoint.m
//  SciChartObjC
//
//  Created by Kuznetsov Aleksey on 11.06.17.
//  Copyright © 2017 Kuznetsov Aleksey. All rights reserved.
//

#import "KAPoint.h"

@implementation KAPoint

- (double)doubleRate
{
    return [self.rate doubleValue];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"date: %@, rate: %@", self.date, self.rate];
}

@end
