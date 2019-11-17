
#include "../meeting_remote_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "wrap/meeting_service_components_wrap/meeting_remote_ctrl_wrap.h"
#include "zoom_native_to_wrap.h"


extern ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& g_meeting_service_wrap;
class ZMeetingRemoteCtrlWrapEvent : public ZOOM_SDK_NAMESPACE::IMeetingRemoteCtrlEvent
{
public:
	void SetOwner(ZMeetingRemoteWrap* obj) { owner_ = obj; }
	virtual void onRemoteControlStatus(ZOOM_SDK_NAMESPACE::RemoteControlStatus status, unsigned int userId)
	{
		if (owner_) {
			
				owner_->onRemoteControlStatus(Map2WrapDefine(status), userId);
			}
		
	}

private:
	ZMeetingRemoteWrap* owner_;
};

static ZMeetingRemoteCtrlWrapEvent g_meeting_remote_ctrl_event;

ZMeetingRemoteWrap::ZMeetingRemoteWrap()
{
	g_meeting_remote_ctrl_event.SetOwner(this);
	m_pSink = 0;
}
ZMeetingRemoteWrap::~ZMeetingRemoteWrap()
{
	Uninit();
	m_pSink = 0;
	g_meeting_remote_ctrl_event.SetOwner(NULL);
}
void ZMeetingRemoteWrap::Init()
{
	

	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRemoteController().SetEvent(&g_meeting_remote_ctrl_event);
}
void ZMeetingRemoteWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRemoteController().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRemoteController().Uninit_Wrap();
}
ZNSDKError ZMeetingRemoteWrap::RequestRemoteControl(unsigned int userId)
{

	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRemoteController().RequestRemoteControl(userId));
	
}
ZNSDKError ZMeetingRemoteWrap::GiveRemoteControlTo(unsigned int userId)
{

	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRemoteController().GiveRemoteControlTo(userId));
	
}
ZNSDKError ZMeetingRemoteWrap::CanRequestControl(unsigned int userId)
{

	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRemoteController().CanRequestControl(userId));
	
}
ZNSDKError ZMeetingRemoteWrap::IsHaveRemoteControlRight(unsigned int userId)
{

	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRemoteController().IsHaveRemoteControlRight(userId));
	
}
ZNSDKError ZMeetingRemoteWrap::IsInRemoteControllingStatus(unsigned int userId)
{

	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRemoteController().IsInRemoteControllingStatus(userId));
	
}
ZNSDKError ZMeetingRemoteWrap::EnterRemoteControllingStatus(unsigned int userId)
{

	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRemoteController().EnterRemoteControllingStatus(userId));
	
}
ZNSDKError ZMeetingRemoteWrap::RevokeRemoteControl()
{

	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRemoteController().RevokeRemoteControl());
	
}
void ZMeetingRemoteWrap::onRemoteControlStatus(ZNRemoteControlStatus status, unsigned int userId)
{
	if (m_pSink)
	{
		m_pSink->onRemoteControlStatus(status, userId);
	}
	
}
void ZMeetingRemoteWrap::SetSink(ZNativeSDKMeetingRemoteWrapSink* pSink)
{
	m_pSink = pSink;
}