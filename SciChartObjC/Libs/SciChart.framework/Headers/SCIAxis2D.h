//
//  SCIAxis2D.h
//  SciChart
//
//  Created by Admin on 10.07.15.
//  Copyright (c) 2015 SciChart Ltd. All rights reserved.
//

/** \addtogroup Axis
 *  @{
 */

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>
#import "SCIAxisCore.h"
#import "SCIDrawable.h"
#import "SCIDataType.h"
#import "SCIRange.h"
#import "SCIAxisEnums.h"
#import "SCIEnumerationConstants.h"
#import "SCICallbackBlock.h"

@protocol SCIChartSurface;
@protocol SCIAxisInteractivityHelper;
@class SCIRenderPassInfo;
@protocol SCILabelProvider;
@protocol SCIAxisPanel;
@class SCIAxisStyle;
@class SCIAxisHitTestProvider;


/**
 * @brief Defines an Axis2D protocol used throughout SciChart
 @extends SCIAxisCore
 @extends SCIDrawable
 */
@protocol SCIAxis2D ///
<NSObject, SCIAxisCore, SCIDrawable>
/** @{ @} */

@required

/** Gets or sets the string Id of this axis. Used to associated SCIRenderableSeries*/
@property (nonatomic, copy) NSString * axisId;

/** 
 Gets the DataRange (full extents of the data) of the Axis
 @see SCIRange
 */
-(id<SCIRange>) getDataRange;

/**
 * Gets or sets the parent that this Axis belongs to
 * @see SCIChartSurface
 */
@property (nonatomic, weak) id<SCIChartSurface> parentSurface;

/**
 Gets or sets a SCILabelProvider instance, which may be used to programmatically override the formatting of the text and cursor labels
 @code
 @endcode
 */
@property (nonatomic, strong) id <SCILabelProvider> labelProvider;

/** Gets whether this Axis is horizontal or not*/
-(BOOL) isHorizontalAxis;

/** Gets or sets whether this Axis is a static axis*/
@property (nonatomic) BOOL isStaticAxis;

/**
 Gets or sets the alignment characteristics that are appliied to an Axis
 */
@property (nonatomic) SCIAxisAlignmentMode axisAlignment;

/** Called when the alignment of axis is changed*/
@property (nonatomic, copy) SCIActionBlock onAxisAlignmentChanged;

/** Gets a value indicating whether this instance is a category axis*/
-(BOOL) isCategoryAxis;

/** Gets a value indicating whether this instance is a polar axis*/
-(BOOL) isPolarAxis;

/** Gets or sets whether current Axis should be placed in the center of the chart or not*/
@property (nonatomic) BOOL isCenterAxis;

/** Gets or sets whether current Axis is the main one in axis collection. This is the axis which is responsible for drawing grid lines on the chart view
 @discussion By default this is the first axis in the collection
 */
@property (nonatomic) BOOL isPrimaryAxis;

/** Gets or sets the visibility of the Axis*/
@property (nonatomic) BOOL isVisible;

/** Gets whether the current axis is flipped
 * @discussion E.g. YAxis on the bottom or top, or XAxis on the left or right
 */
-(BOOL) isAxisFlipped;

/** Gets or sets the VisibleRangeLimit of the Axis. This will be used to clip the axis during ZoomExtents and AutoRange operations
 * @code
 self.chartSurface.xAxes.getAxisById("xAxis").visibleRangeLimit = SCIDoubleRange(min: SCIGeneric(2), max: SCIGeneric(400))
 * @endcode
 @see SCIRange
 */
@property (nonatomic, strong) id<SCIRange> visibleRangeLimit;

/** Gets or sets the VisibleRangeLimitMode of the Axis
 * @discussion This property defines which parts of VisibleRangeLimit will be used by axis
 */
@property (nonatomic) SCIRangeClipMode visibleRangeLimitMode;

/** Gets or sets a value indicating whether label culling is enabled (when labels overlap) on this AxisPanel instance*/
@property (nonatomic) BOOL isLabelCullingEnabled;

/** Gets the current SCIAxisInteractivityHelper for this Axis
 * @see SCIAxisInteractivityHelper
 */
-(id<SCIAxisInteractivityHelper>) getCurrentInteractivityHelper;

/** Gets the aligned VisibleRange of the axis, with optional ZoomToFit flag.
 * @discussion If ZoomToFit ir true, it will return the DataRange plus any GrowBy applied to the axis
 * @param renderPassInfo SCIRenderPassInfo
 * @return SCIRange
 * @see SCIRenderPassInfo
 * @see SCIRange
 */
-(id<SCIRange>) calculateYRangeWithRenderPassInfo:(SCIRenderPassInfo*)renderPassInfo;

/** Called by SCIChartSurface internally.
 * @discussion Returns the max range only for that axis(by the data-series on it), based on xRanges parameter
 * @param xRanges xRanges dictionary
 * @return SCIRange
 * @see SCIRange
 */
-(id<SCIRange>) getWindowedYRangeWithXRanges:(NSDictionary*) xRanges; // <string : SCIRange>

/** Called internally immediatelly before a render pass begins*/
-(void) onBeginRenderPass;

/** Scrolls current VisibleRange by specified number of pixels
 * @param pixelsToScroll Scroll N pixles from the current visible range
 * @param clipMode Defines how scrolling behaves when you reach the edge of the Axis extents
 * @see SCIZoomPanClipMode
 */
-(void) scrollByPixels:(double)pixelsToScroll ClipMode:(SCIZoomPanClipMode)clipMode;

/** Scrolls current VisibleRange by specified number of pixels
 * @param pixelsToScroll Scroll N pixles from the current visible range
 * @param clipMode Defines how scrolling behaves when you reach the edge of the Axis extents
 * @param duration The duration of animation when zooming to extents
 * @see SCIZoomPanClipMode
 */
-(void) scrollByPixels:(double)pixelsToScroll ClipMode:(SCIZoomPanClipMode)clipMode AnimationTime:(float)duration;

/** Translates current VisibleRange by specified number of datapoints
 * @param pointAmount Amount of data points that the start visible range is scrolled by
 * @see SCIRange
 */
-(void) scrollByDataPoints:(int)pointAmount;

/** Translates current VisibleRange by specified number of datapoints
 * @param pointAmount Amount of data points that the start visible range is scrolled by
 * @param duration Defines how scrolling behaves when you reach the edge of the Axis extents
 * @see SCIZoomPanClipMode
 */
-(void) scrollByDataPoints:(int)pointAmount AnimationTime:(float)duration;

/** 
 * Performs zoom on current Axis, using fromCoord as a coordinate of new range start and toCoord as a coordinate of new range end
 * @param fromCoord The coordinate of new range start in pixels
 * @param toCoord The coordinate of new range end in pixels
 * @see SCIRange
 */
-(void) zoomFrom:(double)fromCoord To:(double)toCoord;

/**
 * Performs zoom on current Axis, using fromCoord as a coordinate of new range start and toCoord as a coordinate of new range end
 * @param fromCoord The coordinate of new range start in pixels
 * @param toCoord The coordinate of new range end in pixels
 * @param duration The duration of animation when zooming to extents
 * @see SCIRange
 */
-(void) zoomFrom:(double)fromCoord To:(double)toCoord AnimationTime:(float)duration;

/**
 * Performs zoom on current Axis, using minFraction as a multuplier of range start and maxFraction as a multiplier of range end
 * @param minFraction The miltiplier of range start
 * @param maxFraction The miltiplier of range end
 * @see SCIRange
 */
-(void) zoomByFractionMin:(double)minFraction Max:(double)maxFraction;

/**
 * Performs zoom on current Axis, using minFraction as a multuplier of range start and maxFraction as a multiplier of range end
 * @param minFraction The miltiplier of range start
 * @param maxFraction The miltiplier of range end
 * @param duration The duration of animation when zooming to extents
 * @see SCIRange
 */
-(void) ZoomByFractionMin:(double)minFraction Max:(double)maxFraction AnimationTime:(float)duration;

/**
 * From the starting SCIRange, scrolls to a new range by the specified number of pixels, with the specified range limit
 * @param pixelsToScroll Scroll N pixels from the start visible range
 * @param startVisibleRange The start visible range
 * @param rangeLimit The range limit
 * @see SCIRange
 */
-(void) scrollToPixels:(double)pixelsToScroll WithVisibleRange:(id<SCIRange>)startVisibleRange WithLimit:(id<SCIRange>)rangeLimit;

/** 
 * Asserts the type passed in is supported by the current axis implementation
 * @param type Data type
 * @see SCIDataType
 */
-(void) assertDataType:(SCIDataType)type;

/**
 * String formats the text
 * @param value The data value to format
 * @return The string formatted data value
 */
-(NSString*) formatText:(SCIGenericType)value;

/**
 * String formats text for the cursor
 * @param value The data value to format
 * @return The string formatted data value
 */
-(NSString*) formatCursorText:(SCIGenericType)value;

/** Clears the axis of tick-marks and labels*/
-(void) clear;

/** Returns an undefined SCIRange, called internally by SciChart to reset the Visible Range of an axis to an undefined state
 * @see SCIRange
 */
-(id<SCIRange>) getUndefinedRange;

/** Returns a defulat non zero SCIRange, called internally by SciChart to reset the Visible Range of an axis to an undefined state
 * @see SCIRange
 */
-(id<SCIRange>) getDefaultNonZeroRange;

/**
 @brief Method set visible range for axis. Visible range change is animated if animateVisibleRangeChanges is true and animatedChangeDuration is not zero
 */
-(BOOL)trySetOrAnimateVisibleRange:(id<SCIRange>)newRange;

/**
 @brief Method set visible range for axis. Visible range change is animated if duration is not zero
 */
-(BOOL) trySetOrAnimateVisibleRange:(id<SCIRange>)newRange duration:(float)duration;

/**
 @brief Returns axis panel, which is axis layout and resizing tools.
 @discussion For internal use
 @see SCIAxisPanel
 */
-(id<SCIAxisPanel>) axisPanel;

/**
 * Gets or sets the style of the current axis
 * @code
 let axisStyle = SCIAxisStyle()
 
 let majorPen = SCIPenSolid(colorCode: SCSColorsHEX.majorPen, width: 0.5)
 let minorPen = SCIPenSolid(colorCode: SCSColorsHEX.minorPen, width: 0.5)
 
 let textFormat = SCITextFormattingStyle()
 textFormat.fontName = SCSFontsName.defaultFontName
 textFormat.fontSize = SCSFontSizes.defaultFontSize
 
 axisStyle.majorTickBrush = majorPen
 axisStyle.majorGridLineBrush = majorPen
 axisStyle.gridBandBrush = SCIBrushSolid.init(colorCode: SCSColorsHEX.gridBandPen)
 axisStyle.minorTickBrush = minorPen
 axisStyle.minorGridLineBrush = minorPen
 axisStyle.labelStyle = textFormat
 axisStyle.drawMinorGridLines = true
 axisStyle.drawMajorBands = true
 
 axis.style = axisStyle
 * @endcode
 @see SCIAxisStyle
 */
@property (nonatomic, copy) SCIAxisStyle * style;

/**
 @brief Returns hit test tools for axis
 @see SCIAxisHitTestProvider
 */
-(SCIAxisHitTestProvider*) hitTestProvider;

/**
 @brief Resturns axis frame inside SCIAxisArea. It is equal to axis panel frame
 */
-(CGRect)frame;

/**
 @brief Returns true if point is within axis frame
 */
-(BOOL) isPointWithinBounds:(CGPoint)point;

/**
 @brief Releases all axis resources and stops internal animation timers
 */
-(void) free;

@end

/** @}*/
