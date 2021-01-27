//
//  INVInfoWindow.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import "INVShape.h"

NS_ASSUME_NONNULL_BEGIN

@class INVMarker;
@class INVLatLng;
@class InaviMapView;
@class INVImage;

/**
 정보 창의 기본 전역 Z 인덱스.
 */
const static int INV_INFO_WINDOW_DEFAULT_GLOBAL_Z_INDEX = 3000;

/**
 지도의 특정 위치 또는 마커 위에 창을 띄워 원하는 정보를 표시할 수 있는 셰이프 클래스.
 */
INV_EXPORT
@interface INVInfoWindow : INVShape

/**
 정보 창의 투명도. (`0~1` 사잇값)
 
 기본값은 `1`입니다.
 */
@property(nonatomic) CGFloat alpha;

/**
 정보 창에서 사용할 이미지를 제공하는 데이터 소스.
 
 값을 설정하지 않으면 기본 정보 창 이미지가 표출됩니다.
 */
@property(nonatomic, weak, nullable) id<INVImageDataSource> imageDataSource;

/**
 정보 창을 표출할 마커.
 
 정보 창이 설정된 마커의 위에 표출됩니다.
 */
@property(nonatomic, strong, nullable) INVMarker *marker;

/**
 정보 창의 위치 좌표.
 */
@property(nonatomic) INVLatLng *position;

/**
 정보 창과 좌표 또는 마커 사이의 여백. (pt 단위)
 
 기본값은 `(0, 0)`입니다.
 */
@property(nonatomic) CGPoint offset;

/**
 정보 창의 표출 상태가 변경될 때 애니메이션을 적용할지 여부.
 
 기본값은 `NO`입니다.
 */
@property (nonatomic) BOOL isTransitionEnabled;

/**
 정보 창 이미지를 다시 그립니다.
 */
- (void)invalidate;
@end
NS_ASSUME_NONNULL_END
