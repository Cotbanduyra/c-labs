local ffi = require("ffi")
ffi.cdef[[
  typedef struct FILE FILE;
  FILE* fopen(const char*, const char*);
  int fclose(FILE*);
  void free(void*);
  void ReadString(FILE*, char**);
  void Reverse_words(char*, char**);
]]
local lib, libc = ffi.load("./libforlab7.so"), ffi.C
local f, b = libc.fopen("../input.txt", "r"), ffi.new("char*[1]")
lib.ReadString(f, b); libc.fclose(f)
local o = ffi.new("char*[1]")
lib.Reverse_words(b[0], o)
print(ffi.string(o[0]))
libc.free(b[0]); libc.free(o[0])