//
//  INVInfoWindow.h
//
//  Created by DAECHEOL KIM on 03/07/2019.
//  Copyright © 2019 iNaviMaps. All rights reserved.
//

#import "INVShape.h"

NS_ASSUME_NONNULL_BEGIN

@class INVMarker;
@class INVLatLng;
@class InaviMapView;
@class INVImage;

/**
 정보 창의 기본 전역 Z 인덱스
 */
const static int INV_INFO_WINDOW_DEFAULT_GLOBAL_Z_INDEX = 2000;

/**
 지도의 특정 위치 또는 마커 위에 창을 띄워 원하는 정보를 표시할 수 있는 Shape 클래스.
 */
INV_EXPORT
@interface INVInfoWindow : INVShape

/**
 정보 창의 투명도를 설정합니다. (0~1 사잇값)
 
 기본값은 `1`입니다.
 */
@property(nonatomic) CGFloat alpha;

/**
 정보 창에서 사용할 이미지를 제공해 줄 수 있는 이미지 데이터 소스.
 별도 dataSource를 정의하지 않으면 Default infoWindow가 표출됩니다.
 */
@property(nonatomic, weak, nullable) id<INVImageDataSource> imageDataSource;

/**
 정보 창의 위치를 전달된 `InvMarker`의 위치 위로 설정합니다.
 */
@property(nonatomic, strong, nullable) INVMarker *marker;

/**
 정보 창의 위치 좌표를 설정합니다.
 */
@property(nonatomic) INVLatLng *position;

/**
 정보 창과 좌표 또는 마커 간의 여백을 설정합니다. (pt 단위)
 
 기본값은 `(0, 0)`입니다.
 */
@property(nonatomic) CGPoint offset;

/**
 정보 창 이미지를 다시 그립니다.
 */
- (void)invalidate;
@end
NS_ASSUME_NONNULL_END
