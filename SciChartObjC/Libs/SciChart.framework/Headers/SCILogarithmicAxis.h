//
//  SCILogarithmicAxis.h
//  SciChart
//
//  Created by Admin on 14.01.16.
//  Copyright © 2016 SciChart Ltd. All rights reserved.
//

/** \addtogroup Axis
 *  @{
 */

#import "SCIAxis2D.h"

/**
 @brief Protocol specify axis with logarithmic scaling
 @see SCIAxis2D
 @extends SCIAxis2D
 */
@protocol SCILogarithmicAxis ///
<SCIAxis2D>
/** @{ @} */

/**
 @brief Gets or sets logarithmic base of axis scaling
 @code
 axis.logarithmicBase = M_E
 @endcode
 */
@property (nonatomic) double logarithmicBase;

@end

/** @}*/
