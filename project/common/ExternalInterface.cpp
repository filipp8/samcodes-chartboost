#ifndef STATIC_LINK
#define IMPLEMENT_API
#endif

#if defined(HX_WINDOWS) || defined(HX_MACOS) || defined(HX_LINUX)
#define NEKO_COMPATIBLE
#endif

#include <hx/CFFI.h>
#include <hx/CFFIPrime.h>

#include "SamcodesChartboost.h"

using namespace samcodeschartboost;

#ifdef IPHONE

AutoGCRoot* chartboostEventHandle = 0;

void set_listener(value onEvent)
{
	if(chartboostEventHandle == 0) {
		chartboostEventHandle = new AutoGCRoot(onEvent);
	} else {
		chartboostEventHandle->set(onEvent);
	}
}
DEFINE_PRIME1v(samcodeschartboost_set_listener);

void show_interstitial(HxString location)
{
	showInterstitial(location.c_str());
}
DEFINE_PRIME1v(samcodeschartboost_show_interstitial);

void cache_interstitial(HxString location)
{
	cacheInterstitial(location.c_str());
}
DEFINE_PRIME1v(samcodeschartboost_cache_interstitial);

bool has_interstitial(HxString location)
{
	return hasInterstitial(location.c_str());
}
DEFINE_PRIME1(samcodeschartboost_has_interstitial);

void show_rewarded_video(HxString location)
{
	showRewardedVideo(location.c_str());
}
DEFINE_PRIME1v(samcodeschartboost_show_rewarded_video);

void cache_rewarded_video(HxString location)
{
	cacheRewardedVideo(location.c_str());
}
DEFINE_PRIME1v(samcodeschartboost_cache_rewarded_video);

bool has_rewarded_video(HxString location)
{
	return hasRewardedVideo(location.c_str());
}
DEFINE_PRIME1samcodeschartboost_(has_rewarded_video);

bool is_any_view_visible()
{
	return isAnyViewVisible();
}
DEFINE_PRIME0(samcodeschartboost_is_any_view_visible);

void set_custom_id(HxString id)
{
	setCustomId(id.c_str());
}
DEFINE_PRIME1v(samcodeschartboost_set_custom_id);

HxString get_custom_id()
{
	return HxString(getCustomId());
}
DEFINE_PRIME0(samcodeschartboost_get_custom_id);

void set_should_request_interstitials_in_first_session(bool shouldRequest)
{
	setShouldRequestInterstitialsInFirstSession(shouldRequest);
}
DEFINE_PRIME1v(samcodeschartboost_set_should_request_interstitials_in_first_session);

bool get_auto_cache_ads()
{
	return getAutoCacheAds();
}
DEFINE_PRIME0(samcodeschartboost_get_auto_cache_ads);

void set_auto_cache_ads(bool autoCache)
{
	setAutoCacheAds(autoCache);
}
DEFINE_PRIME1v(samcodeschartboost_set_auto_cache_ads);

void set_should_prefetch_video_content(bool shouldPrefetch)
{
	setShouldPrefetchVideoContent(shouldPrefetch);
}
DEFINE_PRIME1v(samcodeschartboost_set_should_prefetch_video_content);

HxString get_sdk_version()
{
	return HxString(getSDKVersion());
}
DEFINE_PRIME0(samcodeschartboost_get_sdk_version);

void set_status_bar_behavior(bool shouldHide)
{
	setStatusBarBehavior(shouldHide);
}
DEFINE_PRIME1v(samcodeschartboost_set_status_bar_behavior);

void set_muted(bool mute)
{
	setMuted(mute);
}
DEFINE_PRIME1v(samcodeschartboost_set_muted);

void restrict_data_collection(bool shouldRestrict)
{
	restrictDataCollection(shouldRestrict);
}
DEFINE_PRIME1v(samcodeschartboost_restrict_data_collection);

extern "C" void samcodeschartboost_main()
{
}
DEFINE_ENTRY_POINT(samcodeschartboost_main);

extern "C" int samcodeschartboost_register_prims()
{
	return 0;
}

extern "C" void sendChartboostEvent(const char* type, const char* location, const char* uri, int reward_coins, int error, bool status)
{
	if(chartboostEventHandle == 0)
	{
		return;
	}
	value o = alloc_empty_object();
	alloc_field(o, val_id("type"), alloc_string(type));
	alloc_field(o, val_id("location"), alloc_string(location));
	alloc_field(o, val_id("uri"), alloc_string(uri));
	alloc_field(o, val_id("reward_coins"), alloc_int(reward_coins));
	alloc_field(o, val_id("error"), alloc_int(error));
	alloc_field(o, val_id("status"), alloc_bool(status));
	val_call1(chartboostEventHandle->get(), o);
}

#endif
