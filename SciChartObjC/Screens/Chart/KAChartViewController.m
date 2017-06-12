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
#import "KAPoint.h"

#import "SCIAxisMarkerAnnotation+Extensions.h"
#import "SCIChartSurface+Extensions.h"
#import "SCIFastMountainRenderableSeries+Extensions.h"
#import "SCIXyDataSeries+Extensions.h"

@interface KAChartViewController ()

@property (nonatomic) KADataManager *model;

@property (weak, nonatomic) IBOutlet SCIChartSurfaceView *sciChartSurfaceView;
@property (nonatomic) SCIChartSurface *surface;
@property (nonatomic) SCIXyDataSeries *dataSeries;

@end

@implementation KAChartViewController

#pragma mark - --Initialize
- (void)viewDidLoad {
    [super viewDidLoad];

    self.model = [KADataManager sharedInstance];

    [self setupSurface];
    [self loadStartPoints];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    [self loadNewPoints];
}

#pragma mark - --Load data
- (void)loadStartPoints
{
    __weak typeof(self) weakSelf = self;
    [self.model loadPointsWithCount:30 callback:^(NSArray *array, NSError *error) {
        [weakSelf updateChartWithPoints:array];
    }];
}

- (void)loadNewPoints
{
    __weak typeof(self) weakSelf = self;
    [self.model loadDataWithCallback:^(NSArray *array, NSError *error) {
        [weakSelf updateChartWithPoints:array];
    }];
}

#pragma mark - --Update Chart
- (void)updateChartWithPoints:(NSArray *)array
{
    [self updateDataSeriesWithPoints:array];
    [self updateAnnotationWithPoint:array.lastObject];
    
    [self.surface zoomExtents];
    [self.surface invalidateElement];
}

- (void)updateDataSeriesWithPoints:(NSArray *)array
{
    for (int i = 0; i<array.count; i++) {
        KAPoint *point = array[i];
        [self.dataSeries appendX:SCIGeneric(point.date)
                               Y:SCIGeneric(point.doubleRate)];
    }
}

- (void)updateAnnotationWithPoint:(KAPoint *)point
{
    if (!self.surface.annotation) {
        self.surface.annotation = [SCIAxisMarkerAnnotation customWithPosition:SCIGeneric(point.doubleRate)];
    } else {
        SCIAxisMarkerAnnotation *yMarker = self.surface.annotation;
        yMarker.position = SCIGeneric(point.doubleRate);
    }
}

#pragma mark - --Setup Chart
- (void)setupSurface
{
    self.surface = [SCIChartSurface customWithView:self.sciChartSurfaceView];
    self.dataSeries = [SCIXyDataSeries custom];
    [self.surface attachRenderableSeries:[SCIFastMountainRenderableSeries customWithDataSeries:self.dataSeries]];
    [self setupChartModifier];
}

- (void)setupChartModifier
{
    SCIZoomPanModifier * zpm = [[SCIZoomPanModifier alloc] init];
    zpm.modifierName = NSStringFromClass(SCIZoomPanModifier.class);
    SCIPinchZoomModifier * pzm = [[SCIPinchZoomModifier alloc] init];
    pzm.modifierName = NSStringFromClass(SCIPinchZoomModifier.class);
    SCIModifierGroup * gm = [[SCIModifierGroup alloc] initWithChildModifiers:@[pzm, zpm]];
    self.surface.chartModifier = gm;
}

@end
