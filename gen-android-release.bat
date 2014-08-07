@echo off
del /q bin\release\android\*
cocos run -p android -m release
pause