//
//  KAChartViewController.m
//  SciChartObjC
//
//  Created by Kuznetsov Aleksey on 11.06.17.
//  Copyright © 2017 Kuznetsov Aleksey. All rights reserved.
//

#import "KAChartViewController.h"
#import <SciChart/SciChart.h>
#import "KADataManager.h"

@interface KAChartViewController ()

@property (nonatomic) KADataManager *model;

@property (weak, nonatomic) IBOutlet SCIChartSurfaceView *sciChartSurfaceView;

@property (nonatomic) SCIChartSurface *surface;
@property (nonatomic) SCIXyDataSeries *dataSeries;

@end

@implementation KAChartViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.model = [KADataManager sharedInstance];

    [self.model loadPointsWithCount:30 callback:^(NSArray *array, NSError *error) {
        NSLog(@"%@", array);
    }];
}

@end
