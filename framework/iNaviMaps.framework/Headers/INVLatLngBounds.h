//
//  INVLatLngBounds.h
//
//  Created by DAECHEOL KIM on 28/06/2019.
//  Copyright © 2019 iNaviMaps. All rights reserved.
//

#import "INVFoundation.h"

@class INVLatLng;

NS_ASSUME_NONNULL_BEGIN


/**
 북동쪽, 남서쪽의 위도, 경도 좌표로 구성된 범위 사각형 영역 클래스.
 */

INV_EXPORT
@interface INVLatLngBounds : NSObject

/**
 남서쪽 좌표.
 */
@property (nonatomic, nonnull) INVLatLng *southWest;

/**
 북동쪽 좌표.
 */
@property (nonatomic, nonnull) INVLatLng *northEast;

/**
 남서쪽, 북동쪽 좌표로 Bounds 객체를 생성합니다.
 
 @param sourthWest 남서쪽 좌표.
 @param northEast 북동쪽 좌표.
 @return INVLatLngBounds 객체.
 */
+ (nonnull instancetype)latLngBoundsSouthWest:(nonnull INVLatLng *)sourthWest northEast:(nonnull INVLatLng *)northEast;

@end

NS_ASSUME_NONNULL_END
