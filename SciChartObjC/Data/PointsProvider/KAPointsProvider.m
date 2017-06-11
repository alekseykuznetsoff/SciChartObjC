//
//  KAPointsProvider.m
//  SciChartObjC
//
//  Created by Kuznetsov Aleksey on 11.06.17.
//  Copyright © 2017 Kuznetsov Aleksey. All rights reserved.
//

#import "KAPointsProvider.h"
#import "KAPoint.h"

#define randomMin -1.0
#define randomMax 1.0
#define timeInterval 1.0
#define defaultRate 777

@interface KAPointsProvider ()

@property (nonatomic) NSTimer *timer;

@property (nonatomic) double lastRate;
@property (nonatomic) NSDate *lastDate;
@property (nonatomic, copy) void (^callback)(NSArray *array, NSError *error);

- (void)start;
- (void)stop;

@end

@implementation KAPointsProvider

#pragma mark - --Initialize
- (instancetype)init
{
    if ((self = [super init])){
        _lastDate = [NSDate date];
        _lastRate = defaultRate;
        
        srand48(time(0)); // for drand48(), for random double
    }
    return self;
}

#pragma mark - --Public
- (void)loadPointsWithCount:(NSUInteger)count
                   callback:(KACallbackBlock)callback
{
    NSMutableArray *mArray = [NSMutableArray new];
    for (NSUInteger i = 0; i<count; i++) {
        [mArray addObject:[self createNewPoint]];
    }
    callback == nil ?: callback([mArray copy], nil);
}

- (void)startWithCallback:(KACallbackBlock)callback
{
    [self startWithDate:nil rate:nil callback:callback];
}

- (void)startWithDate:(NSDate *)date
                 rate:(NSNumber *)rate
             callback:(KACallbackBlock)callback
{
    if (date) {
        self.lastDate = date;
    }
    if (rate) {
        self.lastRate = [rate doubleValue];
    }
    if (callback) {
        self.callback = callback;
    }
    [self start];
}

- (void)abort
{
    [self stop];
    self.callback = nil;
}

#pragma mark - --Private
- (void)start
{
    if (self.timer.isValid) {
        [self.timer invalidate];
    }
    self.timer = [NSTimer scheduledTimerWithTimeInterval:timeInterval target:self selector:@selector(loadNewPoint) userInfo:nil repeats:YES];
}

- (void)stop
{
    if (self.timer.isValid) {
        [self.timer invalidate];
    }
}

- (void)loadNewPoint
{
    self.callback == nil ?: self.callback(@[[self createNewPoint]], nil);
}

- (KAPoint *)createNewPoint
{
    KAPoint *point = [KAPoint new];
    
    double rate = self.lastRate + [self myRandom];
    self.lastRate = rate;
    point.rate = @(rate);
    
    NSDate *date = [self.lastDate dateByAddingTimeInterval:timeInterval];
    self.lastDate = date;
    point.date = date;
    
    return point;
}

#pragma mark - --Helpers
- (double)myRandom
{
    return [self doubleRandomMin:randomMin andMax:randomMax];
}

- (double)doubleRandomMin:(double)min andMax:(double)max
{
    return min + drand48() * (max - min);
}

@end
