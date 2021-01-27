//
//  INVCluster.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import "INVFoundation.h"
#import "INVClusterItem.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * `INVClusterManager`를 이용하여 생성된 클러스터를 정의한 프로토콜.
 */
@protocol INVCluster <NSObject>

/**
 * 클러스터의 좌표.
 */
@property(nonatomic, readonly) INVLatLng *position;

/**
 * 클러스터에 포함된 아이템의 개수.
 */
@property(nonatomic, readonly) NSUInteger count;

/**
 * 클러스터에 포함된 아이템 배열.
 */
@property(nonatomic, readonly) NSArray<id<INVClusterItem>> *items;

@end
NS_ASSUME_NONNULL_END
