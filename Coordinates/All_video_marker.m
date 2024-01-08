%Sorry in advance, but a wrote down the number of participant and videos
%manually in each place (insteadt of a variable). Make sure that the number
%of videos and participants is in line with yours.
clc
clear
% Put in your screen parameters
screen_height=1080;
screen_length=1920;

%This part is for creating a coordination matrix. The output of this part
%is a 10 * 180 cell array, where every row is a participant, every column
%is a video, and within every cell is a vertical vector, 2 columns on
%around 450 rows. This is because our videos were 30 frames per second, and
%the videos were 15 seconds long. Column 1 represents X location
%(horizontal eye location), and column 2 Y location. If you did not obtain
%coordinations yet an avreged vecotr for every frame (we sampeled 600 times per second
%from the Tobii, so we had to condense it to fit the 1 coordination for
%every frame) you can use "individuals_coordinates" as the basics for this
%task, just note that the way I iterated the data is highly siutable for
%our uses specificaly, and I manually inserted some numbers so it is not an
%easy change with variables. 
% If you already obtained coordinations, just
%make sure you condense them into a vector of the same length as the number
%of frames for a specific video (so each frame will have only 1 corrdinates
%per person).

all_participants={'andrey'};
for iii=1:1 %%% number of participants
    participant=all_participants{iii};
    coordinations_for_video(iii,:)=individuals_coordinates(participant);
end



%%This is the loop that calls the vedios (make sure that you name the
%%vedios in way that the loop can iterate between them) and uses the length
%%and height of the video to add blank pixels to the top left of the
%%frames. This way, the new origin of coordination of the video will match
%%that of the Tobii, and you could see the markers on the video.

for aa=1:7 %%%number of videos
    video_to_read=sprintf('C:\\Users\\erezs\\Videos\\Movies\\%d.mp4',aa);
    video_to_create=sprintf('C:\\Users\\erezs\\Videos\\Movies\\test_%d',aa);
    Current_video=VideoReader(video_to_read);
    number_of_frames=Current_video.NumFrames;
    
    Creating_video=VideoWriter(video_to_create,"MPEG-4"); % The new video will contain the same frames, only with added markers
    Creating_video.Quality = 100;
    Creating_video.FrameRate = 24;
    open(Creating_video)
    marker_colors = "blue";%,"green","blue","cyan","magenta","yellow","black","white","red","blue"]; %Make fure you add the same amount of colors as the number of markers you want to add.
    
    for frame_number=1:number_of_frames
        vidFrame=readFrame(Current_video);
        %pad_frame=padarray(vidFrame,[screen_height/2-Current_video.Height/2,screen_length/2-Current_video.Width/2],'pre'); %Here we add the blank pixels
        pad_frame=padarray(vidFrame,[screen_height/2-Current_video.Height/2,screen_length/2-Current_video.Width/2],'pre');
            
        %פה אפשר להכניס גם את ההיט מאפ כי יש פריים X ו Y בשורה מעל

        for subject = 1 : 1
            location_mat(subject, :) = coordinations_for_video{subject,aa}(frame_number,:); %This is a matrix containing the coordinates of all participants in a specific frame. 
            % We will use this to add the markers to each frame.
        end


        find_nan=isnan(location_mat);
        location_mat(find_nan)=-100;
        if sum(find_nan)<20
            %פה ראיתי בדאטה שהפרמטר השלישי זה הרדיוס של המעגל אבל בגלל שיש
            %שם "NAN" זה עושה בעיות
            %הוספתי LOCATION_MAT 3 שזה מכיל את הרדיוס
            %ששצריף לעשוץ לדאטה סקאלה אקספוננטית כדי שיהיה יותר רגיש
            
            Marked_frame= insertObjectAnnotation(pad_frame,"circle",[location_mat(:,1),location_mat(:,2),power(location_mat(:,3)/1.0e+03,1.5)],all_participants,LineWidth=3,Color= marker_colors,TextColor="white",FontSize=17,TextBoxOpacity=0.6);
            
            Marked_frame=Marked_frame((1+(screen_height/2-Current_video.Height/2)):end,1+((screen_length/2-Current_video.Width/2)):end,:);
            
            writeVideo(Creating_video,Marked_frame);
             
        else
            writeVideo(Creating_video,vidFrame);
        end
        
    end

    close(Creating_video) 
end