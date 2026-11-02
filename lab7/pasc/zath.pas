program Demo;

{$mode objfpc}{$H+}

uses
  dynlibs;

type
  TReadString    = procedure(f: Pointer; str: PPAnsiChar); cdecl;
  TCreateNewStr  = procedure(f_str: PAnsiChar; t_str: PPAnsiChar;
                             curr_pos: LongInt; word_start: LongInt;
                             is_word: Boolean); cdecl;
  TReverse_words = procedure(f_str: PAnsiChar; t_str: PPAnsiChar); cdecl;
  TFopen         = function(path, mode: PAnsiChar): Pointer; cdecl;
  TFclose        = function(f: Pointer): LongInt; cdecl;
  TFree          = procedure(p: Pointer); cdecl;

var
  LibHandle, LibcHandle: TLibHandle;
  ReadString:    TReadString;
  CreateNewStr:  TCreateNewStr;
  Reverse_words: TReverse_words;
  CFopen:  TFopen;
  CFclose: TFclose;
  CFree:   TFree;
  F:          Pointer;
  Buf:        PAnsiChar;
  Result_buf: PAnsiChar;

begin
  LibHandle  := LoadLibrary('libforlab7.so');
  LibcHandle := LoadLibrary('libc.so.6');

  Pointer(ReadString)    := GetProcedureAddress(LibHandle, 'ReadString');
  Pointer(CreateNewStr)  := GetProcedureAddress(LibHandle, 'CreateNewStr');
  Pointer(Reverse_words) := GetProcedureAddress(LibHandle, 'Reverse_words');
  Pointer(CFopen)        := GetProcedureAddress(LibcHandle, 'fopen');
  Pointer(CFclose)       := GetProcedureAddress(LibcHandle, 'fclose');
  Pointer(CFree)         := GetProcedureAddress(LibcHandle, 'free');

  F := CFopen('input.txt', 'r');

  Buf := nil;
  ReadString(F, @Buf);
  CFclose(F);

    WriteLn('aAAAAAAAAAAAAaaa');

  WriteLn(Buf);

  Result_buf := nil;
  CreateNewStr(Buf, @Result_buf, 0, 0, False);
  WriteLn(Result_buf);

  CFree(Result_buf);
  Result_buf := nil;
  Reverse_words(Buf, @Result_buf);
  WriteLn(Result_buf);

  CFree(Buf);
  CFree(Result_buf);

  UnloadLibrary(LibcHandle);
  UnloadLibrary(LibHandle);
end.