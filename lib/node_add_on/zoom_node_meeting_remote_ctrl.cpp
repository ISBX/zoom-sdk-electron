#include "zoom_node_meeting_remote_ctrl.h"


ZoomNodeMeetingRemoteCtrlWrap::ZoomNodeMeetingRemoteCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingRemoteCtrl().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_meetingRemoteControlWrapSink);
}

ZoomNodeMeetingRemoteCtrlWrap::~ZoomNodeMeetingRemoteCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingRemoteCtrl().SetSink(NULL);
}
void ZoomNodeMeetingRemoteCtrlWrap::RequestRemoteControl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsNumber())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	unsigned int userId = (unsigned int)args[0].As<v8::Integer >()->Value();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingRemoteCtrl().RequestRemoteControl(userId);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingRemoteCtrlWrap::GiveRemoteControlTo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsNumber())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	unsigned int userId = (unsigned int)args[0].As<v8::Integer >()->Value();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingRemoteCtrl().GiveRemoteControlTo(userId);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingRemoteCtrlWrap::CanRequestControl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsNumber())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	unsigned int userId = (unsigned int)args[0].As<v8::Integer >()->Value();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingRemoteCtrl().CanRequestControl(userId);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingRemoteCtrlWrap::IsHaveRemoteControlRight(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsNumber())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	unsigned int userId = (unsigned int)args[0].As<v8::Integer >()->Value();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingRemoteCtrl().IsHaveRemoteControlRight(userId);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingRemoteCtrlWrap::IsInRemoteControllingStatus(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsNumber())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	unsigned int userId = (unsigned int)args[0].As<v8::Integer >()->Value();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingRemoteCtrl().IsInRemoteControllingStatus(userId);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingRemoteCtrlWrap::EnterRemoteControllingStatus(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsNumber())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	unsigned int userId = (unsigned int)args[0].As<v8::Integer >()->Value();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingRemoteCtrl().EnterRemoteControllingStatus(userId);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingRemoteCtrlWrap::RevokeRemoteControl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingRemoteCtrl().RevokeRemoteControl();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingRemoteCtrlWrap::SetOnRemoteControlStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onRemoteControlStatus = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}