function coordinations_for_video=individuals_coordinates(participant)
video_coordinates=cell(1,180);
for ii=1:1
    %data_to_laod=sprintf('C:\\Users\\erezs\\OneDrive\\Documents\\repo\\%s_run%d.mat',participant,ii);
    data_to_laod=sprintf('C:\\Users\\erezs\\OneDrive\\Desktop\\andrey_with_calib\\%s_run%d.mat',participant,ii);
    % data_to_laod=sprintf('C:\\Users\\erezs\\Videos\\Movies\\New folder (2)\\%s_run%d.mat',participant,ii)
    load(data_to_laod);
    %videos_num=randomized((30*(ii-1)+1):(30*ii));
    videos_num=1:7;
    messages=dat.messages(:,2);
    relevant_messages=cellfun(@(X) X(1),messages,'UniformOutput',0);
    logical_messages=isstrprop(relevant_messages,'digit');
    relevant_indices=find(cell2mat(logical_messages));
    relevant_indices(:,2)=(relevant_indices+1);
    
    for jj=1:7
        x_averaged_gaze=[];
        y_averaged_gaze=[];
        PupilDiameter=[];
        video_to_read=sprintf('C:\\Users\\erezs\\Videos\\Movies\\%d.mp4',videos_num(jj));
        Current_video=VideoReader(video_to_read);
        number_of_frames=Current_video.NumFrames;
        all_timestamps=dat.data.gaze.systemTimeStamp(:);
        message_time_stamp_start=dat.messages{relevant_indices(jj,1),1};
        message_time_stamp_end=dat.messages{relevant_indices(jj,2),1};
        [~,start_min_index_of_all_timestamps]=min(abs(all_timestamps-message_time_stamp_start));
        [~,end_min_index_of_all_timestamps]=min(abs(all_timestamps-message_time_stamp_end));
        index_to_average=round(linspace(start_min_index_of_all_timestamps,end_min_index_of_all_timestamps,number_of_frames));
        screen_height=1080;
        screen_length=1920;
%       video_height=Current_video.Height;
%       video_length=Current_video.Width;
%       x_video_centere=0.5*screen_length;
%       y_video_centere=0.5*screen_height;
        Window_height=dat.geometry.displayArea.height;
        Window_length=dat.geometry.displayArea.width;
        if domEye=='l'
            for kk=1:(number_of_frames-1)
                averaged_gaze_index=index_to_average(kk):index_to_average(kk+1);
                noNan_averaged_gaze_index=rmmissing(dat.data.gaze.left.gazePoint.onDisplayArea(:,averaged_gaze_index));
                noNan_averaged_pupil_size=rmmissing(dat.data.gaze.left.pupil.diameter(:,averaged_gaze_index));
                    if ~isnan(noNan_averaged_gaze_index) && ~isnan(noNan_averaged_pupil_size)
                        x_location=mean(noNan_averaged_gaze_index(1,:))*screen_length;
                        x_averaged_gaze(kk)=x_location;
                        y_location=mean(noNan_averaged_gaze_index(2,:))*screen_height;
                        y_averaged_gaze(kk)=y_location;

                        location=mean(noNan_averaged_pupil_size(1,:))*screen_length;
                        PupilDiameter(kk)=location;
                        
                    else
                        x_averaged_gaze(kk)=nan;
                        y_averaged_gaze(kk)=nan;  
                        PupilDiameter(kk)=nan;
                    end
            end
        else
            for kk=1:(number_of_frames-1)
                averaged_gaze_index=index_to_average(kk):index_to_average(kk+1);
                noNan_averaged_gaze_index=rmmissing(dat.data.gaze.right.gazePoint.onDisplayArea(:,averaged_gaze_index));
                noNan_averaged_pupil_size=rmmissing(dat.data.gaze.right.pupil.diameter(:,averaged_gaze_index));
                    if ~isnan(noNan_averaged_gaze_index)
                        x_location=mean(noNan_averaged_gaze_index(1,:))*screen_length;
                        x_averaged_gaze(kk)=x_location;
                        y_location=mean(noNan_averaged_gaze_index(2,:))*screen_height;
                        y_averaged_gaze(kk)=y_location;

                        location=mean(noNan_averaged_pupil_size(1,:))*screen_length;
                        PupilDiameter(kk)=location;
                    else
                        x_averaged_gaze(kk)=nan;
                        y_averaged_gaze(kk)=nan; 
                        PupilDiameter(kk)=nan;
                        

                    end
            end
        end
    x_averaged_gaze(kk+1)=x_averaged_gaze(ii);
    y_averaged_gaze(kk+1)=y_averaged_gaze(ii);
    PupilDiameter(kk+1)=PupilDiameter(ii);
    PupilDiameter(isnan(PupilDiameter))=0;

    video_coordinates{videos_num(jj)}=[x_averaged_gaze;y_averaged_gaze;PupilDiameter]';
    end
    coordinations_for_video=video_coordinates;
end