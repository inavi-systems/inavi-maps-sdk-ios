//
//  INVPolygon.h
//
//  Created by DAECHEOL KIM on 24/06/2019.
//  Copyright © 2019 iNaviMaps. All rights reserved.
//

#import "INVShape.h"
#import "INVLatLng.h"

NS_ASSUME_NONNULL_BEGIN

/**
 폴리곤의 기본 전역 Z 인덱스
 */
const static int INV_POLYGON_DEFAULT_GLOBAL_Z_INDEX = -1000;

/**
 지도 위에 다각형을 표출하는 Shape 클래스
 */
INV_EXPORT
@interface INVPolygon : INVShape

/**
 폴리곤의 채우기 색상을 설정합니다.
 
 기본값은 `UIColor.whiteColor`입니다.
 */
@property (nonatomic, strong) UIColor *fillColor;

/**
 폴리곤의 테두리 두께를 설정합니다. (픽셀 단위)
 
 기본값은 `0`입니다.
 */
@property (nonatomic) NSUInteger strokeWidth;

/**
 폴리곤의 테두리 색상을 설정합니다.
 
 기본값은 `UIColor.blackColor`입니다.
 */
@property (nonatomic, copy) UIColor *strokeColor;

/**
 폴리곤의 좌표열을 설정합니다.
 `coords`의 크기는 `2` 이상이어야 합니다.
 */
@property (nonatomic, copy) NSArray<INVLatLng *> *coords;

/**
 폴리곤의 좌표열과 색상을 지정하여 폴리곤을 생성합니다.
 `coords`의 크기는 `2` 이상이어야 합니다.
 
 @param coords 폴리곤의 좌표열.
 @param fillColor 폴리곤을 채울 색상.
 @return `INVPolygon` 객체.
 */
+ (instancetype)polygonWithCoords:(NSArray<INVLatLng*> *)coords fillColor:(UIColor *)fillColor;

/**
 폴리곤의 좌표열과 색상을 지정하여 폴리곤을 생성합니다.
 `coords`의 크기는 `2` 이상이어야 합니다.
 
 @param coords 폴리곤의 좌표열.
 @return `INVPolygon` 객체.
 */
+ (instancetype)polygonWithCoords:(NSArray<INVLatLng*> *)coords;

@end

NS_ASSUME_NONNULL_END
