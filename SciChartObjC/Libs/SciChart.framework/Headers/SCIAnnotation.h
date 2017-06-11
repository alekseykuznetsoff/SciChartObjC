//
//  SCIAnnotation.h
//  SciChart
//
//  Created by Admin on 28.12.15.
//  Copyright © 2015 SciChart Ltd. All rights reserved.
//

/** \addtogroup Annotations 
 *  @{
 */

#import "SCIGestureEventsHandler.h"

@class SCIAxisCollection;
@protocol SCIAxis2D;
@protocol SCIChartSurface;

/**
 \extends SCIGestureEventsHandler
 * Defines the protocol to an annotation, a custom drawable element under the SCIChartSurface
 * @discussion Mind that for annotation to be drawn it has to be attached to SciChartSurface. If you need multiple annotations on surface use SCIAnnotationGroup
 @see SCIChartSurface
 @see SCIAnnotationGroup
 */
@protocol SCIAnnotation ///
<SCIGestureEventsHandler>
 /** @{ @} */

/**
 * Gets or sets the parent that this Annotation belongs to
 * @see SCIChartSurface
 */
@property (nonatomic, weak) id<SCIChartSurface> parentSurface;

/**
 * Gets the primary XAxis instance on the parent
 * @see SCIAxis2D, SCIChartSurface
 */
-(id<SCIAxis2D>) xAxis;

/**
 * Gets the YAxes instance on the parent
 * @see SCIAxisCollection, SCIChartSurface
 */
-(SCIAxisCollection*) yAxes;

/**
 * Gets the primary YAxis instance on the parent
 * @see SCIAxis2D, SCIChartSurface
 */
-(id<SCIAxis2D>) yAxis;

/**
 * Gets the XAxis instance on the parent by Id
 * @param axisId XAxis Id
 * @see SCIAxisCollection, SCIChartSurface
 */
-(id<SCIAxis2D>) getXAxis:(NSString*)axisId;

/**
 * Gets the YAxis instance on the parent by Id
 * @param axisId YAxis Id
 * @see SCIAxisCollection, SCIChartSurface
 */
-(id<SCIAxis2D>) getYAxis:(NSString*)axisId;

/**
 * Called when the Annotation should be drawn
 */
-(void)draw;

/**
 * Called when the Annotation is attached to parent surface
 */
-(void)onAttached;

/**
 * Called when the Annotation is detached from its parent surface
 */
-(void)onDetached;

/**
 * Gets or sets whether the current annotation is attached
 */
@property (nonatomic) BOOL isAttached;

/**
 * Gets or sets the name of current annotation
 */
@property (nonatomic, copy) NSString * annotationName;

@end

/** @}*/
