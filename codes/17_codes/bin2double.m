function data = bin2double(filename, sizeA)
fileID = fopen(filename, 'r');
data = fread(fileID, sizeA, 'double');
fclose(fileID);
end