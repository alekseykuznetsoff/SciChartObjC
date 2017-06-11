//
//  SCIPointMarker.h
//  SciChart
//
//  Created by Admin on 26.11.15.
//  Copyright © 2015 SciChart Ltd. All rights reserved.
//

/** \addtogroup PointMarkers
 *  @{
 */

#import <Foundation/Foundation.h>

@protocol SCIRenderContext2D;
@class UIColor;

/**
 @brief Provides basic functions for point markers. Point markers are visual objects that can be placed at x y position on render surface, usually at data point location
 @extends NSCopying
 */
@protocol SCIPointMarker ///
<NSObject, NSCopying>
/** @{ @} */

/**
 @brief Defines point marker drawing width in pixels on screen
 */
@property (nonatomic) float width;
/**
 @brief Defines point marker drawing height in pixels on screen
 */
@property (nonatomic) float height;

/**
 @brief Method draws point marker to specific OpenGL render context at given screen coordinates.
 @discussion Mind that X and Y coordinates should be coordinates not in SCIChartSurfaceView, but in OpenGL drawing area inside SCIChartSurfaceView
 @code
 let view : SCIChartSurfaceView = SCIChartSurfaceView()
 let surface : SCIChartSurface = SCIChartSurface(view: view)
 
 // some actions
 let renderContext : SCIRenderContext2D = surface.renderSurface.renderContext() // get default render context

 let chartArea : CGRect = view.renderSurfaceSizeView.frame // get frame of chart surface (without axes area)
 renderContext.setDrawingArea( chartArea ) // set drawing area to chart surface. It is required before custom drawing commands to make sure that your drawing area is correct

 let marker : SCITrianglePointMarker = SCITrianglePointMarker() // create point marker
 marker.drawToContext(renderContext, atX: 10, y: 10) // draw point marker at coordinates 10:10 on chart area
 @endcode
 @see SCIChartSurfaceView
 @see SCIChartSurface
 @see SCIRenderContext2D
 */
-(void) drawToContext:(__unsafe_unretained id<SCIRenderContext2D>)context AtX:(float)x Y:(float)y;

/**
 @brief Returns color of point marker. It depends on point marker implementation and can return strange values (like white or transparent color) for textured point markers
 */
-(UIColor*) pointMarkerColor;
/**
 @brief Sets point marker color, if it makes sence for specific point marker implementation. For most point markers it is fill color.
 */
-(void) setPointMarkerColor:(UIColor*)color;

@end

/** @}*/
