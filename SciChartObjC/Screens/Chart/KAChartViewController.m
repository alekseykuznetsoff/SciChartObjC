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

    [self setupSurface];
    [self setupRenderableSeries];
    
    __weak typeof(self) weakSelf = self;
    [self.model loadPointsWithCount:30 callback:^(NSArray *array, NSError *error) {
        [weakSelf updateChartWithPoints:array];
        [weakSelf.surface invalidateElement];
    }];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    __weak typeof(self) weakSelf = self;
    [self.model loadDataWithCallback:^(NSArray *array, NSError *error) {
        [weakSelf updateChartWithPoints:array];
    }];
}

- (void)updateChartWithPoints:(NSArray *)array
{
    KAPoint *point = array.lastObject;
    
    [self updateDataSeriesWithPoints:array];
    [self updateAnnotationWithPoint:point];
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
    SCIAxisMarkerAnnotation * yMarker = [[SCIAxisMarkerAnnotation alloc] init];
    yMarker.coordMode = SCIAnnotationCoord_Absolute;
    yMarker.yAxisId = @"yAxis";
    yMarker.position = SCIGeneric(point.doubleRate);
    yMarker.style.markerLinePen = [[SCIPenSolid alloc] initWithColorCode:0xFFFFFFFF Width:1];
    yMarker.style.backgroundColor = [UIColor clearColor];
    yMarker.style.textColor = [UIColor clearColor];
    [self.surface setAnnotation:yMarker];
}

- (void)setupSurface
{
    SCIChartSurface *surface = [[SCIChartSurface alloc] initWithView:self.sciChartSurfaceView];
    
    SCIPenSolid  *majorPen = [[SCIPenSolid alloc] initWithColor:[UIColor darkGrayColor] Width:1.0];
    SCITextFormattingStyle *  textFormatting= [[SCITextFormattingStyle alloc] init];
    textFormatting.fontSize = 14.0;
    textFormatting.color = [UIColor darkGrayColor];
    
    SCIAxisStyle * axisStyle = [[SCIAxisStyle alloc]init];
    axisStyle.drawMinorTicks = NO;
    axisStyle.majorTickBrush = majorPen;
    axisStyle.majorGridLineBrush = majorPen;
    axisStyle.labelStyle = textFormatting;
    
    SCIDateTimeAxis *xAxis = [[SCIDateTimeAxis alloc] init];
    xAxis.axisId = @"xAxis";
    xAxis.subDayTextFormatting = @"mm:ss";
    xAxis.growBy = [[SCIDoubleRange alloc]initWithMin:SCIGeneric(0.0) Max:SCIGeneric(0.1)];
    xAxis.style = axisStyle;
    [surface attachAxis:xAxis IsXAxis:YES];
    
    SCINumericAxis *yAxis = [[SCINumericAxis alloc] init];
    
    yAxis.axisId = @"yAxis";
    yAxis.growBy = [[SCIDoubleRange alloc]initWithMin:SCIGeneric(0.1) Max:SCIGeneric(0.1)];
    yAxis.visibleRangeLimit = [[SCIDoubleRange alloc]initWithMin:SCIGeneric(760) Max:SCIGeneric(790)];
    yAxis.style = axisStyle;
    [surface attachAxis:yAxis IsXAxis:NO];
    
    SCIZoomPanModifier * zpm = [[SCIZoomPanModifier alloc] init];
    zpm.modifierName = NSStringFromClass(SCIZoomPanModifier.class);
    SCIPinchZoomModifier * pzm = [[SCIPinchZoomModifier alloc] init];
    pzm.modifierName = NSStringFromClass(SCIPinchZoomModifier.class);
    SCIModifierGroup * gm = [[SCIModifierGroup alloc] initWithChildModifiers:@[pzm, zpm]];
    surface.chartModifier = gm;
    
    self.surface = surface;
}

- (void)setupRenderableSeries
{
    SCIXyDataSeries * pointsDataSeries = [[SCIXyDataSeries alloc] initWithXType:SCIDataType_DateTime
                                                                          YType:SCIDataType_Double];
    pointsDataSeries.dataDistributionCalculator = [SCIUserDefinedDistributionCalculator new];
    SCIFastMountainRenderableSeries * mountainSeries = [SCIFastMountainRenderableSeries new];
    id<SCIBrush2D> brush = [[SCIBrushLinearGradient alloc] initWithColorCodeStart:0xbbff0000 Finish:0x88ff0000 Direction:SCILinearGradientDirection_Vertical];
    id<SCIPen2D> pen = [[SCIPenSolid alloc] initWithColorCode:0xFFff0000 Width:0.5];
    mountainSeries.style.areaBrush = brush;
    mountainSeries.style.borderPen = pen;
    mountainSeries.xAxisId = @"xAxis";
    mountainSeries.yAxisId = @"yAxis";
    [mountainSeries setDataSeries:pointsDataSeries];
    [self.surface attachRenderableSeries:mountainSeries];
    self.dataSeries = pointsDataSeries;
}

@end
