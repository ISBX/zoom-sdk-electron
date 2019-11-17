const { ZoomSDKError } = require('./settings.js');

var ZoomMeetingShare = (function () {
  var instance;
  var sharingUserId;
   /**
   * mode: Zoom SDK Meeting share module Init
   * @param {Object} addon zoom sdk module
   * @return {ZoomMeetingShare}
   */
  function init(opts) {
    let clientOpts = opts || {};
    // Private methods and variables
    let meetingShareCtrl = clientOpts.addon.GetMeetingShareCtrl() || null;
    let meetingRemoteCtrl = clientOpts.addon.GetMeetingRemoteCtrl() || null;

    function onSharingStatus(status, userId) {
      sharingUserId = userId;
      console.log('onSharingStatus', status, userId);
    }

    if (meetingShareCtrl) {
      meetingShareCtrl.SetOnSharingStatusCB(onSharingStatus);
    }

    return {
      // Public methods and variables
      /** 
      * mode: Start app share
      * @param {String} zn_hShare_app Specifies which the window is to be shared (require hexadecimal)
      * @return {ZoomSDKError}
      */
      MeetingShare_StartAppShare: function (opts) {
        if (meetingShareCtrl) {
          let clientOpts = opts || {};
          let zn_hShare_app = clientOpts.zn_hShare_app;
          return meetingShareCtrl.StartAppShare(zn_hShare_app);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: start desktopshare 
      * @param {String} zn_monitorID Specifies which the monitor is to be shared.Using EnumDisplayMonitors System api to get this value.
      * @return {ZoomSDKError}
      */
      MeetingShare_StartMonitorShare: function (opts) {
        if (meetingShareCtrl) {
          let clientOpts = opts || {};
          let zn_monitorID = clientOpts.zn_monitorID;
          return meetingShareCtrl.StartMonitorShare(zn_monitorID);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: request remote control
      * @return {ZoomSDKError}
      */
      MeetingShare_RequestRemoteControl: function () {
        if (meetingShareCtrl) {
          console.log('MeetingShare_RequestRemoteControl userId', sharingUserId)
          return meetingRemoteCtrl.RequestRemoteControl(sharingUserId);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: request remote control
      * @return {ZoomSDKError}
      */
      MeetingShare_GiveRemoteControlTo: function (userId) {
        if (meetingShareCtrl) {
          console.log('MeetingShare_GiveRemoteControlTo userId', userId)
          return meetingRemoteCtrl.GiveRemoteControlTo(userId);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }, 
      MeetingShare_CanRequestControl: function (userId) {
        if (meetingShareCtrl) {
          console.log('MeetingShare_CanRequestControl userId', userId)
          return meetingRemoteCtrl.CanRequestControl(userId);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },  
      MeetingShare_IsHaveRemoteControlRight: function (userId) {
        if (meetingShareCtrl) {
          console.log('MeetingShare_IsHaveRemoteControlRight userId', userId)
          return meetingRemoteCtrl.IsHaveRemoteControlRight(userId);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },  
      MeetingShare_IsInRemoteControllingStatus: function (userId) {
        if (meetingShareCtrl) {
          console.log('MeetingShare_IsInRemoteControllingStatus userId', userId)
          return meetingRemoteCtrl.IsInRemoteControllingStatus(userId);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },  
      MeetingShare_EnterRemoteControllingStatus: function (userId) {
        if (meetingShareCtrl) {
          console.log('MeetingShare_EnterRemoteControllingStatus userId', userId)
          return meetingRemoteCtrl.EnterRemoteControllingStatus(userId);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },  
      MeetingShare_RevokeRemoteControl: function () {
        if (meetingShareCtrl) {
          console.log('MeetingShare_RevokeRemoteControl')
          return meetingRemoteCtrl.RevokeRemoteControl();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },                                
      /**
      * mode:  stop share 
      * @return {ZoomSDKError}
      */
      MeetingShare_StopShare: function () {
        if (meetingShareCtrl) {
          return meetingShareCtrl.StopShare();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode:  Set OnSharingStatusb CB
      * @return {ZoomSDKError}
      */
      SetOnSharingStatusCB: function (onSharingStatus) {
        if (meetingShareCtrl) {
          meetingShareCtrl.SetOnSharingStatusCB(onSharingStatus);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
  };
 
  return {
    /**
     * mode: Get Zoom SDK Meeting Audio Module
     * @return {ZoomMeetingShare}
    */
    getInstance: function (opts) {
      if (!instance) {
        instance = init(opts);
      }
      return instance;
    }
  };
})();

module.exports = {
  ZoomMeetingShare: ZoomMeetingShare,
}