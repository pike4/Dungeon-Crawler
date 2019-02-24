

def makeDefs(inName, outName):
    import sys

 
    #Open the files  
    inF = open(inName, 'r')
    outF = open(outName, 'w')


    #Open a second file as a c file of the same base name
    outName2 = outName[:-1] + "c"
    

    #Declarations
    cnt = 0
    names = []

 
    #Remove leading directory from output file name
    while(outName.find('/') != -1):
        outName = outName[1:]
    
    mainName = str.split(inName, '.')[0]
    defName = mainName.upper() + "_DEF"
    arrayName = mainName + "_names"
    for line in inF.readlines():
        if len(line) < 2:
            continue

        #remove the extra line ending on each input line
        if line[len(line) - 1] == '\n':
            line = line[:-1]
        names.append(line)
        cnt = cnt + 1


    #Write out the #define(s)
    cur = 0
    for x in range(0, len(names)):
        if names[x][0] == '/':
            outF.write('\n' + names[x] + '\n')
        else:
            outF.write('#define ' + names[x] + ' ' + str(cur) + '\n')
            cur += 1
        
    outF.close()
    inF.close()
