//
//  AxisCollection.h
//  SciChart
//
//  Created by Admin on 15.07.15.
//  Copyright (c) 2015 SciChart Ltd. All rights reserved.
//

/** \addtogroup Axis
 *  @{
 */

#import <Foundation/Foundation.h>

@protocol SCIAxis2D;

/**
 * @brief Provides functionality for AxisCollection class
 */
@interface SCIAxisCollection : NSObject

-(id)initWithAxisCollection:(NSArray*)axes;

/** Gets axis by Id from the AxisCollection
 * @param axisId AxisId used when searching for an axis
 * @code
 let axis = self.chartSurface.xAxes.getAxisById("xAxis")
 * @endcode
 @see SCIAxis2D
 */
-(id<SCIAxis2D>) getAxisById:(NSString*)axisId;

-(id<SCIAxis2D>) getAxisById:(NSString*)axisId AssertAxisExist:(BOOL)assert;

/**
 * Gets the quantity of axes in collection
 */
-(int) count;

/** Gets axis by index from the AxisCollection
 * @param index Index used when retreiving for an axis
 * @code
 let axis = self.chartSurface.xAxes.itemAt(2)
 * @endcode
 @see SCIAxis2D
 */
-(id<SCIAxis2D>)itemAt:(int)index;

/** Inserts axis into the AxisCollection
 * @param item Item to insert into AxisCollection
 * @code
 self.chartSurface.xAxes.addItem(axis)
 * @endcode
 @see SCIAxis2D
 */
-(void)addItem:(id<SCIAxis2D>)item;

/** Inserts axis into the AxisCollection at specified position
 * @param item Item to insert into AxisCollection
 * @param index Position where axis will be placed
 * @code
 self.chartSurface.xAxes.insertItem(axis, at: 3)
 * @endcode
 @see SCIAxis2D
 */
-(void)insertItem:(id<SCIAxis2D>)item At:(int)index;

/** Checks whether axis collection contains the axis or not
 * @param item Item to check in AxisCollection
 * @code
 let exist = self.chartSurface.xAxes.conains(axis)
 * @endcode
 @see SCIAxis2D
 */
-(BOOL)contains:(id<SCIAxis2D>)item;

/** Removes axis instance from  AxisCollection
 * @param item Item to be deleted from AxisCollection
 * @code
 self.chartSurface.xAxes.removeItem(axis)
 * @endcode
 @see SCIAxis2D
 */
-(void)removeItem:(id<SCIAxis2D>)item;

/** Removes axis instance from  AxisCollection
 * @param index Index of item, which will be deleted from AxisCollection
 * @code
 self.chartSurface.xAxes.removeItemAt(3)
 * @endcode
 @see SCIAxis2D
 */
-(void)removeItemAt:(int)index;

/**Removes all axes from AxisCollection*/
-(void)clear;

/** Checks whether the current AxisCollection has a primary axis - the main one in axis collection. This is the axis which is responsible for drawing grid lines on the chart view
 @discussion By default this is the first axis in the collection
 */
-(BOOL)hasPrimaryAxis;

/** Gets current PrimaryAxis - the main one in axis collection. This is the axis which is responsible for drawing grid lines on the chart view
 @discussion By default this is the first axis in the collection
 */
-(id<SCIAxis2D>) primaryAxis;

/** Gets the default Axis from the AxisCollection*/
-(id<SCIAxis2D>) defaultAxis;

@end

/** @}*/
