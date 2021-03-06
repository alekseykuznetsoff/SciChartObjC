//
//  Int64Range.h
//  SciChart
//
//  Created by Admin on 08.07.15.
//  Copyright (c) 2015 SciChart Ltd. All rights reserved.
//

/** \addtogroup Ranges
 *  @{
 */

#import <Foundation/Foundation.h>
#import "SCIRange.h"

/**
 @brief Numeric integer range
 @see SCIRange
 */
@interface SCIIntegerRange : NSObject <SCIRange>

/**
 @brief Gets or sets min value for range. Internaly stored as int
 @see SCIGenericType
 @code
 range.min = SCIGeneric(0)
 @endoce
 */
@property (nonatomic) SCIGenericType min;
/**
 @brief Gets or sets max value for range. Internaly stored as int
 @see SCIGenericType
 @code
 range.min = SCIGeneric(0)
 @endoce
 */
@property (nonatomic) SCIGenericType max;

/**
 @brief Integer range constructor with min and max values. Min and max internaly stored as int
 @param min SCIGenericType min value
 @param max SCIGenericType max value
 @see SCIGenericType
 @code
 let range = SCIIntegerRange(min: SCIGeneric(0), max: SCIGeneric(10))
 @endcode
 */
-(id) initWithMin:(SCIGenericType)min Max:(SCIGenericType)max;

@end

/** @}*/
