#include "Titta/utils.h"

#include <sstream>

namespace
{
    struct TobiiResearchStatusInfo
    {
        const char* _cName;     /* Name of Constant */
        int			_uVal;      /* Constant's value as int */
        const char* _cErrorTxt; /* Explanatory text for error */
    };

    TobiiResearchStatusInfo lookupTobiiResearchStatus(TobiiResearchStatus in_)
    {
        switch (in_)
        {
            // the below is code generated by the matlab script tools/TobiiResearchEnumLister.m
            case TOBII_RESEARCH_STATUS_OK:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_OK", static_cast<int>(TOBII_RESEARCH_STATUS_OK), "No error"};
            case TOBII_RESEARCH_STATUS_FATAL_ERROR:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_FATAL_ERROR", static_cast<int>(TOBII_RESEARCH_STATUS_FATAL_ERROR), "Fatal error"};
            case TOBII_RESEARCH_STATUS_INITIALIZE_FAILED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_INITIALIZE_FAILED", static_cast<int>(TOBII_RESEARCH_STATUS_INITIALIZE_FAILED), "Failed to initialize the API"};
            case TOBII_RESEARCH_STATUS_TERMINATE_FAILED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_TERMINATE_FAILED", static_cast<int>(TOBII_RESEARCH_STATUS_TERMINATE_FAILED), "Failed to terminate the API"};
            case TOBII_RESEARCH_STATUS_LOCALBROWSER_CREATE_FAILED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_LOCALBROWSER_CREATE_FAILED", static_cast<int>(TOBII_RESEARCH_STATUS_LOCALBROWSER_CREATE_FAILED), "Failed to create browser for finding local devices"};
            case TOBII_RESEARCH_STATUS_LOCALBROWSER_POLL_FAILED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_LOCALBROWSER_POLL_FAILED", static_cast<int>(TOBII_RESEARCH_STATUS_LOCALBROWSER_POLL_FAILED), "Failed to poll local devices"};
            case TOBII_RESEARCH_STATUS_ZEROCONFBROWSER_CREATE_FAILED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_ZEROCONFBROWSER_CREATE_FAILED", static_cast<int>(TOBII_RESEARCH_STATUS_ZEROCONFBROWSER_CREATE_FAILED), "Failed to create zero configuration browser"};
            case TOBII_RESEARCH_STATUS_ZEROCONFBROWSER_POLL_FAILED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_ZEROCONFBROWSER_POLL_FAILED", static_cast<int>(TOBII_RESEARCH_STATUS_ZEROCONFBROWSER_POLL_FAILED), "Failed to poll devices from zero configuration browser"};
            case TOBII_RESEARCH_STATUS_FILEBROWSER_CREATE_FAILED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_FILEBROWSER_CREATE_FAILED", static_cast<int>(TOBII_RESEARCH_STATUS_FILEBROWSER_CREATE_FAILED), "Failed to create browser that looks for devices in file"};
            case TOBII_RESEARCH_STATUS_FILEBROWSER_POLL_FAILED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_FILEBROWSER_POLL_FAILED", static_cast<int>(TOBII_RESEARCH_STATUS_FILEBROWSER_POLL_FAILED), "Failed to poll devices from file browser"};
            case TOBII_RESEARCH_STATUS_INVALID_PARAMETER:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_INVALID_PARAMETER", static_cast<int>(TOBII_RESEARCH_STATUS_INVALID_PARAMETER), "An invalid parameter was given to the method"};
            case TOBII_RESEARCH_STATUS_INVALID_OPERATION:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_INVALID_OPERATION", static_cast<int>(TOBII_RESEARCH_STATUS_INVALID_OPERATION), "The operation was invalid"};
            case TOBII_RESEARCH_STATUS_UNINITIALIZED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_UNINITIALIZED", static_cast<int>(TOBII_RESEARCH_STATUS_UNINITIALIZED), "Internal core error code"};
            case TOBII_RESEARCH_STATUS_OUT_OF_BOUNDS:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_OUT_OF_BOUNDS", static_cast<int>(TOBII_RESEARCH_STATUS_OUT_OF_BOUNDS), "A parameter is out of bounds"};
            case TOBII_RESEARCH_STATUS_DISPLAY_AREA_NOT_VALID:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_DISPLAY_AREA_NOT_VALID", static_cast<int>(TOBII_RESEARCH_STATUS_DISPLAY_AREA_NOT_VALID), "The display area is not valid"};
            case TOBII_RESEARCH_STATUS_BUFFER_TOO_SMALL:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_BUFFER_TOO_SMALL", static_cast<int>(TOBII_RESEARCH_STATUS_BUFFER_TOO_SMALL), "The buffer is too small"};
            case TOBII_RESEARCH_STATUS_NOT_INITIALIZED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_NOT_INITIALIZED", static_cast<int>(TOBII_RESEARCH_STATUS_NOT_INITIALIZED), "tobii_research_initialize has not been called"};
            case TOBII_RESEARCH_STATUS_ALREADY_INITIALIZED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_ALREADY_INITIALIZED", static_cast<int>(TOBII_RESEARCH_STATUS_ALREADY_INITIALIZED), "tobii_research_initialize has already been called"};
            case TOBII_RESEARCH_STATUS_SAVED_LICENSE_FAILED_TO_APPLY:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_SAVED_LICENSE_FAILED_TO_APPLY", static_cast<int>(TOBII_RESEARCH_STATUS_SAVED_LICENSE_FAILED_TO_APPLY), "The license saved on the device failed to apply when connecting"};
            case TOBII_RESEARCH_STATUS_SE_INTERNAL:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_SE_INTERNAL", static_cast<int>(TOBII_RESEARCH_STATUS_SE_INTERNAL), "Internal stream engine error"};
            case TOBII_RESEARCH_STATUS_SE_INSUFFICIENT_LICENSE:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_SE_INSUFFICIENT_LICENSE", static_cast<int>(TOBII_RESEARCH_STATUS_SE_INSUFFICIENT_LICENSE), "The operation requires a higher license type"};
            case TOBII_RESEARCH_STATUS_SE_NOT_SUPPORTED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_SE_NOT_SUPPORTED", static_cast<int>(TOBII_RESEARCH_STATUS_SE_NOT_SUPPORTED), "The operations isn"};
            case TOBII_RESEARCH_STATUS_SE_NOT_AVAILABLE:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_SE_NOT_AVAILABLE", static_cast<int>(TOBII_RESEARCH_STATUS_SE_NOT_AVAILABLE), "The device is unavailable"};
            case TOBII_RESEARCH_STATUS_SE_CONNECTION_FAILED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_SE_CONNECTION_FAILED", static_cast<int>(TOBII_RESEARCH_STATUS_SE_CONNECTION_FAILED), "Connection to the device failed"};
            case TOBII_RESEARCH_STATUS_SE_TIMED_OUT:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_SE_TIMED_OUT", static_cast<int>(TOBII_RESEARCH_STATUS_SE_TIMED_OUT), "The operation timed out"};
            case TOBII_RESEARCH_STATUS_SE_ALLOCATION_FAILED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_SE_ALLOCATION_FAILED", static_cast<int>(TOBII_RESEARCH_STATUS_SE_ALLOCATION_FAILED), "Failed to allocate memory"};
            case TOBII_RESEARCH_STATUS_SE_ALREADY_INITIALIZED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_SE_ALREADY_INITIALIZED", static_cast<int>(TOBII_RESEARCH_STATUS_SE_ALREADY_INITIALIZED), "The API is already initialized"};
            case TOBII_RESEARCH_STATUS_SE_NOT_INITIALIZED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_SE_NOT_INITIALIZED", static_cast<int>(TOBII_RESEARCH_STATUS_SE_NOT_INITIALIZED), "The API isn"};
            case TOBII_RESEARCH_STATUS_SE_INVALID_PARAMETER:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_SE_INVALID_PARAMETER", static_cast<int>(TOBII_RESEARCH_STATUS_SE_INVALID_PARAMETER), "An invalid parameter was given to the method"};
            case TOBII_RESEARCH_STATUS_SE_CALIBRATION_ALREADY_STARTED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_SE_CALIBRATION_ALREADY_STARTED", static_cast<int>(TOBII_RESEARCH_STATUS_SE_CALIBRATION_ALREADY_STARTED), "Calibration has already started"};
            case TOBII_RESEARCH_STATUS_SE_CALIBRATION_NOT_STARTED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_SE_CALIBRATION_NOT_STARTED", static_cast<int>(TOBII_RESEARCH_STATUS_SE_CALIBRATION_NOT_STARTED), "Calibration isn"};
            case TOBII_RESEARCH_STATUS_SE_ALREADY_SUBSCRIBED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_SE_ALREADY_SUBSCRIBED", static_cast<int>(TOBII_RESEARCH_STATUS_SE_ALREADY_SUBSCRIBED), "Already subscribed"};
            case TOBII_RESEARCH_STATUS_SE_NOT_SUBSCRIBED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_SE_NOT_SUBSCRIBED", static_cast<int>(TOBII_RESEARCH_STATUS_SE_NOT_SUBSCRIBED), "Not subscribed"};
            case TOBII_RESEARCH_STATUS_SE_OPERATION_FAILED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_SE_OPERATION_FAILED", static_cast<int>(TOBII_RESEARCH_STATUS_SE_OPERATION_FAILED), "Operation failed"};
            case TOBII_RESEARCH_STATUS_SE_CONFLICTING_API_INSTANCES:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_SE_CONFLICTING_API_INSTANCES", static_cast<int>(TOBII_RESEARCH_STATUS_SE_CONFLICTING_API_INSTANCES), "Conflicting api instances"};
            case TOBII_RESEARCH_STATUS_SE_CALIBRATION_BUSY:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_SE_CALIBRATION_BUSY", static_cast<int>(TOBII_RESEARCH_STATUS_SE_CALIBRATION_BUSY), "Calibration busy"};
            case TOBII_RESEARCH_STATUS_SE_CALLBACK_IN_PROGRESS:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_SE_CALLBACK_IN_PROGRESS", static_cast<int>(TOBII_RESEARCH_STATUS_SE_CALLBACK_IN_PROGRESS), "Callback in progress"};
            case TOBII_RESEARCH_STATUS_SE_TOO_MANY_SUBSCRIBERS:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_SE_TOO_MANY_SUBSCRIBERS", static_cast<int>(TOBII_RESEARCH_STATUS_SE_TOO_MANY_SUBSCRIBERS), "Too many users subscribed to a stream"};
            case TOBII_RESEARCH_STATUS_SE_BUFFER_TOO_SMALL:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_SE_BUFFER_TOO_SMALL", static_cast<int>(TOBII_RESEARCH_STATUS_SE_BUFFER_TOO_SMALL), "The buffer is too small"};
            case TOBII_RESEARCH_STATUS_SE_FIRMWARE_NO_RESPONSE:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_SE_FIRMWARE_NO_RESPONSE", static_cast<int>(TOBII_RESEARCH_STATUS_SE_FIRMWARE_NO_RESPONSE), "No response from firmware"};
            case TOBII_RESEARCH_STATUS_FWUPGRADE_INTERNAL:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_FWUPGRADE_INTERNAL", static_cast<int>(TOBII_RESEARCH_STATUS_FWUPGRADE_INTERNAL), "Internal error"};
            case TOBII_RESEARCH_STATUS_FWUPGRADE_NOT_SUPPORTED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_FWUPGRADE_NOT_SUPPORTED", static_cast<int>(TOBII_RESEARCH_STATUS_FWUPGRADE_NOT_SUPPORTED), "Firmware upgrade is not supported"};
            case TOBII_RESEARCH_STATUS_FWUPGRADE_UNKNOWN_FIRMWARE_VERSION:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_FWUPGRADE_UNKNOWN_FIRMWARE_VERSION", static_cast<int>(TOBII_RESEARCH_STATUS_FWUPGRADE_UNKNOWN_FIRMWARE_VERSION), "Unknown firmware version"};
            case TOBII_RESEARCH_STATUS_FWUPGRADE_CONNECTION_FAILED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_FWUPGRADE_CONNECTION_FAILED", static_cast<int>(TOBII_RESEARCH_STATUS_FWUPGRADE_CONNECTION_FAILED), "Connection failed"};
            case TOBII_RESEARCH_STATUS_FWUPGRADE_INVALID_PARAMETER:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_FWUPGRADE_INVALID_PARAMETER", static_cast<int>(TOBII_RESEARCH_STATUS_FWUPGRADE_INVALID_PARAMETER), "Invalid parameter"};
            case TOBII_RESEARCH_STATUS_FWUPGRADE_PACKAGE_DEVICE_MISMATCH:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_FWUPGRADE_PACKAGE_DEVICE_MISMATCH", static_cast<int>(TOBII_RESEARCH_STATUS_FWUPGRADE_PACKAGE_DEVICE_MISMATCH), "Device mismatch"};
            case TOBII_RESEARCH_STATUS_FWUPGRADE_PARSE_RESPONSE:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_FWUPGRADE_PARSE_RESPONSE", static_cast<int>(TOBII_RESEARCH_STATUS_FWUPGRADE_PARSE_RESPONSE), "Parse response"};
            case TOBII_RESEARCH_STATUS_FWUPGRADE_OPERATION_FAILED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_FWUPGRADE_OPERATION_FAILED", static_cast<int>(TOBII_RESEARCH_STATUS_FWUPGRADE_OPERATION_FAILED), "The firmware upgrade operation failed"};
            case TOBII_RESEARCH_STATUS_FWUPGRADE_ALLOCATION_FAILED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_FWUPGRADE_ALLOCATION_FAILED", static_cast<int>(TOBII_RESEARCH_STATUS_FWUPGRADE_ALLOCATION_FAILED), "Memory allocation failed during firmware upgrade"};
            case TOBII_RESEARCH_STATUS_FWUPGRADE_FIRMWARE_NO_RESPONSE:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_FWUPGRADE_FIRMWARE_NO_RESPONSE", static_cast<int>(TOBII_RESEARCH_STATUS_FWUPGRADE_FIRMWARE_NO_RESPONSE), "The firmware failed to respond during firmware upgrade"};
            case TOBII_RESEARCH_STATUS_FWUPGRADE_DOWNGRADE_NOT_SUPPORTED:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_FWUPGRADE_DOWNGRADE_NOT_SUPPORTED", static_cast<int>(TOBII_RESEARCH_STATUS_FWUPGRADE_DOWNGRADE_NOT_SUPPORTED), "The firmware downgrade operation is not supported"};
            case TOBII_RESEARCH_STATUS_UNKNOWN:
                return TobiiResearchStatusInfo{"TOBII_RESEARCH_STATUS_UNKNOWN", static_cast<int>(TOBII_RESEARCH_STATUS_UNKNOWN), "Unknown error"};
            default:
            {
                std::stringstream os;
                os << "Titta::cpp::lookupTobiiResearchStatus: code " << in_ << " unknown";
                DoExitWithMsg(os.str());
                return TobiiResearchStatusInfo{"", static_cast<int>(-999), ""};  // to shut up compiler warnings
            }
        }
    }

    struct TobiiResearchLogSourceInfo
    {
        const char* _cName;     /* Name of Constant */
        int			_uVal;      /* Constant's value as int */
        const char* _cErrorTxt; /* Explanatory text for error */
    };

    TobiiResearchLogSourceInfo lookupTobiiResearchLogSource(TobiiResearchLogSource in_)
    {
        switch (in_)
        {
            // the below is code generated by the matlab script tools/TobiiResearchEnumLister.m
            case TOBII_RESEARCH_LOG_SOURCE_STREAM_ENGINE:
                return TobiiResearchLogSourceInfo{"TOBII_RESEARCH_LOG_SOURCE_STREAM_ENGINE", static_cast<int>(TOBII_RESEARCH_LOG_SOURCE_STREAM_ENGINE), "The log message is from stream engine"};
            case TOBII_RESEARCH_LOG_SOURCE_SDK:
                return TobiiResearchLogSourceInfo{"TOBII_RESEARCH_LOG_SOURCE_SDK", static_cast<int>(TOBII_RESEARCH_LOG_SOURCE_SDK), "The log message is from the SDK"};
            case TOBII_RESEARCH_LOG_SOURCE_FIRMWARE_UPGRADE:
                return TobiiResearchLogSourceInfo{"TOBII_RESEARCH_LOG_SOURCE_FIRMWARE_UPGRADE", static_cast<int>(TOBII_RESEARCH_LOG_SOURCE_FIRMWARE_UPGRADE), "The log message is from the firmware upgrade module"};
            default:
            {
                std::stringstream os;
                os << "Titta::cpp::lookupTobiiResearchLogSource: code " << in_ << " unknown";
                DoExitWithMsg(os.str());
                return TobiiResearchLogSourceInfo{"", static_cast<int>(-999), ""};  // to shut up compiler warnings
            }
        }
    }

    struct TobiiResearchLogLevelInfo
    {
        const char* _cName;     /* Name of Constant */
        int			_uVal;      /* Constant's value as int */
        const char* _cErrorTxt; /* Explanatory text for error */
    };

    TobiiResearchLogLevelInfo lookupTobiiResearchLogLevel(TobiiResearchLogLevel in_)
    {
        switch (in_)
        {
            // the below is code generated by the matlab script tools/TobiiResearchEnumLister.m
            case TOBII_RESEARCH_LOG_LEVEL_ERROR:
                return TobiiResearchLogLevelInfo{"TOBII_RESEARCH_LOG_LEVEL_ERROR", static_cast<int>(TOBII_RESEARCH_LOG_LEVEL_ERROR), "Error message"};
            case TOBII_RESEARCH_LOG_LEVEL_WARNING:
                return TobiiResearchLogLevelInfo{"TOBII_RESEARCH_LOG_LEVEL_WARNING", static_cast<int>(TOBII_RESEARCH_LOG_LEVEL_WARNING), "Warning message"};
            case TOBII_RESEARCH_LOG_LEVEL_INFORMATION:
                return TobiiResearchLogLevelInfo{"TOBII_RESEARCH_LOG_LEVEL_INFORMATION", static_cast<int>(TOBII_RESEARCH_LOG_LEVEL_INFORMATION), "Information message"};
            case TOBII_RESEARCH_LOG_LEVEL_DEBUG:
                return TobiiResearchLogLevelInfo{"TOBII_RESEARCH_LOG_LEVEL_DEBUG", static_cast<int>(TOBII_RESEARCH_LOG_LEVEL_DEBUG), "Debug message"};
            case TOBII_RESEARCH_LOG_LEVEL_TRACE:
                return TobiiResearchLogLevelInfo{"TOBII_RESEARCH_LOG_LEVEL_TRACE", static_cast<int>(TOBII_RESEARCH_LOG_LEVEL_TRACE), "Trace message"};
            default:
            {
                std::stringstream os;
                os << "Titta::cpp::lookupTobiiResearchLogLevel: code " << in_ << " unknown";
                DoExitWithMsg(os.str());
                return TobiiResearchLogLevelInfo{"", static_cast<int>(-999), ""};  // to shut up compiler warnings
            }
        }
    }

    struct TobiiResearchStreamErrorInfo
    {
        const char* _cName;     /* Name of Constant */
        int			_uVal;      /* Constant's value as int */
        const char* _cErrorTxt; /* Explanatory text for error */
    };

    TobiiResearchStreamErrorInfo lookupTobiiResearchStreamError(TobiiResearchStreamError in_)
    {
        switch (in_)
        {
            // the below is code generated by the matlab script tools/TobiiResearchEnumLister.m
            case TOBII_RESEARCH_STREAM_ERROR_CONNECTION_LOST:
                return TobiiResearchStreamErrorInfo{"TOBII_RESEARCH_STREAM_ERROR_CONNECTION_LOST", static_cast<int>(TOBII_RESEARCH_STREAM_ERROR_CONNECTION_LOST), "Indicates that the connection to the eye tracker was lost"};
            case TOBII_RESEARCH_STREAM_ERROR_INSUFFICIENT_LICENSE:
                return TobiiResearchStreamErrorInfo{"TOBII_RESEARCH_STREAM_ERROR_INSUFFICIENT_LICENSE", static_cast<int>(TOBII_RESEARCH_STREAM_ERROR_INSUFFICIENT_LICENSE), "Indicates that the license is insufficient for subscribing to the stream"};
            case TOBII_RESEARCH_STREAM_ERROR_NOT_SUPPORTED:
                return TobiiResearchStreamErrorInfo{"TOBII_RESEARCH_STREAM_ERROR_NOT_SUPPORTED", static_cast<int>(TOBII_RESEARCH_STREAM_ERROR_NOT_SUPPORTED), "Indicates that the stream isn"};
            case TOBII_RESEARCH_STREAM_ERROR_TOO_MANY_SUBSCRIBERS:
                return TobiiResearchStreamErrorInfo{"TOBII_RESEARCH_STREAM_ERROR_TOO_MANY_SUBSCRIBERS", static_cast<int>(TOBII_RESEARCH_STREAM_ERROR_TOO_MANY_SUBSCRIBERS), "Indicates that number of subscriptions to the stream has reached its limit"};
            case TOBII_RESEARCH_STREAM_ERROR_INTERNAL_ERROR:
                return TobiiResearchStreamErrorInfo{"TOBII_RESEARCH_STREAM_ERROR_INTERNAL_ERROR", static_cast<int>(TOBII_RESEARCH_STREAM_ERROR_INTERNAL_ERROR), "Indicates that an internal error occurred"};
            case TOBII_RESEARCH_STREAM_ERROR_USER_ERROR:
                return TobiiResearchStreamErrorInfo{"TOBII_RESEARCH_STREAM_ERROR_USER_ERROR", static_cast<int>(TOBII_RESEARCH_STREAM_ERROR_USER_ERROR), "Indicates that the user threw an exception in the callback"};
            default:
            {
                std::stringstream os;
                os << "Titta::cpp::lookupTobiiResearchStreamError: code " << in_ << " unknown";
                DoExitWithMsg(os.str());
                return TobiiResearchStreamErrorInfo{"", static_cast<int>(-999), ""};  // to shut up compiler warnings
            }
        }
    }

    struct TobiiResearchStreamErrorSourceInfo
    {
        const char* _cName;     /* Name of Constant */
        int			_uVal;      /* Constant's value as int */
        const char* _cErrorTxt; /* Explanatory text for error */
    };

    TobiiResearchStreamErrorSourceInfo lookupTobiiResearchStreamErrorSource(TobiiResearchStreamErrorSource in_)
    {
        switch (in_)
        {
            // the below is code generated by the matlab script tools/TobiiResearchEnumLister.m
            case TOBII_RESEARCH_STREAM_ERROR_SOURCE_USER:
                return TobiiResearchStreamErrorSourceInfo{"TOBII_RESEARCH_STREAM_ERROR_SOURCE_USER", static_cast<int>(TOBII_RESEARCH_STREAM_ERROR_SOURCE_USER), "User callback failed"};
            case TOBII_RESEARCH_STREAM_ERROR_SOURCE_STREAM_PUMP:
                return TobiiResearchStreamErrorSourceInfo{"TOBII_RESEARCH_STREAM_ERROR_SOURCE_STREAM_PUMP", static_cast<int>(TOBII_RESEARCH_STREAM_ERROR_SOURCE_STREAM_PUMP), "Error when pumping event"};
            case TOBII_RESEARCH_STREAM_ERROR_SOURCE_SUBSCRIPTION_GAZE_DATA:
                return TobiiResearchStreamErrorSourceInfo{"TOBII_RESEARCH_STREAM_ERROR_SOURCE_SUBSCRIPTION_GAZE_DATA", static_cast<int>(TOBII_RESEARCH_STREAM_ERROR_SOURCE_SUBSCRIPTION_GAZE_DATA), "Error when subscribing to event for gaze data"};
            case TOBII_RESEARCH_STREAM_ERROR_SOURCE_SUBSCRIPTION_EXTERNAL_SIGNAL:
                return TobiiResearchStreamErrorSourceInfo{"TOBII_RESEARCH_STREAM_ERROR_SOURCE_SUBSCRIPTION_EXTERNAL_SIGNAL", static_cast<int>(TOBII_RESEARCH_STREAM_ERROR_SOURCE_SUBSCRIPTION_EXTERNAL_SIGNAL), "Error when subscribing to event for external signal"};
            case TOBII_RESEARCH_STREAM_ERROR_SOURCE_SUBSCRIPTION_TIME_SYNCHRONIZATION_DATA:
                return TobiiResearchStreamErrorSourceInfo{"TOBII_RESEARCH_STREAM_ERROR_SOURCE_SUBSCRIPTION_TIME_SYNCHRONIZATION_DATA", static_cast<int>(TOBII_RESEARCH_STREAM_ERROR_SOURCE_SUBSCRIPTION_TIME_SYNCHRONIZATION_DATA), "Error when subscribing to event for time synchronization data"};
            case TOBII_RESEARCH_STREAM_ERROR_SOURCE_SUBSCRIPTION_EYE_IMAGE:
                return TobiiResearchStreamErrorSourceInfo{"TOBII_RESEARCH_STREAM_ERROR_SOURCE_SUBSCRIPTION_EYE_IMAGE", static_cast<int>(TOBII_RESEARCH_STREAM_ERROR_SOURCE_SUBSCRIPTION_EYE_IMAGE), "Error when subscribing to event for eye images"};
            case TOBII_RESEARCH_STREAM_ERROR_SOURCE_SUBSCRIPTION_NOTIFICATION:
                return TobiiResearchStreamErrorSourceInfo{"TOBII_RESEARCH_STREAM_ERROR_SOURCE_SUBSCRIPTION_NOTIFICATION", static_cast<int>(TOBII_RESEARCH_STREAM_ERROR_SOURCE_SUBSCRIPTION_NOTIFICATION), "Error when subscribing to notification event"};
            case TOBII_RESEARCH_STREAM_ERROR_SOURCE_SUBSCRIPTION_HMD_GAZE_DATA:
                return TobiiResearchStreamErrorSourceInfo{"TOBII_RESEARCH_STREAM_ERROR_SOURCE_SUBSCRIPTION_HMD_GAZE_DATA", static_cast<int>(TOBII_RESEARCH_STREAM_ERROR_SOURCE_SUBSCRIPTION_HMD_GAZE_DATA), "Error when subscribing to event for hmd gaze data"};
            case TOBII_RESEARCH_STREAM_ERROR_SOURCE_SUBSCRIPTION_USER_POSITION_GUIDE:
                return TobiiResearchStreamErrorSourceInfo{"TOBII_RESEARCH_STREAM_ERROR_SOURCE_SUBSCRIPTION_USER_POSITION_GUIDE", static_cast<int>(TOBII_RESEARCH_STREAM_ERROR_SOURCE_SUBSCRIPTION_USER_POSITION_GUIDE), "Error when subscribing to event for user position guide"};
            default:
            {
                std::stringstream os;
                os << "Titta::cpp::lookupTobiiResearchStreamErrorSourceInfo: code " << in_ << " unknown";
                DoExitWithMsg(os.str());
                return TobiiResearchStreamErrorSourceInfo{"", static_cast<int>(-999), ""};  // to shut up compiler warnings
            }
        }
    }

    struct TobiiResearchNotificationTypeInfo
    {
        const char* _cName;     /* Name of Constant */
        int			_uVal;      /* Constant's value as int */
        const char* _cErrorTxt; /* Explanatory text for error */
    };

    TobiiResearchNotificationTypeInfo lookupTobiiResearchNotificationType(TobiiResearchNotificationType in_)
    {
        switch (in_)
        {
            // the below is code generated by the matlab script tools/TobiiResearchEnumLister.m
        case TOBII_RESEARCH_NOTIFICATION_CONNECTION_LOST:
            return TobiiResearchNotificationTypeInfo{ "TOBII_RESEARCH_NOTIFICATION_CONNECTION_LOST", static_cast<int>(TOBII_RESEARCH_NOTIFICATION_CONNECTION_LOST), "Indicates that the connection to the eye tracker is lost" };
        case TOBII_RESEARCH_NOTIFICATION_CONNECTION_RESTORED:
            return TobiiResearchNotificationTypeInfo{ "TOBII_RESEARCH_NOTIFICATION_CONNECTION_RESTORED", static_cast<int>(TOBII_RESEARCH_NOTIFICATION_CONNECTION_RESTORED), "Indicates that the connection to the eye tracker is restored" };
        case TOBII_RESEARCH_NOTIFICATION_CALIBRATION_MODE_ENTERED:
            return TobiiResearchNotificationTypeInfo{ "TOBII_RESEARCH_NOTIFICATION_CALIBRATION_MODE_ENTERED", static_cast<int>(TOBII_RESEARCH_NOTIFICATION_CALIBRATION_MODE_ENTERED), "Indicates that the calibration mode is entered" };
        case TOBII_RESEARCH_NOTIFICATION_CALIBRATION_MODE_LEFT:
            return TobiiResearchNotificationTypeInfo{ "TOBII_RESEARCH_NOTIFICATION_CALIBRATION_MODE_LEFT", static_cast<int>(TOBII_RESEARCH_NOTIFICATION_CALIBRATION_MODE_LEFT), "Indicates that the calibration mode is left" };
        case TOBII_RESEARCH_NOTIFICATION_CALIBRATION_CHANGED:
            return TobiiResearchNotificationTypeInfo{ "TOBII_RESEARCH_NOTIFICATION_CALIBRATION_CHANGED", static_cast<int>(TOBII_RESEARCH_NOTIFICATION_CALIBRATION_CHANGED), "Indicates that the calibration is changed" };
        case TOBII_RESEARCH_NOTIFICATION_TRACK_BOX_CHANGED:
            return TobiiResearchNotificationTypeInfo{ "TOBII_RESEARCH_NOTIFICATION_TRACK_BOX_CHANGED", static_cast<int>(TOBII_RESEARCH_NOTIFICATION_TRACK_BOX_CHANGED), "Indicates that the track box is changed" };
        case TOBII_RESEARCH_NOTIFICATION_DISPLAY_AREA_CHANGED:
            return TobiiResearchNotificationTypeInfo{ "TOBII_RESEARCH_NOTIFICATION_DISPLAY_AREA_CHANGED", static_cast<int>(TOBII_RESEARCH_NOTIFICATION_DISPLAY_AREA_CHANGED), "Indicates that the display area is changed" };
        case TOBII_RESEARCH_NOTIFICATION_GAZE_OUTPUT_FREQUENCY_CHANGED:
            return TobiiResearchNotificationTypeInfo{ "TOBII_RESEARCH_NOTIFICATION_GAZE_OUTPUT_FREQUENCY_CHANGED", static_cast<int>(TOBII_RESEARCH_NOTIFICATION_GAZE_OUTPUT_FREQUENCY_CHANGED), "Indicates that the gaze output frequency is changed" };
        case TOBII_RESEARCH_NOTIFICATION_EYE_TRACKING_MODE_CHANGED:
            return TobiiResearchNotificationTypeInfo{ "TOBII_RESEARCH_NOTIFICATION_EYE_TRACKING_MODE_CHANGED", static_cast<int>(TOBII_RESEARCH_NOTIFICATION_EYE_TRACKING_MODE_CHANGED), "Indicates that the eye tracking mode is changed" };
        case TOBII_RESEARCH_NOTIFICATION_DEVICE_FAULTS:
            return TobiiResearchNotificationTypeInfo{ "TOBII_RESEARCH_NOTIFICATION_DEVICE_FAULTS", static_cast<int>(TOBII_RESEARCH_NOTIFICATION_DEVICE_FAULTS), "Indicates that the device has reported new faults" };
        case TOBII_RESEARCH_NOTIFICATION_DEVICE_WARNINGS:
            return TobiiResearchNotificationTypeInfo{ "TOBII_RESEARCH_NOTIFICATION_DEVICE_WARNINGS", static_cast<int>(TOBII_RESEARCH_NOTIFICATION_DEVICE_WARNINGS), "Indicates that the device has reported new warnings" };
        case TOBII_RESEARCH_NOTIFICATION_UNKNOWN:
            return TobiiResearchNotificationTypeInfo{ "TOBII_RESEARCH_NOTIFICATION_UNKNOWN", static_cast<int>(TOBII_RESEARCH_NOTIFICATION_UNKNOWN), " " };
        default:
        {
            std::stringstream os;
            os << "Titta::cpp::lookupTobiiResearchNotificationType: code " << in_ << " unknown";
            DoExitWithMsg(os.str());
            return TobiiResearchNotificationTypeInfo{ "", static_cast<int>(-999), "" };  // to shut up compiler warnings
        }
        }
    }

    struct TobiiResearchEyeImageTypeInfo
    {
        const char* _cName;     /* Name of Constant */
        int			_uVal;      /* Constant's value as int */
        const char* _cErrorTxt; /* Explanatory text for error */
    };

    TobiiResearchEyeImageTypeInfo lookupTobiiResearchEyeImage(TobiiResearchEyeImageType in_)
    {
        switch (in_)
        {
            // the below is code generated by the matlab script tools/TobiiResearchEnumLister.m
        case TOBII_RESEARCH_EYE_IMAGE_TYPE_FULL:
            return TobiiResearchEyeImageTypeInfo{ "TOBII_RESEARCH_EYE_IMAGE_TYPE_FULL", static_cast<int>(TOBII_RESEARCH_EYE_IMAGE_TYPE_FULL), "Indicates that the eye tracker could not identify the eyes" };
        case TOBII_RESEARCH_EYE_IMAGE_TYPE_CROPPED:
            return TobiiResearchEyeImageTypeInfo{ "TOBII_RESEARCH_EYE_IMAGE_TYPE_CROPPED", static_cast<int>(TOBII_RESEARCH_EYE_IMAGE_TYPE_CROPPED), "Indicates that the image is cropped and shows the eyes" };
        case TOBII_RESEARCH_EYE_IMAGE_TYPE_MULTI_ROI:
            return TobiiResearchEyeImageTypeInfo{ "TOBII_RESEARCH_EYE_IMAGE_TYPE_MULTI_ROI", static_cast<int>(TOBII_RESEARCH_EYE_IMAGE_TYPE_MULTI_ROI), "The eye image is part of a group of regions of interest" };
        case TOBII_RESEARCH_EYE_IMAGE_TYPE_UNKNOWN:
            return TobiiResearchEyeImageTypeInfo{ "TOBII_RESEARCH_EYE_IMAGE_TYPE_UNKNOWN", static_cast<int>(TOBII_RESEARCH_EYE_IMAGE_TYPE_UNKNOWN), "The eye image has an unexpected type" };
        default:
        {
            std::stringstream os;
            os << "Titta::cpp::lookupTobiiResearchEyeImage: code " << in_ << " unknown";
            DoExitWithMsg(os.str());
            return TobiiResearchEyeImageTypeInfo{ "", static_cast<int>(-999), "" };  // to shut up compiler warnings
        }
        }
    }

    struct TobiiResearchLicenseValidationResultInfo
    {
        const char* _cName;     /* Name of Constant */
        int			_uVal;      /* Constant's value as int */
        const char* _cErrorTxt; /* Explanatory text for error */
    };

    TobiiResearchLicenseValidationResultInfo lookupTobiiResearchLicenseValidationResult(TobiiResearchLicenseValidationResult in_)
    {
        switch (in_)
        {
            // the below is code generated by the matlab script tools/TobiiResearchEnumLister.m
            case TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_OK:
                return TobiiResearchLicenseValidationResultInfo{"TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_OK", static_cast<int>(TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_OK), "The license is ok"};
            case TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_TAMPERED:
                return TobiiResearchLicenseValidationResultInfo{"TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_TAMPERED", static_cast<int>(TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_TAMPERED), "The license is tampered"};
            case TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_INVALID_APPLICATION_SIGNATURE:
                return TobiiResearchLicenseValidationResultInfo{"TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_INVALID_APPLICATION_SIGNATURE", static_cast<int>(TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_INVALID_APPLICATION_SIGNATURE), "The application signature is invalid"};
            case TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_NONSIGNED_APPLICATION:
                return TobiiResearchLicenseValidationResultInfo{"TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_NONSIGNED_APPLICATION", static_cast<int>(TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_NONSIGNED_APPLICATION), "The application has not been signed"};
            case TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_EXPIRED:
                return TobiiResearchLicenseValidationResultInfo{"TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_EXPIRED", static_cast<int>(TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_EXPIRED), "The license has expired"};
            case TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_PREMATURE:
                return TobiiResearchLicenseValidationResultInfo{"TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_PREMATURE", static_cast<int>(TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_PREMATURE), "The license is not yet valid"};
            case TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_INVALID_PROCESS_NAME:
                return TobiiResearchLicenseValidationResultInfo{"TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_INVALID_PROCESS_NAME", static_cast<int>(TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_INVALID_PROCESS_NAME), "The process name does not match the license"};
            case TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_INVALID_SERIAL_NUMBER:
                return TobiiResearchLicenseValidationResultInfo{"TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_INVALID_SERIAL_NUMBER", static_cast<int>(TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_INVALID_SERIAL_NUMBER), "The serial number does not match the license"};
            case TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_INVALID_MODEL:
                return TobiiResearchLicenseValidationResultInfo{"TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_INVALID_MODEL", static_cast<int>(TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_INVALID_MODEL), "The model does not match the license"};
            case TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_UNKNOWN:
                return TobiiResearchLicenseValidationResultInfo{"TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_UNKNOWN", static_cast<int>(TOBII_RESEARCH_LICENSE_VALIDATION_RESULT_UNKNOWN), "The license validation returned an unexpected result"};
            default:
            {
                std::stringstream os;
                os << "Titta::cpp::TobiiResearchLicenseValidationResult: code " << in_ << " unknown";
                DoExitWithMsg(os.str());
                return TobiiResearchLicenseValidationResultInfo{ "", static_cast<int>(-999), "" };  // to shut up compiler warnings
            }
        }
    }
}

std::string TobiiResearchStatusToString(TobiiResearchStatus in_)
{
    return lookupTobiiResearchStatus(in_)._cName;
}

std::string TobiiResearchStatusToExplanation(TobiiResearchStatus in_)
{
    return lookupTobiiResearchStatus(in_)._cErrorTxt;
}

std::string TobiiResearchLogSourceToString(TobiiResearchLogSource in_)
{
    return lookupTobiiResearchLogSource(in_)._cName;
}

std::string TobiiResearchLogSourceToExplanation(TobiiResearchLogSource in_)
{
    return lookupTobiiResearchLogSource(in_)._cErrorTxt;
}

std::string TobiiResearchLogLevelToString(TobiiResearchLogLevel in_)
{
    return lookupTobiiResearchLogLevel(in_)._cName;
}

std::string TobiiResearchLogLevelToExplanation(TobiiResearchLogLevel in_)
{
    return lookupTobiiResearchLogLevel(in_)._cErrorTxt;
}

std::string TobiiResearchStreamErrorToString(TobiiResearchStreamError in_)
{
    return lookupTobiiResearchStreamError(in_)._cName;
}

std::string TobiiResearchStreamErrorToExplanation(TobiiResearchStreamError in_)
{
    return lookupTobiiResearchStreamError(in_)._cErrorTxt;
}

std::string TobiiResearchStreamErrorSourceToString(TobiiResearchStreamErrorSource in_)
{
    return lookupTobiiResearchStreamErrorSource(in_)._cName;
}

std::string TobiiResearchStreamErrorSourceToExplanation(TobiiResearchStreamErrorSource in_)
{
    return lookupTobiiResearchStreamErrorSource(in_)._cErrorTxt;
}

std::string TobiiResearchNotificationToString(TobiiResearchNotificationType in_)
{
    return lookupTobiiResearchNotificationType(in_)._cName;
}

std::string TobiiResearchNotificationToExplanation(TobiiResearchNotificationType in_)
{
    return lookupTobiiResearchNotificationType(in_)._cErrorTxt;
}

std::string TobiiResearchEyeImageToString(TobiiResearchEyeImageType in_)
{
    return lookupTobiiResearchEyeImage(in_)._cName;
}

std::string TobiiResearchEyeImageToExplanation(TobiiResearchEyeImageType in_)
{
    return lookupTobiiResearchEyeImage(in_)._cErrorTxt;
}

std::string TobiiResearchLicenseValidationResultToString(TobiiResearchLicenseValidationResult in_)
{
    return lookupTobiiResearchLicenseValidationResult(in_)._cName;
}

std::string TobiiResearchLicenseValidationResultToExplanation(TobiiResearchLicenseValidationResult in_)
{
    return lookupTobiiResearchLicenseValidationResult(in_)._cErrorTxt;
}

// deal with error messages
[[ noreturn ]] void ErrorExit(std::string_view errMsg_, TobiiResearchStatus errCode_)
{
    std::stringstream os;
    os << "Titta::cpp Error: " << errMsg_ << std::endl;
    os << "Error code: " << static_cast<int>(errCode_) << ": " << TobiiResearchStatusToString(errCode_) << " (" << TobiiResearchStatusToExplanation(errCode_) << ")" << std::endl;

    DoExitWithMsg(os.str());
}