function double2bin(data, filename)
fileID = fopen(filename, 'w');
fwrite(fileID, data(:), 'double');
fclose(fileID);
end