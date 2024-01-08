
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fid = fopen(['test', '.txt'] , 'a');
if fid == -1
  error('Cannot open log file.');
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
lib = lsl_loadlib();
% Resolve an available OpenSignals stream
disp('Looking for an available OpenSignals stream...');
streams = {};

while isempty(streams)
	streams = lsl_resolve_byprop(lib, 'name', 'OpenSignals');
end
disp('OpenSignals stream found...');

% Create an inlet to receive signal samples from the stream
inlet = lsl_inlet(streams{1});

[samples, ts] = inlet.pull_sample();

tobii = EyeTrackingOperations();
found_eyetrackers = tobii.find_all_eyetrackers();
my_eyetracker = found_eyetrackers(1);
disp(["Address: ", my_eyetracker.Address]);
disp(["Model: ", my_eyetracker.Model]);
disp(["Name (It's OK if this is empty): ", my_eyetracker.Name]);
disp(["Serial number: ", my_eyetracker.SerialNumber]);

my_eyetracker.get_gaze_data();
gaze_data = my_eyetracker.get_gaze_data();
latest_gaze_data = gaze_data(end);


% %%%%%%%%%Testing time stamps%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

fprintf(fid,'Testing the time stamp differance:\n');
fprintf(fid,'%s : 1st_SystemTimeStamp Tobii : %.0f\n',datestr(now, 0),latest_gaze_data.SystemTimeStamp);
fprintf(fid,'%s : BioSignals test 1 time    : %.7f\n',datestr(now, 0) ,ts);
my_eyetracker.stop_gaze_data();
my_eyetracker.get_gaze_data();
gaze_data = my_eyetracker.get_gaze_data();
latest_gaze_data = gaze_data(end);
[samples, ts1] = inlet.pull_sample();

fprintf(fid,'%s : 2nd_SystemTimeStamp Tobii : %.0f\n',datestr(now, 0),latest_gaze_data.SystemTimeStamp);
fprintf(fid,'%s : BioSignals test 2 time    : %.7f\n',datestr(now, 0), ts1);
my_eyetracker.stop_gaze_data();
my_eyetracker.get_gaze_data();
gaze_data = my_eyetracker.get_gaze_data();
latest_gaze_data = gaze_data(end);
[samples, ts2] = inlet.pull_sample();

fprintf(fid,'%s : 3ed_SystemTimeStamp Tobii : %.0f\n',datestr(now, 0),latest_gaze_data.SystemTimeStamp);
fprintf(fid,'%s : BioSignals test 3 time    : %.7f\n',datestr(now, 0), ts2);
fprintf(fid,'\n');
fprintf(fid,'\n');  

% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

my_eyetracker.stop_gaze_data();
fclose(fid);