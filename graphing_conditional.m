
list = ls('./data_spliced/*ivin2_*deadlift*');
A = size(list);
no_of_files = A(1);

sens_num=4;

window = 40;%25;
kernel = ones(window,1)/window;

%deblank(list(3, :))

f=figure();

for i=1:no_of_files
    dir_name = deblank(list(i, :));
    
    address = strcat('./data_spliced/', dir_name);
    temp = size( ls(address) );
    sensor_count = temp(1)-2;
    
    
    for s=1:sens_num%sensor_count
        filename = strcat('sensor', num2str(s), '.txt');
        file_addr = strcat(address,'/',filename);
        data = importdata( file_addr, '\n', 0);
        filtered_data = filter(kernel, 1, data);
        
        
    
        
        %f=figure();
        hold on;
        
        %subplot(no_of_files, 1, i);
        subplot(sensor_count,1,s);
        axis = 1:length(data);
        %plot(axis, data);
        data_freq= abs(fft(filtered_data).^2);
        plot(axis, filtered_data );
        str_title = strcat(dir_name, ',', filename);
        title(str_title)
        %title('fft ignore initial');
        
        name = strcat(dir_name, 'sensor', num2str(s));
        imgname= strcat('./graph_ind/', name, '.png');
        saveas(f, imgname);
   
        
    end
    
    
end