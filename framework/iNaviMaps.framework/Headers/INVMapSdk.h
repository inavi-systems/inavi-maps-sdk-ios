//
//  INVMapSdk.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import "INVFoundation.h"

@class UIViewController;
@class INVMapStyle;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, INVErrorCode) {
    
    /**
     인증 시도하지 않은 상태
     */
    INVAuthInitialize    = -1,
    /**
     인증 성공
     */
    INVAuthSuccess       = 0,
    /**
     인증 실패
     */
    INVAuthFailure       = 1,

    /**
     설정된 Appkey가 유효하지 않음,
     */
    INVAppKeyInvalid     = 300,

    /**
     Appkey 설정되지 않음,
     */
    INVAppKeyError       = 401,
    /**
     서버 연결 실패,
     */
    INVConnectionFail    = 503,
    /**
     서버 연결 시간 초과,
     */
    INVConnectionTimeOut = 504,
    /**
     알 수 없는 에러
     */
    INVUnknownError      = 500,
    
};

/**
  아이나비 지도 인증 결과를 알려주는 콜백 메서드가 정의된 프로토콜.
 */
@protocol INVMapSdkDelegate <NSObject>
@optional
/**
 아이나비 지도 인증에 실패했을 때 호출되는 콜백.
 @param errorCode 인증 실패 오류 코드
 @param message 인증 실패 메시지
 */
- (void)authFailure:(NSInteger)errorCode message:(NSString*)message;

/**
 아이나비 지도 인증에 성공했을 때 커스텀 스타일 배열과 함께 호출되는 콜백.<br>
 커스텀 지도 스타일 배열은 SDK에 저장되며 `INVMapSdk.savedCustomMapStyles`에서 확인할 수 있습니다.
 
 @param customMapStyles 커스텀 지도 스타일 배열
 */
- (void)authSuccess:(NSArray<INVMapStyle*> *)customMapStyles;
@end


/**
 아이나비 지도 SDK의 인증을 담당하는 클래스.
 아이나비 지도 SDK를 사용하기 위해서는 아래 중 한 가지 방법으로 Appkey 설정을 해주어야 합니다.
 #### 1. `info.plist`에 지정하는 방식
 ### examples
     <dict>
         <key>iNaviAppKey</key>
         <string>YOUR_APP_KEY</string>
     <dict>
 #### 2. Application 생성 시점에 Appkey를 설정하는 함수를 동적으로 호출
 ```swift
 INVMapSdk.sharedInstance().appKey = "YOUR_APP_KEY"
 ```
 */

INV_EXPORT

@interface INVMapSdk : NSObject

/**
 싱글턴 객체 접근
 */
+ (nonnull instancetype)sharedInstance;

/**
 지도 캐시 데이터를 삭제합니다.
 */
- (void)clearCache;

/**
 오픈 소스 라이선스 `UIViewController`를 표출합니다.
*/
+ (void)presentLicenseViewController;

/**
 법적 고지 `UIViewController`를 표출합니다.
*/
+ (void)presentLegalNoticeViewController;

/**
 아이나비 지도 인증 결과가 전달되는 delegate
 */
@property (nonatomic, weak) id<INVMapSdkDelegate> delegate;

/**
 지도 인증 AppKey
 */
@property (nonatomic, nullable) NSString *appKey;

/**
 저장된 커스텀 지도 스타일 배열
 */
@property (nonatomic, readonly) NSArray<INVMapStyle *> *savedCustomMapStyles;

@end

NS_ASSUME_NONNULL_END
