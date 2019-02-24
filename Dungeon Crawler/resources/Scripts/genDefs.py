

def makeDefs(inName, outName):
    import sys

 
    #Open the files  
    inF = open(inName, 'r')
    outF = open(outName, 'w')


    #Open a second file as a c file of the same base name
    outName2 = outName[:-1] + "cpp"
    outF2 = open(outName2, 'w')

    #Declarations
    cnt = 0
    names = []

 
    #Remove leading directory from output file name
    while(outName.find('/') != -1):
        print(outName)
        outName = outName[1:]
    
    mainName = str.split(inName, '.')[0]
    mainName = str.split(mainName, '/')[len(str.split(mainName, '/')) - 1]
    defName = mainName.upper() + "_DEF"
    arrayName = mainName + "Names"
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

    #Write the array declaration
    outF.write("\nextern char* " + arrayName + "[" + str(len(names)) + "];\n")

    # Write out names to cpp file
    outF2.write("#include \"" + outName + "\"\n")
    outF2.write("\nchar* " + arrayName + "[" + str(len(names)) + "] = \n{\n")

    #Write array contents
    for x in range(0, len(names)):
        outF2.write("\t\"" + names[x] + "\"")
        if x < len(names) - 1:
            outF2.write(",")
        outF2.write("\n")
    outF2.write("};\n")
        
    outF.close()
    inF.close()
