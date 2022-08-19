//
//  INVKatec.h
//
//  Created by DongWon Park on 2022/08/09.
//  ⓒ 2019-2022. iNavi Systems Corp. All rights reserved.
//

#import "INVFoundation.h"
#import "INVLatLng.h"

NS_ASSUME_NONNULL_BEGIN

/**
 KATEC 좌표를 나타내는 클래스.
 */
INV_EXPORT
@interface INVKatec : NSObject
/**
 x 좌표.
 */
@property (nonatomic, readonly) double x;

/**
 y 좌표.
 */
@property (nonatomic, readonly) double y;


/**
 특정 위치에 대한 KATEC 좌표를 생성합니다.
 
 @param x 좌표.
 @param y 좌표.
 @return INVKatec 객체.
 */
+ (nonnull instancetype)katecWithX:(double)x y:(double)y;

/**
 위경도 좌표로 KATEC 좌표를 생성합니다.
 
 @param latLng 변환할 위경도 좌표.
 @return INVKatec 객체.
 */
+ (nonnull instancetype)katecWithLatLng:(nonnull INVLatLng *)latLng;

/**
 KATEC 좌표를 위경도 `INVLatLng` 객체로 변환합니다.
 
 @return 변환된 위경도 좌표.
 */
- (nonnull INVLatLng *)toLatLng;
@end
NS_ASSUME_NONNULL_END
