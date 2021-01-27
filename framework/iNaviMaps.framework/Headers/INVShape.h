//
//  INVShape.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "INVFoundation.h"
#import "INVLatLng.h"
#import "INVShapeOptions.h"

@class INVShape;
@class InaviMapView;

NS_ASSUME_NONNULL_BEGIN


/**
 셰이프 터치에 대한 이벤트 블록 타입 선언.
 
 @return 이벤트 소비 여부. `YES`이면 이벤트가 지도로 전달되지 않습니다. `NO`를 반환할 경우 `InaviMapView`까지 이벤트가 전달되어 `-[INVMapViewDelegate didTapMapView:LatLng:]`가 호출됩니다.
 */

typedef BOOL (^INVShapeTouchEvent)(INVShape * __weak);

/**
 연결점의 모양을 정의한 열거형.
 */
typedef NS_ENUM(NSUInteger, INVLineJoin) {
    /**
     사면.
     */
    INVLineJoinBevel,
    /**
     원형.
     */
    INVLineJoinRound,
    /**
     미터.
     */
    INVLineJoinMiter,
};

/**
 끝 지점의 모양을 정의한 열거형.
 */
typedef NS_ENUM(NSUInteger, INVLineCap) {
    /**
     평면.
     */
    INVLineCapButt,
    /**
     원형.
     */
    INVLineCapRound,
    /**
     사각형.
     */
    INVLineCapSquare,
};

/**
 아이나비 지도 위에 표출되는 셰이프의 속성을 관리하는 클래스.<br>
 지도에 추가하거나 제거할 수 있습니다.
 */
INV_EXPORT
@interface INVShape : NSObject <INVShapeOptions>


#pragma mark Accessing the Shape Attributes

/**
셰이프의 고유 ID.
*/
@property (nonatomic, readonly) NSString* identifier;

/**
 셰이프에 저장할 사용자 정보.
 */
@property (nonatomic, strong) NSDictionary *userInfo;

/**
 셰이프를 등록할 지도 객체.
 
 지도에 셰이프가 등록되면 지도상에 셰이프가 표출됩니다.<br>
 `nil`로 설정할 경우 셰이프가 지도에서 제거됩니다.
 */
@property (nonatomic, weak, nullable) InaviMapView *mapView;

/**
 셰이프의 Z 인덱스.
 
 두 셰이프가 겹쳐진 경우, 높은 값일 수록 앞에 표출됩니다.
 */
@property (nonatomic) NSInteger zIndex;

/**
 셰이프의 전역 Z 인덱스.
 */
@property(nonatomic) NSInteger globalZIndex;

/**
 셰이프가 표출되기 위한 최소 줌 레벨.
 
 기본값은 `1`입니다.
 */
@property (nonatomic) double visibleMinZoom;

/**
 셰이프가 표출되기 위한 최대 줌 레벨.
 
 기본값은 `20`입니다.
 */
@property (nonatomic) double visibleMaxZoom;

/**
 셰이프 표출 여부.

 값이 `NO`이면 셰이프 관련 이벤트를 전달받을 수 없습니다.<br>
 셰이프가 지도 영역 밖에 위치하더라도 해당 값은 변함 없이 유지됩니다.
 */
@property (nonatomic, assign, getter=isVisible) BOOL visible;

/**
 셰이프 객체가 지도에 등록된 상태인지 여부.
 */
@property (nonatomic, readonly) BOOL isAttached;

/**
 셰이프가 터치되었을 때 호출되는 이벤트 블록.
 */
@property (nonatomic, nullable) INVShapeTouchEvent touchEvent;

@end

/**
 셰이프에서 사용하는 이미지 리소스를 생성하는 기본 프로토콜.
 */
@protocol INVImageDataSource <NSObject>
@required
@end

/**
 셰이프에서 사용하는 이미지 리소스를 `UIView`로 구성하는 프로토콜.
 */
@protocol INVImageViewDataSource <INVImageDataSource>
@required

/**
 이미지로 변환할 `UIView`를 구성해야 합니다.
 @param shape 이미지를 사용하는 `INVShape` 객체.
 @return 이미지로 변환할 `UIView` 객체.
 */
- (UIView *)viewWithShape:(INVShape *)shape;

@end


/**
 셰이프에서 사용하는 이미지 리소스를 `NSString`으로 구성하면 title을 포함해 기본 배경이 있는 이미지로 구성하는 프로토콜
 */
@protocol INVImageTextDataSource <INVImageDataSource>
@required

/**
 이미지로 변환할 `NSString`을 구성해야 합니다.
 @param shape 이미지를 사용하는 `INVShape` 객체.
 @return 기본 이미지로 변환할 `NSString` 객체.
 */
- (NSString *)titleWithShape:(INVShape *)shape;
@end


NS_ASSUME_NONNULL_END
