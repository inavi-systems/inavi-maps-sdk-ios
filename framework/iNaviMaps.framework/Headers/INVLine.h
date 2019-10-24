//
//  INVLine.h
//
//  Created by DAECHEOL KIM on 14/08/2019.
//  Copyright © 2019 iNaviMaps. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "INVFoundation.h"

@class INVLatLng;

NS_ASSUME_NONNULL_BEGIN

/**
 다중 선형에서 사용하는 선형의 좌표열과 색상 속성을 정의한 클래스.
 */

INV_EXPORT
@interface INVLine : NSObject

/**
 라인의 색상을 설정합니다.
 
 기본값은 `UIColor.blackColor`입니다.
 */
@property (nonatomic, copy) UIColor *color;

/**
 라인의 좌표열을 설정합니다.
 `coords`의 크기는 `2` 이상이어야 합니다.
 */
@property (nonatomic, copy) NSArray<INVLatLng *> *coords;

/**
 좌표열을 지정하여 선형 생성합니다.
 `coords`의 크기는 `2` 이상이어야 합니다.
 */
+ (instancetype)lineWithCoords:(NSArray<INVLatLng *> *)coords;

/**
 좌표열과 색상을 지정하여 INVLine를 생성합니다.
 `coords`의 크기는 `2` 이상이어야 합니다.
 */
+ (instancetype)lineWithCoords:(NSArray<INVLatLng *> *)coords color:(UIColor*)color;

@end

NS_ASSUME_NONNULL_END
