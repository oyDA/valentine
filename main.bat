@echo off
:: Включение поддержки ANSI-цветов
reg add "HKCU\Console" /v VirtualTerminalLevel /t REG_DWORD /d 1 /f

:: Установка размера окна и буфера
mode con: cols=120 lines=40

:: Установка шрифта и его размера
reg add "HKCU\Console" /v FaceName /t REG_SZ /d "Consolas" /f
reg add "HKCU\Console" /v FontSize /t REG_DWORD /d 0x00060000 /f

:: Небольшая задержка для применения изменений
timeout /t 1 >nul

:: Запуск программы
start "" /max cmd /c main.exe

:: Пауза перед закрытием окна
pause