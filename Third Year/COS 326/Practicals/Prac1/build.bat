@echo off
setlocal

REM Compile Java files
javac -cp objectdb.jar *.java

REM Run the Main class
java -cp ".;objectdb.jar" Main

REM Remove the compiled Java class files
del *.class

endlocal
