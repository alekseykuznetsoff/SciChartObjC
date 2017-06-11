//
//  SCICustomRenderableSeries.h
//  SciChart
//
//  Created by Admin on 29/12/16.
//  Copyright © 2016 SciChart. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCIRenderableSeriesBase.h"

@interface SCICustomRenderableSeries : SCIRenderableSeriesBase

-(id<SCIRange>) getYRange:(id<SCIRange>)xRange Positive:(BOOL)getPositiveRange;

-(id<SCIRange>)getXRange;

-(SCISeriesInfo*) toSeriesInfoWithHitTest:(HitTestResult)info;

-(id<SCIHitTestProvider>) hitTestProvider;

-(UIColor *) seriesColor;

-(void)internalDrawWithContext:(id<SCIRenderContext2D>)renderContext WithData:(id<SCIRenderPassData>)renderPassData;

@end
