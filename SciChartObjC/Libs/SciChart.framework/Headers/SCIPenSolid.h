//
//  SCIPenSolid.h
//  SciChart
//
//  Created by Admin on 17.06.15.
//
//

#import <Foundation/Foundation.h>
#import "SCIPen2D.h"

/**
 @brief Pen with stroke thickness and solid color
 @see SCIPen2D
 */
@interface SCIPenSolid : NSObject <SCIPen2D>

/**
 @brief Constructor creates pen with given color and stroke thickness
 */
-(id) initWithColor:(UIColor *)color Width:(float)width;
/**
 @brief Constructor creates pen with given color code and stroke thickness. Color code byte order is 0xAABBGGRR
 */
-(id) initWithColorCode:(unsigned int)color Width:(float)width;

@end
