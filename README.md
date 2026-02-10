Name: Jackie Herbstreit
Date: January 30, 2026
Environment: linux, vim
How to compile the project:
	 Type 'make'
Example of how to run the project: 
	Type './oss -n 4 -s 2 -t 5'

Generative AI used: chatgpt
Prompts:
	Please do not code anything for me. I wanted to give you the full picture of what my 
	project requirements are so I can ask some questions related.
	Can you explain what the heck the exec() call does? I know fork() is used to create a 
	new child process(es) depending on what -n is. What does exec() do? 
	How does getopt(3) work?
	Can you explain how the argc, char *argv works. I get that with the oss.cpp that's what 
	we're using to get the parsing stuff, so it makes sense that that's what the child brings 
	with it when it calls exec. I just don't think I understand how it works.
	How exactly does optarg work then? I'm missing the logic there.
	So do we convert t to an int to validate the value is correct, and then just convert back 
	to a string once in the while loop? Why can't we just convert t into an int without having 
	to do the char tstr[10]? What does the "%d" do? Is it only to format? Do I actually need 
	it in my code?
	NOTE: I also input my code block throughout and asked chatgpt to confirm whether the syntax
	and logic was correct. I did not want chatgpt to generate code for me, I wanted to work 
	through the coding on my own. It did suggest specific functions to use for certain things,
	atoi() function for example.
Summary: The explanations for specific logic questions were answered very well, and were helpful
	throughout this project. Chatgpt did very well at connecting the missing logic pieces
	for me.
