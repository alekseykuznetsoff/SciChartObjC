//
//  SCIStackedRenderableSeries.h
//  SciChart
//
//  Created by Admin on 19.02.16.
//  Copyright © 2016 SciChart Ltd. All rights reserved.
//

/** \addtogroup RenderableSeries
 *  @{
 */

#import "SCIRenderableSeries.h"
@protocol SCIRenderPassData;

/**
 * @abstract Action that is performed by SCIStackedRenderableSeries at beginning of render loop
 * @discussion For internal use
 * @param series SCIRenderableSeries sender of data
 * @param data SCIRenderPassData data that will be used in drawing loop
 * @see SCIRenderableSeries
 * @see SCIRenderPassData
 */
typedef void(^SCIStackedSeriesRenderDataRequest)(id<SCIRenderableSeries> series, id<SCIRenderPassData> data);

/**
 * @brief SCIStackedRenderableSeries protocol defines methods for stacked series. If renderable series implements this protocol it can be used as series in SCIStackedGroupSeries
 * @see SCIRenderableSeries
 * @see SCIStackedGroupSeries
 @extends SCIRenderableSeries
 */
@protocol SCIStackedRenderableSeries ///
<SCIRenderableSeries>
/** @{ @} */

/**
 * @brief Action that is performed at beginning of rendering
 * @discussion For internal use. Do not override it, because it is used by SCIStackedGroupSeries for collecting data for drawing
 * @see SCIStackedSeriesRenderDataRequest
 */
@property (nonatomic, copy) SCIStackedSeriesRenderDataRequest updateRenderData;

/**
 * @brief Perform preparation of points data for drawing based on previous series data.
 * @discussion First stacked series will get nil in second parameter, every following series will get points modified by previous stacked series
 * @params points1 SCIPointSeries current points. They will be changed after execution of this method
 * @params points2 SCIPointSeries points that was used by previous stacked series
 * @see SCIPointSeries
 */
-(void) modifyPointSeries:(id<SCIPointSeries>)points1 With:(id<SCIPointSeries>)points2;

/**
 * @brief Performs drawing of stacked series. This method is called by SCIStackedGroupSeries after data preparation
 * @params renderContext SCIRenderContext2D OpenGl context that performs drawing
 * @params renderPassData SCIRenderPassData data prepared for drawing. Valid only in current render loop
 * @see SCIRenderContext2D
 * @see SCIRenderPassData
 */
-(void) drawWithContext:(id<SCIRenderContext2D>)renderContext
        WithStackedData:(id<SCIRenderPassData>)renderPassData;

/**
 * @brief Combine point series from previous and current stacked series into points acceptable for drawing.
 * @params points1 SCIPointSeries points of current stacked series
 * @params points2 SCIPointSeries points that was used by previous stacked series
 * @result SCIPointSeries combined point series, which SCIStackedRenderableSeries knows how to draw
 * @see SCIPointSeries
 */
-(id<SCIPointSeries>) getStackedPointSeriesFromPoints1:(id<SCIPointSeries>)points1 Points2:(id<SCIPointSeries>)points2;

@end

/** @}*/
