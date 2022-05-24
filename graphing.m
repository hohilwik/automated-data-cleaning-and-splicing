%text = importdata('./data_spliced/normal_standing2/sensor1.txt', '\n', 0);

%fileID = fopen('dir_ls.txt', 'r');
%A = fscanf(fileID, '%s');

list = ls('./data_spliced');
A = size(list);
no_of_files = A(1);

%deblank(list(3, :))

for i=3:no_of_files
    dir_name = deblank(list(i, :));
    
    address = strcat('./data_spliced/', dir_name);
    temp = size( ls(address) );
    sensor_count = temp(1)-2;
    
    f=figure();
    
    for s=1:sensor_count
        filename = strcat('sensor', num2str(s), '.txt');
        file_addr = strcat(address,'/',filename);
        data = importdata( file_addr, '\n', 0);
        
        if (s==1)
            data1 = data;
        end
        if (s==2)
            data2 = data;
        end
        if (s==3)
            data3 = data;
        end
        if (s==4)
            data4 = data;
        end
        if (s==5)
            data5 = data;
        end
        if (s==6)
            data6 = data;
        end
        if (s==7)
            data7 = data;
        end
        if (s==8)
            data8 = data;
        end
        if (s==9)
            data9 = data;
        end
        if (s==10)
            data3 = data;
        end
        if (s==10)
            data3 = data;
        end
        if (s==11)
            data11 = data;
        end
        if (s==12)
            data12 = data;
        end
        
        subplot(sensor_count, 1, s);
        axis = 1:length(data);
        plot(axis, data);
        str_title = strcat(dir_name, ' ', filename);
        title(str_title)
        
        
        
    end
    imgname= strcat('./graphs/', dir_name, '.png');
    saveas(f, imgname);
   
    
end