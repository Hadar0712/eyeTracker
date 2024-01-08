function Tobi(Subject_name,domEye,randomized,run)
sca
format longG
num_of_movies = 6;
%coose how many movies you are playing

path='C:\Users\erezs\Videos\Movies';
%location of the movies

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Tobii = EyeTrackingOperations();

eyetracker_address = 'tet-tcp://169.254.6.41';

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  
try
    eyetracker = Tobii.get_eyetracker(eyetracker_address);
catch ME
    if (strcmp(ME.identifier,'EyeTrackerGet:error204'))
        fprintf('Unable to connect eye tracker.\n');
        return
    end
end

available_gaze_output_frequencies = eyetracker.get_all_gaze_output_frequencies();

gaze_output_frequency = available_gaze_output_frequencies(2); %frequencies options 600,300,150,120,60

eyetracker.set_gaze_output_frequency(gaze_output_frequency) %we choose 300

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fid = fopen([Subject_name, '.txt'] , 'a');
if fid == -1
  error('Cannot open log file.');
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%start of experiment
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fprintf(fid,'Time of experiment start : %s\n', datestr(now,'HH:MM:SS.FFF'));
fprintf(fid,'\n');
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Open signals code
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
% Get information about the stream
stream_info = inlet.info();
% Get individual stream attributes
stream_name = stream_info.name();
stream_mac = stream_info.type();
stream_n_channels = stream_info.channel_count();

% Store sensor channel info & units in a containers.map
stream_channels = containers.Map('KeyType', 'double', 'ValueType', 'any');
channels = stream_info.desc().child('channels').child('channel');
channel = 0;

% Loop through all available channels
for k = 1:(stream_n_channels - 1)
	% Get the channel number (e.g. 1)
	channel = k + 1;

	% Get the channel type (e.g. ECG)
	sensor = channels.child_value('sensor');

	% Get the channel unit (e.g. mV)
	unit = channels.child_value('unit');
    
	% Store the information in stream_channels
	stream_channels(channel) = [sensor, unit];
    channels = channels.next_sibling();
end
[samples, ts] = inlet.pull_sample();
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Apply user data
Saving_file=strcat(Subject_name,'_','run',num2str(run));

% Avoid Psychotoolbox synchronization test and warnings
% Screen('Preference', 'SkipSyncTests', 1);
% Screen('Preference', 'SuppressAllWarnings', 1);
% Screen('Preference', 'VisualDebuglevel', 3);

% set basic prefrences
bgClr = 127;
rectColor = 127;
fixClrs = [0 255];
useAnimatedCalibration = true;
scr = max(Screen('Screens')-1);
disp(scr)
DEBUGlevel = 0;
runInDummyMode = false;
doBimonocularCalibration= false;
dur = 8;  
fixTime = 1.2; 

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%for tests
% path ='C:\Users\erezs\OneDrive\Desktop\andrey_with_calibration';
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
rect1=[0,0,1920,1080];

% set up possible movies

if run==1
    current_movies=randomized(1:30);
elseif run==2
    current_movies=randomized(31:60);
elseif run==3
    current_movies=randomized(61:90);
elseif run==4
    current_movies=randomized(91:120);
elseif run==5
    current_movies=randomized(121:150);
elseif run==6
    current_movies=randomized(1:6); 
end
%number your movies 
possibleMoviesCell= compose('%d.mp4',current_movies);
until_calibration=20;
% until_calibration=4;

% You can run addTittaToPath once to "install" it, or you can simply add a
% call to it in your script so each time you want to use Titta, it is
% ensured it is on path
% home = cd;
% cd ..;
% addTittaToPath;
% cd(home);

try
    % get setup struct (can edit that of course):
    settings = Titta.getDefaults('Tobii Pro Spectrum');
    % request some debug output to command window, can skip for normal use
    settings.debugMode      = true;
    % customize colors of setup and calibration interface (colors of
    % everything can be set, so there is a lot here).
    % 1. setup screen
    settings.UI.setup.bgColor       = bgClr;
    settings.UI.setup.instruct.color= fixClrs(1);
    settings.UI.setup.fixBackColor  = fixClrs(1);
    settings.UI.setup.fixFrontColor = fixClrs(2);
    % 2. validation result screen
    settings.UI.val.bgColor                 = bgClr;
    settings.UI.val.avg.text.color          = fixClrs(1);
    settings.UI.val.fixBackColor            = fixClrs(1);
    settings.UI.val.fixFrontColor           = fixClrs(2);
    settings.UI.val.onlineGaze.fixBackColor = fixClrs(1);
    settings.UI.val.onlineGaze.fixFrontColor= fixClrs(2);
    % calibration display
    if useAnimatedCalibration
        % custom calibration drawer
        calViz                      = AnimatedCalibrationDisplay();
        settings.cal.drawFunction   = @calViz.doDraw;
        calViz.bgColor              = bgClr;
        calViz.fixBackColor         = fixClrs(1);
        calViz.fixFrontColor        = fixClrs(2);
    else
        % set color of built-in fixation points
        settings.cal.bgColor =          bgClr;
        settings.cal.fixBackColor   = fixClrs(1);
        settings.cal.fixFrontColor  = fixClrs(2);
    end
    % callback function for completion of each calibration point
    settings.cal.pointNotifyFunction = @demoCalCompletionFun;


EThndl = Titta(settings);
    
    if runInDummyMode
        EThndl = EThndl.setDummyMode();
    end
    
EThndl.init();

if DEBUGlevel>1
        % make screen partially transparent on OSX and windows vista or
        % higher, so we can debug.
        PsychDebugWindowConfiguration;
end
if DEBUGlevel
   % Be pretty verbose about information and hints to optimize your code and system.
    Screen('Preference', 'Verbosity', 4);
else
    % Only output critical errors and warnings.
    Screen('Preference', 'Verbosity', 2);
end

Screen('Preference', 'SyncTestSettings', 0.002);    % the systems are a little noisy, give the test a little more leeway
    

[wpnt,winRect] = PsychImaging('OpenWindow', scr, bgClr, [], [], [], [], 4);
hz=Screen('NominalFrameRate', wpnt);
Priority(1);
Screen('BlendFunction', wpnt, GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
Screen('Preference', 'TextAlphaBlending', 1);
Screen('Preference', 'TextAntiAliasing', 2);
    % This preference setting selects the high quality text renderer on
    % each operating system: It is not really needed, as the high quality
    % renderer is the default on all operating systems, so this is more of
    % a "better safe than sorry" setting.
Screen('Preference', 'TextRenderer', 1);
KbName('UnifyKeyNames');    % for correct operation of the setup/calibration interface, calling this is required

   % precompute target trajectory
    nFrame = hz*dur-2;
    every_point=floor(nFrame/9);
    a=[864 2016 486 1134];
    stim.t = linspace(0,dur,nFrame);
    stim.x(1:104)=a(1);
    stim.x(105:208)=a(2);
    stim.x(209:260)=1440;
    stim.x(261:312)=a(2);
    stim.x(313:404)=a(1);
    stim.x(405:nFrame)=a(2);
      
    stim.y(1:52)=a(3);
    stim.y(53:156)=a(4);
    stim.y(157:208)=a(3);
    stim.y(209:260)=810;
    stim.y(261:364)=a(3);
    stim.y(365:nFrame)=a(4);

% do calibration
try
    ListenChar(-1);
catch ME
     % old PTBs don't have mode -1, use 2 instead which also supresses
     % keypresses from leaking through to matlab
     ListenChar(2);
end
if doBimonocularCalibration
    % do sequential monocular calibrations for the two eyes
    settings= EThndl.getOptions();
    

    settings.calibrateEye   = 'left';
    settings.UI.button.setup.cal.string = 'calibrate left eye (<i>spacebar<i>)';
    str = settings.UI.button.val.continue.string;
    settings.UI.button.val.continue.string = 'calibrate other eye (<i>spacebar<i>)';
    EThndl.setOptions(settings);
    tobii.calVal{1}         = EThndl.calibrate(wpnt,1);
      if ~tobii.calVal{1}.wasSkipped
          settings.calibrateEye   = 'right';
          settings.UI.button.setup.cal.string = 'calibrate right eye (<i>spacebar<i>)';
          settings.UI.button.val.continue.string = str;
          EThndl.setOptions(settings);
          tobii.calVal{2}         = EThndl.calibrate(wpnt,2);
      end
else
    % do binocular calibration
    tobii.calVal{1}         = EThndl.calibrate(wpnt);
end
ListenChar(0);

        EThndl.buffer.start('gaze');
        WaitSecs(.8);
% play the movies
for ii = 1:num_of_movies
        %get the file to play
        moviefile = possibleMoviesCell{ii};
        
        %CHANGE FILE PATH FOR WHEREVER THE VIDEOS ARE ON EXPERIMENTAL
        %COMPUTER
        moviename = strcat(path,'\',moviefile);
        [movie, movduration, fps,imgw,imgh] = Screen('OpenMovie', wpnt, moviename);
       
        Screen('PlayMovie', movie, 1);
        % First draw a fixation point
        Screen('TextSize', wpnt ,100);
        DrawFormattedText(wpnt, '+', 'center', 'center', 0);
        Screen('Flip',wpnt);
        pause(2)
         startT=GetSecs;
           %play the actual movie
        % EThndl.sendMessage(sprintf('%s',moviefile),startT);
        inlet = lsl_inlet(streams{1});
        [samples, ts] = inlet.pull_sample();

        Start = EThndl.sendMessage(startT);
        fprintf(fid,'%s : Movie %s *Start* time : %d\n',datestr(now, 0),moviefile,Start);
        fprintf(fid,'%s : BioSignals *Start* time for movie %s  : %.5f\n',datestr(now, 0),moviefile, ts);
        fprintf(fid,'%s : The first BioSignals sample for movie %s :\n',datestr(now, 0),moviefile);
        fprintf(fid,'\n');
        fprintf(fid, ' %.4f\t , %.4f\t, %.4f\t, %.4f\t' ,samples);
        fprintf(fid,'\n');
        fprintf(fid,'\n');

        while ~KbCheck
            % Wait for next movie frame, retrieve texture handle to it
             tex = Screen('GetMovieImage', wpnt, movie);
            % Valid texture returned? A negative value means end of movie reached:
            if tex<=0
                % We're done, break out of loop:
                break;
            end
            % Draw the new texture immediately to screen:
            Screen('DrawTexture', wpnt, tex,[],rect1);
            % Update display:
            Screen('Flip', wpnt);
            % Release texture:
            Screen('Close', tex);
        end
        % Stop playback
        Screen('PlayMovie', movie,0);
        endT=GetSecs;
        % Close movie:
        Screen('CloseMovie', movie);
        Screen('FillRect', wpnt, rectColor);
        Screen('Flip', wpnt);
        % EThndl.sendMessage(sprintf('end - %s',moviefile),endT);
        End = EThndl.sendMessage(endT);
        inlet = lsl_inlet(streams{1});
        [samples, ts] = inlet.pull_sample();

        fprintf(fid,'%s : Movie %s *End* time : %d\n',datestr(now, 0),moviefile,End);
        fprintf(fid,'%s : BioSignals *End* time for movie %s  : %.5f\n',datestr(now, 0),moviefile, ts);
        fprintf(fid,'%s : The last BioSignals sample for movie %s :\n',datestr(now, 0),moviefile);
        fprintf(fid,'\n');
        fprintf(fid, ' %.4f\t , %.4f\t, %.4f\t, %.4f\t' ,samples);
        fprintf(fid,'\n');
        fprintf(fid,'\n');
        
        % stop recording
        pause(2)

        if ii==until_calibration
        
        startT=GetSecs;
           %play the actual movie
        EThndl.sendMessage(sprintf('calibration'));
        
        Screen('gluDisk',wpnt,fixClrs(1),1440,810,round(winRect(3)/100));
        Screen('gluDisk',wpnt,fixClrs(2),1440,810,round(winRect(3)/250));
        startT = Screen('Flip',wpnt);
        nextFlipT   = startT+fixTime-1/hz/2;    % bit of slack to make sure requested presentation time can be achieved
        frameT      = nan(1,nFrame);
    for f=1:nFrame
        Screen('gluDisk',wpnt,fixClrs(1),stim.x(f),stim.y(f),round(winRect(3)/100));
        Screen('gluDisk',wpnt,fixClrs(2),stim.x(f),stim.y(f),round(winRect(3)/250));
        frameT(f)   = Screen('Flip',wpnt,nextFlipT);        
        nextFlipT   = frameT(f)+.5/hz;  % we want to show a new location each frame, but ask for a bit early to provide the needed slack
    end
    
    % Clear screen and indicate that the stimulus was removed

    endT = Screen('Flip',wpnt,nextFlipT);
      
        EThndl.sendMessage(sprintf('end - calibration'),endT);
        % stop recording
        pause(2)
        end
            
end
EThndl.buffer.stop('gaze');
        dat = EThndl.collectSessionData();
EThndl.deInit();
catch me
    sca
    ListenChar(0);
    rethrow(me)
end


sca
fprintf(fid,'Time of experiment end : %s\n', datestr(now,'HH:MM:SS.FFF'));
save(Saving_file,'dat','domEye','stim','current_movies','randomized')
fclose(fid);
end
