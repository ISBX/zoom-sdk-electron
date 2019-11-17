#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_sinks_wrap_class.h"

class ZMeetingRemoteWrap
{
public:
	ZMeetingRemoteWrap();
	virtual ~ZMeetingRemoteWrap();
	void Init();
	void Uninit();
	void SetSink(ZNativeSDKMeetingRemoteWrapSink* pSink);

	void onRemoteControlStatus(ZNRemoteControlStatus status, unsigned int userId);

	ZNSDKError RequestRemoteControl(unsigned int userId);
	ZNSDKError GiveRemoteControlTo(unsigned int userId);
	ZNSDKError CanRequestControl(unsigned int userId);
	ZNSDKError IsHaveRemoteControlRight(unsigned int userId);
	ZNSDKError IsInRemoteControllingStatus(unsigned int userId);
	ZNSDKError EnterRemoteControllingStatus(unsigned int userId);
	// ZNSDKError GiveupRemoteControl(unsigned int userId);
	ZNSDKError RevokeRemoteControl();
private:
	ZNativeSDKMeetingRemoteWrapSink* m_pSink;
};
