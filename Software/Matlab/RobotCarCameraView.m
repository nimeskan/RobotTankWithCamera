function [status, rawImageData, imageData] = RobotCarCameraView(saveFileName)
status = 0;

client = tcpclient('192.168.0.20', 14000);
data = uint8([0]);
whos data
write(client, data)
sizeBytes = read(client,4);
sizeOfImage = uint32(sizeBytes(1))*power(2,24) + uint32(sizeBytes(2))*power(2,16) + uint32(sizeBytes(3))*power(2,8) + uint32(sizeBytes(4));

sizeBytes;
sizeOfImage;

imagebytes = read(client, sizeOfImage);

disp('Saving into file:')
disp(saveFileName);
fid = fopen(saveFileName, 'w');
fwrite(fid, imagebytes, 'uint8');
fclose(fid);
rawImageData = imread(saveFileName);
imageData = imrotate(rawImageData, 180);
%imshow(imageData);

clear client

status = 1;