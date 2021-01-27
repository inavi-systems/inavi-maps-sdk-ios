//
//  INVMapViewDelegate.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "iNaviMaps.h"

NS_ASSUME_NONNULL_BEGIN

@class InaviMapView;
@class INVLatLng;

/**
`InaviMapView`의 비동기 작업 및 속성 변화의 결과를 알려주는 함수가 정의된 프로토콜.
*/
@protocol INVMapViewDelegate <NSObject>

@optional

#pragma mark Responding to Map Position Changes


/**
 지도가 표시하는 영역이 변경될 때 호출되는 콜백 메서드.

 @param mapView 영역이 변경될 `InaviMapView` 객체.
 @param animated 애니메이션 효과가 적용돼 움직일 경우 `YES`, 그렇지 않을 경우 `NO`.
 @param reason 카메라 변경 이유.
 */
- (void)mapView:(InaviMapView *)mapView regionWillChangeAnimated:(BOOL)animated reason:(NSInteger)reason;

/**
 지도가 표시하고 있는 영역이 변경되고 있을 때 호출되는 콜백 메서드.

 @param mapView 영역이 변경되고 있는 `InaviMapView` 객체.
 @param reason 카메라 변경 이유.
 */
- (void)mapView:(InaviMapView *)mapView regionIsChangingWithReason:(NSInteger)reason;

/**
 지도가 표시하고 있는 영역이 변경되었을 때 호출되는 콜백 메서드.

 @param mapView 영역이 변경된 `InaviMapView` 객체.
 @param animated 애니메이션 효과가 적용돼 움직인 경우 `YES`, 그렇지 않은 경우 `NO`.
 @param reason 카메라 변경 이유.
 */
- (void)mapView:(InaviMapView *)mapView regionDidChangeAnimated:(BOOL)animated reason:(NSInteger)reason;


/**
 추가적인 데이터나 지도와 상호 작용이 없는 유휴 상태로 진입할 때마다 호출되는 콜백 메서드.
 
 @param mapView 유휴 상태로 진입한 `InaviMapView` 객체.
 */
- (void)mapViewDidBecomeIdle:(InaviMapView *)mapView;

#pragma mark Responding to Map Event

/**
 사용자가 지도를 탭했을 때 호출되는 콜백 메서드.

 @param point 탭한 화면 좌표.
 @param latlng 탭한 위경도 좌표.
 */
- (void)didTapMapView:(CGPoint)point LatLng:(INVLatLng*)latlng;

/**
 사용자가 지도를 더블 탭했을 때 호출되는 콜백 메서드.

 @param point 더블 탭한 화면 좌표.
 @param latlng 더블 탭한 위경도 좌표.
 @return `YES`일 경우 이벤트를 소비합니다. 그렇지 않을 경우 `InaviMapView`까지 이벤트가 전달됩니다.
 */
- (BOOL)didDoubleTapMapView:(CGPoint)point LatLng:(INVLatLng*)latlng;

/**
 사용자가 지도를 롱 탭했을 때 호출되는 콜백 메서드.
 
 @param point 롱 탭한 화면 좌표.
 @param latlng 롱 탭한 위경도 좌표.
 */
- (void)didLongTapMapView:(CGPoint)point LatLng:(INVLatLng*)latlng;

#pragma mark Responding to User Location

/**
 위치 추적 모드가 변경되었을 때 호출되는 콜백 메서드.

 @param mapView 위치 추적 모드가 적용된 `InaviMapView` 객체.
 @param mode 위치 추적 모드.
 @param animated 애니메이션 효과가 적용돼 움직인 경우 `YES`, 그렇지 않은 경우 `NO`.
 */
- (void)mapView:(InaviMapView *)mapView didChangeUserTrackingMode:(INVUserTrackingMode)mode animated:(BOOL)animated;

/**
 위치가 업데이트 되었을 때 호출되는 콜백 메서드.

@param mapView 위치 추적 모드가 적용된 `InaviMapView` 객체.
@param userLocation 업데이트 된 위치
*/
- (void)mapView:(InaviMapView *)mapView didUpdateUserLocation:(nullable CLLocation *)userLocation;
@end
NS_ASSUME_NONNULL_END
