#import <UIKit/UIKit.h>

#import "INVFoundation.h"


NS_ASSUME_NONNULL_BEGIN

/**
 <a href="https://docs.toast.com/ko/Application%20Service/Maps/ko/Overview/" target="_blank">Map Studio</a> 서비스를 이용하여 생성된 커스텀 지도 스타일을 나타내는 클래스.
 
 아이나비 지도 인증이 완료되면 `-[INVMapSdkDelegate authSuccess:]` 콜백으로 커스텀 지도 스타일 배열이 전달됩니다. 커스텀 지도 스타일 배열은 SDK에 저장되며 `INVMapSdk.savedCustomMapStyles`에서 확인할 수 있습니다.
 */
INV_EXPORT
@interface INVMapStyle : NSObject <NSSecureCoding>

/**
 지도 스타일의 이름.
 */
@property (nonatomic, readonly) NSString* styleName;

/**
 지도 스타일의 ID.
 */
@property (nonatomic, readonly) NSString* styleID;

/**
 지정된 지도 스타일의 이름과 ID로 지도 스타일 객체를 생성합니다.

 @param styleName 스타일의 이름.
 @param styleID 스타일의 ID.
 @return `INVMapStyle` 객체.
 */
+ (instancetype)mapStyleWithStyleName:(nonnull NSString *)styleName
                              styleID:(nonnull NSString *)styleID;

@end
NS_ASSUME_NONNULL_END
