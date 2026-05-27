//
//  INVFloor.h
//
//  ⓒ 2019-2026. iNavi Systems Corp. All rights reserved.
//

#import "INVFoundation.h"

NS_ASSUME_NONNULL_BEGIN
/**
 실내 지도에서 층을 표현하는 모델 객체.
 */
INV_EXPORT
@interface INVFloor : NSObject

/** 
 실내 지도에서 층 식별자.
 */
@property (nonatomic, strong, nullable) NSString *floorId;

/**
 실내 지도에서 층 명칭.
*/
@property (nonatomic, strong, nullable) NSString *name;
@end

NS_ASSUME_NONNULL_END
