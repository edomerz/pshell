psudu shell
pshell

prints prompt, gets the input to a buf, parse the input, and execute DO(command, args)

above this program will be watchdog program - it will call the pshell, wait for it to 
complete, and recall it

they will exit, end when a reserved word will be inserted, 
the pshell will return the exit code to the watchdog, and watchdog will end

2 versions
- fork()
- system()

