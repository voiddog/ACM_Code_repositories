@g++ random.cpp -o random.exe
@g++ a.cpp -o a.exe
@g++ b.cpp -o b.exe
@for /f "delims=" %%i in ('FC /L a.txt a.txt') do @set a=%%i
@echo %a%
:begin
@random.exe
@a.exe
@b.exe
@for /f "delims=" %%i in ('FC /L a.txt b.txt') do @set b=%%i
@echo %a%
@echo %b%
@if "%a%" == "%b%" goto begin
@pause
