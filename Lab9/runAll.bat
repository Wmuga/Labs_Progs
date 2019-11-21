for /l %%i in (0,1,3) do start Lab9.exe "in/input%%i.txt" "out/output%%i.txt"
start Lab9.exe "inputTXT.txt" "outputTest.txt"
start Lab9.exe "in/input0.txt"
for /l %%i in (1,1,5) do start Lab9.exe "in/input_an%%i.txt" "out/output_an%%i.txt"