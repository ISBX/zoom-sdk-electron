#ifndef _ZOOM_NODE_MEETING_REMOTE_CTRL_H_
#define _ZOOM_NODE_MEETING_REMOTE_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeMeetingRemoteCtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingRemoteCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingRemoteCtrlWrap >;
private:
	ZoomNodeMeetingRemoteCtrlWrap();
	~ZoomNodeMeetingRemoteCtrlWrap();
public:
	/// \brief Request Remote Control.
	/// \param 1. userId(number) Specify the userId to get remote control.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void RequestRemoteControl(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GiveRemoteControlTo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void CanRequestControl(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsHaveRemoteControlRight(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsInRemoteControllingStatus(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnterRemoteControllingStatus(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void RevokeRemoteControl(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetOnRemoteControlStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args);


	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingRemoteCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingRemoteCtrlWrap"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "RequestRemoteControl", ZoomNodeMeetingRemoteCtrlWrap::RequestRemoteControl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GiveRemoteControlTo", ZoomNodeMeetingRemoteCtrlWrap::GiveRemoteControlTo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanRequestControl", ZoomNodeMeetingRemoteCtrlWrap::CanRequestControl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsHaveRemoteControlRight", ZoomNodeMeetingRemoteCtrlWrap::IsHaveRemoteControlRight);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsInRemoteControllingStatus", ZoomNodeMeetingRemoteCtrlWrap::IsInRemoteControllingStatus);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnterRemoteControllingStatus", ZoomNodeMeetingRemoteCtrlWrap::EnterRemoteControllingStatus);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RevokeRemoteControl", ZoomNodeMeetingRemoteCtrlWrap::RevokeRemoteControl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnRemoteControlStatusCB", ZoomNodeMeetingRemoteCtrlWrap::SetOnRemoteControlStatusCB);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingRemoteCtrlWrap >() {
	return &ZoomNodeMeetingRemoteCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
