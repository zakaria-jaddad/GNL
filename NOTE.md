# GNL

- repeated calls to the function should read the text file pointed to by the file
  descriptor, _one line at a time_.

- the function should return the line that was read, no limit for the line.

- if there is nothing else to read or an error accurred, function should return NULL

- Returned value should include `\n`. if EOF reached doesn't end with `\n`.

- header file must include function prototype.
