import os
import sys
sys.path.append(os.path.abspath("/scratch/emizen/falcon7b/falcon"))

# next step, add in llama stuff:
# check if I need to add path to llama stuff
# import llama stuff
# modify llama model so that it's a function also
# feed same prompts to llama and then 

# import all of my falcon stuff 
import falcon
print(dir(falcon))


# import all of my llama stuff
#import llama
#print(dir(llama))

#open the prompts, read each line of the prompts, and feed it to each of the models 
with open('prompts.txt', 'r') as prompts:
    lines = prompts.read().splitlines()
    print(lines)
    prompts.close()

#open the example directory/iterate through examples
for filename in os.listdir('examples'):
    with open('examples/{}'.format(filename), 'r') as e:
        code = e.read()
        #add prompt to example
        for line in lines:
            falcon.run_falcon(line + code)
            #llama.run_llama(line + code)
        e.close()  
        