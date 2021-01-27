//
//  INVClusterManager.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import "INVFoundation.h"
#import "INVClusterItem.h"
#import "INVClusterManagerDelegate.h"
#import "INVClusterIconGenerator.h"

@class InaviMapView;
@class INVMarker;

NS_ASSUME_NONNULL_BEGIN

/**
 클러스터링을 관리하는 클래스.<br>
 특정 데이터를 기반으로 단일 아이템 또는 아이템의 집합(클러스터)을 지도 위에 표출할 때 사용합니다.
 */
INV_EXPORT
@interface INVClusterManager : NSObject

#pragma mark Creating Instances

/**
 `initWithMapView:` 생성자를 사용하세요.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 지도 객체를 이용하여 `INVClusterManager` 객체를 생성합니다.
 
 @param mapView 지도 객체.
 @return `INVClusterManager` 객체.
 */
- (instancetype)initWithMapView:(InaviMapView *)mapView NS_DESIGNATED_INITIALIZER;

#pragma mark Accessing the Delegate

/**
 `INVClusterManager`의 Delegate.
 */
@property(nonatomic, weak, nullable) id<INVClusterManagerDelegate> delegate;

#pragma mark Properties for Clustering

/**
 클러스터링이 되기 위해 필요한 최소 아이템 개수.
 
 기본값은 `2`입니다.
 */
@property(nonatomic) NSUInteger minClusteringCount;

/**
 클러스터링이 되기 위해 필요한 아이템 사이의 최대 간격. (pt 단위)<br>
 값이 클수록 클러스터가 구성되는 범위가 넓어집니다.
 
 기본값은 `200`입니다.
 */
@property(nonatomic) NSUInteger maxDistanceBetweenItems;

/**
 클러스터가 지도 위에 표출될 때 아이콘 이미지를 만들어주는 생성기.<br>
 해당 속성을 설정하지 않으면 기본 아이콘 이미지가 설정되어 지도에 표출됩니다.
 */
@property(nonatomic) id<INVClusterIconGenerator> clusterIconGenerator;

#pragma mark Configuring Items for Clustering

/**
 아이템을 추가합니다.
 
 @param item 추가할 아이템.
 */
- (void)addItem:(id<INVClusterItem>)item;

/**
 복수의 아이템을 추가합니다.
 
 @param items 추가할 아이템 배열.
 */
- (void)addItems:(NSArray<id<INVClusterItem>> *)items;

/**
 아이템을 제거합니다.
 
 @param item 제거할 아이템.
*/
- (void)removeItem:(id<INVClusterItem>)item;

/**
 복수의 아이템을 제거합니다.
 
 @param items 제거할 아이템 배열.
 */
- (void)removeItems:(NSArray<id<INVClusterItem>> *)items;

/**
 모든 아이템을 제거합니다.
 */
- (void)clearItems;

#pragma mark Redraw Clusters

/**
 클러스터를 다시 그립니다.
 */
- (void)invalidate;

@end

NS_ASSUME_NONNULL_END
