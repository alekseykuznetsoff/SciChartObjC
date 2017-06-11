//
//  UIColor+SCIConvertToHexColorCode.h
//  SciChart
//
//  Created by Admin on 09/06/16.
//  Copyright © 2016 SciChart. All rights reserved.
//

#import <UIKit/UIKit.h>

// color code has format AABBGGRR
@interface UIColor (SCIConvertToHexColorCode)

/**
 @brief Create UIColor from hex color code. Color code bytes order is 0xAABBGGRR
 */
+(UIColor *) fromColorCode:(uint)color;
/**
 @brief Get hex color code from UIColor. Color code bytes order is 0xAABBGGRR
 */
-(uint) colorCode;

@end
