//
//  StackedGroupSeries.h
//  SciChart
//
//  Created by Admin on 19.02.16.
//  Copyright © 2016 SciChart Ltd. All rights reserved.
//

/** \addtogroup RenderableSeries
 *  @{
 */

#import <Foundation/Foundation.h>
#import "SCIRenderableSeriesBase.h"

@protocol SCIStackedRenderableSeries;

/**
 @brief The SCIStackedGroupSeries class.
 @discussion That series is not visible, but used for organization of drawing SCIStackedRenderableSeries that were added to it.
 @remark Do not need any data, and do not have styles. Provide data and styles to attached SCIStackedRenderableSeries.
 @see SCIRenderableSeries
 @see SCIRenderableSeriesBase
 @see SCIStackedRenderableSeries
 */
@interface SCIStackedGroupSeries : SCIRenderableSeriesBase

/**
 * @brief Method adds stacked series to drawing queue. 
 * @discussion Order of adding matters, because usually data of stacked series is modified with data of all previous stacked series
 * @params series SCIStackedRenderableSeries to be drawn
 */
-(void)addSeries:(id<SCIStackedRenderableSeries>)series;
/**
 * @brief Method removes stacked series from drawing queue.
 * @params series SCIStackedRenderableSeries to be removed
 */
-(void)removeSeries:(id<SCIStackedRenderableSeries>)series;
/**
 * @brief Method removes all stacked series from drawing queue.
 */
-(void)removeAllSeries;

@end

/** @}*/
