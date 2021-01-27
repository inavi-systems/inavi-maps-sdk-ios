//
//  INVCameraPosition.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import "INVFoundation.h"
#import "INVLatLng.h"

NS_ASSUME_NONNULL_BEGIN

/**
 카메라의 위치 정보 관련 클래스.
 */

INV_EXPORT
@interface INVCameraPosition : NSObject

/**
 카메라의 위치 좌표.
 */
@property (nonatomic, strong, readonly) INVLatLng *target;


/**
 줌 레벨. 지도에서 보여질 축척을 의미합니다. 값이 증가할수록 지도가 확대되어 보여집니다.
 */
@property (nonatomic, readonly) double zoom;

/**
 기울기 각도. 카메라가 지면을 내려다보는 각도를 의미합니다. (도 단위)
 값이 '0'이면 지면을 수직으로 내려다보는 경우를 의미하며, 수평으로 비스듬해질수록 값이 증가합니다.
 */
@property (nonatomic, readonly) double tilt;

/**
 베어링 각도. 카메라가 바라보는 방위를 의미합니다. (도 단위)
 값이 '0'이면 북쪽을 의미하며, 시계 방향으로 값이 증가합니다. '360'의 배수마다 다시 북쪽이 됩니다.
 */
@property (nonatomic, readonly) double bearing;


/**
 좌표, 줌 레벨, 기울기, 베어링으로 `INVCameraPosition`객체를 생성합니다.
 
 @param target 카메라의 좌표.
 @param tilt 카메라의 기울기 각도.
 @param bearing 카메라의 베어링 각도.
 
 @return `INVCameraPosition` 객체.
 */
+ (instancetype)cameraPosition:(INVLatLng *)target zoom:(double)zoom tilt:(double)tilt bearing:(double)bearing;

/**
 좌표와 줌 레벨로 `INVCameraPosition`객체를 생성합니다.
 
 @param target 카메라의 좌표.
 @param zoom 카메라의 줌 레벨.
 
 @return `INVCameraPosition` 객체.
 */
+ (instancetype)cameraPosition:(INVLatLng *)target zoom:(double)zoom;

@end

NS_ASSUME_NONNULL_END
