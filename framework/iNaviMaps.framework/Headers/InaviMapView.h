//
//  InaviMapView.h
//
//  ⓒ 2019-2020. iNavi Systems Corp. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "INVFoundation.h"

NS_ASSUME_NONNULL_BEGIN

@class INVMapCamera;

@class INVImage;
@class INVCameraPosition;
@class INVCameraUpdate;
@class INVProjection;
@class INVLatLngBounds;
@class INVMapOptions;
@class INVLocationIcon;

@protocol INVMapViewDelegate;

/**
 사용자의 위치 추적 모드를 정의하는 열거형.
 */
typedef NS_ENUM(NSUInteger, INVUserTrackingMode) {
    
    /**
     사용자 위치 추적을 사용하지 않는 모드.<br>
     이전에 기록된 사용자의 위치가 초기화되며, 위치와 베어링이 갱신되지 않습니다.
     */
    INVUserTrackingModeNone = 0,
    
    /**
     사용자 위치가 추적되지만 카메라는 변경되지 않는 모드.
     */
    INVUserTrackingModeNoTracking,
    
    /**
     사용자 위치가 추적되고 그에 따른 카메라의 위치가 변경되는 모드.
     */
    INVUserTrackingModeTracking,
    
    /**
     사용자 위치가 추적되고 그에 따른 카메라의 위치와 베어링이 변경되는 모드.
     */
    INVUserTrackingModeTrackingCompass,
};

/**
 아이나비 지도를 정의하는 뷰 클래스.<br>
 해당 클래스를 서브 뷰로 추가하여 지도를 표출할 수 있습니다.
 */

INV_EXPORT
IB_DESIGNABLE
@interface InaviMapView : UIView

#pragma mark Creating Instances

/**
 지정된 프레임 크기로 지도 뷰의 인스턴스를 생성합니다.

 @param frame 사용자 지정 프레임 크기.
 @return `InaviMapView` 인스턴스.
 */
- (instancetype)initWithFrame:(CGRect)frame;


/**
 지정된 프레임 크기와 지도의 기본 옵션을 지정하여 지도 뷰의 인스턴스를 생성합니다.
 
 @param frame 사용자 지정 프레임 크기.
 @param options 지도의 기본 옵션.
 @return `InaviMapView` 인스턴스.
 */
- (instancetype)initWithFrame:(CGRect)frame options:(INVMapOptions *)options;


#pragma mark Accessing the Delegate

/**
 `InaviMapView`의 Delegate.
 
 지도 뷰의 Delegate를 이용해 지도의 표출이나, 화면 갱신 여부 등의 메시지를 전달합니다.
 */

@property(nonatomic, weak, nullable) IBOutlet id<INVMapViewDelegate> delegate;

#pragma mark Configuring the Map’s Appearance

/**
 지도의 최소 줌 레벨.
 
 기본값은 `1`입니다.
 */
@property (nonatomic) double minimumZoomLevel;

/**
 지도의 최대 줌 레벨.
 
 기본값은 `20`입니다.
 */
@property (nonatomic) double maximumZoomLevel;

/**
 지도 이동을 제한하는 `INVLatLngBounds` 영역.
 
 `nil`로 설정할 경우 제한이 해제됩니다.
 */
@property (nonatomic, nullable) INVLatLngBounds *constraintBounds;

/**
 지도 영역 중심에 대한 카메라 위치.
 */
@property (nonatomic) INVCameraPosition *cameraPosition;

/**
 이 지도에 대한 `INVProjection` 객체.
 */
@property (nonatomic, readonly) INVProjection *projection;

/**
 지도의 패딩. 패딩에 해당하는 부분은 지도의 콘텐츠 영역에서 제외됩니다.
 */
@property (nonatomic, assign) UIEdgeInsets contentInset;

/**
 지도 영역에 대한 `INVLatLngBounds`.
 */
@property (nonatomic, readonly, copy) INVLatLngBounds *contentBounds;

/**
 축척 바 표출 여부.
 
 기본값은 `YES`입니다.
 */
@property (nonatomic, assign) IBInspectable BOOL showScaleBar;

/**
 나침반 표출 여부.

 기본값은 `YES`입니다.
 */
@property(nonatomic, assign) IBInspectable BOOL showCompass;

/**
 줌 컨트롤 표출 여부.
 
 기본값은 `NO`입니다.
 */
@property (nonatomic) IBInspectable BOOL showZoomControl;

/**
 현위치 버튼 표출 여부.
 
 기본값은 `NO`입니다.
 */
@property (nonatomic) IBInspectable BOOL showLocationButton;

#pragma mark Displaying the User’s Location

/**
 위치 추적 모드.
 
 @see `INVUserTrackingMode`
 */
@property (nonatomic, assign) INVUserTrackingMode userTrackingMode;

/**
 현위치 아이콘.
 */
@property (readonly, strong, nonatomic) INVLocationIcon * _Nonnull locationIcon;

#pragma mark Configuring How the User Interacts with the Map

/**
 지도 줌 제스처 사용 여부를 나타내는 속성.
 
 기본값은 `YES`입니다.
 */
@property(nonatomic, getter=isZoomGesturesEnabled) BOOL zoomGesturesEnabled;

/**
 지도 스크롤 제스처 사용 여부를 나타내는 속성.
 
 기본값은 `YES`입니다.
 */
@property(nonatomic, getter=isScrollGesturesEnabled) BOOL scrollGesturesEnabled;

/**
 지도 회전 제스처 사용 여부를 나타내는 속성.
 
 기본값은 `YES`입니다.
 */
@property(nonatomic, getter=isRotateGesturesEnabled) BOOL rotateGesturesEnabled;

/**
 지도 기울기 제스처 사용 여부를 나타내는 속성.
 
 기본값은 `YES`입니다.
 */
@property(nonatomic, getter=isTiltGesturesEnabled) BOOL tiltGesturesEnabled;


/**
 로고 클릭 시 SDK 정보 팝업 표출 여부를 나타내는 속성.
 
 비활성화 시 별도의 페이지에 아이나비 지도 SDK의 오픈 소스 라이선스와 법적 고지를 제공해야 합니다.<br>
 기본값은 `YES`입니다.
 
 @see `+[INVMapSdk presentLicenseViewController]`<br>`+[INVMapSdk presentLegalNoticeViewController]`
 */
@property(nonatomic, getter=isLogoClickEnabled) BOOL logoClickEnabled;


/**
 지도 애니메이션 마찰 계수 입니다.
 값의 범위는 `0~1`이며, 계수가 클수록 마찰이 강해집니다.
 
 기본값은 `UIScrollViewDecelerationRateNormal`입니다.
 */
@property(nonatomic) CGFloat decelerationRate;
#pragma mark Manipulating the Viewpoint

/**
 카메라를 이동합니다.
 
 @param cameraUpdate `INVCameraUpdate` 객체.
 */
- (void)moveCamera:(INVCameraUpdate *)cameraUpdate;

/**
 카메라를 이동합니다.
 카메라 이동이 완료되거나 취소되었을 경우 `completion` 블록이 호출됩니다.
 
 @param cameraUpdate `INVCameraUpdate` 객체.
 @param completion   카메라 이동이 완료되었을 때 호출되는 콜백 블록. (완료 전에 다른 지도 조작으로 취소 여부를 isCancelled로 전달합니다.)
 */
- (void)moveCamera:(INVCameraUpdate *)cameraUpdate completion:(nullable void (^)(BOOL isCancelled))completion;

/**
 현재 진행 중인 지도 이동 애니메이션을 취소합니다.
 */
- (void)cancelTransitions;


/**
 특정 `INVLatLngBounds` 전체 영역이 보이는 중심 좌표와 줌 레벨을 포함하는 `INVCameraPosition` 객체를 반환합니다.

 @param bounds `INVLatLngBounds` 객체.
 @return `INVCameraPosition` 객체.
*/
- (INVCameraPosition *)cameraFitBounds:(INVLatLngBounds*)bounds;

/**
 특정 `INVLatLngBounds` 전체 영역이 보이는 중심 좌표와 줌 레벨을 포함하는 `INVCameraPosition` 객체를 반환합니다.

 @param bounds `INVLatLngBounds` 객체.
 @param insets 패딩 값. (pt 단위)
 @return `INVCameraPosition` 객체.
*/
- (INVCameraPosition *)cameraFitBounds:(INVLatLngBounds*)bounds insets:(UIEdgeInsets)insets;


/**
지도에 등록된 모든 셰이프를 지도에서 제거합니다.

 @see `INVShape.mapView`
*/
- (void)clearShapes;

@end

NS_ASSUME_NONNULL_END
