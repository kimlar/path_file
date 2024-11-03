# path_file_h
![alt text](https://github.com/kimlar/path_file_h/blob/main/path_file-code.png "Showing the code")

<br>

![alt text](https://github.com/kimlar/path_file_h/blob/main/path_file-running.png "Showing the code in action")

## Example of using path_file.h
```c
#include "path_file.h"
...
str filename = "Temp/Resource.pack";

str get_path = path_file_get_path__new(filename);
str get_path_slash = path_file_get_path_slash__new(filename);
str get_fullname = path_file_get_fullname__new(filename);
str get_basename = path_file_get_basename__new(filename);
str get_extension = path_file_get_extension__new(filename);
str get_extension_dot = path_file_get_extension_dot__new(filename);

printf("%s\n", get_path);
printf("%s\n", get_path_slash);
printf("%s\n", get_fullname);
printf("%s\n", get_basename);
printf("%s\n", get_extension);
printf("%s\n", get_extension_dot);

path_file_get_path__delete(get_path);
path_file_get_path_slash__delete(get_path_slash);
path_file_get_fullname__delete(get_fullname);
path_file_get_basename__delete(get_basename);
path_file_get_extension__delete(get_extension);
path_file_get_extension_dot__delete(get_extension_dot);
```

This is a drop-in file for any Windows C projects to quickly add a higher level to get path and filename functions.
