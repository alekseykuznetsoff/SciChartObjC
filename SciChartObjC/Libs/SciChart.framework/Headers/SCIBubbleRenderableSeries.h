//
//  BubbleRenderableSeries.h
//  SciChart
//
//  Created by Admin on 18.02.16.
//  Copyright © 2016 SciChart Ltd. All rights reserved.
//

/** \addtogroup RenderableSeries
 *  @{
 */

#import <SciChart/SciChart.h>

@class SCIBubbleSeriesStyle;

/**
 @brief The SCIBubbleRenderableSeries class.
 @discussion Every data point in this renderable series has XYZ data and displayed as buble with position at XY and radius defined by Z value
 @remark Designed to work with SCIXyzDataSeries as data container
 @remark For styling provide or customize SCIBubbleSeriesStyle
 @see SCIRenderableSeries
 @see SCIRenderableSeriesBase
 @see SCIXyzDataSeries
 @see SCIBubbleSeriesStyle
 */
@interface SCIBubbleRenderableSeries : SCIRenderableSeriesBase

/**
 @brief Get or set style for visual customization
 @see SCIBubbleSeriesStyle
 */
@property (nonatomic, copy) SCIBubbleSeriesStyle * style;

/**
 @brief Get or set bubble scale
 @discussion Z value multiplied by zScale is bubble radius in pixels
 */
@property (nonatomic) double zScale;

@end

/** @}*/
