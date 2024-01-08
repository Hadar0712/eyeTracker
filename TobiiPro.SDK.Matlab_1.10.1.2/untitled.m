addpath(genpath('path'))
Screen('Preference', 'SkipSyncTests', 0);

tobii = EyeTrackingOperations();
found_eyetrackers = tobii.find_all_eyetrackers();
my_eyetracker = found_eyetrackers(1);

disp(["Address: ", my_eyetracker.Address])
disp(["Model: ", my_eyetracker.Model])
disp(["Name (It's OK if this is empty): ", my_eyetracker.Name])
disp(["Serial number: ", my_eyetracker.SerialNumber])


version = Tobii.get_sdk_version();

disp(['Current SDK Version: ',version])


my_eyetracker.get_gaze_data();
pause(1)
gaze_data = my_eyetracker.get_gaze_data();
latest_gaze_data = gaze_data(end);

fprintf('SystemRequestTimeStamp: %d\n',latest_gaze_data.SystemTimeStamp);
fprintf('DeviceTimeStamp: %d\n',latest_gaze_data.DeviceTimeStamp);

disp('Left Eye');

fprintf('GazePoint.OnDisplayArea: %.2f %.2f\n',latest_gaze_data.LeftEye.GazePoint.OnDisplayArea);
fprintf('GazePoint.InUserCoordinateSystem: %.2f %.2f %.2f\n',latest_gaze_data.LeftEye.GazePoint.InUserCoordinateSystem);
%fprintf('GazePoint.Validity: %s\n',latest_gaze_data.LeftEye.GazePoint.Validity);

fprintf('GazeOrigin.InUserCoordinateSystem: %.2f %.2f %.2f\n',latest_gaze_data.LeftEye.GazeOrigin.InUserCoordinateSystem);
fprintf('GazeOrigin.InTrackBoxCoordinateSystem: %.2f %.2f %.2f\n',latest_gaze_data.LeftEye.GazeOrigin.InTrackBoxCoordinateSystem);
%fprintf('GazeOrigin.Validity: %s\n',char(latest_gaze_data.LeftEye.GazeOrigin.Validity));

fprintf('Pupil.Diameter: %.2f\n',latest_gaze_data.LeftEye.Pupil.Diameter);
%fprintf('Pupil.Validity: %s\n',char(latest_gaze_data.LeftEye.Pupil.Validity));

disp('Right Eye');

fprintf('GazePoint.OnDisplayArea: %.2f %.2f\n',latest_gaze_data.RightEye.GazePoint.OnDisplayArea);
fprintf('GazePoint.InUserCoordinateSystem: %.2f %.2f %.2f\n',latest_gaze_data.RightEye.GazePoint.InUserCoordinateSystem);
%fprintf('GazePoint.Validity: %s\n',char(latest_gaze_data.RightEye.GazePoint.Validity));

fprintf('GazeOrigin.InUserCoordinateSystem: %.2f %.2f %.2f\n',latest_gaze_data.RightEye.GazeOrigin.InUserCoordinateSystem);
fprintf('GazeOrigin.InTrackBoxCoordinateSystem: %.2f %.2f %.2f\n',latest_gaze_data.RightEye.GazeOrigin.InTrackBoxCoordinateSystem);
%fprintf('GazeOrigin.Validity: %s\n',char(latest_gaze_data.RightEye.GazeOrigin.Validity));

fprintf('Pupil.Diameter: %.2f\n',latest_gaze_data.RightEye.Pupil.Diameter);
%fprintf('Pupil.Validity: %s\n',char(latest_gaze_data.RightEye.Pupil.Validity));

my_eyetracker.stop_gaze_data()
