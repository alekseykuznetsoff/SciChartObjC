//
//  KADataManager.m
//  SciChartObjC
//
//  Created by Kuznetsov Aleksey on 11.06.17.
//  Copyright © 2017 Kuznetsov Aleksey. All rights reserved.
//

#import "KADataManager.h"
#import "KAPointsProvider.h"

@interface KADataManager ()

@property (nonatomic) KAPointsProvider *dataProvider;

@end

@implementation KADataManager

#pragma mark - --Initialize
+ (instancetype)sharedInstance
{
    static KADataManager *_sharedManager = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _sharedManager = [[self alloc] init];
    });
    return _sharedManager;
}

- (instancetype)init
{
    if ((self = [super init])){
        _dataProvider = [KAPointsProvider new];
    }
    return self;
}

#pragma mark - --Load data
- (void)loadPointsWithCount:(NSUInteger)count
                   callback:(KACallbackBlock)callback
{
    
}

- (void)loadDataWithCallback:(KACallbackBlock)callback
{
    
}

- (void)abortLoadingData
{
    
}

@end
